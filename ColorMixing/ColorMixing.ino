const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

const int redLedPin = 9;
const int greenLedPin = 10;
const int blueLedPin = 11;

int redSensorValue = 0, greenSensorValue = 0, blueSensorValue = 0;
float redValue = 0, greenValue = 0, blueValue = 0;
int mStep = 1;

void setup() {
  Serial.begin(9600);

  // Configure PWM output ports
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop() {

  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);

  Serial.print("Sensor values in RGB: ");
  Serial.print(redSensorValue);
  Serial.print(", ");
  Serial.print(greenSensorValue);
  Serial.print(", ");
  Serial.println(blueSensorValue);

  redValue = redSensorValue / 4.0;
  greenValue = greenSensorValue / 4.0;
  blueSensorValue = blueSensorValue / 4.0;

  Serial.print("Color values in RGB: ");
  Serial.print(redValue);
  Serial.print(", ");
  Serial.print(greenValue);
  Serial.print(", ");
  Serial.println(blueSensorValue);

  analogWrite(redLedPin, redValue);
  analogWrite(greenLedPin, greenValue);
  analogWrite(blueLedPin, blueValue);

  delay(1000);
}

// Testing
//void loop() {
//  blueValue = 255;
//  if (greenValue > 255 || greenValue < 0) {
//    mStep *= -1;
//  }
//
//  greenValue += mStep;
//  redValue += mStep;
//
//  Serial.print("Color values in RGB: ");
//  Serial.print(redValue);
//  Serial.print(", ");
//  Serial.print(greenValue);
//  Serial.print(", ");
//  Serial.println(blueValue);
//
//  analogWrite(redLedPin, redValue);
//  analogWrite(greenLedPin, greenValue);
//  analogWrite(blueLedPin, blueValue);
//
//  delay(10);
//}
