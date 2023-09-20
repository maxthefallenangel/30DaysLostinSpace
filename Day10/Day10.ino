int sensorPin = A0;
int LED = 9;
int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  
}

void loop() {
  sensorValue = analogRead(sensorPin);
  if (sensorValue < 50 )
  {digitalWrite(LED, HIGH);
  }
else digitalWrite(LED, LOW);

  Serial.println(sensorValue);
  
  
}
