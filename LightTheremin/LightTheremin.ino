const int ledPin = 2;
const int beeperPin = 9;
const int sensorPin = A0;

int sensorLow = 1023;
int sensorHigh = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
 
  while(millis() < 5000) {
    int sensorValue = analogRead(sensorPin);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
    delay(10);
  }

  digitalWrite(ledPin, LOW);
}

void loop() {
  const int sensorValue = analogRead(sensorPin);
  const int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  tone(beeperPin, pitch, 20);
  delay(1000);
}
