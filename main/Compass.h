#include "Arduino.h"
#include "SoftwareSerial.h"
#include "HMC5883L.h"

#ifndef COMPASS_H
#define COMPASS_H

Class Compass
{
  public:
  float dgraus;
  float dgraus1;
  float dgraus2;
  
  protected:
  
  private:
  int i;
  float graus;
  float graus0;
  float latitude0;
  float longitude0;
  float precisao;
};

#endif // COMPASS_H
