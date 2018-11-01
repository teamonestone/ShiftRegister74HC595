/*
/////////////////////////////////////////////////////	
/////  ShiftRegister74HC595 Library for Arduino	/////
/////	Copyright (c) 2018 by Jonas J. Merkle	/////
/////	     Version 1.0.0 -1.11.2018- 		    /////
/////////////////////////////////////////////////////
*/

// Include
#include "ShiftRegister74HC595.h"

//////////////////
// constructors //
//////////////////

ShiftRegister74HC595::ShiftRegister74HC595(uint8_t numberOfShiftRegisters, uint8_t dataPin, uint8_t clockPin, 
                             uint8_t latchPin, uint8_t clearPin, uint8_t oePin) {
    __dataPin = dataPin;
    __clockPin = clockPin;
    __latchPin = latchPin;
    __clearPin = clearPin;
    __oePin = oePin;
}

ShiftRegister74HC595::~ShiftRegister74HC595() {

}

///////////////////
// init funktion //
///////////////////

void ShiftRegister74HC595::init() {
    pinMode(__dataPin, OUTPUT);
    pinMode(__clockPin, OUTPUT);
    pinMode(__latchPin, OUTPUT);
    pinMode(__clearPin, OUTPUT);
    pinMode(__oePin, OUTPUT);

    digitalWrite(__dataPin, 0);
    digitalWrite(__clockPin, 0);
    digitalWrite(__latchPin, 0);
    digitalWrite(__clearPin, 1);        // disable clear
    digitalWrite(__oePin, 1);           // disable output
}

/////////////////////////////////////
// funktion for the shift register //
/////////////////////////////////////

void ShiftRegister74HC595::clear() {
    digitalWrite(__clearPin, 0);
    digitalWrite(__clearPin, 1);
}

void ShiftRegister74HC595::enable() {
    digitalWrite(__oePin, 0);
}

void ShiftRegister74HC595::disable() {
    digitalWrite(__oePin, 1);
}

void ShiftRegister74HC595::writeHigh() {
    for (uint16_t i = 0; i < __numberOfShiftRegisters * 8; i++) {
        __shiftOut(1);
    }
    __latchIt();
}

void ShiftRegister74HC595::writeLow() {
    for (uint16_t i = 0; i < __numberOfShiftRegisters * 8; i++) {
        __shiftOut(1);
    }
    __latchIt();
}

void ShiftRegister74HC595::writeBit(bool state) {
    __shiftOut(state);
    __latchIt();
}

void ShiftRegister74HC595::writeBits(bool* arrayOfBits, uint16_t sizeOfArray) {
    for (uint16_t i = 0; i < sizeOfArray; i++) {
        __shiftOut(arrayOfBits[i]);
    }
    __latchIt();
}

void ShiftRegister74HC595::writeByte(uint8_t dataByte) {
    for (uint8_t i = 0; i < 7; i++) {
        __shiftOut(((dataByte >> (8 - i)) & 1));
    }
    __latchIt();
}

//////////////////////
// intern functions //
//////////////////////

void ShiftRegister74HC595::__shiftOut(bool state) {
    digitalWrite(__dataPin, state);

    digitalWrite(__clockPin, 1);
    digitalWrite(__clockPin, 0);
}

void ShiftRegister74HC595::__latchIt() {
    digitalWrite(__latchPin, 1);
    digitalWrite(__latchPin, 0);
}