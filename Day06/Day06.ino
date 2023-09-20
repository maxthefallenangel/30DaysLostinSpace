int sensorPin = A0;
int onboardLED = 13;
int sensorValue = 0;

void setup() {
  Serial.begin(9600);
pinMode(onboardLED, OUTPUT);
}

void loop() {
 sensorValue = analogRead(sensorPin);
 digitalWrite(onboardLED, HIGH);
 delay(sensorValue);
 digitalWrite(onboardLED, LOW);
 delay(sensorValue);
 
 Serial.println(sensorValue);
 delay(500);
 
}
