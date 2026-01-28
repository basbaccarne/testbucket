// Rotary Encoder Example:
// This code reads a rotary encoder connected to analog pins 2 and 3
// and prints the position to the Serial Monitor. It also detects button
// presses on pin 4.

// Wiring:
// Connect the encoder's A output to pin A2
// Connect the encoder's B output to pin A3
// Swap the pins when direction is detected wrong.
// Connect the encoder's switch output to pin D4
// Connect both grounds

// install RotaryEncoder by Matthias Hertel
#include <RotaryEncoder.h>

#define PIN_IN1 A2
#define PIN_IN2 A3
#define PIN_SW 4

// Change to the appropirate code below

// Option 1: Setup a RotaryEncoder with 4 steps per latch for the 2 signal input
// pins:
RotaryEncoder encoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::FOUR3);

// Option 2: Setup a RotaryEncoder with 2 steps per latch for the 2 signal input
// pins: RotaryEncoder encoder(PIN_IN1, PIN_IN2,
// RotaryEncoder::LatchMode::TWO03);

void setup() {
  Serial.begin(115200);
  pinMode(PIN_SW, INPUT_PULLUP);
}

void loop() {
  static int pos = 0;

  encoder.tick();

  // Get position and detect changes
  int newPos = encoder.getPosition();
  if (pos != newPos) {
    Serial.print("pos:");
    Serial.print(newPos);
    Serial.print(" dir:");
    Serial.println((int)(encoder.getDirection()));
    pos = newPos;
  }

  // Detect button press
  if (digitalRead(PIN_SW) == LOW) {
    Serial.println("Button pressed!");
    delay(200);  // simple debounce
  }
}
