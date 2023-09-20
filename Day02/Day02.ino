int LED = 12 ; //Hero pin 12

void setup() {
pinMode(LED, OUTPUT);
digitalWrite(LED, HIGH);

}

void loop() {

digitalWrite(LED, LOW);
delay(1000);
digitalWrite(LED, HIGH);
delay(500);

}
