int red = 11;
int green = 10;
int blue = 9;

void setup() {
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);

}

void RGB_color(int red_value, int green_value, int blue_value)
{
  analogWrite(red, red_value);
  analogWrite(green, green_value);
  analogWrite(blue, blue_value);
}


void loop() {

 RGB_color(125, 0, 0);
 delay(800);
 RGB_color(0, 125, 0);
 delay(800);
 RGB_color(0, 0, 125);
 delay(800);
 RGB_color(64, 32, 0);
 delay(800);
 RGB_color(125, 0, 125);
 delay(800);
 RGB_color(125, 125, 125);
 delay(2000);
 }
