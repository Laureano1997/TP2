//=====[#include guards - begin]===============================================

#ifndef _ALARM_H_
#define _ALARM_H_

//=====[Declaration of public defines]=========================================

#define ALARM_BUZZ_ACTIVATION_TIME 10000
#define ALARM_BUZZ_TIME 500     //Mitad del período de el buzzer

//=====[Declaration of public data types]======================================

typedef enum{
    NORMAL_WORKING,
    EMPTY_TANK,
    SYSTEM_BLOCKED
}status_t;

//=====[Declarations (prototypes) of public functions]=========================

void alarmInit();
bool alarmLEDStateRead();
bool alarmBuzzerStateRead();
void alarmLEDStateWrite( bool state );
void alarmBuzzerStateWrite( bool state );
void alarmUpdate();
status_t alarmSystemStatus();

//=====[#include guards - end]=================================================

#endif // _ALARM_H_
