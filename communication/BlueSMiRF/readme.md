### General
* BlueSMiRF is a **Bluetooth to Serial** interface similar to the HC05.   
* It connects the microcontroller's (or any other device) **RX/TX signals** (that you can read and write using Serial) to a device that can read and write serial data over USB (e.g. smartphone or laptop)
* Range: Ongeveer **33 m** indoor
* De devices hebben ook een **pair button** waarmee je makkelijk devices aan elkaar kan koppelen.
    * Short Push — Press and hold the button down between 4 to 8 seconds will initiate pairing with another Bluetooth device. During that period of time, the Status and Connect LEDs will slowly blink back and forth. When the BlueSMiRF v2 fails to discover any compatible devices, it will enter Discoverable mode.
    * Long Push — Press and hold the down for more than 8 seconds to set the ESP32 back to its factory default settings.

### Setup (changing default settings, e.g. baud rate, name, ..)
* Gebruik een serial to USB converter
* Verbind Vcc, Ground, RX(I) & TX(0)
* Verbind met een Serial Monitor (baud: 115200)
* Send `$$$` to enter AT command mode (zonder enter)
* Use AT command `ata` to see all the settings
* An issue with PCs can be slow pairing time. A possible fix is to increase the timeout: `AT-BluetoothConnectTimeoutMs=15000`

### Setup (wiring etc)
* For a quick test without a microcontroller, gebruik een serial to USB converter en verbind Vcc, Ground, RX(I) & TX(0)
* Add the bluetooth device on Windows and two COM ports will be added (one is send, the other is receive)
* Don't worry if the LED blinks (indicating no connection). Once you open the serial connection, the connection will be established.
* Open een verbinding met de serial to USB connector (via een Serial Monitor (baud: 115200))
* Open een verbinding met de bluetooth receiver in een tweede Serial Monitor
* Wat je typt via de Rx/Tx monitor zal nu zichtbaar zijn in de bluetooth monitor.

### Led indicators
*CONNECT LED*
The connect LED indicates when the ESP32 is connected to another Bluetooth device. The behavior of the LED will depend on the mode:
* 0 — By default, the CONNECT LED will blink until it is connect to another Bluetooth device. Once connected, this LED will remain solid.
* 1 — When set to a 1, the CONNECT LED will blink until it is connected to another Bluetooth device. Once connected, this LED will blink with TX traffic.

*STATUS LED*
The status LED indicates when there is UART traffic. The behavior of the LED will depend on the mode.
* 0 — By default, the STATUS LED blinks with any TX/RX traffic.
* 1 — When set to a 1, the STATUS LED blinks with only the RX traffic.

### Default settings
```ini
AT-BluetoothConnectRetries=5 
AT-BluetoothConnectTimeoutMs=3000 
AT-BluetoothEscapeCharacter=+ 
AT-BluetoothNickname=BlueSMiRF-F282 
AT-BluetoothPairedMac= 
AT-BluetoothPairedName= 
AT-BluetoothPin=1234 
AT-BluetoothRxSize=2048 
AT-BluetoothTxSize=1024 
AT-BluetoothType=0 
AT-EscapeCharacter=$ 
AT-EscapeCharacterCount=3 
AT-FlowControl=0 
AT-InvertCts=0 
AT-InvertRts=0 
AT-LedStyle=0 
AT-MaxCommandTimeMs=60000 
AT-MinEscapeTimeMs=2000 
AT-PartialFrameTimeoutMs=50 
AT-RtsStartSendingPercent=25 
AT-RtsStopSendingPercent=5 
AT-SerialReceiveBufferSize=51200 
AT-SerialSpeed=115200 
AT-SerialTransmitBufferSize=10240 
AT-WiFiPassword= 
AT-WiFiSSID=
```