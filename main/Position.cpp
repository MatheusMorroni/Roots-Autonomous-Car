#include "Position.h"


Position::Position(int rX, int tX)
{
    TinyGPS *GPS = new TinyGPS;
    SoftwareSerial *rxTx = new SoftwareSerial(rX, tX);
}

Position::~Position()
{
    //dtor
}

void Position::Acquire(){
    unsigned long start = millis();
  do
  {
    while (rxTx->available())
      GPS->encode(rxTx->read());
  } while (millis() - start < 1000);
    GPS->f_get_position(&this->latitude, &this->longitude, &age);
}

float Position::getLongitude()
{
    return longitude;
}

float Position::getLatitude()
{
    return latitude;
}


