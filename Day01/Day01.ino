void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);// turn on Built in LED
  delay(1000); // wait 1 second
  digitalWrite(LED_BUILTIN, LOW); //turn off LED
  delay(1000); //wait 1 second

}
