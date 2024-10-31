#include "DHT.h"

#define DHTTYPE DHT22   

#define DHTPIN 2  
#define LEDPIN 13
#define buzzerpin 12

int SUHUBATAS = 28;
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);
  Serial.println("DHT Sensor Suhu dan Kelembapan");

  dht.begin();
  pinMode(LEDPIN, OUTPUT);
  pinMode(buzzerpin, OUTPUT);

  digitalWrite(LEDPIN, LOW);
  digitalWrite(buzzerpin, LOW);
}

void loop() {
  delay(2000);
  float kelembapan = dht.readHumidity();
  float suhu = dht.readTemperature();
  

  Serial.print("Kelembapan: ");
  Serial.print(kelembapan);
  Serial.print(" %\t");
  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.println(" *C");

  if (suhu > SUHUBATAS){
    digitalWrite(LEDPIN, HIGH);
    digitalWrite(buzzerpin, HIGH);
  }
  else {
    digitalWrite(LEDPIN, LOW);
    digitalWrite(buzzerpin, LOW);
  }

}
