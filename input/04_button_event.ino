/*
 * Arduino Coding Module - Button Event (Edge Detection)
 * 
 * Target: Input handling dengan debounce dan event detection
 * 
 * Konsep:
 * - Edge detection: detect perubahan state
 * - Debounce implisit dengan loop rate
 * - Event-based input (bukan polling kontinyu)
 * - Non-blocking button reading
 */

const uint8_t BUTTON_PIN = 2;
bool lastState = HIGH; // Pull-up, so idle state is HIGH

unsigned long pressCount = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Button event handler started");
}

void loop() {
  // Read current button state
  bool currentState = digitalRead(BUTTON_PIN);

  // Edge detection: HIGH -> LOW (button press)
  if (lastState == HIGH && currentState == LOW) {
    pressCount++;
    Serial.print("Button Pressed #");
    Serial.println(pressCount);
  }

  // Edge detection: LOW -> HIGH (button release)
  if (lastState == LOW && currentState == HIGH) {
    Serial.println("Button Released");
  }

  // Update last state untuk next loop
  lastState = currentState;

  // Task lain berjalan tanpa blocking
  delay(10); // minimal debounce delay, atau gunakan non-blocking timer
}
