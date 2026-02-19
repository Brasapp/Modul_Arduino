# Tutorial Wokwi Extension di VS Code

> Wokwi = Simulator Arduino online untuk test tanpa hardware fisik

## 1. Apa itu Wokwi?

**Wokwi** adalah simulator online yang memungkinkan Anda:
- ✅ Test Arduino code tanpa board fisik
- ✅ Simulasi berbagai hardware (LED, button, sensor, display)
- ✅ Debug interaktif dengan serial monitor
- ✅ Share project ke orang lain (online)

**Keuntungan:**
- Cepat setup (tidak perlu hardware)
- Safe untuk experimenting
- Dapat di-integrate langsung di VS Code
- Free version cukup untuk belajar

---

## 2. Instalasi Wokwi VS Code Extension

### Step 1: Buka VS Code Extension Marketplace
```
Ctrl+Shift+X  (pada Windows)
Cmd+Shift+X   (pada Mac)
```

### Step 2: Search "Wokwi"
Cari di search bar, akan muncul extension bernama "Wokwi Simulator"

**Extension Details:**
- Publisher: Uri Shaked
- ID: `wokwi.wokwi-simulator`

### Step 3: Click "Install"
Tunggu hingga install selesai. Akan muncul status "Installed"

### Step 4: Reload VS Code (Opsional)
Extension biasanya sudah aktif, atau click reload untuk memastikan.

---

## 3. Kebutuhan Account Wokwi

**Untuk fitur lengkap, buat account:**

1. Buka https://wokwi.com
2. Click "Sign up" / "Create account"
3. Email verification
4. Buat API token di settings (untuk offline simulation)

**Untuk simulasi offline di VS Code:**
1. Generate API token di https://wokwi.com/account/api-token
2. Di VS Code: `Ctrl+Shift+P` → "Wokwi: Add API Token"
3. Paste token

---

## 4. Membuat Project Wokwi Pertama

### Method A: Template Wokwi

1. **Create folder project**
   ```powershell
   mkdir my-Arduino-project
   cd my-Arduino-project
   ```

2. **Buat file `diagram.json`** (Konfigurasi hardware)
   ```json
   {
     "version": 1,
     "author": "Nama Anda",
     "title": "LED Blink",
     "description": "Simple LED blink project",
     "files": {
       "sketch.ino": {
         "content": "void setup() {\n  pinMode(13, OUTPUT);\n}\n\nvoid loop() {\n  digitalWrite(13, HIGH);\n  delay(1000);\n  digitalWrite(13, LOW);\n  delay(1000);\n}"
       }
     },
     "parts": [
       {
         "type": "wokwi-led",
         "id": "led1",
         "top": 100,
         "left": 200,
         "attrs": {
           "color": "red"
         }
       }
     ],
     "connections": [
       [
         "uno:13",
         "led1:A",
         "green",
         ["h12"]
       ],
       [
         "led1:C",
         "uno:GND",
         "black",
         ["h0"]
       ]
     ]
   }
   ```

3. **Buat file `sketch.ino`** (Arduino code)

### Method B: File → New Wokwi Project (Jika ada extension)

Di VS Code:
```
Ctrl+Shift+P → "Wokwi: Create New Project"
```

---

## 5. Struktur `diagram.json`

### A. Basic Properties
```json
{
  "version": 1,
  "author": "Your Name",
  "title": "Project Title",
  "description": "Deskripsi singkat",
  "files": {
    "sketch.ino": { "content": "..." }
  },
  "parts": [...],
  "connections": [...]
}
```

### B. Bagian `parts[]` - Hardware Configuration

Setiap bagian adalah object dengan `type`, `id`, dan `attrs`

**Contoh komponen:**

```json
// Arduino Uno (otomatis ditambah)
{
  "type": "wokwi-arduino-uno",
  "id": "uno",
  "top": 0,
  "left": 0
}

// LED
{
  "type": "wokwi-led",
  "id": "led1",
  "top": 100,
  "left": 200,
  "attrs": {
    "color": "red"
  }
}

// Push Button
{
  "type": "wokwi-pushbutton",
  "id": "btn1",
  "top": 50,
  "left": 300,
  "attrs": {
    "color": "blue"
  }
}

// Resistor
{
  "type": "wokwi-resistor",
  "id": "r1",
  "top": 150,
  "left": 100,
  "attrs": {
    "value": "10k"
  }
}

// Potentiometer
{
  "type": "wokwi-rotary-potentiometer",
  "id": "pot1",
  "top": 200,
  "left": 200
}

// LCD Display 16x2
{
  "type": "wokwi-lcd1602",
  "id": "lcd1",
  "top": 50,
  "left": 400,
  "attrs": {
    "displayText": "Hello"
  }
}

// Buzzer
{
  "type": "wokwi-buzzer",
  "id": "buzzer1",
  "top": 250,
  "left": 50
}
```

### C. Bagian `connections[]` - Wiring

Format: `[pin1, pin2, color, route]`

```json
"connections": [
  // LED (anode) ke pin 13
  [
    "uno:13",
    "led1:A",
    "green",
    ["h12"]
  ],
  // LED (cathode) ke GND
  [
    "led1:C",
    "uno:GND",
    "black",
    ["h0"]
  ],
  // Button ke pin 2
  [
    "uno:2",
    "btn1:1",
    "blue",
    ["h50", "v100"]
  ]
]
```

