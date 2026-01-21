// quick check of pin function & voltage
// internal led + serial message for extra debugging

#define PIN_TO_CHECK 2

void setup() {
  pinMode(PIN_TO_CHECK, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Go high
  Serial.begin(9600);
  Serial.println("1 ");
  digitalWrite(PIN_TO_CHECK, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);

  // Go low
  digitalWrite(PIN_TO_CHECK, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("0");
  delay(1000);
}