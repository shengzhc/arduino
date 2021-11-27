const int beeperPin = 8;
const int keyPin = A0;

int notes[] = {262, 294, 331, 349};

void setup() {
  Serial.begin(9600);
}

void loop() {
  int keyValue = analogRead(keyPin);
  Serial.println(keyValue);

  if (keyValue >= 1010 && keyValue <= 1025) {
    tone(beeperPin, notes[0]);
  } else if (keyValue >= 980 && keyValue <= 1010) {
    tone(beeperPin, notes[1]);
  } else if (keyValue >= 485 && keyValue <= 510) {
    tone(beeperPin, notes[2]);
  } else if (keyValue > 0 && keyValue <= 10) {
    tone(beeperPin, notes[3]);
  } else {
    noTone(beeperPin);
  }
  delay(5);
}
