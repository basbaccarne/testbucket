// Rotary Encoder Example:
// This code reads a rotary encoder connected to digital pins 2 and 3
// and prints the position to the Serial Monitor. It also detects button
// presses on pin 4.

// Wiring:
// Connect the encoder's A output to pin D2
// Connect the encoder's B output to pin D3
// Connect the encoder's switch output to pin 4
// Connect both grounds

#define PIN_A 2   // Encoder output A
#define PIN_B 3   // Encoder output B
#define PIN_SW 4  // Encoder push-button

int position = 0;  // Variable to store encoder position
int lastA = HIGH;  // Variable to store last state of A

void setup() {
  Serial.begin(9600);

  pinMode(PIN_A, INPUT_PULLUP);
  pinMode(PIN_B, INPUT_PULLUP);
  pinMode(PIN_SW, INPUT_PULLUP);
}

void loop() {
  int a = digitalRead(PIN_A);
  int b = digitalRead(PIN_B);

  // Detect rising edge on A
  // Logic:
  // If A goes from LOW to HIGH, check B to determine direction
  // If B is LOW, it's clockwise; if HIGH, it's counter-clockwise

  if (a == HIGH && lastA == LOW) {
    if (b == LOW)
      position++;  // clockwise
    else
      position--;  // counter-clockwise
    Serial.print("Position: ");
    Serial.println(position);
  }

  // Update lastA state
  lastA = a;

  // Simple Button press detection
  if (digitalRead(PIN_SW) == LOW) {
    Serial.println("Button pressed!");
    delay(200);  // debounce
  }

  delay(5);
}
