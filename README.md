Berikut konten README.md siap pakai, fokus murni koding Arduino, dengan contoh kode konkret. Bisa langsung kamu taruh di repo GitHub.

# Arduino Coding Module (Software-Oriented)

Modul ini ditujukan untuk programmer yang **sudah paham coding**, tetapi **baru masuk ke Arduino / embedded**.  
Fokus utama: **pola koding yang benar, non-blocking, modular, dan scalable**.

Board contoh: Arduino Uno  
Bahasa: C++ (Arduino)

---

## Target Pembelajaran

Setelah menyelesaikan modul ini, peserta mampu:
- Menulis kode Arduino tanpa `delay()`
- Membuat loop multitasking sederhana
- Menggunakan state machine
- Membuat interface berbasis Serial
- Menulis kode modular dan maintainable

---

## Struktur Proyek


arduino-coding-module/
├── README.md
├── basic/
│   ├── 01_structure.ino
│   ├── 02_non_blocking.ino
│   └── 03_state_machine.ino
├── input/
│   ├── 04_button_event.ino
├── serial/
│   ├── 05_serial_command.ino
├── project/
│   └── 06_mini_project.ino

---

## 1. Struktur Program Arduino

File: `basic/01_structure.ino`

```cpp
void setup() {
  Serial.begin(9600);
  Serial.println("System init");
}

void loop() {
  Serial.println("Loop running");
  delay(1000); // hanya untuk demo lifecycle
}

Tujuan:


Memahami lifecycle setup() dan loop()



2. Non-Blocking Timing (Tanpa delay)
File: basic/02_non_blocking.ino
const uint8_t LED_PIN = 13;
unsigned long lastToggle = 0;
const unsigned long interval = 1000;
bool ledState = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  unsigned long now = millis();

  if (now - lastToggle >= interval) {
    lastToggle = now;
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
  }

  // task lain bisa jalan di sini
}

Prinsip:


Semua task berjalan paralel


Tidak ada blocking



3. State Machine Dasar
File: basic/03_state_machine.ino
enum State {
  IDLE,
  RUNNING,
  ERROR
};

State currentState = IDLE;

void setup() {
  Serial.begin(9600);
}

void loop() {
  switch (currentState) {
    case IDLE:
      Serial.println("IDLE");
      currentState = RUNNING;
      break;

    case RUNNING:
      Serial.println("RUNNING");
      currentState = ERROR;
      break;

    case ERROR:
      Serial.println("ERROR");
      currentState = IDLE;
      break;
  }

  delay(1000); // hanya untuk visualisasi state
}

Konsep:


Alur program eksplisit


Mudah dikembangkan



4. Button sebagai Event (Debounce Non-Blocking)
File: input/04_button_event.ino
const uint8_t BUTTON_PIN = 2;
bool lastState = HIGH;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  bool currentState = digitalRead(BUTTON_PIN);

  if (lastState == HIGH && currentState == LOW) {
    Serial.println("Button Pressed");
  }

  lastState = currentState;
}

Fokus:


Edge detection


Event-based input



5. Serial Command Interface
File: serial/05_serial_command.ino
String cmd;

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      processCommand(cmd);
      cmd = "";
    } else {
      cmd += c;
    }
  }
}

void processCommand(String command) {
  if (command == "LED_ON") {
    Serial.println("LED ON command received");
  } else if (command == "LED_OFF") {
    Serial.println("LED OFF command received");
  } else {
    Serial.println("Unknown command");
  }
}

Catatan:


Untuk proyek besar, hindari String


Gunakan char buffer[] di level lanjut



6. Mini Project: Multi-Task Loop Controller
File: project/06_mini_project.ino
unsigned long tBlink = 0;
unsigned long tLog = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  unsigned long now = millis();

  if (now - tBlink >= 500) {
    tBlink = now;
    digitalWrite(13, !digitalRead(13));
  }

  if (now - tLog >= 2000) {
    tLog = now;
    Serial.println("System alive");
  }

  handleSerial();
}

void handleSerial() {
  if (Serial.available()) {
    Serial.println("Command received");
    Serial.read();
  }
}

Kriteria lulus:


Tidak ada delay()


Semua task berjalan bersamaan


Kode mudah dibaca



Coding Rules (WAJIB)


❌ delay() di project utama


❌ logic di loop() yang panjang


✅ fungsi kecil & jelas


✅ state machine untuk mode


✅ timing berbasis millis()



Next Step (Opsional)


Interrupt


Timer


UART protocol


Migrasi ke non-Arduino C++



Platform
Powered by Arduino

---

Kalau mau, langkah berikutnya paling optimal:
- pisahkan jadi **repo template**
- buatin **branch latihan & solusi**
- konversi ke **Arduino Nano / ESP32**
- atau bikin **versi strict (tanpa `String`, tanpa delay sama sekali)**

Tinggal bilang target akhirnya.
