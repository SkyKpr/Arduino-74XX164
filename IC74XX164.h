#ifndef IC74XX164_h
#define IC74XX164_h

#include "Arduino.h"

class IC74XX164 {
  public:
    IC74XX164(uint8_t dataP, uint8_t clkP, uint8_t clrP);
    begin(void);
    shift8Bit(uint8_t value);
    shiftBits(uint16_t value, uint8_t lenght);
    clockPulse(uint8_t  number);
    clear(void);

    uint8_t dataPin;
    uint8_t clockPin;
    uint8_t clearPin;
    uint8_t registers[6];
};

#endif