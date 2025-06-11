//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "alarm.h"
#include "greenhouse_system.h"
#include "water_sensor.h"
#include "temperature_sensor.h"
#include "reset_button.h"
#include "soil_moisture_sensor.h"
#include "irrigation_valve.h"


//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalOut emptyWaterLED(LED1);//D11);     //LED de alarma (Ausencia de agua)
DigitalOut emptyWaterBuzzer(LED2);//D12);  //Buzzer de alarma (Ausencia de agua prolongada)

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static bool irrigationValveState = OFF;
static bool waterSensorState = ON;
static bool alarmLEDState = OFF;
static bool alarmBuzzerState = OFF;
static bool timeReset = OFF;
static status_t systemStatus = NORMAL_WORKING;

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void alarmInit()
{
    waterSensorInit();
    temperatureSensorInit();
    resetButtonInit();
    soilMoistureSensorInit();
    irrigationValveInit();
    emptyWaterLED = OFF;
    emptyWaterBuzzer = OFF;
}

bool alarmLEDStateRead()
{
    return alarmLEDState;
}

bool alarmBuzzerStateRead()
{
    return alarmBuzzerState;
}

void alarmLEDStateWrite( bool state )
{
    alarmLEDState = state;
}

void alarmBuzzerStateWrite( bool state )
{
    alarmBuzzerState = state;
}

void alarmUpdate()
{
    temperatureSensorUpdate();
    waterSensorUpdate();
    soilMoistureSensorUpdate();
    irrigationValveUpdate();

    static int accumulatedTimeAlarm = 0;
    accumulatedTimeAlarm = accumulatedTimeAlarm + SYSTEM_TIME_INCREMENT_MS;
    
    if(resetButtonRead()){
        alarmBuzzerState = OFF; //Al Switch
        timeReset = OFF;    //Al Switch
        systemStatus = NORMAL_WORKING;
    }

    waterSensorState = waterSensorRead();

    if(!waterSensorState){
        alarmLEDState = ON;
        systemStatus = EMPTY_TANK;
        irrigationValveState = OFF;
    }
    else{
        alarmLEDState = OFF;
        if(soilMoistureSensorRead())
            irrigationValveState = OFF;
        else
            irrigationValveState = ON;
    }

    irrigationValveWrite(irrigationValveState);

    if( alarmLEDState ) {
        emptyWaterLED = ON;
        if(!timeReset){
            timeReset = ON;
            accumulatedTimeAlarm = 0;
        }
    } else {
        emptyWaterLED = OFF;
    }

    if(emptyWaterLED && accumulatedTimeAlarm > ALARM_BUZZ_ACTIVATION_TIME){
        systemStatus = SYSTEM_BLOCKED;
        alarmBuzzerState = ON;
    }

    if(!emptyWaterLED && !alarmBuzzerState)
        accumulatedTimeAlarm = 0;

    if( alarmBuzzerState ) {
        if( accumulatedTimeAlarm >= ALARM_BUZZ_TIME ) {
                accumulatedTimeAlarm = 0;
                emptyWaterBuzzer= !emptyWaterBuzzer;
        }
    } else {
        emptyWaterBuzzer = OFF;
        systemStatus = EMPTY_TANK;
    }
}

status_t alarmSystemStatus(){
    return systemStatus;
}


//=====[Implementations of private functions]==================================

