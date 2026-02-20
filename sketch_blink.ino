/*
 * Mini Project: LED Berkedip (Blink)
 * Deskripsi: LED akan menyala dan mati secara bergantian setiap 1 detik
 * Hardware: Arduino Uno + 1 LED + 1 Resistor 220Ω
 * 
 * Cara menjalankan:
 * 1. Buka folder ini di VS Code
 * 2. Pastikan file sketch.ino, diagram.json ada di folder yang sama
 * 3. Tekan Ctrl+Shift+P -> "Wokwi: Start Simulator"
 */

// Definisikan pin tempat LED terhubung
#define LED_PIN 13      // LED terhubung ke pin 13 (Built-in LED)

// Setup - Berjalan sekali saat startup
void setup() {
  // Deklarasikan pin 13 sebagai OUTPUT
  pinMode(LED_PIN, OUTPUT);
  
  // Mulai komunikasi Serial (opsional, untuk debugging)
  Serial.begin(9600);
  Serial.println("=== Program Blink Dimulai ===");
  Serial.println("LED akan berkedip setiap 1 detik");
  delay(500);
}

// Loop - Berjalan terus-menerus
void loop() {
  // Nyalakan LED
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED: ON");
  
  // Tunggu 1 detik (1000 millisecond)
  delay(1000);
  
  // Matikan LED
  digitalWrite(LED_PIN, LOW);
  Serial.println("LED: OFF");
  
  // Tunggu 1 detik sebelum siklus berikutnya
  delay(1000);
}

/*
 * PENJELASAN KODE:
 * 
 * 1. #define LED_PIN 13
 *    - Mendefinisikan konstanta LED_PIN dengan nilai 13
 *    - Memudahkan jika ingin mengubah pin nanti
 * 
 * 2. void setup()
 *    - Fungsi yang dijalankan sekali saat startup
 *    - Inisialisasi pin, serial, library, dll
 * 
 * 3. pinMode(LED_PIN, OUTPUT)
 *    - Set pin 13 sebagai OUTPUT (untuk mengirim sinyal)
 *    - Alternatif: INPUT, INPUT_PULLUP, OUTPUT
 * 
 * 4. Serial.begin(9600)
 *    - Mulai komunikasi serial dengan baud rate 9600
 *    - Gunakan Serial Monitor (icon monitor di Wokwi) untuk lihat output
 * 
 * 5. void loop()
 *    - Fungsi yang dijalankan berulang kali
 *    - Kode utama program berada di sini
 * 
 * 6. digitalWrite(pin, HIGH/LOW)
 *    - Tulis nilai digital ke pin (5V atau 0V)
 *    - HIGH = 5V (LED menyala)
 *    - LOW = 0V (LED mati)
 * 
 * 7. delay(1000)
 *    - Tunda eksekusi selama 1000 millisecond = 1 detik
 *    - Satuan selalu millisecond
 * 
 * 8. Serial.println()
 *    - Print teks ke serial monitor
 *    - Berguna untuk debugging dan melihat status program
 */
