//=====[Libraries]=============================================================

#include "mbed.h"

#include "water_sensor.h"
#include "alarm.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalIn  tankWaterSensor(D5);    //Sensor de agua en tanque

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void waterSensorInit()
{
    tankWaterSensor.mode(PullUp);
}

void waterSensorUpdate()
{
}

bool waterSensorRead()
{
    return tankWaterSensor;
}

//=====[Implementations of private functions]==================================
