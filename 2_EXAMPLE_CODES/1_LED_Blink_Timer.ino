/*
 * CONTOH 1: LED BLINK dengan Non-Blocking Timer
 * 
 * Konsep:
 * - Menggunakan millis() untuk timing tanpa blocking
 * - Membuat 2 LED blink dengan interval berbeda
 * 
 * Hardware yang diperlukan:
 * - Arduino board
 * - 2 LED
 * - 2 resistor 220Ω
 * - Breadboard dan kabel
 */

const int LED1_PIN = 13;
const int LED2_PIN = 12;

unsigned long previousMillis_LED1 = 0;
unsigned long previousMillis_LED2 = 0;

const unsigned long INTERVAL_LED1 = 500;   // Blink setiap 500ms
const unsigned long INTERVAL_LED2 = 1000;  // Blink setiap 1000ms

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Program mulai...");
}

void loop() {
  unsigned long currentMillis = millis();
  
  // LED1 blink logic
  if (currentMillis - previousMillis_LED1 >= INTERVAL_LED1) {
    previousMillis_LED1 = currentMillis;
    digitalWrite(LED1_PIN, !digitalRead(LED1_PIN)); // Toggle
    Serial.println("LED1 toggle");
  }
  
  // LED2 blink logic
  if (currentMillis - previousMillis_LED2 >= INTERVAL_LED2) {
    previousMillis_LED2 = currentMillis;
    digitalWrite(LED2_PIN, !digitalRead(LED2_PIN)); // Toggle
    Serial.println("LED2 toggle");
  }
  
  // Kode lain bisa berjalan di sini tanpa terganggu delay
}

/*
PENJELASAN:
- previousMillis menyimpan waktu terakhir kali kondisi terpenuhi
- Setiap loop, kita compare (currentMillis - previousMillis) dengan INTERVAL
- Jika sudah mencapai interval, toggle LED dan update previousMillis
- Keuntungan: program tidak "freeze" seperti delay()

EXPERIMENT:
- Ubah INTERVAL_LED1 dan INTERVAL_LED2 untuk pattern berbeda
- Tambah LED ketiga dengan interval lain
*/
