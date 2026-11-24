int motor_pin[] = {8, 9, 10, 11};

void setup() {
  // put your setup code here, to run once:
  pinMode(motor_pin[0], OUTPUT);
  pinMode(motor_pin[1], OUTPUT);
  pinMode(motor_pin[2], OUTPUT);
  pinMode(motor_pin[3], OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(motor_pin[0], HIGH);
  digitalWrite(motor_pin[1], LOW);
  digitalWrite(motor_pin[2], LOW);
  digitalWrite(motor_pin[3], LOW);

  delayMicroseconds(2000);

  digitalWrite(motor_pin[0], HIGH);
  digitalWrite(motor_pin[1], HIGH);
  digitalWrite(motor_pin[2], LOW);
  digitalWrite(motor_pin[3], LOW);

  delayMicroseconds(2000);

  digitalWrite(motor_pin[0], LOW);
  digitalWrite(motor_pin[1], HIGH);
  digitalWrite(motor_pin[2], LOW);
  digitalWrite(motor_pin[3], LOW);

  delayMicroseconds(2000);

  digitalWrite(motor_pin[0], LOW);
  digitalWrite(motor_pin[1], HIGH);
  digitalWrite(motor_pin[2], HIGH);
  digitalWrite(motor_pin[3], LOW);

  delayMicroseconds(2000);

  digitalWrite(motor_pin[0], LOW);
  digitalWrite(motor_pin[1], LOW);
  digitalWrite(motor_pin[2], HIGH);
  digitalWrite(motor_pin[3], LOW);

  delayMicroseconds(2000);

  digitalWrite(motor_pin[0], LOW);
  digitalWrite(motor_pin[1], LOW);
  digitalWrite(motor_pin[2], HIGH);
  digitalWrite(motor_pin[3], HIGH);

  delayMicroseconds(2000);

  digitalWrite(motor_pin[0], LOW);
  digitalWrite(motor_pin[1], LOW);
  digitalWrite(motor_pin[2], LOW);
  digitalWrite(motor_pin[3], HIGH);

  delayMicroseconds(2000);

  digitalWrite(motor_pin[0], HIGH);
  digitalWrite(motor_pin[1], LOW);
  digitalWrite(motor_pin[2], LOW);
  digitalWrite(motor_pin[3], HIGH);

  delayMicroseconds(2000);

}
