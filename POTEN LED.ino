int potpin = A0;
int potvalue = 0;
int ledpin = 9;
int ledvalue = 0;

void setup(){
  pinMode(ledpin, OUTPUT);
}

void loop(){
  potvalue = analogRead(potpin);
  ledvalue = map(potvalue, 0, 1023, 0, 255);
  analogWrite(ledpin, ledvalue);
  delay(10);

}