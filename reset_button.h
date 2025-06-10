//=====[#include guards - begin]===============================================

#ifndef _RESET_BUTTON_H_
#define _RESET_BUTTON_H_

//=====[Declaration of public defines]=========================================

#define DEBOUNCE_BUTTON_TIME_MS   40  

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void resetButtonInit();
void resetButtonUpdate();
bool resetButtonRead();

//=====[#include guards - end]=================================================

#endif // _RESET_BUTTON_H_