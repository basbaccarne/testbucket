// Code to connect a BlueSMiRF module to an Arduino and send data
// See documentation in this folder for set-up instructions

// Wiring:
// Connect power & ground
// Connect BlueSMiRF TX to Arduino pin 2 (RX)
// Connect BlueSMiRF RX to Arduino pin 3 (TX) via a voltage divider

#include <SoftwareSerial.h>

SoftwareSerial btSerial(3, 2);  // RX, TX

void setup() {
  btSerial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  btSerial.println(1);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);

  btSerial.println(0);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

// Connect device using PC or smartphone and monitor the data received.