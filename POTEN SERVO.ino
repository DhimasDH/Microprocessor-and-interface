#include <Servo.h>  

Servo myservo;      
int potPin = A0;    
int valuepot = 0;
int valueser = 0;            

void setup() {
  myservo.attach(10);  
}

void loop() {
  valuepot = analogRead(potPin);            
  valueser = map(valuepot, 0, 1023, 0, 180);     
  myservo.write(valueser);                  
  delay(5);                           
}
