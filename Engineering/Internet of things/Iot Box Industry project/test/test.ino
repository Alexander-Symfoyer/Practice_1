#define BUTTON_1 16
#define BUTTON_2 17

bool last_raw_1 = HIGH;
bool last_raw_2 = HIGH;

bool stable_1 = HIGH;
bool stable_2 = HIGH;

unsigned long debounce_1 = 0;
unsigned long debounce_2 = 0;

const unsigned long DEBOUNCE_DELAY = 50;

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);

  last_raw_1 = digitalRead(BUTTON_1);
  last_raw_2 = digitalRead(BUTTON_2);

  stable_1 = last_raw_1;
  stable_2 = last_raw_2;
}

void loop() {

  unsigned long now = millis();

  // Button 1
  bool reading_1 = digitalRead(BUTTON_1);

  if (reading_1 != last_raw_1) {
    debounce_1 = now;
    last_raw_1 = reading_1;
  }

  if (now - debounce_1 >= DEBOUNCE_DELAY) {
    if (reading_1 != stable_1) {
      stable_1 = reading_1;

      if (stable_1 == LOW) {
        Serial.println("Button 1 pressed");
      }
    }
  }

  // Button 2
  bool reading_2 = digitalRead(BUTTON_2);

  if (reading_2 != last_raw_2) {
    debounce_2 = now;
    last_raw_2 = reading_2;
  }

  if (now - debounce_2 >= DEBOUNCE_DELAY) {
    if (reading_2 != stable_2) {
      stable_2 = reading_2;

      if (stable_2 == LOW) {
        Serial.println("Button 2 pressed");
      }
    }
  }
}