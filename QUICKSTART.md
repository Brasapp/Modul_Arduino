# Quick Start Guide

Panduan cepat untuk memulai project Arduino di Wokwi VS Code extension.

## File-File yang Ada di Repository Ini

```
Modul_Arduino/
├── README.md                    # Modul lengkap pengenalan Arduino
├── sketch_blink.ino             # Mini Project: LED Berkedip (Dasar)
├── diagram.json                 # Diagram Wokwi untuk project Blink
├── sketch_sos_morse.ino         # Variasi Project: LED SOS Signal
├── wokwi.toml                   # Konfigurasi project Wokwi
├── QUICKSTART.md                # File ini - Panduan cepat
└── TROUBLESHOOTING.md           # Solusi masalah umum (opsional)
```

---

## Langkah-Langkah Cepat

### 1. Install Extension Wokwi
```
Di VS Code:
Ctrl+Shift+X → Search "Wokwi for VS Code" → Install
```

### 2. Buka Folder Project
```
File → Open Folder → Pilih folder "Modul_Arduino"
```

### 3. Jalankan Simulator
```
Ctrl+Shift+P → Ketik "Wokwi: Start Simulator" → Enter
```

### 4. Lihat LED Berkedip!
LED merah di simulator akan berkedip setiap 1 detik.

---

## Mengganti Project

Jika ingin mencoba variasi project lain:

### Menggunakan SOS Morse Code:
1. Buka `sketch_sos_morse.ino`
2. Salin isi file
3. Buka `sketch.ino` (atau rename jadi sketch.ino)
4. Paste kode SOS
5. Jalankan simulator lagi (Ctrl+Shift+P → Wokwi: Start Simulator)

---

## Serial Monitor

Untuk melihat output dari `Serial.println()`:

1. Di Wokwi simulator (sebelah kanan), cari tombol monitor atau "Serial Monitor"
2. Klik untuk membuka
3. Output akan menampilkan status LED

**Expected Output untuk Blink:**
```
=== Program Blink Dimulai ===
LED akan berkedip setiap 1 detik
LED: ON
LED: OFF
LED: ON
LED: OFF
...
```

**Expected Output untuk SOS:**
```
=== SOS Morse Code ===
Pola: S(3 titik) O(3 garis) S(3 titik)
.--.--. 
SOS Pattern Complete
.--.--. 
SOS Pattern Complete
...
```

---

## Hal yang Dipelajari di Modul Ini

- Instalasi Wokwi Extension di VS Code
- Struktur program Arduino (setup & loop)
- Fungsi dasar Arduino (`pinMode`, `digitalWrite`, `delay`)
- Cara menghubungkan komponen (LED, Resistor, GND, VCC)
- Serial communication untuk debugging
- Logika dasar pemrograman mikrokontroler

---

## Troubleshooting

### "Simulator tidak mau buka"
- Pastikan file `sketch.ino` dan `diagram.json` ada di folder
- Coba restart VS Code
- Lihat console (Ctrl+`) untuk error message

### "LED tidak berkedip"
- Periksa pin di `diagram.json` sesuai dengan `sketch.ino` (pin 13)
- Periksa koneksi di diagram (LED harus ke pin, resistor ke GND)

### "Serial Monitor tidak kebuka"
- Di simulator Wokwi, cari ikon printer atau monitor
- Alternatif: Buka console Wokwi untuk melihat output

### "File diagram.json error"
- Pastikan JSON valid (gunakan JSON validator online)
- Cek syntax: Jangan ada trailing comma
- Reset diagram.json dengan yang ada di repository

---

## Next Steps

1. **Modifikasi Timing**: Ubah `delay()` di sketch menjadi 500ms atau 2000ms
2. **Tambah Komponen**: Tambah LED kedua dengan warna berbeda
3. **Logika Lebih Kompleks**: Gunakan `if` statement untuk kondisional
4. **Sensor**: Tambahkan sensor untuk membaca input
5. **Project Button**: Buat LED yang bisa on/off dengan button

---

## Resources

- Baca `README.md` untuk penjelasan detail
- Arduino Official Docs: https://www.arduino.cc/reference/
- Wokwi Documentation: https://docs.wokwi.com/
- Wokwi Parts Library: https://wokwi.com/parts

---

## Pertanyaan Umum (FAQ)

**Q: Bisa nggak edit diagram.json langsung di VS Code?**  
A: Bisa! Diagram.json adalah JSON biasa, edit langsung. Tapi perlu restart simulator setelah perubahan.

**Q: Kenapa harus pakai resistor untuk LED?**  
A: Resistor membatasi arus untuk proteksi LED dan pin Arduino. Tanpa resistor, LED bisa burnout.

**Q: Apa beda `digitalWrite` dan `analogWrite`?**  
A: `digitalWrite` = digital (ON/OFF), `analogWrite` = PWM untuk brightness/kecepatan.

**Q: Bisa nggak upload ke real Arduino board?**  
A: Bisa! File `.ino` kompatibel dengan Arduino IDE resmi untuk upload ke board fisik.

---

**Selamat belajar! Jika ada pertanyaan, cek README.md untuk penjelasan lebih detail.**
