### General
⚙️ [Set-up](https://github.com/basbaccarne/HybridPrototypingTemplates/tree/main/arduino_VSC)



1️⃣ Search board name:
`arduino-cli board listall | findstr nano`

2️⃣ Get board list:
`arduino-cli board list`

3️⃣ Compile code:
`arduino-cli compile --fqbn arduino:samd:nano_33_iot blink`

4️⃣ Upload code
`arduino-cli upload -p COM7 --fqbn arduino:samd:nano_33_iot blink`


### Issues & fixes
⚠️ Arduino Nano sometimes needs the old bootloader
💡use `arduino:avr:nano:cpu=atmega328old` as board name