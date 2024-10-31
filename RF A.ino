#include <SPI.h>
#include <MFRC522.h>

// Definisikan pin untuk SS (Slave Select) dan RST (Reset)
#define SS_PIN 10
#define RST_PIN 9

// Inisialisasi objek MFRC522
MFRC522 mfrc522(SS_PIN, RST_PIN);  

void setup() {
  // Memulai komunikasi serial
  Serial.begin(9600);
  Serial.println("Siapkan RFID Reader");

  // Memulai SPI
  SPI.begin();

  // Memulai sensor RFID
  mfrc522.PCD_Init();
  Serial.println("Letakkan kartu RFID di dekat reader...");
}

void loop() {
  // Periksa apakah ada kartu RFID yang tersedia
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Periksa apakah kartu dapat dibaca
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Tampilkan UID kartu/tag RFID di Serial Monitor
  Serial.print("UID Kartu: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();

  // Hentikan komunikasi dengan kartu
  mfrc522.PICC_HaltA();
}
