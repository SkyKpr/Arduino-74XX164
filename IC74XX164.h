#ifndef IC74XX164_h
#define IC74XX164_h

#include "Arduino.h"

class IC74XX164 {
  public:
    IC74XX164(uint8_t dataPin, uint8_t clockPin, uint8_t clearPin, uint8_t enablePin);
    begin(void);
    shiftLSB(uint8_t value);

    uint8_t dataPin;
    uint8_t clockPin;
    uint8_t clearPin;
    uint8_t enablePin;
};

#endif