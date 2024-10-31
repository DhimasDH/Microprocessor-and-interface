#include "DHT.h"

#define DHTTYPE DHT22   

#define DHTPIN 2  


DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);
  Serial.println("DHT Sensor Suhu dan Kelembapan");

  dht.begin();
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

}
