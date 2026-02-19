/*
 * CONTOH 5: SERIAL KOMUNIKASI & STATE MACHINE
 * 
 * Konsep:
 * - Komunikasi 2-arah dengan komputer via serial
 * - State machine untuk manage berbagai mode
 * - Parsing command dari serial
 * 
 * Hardware:
 * - Arduino board (USB connection)
 * - LED dan resistor 220Ω
 * 
 * Komunikasi:
 * - Buka Serial Monitor (9600 baud)
 * - Ketik: ON, OFF, BLINK, STATUS
 */

#include <String.h>

const int LED_PIN = 13;

// State machine
enum State {
  STATE_OFF,
  STATE_ON,
  STATE_BLINK
};

State currentState = STATE_OFF;
unsigned long lastBlinkTime = 0;
const unsigned long BLINK_INTERVAL = 500;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.begin(9600);
  writeStartupMessage();
}

void loop() {
  // Baca command dari serial
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();  // Hapus whitespace
    command.toUpperCase();  // Convert ke uppercase
    
    processCommand(command);
  }
  
  // Update state machine
  updateStateMachine();
}

void processCommand(String cmd) {
  if (cmd == "ON") {
    currentState = STATE_ON;
    digitalWrite(LED_PIN, HIGH);
    Serial.println("✓ LED ON");
  }
  else if (cmd == "OFF") {
    currentState = STATE_OFF;
    digitalWrite(LED_PIN, LOW);
    Serial.println("✓ LED OFF");
  }
  else if (cmd == "BLINK") {
    currentState = STATE_BLINK;
    Serial.println("✓ LED BLINKING");
  }
  else if (cmd == "STATUS") {
    printStatus();
  }
  else if (cmd == "HELP") {
    writeStartupMessage();
  }
  else {
    Serial.print("? Unknown command: ");
    Serial.println(cmd);
  }
}

void updateStateMachine() {
  switch(currentState) {
    case STATE_OFF:
      // Tidak ada action
      break;
      
    case STATE_ON:
      // LED tetap ON (sudah di digitalWrite)
      break;
      
    case STATE_BLINK:
      if (millis() - lastBlinkTime >= BLINK_INTERVAL) {
        lastBlinkTime = millis();
        digitalWrite(LED_PIN, !digitalRead(LED_PIN));
      }
      break;
  }
}

void printStatus() {
  Serial.print("Current State: ");
  switch(currentState) {
    case STATE_OFF:
      Serial.println("OFF");
      break;
    case STATE_ON:
      Serial.println("ON");
      break;
    case STATE_BLINK:
      Serial.println("BLINKING");
      break;
  }
  
  Serial.print("LED Pin: ");
  Serial.println(digitalRead(LED_PIN) ? "HIGH" : "LOW");
}

void writeStartupMessage() {
  Serial.println("\n========== Arduino LED Control ==========");
  Serial.println("Commands:");
  Serial.println("  ON     - Turn LED on");
  Serial.println("  OFF    - Turn LED off");
  Serial.println("  BLINK  - Blink LED");
  Serial.println("  STATUS - Show current state");
  Serial.println("  HELP   - Show this message");
  Serial.println("=========================================\n");
}

/*
PENJELASAN STATE MACHINE:

State machine = sistem dengan beberapa state terdefinisi
Setiap state punya behavior tertentu dan transition rules

Visual:
       ┌──(ON)──┐
       ▼        │
     [ON] ─(OFF/BLINK)─┐
       ▲               │
       └────(ON)───[OFF]
              │
          (BLINK)│
              ▼
           [BLINK]    ◄── blink otomatis
              │
      (ON/OFF)└─●

SERIAL KOMUNIKASI:

1. Serial.available():
   - Return jumlah byte yang ada di buffer
   - Gunakan untuk check apakah ada data incoming

2. Serial.readStringUntil('\n'):
   - Baca sampai newline ('\n')
   - Simpan ke String

3. String.trim():
   - Hapus whitespace: spaces, tabs, newlines

4. String.toUpperCase():
   - Convert semua character ke uppercase
   - Membuat command case-insensitive

KEUNTUNGAN DESIGN INI:
✓ Mudah ditambah command baru
✓ State jelas dan manageable
✓ Transition explicit dan safe
✓ Debug-friendly (printStatus)

EXPERIMENT:
- Tambah state baru (e.g., STATE_PULSE dengan brightness changing)
- Kirim sensor data ke serial setiap detik
- Parse numeric value: "BRIGHTNESS:150"
- Buat data logging di komputer
*/
