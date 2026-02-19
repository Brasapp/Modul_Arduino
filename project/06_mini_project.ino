/*
 * Arduino Coding Module - Mini Project: Multi-Task Loop Controller
 * 
 * Target: Kombinasi semua konsep - multiple non-blocking tasks
 * 
 * Spesifikasi:
 * - LED toggle setiap 500ms (non-blocking)
 * - Log status setiap 2 detik
 * - Handle serial command
 * - Tidak ada delay() di main loop
 * 
 * Kriteria Kelulusan:
 * ✅ Semua task berjalan bersamaan
 * ✅ Tidak ada delay() di loop() utama
 * ✅ Kode mudah dibaca dan maintainable
 * ✅ Mudah untuk menambah task baru
 */

// Task 1: LED Blinking
unsigned long tBlink = 0;
const unsigned long intervalBlink = 500;
bool ledState = false;

// Task 2: System Logging
unsigned long tLog = 0;
const unsigned long intervalLog = 2000;

// Task 3: Serial Command
String serialCmd = "";

// System counter
unsigned long systemUptime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  
  Serial.println("=============================");
  Serial.println("  Multi-Task Loop Controller");
  Serial.println("=============================");
  Serial.println("Commands: INFO, HELP, LED_ON, LED_OFF");
  Serial.println("");
}

void loop() {
  unsigned long now = millis();

  // Task 1: LED Blinking (500ms interval)
  if (now - tBlink >= intervalBlink) {
    tBlink = now;
    ledState = !ledState;
    digitalWrite(13, ledState);
  }

  // Task 2: System Logging (2s interval)
  if (now - tLog >= intervalLog) {
    tLog = now;
    systemUptime = now / 1000; // convert to seconds
    Serial.print(">> System alive - Uptime: ");
    Serial.print(systemUptime);
    Serial.println("s");
  }

  // Task 3: Handle Serial Input (non-blocking)
  handleSerial();

  // *** Semua task berjalan parallel tanpa blocking ***
}

void handleSerial() {
  while (Serial.available()) {
    char c = Serial.read();
    
    if (c == '\n') {
      processSerialCommand(serialCmd);
      serialCmd = "";
    } else if (c != '\r') {
      serialCmd += c;
    }
  }
}

void processSerialCommand(String cmd) {
  cmd.trim();

  if (cmd == "INFO") {
    Serial.println("\n--- System Info ---");
    Serial.print("Uptime: ");
    Serial.print(millis() / 1000);
    Serial.println("s");
    Serial.print("LED State: ");
    Serial.println(ledState ? "ON" : "OFF");
    Serial.println("");
  }
  else if (cmd == "HELP") {
    Serial.println("\n--- Available Commands ---");
    Serial.println("  INFO    - Show system status");
    Serial.println("  LED_ON  - Turn LED on");
    Serial.println("  LED_OFF - Turn LED off");
    Serial.println("  HELP    - Show this help");
    Serial.println("");
  }
  else if (cmd == "LED_ON") {
    digitalWrite(13, HIGH);
    ledState = true;
    Serial.println(">> LED ON");
  }
  else if (cmd == "LED_OFF") {
    digitalWrite(13, LOW);
    ledState = false;
    Serial.println(">> LED OFF");
  }
  else if (cmd.length() > 0) {
    Serial.print(">> Unknown: '");
    Serial.print(cmd);
    Serial.println("' - Type HELP");
  }
}
