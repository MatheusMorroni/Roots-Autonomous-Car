#include "Arduino.h"
#include "Motor.h"

#include "Ports.h"

Motor *motor;


void setup() {
  motor = new Motor();
  Serial.begin(9600);
  motor->defVel(4);
}

void loop() {
  motor->avancar(0);
  delay(10000);
  motor->parar();
  delay(1000);
  motor->avancar(10);
  delay(10000);
  motor->parar();
  delay(1000);
  motor->avancar(-10);
  delay(10000);
  delay(1000);
  
}
