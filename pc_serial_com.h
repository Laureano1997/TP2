//=====[#include guards - begin]===============================================

#ifndef _PC_SERIAL_COM_H_
#define _PC_SERIAL_COM_H_

//=====[Declaration of public defines]=========================================

#define UPDATE_TIME_SYSTEM_STATUS 10000

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void pcSerialComInit();
void pcSerialComStringWrite( const char* str );
void pcSerialComUpdate();

//=====[#include guards - end]=================================================

#endif // _PC_SERIAL_COM_H_