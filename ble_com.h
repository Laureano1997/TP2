//=====[#include guards - begin]===============================================

#ifndef _BLE_COM
#define _BLE_COM

//=====[Declaration of public defines]=========================================

#define BLE_UPDATE_TIME 1000

//=====[Declaration of public data types]======================================

//char timeStr[16];

//=====[Declarations (prototypes) of public functions]=========================

void bleComUpdate();
char* bleComRead();

void bleComWrite(const char * str);

//=====[#include guards - end]=================================================

#endif // _BLE_COM