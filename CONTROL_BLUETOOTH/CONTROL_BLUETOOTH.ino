#include <SoftwareSerial.h>
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Ticker.h>
#define ROJO 2

char RECEPCIONLED;
void TEMPERATURE (void);


OneWire ourWire(5);
DallasTemperature sensors(&ourWire);
SoftwareSerial BLUTU(10, 11); // RX,TX
Ticker TEMP(TEMPERATURE, 10000);


void setup() {
  pinMode(ROJO, OUTPUT);
  Serial.begin(9600);
  BLUTU.begin(9600);
  sensors.begin();
  TEMP.start();
}

void loop() {
  LEDPRENDER();
  TEMP.update();
}

void TEMPERATURE (void)
{
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  BLUTU.print(tempC);
  BLUTU.println(" ºC");

}

void LEDPRENDER (void)
{
  if (BLUTU.available() ) {
    RECEPCIONLED = BLUTU.read();
    Serial.print(RECEPCIONLED);
    if (RECEPCIONLED == '1')
    {
      Serial.print("ENCENDIDO");
      digitalWrite(ROJO, HIGH);
    }
    if (RECEPCIONLED == '0')
    {
      Serial.print("APAGADO");
      digitalWrite(ROJO, LOW);
    }

  }

}
