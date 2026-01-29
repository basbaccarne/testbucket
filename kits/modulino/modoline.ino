// Modulino is a modular system for arduino components
// It uses chained I²C connections (wire.h) and Qwiic connectors
// This is a sample script with a knob (rotary encoder), buttons and a led strip
// The example uses an Arduino R4 with a led matrix that shows a heartbeat
// animation

#include <Arduino_Modulino.h>

#include "Arduino_LED_Matrix.h"

// Modulino objects
ArduinoLEDMatrix matrix;
ModulinoButtons buttons;
ModulinoPixels leds;
ModulinoKnob knob;

// Variables
ModulinoColor currentColor(0, 0, 255);
ModulinoColor lastColor(255, 255, 255);
uint8_t color_r = 0, color_g = 255, color_b = 0;
int brightness = 10;

int led_count = 8;
int last_led_count = -1;

// --------------------------------------------------

void setup() {
  Serial.begin(9600);

  matrix.begin();
  Modulino.begin();
  buttons.begin();
  leds.begin();
  knob.begin();

  matrix.loadSequence(LEDMATRIX_ANIMATION_HEARTBEAT_LINE);
  matrix.play(true);

  buttons.setLeds(false, false, false);
}

// --------------------------------------------------

void loop() {
  // ---------- BUTTONS ----------
  if (buttons.update()) {
    if (buttons.isPressed('A')) {
      currentColor = ModulinoColor(255, 0, 0);
      color_r = 255;
      color_g = 0;
      color_b = 0;
      buttons.setLeds(true, false, false);
    } else if (buttons.isPressed('B')) {
      currentColor = ModulinoColor(0, 255, 0);
      color_r = 0;
      color_g = 255;
      color_b = 0;
      buttons.setLeds(false, true, false);
    } else if (buttons.isPressed('C')) {
      currentColor = ModulinoColor(0, 0, 255);
      color_r = 0;
      color_g = 0;
      color_b = 255;
      buttons.setLeds(false, false, true);
    }
  }

  // ---------- KNOB ----------
  int8_t direction = knob.getDirection();
  if (direction == 1 && led_count < 8) {
    led_count++;
  } else if (direction == -1 && led_count > 0) {
    led_count--;
  }

  // ---------- LEDS ----------
  if (led_count != last_led_count || currentColor != lastColor) {
    for (int i = 0; i < 8; i++) {
      if (i < led_count) {
        leds.set(i, currentColor, brightness);
      } else {
        leds.set(i, ModulinoColor(0, 0, 0), 0);
      }
    }
    leds.show();

    last_led_count = led_count;
    lastColor = currentColor;

    // GET THE MESSAGE OUT
    Serial.print("LEDs: ");
    Serial.print(led_count);
    Serial.print("  Color: ");
    Serial.print(color_r);
    Serial.print(",");
    Serial.print(color_g);
    Serial.print(",");
    Serial.println(color_b);
  }

  delay(50);  // keep I²C calm
}