**Pin Reference (Arduino Uno):**
```
Digital: uno:0 hingga uno:13
Analog:  uno:A0 hingga uno:A5
Power:   uno:5V, uno:3V3, uno:GND
```

---

## 6. Menjalankan Simulasi

### Option 1: Langsung dari VS Code

1. Buka folder dengan `diagram.json`
2. Buka file diagram.json
3. Click tombol **"Play"** / **"Start Simulation"** di atas
4. Simulator akan terbuka di panel

### Option 2: Via Command Palette

```
Ctrl+Shift+P → "Wokwi: Start Simulator"
```

### Option 3: Keyboard Shortcut

```
F1 (atau Ctrl+Shift+P) → Type "Wokwi" → See options
```

---

## 7. Serial Monitor dalam Wokwi

### Mengakses Serial Monitor

**Di Wokwi simulator:**
1. Look untuk icon **"Serial Monitor"** di toolbar
2. Click untuk buka
3. Set baud rate sama dengan code (default 9600)

**Cara kirim data ke board:**
1. Di input field, ketik command
2. Press Enter atau click Send
3. Arduino akan terima di `Serial.read()`

**Contoh:**
```cpp
void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    Serial.print("You sent: ");
    Serial.println(input);
  }
}
```

Kemudian di Serial Monitor Wokwi, ketik: `Hello`
Output: `You sent: Hello`

---

## 8. Contoh Project Lengkap: LED Button

### File: `diagram.json`

```json
{
  "version": 1,
  "author": "Bram",
  "title": "LED Button Control",
  "description": "Press button to toggle LED",
  "files": {
    "sketch.ino": {
      "content": "#include <code di sketch.ino>"
    }
  },
  "parts": [
    {
      "type": "wokwi-arduino-uno",
      "id": "uno",
      "top": 0,
      "left": 0
    },
    {
      "type": "wokwi-led",
      "id": "led1",
      "top": 100,
      "left": 250,
      "attrs": {
        "color": "red"
      }
    },
    {
      "type": "wokwi-pushbutton",
      "id": "btn1",
      "top": 100,
      "left": 100,
      "attrs": {
        "color": "blue"
      }
    },
    {
      "type": "wokwi-resistor",
      "id": "r1",
      "top": 150,
      "left": 150,
      "attrs": {
        "value": "220"
      }
    }
  ],
  "connections": [
    ["uno:13", "r1:1", "green", []],
    ["r1:2", "led1:A", "green", []],
    ["led1:C", "uno:GND", "black", []],
    ["uno:2", "btn1:1", "blue", []],
    ["btn1:2", "uno:GND", "black", []]
  ]
}
```

### File: `sketch.ino`

```cpp
#include <code dari 2_Button_Debounce.ino>
```

---

## 9. Multiple Arduino Boards

Wokwi support multiple boards dalam satu project:

```json
"parts": [
  {
    "type": "wokwi-arduino-uno",
    "id": "uno1",
    "top": 0,
    "left": 0
  },
  {
    "type": "wokwi-arduino-nano",
    "id": "nano1",
    "top": 0,
    "left": 300
  }
]
```

**Komunikasi antar board:** via wire connection (TX-RX)

---

## 10. Troubleshooting Wokwi

| Problem | Solution |
|---------|----------|
| Simulator tidak muncul | Pastikan `diagram.json` valid (check syntax) |
| Serial Monitor tidak terbuka | Refresh atau restart simulator |
| Component tidak connect | Check pin reference di documentation |
| Simulation lambat | Reduce `delay()` atau close browser tabs lain |
| Syntax error di JSON | Use JSON validator online |

---

## 11. Tips & Tricks

**✓ Pro Tips:**

1. **Version Control JSON**
   ```
   git commit diagram.json sketch.ino
   ```

2. **Share Online**
   - Export project ke Wokwi.com
   - Get shareable link

3. **Multiple Scenarios**
   - Buat folder `test1/`, `test2/` dengan diagram berbeda
   - Test berbagai kondisi

4. **Debug dengan Serial**
   - Print state variables
   - Monitor sensor values real-time

5. **Component Library**
   - Cek https://docs.wokwi.com/parts untuk all available components

---

## 12. Keyboard Shortcuts Wokwi

| Action | Shortcut |
|--------|----------|
| Start/Stop Simulation | F1 or Ctrl+Shift+P → Wokwi: Start |
| Reset Simulation | Ctrl+R |
| Serial Monitor | Ctrl+Shift+M (dalam simulator) |
| Zoom In/Out | Scroll wheel |
| Pan View | Click + Drag |

---

## 13. Quick Start: Copy & Paste Project

1. Copy file [button_example_wokwi.json](./3_WOKWI_PROJECTS/) ke folder project Anda
2. Copy [2_Button_Debounce.ino](./2_EXAMPLE_CODES/) ke folder yang sama
3. Di VS Code, open diagram.json
4. Click "Play" untuk simulasi
5. Press button di simulator!

---

## Next Step

→ Buat project Anda sendiri dengan komponen favorite  
→ Explore library komponen di https://docs.wokwi.com/parts  
→ Share project di komunitas Wokwi
