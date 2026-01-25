/*
Lora sender:
(component: HopeRFM95W)

This script sends hello messages over LoRa spreading factor 7

Pinout:
-------
NSS / CS > D10 (When LOW → the SX1276 tranceiver listens to SPI // When HIGH →
the SX1276 tranceiver ignores SPI // The library pulls D10 LOW whenever it talks
to the radio.) RESET	> D9 (The SX1276 tranceiver does not reliably self-reset
// The library toggles this pin during LoRa.begin()) DIO0	> D2 (interrupt
line // The SX1276 raises DIO0 HIGH when a packet is fully received or a packet
finished transmitting) MOSI	> MOSI MISO	> MISO SCK	> SCK 3.3V
> 3.3V GND	> GND

[!] don't forget to connect an antenna to pin ANT [!]
-------
*/

#include <LoRa.h>
#include <SPI.h>

int counter = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("I am your LoRa Sender");
  LoRa.setPins(10, 9, 2);  // NSS, RESET, DIO0

  // Chip: RFM95 W (SX1276)
  // Band: 868 MHz (EU / Belgium)
  // code > 868E6

  if (!LoRa.begin(868E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  // must match receiver
  LoRa.setSpreadingFactor(7);
  LoRa.setSignalBandwidth(125E3);
  LoRa.setCodingRate4(5);
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(5000);
}
