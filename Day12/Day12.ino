#include <Key.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7, 8, 9};

char buttons[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'C'},
};

Keypad myAwesomePad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS);

int tones[ROWS][COLS] = {
  {31, 93, 147, 208},
  {247, 311, 370, 440},
  {523, 587, 698,880},
  {1397, 2637, 3729, 4978}
};

int buzzer = 10;

void setup() {
  Serial.begin(9600);

}

void loop() {

  int toneFreq = 0;
  char result = myAwesomePad.getKey();

if (result){

  for (byte j=0; j<ROWS; j++) {
    for (byte i=0; i<COLS; i++) {
      if (result == buttons[j][i]) {
        toneFreq=tones[j][i];
       }
    }
  }

  Serial.print("key: ");
  Serial.print(result);
  Serial.print("   Freq: ");
  Serial.println(toneFreq);

  tone(buzzer, toneFreq, 500);
  delay(500);
  noTone(buzzer);
}

}
