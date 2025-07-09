//=====[Libraries]=============================================================

#include "mbed.h"

#include "ble_com.h"
#include "greenhouse_system.h"
#include "date_and_time.h"
#include "light_control.h"
#include "soil_moisture_sensor.h"
#include "water_sensor.h"
#include "irrigation_valve.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

UnbufferedSerial uartBle(PD_5, PD_6, 9600);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

static char bleComCharRead();
static void bleComStringRead(char* string,size_t len);

//=====[Implementations of public functions]===================================

void bleComUpdate(){
    static int accumulatedTimeBleCom = 0;
    accumulatedTimeBleCom = accumulatedTimeBleCom + SYSTEM_TIME_INCREMENT_MS;
    char receivedChar = bleComCharRead();
    char lightLevel[5]="";
    int dutyCycle;
    char soilAndTank[5]="";

    if(accumulatedTimeBleCom > BLE_UPDATE_TIME){
        sprintf(soilAndTank,"%1i%1i\n", soilMoistureSensorRead(), waterSensorRead());
        bleComWrite(dateAndTimeRead());
        bleComWrite(soilAndTank);
        accumulatedTimeBleCom = 0;
    }

}

void bleComWrite(const char * str){
    uartBle.write( str, strlen(str) );
}
//=====[Implementations of private functions]==================================

static char bleComCharRead(){
    char receivedChar = '\0';
    if( uartBle.readable() ) {
        uartBle.read(&receivedChar,1);
    }
    return receivedChar;
}

static void bleComStringRead(char* string, size_t len){
    if(uartBle.readable())
        uartBle.read(&string, len);
    string[len] = '\0';
}

