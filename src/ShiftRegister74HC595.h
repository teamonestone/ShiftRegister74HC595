/*
/////////////////////////////////////////////////////	
/////  ShiftRegister74HC595 Library for Arduino	/////
/////	Copyright (c) 2018 by Jonas J. Merkle	/////
/////	     Version 1.0.0 -1.11.2018- 		    /////
/////////////////////////////////////////////////////
*/

#ifndef ShiftRegister74HC595_h
#define ShiftRegister74HC595_h

#include <inttypes.h>
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
                             uint8_t latchPin, uint8_t clearPin, uint8_t oePin);
		~ShiftRegister74HC595();

        ///////////////////
        // init funktion //
        ///////////////////

        void init();                                                // must be called in void setup bevor using the shift register

        /////////////////////////////////////
        // funktion for the shift register //
        /////////////////////////////////////

        void clear();                                               // triggers the clear pin
        void enable();                                              // enables the output
        void disable();                                             // disables the output 
        void writeHigh();                                           // sets every output to high 
        void writeLow();                                            // sets every output to low
        void writeBit(bool state);                                   // write one Bit to the shift register
        void writeBits(bool* arrayOfBits, uint16_t sizeOfArray);    // writes data out of an bool array to the shift register
        void writeByte(uint8_t dataByte);                           // wirtes a whole byte to the shift register

// End PUBLIC --------------------------------------------------------------------

// Begin PRIVATE -----------------------------------------------------------------
    private:	

        ///////////////////////
        // private variables //
        ///////////////////////
        uint8_t __numberOfShiftRegisters;   // number of shift register in series
        uint8_t __dataPin;                  // pin number of the data pin 
        uint8_t __clockPin;                 // pin number of the clock pin
        uint8_t __latchPin;                 // pin number of the latch pin
        uint8_t __clearPin;                 // pin number of the clear pin
        uint8_t __oePin;                    // pin number of the output enable pin

        //////////////////////
        // intern functions //
        //////////////////////

        void __shiftOut(bool state);          // shift one bit to the shift register
        void __latchIt();                     // toggles the latch pin

// End PRIVATE -------------------------------------------------------------------
};

#endif
