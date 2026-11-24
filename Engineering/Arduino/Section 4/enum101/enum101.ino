enum Relay_state {
  OFF,  // 0
  ON    // 1
};

enum ui_state {
  home_screen = 5,
  menu_screen,  // 6
  set_time      // 7
};

enum Relay_state relay_state = ON;
enum ui_state state = home_screen;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(relay_state);
  if (relay_state == ON) {
    Serial.println("ON");
  }
  delay(1000);
}
