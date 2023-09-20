int LED = 12 ; //Hero pin 12
int Switch1 = 2;

void setup() {
pinMode(LED, OUTPUT);
pinMode(Switch1, INPUT);

}

void loop() {

if (digitalRead(Switch1) == HIGH){
  digitalWrite(LED, LOW);
  delay(100);
  digitalWrite(LED, HIGH);
  delay(100);  
  digitalWrite(LED, LOW);
  delay(100);  
  digitalWrite(LED, HIGH);
  delay(100);
}
else {
digitalWrite(LED, LOW);
}

}
