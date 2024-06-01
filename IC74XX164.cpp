#include <Arduino.h>
#include "IC74XX164.h"

IC74XX164::IC74XX164(uint8_t dP, uint8_t clkP, uint8_t clrP, uint8_t eP) {
  dataPin = dP;
  clockPin = clkP;
  clearPin = clrP;
  enablePin = eP;
}

IC74XX164::begin(void) {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(clearPin, OUTPUT);
  pinMode(enablePin, OUTPUT);

  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, LOW);
  digitalWrite(clearPin, HIGH);
  digitalWrite(enablePin, LOW);
}

IC74XX164::shiftLSB(uint8_t value) {
  
  digitalWrite(enablePin, HIGH);

  for(int i = 0; i < 8; i++) {
    digitalWrite(dataPin, value & (1 << i));
    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW);
  }

  digitalWrite(enablePin, LOW);
}