/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre:Pablo David Hernandez Ajiataz
 * Carnet: 2022472
 * Proyecto: Uso de interrupciones externas - Bimestre III
*/
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
