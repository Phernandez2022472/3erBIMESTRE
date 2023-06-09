/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Electronica
   Grado: Quinto
   Sección: A
   Curso: Taller de electronica digital y reparación de computadoras I
   Nombre:Pablo David Hernandez Ajiataz
   Carnet: 2022472
   Proyecto:OHMNIMETRO
*/
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C LCD(0x27, 16, 2);
byte OHM[8] = {
  B01110,
  B10001,
  B10001,
  B10001,
  B10001,
  B01010,
  B11011,
  B00000
};
void setup() {
  pinMode(A0, INPUT);
  LCD.init();
  LCD.backlight();
  LCD.createChar(0, OHM);
}
void loop() {
  float LECTURA = analogRead(A0);
  float LECTURA2 = map(LECTURA, 0, 1023, 0, 500000);
  
  float Vout = LECTURA2 / 100000;
  LCD.setCursor(0, 0);
  LCD.print("Vout:");
  LCD.setCursor(5, 0);
  LCD.print(Vout);
  float valor1 = 50000 / Vout;
  float R1 = valor1 - 10000;
  R1 = R1 + 10;
  LCD.setCursor(4, 1);
  LCD.print(R1);
  LCD.write(0);

}
