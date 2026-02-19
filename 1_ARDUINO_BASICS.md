# Modul Pembelajaran Arduino - Struktur & Konsep

> Untuk developer yang sudah mengerti dasar programming (variables, functions, loops, conditionals)

## 1. Struktur Dasar Kode Arduino

Setiap program Arduino memiliki 2 function utama:

```cpp
void setup() {
  // Berjalan 1 kali saat board pertama kali dihidupkan
  // Gunakan untuk inisialisasi pin, sensor, komunikasi serial
}

void loop() {
  // Berjalan berulang kali (infinite loop)
  // Gunakan untuk membaca sensor, kontrol output, logika program
}
```

**Analogi:** `setup()` = persiapan, `loop()` = pekerjaan berulang

---

## 2. Pin Arduino

### A. Pin Digital (I/O)
Hanya ada 2 state: **HIGH** (5V/3.3V) atau **LOW** (0V)

```cpp
pinMode(pin, mode);        // Tiga opsi mode:
                           // - INPUT : baca nilai
                           // - OUTPUT : kirim nilai
                           // - INPUT_PULLUP : input dengan resistor internal

digitalWrite(pin, state);  // Kirim HIGH atau LOW
int value = digitalRead(pin);  // Baca HIGH atau LOW (return 0 atau 1)
```

### B. Pin Analog (A0-A5)
Membaca nilai tegangan: **0-1023** (0V hingga 5V/3.3V)

```cpp
int value = analogRead(pin);    // Baca nilai 0-1023
analogWrite(pin, value);        // Kirim PWM 0-255 (Pulse Width Modulation)
                                // Hanya pin berlogo ~ yang support PWM
```

**PWM** = Mengirim HIGH-LOW dengan frekuensi tinggi untuk simulasi voltase tengah

---

## 3. Komunikasi Serial

Untuk debug dan komunikasi dengan komputer:

```cpp
Serial.begin(9600);                // Setup dengan baud rate 9600
Serial.print("Halo");              // Tulis tanpa newline
Serial.println("Dunia");           // Tulis dengan newline
Serial.println(variableName);      // Tampilkan nilai variabel

if(Serial.available()) {           // Cek ada data dari serial
  char data = Serial.read();       // Baca 1 character
}
```

**Baud Rate** = Kecepatan transfer data (bit per detik)

---

## 4. Konsep Timing & Delay

```cpp
delay(miliseconds);         // Jeda dalam milidetik
delayMicroseconds(microsec); // Jeda dalam mikrodetik
unsigned long millis();     // Milidetik sejak board dihidupkan
unsigned long micros();     // Mikrodetik sejak board dihidupkan
```

**Tips:** Jangan gunakan `delay()` berlebihan, gunakan `millis()` untuk kode non-blocking

---

## 5. Tipe Data Penting

| Tipe | Range | Ukuran | Gunakan untuk |
|------|-------|--------|---|
| `byte` | 0-255 | 1 byte | Counter kecil |
| `int` | -32768 to 32767 | 2 bytes | Nilai normal |
| `long` | -2M to +2M | 4 bytes | Nilai besar |
| `float` | -3.4e38 to 3.4e38 | 4 bytes | Desimal |
| `boolean` | true/false | 1 byte | Kondisi |

**Memory terbatas di Arduino!** Gunakan tipe terkecil yang cukup

---

## 6. Interrupt (Fungsi Emergency)

```cpp
void setup() {
  attachInterrupt(digitalPinToInterrupt(pin), function, mode);
  // mode: RISING, FALLING, CHANGE, LOW
}

void myInterruptFunction() {
  // Eksekusi instan saat event terjadi
  // Simpan singkat! Hindari Serial.print() di interrupt
}
```

**Gunakan untuk:** Event cepat, sensor motion, button press real-time

---

## 7. Library Arduino

### Menggunakan Library
```cpp
#include <Wire.h>           // I2C communication
#include <SPI.h>            // SPI communication
#include <Servo.h>          // Kontrol servo motor
#include <LiquidCrystal.h>  // LCD display
```

### Cara Install Library
1. Arduino IDE → Sketch → Include Library → Manage Libraries
2. Search nama library → Install

---

## 8. Koneksi & Protokol Komunikasi

### SPI (Serial Peripheral Interface)
- **Kecepatan:** Sangat cepat
- **Jarak:** Pendek (same board)
- **Pin:** MOSI, MISO, SCK, CS
- **Gunakan:** SD card, fast sensors

### I2C (Two-Wire Interface)
- **Kecepatan:** Sedang
- **Jarak:** Medium (beberapa meter dengan wire)
- **Pin:** SDA, SCL
- **Gunakan:** Sensor I2C, LCD, RTC

### UART (Serial)
- **Kecepatan:** Lambat
- **Jarak:** Jauh
- **Pin:** TX, RX
- **Gunakan:** Debug, wireless modules

---

## 9. Debugging Tips

```cpp
// 1. Serial Monitor
Serial.println("Debug message");

// 2. Blink LED
digitalWrite(13, HIGH);
delay(100);
digitalWrite(13, LOW);

// 3. Conditional debug
if(sensorValue > threshold) {
  Serial.print("ALERT: ");
  Serial.println(sensorValue);
}
```

---

## 10. Best Practices

✅ **DO:**
- Gunakan meaningful variable names
- Add comments untuk logika kompleks
- Test dengan Serial Monitor
- Pakai PWM untuk smooth control
- Gunakan `unsigned long` untuk timer

❌ **DON'T:**
- Gunakan `delay()` untuk timing precise → gunakan `millis()`
- Kirim Serial terlalu sering → lambat
- Lupa initialize pin dengan `pinMode()`
- Cobalkan hardware baru tanpa protective resistor
- Baca analog pin terlalu cepat (tunggu ~100µs antar read)

---

## Next Step
→ Lihat `2_EXAMPLE_CODES/` untuk contoh implementasi  
→ Lihat `WOKWI_TUTORIAL.md` untuk mencoba simulasi
