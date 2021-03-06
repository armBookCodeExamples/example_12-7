//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "relay.h"

#include "buttons.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

static DigitalInOut relayControlPin(PF_2);

//=====[Declaration and initialization of private global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Implementations of public functions]===================================

void relayInit()
{
    relayControlPin.mode(OpenDrain);
    relayControlPin.input();
}

void relayUpdate()
{
    buttonsStatus_t buttonsStatusLocalCopy;

    buttonsStatusLocalCopy = buttonsRead();

    if( buttonsStatusLocalCopy.changeMode ) {
        relayControlPin.output();                                     
        relayControlPin = LOW;            
    } else {
        relayControlPin.input(); 
    }
}

void relayRead()
{
}