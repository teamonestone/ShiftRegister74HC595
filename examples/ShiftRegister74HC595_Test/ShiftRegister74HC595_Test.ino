#include <ShiftRegister74HC595.h>

ShiftRegister74HC595 ShiftRegister(1, 13, 12, 11, 10, 9);

void setup() {
    ShiftRegister.init();
    ShiftRegister.enable();

    ShiftRegister.writeHigh();
    delay(1000);
    ShiftRegister.writeLow();
    delay(1000);
}

void loop() {
    for (int i = 0; i < 8; i++) {
        ShiftRegister.writeBit(1);
        delay(500);
    }

    for (int i = 0; i < 8; i++) {
        ShiftRegister.writeBit(0);
        delay(500);
    }
}
