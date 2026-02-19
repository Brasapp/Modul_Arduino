/*
 * CONTOH 4: KONTROL SERVO MOTOR
 * 
 * Konsep:
 * - Servo motor: rotate ke angle spesifik (0-180 derajat)
 * - Menggunakan library Servo
 * - PWM pulse timing untuk control angle
 * 
 * Hardware:
 * - Arduino board
 * - Servo motor 9g
 * - Potensiometer 10kΩ (opsional, untuk kontrol)
 * 
 * Wiring Servo:
 * - Merah (VCC) → 5V
 * - Hitam (GND) → GND
 * - Kuning/Brown (Signal) → Pin 9 (PWM pin)
 */

#include <Servo.h>

Servo myServo;                // Object servo
const int SERVO_PIN = 9;      // PWM pin untuk servo
const int POT_PIN = A0;       // Potensiometer untuk control (opsional)

int currentAngle = 90;        // Posisi saat ini
int targetAngle = 90;         // Target posisi

void setup() {
  myServo.attach(SERVO_PIN);  // Attach servo ke pin
  myServo.write(90);          // Set posisi awal ke 90 derajat
  Serial.begin(9600);
  Serial.println("Servo Motor Program Started");
}

void loop() {
  // METODE 1: Kontrol dengan potensiometer
  int potValue = analogRead(POT_PIN);
  targetAngle = map(potValue, 0, 1023, 0, 180);  // Map ke 0-180 derajat
  
  // METODE 2: Sweep otomatis (uncomment untuk test)
  // targetAngle = sweepServo();
  
  // Smooth movement (bukan langsung melompat)
  if (currentAngle < targetAngle) {
    currentAngle++;
  } 
  else if (currentAngle > targetAngle) {
    currentAngle--;
  }
  
  myServo.write(currentAngle);
  
  // Debug
  Serial.print("Target: ");
  Serial.print(targetAngle);
  Serial.print("° | Current: ");
  Serial.println(currentAngle);
  
  delay(15); // Servo update rate
}

// FUNGSI BONUS: Sweep otomatis 0-180-0
int sweepServo() {
  static int sweepAngle = 0;
  static int direction = 1;  // 1 untuk naik, -1 untuk turun
  
  sweepAngle += direction;
  
  if (sweepAngle >= 180) {
    sweepAngle = 180;
    direction = -1;
  } 
  else if (sweepAngle <= 0) {
    sweepAngle = 0;
    direction = 1;
  }
  
  return sweepAngle;
}

/*
PENJELASAN:

1. servo.attach(pin):
   - Mengaktifkan kontrol servo pada pin PWM
   - Arduino akan handle timing pulse otomatis
   - Pin harus PWM (3, 5, 6, 9, 10, 11)

2. servo.write(angle):
   - Perintah ke servo untuk rotate ke angle (0-180)
   - Bukan instant, servo butuh waktu untuk rotate

3. Timing Servo:
   - 0° = pulse 1.0ms
   - 90° = pulse 1.5ms
   - 180° = pulse 2.0ms
   - Frequency: 50Hz (period 20ms)

SMOOTH MOVEMENT:
- Jika langsung write() dari 0 ke 180, servo akan cepat sekali
- For smooth: increment currentAngle 1° per loop
- Delay 15ms untuk realistic speed

EXPERIMENT:
- Ubah delay timing untuk speed berbeda
- Combine dengan button untuk preset positions
- Gunakan multiple servo dengan array
- Integrate dengan sensor untuk automasi
*/
