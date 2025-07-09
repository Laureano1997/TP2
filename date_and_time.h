//=====[#include guards - begin]===============================================

#ifndef _DATE_AND_TIME_H_
#define _DATE_AND_TIME_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//char timeStr[16];

//=====[Declarations (prototypes) of public functions]=========================

char* dateAndTimeRead();

void dateAndTimeWrite( int year, int month, int day, 
                       int hour, int minute, int second );

void updateDateAndTime(char * str);

//=====[#include guards - end]=================================================

#endif // _DATE_AND_TIME_H_