/*
I2C Scanner:
This code scans the I2C bus for connected devices and prints their addresses
to the Serial Wiring: Connect SDA to A4 and SCL to A5 on an Arduino Uno (+
power & ground)
*/

#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Scanning...");
}

void loop() {
  for (byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.print("Found device at 0x");
      Serial.println(addr, HEX);
    }
  }
  delay(3000);
}