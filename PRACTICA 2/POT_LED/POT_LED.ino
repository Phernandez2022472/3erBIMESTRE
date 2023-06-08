
#define LED 5
int luminosidad;
void setup() {
  pinMode(A0, INPUT);
  pinMode(LED, OUTPUT);
}
void loop() {
  int Leer_Estado = analogRead(A0);
  luminosidad = map(Leer_Estado, 0, 1023, 0, 255);
  analogWrite(LED,luminosidad);
}
