/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Electronica
   Grado: Quinto
   Sección: A
   Curso: Taller de electronica digital y reparación de computadoras I
   Nombre:Pablo David Hernandez Ajiataz
   Carnet: 2022472
   Proyecto: Uso de interrupciones de temporizador por medio de Ticker
*/

#define R 2
#define G 3
#define B 4
int N;
void setup() {
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(A0,INPUT);
}
void loop() {
  int Estado=analogRead(A0);
  N=map(Estado,0,1023,100,1000);

  analogWrite(R,174);
  analogWrite(G,92);
  analogWrite(B,230);
  delay(N);

  analogWrite(R,255);
  analogWrite(G,255);
  analogWrite(B,255);
  delay(N);

  analogWrite(R,0);
  analogWrite(G,255);
  analogWrite(B,255);
  delay(N);

  analogWrite(R,189);
  analogWrite(G,174);
  analogWrite(B,20);
  delay(N);

  analogWrite(R,225);
  analogWrite(G,87);
  analogWrite(B,35);
  delay(N);
}
