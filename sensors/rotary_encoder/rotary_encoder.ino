// Code to test the Pimoroni RGB Encoder Breakout (PIM522)
// Wiring: connect power, ground, SDA & SCL
// You'll need the IOExpander_Library
// (https://github.com/ZodiusInfuser/IOExpander_Library/)

// The code sets the led to green and prints out the encoder count as it
// changes.

#include <EncBreakout.h>
#include <Wire.h>

EncBreakout enc(Wire, 0x0F);  // I2C polling mode

/* info:
The line abocve creates an EncBreakout object named enc that stores:
* A reference to the I²C bus (Wire)
* The I²C address (0x0F=default)

This does NOT talk to the hardware yet
No I²C traffic happens here (it just sets up internal variables).
*/

void setup() {
  Serial.begin(9600);

  // Initialize the Arduino as an I²C master & enable SDA/SCL pins
  Wire.begin();

  // enc.initialise() sends an I²C request to address 0x0F
  if (!enc.initialise()) {
    Serial.println("Encoder not found");
    while (1);
  } else
    Serial.println("Encoder found");

  enc.setRGB(0, 255, 0);  // Green = OK
}

void loop() {
  /* enc.read() sends an I²C read request to the breakout and retrieves:
   - Current encoder position (a signed integer)
   - Button state (internally)
   - Updates internal cached state inside EncBreakout object
   */

  int16_t count = enc.read();
  static int16_t last = 0;

  if (count != last) {
    Serial.println(count);
    last = count;
  }

  delay(10);
}