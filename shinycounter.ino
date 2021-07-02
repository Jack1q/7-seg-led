// manual Arduino Nano counter for shiny hunting

int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;

int buttonPin = A1;

//
// the setup routine runs once when you press reset:
void setup() {

  pinMode(buttonPin, INPUT);
   
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
}

void setDigitConfig(int * array, int number) {
  if (number < 0 || number > 9) {
    number = 0;
  }
  switch (number) {
    case 0:
      array[0] = HIGH;
      array[1] = HIGH;
      array[2] = HIGH;
      array[3] = HIGH;
      array[4] = HIGH;
      array[5] = HIGH;
      array[6] = LOW;
      break;
    case 1:
      array[0] = LOW;
      array[1] = HIGH;
      array[2] = HIGH;
      array[3] = LOW;
      array[4] = LOW;
      array[5] = LOW;
      array[6] = LOW;
      break;
    case 2:
      array[0] = HIGH;
      array[1] = HIGH;
      array[2] = LOW;
      array[3] = HIGH;
      array[4] = HIGH;
      array[5] = LOW;
      array[6] = HIGH;
      break;
    case 3:
      array[0] = HIGH;
      array[1] = HIGH;
      array[2] = HIGH;
      array[3] = HIGH;
      array[4] = LOW;
      array[5] = LOW;
      array[6] = HIGH;
      break;    
    case 4:
      array[0] = LOW;
      array[1] = HIGH;
      array[2] = HIGH;
      array[3] = LOW;
      array[4] = LOW;
      array[5] = HIGH;
      array[6] = HIGH;
      break;   
    case 5:
      array[0] = HIGH;
      array[1] = LOW;
      array[2] = HIGH;
      array[3] = HIGH;
      array[4] = LOW;
      array[5] = HIGH;
      array[6] = HIGH;
      break;
    case 6:
      array[0] = HIGH;
      array[1] = LOW;
      array[2] = HIGH;
      array[3] = HIGH;
      array[4] = HIGH;
      array[5] = HIGH;
      array[6] = HIGH;
      break;
    case 7:
      array[0] = HIGH;
      array[1] = HIGH;
      array[2] = HIGH;
      array[3] = LOW;
      array[4] = LOW;
      array[5] = LOW;
      array[6] = LOW;
      break;
    case 8:
      array[0] = HIGH;
      array[1] = HIGH;
      array[2] = HIGH;
      array[3] = HIGH;
      array[4] = HIGH;
      array[5] = HIGH;
      array[6] = HIGH;
      break;
    case 9:
      array[0] = HIGH;
      array[1] = HIGH;
      array[2] = HIGH;
      array[3] = HIGH;
      array[4] = LOW;
      array[5] = HIGH;
      array[6] = HIGH;
      break;
  }
  return array;
}

void displayNumToDigit(int digit, int num) {
  switch (digit) {
    case 0:
      digitalWrite(D1, LOW);
      digitalWrite(D2, HIGH);
      digitalWrite(D3, HIGH);
      digitalWrite(D4, HIGH);
      break;
    case 1:
      digitalWrite(D1, HIGH);
      digitalWrite(D2, LOW);
      digitalWrite(D3, HIGH);
      digitalWrite(D4, HIGH);
      break;
    case 2:
      digitalWrite(D1, HIGH);
      digitalWrite(D2, HIGH);
      digitalWrite(D3, LOW);
      digitalWrite(D4, HIGH);
      break;
    case 3:
      digitalWrite(D1, HIGH);
      digitalWrite(D2, HIGH);
      digitalWrite(D3, HIGH);
      digitalWrite(D4, LOW);
      break;
  }
  int nums[7];
  setDigitConfig(nums, num);
  digitalWrite(pinA, nums[0]);
  digitalWrite(pinB, nums[1]);
  digitalWrite(pinC, nums[2]);
  digitalWrite(pinD, nums[3]);
  digitalWrite(pinE, nums[4]);
  digitalWrite(pinF, nums[5]);
  digitalWrite(pinG, nums[6]);  
}


void displayNumber(int n) {
  if (n < 0 || n > 9999) {
    n = 0;
  }
  int num0 = n / 1000;
  int num1 = (n / 100) % 10;
  int num2 = (n / 10) % 10;
  int num3 = n % 10;
  displayNumToDigit(0, num0);
  delay(5.5);
  displayNumToDigit(1, num1);
  delay(5.5);
  displayNumToDigit(2, num2);
  delay(5.5);
  displayNumToDigit(3, num3);
  delay(5.5);
}

boolean buttonState;
int count = 0;
int lastPressTime = 0;

void loop() {
   buttonState = digitalRead(buttonPin);
   int timeSincePress = millis() - lastPressTime;
   if (buttonState && timeSincePress > 500) {
    count += 1;
    lastPressTime = millis();
   }
   displayNumber(count);
}
