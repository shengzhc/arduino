#include "Servo.h"

const int potPin = A0;
const int pwmPin = 9;

Servo myServo;
int potValue;
int motorAngle;

void setup() {
  myServo.attach(pwmPin);
  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(potPin);
  Serial.print("Pot Value: ");
  Serial.print(potValue);

  motorAngle = map(potValue, 0, 1023, 0, 179);
  Serial.print(", Motor Angle: ");
  Serial.println(motorAngle);
  myServo.write(motorAngle);
  delay(20);
}
