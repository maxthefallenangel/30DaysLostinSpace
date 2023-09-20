#include <Key.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char buttons[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad myAwesomePad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop(){
  char result = myAwesomePad.getKey();

  if (result){
    Serial.println(result);
    
  }
}
