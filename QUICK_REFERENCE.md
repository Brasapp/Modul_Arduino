# Arduino Quick Reference - Cheat Sheet

> Copy-paste ready snippets untuk common tasks

---

## 📌 Setup & Serial

```cpp
void setup() {
  Serial.begin(9600);           // Start serial, 9600 baud
  pinMode(13, OUTPUT);          // Set pin mode
  pinMode(2, INPUT_PULLUP);     // Input dengan internal resistor
}
```

---

## 💡 Pin Control

### Digital Output
```cpp
pinMode(pin, OUTPUT);           // Set sebagai output
digitalWrite(13, HIGH);         // Kirim HIGH (5V)
digitalWrite(13, LOW);          // Kirim LOW (0V)
```

### Digital Input
```cpp
pinMode(pin, INPUT);            // Set sebagai input
int value = digitalRead(2);     // Baca: return 0 atau 1
```

### Analog Input (0-1023)
```cpp
int sensorValue = analogRead(A0);  // Baca A0-A5
```

### PWM Output (0-255) - Hanya pin dengan ~
```cpp
analogWrite(11, 128);           // 50% brightness/speed
```

---

## ⏱️ Timing (Non-Blocking)

### Setup
```cpp
unsigned long lastTime = 0;
const unsigned long INTERVAL = 1000;  // 1 detik
```

### Loop
```cpp
void loop() {
  unsigned long currentTime = millis();
  
  if (currentTime - lastTime >= INTERVAL) {
    lastTime = currentTime;
    
    // Aksi di sini (berjalan setiap 1 detik)
  }
}
```

---

## 🔘 Button dengan Debounce

```cpp
const int BUTTON_PIN = 2;
const unsigned long DEBOUNCE_DELAY = 50;

int buttonState = LOW;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);
  
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    if (reading != buttonState) {
      buttonState = reading;
      
      if (buttonState == HIGH) {
        // Aksi saat button ditekan
      }
    }
  }
  
  lastButtonState = reading;
}
```

---

## 📊 Mapping & Constraining

```cpp
// Map: ubah range A ke range B
int output = map(input, 0, 1023, 0, 255);

// Constrain: limit value dalam range
int safe = constrain(value, 0, 255);

// Contoh praktis
int brightness = map(analogRead(A0), 0, 1023, 0, 255);
analogWrite(11, brightness);
```

---

## 🔊 Serial Communication

### Output
```cpp
Serial.print("Halo");           // Tanpa newline
Serial.println("World");        // Dengan newline
Serial.println(variableName);   // Print variable

// Format angka
Serial.println(3.14159, 2);     // Output: 3.14 (2 decimal)
```

### Input
```cpp
if (Serial.available()) {
  char data = Serial.read();         // Baca 1 byte
  String input = Serial.readStringUntil('\n');
  int number = Serial.parseInt();    // Baca integer
}
```

---

## 🔄 Loops & Conditions

### For Loop (counter)
```cpp
for (int i = 0; i < 10; i++) {
  Serial.println(i);
}
```

### While Loop
```cpp
while (condition) {
  // code
}
```

### For Each (Array)
```cpp
int pins[] = {2, 3, 4, 5};
for (int pin : pins) {
  digitalWrite(pin, HIGH);
}
```

### If-Else Logic
```cpp
if (sensor > 500) {
  digitalWrite(LED, HIGH);
} else if (sensor > 250) {
  digitalWrite(LED, LOW);
} else {
  digitalWrite(LED, HIGH);
}
```

---

## 📚 Library Usage

### Servo
```cpp
#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(9);        // Attach ke pin 9
}

void loop() {
  myServo.write(90);        // Rotate ke 90 derajat
  delay(15);
}
```

### Wire (I2C)
```cpp
#include <Wire.h>

Wire.begin();               // Initialize I2C
Wire.beginTransmission(0x50);    // Address 0x50
Wire.write(data);
Wire.endTransmission();
```

---

## 🎯 Useful Functions

### Constrain
```cpp
constrain(value, 0, 255);   // 0 ≤ value ≤ 255
```

### Min / Max
```cpp
min(a, b);                  // Return yang lebih kecil
max(a, b);                  // Return yang lebih besar
```

### Absolute Value
```cpp
abs(-10);                   // Return 10
```

### Power
```cpp
pow(2, 3);                  // 2^3 = 8
sqrt(16);                   // √16 = 4
```

### Random
```cpp
randomSeed(analogRead(A0)); // Initialize
int random_val = random(0, 100);  // 0-99
```

---

## 📋 Data Types

```cpp
byte myByte = 255;              // 0-255
int myInt = 32000;              // -32768 to 32767
unsigned int myUInt = 65000;    // 0-65535
long myLong = 2000000;          // -2.1B to 2.1B
float myFloat = 3.14;           // Decimal numbers
boolean myBool = true;          // true atau false
char myChar = 'A';              // Single character
String myString = "Hello";      // Text (use Quotes + Capital S)
```

---

## 🐛 Debug Techniques

### Serial Printing
```cpp
Serial.print("Sensor value: ");
Serial.println(sensorValue);
```

### Conditional Debug
```cpp
if (isError) {
  Serial.println("ERROR!");
}
```

### LED Blink for Status
```cpp
digitalWrite(13, HIGH); delay(100);
digitalWrite(13, LOW);  delay(100);
```

---

## ❌ Common Errors

| Error | Fix |
|-------|-----|
| `'digitalRead' was not declared` | Pastikan `#include` library |
| Pin tidak berubah | Check `pinMode()` di setup |
| `analogWrite` ke pin analog pin | Hanya bisa ke digital PWM pin (~) |
| Serial garbage text | Check baud rate sama (9600) |
| Variable jadi 0 tiba-tiba | Check integer overflow |

---

## 🎮 State Machine Template

```cpp
enum State {
  IDLE,
  RUNNING,
  STOPPED,
  ERROR
};

State currentState = IDLE;

void setup() {
  currentState = IDLE;
}

void loop() {
  switch(currentState) {
    case IDLE:
      if (buttonPressed()) {
        currentState = RUNNING;
      }
      break;
      
    case RUNNING:
      if (time > MAX_TIME) {
        currentState = STOPPED;
      }
      break;
      
    case STOPPED:
      if (resetButton()) {
        currentState = IDLE;
      }
      break;
  }
}
```

---

## ⚡ Quick Tips

✅ **Always:**
- Set `Serial.begin(9600)` di setup
- Use `pinMode()` sebelum read/write pin
- Gunakan `millis()` untuk timing >100ms
- Add comments untuk logika kompleks

❌ **Never:**
- Use `delay()` > 100ms di loop
- Lupa initialize variable
- Gunakan variable name undef
- Kirim HIGH/LOW ke analog pin

---

**Keep this visible while coding! 📌**
