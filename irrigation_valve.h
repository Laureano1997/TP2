//=====[#include guards - begin]===============================================

#ifndef _IRRIGATION_VALVE_H_
#define _IRRIGATION_VALVE_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void irrigationValveInit();
void irrigationValveUpdate();
bool irrigationValveRead();
void irrigationValveWrite(bool state);

//=====[#include guards - end]=================================================

#endif // _IRRIGATION_VALVE_H_