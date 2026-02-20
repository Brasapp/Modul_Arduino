/*
 * BONUS: Variasi Project - LED SOS Signal (Morse Code)
 * 
 * Deskripsi: LED akan berkedip dengan pola SOS (Signal Of Distress)
 *            dalam kode morse:
 *            S = ... (3 short blinks)
 *            O = --- (3 long blinks)
 *            S = ... (3 short blinks)
 *
 * Hardware: Arduino Uno + 1 LED + 1 Resistor 220Ω (sama seperti Blink project)
 * 
 * CATATAN: Gunakan diagram.json yang sama dari project Blink
 */

#define LED_PIN 13

// Definisikan timing untuk morse code (dalam millisecond)
#define DOT_DURATION 200      // Durasi titik (short)
#define DASH_DURATION 600     // Durasi garis (long) = 3x dot
#define GAP_DURATION 200      // Jeda antar dot/dash
#define CHAR_GAP 600          // Jeda antar karakter = 3x dot
#define WORD_GAP 1400         // Jeda antar kata = 7x dot

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("=== SOS Morse Code ===");
  Serial.println("Pola: S(3 titik) O(3 garis) S(3 titik)");
}

void loop() {
  // S = ... (3 titik)
  sendDot();
  sendDot();
  sendDot();
  delay(CHAR_GAP);
  
  // O = --- (3 garis)
  sendDash();
  sendDash();
  sendDash();
  delay(CHAR_GAP);
  
  // S = ... (3 titik)
  sendDot();
  sendDot();
  sendDot();
  
  // Jeda sebelum mengulang SOS berikutnya
  Serial.println("SOS Pattern Complete");
  delay(WORD_GAP);
}

// Fungsi untuk mengirim titik (dot) dalam morse code
void sendDot() {
  digitalWrite(LED_PIN, HIGH);
  Serial.print(".");
  delay(DOT_DURATION);
  digitalWrite(LED_PIN, LOW);
  delay(GAP_DURATION);
}

// Fungsi untuk mengirim garis (dash) dalam morse code
void sendDash() {
  digitalWrite(LED_PIN, HIGH);
  Serial.print("-");
  delay(DASH_DURATION);
  digitalWrite(LED_PIN, LOW);
  delay(GAP_DURATION);
}

/*
 * PENJELASAN KONSEP:
 * 
 * 1. KONSTANTA UNTUK TIMING
 *    Dalam Morse Code:
 *    - 1 Dot = 1 unit waktu
 *    - 1 Dash = 3 unit waktu (kita gunakan 600ms untuk LED terlihat jelas)
 *    - Jeda dalam karakter = 1 unit
 *    - Jeda antar karakter = 3 unit
 *    - Jeda antar kata = 7 unit
 * 
 * 2. FUNCTION SENDOT() DAN SENDDASH()
 *    - Fungsi yang dipanggil berulang kali
 *    - Mengurangi pengulangan kode (DRY principle)
 *    - Memudahkan maintenance jika ingin mengubah timing
 * 
 * 3. OUTPUT SERIAL MONITOR
 *    Saat menjalankan program, serial monitor akan menampilkan:
 *    ... - - - ...
 *    ... - - - ...
 *    (berulang terus)
 * 
 * 4. MODIFIKASI LEBIH LANJUT:
 *    - Ubah durasi untuk membuat SOS lebih cepat atau lambat
 *    - Tambahkan komponen buzzer untuk suara
 *    - Gunakan button untuk on/off SOS signal
 *    - Buat pola morse code untuk kata-kata lain
 */
