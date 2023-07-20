/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Electronica
   Grado: Quinto
   Sección: A
   Curso: Taller de electronica digital y reparación de computadoras I
   Nombre:Pablo David Hernande Ajiataz y Angello Gabriel Mansilla Dieguez 
   carnet: 2022472 y 2022380
*/
#include<Wire.h>
#include <LedControl.h>
#include<SparkFun_ADXL345.h>


#define dataPin0   12   //pin 12 conectado al pin de datos del max7219.
#define dataClock0 10   //pin 11 conectado al pin de clock del max7219.
#define dataLoad0  11   //pin 10 conectado al pin de carga del max7219.

ADXL345 acelerometro_ADXL345 = ADXL345();
LedControl matrix_unidades = LedControl(dataPin0, dataClock0, dataLoad0, 1);
byte centro[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00000000,
};
byte DERECHO_1[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00001100,
  B00001100,
  B00000000,
  B00000000,
  B00000000,
};
byte DERECHO_2[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000110,
  B00000110,
  B00000000,
  B00000000,
  B00000000,
};
byte DERECHO_3[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000011,
  B00000011,
  B00000000,
  B00000000,
  B00000000,
};
byte DERECHO_4[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000001,
  B00000001,
  B00000000,
  B00000000,
  B00000000,
};
byte IZQUIERDA_1[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00110000,
  B00110000,
  B00000000,
  B00000000,
  B00000000,
};
byte IZQUIERDA_2[8] = {
  B00000000,
  B00000000,
  B00000000,
  B01100000,
  B01100000,
  B00000000,
  B00000000,
  B00000000,
};
byte IZQUIERDA_3[8] = {
  B00000000,
  B00000000,
  B00000000,
  B11000000,
  B11000000,
  B00000000,
  B00000000,
  B00000000,
};
byte IZQUIERDA_4[8] = {
  B00000000,
  B00000000,
  B00000000,
  B10000000,
  B10000000,
  B00000000,
  B00000000,
  B00000000,
};


int i;
int x;
void setup() {
  Serial.begin(9600);     //Inicio la comunicacion serial a 9600 baudios.
  Serial.println("Uso del acelerometro ADXL345");
  acelerometro_ADXL345.powerOn();             
  acelerometro_ADXL345.setRangeSetting(16);    
  
  matrix_unidades.shutdown(0, false); 
  matrix_unidades.setIntensity(0, 15); 
  matrix_unidades.clearDisplay(0);   
}
void loop() {
  acelerometro_ADXL345.readAccel(&x);

  Serial.println(x);

  Burbuja();

}

void Burbuja() {
  if (x >= -35 && x < -28) {
    for ( i = 0; i < 8; i++)
    {
      matrix_unidades.setRow(0, i, IZQUIERDA_4[i]);
    }
  }
  if (x >= -28 && x < -21) {
    for ( i = 0; i < 8; i++)
    {
      matrix_unidades.setRow(0, i, IZQUIERDA_3[i]);
    }
  }
  if (x >= -21 && x < -14) {
    for ( i = 0; i < 8; i++)
    {
      matrix_unidades.setRow(0, i, IZQUIERDA_2[i]);
    }
  }
  if (x >= -14 && x < - 7) {
    for ( i = 0; i < 8; i++)
    {
      matrix_unidades.setRow(0, i, IZQUIERDA_1[i]);
    }
   
  }
  if (x > -7 && x <= 7) {
    for ( i = 0; i < 8; i++)
    {
      matrix_unidades.setRow(0, i, centro[i]);
    }
    Serial.println("CEntro");
  }
  if (x > 7 && x <= 14) {
    for ( i = 0; i < 8; i++)
    {
      matrix_unidades.setRow(0, i, DERECHO_1[i]);
    }
  }
  if (x>14 && x <= 21) {
    for ( i = 0; i < 8; i++)
    {
      matrix_unidades.setRow(0, i, DERECHO_2[i]);
    }
  }
  if (x > 21 && x <= 28) {
   for ( i = 0; i < 8; i++)
    {
      matrix_unidades.setRow(0, i, DERECHO_3[i]);
    }
  }
  if (x > 28 && x <= 35) {
    for ( i = 0; i < 8; i++)
    {
      matrix_unidades.setRow(0, i, DERECHO_4[i]);
    }
  }
}
