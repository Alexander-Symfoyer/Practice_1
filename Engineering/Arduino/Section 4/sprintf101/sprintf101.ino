void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int humidity = 60;
  int temperature = 30;

  char message[50];
  char y[] = "Data : ";
  sprintf(message, " %s Humidity = %d, Temperature = %d", y, humidity, temperature);
  Serial.println(message);

  char s[100];
  sprintf(s, "%05d", humidity);
  Serial.println(s);
}

void loop() {
  // put your main code here, to run repeatedly:

}
