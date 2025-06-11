//=====[Libraries]=============================================================

#include "mbed.h"

#include "temperature_sensor.h"

//#include "smart_home_system.h"

//=====[Declaration of private defines]========================================

#define LM35_NUMBER_OF_AVG_SAMPLES    10

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

AnalogIn lm35(A0);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

float lm35TemperatureC = 0.0;
float lm35ReadingsArray[LM35_NUMBER_OF_AVG_SAMPLES];
char str[4];

//=====[Declarations (prototypes) of private functions]========================

static float analogReadingScaledWithTheLM35Formula( float analogReading );

//=====[Implementations of public functions]===================================

void temperatureSensorInit()
{
    int i;
    
    for( i=0; i<LM35_NUMBER_OF_AVG_SAMPLES ; i++ ) {
        lm35ReadingsArray[i] = 0;
    }
}

void temperatureSensorUpdate()
{
    static int lm35SampleIndex = 0;
    float lm35ReadingsSum = 0.0;
    float lm35ReadingsAverage = 0.0;

    int i = 0;

    lm35ReadingsArray[lm35SampleIndex] = lm35.read();
       lm35SampleIndex++;
    if ( lm35SampleIndex >= LM35_NUMBER_OF_AVG_SAMPLES) {
        lm35SampleIndex = 0;
    }
    
   lm35ReadingsSum = 0.0;
    for (i = 0; i < LM35_NUMBER_OF_AVG_SAMPLES; i++) {
        lm35ReadingsSum = lm35ReadingsSum + lm35ReadingsArray[i];
    }
    lm35ReadingsAverage = lm35ReadingsSum / LM35_NUMBER_OF_AVG_SAMPLES;
       lm35TemperatureC = analogReadingScaledWithTheLM35Formula ( lm35ReadingsAverage );    
}


float temperatureSensorReadCelsius()
{
    return lm35TemperatureC;
}

float temperatureSensorReadFahrenheit()
{
    return celsiusToFahrenheit( lm35TemperatureC );
}

float celsiusToFahrenheit( float tempInCelsiusDegrees )
{
    return ( tempInCelsiusDegrees * 9.0 / 5.0 + 32.0 );
}

//=====[Implementations of private functions]==================================

static float analogReadingScaledWithTheLM35Formula( float analogReading )
{
    return ( analogReading * 3.3 / 0.01 );
}

void floatToStr(char str[], float num) {
    if (num < 0) {      //Si es negativo agrego un - al comienzo
        str[0] = '-';
        num = -num; 
    }
    else{               //Sino agrego un espacio
        str[0] = ' ';
    }

    int aux = (int)((num + 0.05) * 100); // Aplico redondeo 12.36 -> 12.41 -> 1241 y me quedo con los primeros tres valores
    int integer = aux / 100;       // Parte entera: 12
    int decimal = aux % 100;      // Parte decimal: 41

    str[1] = (integer / 10) + '0'; // Decena
    str[2] = (integer % 10) + '0'; // Unidad
    //str[3] = ',';                 // Separador decimal
    //str[4] = (decimal / 10) + '0'; // Décima
    str[3] = '\0';
}
