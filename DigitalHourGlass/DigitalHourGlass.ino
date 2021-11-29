const int pins[] = {2, 3, 4, 7, 8, 11};
const unsigned long interval = 1000;

unsigned long previousTime = 0;
int ledIndex = 0;

void setup() {
  for (int i=0; i<sizeof(pins) / sizeof(pins[0]); i++) {
    pinMode(pins[i], OUTPUT);
  }

}

void loop() {
  unsigned long currentTime = millis();
  const int pinLength = sizeof(pins) / sizeof(pins[0]);

  if (currentTime - previousTime > interval) {
    previousTime = currentTime;
    digitalWrite(pins[ledIndex], HIGH);
    ledIndex += 1;
  }

  if (ledIndex >= pinLength) {
    delay(interval);
    ledIndex = 0;
    for (int i=0; i<pinLength; i++) {
      digitalWrite(pins[i], LOW);
    }
    previousTime = millis();
  }
}
