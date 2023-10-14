#include <Key.h>
#include <Keypad.h>

int buzzer = 8;
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

const byte ROWS = 4;
const byte COLS = 4;
const byte PassLength = 4;
char currentPassword[PassLength] = {'0', '0', '0', '0'};

 char buttons[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
 };

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7, 12, 13};

Keypad securityPad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS);

int unlockMode(){
  char result ;

  RGB_color(0,0,0);
  Serial.println("Unlock Mode: Type Password to continue");
  delay(500);

  for(int i = 0; i <PassLength; i++) {
    while(!(result = securityPad.getKey())) {
      
    }
    if(currentPassword[i] != result){
      Serial.println("WRONG PASSWORD");
      Serial.println(result);
      playError();
      return -1;
    }
    Serial.print('*');
    playInput();
    RGB_color(0, 0, 125);
    delay(100);
    RGB_color(0, 0, 0);
  }
  Serial.println("");
  Serial.println("Device Successfully Unlocked!");
  playSuccess();
  return 0;
}

void playSuccess() {
  tone(buzzer, 1000, 200);
  delay(200);
  tone(buzzer, 2700, 1000);
  delay(1000);
  noTone(buzzer);
}

void playError() {
  tone(buzzer, 147, 200);
  delay(100);
  noTone(buzzer);
}

void playInput() {
  tone(buzzer, 880, 200);
  delay(50);
  noTone(buzzer);
}
void RGB_color(int red_value, int green_value, int blue_value)
{
  analogWrite(redPin, red_value);
  analogWrite(greenPin, green_value);
  analogWrite(bluePin, blue_value);
}

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  RGB_color(125, 125, 125);
  delay(2000);
  RGB_color(0, 0, 0);

  Serial.begin(9600);
  delay(2000);
  Serial.println("Press * to set a new pasword.");
  Serial.println("Press # to access the system with the existing one.");
}

void loop() {
  char result = securityPad.getKey();

  if (result == '*'){
    int access = unlockMode();

    if(access < 0) {
      Serial.println("Access Denied. Cannot change password without knowing the previous or default.");
      RGB_color(125, 0, 0);
    }
    else {
      RGB_color(0, 125, 0);
      delay(2000);
      RGB_color(0, 0, 0);
      Serial.println("Welcome, authorized user. Please Enter a new password: ");
      delay(500);

      for(int i = 0; i < PassLength; i++) {
        while(!(result = securityPad.getKey())) {
          
        }

        currentPassword[i] = result;
        Serial.print("*");
        playInput();
        RGB_color(0, 0, 0);
      }

      Serial.println(" ");
      Serial.println("Password Successfully Changed!");
      RGB_color(0, 125, 0);
    }
  }

  else if (result == '#') {
    int access = unlockMode();
    if(access < 0) {
      Serial.println("Password error. Access Denied.");
      RGB_color(125, 0, 0);
    }
    else {
      Serial.println("Welcome, authorized user. You may now begin using the system.");
      RGB_color(0, 125, 0);  
    }
  }
  
}
