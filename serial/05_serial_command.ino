/*
 * Arduino Coding Module - Serial Command Interface
 * 
 * Target: Menerima dan memproses command via Serial
 * 
 * Konsep:
 * - Non-blocking serial reading
 * - Command parsing dengan delimiter ('\n')
 * - Respons ke host
 * - Fleksibel untuk command expansion
 * 
 * Testing: Gunakan Serial Monitor di Arduino IDE
 *   Kirim: LED_ON
 *   Kirim: LED_OFF
 *   Kirim: STATUS
 */

String cmd = "";
bool ledState = false;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  Serial.println("Serial command interface ready");
  Serial.println("Commands: LED_ON, LED_OFF, STATUS");
}

void loop() {
  // Non-blocking serial reading
  while (Serial.available()) {
    char c = Serial.read();
    
    if (c == '\n') {
      // Command selesai, proses
      processCommand(cmd);
      cmd = ""; // clear buffer
    } else if (c != '\r') {
      // Accumulate command (skip carriage return)
      cmd += c;
    }
  }

  // Task lain tetap berjalan
}

void processCommand(String command) {
  // Trim whitespace (optional)
  command.trim();

  if (command == "LED_ON") {
    ledState = true;
    digitalWrite(13, HIGH);
    Serial.println(">> LED ON");
  } 
  else if (command == "LED_OFF") {
    ledState = false;
    digitalWrite(13, LOW);
    Serial.println(">> LED OFF");
  } 
  else if (command == "STATUS") {
    Serial.print(">> LED Status: ");
    Serial.println(ledState ? "ON" : "OFF");
  }
  else if (command.length() > 0) {
    Serial.print(">> Unknown command: ");
    Serial.println(command);
  }
}
