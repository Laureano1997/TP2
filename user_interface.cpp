#include "mbed.h"
#include "arm_book_lib.h"

#include "display.h"
#include "temperature_sensor.h"
#include "water_sensor.h"
#include "alarm.h"
#include "greenhouse_system.h"

//=====[Declaration of private defines]========================================
#define DISPLAY_REFRESH_TIME_MS 1000

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalOut incorrectCodeLed(LED3);
DigitalOut systemBlockedLed(LED2);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static bool systemBlockedState = OFF;
static char degreeSymbol[2] = {0xFC, '\0'};
static status_t systemStatus = NORMAL_WORKING;


//=====[Declarations (prototypes) of private functions]========================

static void userInterfaceDisplayInit();
static void userInterfaceDisplayUpdate();

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

static void userInterfaceDisplayInit()
{
    displayInit( DISPLAY_CONNECTION_I2C_PCF8574_IO_EXPANDER );
}

static void userInterfaceDisplayUpdate()
{
    static int accumulatedDisplayTime = 0;
    char temperatureString[3] = "";
    
    if( accumulatedDisplayTime >=
        DISPLAY_REFRESH_TIME_MS ) {

        accumulatedDisplayTime = 0;

        switch (alarmSystemStatus()){
            case NORMAL_WORKING:
                displayCharPositionWrite ( 0,0 );
                displayStringWrite( "Temperatura" );

                displayCharPositionWrite ( 0,1 );
                displayStringWrite( "Tanque  " );

                floatToStr(temperatureString, temperatureSensorReadCelsius());
                displayCharPositionWrite ( 11,0 );
                displayStringWrite( temperatureString );
                displayCharPositionWrite ( 14,0 );
                displayStringWrite(degreeSymbol);
                displayCharPositionWrite ( 15,0 );
                displayStringWrite( "C" );

                displayCharPositionWrite( 8,1 );
                displayStringWrite( "        " );
                displayCharPositionWrite ( 8,1 );
                displayStringWrite( "Lleno" );
                break;
            case EMPTY_TANK:
                displayCharPositionWrite ( 0,0 );
                displayStringWrite( "Temperatura" );

                displayCharPositionWrite ( 0,1 );
                displayStringWrite( "Tanque  " );

                floatToStr(temperatureString, temperatureSensorReadCelsius());
                displayCharPositionWrite ( 11,0 );
                displayStringWrite( temperatureString );
                displayCharPositionWrite ( 14,0 );
                displayStringWrite(degreeSymbol);
                displayCharPositionWrite ( 15,0 );
                displayStringWrite( "C" );

                displayCharPositionWrite( 8,1 );
                displayStringWrite( "        " );
                displayCharPositionWrite ( 8,1 );
                displayStringWrite( "Vacio" );
                break;
            case SYSTEM_BLOCKED:
                displayClearScreen();
                displayCharPositionWrite( 5,0 );
                displayStringWrite( "ALERTA" );
                displayCharPositionWrite(2, 1);
                displayStringWrite( "TANQUE VACIO" );
            default:
                break;
        }
    } else {
        accumulatedDisplayTime =
            accumulatedDisplayTime + SYSTEM_TIME_INCREMENT_MS;        
    } 
}