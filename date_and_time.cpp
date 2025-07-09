//=====[Libraries]=============================================================

#include "mbed.h"

#include "date_and_time.h"
#include "pc_serial_com.h"


//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

static void RTCGetTime(char* RTCTime);

//=====[Implementations of public functions]===================================

char* dateAndTimeRead()
{
    static char dateAndTime[16] = "";
    RTCGetTime(dateAndTime);
    return dateAndTime;    
}

void updateDateAndTime(char * str){
    char *token;
    int year, month, day, hour, minute, second;

    // Get the first token
    token = strtok(str, ",");
    if (token != NULL) {
        year = atoi(token);
    }

    // Get the remaining tokens
    token = strtok(NULL, ",");
    if (token != NULL) {
        month = atoi(token);
    }

    token = strtok(NULL, ",");
    if (token != NULL) {
        day = atoi(token);
    }

    token = strtok(NULL, ",");
    if (token != NULL) {
        hour = atoi(token);
    }

    token = strtok(NULL, ",");
    if (token != NULL) {
        minute = atoi(token);
    }

    token = strtok(NULL, ",");
    if (token != NULL) {
        second = atoi(token);
    }

    dateAndTimeWrite(year, month, day, hour, minute, second);
}

void dateAndTimeWrite( int year, int month, int day, 
                       int hour, int minute, int second )
{
    struct tm rtcTime;

    rtcTime.tm_year = year - 1900;
    rtcTime.tm_mon  = month - 1;
    rtcTime.tm_mday = day;
    rtcTime.tm_hour = hour;
    rtcTime.tm_min  = minute;
    rtcTime.tm_sec  = second;

    rtcTime.tm_isdst = -1;

    set_time( mktime( &rtcTime ) );
}


//=====[Implementations of private functions]==================================

static void RTCGetTime(char* RTCTime){
    time_t epochSeconds = time(NULL);                   //Toma el tiempo del sistema
    struct tm *rtc_info = localtime(&epochSeconds);     //Lo transforma en un struct tm
    if(rtc_info!=NULL){                                 //Si devuelve un valor correcto, toma la informacion de hora, minutos y segundos 
        sprintf(RTCTime,"%02i:%02i %02i/%02i/%02i", rtc_info->tm_hour, rtc_info->tm_min,rtc_info->tm_mday,rtc_info->tm_mon+1, (rtc_info->tm_year)%100);    //y lo formatea en un string
    }
}