//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "pc_serial_com.h"
#include "greenhouse_system.h"
#include "alarm.h"
#include "temperature_sensor.h"
#include "water_sensor.h"
#include "irrigation_valve.h"
#include "soil_moisture_sensor.h"
#include "date_and_time.h"
#include "light_control.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

typedef enum{
    PC_SERIAL_COMMANDS,
    PC_SERIAL_GET_CODE,
    PC_SERIAL_SAVE_NEW_CODE,
} pcSerialComMode_t;

//=====[Declaration and initialization of public global objects]===============

UnbufferedSerial uartUsb(USBTX, USBRX, 115200);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============


//=====[Declaration and initialization of private global variables]============

static pcSerialComMode_t pcSerialComMode = PC_SERIAL_COMMANDS;
static bool codeComplete = false;
static int numberOfCodeChars = 0;
static char temperature[3];
static bool alertMsgSent = OFF;

//=====[Declarations (prototypes) of private functions]========================

static void pcSerialComStringRead( char* str, int strLength );
static void commandShowDateAndTime();
static void commandSetDateAndTime();
static char serialComCharRead();
static void serialComStringRead(char* string, size_t len);

//=====[Implementations of public functions]===================================

char pcSerialComCharRead()
{
    char receivedChar = '\0';
    if( uartUsb.readable() ) {
        uartUsb.read( &receivedChar, 1 );
    }
    return receivedChar;
}

void pcSerialComInit()
{
    pcSerialComStringWrite( "SISTEMA DE MONITOREO DE INVERNADERO:\r\n" );
    if(waterSensorRead())
        pcSerialComStringWrite( "Estado del tanque: Lleno\r\n" );
    else
        pcSerialComStringWrite( "Estado del tanque: Vacío\r\n" );

    pcSerialComStringWrite( "Temperatura del recinto:" );
    floatToStr(temperature, temperatureSensorReadCelsius());
    pcSerialComStringWrite(temperature);
    pcSerialComStringWrite("°C\r\n");

    if(soilMoistureSensorRead())
        pcSerialComStringWrite( "Estado del suelo: Humedo\r\n" );
    else
        pcSerialComStringWrite( "Estado del suelo: Seco\r\n" );

    if(irrigationValveRead())
        pcSerialComStringWrite( "Estado de la electroválvula de riego: Encendida\r\n" );
    else
        pcSerialComStringWrite( "Estado de la electroválvula de riego: Apagada\r\n" );
    pcSerialComStringWrite("\r\n");
}


void pcSerialComStringWrite( const char* str )
{
    uartUsb.write( str, strlen(str) );
}

void pcSerialComUpdate()
{
    static int accumulatedTimeSerialCom = 0;
    accumulatedTimeSerialCom = accumulatedTimeSerialCom + SYSTEM_TIME_INCREMENT_MS;
    char receivedChar = pcSerialComCharRead();
    char lightLevel[5]="";
    if(alarmBuzzerStateRead() && !alertMsgSent){
        pcSerialComStringWrite("EL SISTEMA ESTÁ BLOQUEADO POR FALTA DE AGUA\r\n");
        pcSerialComStringWrite("\r\n");
        alertMsgSent = ON;
    }

    if(accumulatedTimeSerialCom > UPDATE_TIME_SYSTEM_STATUS && !alarmBuzzerStateRead()){
        pcSerialComInit();
        accumulatedTimeSerialCom = 0;
        alertMsgSent = OFF;
    }

    //bleComWrite(dateAndTime);
    if(receivedChar != '\0'){
        switch(receivedChar){
            case 'T': 
                //bleComStringRead(dateAndTime, 19);
                //updateDateAndTime(dateAndTime);
                commandSetDateAndTime();
                break;
            case 'L': 
                pcSerialComStringWrite("\r\nIndique nivel de luz");
                pcSerialComStringRead( lightLevel, 3);
                pcSerialComStringWrite("\r\n");
                
                //dutyCycle = (int) bleComCharRead();
                lightControlUpdate(0.01*atoi(lightLevel));//atof(dutyCycle));
                break;
            default:
                break;
        }
    }
}

//=====[Implementations of private functions]==================================

static void pcSerialComStringRead( char* str, int strLength )
{
    int strIndex;
    for ( strIndex = 0; strIndex < strLength; strIndex++) {
        uartUsb.read( &str[strIndex] , 1 );
        //uartUsb.write( &str[strIndex] ,1 );
    }
    str[strLength]='\0';
}

static void commandShowDateAndTime()
{
    char str[100] = "";
    sprintf ( str, "Date and Time = %s", dateAndTimeRead() );
    pcSerialComStringWrite( str );
    pcSerialComStringWrite("\r\n");
}

static void commandSetDateAndTime()
{
    char year[5] = "";
    char month[3] = "";
    char day[3] = "";
    char hour[3] = "";
    char minute[3] = "";
    char second[3] = "";
    
    pcSerialComStringWrite("\r\nIngrese cuatro dígitos para el año (YYYY): ");
    pcSerialComStringRead( year, 4);
    pcSerialComStringWrite("\r\n");

    pcSerialComStringWrite("Ingrese dos dígitos para el mes (01-12): ");
    pcSerialComStringRead( month, 2);
    pcSerialComStringWrite("\r\n");

    pcSerialComStringWrite("Ingrese dos dígitos para el día (01-31): ");
    pcSerialComStringRead( day, 2);
    pcSerialComStringWrite("\r\n");

    pcSerialComStringWrite("Ingrese dos dígitos para la hora (00-23): ");
    pcSerialComStringRead( hour, 2);
    pcSerialComStringWrite("\r\n");

    pcSerialComStringWrite("Ingrese dos dígitos para los minutos (00-59): ");
    pcSerialComStringRead( minute, 2);
    pcSerialComStringWrite("\r\n");

    pcSerialComStringWrite("Ingrese dos dígitos para los segundos (00-59): ");
    pcSerialComStringRead( second, 2);
    pcSerialComStringWrite("\r\n");
    
    pcSerialComStringWrite("Hora y fecha configuradas\r\n");

    dateAndTimeWrite( atoi(year), atoi(month), atoi(day), 
        atoi(hour), atoi(minute), atoi(second) );
}

static char serialComCharRead(){
    char receivedChar = '\0';
    if( uartUsb.readable() ) {
        uartUsb.read(&receivedChar,1);
    }
    return receivedChar;
}

static void serialComStringRead(char* string, size_t len){
    if(uartUsb.readable())
        uartUsb.read(&string, len);
    string[len] = '\0';
}