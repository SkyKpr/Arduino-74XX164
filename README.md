## Arduino-74XX164

### Description
Arduino-74XX164 is a simple library for using 74XX164 8 Bit shift registers with Arduino microcontrollers.

### How to use

1. Download and copy the ```.h``` and ```.cpp``` file into your Arduino sketch directory
2. Add ```#include "IC74XX164.h"```to your ```.ino``` file
3. Initialize an object of the ```IC74XX164``` class with your data (A), clock and clear pins
4. Start the library with the ```.begin()``` functions
5. Use functions to access the register

### Example

```
#include "IC74XX164.h"

IC74XX164 shiftReg(2,3,4);

void setup() {
  shiftReg.begin();
  shiftReg.shift8Bit(255);
  delay(1000);
}

void loop() {

  //2 registers chained together -> shift 16 Bits
  shiftReg.shiftBits(0xA5A5, 16);
  delay(500);
  shiftReg.shiftBits(0x5A5A, 16);
  delay(500);

}
```
