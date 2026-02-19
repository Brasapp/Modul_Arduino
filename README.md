# Arduino Coding Module (Software-Oriented)

**Board**: Arduino Uno | **Bahasa**: C++ (Arduino) | **Versi**: 1.0

---

## Target Pembelajaran

Setelah menyelesaikan modul ini, peserta mampu:
- ✅ Menulis kode Arduino **tanpa `delay()`**
- ✅ Membuat **loop multitasking** sederhana
- ✅ Mengimplementasikan **state machine**
- ✅ Membuat **interface berbasis Serial**
- ✅ Menulis kode **modular dan maintainable**

---

## Struktur Proyek

```
Modul_Arduino/
├── README.md
├── basic/                    # Konsep dasar
│   ├── 01_structure.ino         → Lifecycle setup() & loop()
│   ├── 02_non_blocking.ino      → Timing tanpa delay()
│   └── 03_state_machine.ino     → FSM sederhana
├── input/                    # Input handling
│   └── 04_button_event.ino      → Edge detection & debounce
└── serial/                   # Communication
    └── 05_serial_command.ino    → Command parsing
```

---

## Modul Pembelajaran

### **1️⃣ Struktur Program Arduino** | [basic/01_structure.ino](basic/01_structure.ino)

**Target**: Memahami lifecycle `setup()` dan `loop()`

**Konsep Kunci**:
- `setup()` → dijalankan **sekali** saat startup
- `loop()` → dijalankan **berulang** tanpa batas
- Inisialisasi hardware & variable di `setup()`
- Logic utama di `loop()`

---

### **2️⃣ Non-Blocking Timing** | [basic/02_non_blocking.ino](basic/02_non_blocking.ino)

**Target**: Timing akurat **tanpa `delay()`** - semua task berjalan parallel

**Prinsip Utama**:
- Semua task berjalan di loop yang sama
- Tidak ada blocking dengan `delay()`
- Cek kondisi dengan `millis()` untuk eksekusi periodik
- Scalable untuk multi-tasking

**Pattern**:
```cpp
unsigned long lastTime = 0;
const unsigned long interval = 1000;

if (millis() - lastTime >= interval) {
  lastTime = millis();
  // do task
}
```

---

### **3️⃣ State Machine Dasar** | [basic/03_state_machine.ino](basic/03_state_machine.ino)

**Target**: Alur program yang **eksplisit & mudah dikembangkan**

**Konsep Kunci**:
- Gunakan `enum` untuk state yang jelas
- Transition state dalam `switch/case`
- Setiap state punya behavior spesifik
- Mudah di-debug dan di-extend

**Keuntungan**:
- Alur logic yang terlihat jelas
- Mudah menambah state baru
- Prevents spaghetti logic

---

### **4️⃣ Button Event Detection** | [input/04_button_event.ino](input/04_button_event.ino)

**Target**: Input handling dengan **edge detection** & **debounce non-blocking**

**Teknik**:
- **Edge detection**: Deteksi perubahan state (HIGH→LOW, LOW→HIGH)
- **Debounce implisit**: Loop rate alami memberikan debounce
- **Event-based input**: Reaksi pada event, bukan polling kontinyu
- **Non-blocking**: Tidak menghentikan task lain

---

### **5️⃣ Serial Command Interface** | [serial/05_serial_command.ino](serial/05_serial_command.ino)

**Target**: Menerima & memproses command via **Serial (non-blocking)**

**Fitur**:
- Command parsing dengan delimiter (`\n`)
- Response ke host
- Fleksibel untuk command expansion
- Cocok untuk debugging & kontrol real-time

**Testing**: Gunakan Serial Monitor (Arduino IDE)
```
Input:  LED_ON
Input:  LED_OFF
Input:  STATUS
```

**Progress**: Advanced version gunakan `char buffer[]` (avoid `String` di production)

---

## ⚠️ Coding Rules (WAJIB)

### **Jangan Lakukan**:
- `delay()` di main loop (kecuali edge case sangat khusus)
- Logic panjang & kompleks langsung di `loop()`
- Hard-coded magic number tanpa konstan
- Mixed blocking & non-blocking code

### **Lakukan**:
- Timing berbasis `millis()`
- Fungsi kecil & jelas dengan nama deskriptif
- State machine untuk multi-mode behavior
- Struktur code yang modular
- Dokumentasi di atas setiap function

---

## Referensi

- [Arduino Official Reference](https://www.arduino.cc/reference/en/)
- [millis() Documentation](https://www.arduino.cc/reference/en/language/functions/time/millis/)
- [Non-blocking timing pattern](https://learn.adafruit.com/multi-tasking-the-arduino-part-1)

---

