//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "greenhouse_system.h"

#include "alarm.h"
#include "user_interface.h"
#include "pc_serial_com.h"
#include "light_control.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static status_t systemStatus = NORMAL_WORKING;

//=====[Declarations (prototypes) of private functions]========================
static void systemStatusUpdate();

//=====[Implementations of public functions]===================================

void greenhouseSystemInit()
{
    lightControlInit();
    userInterfaceInit();
    alarmInit();
    pcSerialComInit();
}

void greenhouseSystemUpdate()
{
    lightControlUpdate();
    alarmUpdate();
    systemStatusUpdate();
    userInterfaceUpdate();

    pcSerialComUpdate();
    delay(SYSTEM_TIME_INCREMENT_MS);
}

status_t greenhouseSystemStatusRead(){
    return systemStatus;
}

//=====[Implementations of private functions]==================================
static void systemStatusUpdate(){
    if(alarmBuzzerStateRead()){
        systemStatus = SYSTEM_BLOCKED;
    }else if(alarmLEDStateRead()){
        systemStatus = EMPTY_TANK;
    }else{
        systemStatus = NORMAL_WORKING;
    }
}