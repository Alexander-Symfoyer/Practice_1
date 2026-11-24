int run_pin = 9;
int cancel_pin = 6;
int last_run = 0;
int last_cancel = 0;
int last_time = 0;

int value = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(run_pin, INPUT);
  pinMode(cancel_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int current_time = millis();
  if (current_time - last_time >= 1000 && value > 0) {
    value--;
    last_time = current_time;
  }

  int current_run = digitalRead(run_pin);
  int current_cancel = digitalRead(cancel_pin);

  if (last_run == 0 && current_run == 1) {
    Serial.println("Running");
    value += 10;
    last_time = current_time;
  }

  if (last_cancel == 0 && current_cancel == 1) {
    Serial.println("Canceling");
    value = 0;
  }

  if (value > 0) {
    Serial.println("Pump on");
  }
  else {
    Serial.println("Pump off");
  }

  Serial.println(value);

  last_run = current_run;
  last_cancel = current_cancel;

}
