//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "pc_serial_com.h"
#include "greenhouse_system.h"
#include "alarm.h"
#include "temperature_sensor.h"
#include "water_sensor.h"
#include "irrigation_valve.h"
#include "soil_moisture_sensor.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

typedef enum{
    PC_SERIAL_COMMANDS,
    PC_SERIAL_GET_CODE,
    PC_SERIAL_SAVE_NEW_CODE,
} pcSerialComMode_t;

//=====[Declaration and initialization of public global objects]===============

UnbufferedSerial uartUsb(USBTX, USBRX, 115200);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============


//=====[Declaration and initialization of private global variables]============

static pcSerialComMode_t pcSerialComMode = PC_SERIAL_COMMANDS;
static bool codeComplete = false;
static int numberOfCodeChars = 0;
static char temperature[3];
static bool alertMsgSent = OFF;

//=====[Declarations (prototypes) of private functions]========================

static void pcSerialComStringRead( char* str, int strLength );

//=====[Implementations of public functions]===================================

void pcSerialComInit()
{
    pcSerialComStringWrite( "SISTEMA DE MONITOREO DE INVERNADERO:\r\n" );
    if(waterSensorRead())
        pcSerialComStringWrite( "Estado del tanque: Lleno\r\n" );
    else
        pcSerialComStringWrite( "Estado del tanque: Vacío\r\n" );

    pcSerialComStringWrite( "Temperatura del recinto:" );
    floatToStr(temperature, temperatureSensorReadCelsius());
    pcSerialComStringWrite(temperature);
    pcSerialComStringWrite("°C\r\n");

    if(soilMoistureSensorRead())
        pcSerialComStringWrite( "Estado del suelo: Humedo\r\n" );
    else
        pcSerialComStringWrite( "Estado del suelo: Seco\r\n" );

    if(irrigationValveRead())
        pcSerialComStringWrite( "Estado de la electroválvula de riego: Encendida\r\n" );
    else
        pcSerialComStringWrite( "Estado de la electroválvula de riego: Apagada\r\n" );
    pcSerialComStringWrite("\r\n");
}


void pcSerialComStringWrite( const char* str )
{
    uartUsb.write( str, strlen(str) );
}

void pcSerialComUpdate()
{
    static int accumulatedTimeSerialCom = 0;
    accumulatedTimeSerialCom = accumulatedTimeSerialCom + SYSTEM_TIME_INCREMENT_MS;
    if(alarmBuzzerStateRead() && !alertMsgSent){
        pcSerialComStringWrite("EL SISTEMA ESTÁ BLOQUEADO POR FALTA DE AGUA\r\n");
        pcSerialComStringWrite("\r\n");
        alertMsgSent = ON;
    }

    if(accumulatedTimeSerialCom > UPDATE_TIME_SYSTEM_STATUS && !alarmBuzzerStateRead()){
        pcSerialComInit();
        accumulatedTimeSerialCom = 0;
        alertMsgSent = OFF;
    }
}

//=====[Implementations of private functions]==================================

static void pcSerialComStringRead( char* str, int strLength )
{
    int strIndex;
    for ( strIndex = 0; strIndex < strLength; strIndex++) {
        uartUsb.read( &str[strIndex] , 1 );
        uartUsb.write( &str[strIndex] ,1 );
    }
    str[strLength]='\0';
}