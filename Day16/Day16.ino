#include <TM1637Display.h>

#define CLK 6
#define DIO 5

TM1637Display myDisplay = TM1637Display(CLK, DIO);

const uint8_t all_on[] = {0xff, 0xff, 0xff, 0xff};

const uint8_t blank[] = {0x00, 0x00, 0x00, 0x00};

const uint8_t done[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,
  SEG_C | SEG_E | SEG_G,
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G
};

void setup() {

  myDisplay.clear();
  delay(1000);
}

void loop() {

  myDisplay.setBrightness(7);

  myDisplay.setSegments(all_on);
  delay(2000);
  myDisplay.clear();
  delay(1000);

  int i;
  for (i = 0; i <= 123; i++) {
    myDisplay.showNumberDec(i);
    delay(100);
  }
 delay(2000);
 myDisplay.clear();
 delay(1000);
 myDisplay.setSegments(done);
 while(1);
}
