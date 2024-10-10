const int redPin = 5;
const int yellowPin = 4;
const int greenPin = 3;


const int segA2 = 6;
const int segB2 = 7;
const int segC2 = 8;
const int segD2 = 9;
const int segE2 = 10;
const int segF2 = 11;
const int segG2 = 12;

const int segA1 = 13;
const int segB1 = A0;
const int segC1 = A1;
const int segD1 = A2;
const int segE1 = A3;
const int segF1 = A4;
const int segG1 = A5;


const int buttonPin = 2;


int buttonState = 0;

void setup() {
  
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  
  pinMode(segA1, OUTPUT);
  pinMode(segB1, OUTPUT);
  pinMode(segC1, OUTPUT);
  pinMode(segD1, OUTPUT);
  pinMode(segE1, OUTPUT);
  pinMode(segF1, OUTPUT);
  pinMode(segG1, OUTPUT);

  pinMode(segA2, OUTPUT);
  pinMode(segB2, OUTPUT);
  pinMode(segC2, OUTPUT);
  pinMode(segD2, OUTPUT);
  pinMode(segE2, OUTPUT);
  pinMode(segF2, OUTPUT);
  pinMode(segG2, OUTPUT);
  
  
  pinMode(buttonPin, INPUT);

  
  digitalWrite(greenPin, HIGH);
}

void loop() {
  
  buttonState = digitalRead(buttonPin);

  
  if (buttonState == HIGH) {
    
    blinkLED(greenPin, 2000);

    
    blinkLED(yellowPin, 3000);

    
    digitalWrite(redPin, HIGH);
    for (int i = 20; i >= 0; i--) {
      displayNumber(i); 
      delay(1000); 
    }
    digitalWrite(redPin, LOW);

    
    digitalWrite(greenPin, HIGH);
  }
}

void displayNumber(int num) {
  
  int tens = num / 10;
  int units = num % 10;

  
  displaySingleDigit(tens, segA1, segB1, segC1, segD1, segE1, segF1, segG1);
  
  
  displaySingleDigit(units, segA2, segB2, segC2, segD2, segE2, segF2, segG2);
}

void displaySingleDigit(int digit, int a, int b, int c, int d, int e, int f, int g) {
  
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);

  
  switch(digit) {
    case 0: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); break;
    case 1: digitalWrite(b, HIGH); digitalWrite(c, HIGH); break;
    case 2: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(g, HIGH); break;
    case 3: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(g, HIGH); break;
    case 4: digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break;
    case 5: digitalWrite(a, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break;
    case 6: digitalWrite(a, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break;
    case 7: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); break;
    case 8: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break;
    case 9: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break;
    default: break; 
  }
}


void blinkLED(int ledPin, int duration) {
  unsigned long startTime = millis();
  while (millis() - startTime < duration) {
    digitalWrite(ledPin, HIGH);
    delay(250);
    digitalWrite(ledPin, LOW);
    delay(250);
  }
}
