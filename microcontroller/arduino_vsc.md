### General
⚙️ [Set-up](https://github.com/basbaccarne/HybridPrototypingTemplates/tree/main/arduino_VSC)



1️⃣ Search board name:
`arduino-cli board listall | findstr nano`

2️⃣ Get board list:
`arduino-cli board list`

3️⃣ Compile code:
`arduino-cli compile --fqbn arduino:avr:uno blink`

4️⃣ Upload code
`arduino-cli upload -p COM13 --fqbn arduino:avr:uno blink`


### Issues & fixes
⚠️ Arduino Nano sometimes needs the old bootloader
💡use `arduino:avr:nano:cpu=atmega328old` as board name