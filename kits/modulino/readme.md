# Modulino
Modulino is [Arduino’s modular hardware system](https://store.arduino.cc/collections/modulino). It follows a philosophy similar to the Grove ecosystem (Seeed Studio): plug-and-play, PCB-ready components that are quick and easy to connect. But, Modulina adds an extra layer of elegance.

First, it uses the smaller **Qwiic connector**. Second, all communication happens over **I²C** (often loosely referred to as “one-wire”, using SDA/SCL). Components are configured to be **daisy-chained** in any direction, making physical layouts very flexible. Each module includes a status LED to confirm correct power and connectivity, and everything is supported by an intuitive, high-level **library** that makes controlling the hardware straightforward. The components also have extra solder pads to directly access the raw component data or the SDA.SCL, power & ground lines.

* [Library Documentation](https://github.com/arduino-libraries/Arduino_Modulino/tree/main/docs)
* [Examples](https://github.com/arduino-libraries/Arduino_Modulino/tree/main/examples)


<div align="center">  
 <img src="/kits/modulino/modulino.gif" width="400"> <br>
 (<a href = /kits/modulino/modulino.ino>code of the video above</a>)
</div>




