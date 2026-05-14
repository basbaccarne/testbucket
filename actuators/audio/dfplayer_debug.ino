// This is a quick example of how to use the DFRobot DFPlayer Mini MP3 module
// with an Arduino Uno. It plays a random track from the SD card every 3
// seconds.

// Wires (Arduino Uno):
// Arduino D2 (later: RX) to DF player TX
// Arduino D3 (later: TX) (via 1k resistor) to DF player RX
// Arduino GND to DF player GND
// Arduino 5V to DF player VCC
// Speaker - to DF player SPK1
// Speaker + to DF player SPK2

// Pinout

//  VCC    ) --- \__/ --- ( BUSY
//  RX     ) -          - ( USB-
//  TX     ) -          - ( USB+
//  DAC_R  ) -          - ( ADKEY_2
//  DAC_L  ) -          - ( ADKEY_1
//  SPK_1  ) -          - ( IO_2
//  GND    ) -          - ( GND
//  SPK_2  ) -          - ( IO_1
//         ----------------

// file structure in the SD card (formatted as FAT32):
// Create a folder called MP3 in the root folder
// files need to start with 4 digits: e.g. 0001.mp3, 0002.mp3, 0003.mp3, etc.
// after these 4 digits, the file name can be anything: e.g. 0001.mp3,
// 0001_hello.mp3, 0001_hello_world.mp3, etc.

// to use ffmpeg to convert to mp3: ffmpeg -i 0001.wav -vn -ar 44100 -ac 2 -b:a
// 192k 0001.mp3

// The DF player needs to be power at the same time or before the Arduino is
// powered on, otherwise it won't be detected by the Arduino.

// DFPlayer Mini - clone-compatible
//
// Wiring (Arduino Uno):
//   Arduino D2 (RX) <------- DFPlayer TX
//   Arduino D3 (TX) --[1kΩ]-> DFPlayer RX
//   Arduino GND <-----------> DFPlayer GND
//   Arduino 5V <------------> DFPlayer VCC
//   Speaker - <-------------> DFPlayer SPK1
//   Speaker + <-------------> DFPlayer SPK2
//
// SD card: FAT32, /MP3 folder in root, files named 0001.mp3, 0002.mp3, etc.

#include <SoftwareSerial.h>

#include "DFRobotDFPlayerMini.h"

SoftwareSerial AudioSerial(2, 3);
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  Serial.begin(115200);
  Serial.println("\n🎵 DFPlayer Mini starting up...");

  AudioSerial.begin(9600);
  delay(2000);

  Serial.println("🔌 Connecting (ACK mode)...");
  bool connected = myDFPlayer.begin(AudioSerial, true);

  if (!connected) {
    Serial.println("⚠️  ACK mode failed, trying clone mode...");
    delay(500);
    connected = myDFPlayer.begin(AudioSerial, false);
  }

  if (!connected) {
    Serial.println("❌ No DFPlayer found. Check wiring and SD card.");
    while (true);
  }

  Serial.println("✅ DFPlayer connected! Letting it settle...");
  delay(2000);

  myDFPlayer.volume(15);  // 0–30
  Serial.println("🔊 Volume set to 15 (goes from 0 to 30).");

  myDFPlayer.play(1);
  Serial.println("▶️ Playing track 1.");
}

void loop() {
  if (myDFPlayer.available()) {
    uint8_t type = myDFPlayer.readType();
    int value = myDFPlayer.read();

    static unsigned long lastFinished = 0;  // track last finish event time

    switch (type) {
      case DFPlayerPlayFinished:
        if (millis() - lastFinished > 500) {  // ignore duplicates within 500ms
          Serial.print("⏹️ Track ");
          Serial.print(value);
          Serial.println(" finished. Reset to retry.");
          lastFinished = millis();
        }
        break;
      case DFPlayerError:
        Serial.print("❌ Playback error, code: ");
        Serial.println(value);
        break;
      case DFPlayerCardInserted:
        Serial.println("💾 SD card inserted.");
        break;
      case DFPlayerCardRemoved:
        Serial.println("⚠️  SD card removed!");
        break;
      case DFPlayerCardOnline:
        Serial.println("💾 SD card ready.");
        break;
      default:
        if (type != 0) {
          Serial.print("❓ Unknown event type=");
          Serial.print(type);
          Serial.print(" value=");
          Serial.println(value);
        }
        break;
    }
  }
}