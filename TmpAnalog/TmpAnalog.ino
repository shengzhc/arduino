const float baseTemperature = 26.0;
const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
  for (int i=3; i<6; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);

  const float voltage = sensorValue / 1024.0 * 5.0;
  Serial.print(", Voltage: ");
  Serial.print(voltage);

  const float tmp = (voltage - 0.5) * 100;
  Serial.print(", temperature in C: ");
  Serial.println(tmp);

  if (tmp < baseTemperature) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  } else if (tmp < baseTemperature + 2) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else if (tmp < baseTemperature + 4) {
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  } else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }
  delay(10);
}
