//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "reset_button.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalIn  resetButton(D2);        //Botón de Reset para apagar el buzzer

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================
static bool _resetButtonRead();

//=====[Implementations of public functions]===================================

void resetButtonInit()
{
    resetButton.mode(PullDown);
}

void resetButtonUpdate()
{
}

bool resetButtonRead()
{
    return _resetButtonRead();
}

//=====[Implementations of private functions]==================================

static bool _resetButtonRead(){
    if(resetButton.read()){
        delay(DEBOUNCE_BUTTON_TIME_MS);
        if(resetButton.read())
            return ON;
    }
    return OFF;
}