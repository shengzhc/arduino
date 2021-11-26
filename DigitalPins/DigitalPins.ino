int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT); // Switch
  pinMode(3, OUTPUT); // Red light
  pinMode(4, OUTPUT); // Red light
  pinMode(5, OUTPUT); // Green light
}

void loop() {
  // put your main code here, to run repeatedly:

  switchState = digitalRead(2);
  if (switchState == LOW) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  } else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);

    for (int i=0; i<10; i++) {
      digitalWrite(5, HIGH);
      delay(100);
      digitalWrite(5, LOW);
      delay(100);
    }
  }
}
