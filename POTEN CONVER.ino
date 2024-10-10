int potpin = A0;
int potvalue = 0;
int pothitung;

void setup(){
  Serial.begin(9600);
}

void loop(){
  potvalue = analogRead(potpin);
  pothitung = (potvalue*5)/1023;
  Serial.print("Nilai ADC = ");
  Serial.println(pothitung);
  delay(1000);
}