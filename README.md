# 📚 Modul Pembelajaran Arduino - Complete Guide

Selamat datang di modul pembelajaran Arduino untuk developer yang sudah mengerti basic programming!

## 📁 Struktur Folder

```
Modul_Arduino/
├── 1_ARDUINO_BASICS.md              ← Mulai dari sini! Konsep & struktur
├── WOKWI_TUTORIAL.md                ← Cara setup & gunakan Wokwi simulator
├── README.md                         ← File ini
│
├── 2_EXAMPLE_CODES/                 ← Contoh code nyata + penjelasan
│   ├── 1_LED_Blink_Timer.ino
│   ├── 2_Button_Debounce.ino
│   ├── 3_Analog_Sensor_LDR.ino
│   ├── 4_Servo_Control.ino
│   └── 5_Serial_StateMachine.ino
│
└── 3_WOKWI_PROJECTS/               ← Siap pakai di Wokwi simulator
    ├── 1_LED_Blink_Timer_diagram.json
    ├── 2_Button_Debounce_diagram.json
    ├── 3_Analog_Sensor_diagram.json
    └── 4_Servo_Control_diagram.json
```

---

## 🚀 Quick Start - 3 Langkah

### Langkah 1: Pahami Konsep
📖 Buka: **`1_ARDUINO_BASICS.md`**
- Pelajari pengertian setup() vs loop()
- Pahami digital vs analog pins
- Review best practices

**Waktu:** 15-20 menit

### Langkah 2: Lihat & Pahami Contoh Code
📝 Buka salah satu file di **`2_EXAMPLE_CODES/`**
- Setiap file memiliki:
  - ✅ Penjelasan hardware yang dibutuhkan
  - ✅ Inline comments detail
  - ✅ Penjelasan konsep penting
  - ✅ Eksperimen saran di akhir

**Rekomendasi urutan:**
1. `1_LED_Blink_Timer.ino` (dasar timer non-blocking)
2. `2_Button_Debounce.ino` (input handling)
3. `3_Analog_Sensor_LDR.ino` (analog reading & PWM)
4. `4_Servo_Control.ino` (library usage)
5. `5_Serial_StateMachine.ino` (komunikasi & state machine)

**Waktu:** 10 menit per file

### Langkah 3: Test dengan Wokwi
🎮 Buka file `.json` di **`3_WOKWI_PROJECTS/`**
- Tidak perlu hardware fisik
- Simulasi langsung di VS Code
- Test code sebelum ke hardware real

**Cara menggunakan:**
1. Install extension: Wokwi Simulator di VS Code
2. Buka folder `Modul_Arduino` di VS Code
3. Buka file `diagram.json` dari `3_WOKWI_PROJECTS/`
4. Click tombol "Play" untuk simulasi
5. Lihat hasil di serial monitor

**Waktu:** 5 menit per project

---

## 📊 Learning Path

### Untuk Pemula (belum paham Arduino)

```
1. Baca: 1_ARDUINO_BASICS.md (section 1-3: struktur & pin)
2. Code: 2_EXAMPLE_CODES/1_LED_Blink_Timer.ino
3. Test: 3_WOKWI_PROJECTS/1_LED_Blink_Timer_diagram.json
   ↓
4. Baca: 1_ARDUINO_BASICS.md (section 4-5: serial & timing)
5. Code: 2_EXAMPLE_CODES/2_Button_Debounce.ino
6. Test: 3_WOKWI_PROJECTS/2_Button_Debounce_diagram.json
   ↓
7. Baca: 1_ARDUINO_BASICS.md (section 9: debugging)
8. Eksperimen: Modifikasi kode sendiri
```

**Total waktu:** 2-3 jam

---

### Untuk Intermediate (paham C/C++)

```
1. Skim: 1_ARDUINO_BASICS.md (focus: concepts yang unfamiliar)
2. Study: Semua di 2_EXAMPLE_CODES/ sekaligus
3. Hands-on: Modify & extend Wokwi projects
4. Challenge: Buat project kombinasi sendiri
```

**Total waktu:** 1-2 jam

---

## 💡 Konsep Kunci yang Perlu Dikuasai

### 1. Non-Blocking Timing (⭐ PENTING)
```cpp
// ❌ JANGAN:
delay(1000);  // Program "freeze" selama 1 detik

// ✅ PAKAI:
if (millis() - lastTime >= 1000) {
  lastTime = millis();
  // aksi di sini
}
```
**Penjelasan:** Program tetap responsif untuk baca input atau aksi lain

Lihat: `1_LED_Blink_Timer.ino`

---

### 2. Debouncing Button Input
```cpp
// Mechanical buttons membuat banyak false triggers
// Solusi: tunggu 50ms untuk signal stabilizing
```
Lihat: `2_Button_Debounce.ino`

---

### 3. Analog Reading & PWM
```cpp
analogRead(pin)   // 0-1023 (baca tegangan)
analogWrite(pin)  // 0-255 (kirim PWM untuk smooth control)
map()             // Konversi antar range
```
Lihat: `3_Analog_Sensor_LDR.ino`

