/*
 * Arduino Coding Module - State Machine Dasar
 * 
 * Target: Alur program yang eksplisit dan mudah dikembangkan
 * 
 * Konsep:
 * - Gunakan enum untuk state yang jelas
 * - Transition state dalam switch/case
 * - Setiap state memiliki behavior spesifik
 * - Mudah untuk debug dan extend
 */

enum State {
  IDLE,
  RUNNING,
  ERROR
};

State currentState = IDLE;
unsigned long lastTransition = 0;
const unsigned long stateInterval = 1000; // 1 detik

void setup() {
  Serial.begin(9600);
  Serial.println("State Machine started");
  lastTransition = millis();
}

void loop() {
  unsigned long now = millis();

  // Setiap state dengan behavior spesifik
  switch (currentState) {
    case IDLE:
      if (now - lastTransition >= stateInterval) {
        Serial.println("[IDLE -> RUNNING]");
        currentState = RUNNING;
        lastTransition = now;
      }
      break;

    case RUNNING:
      if (now - lastTransition >= stateInterval) {
        Serial.println("[RUNNING -> ERROR]");
        currentState = ERROR;
        lastTransition = now;
      }
      break;

    case ERROR:
      if (now - lastTransition >= stateInterval) {
        Serial.println("[ERROR -> IDLE]");
        currentState = IDLE;
        lastTransition = now;
      }
      break;
  }

  // Task lain tetap berjalan
}
