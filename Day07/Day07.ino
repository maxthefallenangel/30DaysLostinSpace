int sensorPin = A0;
int onboardLED = 13;
int sensorValue = 0;
unsigned int batteryCapacity = 50000;
unsigned int batteryLevel = 0;
unsigned int ticks = 0;
unsigned int wait = 100;
double PercentFull;

void setup() {

pinMode(onboardLED, OUTPUT);
Serial.begin(9600);
}

void PrintBatteryPercentage() {
  Serial.print(ticks);
  Serial.print(" ms    charge at ");

  PercentFull=100*((double)batteryLevel / (double)batteryCapacity);
  Serial.print(PercentFull);

  Serial.println("%");
}

void loop() {
 sensorValue = analogRead(sensorPin);
 batteryLevel += sensorValue;
 ticks += wait;

 if(batteryLevel >= batteryCapacity) {
  Serial.print(ticks);
  Serial.print(" ms      ");
  Serial.print("FULLY CHARGED");
  batteryLevel = batteryCapacity;
  ticks = 0;
  delay(20000);
  }
  else {
    PrintBatteryPercentage();
  }

  delay(wait);
 
}
