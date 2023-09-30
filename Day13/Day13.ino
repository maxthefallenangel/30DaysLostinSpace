#include <Key.h>
#include <Keypad.h>

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
byte colPins[COLS] = {6, 7, 8, 9};

Keypad myAwesomePad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS);

int unlockMode(){
  char result ;
  
  Serial.println("Unlock Mode: Type Password to continue");
  delay(500);

  for(int i = 0; i < PassLength; i++) {
    while(!(result = myAwesomePad.getKey())) {

    }
    if(currentPassword[i] != result){
      Serial.println("WRONG PASSWORD");
      Serial.println(result);
      return -1;
      }
      Serial.println("*");
  }
  Serial.println("");
  Serial.println("Device Successfully Unlocked");
      return 0;
  }
  
void setup() {
  Serial.begin(9600);
  delay(2000);
  Serial.println("Press * to set a new password.");
  Serial.println("Press # to access the system with the existing one.");
}

void loop() {
  char result = myAwesomePad.getKey();

  if (result == '*'){
    int access = unlockMode();
    
    if(access < 0){
      Serial.println("Access Denied. Cannot change password without knowing previous or default.");
    }
    else {
      Serial.println("Welcome, authorized user, please Enter a new password: ");
      delay(500);

      for(int i = 0; i < PassLength; i++) {
        while(!(result = myAwesomePad.getKey()))  {
          
        }
        currentPassword[i] = result;
        Serial.print("*");
      }

       Serial.println("");
       Serial.println("Password Successfully Changed!");
      }
    }

    else if (result == '#') {
      int access = unlockMode();
      if(access < 0) {
        Serial.println("Password error. Access Denied.");  
      }
      else {
        Serial.println("Welcome, authorized user. You may now begin using the system.");
      }
    }
}
