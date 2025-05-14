//=====[Libraries]=============================================================

#include "mbed.h"

#include "soil_moisture_sensor.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalIn  soilMoistureSensor(D3); //Sensor de Humedad del suelo

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void soilMoistureSensorInit()
{
    soilMoistureSensor.mode(PullUp);
}

void soilMoistureSensorUpdate()
{
}

bool soilMoistureSensorRead()
{
    return soilMoistureSensor.read();
}

//=====[Implementations of private functions]==================================
