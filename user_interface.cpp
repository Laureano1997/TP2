#include "mbed.h"
#include "arm_book_lib.h"

#include "display.h"
#include "temperature_sensor.h"
#include "water_sensor.h"
#include "alarm.h"
#include "greenhouse_system.h"
#include "reset_button.h"
#include "menu_button.h"
#include "soil_moisture_sensor.h"
#include "irrigation_valve.h"

//=====[Declaration of private defines]========================================
#define DISPLAY_REFRESH_TIME_MS 1000

//=====[Declaration of private data types]=====================================

typedef enum{
    SYSTEM_DESCRIPTION,
    DISPLAY_BIO_DATA,
    SYSTEM_DATA,
}interfaceState_t;

//=====[Declaration and initialization of public global objects]===============

DigitalOut incorrectCodeLed(LED3);
DigitalOut systemBlockedLed(LED2);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static bool systemBlockedState = OFF;
static char degreeSymbol[2] = {'\337', '\0'};
static status_t systemStatus = NORMAL_WORKING;
static interfaceState_t interfaceState = DISPLAY_BIO_DATA;
static bool printed = false;


//=====[Declarations (prototypes) of private functions]========================

static void userInterfaceMatrixKeypadUpdate();

static void userInterfaceDisplayInit();
static void userInterfaceDisplayUpdate();
static void userInterfacePrintData();
static void printTemperature();

//=====[Implementations of public functions]===================================

void userInterfaceInit()
{
    userInterfaceDisplayInit();
}

void userInterfaceUpdate()
{
    userInterfaceDisplayUpdate();
}

//=====[Implementations of private functions]==================================

static void userInterfaceMatrixKeypadUpdate(){
    static char i=0;
    if(menuButtonRead()==ON){
        i++;
        printed=false;
        while(menuButtonRead()==ON);
    }
    if(i == 3){
        i=0;
    }
    switch (i){
        case 0:
            interfaceState = SYSTEM_DESCRIPTION;
            break;
        case 1:
            interfaceState = DISPLAY_BIO_DATA;
            break;
        case 2:
            interfaceState = SYSTEM_DATA;
            break;
        default:
            interfaceState = SYSTEM_DESCRIPTION;
            break;
    }       

}


static void userInterfaceDisplayInit()
{
    displayInit( DISPLAY_CONNECTION_I2C_PCF8574_IO_EXPANDER );
    interfaceState = SYSTEM_DESCRIPTION;
    menuButtonInit();
    resetButtonInit();
}

static void userInterfaceDisplayUpdate()
{
    static int accumulatedDisplayTime = 0;
    
    userInterfaceMatrixKeypadUpdate();

    if( accumulatedDisplayTime >=
        DISPLAY_REFRESH_TIME_MS ) {

        accumulatedDisplayTime = 0;

        switch (greenhouseSystemStatusRead()){
            case NORMAL_WORKING:
                switch (interfaceState){
                    case SYSTEM_DESCRIPTION:
                        if(!printed){
                            displayClearScreen();
                            displayCharPositionWrite( 3,0 );
                            displayStringWrite( "SISTEMA DE" );
                            displayCharPositionWrite(0, 1);
                            displayStringWrite( "RIEGO AUTOMATICO" );
                            printed = true;
                        }
                        break;
                    case DISPLAY_BIO_DATA:
                        if(!printed){
                            displayClearScreen();
                            displayCharPositionWrite( 0,0 );
                            displayStringWrite( "Suelo:" );
                            displayCharPositionWrite( 0,1 );
                            displayStringWrite( "Riego:" );
                            printed = true;
                        }
                        displayCharPositionWrite ( 7,0 );
                        if(soilMoistureSensorRead())
                            displayStringWrite( "Mojado" );
                        else
                            displayStringWrite( "Seco  " );
                        displayCharPositionWrite ( 7,1 );
                        if(irrigationValveRead())
                            displayStringWrite( "Encendido" );
                        else
                            displayStringWrite( "Apagado  " );
                        break;
                    case SYSTEM_DATA:
                        if(!printed){
                            displayClearScreen();
                            userInterfacePrintData();
                            printed = true;
                        }
                        printTemperature();
                        displayCharPositionWrite ( 8,1 );
                        displayStringWrite( "Lleno" );
                        break;
                    default:
                        displayClearScreen();
                        break;
                }
                break;
            case EMPTY_TANK:
                switch (interfaceState){
                    case SYSTEM_DESCRIPTION:
                        if(!printed){
                            displayClearScreen();
                            displayCharPositionWrite( 3,0 );
                            displayStringWrite( "SISTEMA DE" );
                            displayCharPositionWrite(0, 1);
                            displayStringWrite( "RIEGO AUTOMATICO" );
                            printed = true;
                        }
                        break;
                    case DISPLAY_BIO_DATA:
                        if(!printed){
                            displayClearScreen();
                            displayCharPositionWrite( 0,0 );
                            displayStringWrite( "Suelo:" );
                            displayCharPositionWrite( 0,1 );
                            displayStringWrite( "Riego:" );
                            printed = true;
                        }
                        displayCharPositionWrite ( 7,0 );
                        if(soilMoistureSensorRead())
                            displayStringWrite( "Mojado" );
                        else
                            displayStringWrite( "Seco  " );
                        displayCharPositionWrite ( 7,1 );
                        if(irrigationValveRead())
                            displayStringWrite( "Encendido" );
                        else
                            displayStringWrite( "Apagado  " );
                        break;
                    case SYSTEM_DATA:
                        if(!printed){
                            displayClearScreen();
                            userInterfacePrintData();
                            printed = true;
                        }
                        printTemperature();
                        displayCharPositionWrite ( 8,1 );
                        displayStringWrite( "Vacio" );
                        break;
                    default:
                        displayClearScreen();
                        break;
                }
                break;
            case SYSTEM_BLOCKED:
                displayClearScreen();
                displayCharPositionWrite( 5,0 );
                displayStringWrite( "ALERTA" );
                displayCharPositionWrite(2, 1);
                displayStringWrite( "TANQUE VACIO" );
                printed = false;
                break;
            default:
                break;
        }
    } else {
        accumulatedDisplayTime =
            accumulatedDisplayTime + SYSTEM_TIME_INCREMENT_MS;        
    } 
}

static void userInterfacePrintData(){
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "Temperatura" );

    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "Tanque  " );

    displayCharPositionWrite( 8,1 );
    displayStringWrite( "        " );
}

static void printTemperature(){
    static char temperatureString[3] = "";

    floatToStr(temperatureString, temperatureSensorReadCelsius());
    displayCharPositionWrite ( 11,0 );
    displayStringWrite( temperatureString );
    displayCharPositionWrite ( 14,0 );
    displayStringWrite(degreeSymbol);
    displayCharPositionWrite ( 15,0 );
    displayStringWrite( "C" );
}