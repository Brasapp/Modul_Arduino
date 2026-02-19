/*
 * CONTOH 2: TOMBOL (BUTTON) DENGAN DEBOUNCE
 * 
 * Konsep:
 * - Membaca digital input dari button
 * - Menangani "bouncing" (signal noise saat button press)
 * - Deteksi tekan vs lepas
 * 
 * Hardware:
 * - Arduino board
 * - 1 push button
 * - 1 resistor 10kΩ (pull-down)
 * - LED dan resistor 220Ω (optional)
 */

const int BUTTON_PIN = 2;
const int LED_PIN = 13;
const unsigned long DEBOUNCE_DELAY = 50; // 50ms debounce

int buttonState = LOW;              // State saat ini
int lastButtonState = LOW;          // State sebelumnya
unsigned long lastDebounceTime = 0; // Waktu terakhir perubahan
int pressCount = 0;                 // Counter tekan button

void setup() {
  pinMode(BUTTON_PIN, INPUT);      // INPUT tanpa PULLUP (gunakan resistor eksternal)
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Program tombol siap");
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);
  
  // Jika ada perubahan state
  if (reading != lastButtonState) {
    lastDebounceTime = millis(); // Reset debounce timer
  }
  
  // Tunggu debounce delay untuk memastikan state stabil
  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    // Jika state berubah (stabil)
    if (reading != buttonState) {
      buttonState = reading;
      
      // Jika button ditekan (LOW ke HIGH atau sebaliknya, tergantung setup)
      if (buttonState == HIGH) {
        pressCount++;
        Serial.print("Tombol ditekan! Total: ");
        Serial.println(pressCount);
        
        // Toggle LED
        digitalWrite(LED_PIN, !digitalRead(LED_PIN));
      }
    }
  }
  
  lastButtonState = reading;
}

/*
PENJELASAN DEBOUNCE:
- Button berisi mechanical switch yang "bergerak-gerak" sebelum final state
- Ini menyebabkan multiple HIGH-LOW transitions dalam waktu singkat
- DEBOUNCE: tunggu 50ms untuk memastikan signal stabil

TIMING:
1. Button ditekan → reading berubah → timer mulai
2. Tunggu 50ms
3. Cek lagi, jika masih sama → dianggap state valid
4. Trigger aksi

EXPERIMENT:
- Ubah DEBOUNCE_DELAY jadi 0 → akan ketik banyak kali (debounce tidak bekerja)
- Ubah jadi 200 → terlalu lambat merespons cepat
- Gunakan array untuk multiple buttons
*/
