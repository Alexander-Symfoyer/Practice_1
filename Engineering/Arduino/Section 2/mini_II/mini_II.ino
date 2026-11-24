int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int dp = 9;

int d1 = 10;
int d2 = 11;
int d3 = 12;
int d4 = 13;

unsigned long last_time7 = 0;
unsigned int digit_pos = 1;

int run_pin = A1;
int cancel_pin = A2;
int relay_pin = A3;

int last_run = 0;
int last_cancel = 0;
unsigned long last_time = 0;

int value = 0;

void setup() {
  
  pinMode(run_pin, INPUT);
  pinMode(cancel_pin, INPUT);
  pinMode(relay_pin, OUTPUT);
  Serial.begin(9600);

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);

  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  
}

void loop() {
  

  unsigned long current_time = millis();

  if (current_time - last_time >= 1000 && value > 0) {
    value--;
    last_time = current_time;
  }

  if (current_time - last_time7 >= 0) {
    last_time7 = current_time;
    digit_pos++;
    if (digit_pos > 4) {
      digit_pos = 1;
    }
  }

  int current_run = digitalRead(run_pin);
  int current_cancel = digitalRead(cancel_pin);

  if (last_run == 0 && current_run == 1) {
    value += 10;
    last_time = current_time;
  }

  if (last_cancel == 0 && current_cancel == 1) {
    value = 0;
  }

  if (value > 0) {
    digitalWrite(relay_pin, LOW);
  }
  else {
    digitalWrite(relay_pin, HIGH);
  }

  Serial.println(value);

  last_run = current_run;
  last_cancel = current_cancel;

  unsigned int digit = (value / (int)(pow(10, 4 - digit_pos) + 0.5)) % 10;

  show_digit(digit);

  if (digit_pos == 1) {
    digitalWrite(d1, LOW);
    digitalWrite(d2, HIGH);
    digitalWrite(d3, HIGH);
    digitalWrite(d4, HIGH);
  } else if (digit_pos == 2) {
    digitalWrite(d1, HIGH);
    digitalWrite(d2, LOW);
    digitalWrite(d3, HIGH);
    digitalWrite(d4, HIGH);
  } else if (digit_pos == 3) {
    digitalWrite(d1, HIGH);
    digitalWrite(d2, HIGH);
    digitalWrite(d3, LOW);
    digitalWrite(d4, HIGH);
  } else {
    digitalWrite(d1, HIGH);
    digitalWrite(d2, HIGH);
    digitalWrite(d3, HIGH);
    digitalWrite(d4, LOW);
  }

}

void show_digit(int value) {

  if (value == 0) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
  }

  else if (value == 1) {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }

  else if (value == 2) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  }

  else if (value == 3) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  }

  else if (value == 4) {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }

  else if (value == 5) {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }

  else if (value == 6) {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }

  else if (value == 7) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }

  else if (value == 8) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }

  else if (value == 9) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }

  digitalWrite(dp, LOW);
}
