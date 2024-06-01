## Arduino-74XX164

### Description
Arduino-74XX164 is a simple library for using 74XX164 8 Bit shift registers with Arduino microcontrollers.

### How to use

1. Download and copy the ```.h``` and ```.cpp``` file into your Arduino sketch directory
2. Add ```#include "IC74XX164.h"```to your ```.ino``` file
3. Initialize an object of the ```IC74XX164``` class with your data (A), enable (B), clock and enable pin
4. Start the library with the ```.begin()``` functions
5. Use functions to access the register

### Example

```
#include "IC74XX164.h"

IC74XX164 shiftReg(5,6,7,8);

void setup() {
  shiftReg.begin();
}

void loop() {

  byte shiftValue = 1;

  for(int i = 0; i < 8; i++) {
    shiftReg.shiftLSB(shiftValue);
    shiftValue = shiftValue << 1;
    delay(100);
  }

  shiftReg.shiftLSB(255);
  delay(100);

}
```
