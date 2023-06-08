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

//Librerias
#include <Ticker.h>  //esta libreria me permite hacer uso del timer
#include <OneWire.h>
#include <DallasTemperature.h>

//Directivas de preprocesador




//Funciones de ISR
void isr_BOTON(void);
void isr_TEMPERATURA(void);
//Variables
volatile static bool estado_btL;
//Constructores
OneWire ourWire(5);
DallasTemperature sensors(&ourWire);


Ticker TEMPERATURA(isr_TEMPERATURA, 3000);
Ticker BOTON(isr_BOTON, 6000);

void setup() {
  Serial.begin(9600);
  sensors.begin();
  TEMPERATURA.start();
  BOTON.start();
}
void loop() {
  TEMPERATURA.update();
  BOTON.update();
}
////////////FUNCIONES////////////

void isr_BOTON(void) {
  estado_btL = digitalRead(3);
  if (estado_btL == HIGH) {
    Serial.println("boton presionado");
  }
  else if (estado_btL == LOW) {
    Serial.println("boton no esta presionado");
  }
}
void isr_TEMPERATURA(void) {
  sensors.requestTemperatures();
  int tempC = sensors.getTempCByIndex(0);
  if (tempC < -127) {
    Serial.println(tempC);
  } else if (tempC == -127) {
    Serial.println("ERROR");
  }
}
