//=====[#include guards - begin]===============================================

#ifndef _MENU_BUTTON_H_
#define _MENU_BUTTON_H_

//=====[Declaration of public defines]=========================================

#define DEBOUNCE_BUTTON_TIME_MS   40  

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void menuButtonInit();
void menuButtonUpdate();
bool menuButtonRead();

//=====[#include guards - end]=================================================

#endif // _MENU_BUTTON_H_