---

### 4. Library & Abstraction
```cpp
#include <Servo.h>
Servo myServo;
myServo.attach(9);
myServo.write(angle);  // Library handle PWM complexity
```
Lihat: `4_Servo_Control.ino`

---

### 5. State Machine Pattern
```cpp
enum State { STATE_OFF, STATE_ON, STATE_BLINK };
// Clean way to manage multiple modes
// Mudah diperluas & debug
```
Lihat: `5_Serial_StateMachine.ino`

---

## 🔥 Common Mistakes (Jangan Sampai!)

| ❌ Mistake | ✅ Correct | Alasan |
|-----------|-----------|--------|
| `while(1) { delay(...) }` | Gunakan `loop()` | Arduino `loop()` sudah infinite |
| Lupa `pinMode()` | Selalu set di `setup()` | Pin mode default undefined |
| `delay()` berlebihan | Gunakan `millis()` | Program jadi lambat & unresponsive |
| Write ke pin undefined | Check pin number | Pin > 13 mungkin invalid |
| Baca analog terlalu cepat | `delay(100)` antar read | ADC butuh waktu |
| Lupa serial monitor setup | `Serial.begin(9600)` | Tidak bisa debug |

Penjelasan lengkap: Lihat `1_ARDUINO_BASICS.md` section 10

---

## 🛠️ Wokwi Setup (untuk simulasi)

### Minimum Setup:
1. Install VS Code Extension: **Wokwi Simulator**
   - Ctrl+Shift+X → search "Wokwi" → Install

2. Open folder Modul_Arduino di VS Code

3. Navigate ke `3_WOKWI_PROJECTS/1_LED_Blink_Timer_diagram.json`

4. File akan terbuka, click tombol **"Play"** di toolbar

5. Lihat simulasi berjalan & serial output

### Kalau tidak bisa:
→ Lihat `WOKWI_TUTORIAL.md` section 2-7 untuk detail setup

---

## 🎯 Challenge Projects

Setelah selesai contoh, coba buat ini:

### Challenge 1: Traffic Light System
```
- 3 LED (merah, kuning, hijau)
- Berganti otomatis: merah 5s → kuning 2s → hijau 5s
- Button untuk override (all off)

Gunakan: state machine, non-blocking timer, button debounce
```

### Challenge 2: Light Meter + Alert
```
- LDR sensor measure cahaya
- LED terang/redup mengikuti cahaya
- Buzzer beep jika terlalu gelap
- Display status di Serial

Gunakan: analog read, PWM, threshold detection
```

### Challenge 3: Servo Sweep dengan Button
```
- Button 1: sweep servo 0-180
- Button 2: stop sweep
- Potentiometer: manual control angle
- Serial display current angle

Gunakan: servo library, button debounce, multiple input
```

---

## 📚 Referensi Tambahan

- **Arduino Official:** https://www.arduino.cc/reference/
- **Wokwi Components:** https://docs.wokwi.com/parts
- **Simulator Online:** https://wokwi.com (version web)

---

## 💻 Tips Menggunakan File `.ino`

### Option 1: Di Arduino IDE
```
1. Download Arduino IDE dari arduino.cc
2. Copy-paste code dari 2_EXAMPLE_CODES/*.ino
3. Connect board via USB
4. Verify & Upload
```

### Option 2: Di Wokwi Online
```
1. Buka wokwi.com
2. Create new Arduino project
3. Copy diagram.json dari 3_WOKWI_PROJECTS/
4. Copy .ino code ke editor
5. Simulasi!
```

### Option 3: Di VS Code + Wokwi Extension (Recommended)
```
1. Install Wokwi extension
2. Buka folder Modul_Arduino
3. Buka .json file dari 3_WOKWI_PROJECTS/
4. Click Play
5. Test & modify on the fly
```

---

## 🤝 Kontribusi & Pertanyaan

Jika Anda:
- 🐛 Menemukan bug atau error di code
- ❓ Punya pertanyaan tentang konsep
- 💡 Punya improvement suggestion
- 🎓 Membuat project epic dengan modul ini

**Silakan dokumentasikan dan share!**

---

## 📝 Checklist Pembelajaran

- [ ] Baca `1_ARDUINO_BASICS.md` lengkap
- [ ] Pahami konsep: setup(), loop(), pins
- [ ] Pahami: digital vs analog
- [ ] Pahami: non-blocking timing
- [ ] Study code 1-5 secara urut
- [ ] Test setiap code di Wokwi
- [ ] Modifikasi & eksperimen sendiri
- [ ] Pahami penjelasan di akhir setiap code
- [ ] Complete minimal 2 challenge projects
- [ ] Siap untuk hardware fisik! ✅

---

**Selamat belajar! Happy coding! 🚀**

---

*Last Updated: February 2026*  
*Version: 1.0*
