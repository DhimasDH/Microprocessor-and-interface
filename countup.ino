const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5;
const int E = 6;
const int F = 7;
const int G = 8;

unsigned long previousMillis = 0;
const long interval = 1000; 

int number = 0; 

const int numbers[10][7] = {
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},    
  {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW},        
  {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH},     
  {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH},     
  {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH},      
  {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH},     
  {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},    
  {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW},      
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},   
  {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH}     
};

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; 

    displayNumber(number);

    number++;
    if (number > 9) {
      number = 0;
    }
  }
}

void displayNumber(int num) {
  digitalWrite(A, numbers[num][0]);
  digitalWrite(B, numbers[num][1]);
  digitalWrite(C, numbers[num][2]);
  digitalWrite(D, numbers[num][3]);
  digitalWrite(E, numbers[num][4]);
  digitalWrite(F, numbers[num][5]);
  digitalWrite(G, numbers[num][6]);
}
