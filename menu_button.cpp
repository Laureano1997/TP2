//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "menu_button.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalIn  menuButton(D7);        //Botón de Menu para cambiar el menú

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================
static bool _menuButtonRead();

//=====[Implementations of public functions]===================================

void menuButtonInit()
{
    menuButton.mode(PullDown);
}

void menuButtonUpdate()
{
}

bool menuButtonRead()
{
    return _menuButtonRead();
}

//=====[Implementations of private functions]==================================

static bool _menuButtonRead(){
    if(menuButton.read()){
        delay(DEBOUNCE_BUTTON_TIME_MS);
        if(menuButton.read())
            return ON;
    }
    return OFF;
}