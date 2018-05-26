#include "Arduino.h"
#include "SoftwareSerial.h"
#include "HMC5883L.h"

#ifndef COMPASS_H
#define COMPASS_H

Class Compass
{
  public:
  float lgraus;
  float rgaus;
  float lbgraus;
  float rbgraus;
  
  protected:
  
  private:
  int i;
  float graus;
  float graus0;
  float precisao;
};

#endif // COMPASS_H
