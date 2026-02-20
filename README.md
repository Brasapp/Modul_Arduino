# Modul Pengenalan Koding Arduino

Selamat datang di modul pengenalan Arduino! Modul ini dirancang untuk pemula yang ingin belajar mikrokontroler Arduino melalui praktik langsung di **Wokwi** - simulator Arduino online.

## Daftar Isi
1. [Tentang Arduino](#tentang-arduino)
2. [Setup & Tools](#setup--tools)
3. [Struktur Program Arduino](#struktur-program-arduino)
4. [Menghubungkan Komponen](#menghubungkan-komponen)
5. [File-File yang Dibutuhkan](#file-file-yang-dibutuhkan)
6. [Mini Project: LED Berkedip](#mini-project-led-berkedip)

---

## Tentang Arduino

Arduino adalah platform open-source untuk membuat prototipe elektronik. Terdiri dari:
- **Hardware**: Board mikrokontroler (Arduino Uno, Nano, Mega, dll)
- **Software**: IDE atau editor untuk menulis kode

Keuntungan Arduino:
- Mudah dipelajari (bahasa mirip C/C++)
- Open-source dan gratis
- Komunitas besar dengan banyak tutorial
- Bisa digunakan untuk berbagai project IoT, robotika, dll

---

## Setup & Tools

### 1. Install VS Code Extension: Wokwi for VS Code

Wokwi adalah simulator Arduino yang memungkinkan Anda berlatih tanpa hardware fisik.

**Langkah Instalasi:**

1. Buka VS Code
2. Pergi ke **Extensions** (Ctrl+Shift+X)
3. Cari **"Wokwi for VS Code"** oleh Wokwi
4. Klik **Install**
5. Restart VS Code jika perlu



**Cara Menggunakan:**
- Buka folder project Arduino Anda
- Letakkan file `diagram.json` dan `sketch.ino` di folder project
- Tekan **Ctrl+Shift+P** → ketik "Wokwi: Start Simulator"
- Simulator akan terbuka di preview panel

---

## Struktur Program Arduino

Setiap program Arduino memiliki struktur dasar yang sama:

```cpp
// 1. DEKLARASI & SETUP (Berjalan sekali saat startup)
void setup() {
  // Inisialisasi pin, serial communication, dll
  Serial.begin(9600);        // Mulai komunikasi serial
  pinMode(LED_PIN, OUTPUT);  // Set pin sebagai output
  pinMode(BUTTON_PIN, INPUT); // Set pin sebagai input
}

// 2. LOOP (Berjalan terus-menerus)
void loop() {
  // Kode utama yang akan diulang
  digitalWrite(LED_PIN, HIGH);  // Nyalakan LED
  delay(1000);                  // Tunggu 1 detik
  digitalWrite(LED_PIN, LOW);   // Matikan LED
  delay(1000);                  // Tunggu 1 detik
}
```

### Penjelasan Fungsi Penting:

| Fungsi | Kegunaan | Contoh |
|--------|----------|---------|
| `pinMode(pin, mode)` | Set pin sebagai INPUT/OUTPUT | `pinMode(13, OUTPUT)` |
| `digitalWrite(pin, value)` | Set pin HIGH/LOW (digital) | `digitalWrite(13, HIGH)` |
| `digitalRead(pin)` | Baca nilai pin (HIGH/LOW) | `int state = digitalRead(2)` |
| `analogRead(pin)` | Baca nilai analog (0-1023) | `int value = analogRead(A0)` |
| `analogWrite(pin, value)` | PWM output (0-255) | `analogWrite(5, 128)` |
| `delay(ms)` | Tunggu (milliseconds) | `delay(500)` |
| `Serial.print()` | Print ke serial monitor | `Serial.print("Halo")` |

---

## Menghubungkan Komponen

### Pin Arduino Uno

```
POWER & GROUND (Wajib):
┌─────────────────────┐
│   Arduino Uno       │
│ GND ← Ground (Bumi) │
│ 5V  ← Power 5 Volt  │
│ 3V3 ← Power 3.3V    │
└─────────────────────┘
```

### Aturan Koneksi Umum

#### 1. **LED (Light Emitting Diode)**
```
LED memiliki 2 kaki:
- Kaki panjang (+) → GPIO Pin (misal pin 13)
- Kaki pendek (-) → 220Ω Resistor → GND

Diagram:
5V Pin ──[220Ω Resistor]── LED (+) [LED (-)] ── GND
```

#### 2. **Push Button**
```
Button (saklar) memiliki 4 kaki yang terhubung 2 pasang.

Diagram:
5V ──[Button]── GPIO Pin (misal pin 2)
                GPIO Pin ──[10kΩ Pull-down Resistor]── GND
                
Catatan: Pull-down resistor membuat pin stabil saat button tidak ditekan
```

#### 3. **Buzzer (Pembaca Suara)**
```
Buzzer aktif (dengan ±):
- Kaki (+) → GPIO Pin (misal pin 9)
- Kaki (-) → GND
```

#### 4. **Sensor (umumnya)**
```
Sensor 3 kaki:
- VCC → 5V (atau 3.3V)
- GND → GND
- DATA/OUT → GPIO Pin (misal A0 untuk analog)
```

### Tabel Referensi Cepat: Pin Arduino Uno

```
        ┌─────────────┐
    3V3 │1           │ Reset
    5V  │2           │ GND
    GND │3           │ Vin
Analog: │4           │ D0 (RX)
  A0-A5 │5           │ D1 (TX)
        │6           │ D2
Digital:│7           │ D3 (PWM)
  D2-D13│8           │ D4
        │9           │ D5 (PWM)
    GND │10          │ D6 (PWM)
        │11          │ D7
        │12          │ D8
        │13 (LED)    │ D9 (PWM)
        │14          │ D10 (PWM)
        │15          │ D11 (PWM)
        │16          │ D12
        │17          │ D13 (LED)
        │18          │ GND
        │19          │ Vin
        └─────────────┘
```

**Catatan Penting:**
- GND harus terhubung ke ground semua komponen
- VCC harus terhubung ke power (5V atau 3.3V)
- Resistor untuk LED selalu digunakan (220Ω-470Ω) untuk proteksi
- Pull-down resistor untuk button (10kΩ)

---

## File-File yang Dibutuhkan

Untuk menjalankan project Wokwi di VS Code, Anda membutuhkan:

### Struktur Folder Project

```
my_arduino_project/
├── README.md              (Opsional - Penjelasan project)
├── sketch.ino             (Wajib - Kode Arduino utama)
├── diagram.json           (Wajib - Diagram komponen dan koneksi)
└── libraries/             (Opsional - Library eksternal)
    └── library_name/
        ├── library.cpp
        └── library.h
```

### 1. **sketch.ino** (File Utama)
File yang berisi kode Arduino Anda. Wokwi secara otomatis mencari file dengan ekstension `.ino`.

### 2. **diagram.json** (Wajib)
File JSON yang mendefinisikan:
- Komponen apa saja yang digunakan
- Di mana tiap komponen ditempatkan di breadboard virtual
- Bagaimana komponen terhubung (wiring)

**Contoh struktur diagram.json:**
```json
{
  "version": 1,
  "author": "Your Name",
  "parts": [
    {
      "type": "wokwi-arduino-uno",
      "id": "uno",
      "top": 200,
      "left": 50,
      "attrs": {}
    },
    {
      "type": "wokwi-led",
      "id": "led1",
      "top": 200,
      "left": 300,
      "attrs": { "color": "red" }
    }
  ],
  "connections": [
    [ "uno:13", "led1:A", "red", [ "h6" ] ],
    [ "led1:C", "uno:GND", "black", [ "v0" ] ]
  ]
}
```

### 3. **wokwi.toml** (Opsional tapi Recommended)
Konfigurasi project Wokwi:
```toml
[wokwi]
version = 1
author = "Your Name"
title = "My Arduino Project"
description = "Description of your project"

[build]
firmware = "sketch.ino"

[env]
SIMULATED = "1"
```

---

## Mini Project: LED Berkedip

Ini adalah project paling sederhana untuk memulai Arduino. LED akan berkedip setiap 1 detik.

### Yang Dibutuhkan:
- Arduino Uno (Simulasi Wokwi)
- LED (warna bebas)
- Resistor 220Ω (atau 470Ω)

### Diagram Koneksi:
```
Arduino Pin 13 ──[220Ω Resistor]── LED (+) Pin
LED (-) ── GND
```

### File: sketch_blink.ino

```cpp
/*
 * Mini Project: LED Berkedip (Blink)
 * Deskripsi: LED akan menyala dan mati secara bergantian setiap 1 detik
 * Hardware: Arduino Uno + 1 LED + 1 Resistor 220Ω
 */

// Definisikan pin tempat LED terhubung
#define LED_PIN 13      // LED terhubung ke pin 13 (Built-in LED)

// Setup - Berjalan sekali saat startup
void setup() {
  // Deklarasikan pin 13 sebagai OUTPUT
  pinMode(LED_PIN, OUTPUT);
  
  // Mulai komunikasi Serial (opsional, untuk debugging)
  Serial.begin(9600);
  Serial.println("Program Blink dimulai!");
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
  
  // Tunggu 1 detik
  delay(1000);
}
```

### Cara Menjalankan di Wokwi:

1. **Buat folder project:**
   ```bash
   mkdir my_first_arduino
   cd my_first_arduino
   ```

2. **Buat file `sketch.ino`** dengan isi kode di atas

3. **Buat file `diagram.json`** (lihat di folder project ini)

4. **Di VS Code:**
   - Buka folder project
   - Tekan `Ctrl+Shift+P`
   - Ketik: "Wokwi: Start Simulator"
   - Simulator akan membuka dan LED akan berkedip!

5. **Untuk melihat Serial Output:**
   - Di Wokwi simulator, buka icon Serial Monitor atau "Serial" di preview
   - Serial akan menampilkan "LED: ON" dan "LED: OFF"

### Output yang Diharapkan:
```
Program Blink dimulai!
LED: ON
LED: OFF
LED: ON
LED: OFF
... (terus berulang)
```

---

## Konsep Penting yang Dipelajari

Dari mini project ini, Anda telah belajar:

1. Struktur program Arduino (setup & loop)
2. Deklarasi PIN dan mode (`pinMode`)
3. Kontrol digital output (`digitalWrite`)
4. Timing (delay) (`delay`)
5. Serial communication (`Serial.print`)
6. Koneksi dasar (PIN ke LED ke GND)

---

## Langkah Selanjutnya

Setelah paham LED berkedip, coba:

1. **Modifikasi timing** - Ubah delay() menjadi 500ms atau 2000ms
2. **Sensor Suara (Buzzer)** - Ganti LED dengan buzzer untuk output suara
3. **Push Button** - Tambahkan button untuk control LED manual
4. **Sensor Analog** - Gunakan sensor cahaya atau suhu
5. **Motor DC** - Kontrol kecepatan motor dengan PWM

---

## Resource Berguna

- **Wokwi Official**: https://wokwi.com
- **Arduino Official**: https://www.arduino.cc
- **Arduino Reference**: https://www.arduino.cc/reference/en/
- **Wokwi for VS Code Docs**: https://docs.wokwi.com/

---

