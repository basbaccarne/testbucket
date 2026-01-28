## Type 1: rotary encoders with a push button
e.g. **[Bourns 24 Pulse Incremental Mechanical Rotary Encoder with a 6 mm Flat Shaft](https://benl.rs-online.com/web/p/mechanical-rotary-encoders/1675389)**   

A first type of encorder is a rotary encoder with push button.
These often have a 2x3 pin layout. Looked at from the bottom:
```
                - out A
switch -
                - ground
ground -    
                - out B
```
Connect outA, outB and the swith to e.g. D2,D3 and D4 (Connect both grounds).
* [Example code](/sensors/rotary_encoder/rotary_encoder.ino)

### Type 2: integrated rotary encoders with RGB leds  
e.g. **[Pimoroni RGB Encoder Breakout](https://opencircuit.nl/product/breakout-rgb-encoder)**    

This Encoder has no direct pins exposed but is controlled over an on board Nuvoton MS51 microcontroller that handles both the encoder and the led. You can communicate with this microcontroller over I²C.
* In Arduino, you'll need the [IOExpander Library](https://github.com/ZodiusInfuser/IOExpander_Library)
* [Example code](/sensors/rotary_encoder/rotary_encoder_LEDbreakout.ino)