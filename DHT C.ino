#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

// Definisikan jenis sensor DHT (DHT11 atau DHT22)
#define DHTTYPE DHT22   // Ubah ke DHT22 jika menggunakan DHT22

// Pin yang terhubung ke sensor DHT
#define DHTPIN 2

// Pin untuk LED dan buzzer
#define LEDPIN 13
#define BUZZERPIN 12

// Inisialisasi DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Inisialisasi LCD I2C dengan alamat 0x27 dan ukuran 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Memulai komunikasi serial
  Serial.begin(9600);
  Serial.println("DHT Sensor dengan LCD I2C dan Alarm");

  // Memulai sensor DHT
  dht.begin();

  // Memulai LCD I2C
  lcd.init();
  lcd.backlight();

  // Mengatur pin LED dan buzzer sebagai output
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUZZERPIN, OUTPUT);
}

void loop() {
  // Tunggu beberapa saat antara pembacaan (2 detik)
  delay(2000);

  // Membaca kelembapan dan suhu
  float kelembapan = dht.readHumidity();
  float suhu = dht.readTemperature();

  // Menampilkan suhu dan kelembapan di Serial Monitor
  Serial.print("Kelembapan: ");
  Serial.print(kelembapan);
  Serial.print(" %\t");
  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.println(" *C");

  // Menampilkan suhu dan kelembapan di LCD
  lcd.clear();
  lcd.setCursor(0, 0); // Baris pertama
  lcd.print("Suhu: ");
  lcd.print(suhu);
  lcd.print(" C");
  
  lcd.setCursor(0, 1); // Baris kedua
  lcd.print("Kelembapan: ");
  lcd.print(kelembapan);
  lcd.print(" %");

  
  if (suhu > 28) {
    digitalWrite(LEDPIN, HIGH);  
    digitalWrite(BUZZERPIN, HIGH);  
  } else {
    digitalWrite(LEDPIN, LOW);   
    digitalWrite(BUZZERPIN, LOW);   
  }
}
