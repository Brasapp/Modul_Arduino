/*
 * CONTOH 3: PEMBACAAN SENSOR ANALOG (LDR / LIGHT SENSOR)
 * 
 * Konsep:
 * - Membaca nilai analog (0-1023)
 * - Map nilai ke range yang berguna
 * - Triggering aksi berdasarkan threshold
 * 
 * Hardware:
 * - Arduino board
 * - LDR (Light Dependent Resistor) atau potensiometer
 * - Resistor 10kΩ
 * - LED dan resistor 220Ω
 * 
 * Wiring:
 * 5V ---- LDR ---- A0 ---- 10kΩ ---- GND
 */

const int LDR_PIN = A0;
const int LED_PIN = 11;  // PWM pin untuk brightness control

// Range kalibrasi
const int MIN_SENSOR_VALUE = 50;   // Nilai saat gelap maksimal
const int MAX_SENSOR_VALUE = 900;  // Nilai saat terang maksimal

// Threshold untuk aksi
const int THRESHOLD_GELAP = 300;
const int THRESHOLD_TERANG = 700;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Light Sensor Program Started");
}

void loop() {
  // Baca raw value
  int rawValue = analogRead(LDR_PIN);
  
  // Map ke 0-255 untuk PWM brightness
  int brightness = map(rawValue, MIN_SENSOR_VALUE, MAX_SENSOR_VALUE, 0, 255);
  brightness = constrain(brightness, 0, 255);  // Pastikan dalam range 0-255
  
  // Kirim ke LED dengan PWM
  analogWrite(LED_PIN, brightness);
  
  // Debug output
  Serial.print("Raw: ");
  Serial.print(rawValue);
  Serial.print(" | Brightness: ");
  Serial.print(brightness);
  Serial.print(" | Status: ");
  
  // Deteksi kondisi
  if (rawValue < THRESHOLD_GELAP) {
    Serial.println("GELAP - LED terang penuh");
  } 
  else if (rawValue > THRESHOLD_TERANG) {
    Serial.println("TERANG - LED redup");
  }
  else {
    Serial.println("MEDIUM");
  }
  
  delay(100); // Baca setiap 100ms, cegah bacaan terlalu sering
}

/*
PENJELASAN FUNGSI PENTING:

1. analogRead(pin): return 0-1023
   - 0 = 0V (GND)
   - 1023 = 5V (VCC)

2. map(value, fromLow, fromHigh, toLow, toHigh):
   - Mengkonversi range: value dari [fromLow-fromHigh] ke [toLow-toHigh]
   - Contoh: map(512, 0, 1023, 0, 255) = 128

3. constrain(value, min, max):
   - Membatasi value antara min dan max
   - Jika value > max → return max
   - Jika value < min → return min

4. analogWrite(pin, value):
   - Kirim PWM ke pin
   - Value 0-255 (0% - 100%)
   - Hanya pin dengan ~ symbol

EXPERIMENT:
- Ganti LDR dengan temperature sensor (TMP36)
- Gunakan multiple threshold untuk 3-4 kondisi
- Tampilkan status di LCD/OLED
- Combine dengan button untuk mode manual/otomatis
*/
