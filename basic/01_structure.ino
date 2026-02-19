/*
 * Arduino Coding Module - Basic Structure
 * 
 * Target: Memahami lifecycle setup() dan loop()
 * 
 * Konsep:
 * - setup() dijalankan sekali saat startup
 * - loop() dijalankan berulang kali
 * - Inisialisasi hardware/variable di setup()
 * - Logic utama di loop()
 */

void setup() {
  // Jalankan sekali saat startup
  Serial.begin(9600);
  Serial.println("System init");
}

void loop() {
  // Jalankan berulang kali
  Serial.println("Loop running");
  delay(1000); // hanya untuk demo lifecycle
}
