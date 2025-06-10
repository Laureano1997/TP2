//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "light_control.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

AnalogIn reference(A2);
PwmOut lamp = PB_4; //{(PB_4), (PA_0), (PD_12)};

//=====[Declaration and initialization of private global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static void setPeriod( float period );
static void setDutyCycle( float dutyCycle );

//=====[Implementations of public functions]===================================

void lightControlInit()
{
    setPeriod( 0.01f );
    setDutyCycle( 0.5f );
}

void lightControlUpdate(){
    setDutyCycle(reference.read());
}

int lightControlRead(){
    return (int) 100*reference.read();
}

//=====[Implementations of private functions]==================================

static void setPeriod( float period )
{
    lamp.period(period);
}

static void setDutyCycle( float dutyCycle )
{
    lamp.write(dutyCycle);
}