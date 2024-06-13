#include <Arduino.h>
#include <stdio.h>
#include "IC74XX164.h"

IC74XX164::IC74XX164(uint8_t dataP, uint8_t clkP, uint8_t clrP) {
  dataPin = dataP;
  clockPin = clkP;
  clearPin = clrP;
}

IC74XX164::begin(void) {
  
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(clearPin, OUTPUT);

  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, LOW);
  digitalWrite(clearPin, HIGH);
}

IC74XX164::shift8Bit(uint8_t value) {
  for(int i = 0; i < 8; i++) {
    digitalWrite(dataPin, value & (1 << i));
    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW);
  }
}

IC74XX164::shiftBits(uint16_t value, uint8_t lenght) {
  for(int i = 0; i < lenght; i++) {
    digitalWrite(dataPin, (bool)(value & (1 << i)));
    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW);
  }
}

IC74XX164::clockPulse(uint8_t number) {
  digitalWrite(registers[number], HIGH);

  digitalWrite(clockPin, HIGH);
  digitalWrite(clockPin, LOW);

  digitalWrite(registers[number], LOW);
}

IC74XX164::clear(void) {
  digitalWrite(clearPin, LOW);
  delay(10);
  digitalWrite(clearPin, HIGH);
}