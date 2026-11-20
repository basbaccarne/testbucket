# Load Cells
## S Type
An S-Type load cell (also called an S-beam load cell) is a force sensor shaped like the letter S, designed to measure forces applied in either tension (pulling) or compression (pushing). It converts mechanical deformation into an electrical signal, which can be measured and translated into force or weight.   

**Requires an amplfier:** The amplifier (typically an ```HX711 module```) is the intermediary between the load cell and your Arduino. The load cell produces an extremely small electrical signal, which is too weak for an Arduino to measure reliably and directly. 

### test
**Hardware**
* [HX11](https://www.tinytronics.nl/en/sensors/weight-pressure-force/load-cells/load-cell-amplifier-hx711)
* [Mavin Load Cell - S Type - 50kg](https://www.tinytronics.nl/en/sensors/weight-pressure-force/load-cells/mavin-load-cell-s-type-50kg)



**Pinout from sensor to HX711**
|  Pin |  Meaning | Function | Wire Color on Mavin Load Cell |
| --- | --- | --- | --- |
|  E+ | Excitation + | Positive supply voltage to the load cell | Red |
|  E− | Excitation − | Negative supply / ground reference for the load cell | Black |
|  A+ | Channel A + | Positive measurement signal | Green |
|  A− | Channel A − | Negative measurement signal | White |
|  B+ | Channel B + | Positive measurement signal | *for four-wire load cells* |
|  B− | Channel B − | Negative measurement signal |  *for four-wire load cells*|
|  *not connected* | Shielding   | Shielding for the load cell   | Transparent |



**Pinout from HX711 to Arduino:**
|  Arduino |  HX711 | Function | Wire Color|
| --- | --- | --- | --- |
| 5V | VCC | Power supply for the HX711 module | Red |
| GND | GND | Ground connection | Black |
| D2 | DT | Data output from HX711 to Arduino | Green |
| D3 | SCK | Clock input from Arduino to HX711 | White |

*Note:* The HX711 clock is not the same as the Arduino's hardware SPI clock (SCK). The HX711 uses its own simple two-wire serial protocol, so you can use ordinary digital pins.

**Code**
```cpp

#include "HX711.h"

// HX711 connections
#define HX711_DOUT 2   // DT -> Arduino D2
#define HX711_SCK  3   // SCK -> Arduino D3

HX711 scale;

// Calibration factor (calibrated using a 258 gram weight)
float calibration_factor = 87729.0;

void setup() {
  Serial.begin(9600);

  scale.begin(HX711_DOUT, HX711_SCK);

  Serial.println("Load cell initialization...");

  // Wait for HX711 to become ready (maximum 5 seconds)
  unsigned long startTime = millis();

  while (!scale.is_ready() && millis() - startTime < 5000) {
    delay(100);
  }

  if (scale.is_ready()) {
    Serial.println("HX711 detected!");
  } else {
    Serial.println("ERROR: HX711 not responding!");
    while (1) {
      delay(1000);
    }
  }

  // Set calibration factor
  scale.set_scale(calibration_factor);

  // Zero the load cell
  Serial.println("Taring... remove all load!");
  delay(2000);

  scale.tare(20);

  Serial.println("Zero established.");
  delay(500);

  Serial.println("Ready!");
  Serial.println("------------------------------");
}

void loop() {

  if (scale.is_ready()) {

    // Read measurement
    // 10 specifies the number of measurements the HX711 takes and averages to calculate the result.
    // Lower = faster but more noise, higher = slower but more stable.
    float weight_kg = scale.get_units(10);

    // Convert kg to Newtons
    float force_N = weight_kg * 9.80665;

    Serial.print("Weight: ");
    Serial.print(weight_kg, 3);
    Serial.print(" kg");

    Serial.print("  |  Force: ");
    Serial.print(force_N, 2);
    Serial.println(" N");

  } else {
    Serial.println("HX711 not ready");
  }

  delay(200);
}


```


**Notes**

* The GND and AGND are not connected on the HX11. Connect GND to pin 5 (= E-).
* Replace R12 with 12k to use with 3V3 on Vcc.