//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "irrigation_valve.h"
#include "alarm.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalOut irrigationValve(D10);   //Electroválvula de irrigación

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void irrigationValveInit()
{
    irrigationValve.write(OFF);
}

void irrigationValveUpdate()
{
}

bool irrigationValveRead()
{
    return irrigationValve.read();
}

void irrigationValveWrite(bool state)
{
    irrigationValve.write(state);
}

//=====[Implementations of private functions]==================================
