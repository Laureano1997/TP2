//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "event_log.h"

#include "alarm.h"
#include "user_interface.h"
//#include "pc_serial_com.h"
#include "water_sensor.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

typedef struct systemEvent {
    time_t seconds;
    char typeOfEvent[EVENT_LOG_NAME_MAX_LENGTH];
} systemEvent_t;

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static bool alarmLEDLastState = OFF;
static bool alarmBuzzerLastState = OFF;
//static bool soilMoistureLastState = OFF;
//static bool irrigationValveLastState = OFF;
//static bool waterLastState = OFF;
//static bool SBLastState    = OFF;
static int eventsIndex     = 0;
static systemEvent_t arrayOfStoredEvents[EVENT_LOG_MAX_STORAGE];

//=====[Declarations (prototypes) of private functions]========================

static void eventLogElementStateUpdate( bool lastState,
                                        bool currentState,
                                        const char* elementName );

//=====[Implementations of public functions]===================================

void eventLogUpdate()
{
    bool currentState = alarmLEDStateRead();
    eventLogElementStateUpdate( alarmLEDLastState, currentState, "ALARM_LED" );
    alarmLEDLastState = currentState;
    
    currentState = alarmBuzzerStateRead();
    eventLogElementStateUpdate(alarmBuzzerLastState, currentState, "ALARM_BUZZER" );
    alarmBuzzerLastState = currentState;

    /*currentState = waterSensorRead();
    eventLogElementStateUpdate( waterLastState, currentState, "EMPTY_TANK" );
    waterLastState = currentState;

    currentState = systemBlockedStateRead();
    eventLogElementStateUpdate( SBLastState ,currentState, "SYSTEM_BLOCKED" );
    SBLastState = currentState;*/
}

int eventLogNumberOfStoredEvents()
{
    return eventsIndex;
}

void eventLogRead( int index, char* str )
{
    str[0] = '\0';
    strcat( str, "Event = " );
    strcat( str, arrayOfStoredEvents[index].typeOfEvent );
    strcat( str, "\r\nDate and Time = " );
    strcat( str, ctime(&arrayOfStoredEvents[index].seconds) );
    strcat( str, "\r\n" );
}

void eventLogWrite( bool currentState, const char* elementName )
{
    char eventAndStateStr[EVENT_LOG_NAME_MAX_LENGTH] = "";

    strcat( eventAndStateStr, elementName );
    if ( currentState ) {
        strcat( eventAndStateStr, "_ON" );
    } else {
        strcat( eventAndStateStr, "_OFF" );
    }

    arrayOfStoredEvents[eventsIndex].seconds = time(NULL);
    strcpy( arrayOfStoredEvents[eventsIndex].typeOfEvent, eventAndStateStr );
    if ( eventsIndex < EVENT_LOG_MAX_STORAGE -1 ) {
        eventsIndex++;
    } else {
        eventsIndex = 0;
    }

    //pcSerialComStringWrite(eventAndStateStr);
    //pcSerialComStringWrite("\r\n");
}

//=====[Implementations of private functions]==================================

static void eventLogElementStateUpdate( bool lastState,
                                        bool currentState,
                                        const char* elementName )
{
    if ( lastState != currentState ) {        
        eventLogWrite( currentState, elementName );       
    }
}
