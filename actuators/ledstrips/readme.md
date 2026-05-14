# Addressable LED Strips

LED strips come in two variants: single data line (Din, 3 wires) or clock + data (SPI, 4 wires).

## Examples

- [Test LED strip SPI all red](led_red.ino)
- [Test LED strip SPI rainbow](led_rainbow.ino)
- [Test LED stick Din chase](led_stick.ino)

## Din Wiring

**Data line** — Arduino Pin 6 → DIN. For longer cable runs (30cm+), add a 330–470 Ω resistor in series to damp signal reflections. For short connections, skip the resistor — it can degrade the signal enough to cause communication failures.

**Power** — Use a stable 5V external power supply.

**Capacitor** — Add 470–1000 µF between 5V and GND, placed close to the LEDs. This smooths power dips and prevents flicker. Polarity matters: long leg (+) to 5V, short leg (–) to GND. The stripe on the capacitor marks the negative (–) side.

**Ground** — Connect all grounds together.

## SPI Wiring

- **CO** (clock) → Pin 13 (SCK)
- **DO** (data) → Pin 11 (MOSI)
- Increase supply voltage incrementally if behavior is unstable
- Connect all grounds together

**Capacitor** — same as Din: add 470–1000 µF between 5V and GND close to the LEDs.

**Resistors** — less critical than Din (the clock keeps things synchronized), but for longer runs it's good practice to put a 100–470 Ω resistor on both CLK and DATA to reduce signal ringing.

# Non-addressable LED Strips
Some led strips are non-addressable, meaning all LEDs show the same color. 
These come in single color or in rgb variants. You can set the brightness using pwm (analogWrite).

## Wiring
For a led strip that has e.g. a 12V pin, an R, G and B pin, you can connect the 12V pin to a 12V power supply. THe led color is activated when you connect the R, G or B pin to ground.   

When it has just a positive and a negative pin, you can connect the positive pin to a power supply and the negative pin to ground. 

**beware**: a led strip typically draws 1-2A, which is more than an arduino pin can handle. You need to use a transistor, mosfet or a relay to switch the led strip on and off.