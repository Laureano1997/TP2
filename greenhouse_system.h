//=====[#include guards - begin]===============================================

#ifndef _GREENHOUSE_SYSTEM_H_
#define _GREENHOUSE_SYSTEM_H_

//=====[Declaration of public defines]=========================================

#define EMPTY_TANK_MESSAGE "El tanque está vacío, por favor rellenar\n" //Mensaje de error ante tanque vacío
#define STATUS_MESSAGE "La temperatura del recinto es de: "             //Mensaje que acompaña la temperatura del recinto
#define CELSIUS_DEGREES "°C\n"
#define SYSTEM_TIME_INCREMENT_MS   10

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void greenhouseSystemInit();
void greenhouseSystemUpdate();

//=====[#include guards - end]=================================================

#endif // _GREENHOUSE_SYSTEM_H_ 