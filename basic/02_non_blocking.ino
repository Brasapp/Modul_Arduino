/*
 * Arduino Coding Module - Non-Blocking Timing
 * 
 * Target: Timing tanpa delay() - semua task berjalan paralel
 * 
 * Prinsip:
 * - Semua task berjalan parallel di loop yang sama
 * - Tidak ada blocking dengan delay()
 * - Cek condition dengan millis() untuk eksekusi periodik
 * - Scalable untuk multiple tasking
 */

const uint8_t LED_PIN = 13;
unsigned long lastToggle = 0;
const unsigned long interval = 1000; // 1 detik

bool ledState = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Non-blocking timer started");
}

void loop() {
  unsigned long now = millis();

  // Task 1: Toggle LED setiap 1 detik (non-blocking)
  if (now - lastToggle >= interval) {
    lastToggle = now;
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    Serial.print("LED toggled: ");
    Serial.println(ledState);
  }

  // Task lain bisa jalan di sini tanpa tertunda
  // Task 2, Task 3, etc...
}
