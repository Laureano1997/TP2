//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "greenhouse_system.h"

#include "alarm.h"
#include "user_interface.h"
#include "pc_serial_com.h"
#include "event_log.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void greenhouseSystemInit()
{
    userInterfaceInit();
    alarmInit();
    pcSerialComInit();
}

void greenhouseSystemUpdate()
{
    alarmUpdate();
    userInterfaceUpdate();

    pcSerialComUpdate();
    eventLogUpdate();
    delay(SYSTEM_TIME_INCREMENT_MS);
}

//=====[Implementations of private functions]==================================
