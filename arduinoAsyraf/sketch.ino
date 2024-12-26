#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD I2C dengan alamat 0x27 (untuk LCD 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin(16, 2);         // Inisialisasi LCD dengan 16 kolom dan 2 baris
  lcd.backlight();          // Menyalakan lampu latar LCD
  Serial.begin(9600);       // Menginisialisasi Serial Monitor
  lcd.print("Hello, World!");  // Menampilkan teks di LCD
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(A0);  // Membaca nilai dari potensiometer
  float voltage = sensorValue * (5.0 / 1023.0);  // Menghitung tegangan
  float temperature = (voltage - 0.5) * 100.0;   // Menghitung suhu

  // Menampilkan suhu di LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  // Menampilkan suhu di Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  delay(1000);  // Menunggu 1 detik sebelum pembacaan berikutnya
}
