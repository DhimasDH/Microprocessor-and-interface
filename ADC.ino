int potpin = A0;
int potvalue = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  potvalue = analogRead(potpin);
  Serial.print("Nilai ADC: ");
  Serial.println(potvalue);
  delay(500);
}