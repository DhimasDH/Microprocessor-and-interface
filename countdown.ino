int Pins1[] = {2, 3, 4, 5, 6, 7, 8};
int Pins2[] = {9, 10, 11, 12, 13, A0, A1};

byte numbers[] = {
  B00111111, 
  B00000110, 
  B01011011, 
  B01001111, 
  B01100110, 
  B01101101, 
  B01111101, 
  B00000111, 
  B01111111, 
  B01101111    
};

unsigned long previousMillis = 0;
const long interval = 1000; 
int number = 20; 

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(Pins1[i], OUTPUT);
    pinMode(Pins2[i], OUTPUT);
  }
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; 
    if (number >= 0) {
      displayNumber(number);
      number--;
    } else {
      number = 20;
    }
  }
}


void displayNumber(int number) {
  int tens = number / 10;  
  int ones = number % 10;  
  {
  byte seg1 = numbers[ones];  
  for (int i = 0; i < 9; i++) {
    digitalWrite(Pins1[i], bitRead(seg1, i));  
  }
  byte seg2 = numbers[tens];
  for (int v = 0; v < 7; v++) {
    digitalWrite(Pins2[v], bitRead(seg2, v));  
  }
  }
}