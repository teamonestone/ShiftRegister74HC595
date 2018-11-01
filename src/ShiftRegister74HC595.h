/*
/////////////////////////////////////////////////////	
/////  ShiftRegister74HC595 Library for Arduino	/////
/////	Copyright (c) 2018 by Jonas J. Merkle	/////
/////	    Version 1.0.0.0 -1.11.2018- 		/////
/////////////////////////////////////////////////////
*/

#ifndef ShiftRegister74HC595_h
#define ShiftRegister74HC595_h

#include <inttypes.h>
#include <avr/io.h>
#include <Arduino.h>
#include <stdbool.h>
	
////////////////////////////////
// ShiftRegister74HC595 class //	
////////////////////////////////
class ShiftRegister74HC595
{
// Begin PUBLIC ------------------------------------------------------------------
	public:
		
        //////////////////
		// constructors //
        //////////////////

		ShiftRegister74HC595(uint8_t numberOfShiftRegisters, uint8_t dataPin, uint8_t clockPin, 
                             uint8_t latch_pin, uint8_t clearPin, uint8_t oePin);
		~ShiftRegister74HC595();

        ///////////////////
        // init funktion //
        ///////////////////

        void init();            // must be called in void setup bevor using the shift register

        /////////////////////////////////////
        // funktion for the shift register //
        /////////////////////////////////////

        void clear();
        void enable();
        void disable();
        void wirteHigh();
        void writeLow();
        void writeBits(bool* arrayOfBits, uint16_t sizeOfArray);
        void wirteByte(uint8_t dataByte);

// End PUBLIC --------------------------------------------------------------------

// Begin PRIVATE -----------------------------------------------------------------
    private:	

        ///////////////////////
        // private variables //
        ///////////////////////
        uint8_t __numberOfShiftRegisters;
        uint8_t __dataPin;
        uint8_t __clockPin;
        uint8_t __latch_pin;
        uint8_t __clearPin;
        uint8_t __oePin;

        //////////////////////
        // intern functions //
        //////////////////////

        void shiftOut(bool state);

// End PRIVATE -------------------------------------------------------------------
};

#endif
