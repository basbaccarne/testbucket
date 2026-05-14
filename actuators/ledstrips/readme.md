# LED strips
LED strips come with a single Din line (3 wires), or with a clock and data line (SPI, 4 wires).
* 🔴 [Test led strip SPI all red](led_red.ino)
* 🌈 [Test led strip SPI rainbow](led_rainbow.ino)
* 🚨[Test led stick Din chase](led_stick.ino)


# Din
📡 DATA LINE
* Arduino Pin 6 ──[330–470 Ω]──> DIN (NeoPixel) (Resistor Protects the first LED from signal spikes)

⚡ POWER
* Use a stable 5V EXTERNAL power supply

🔋 CAPACITOR
* Add 470–1000 µF between 5V and GND (close to LEDs) (This smooths power dips (prevents flicker/glitches))
* Polarity matters:
    * ➕ Long leg = + → connect to 5V
    * ➖ Short leg = – → connect to GND
    * ⚠️ Stripe on the capacitor = NEGATIVE (–)

🔗 GROUND
* Connect all grounds

# SPI
* uses CO (clock) > connected to Pin 13 (SCK) 
* and DO (data) > connected to Pin 11 (MOSI)
* Check power voltage (an increase incrementally if you're not sure)
* connect all grounds together