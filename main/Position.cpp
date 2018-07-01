#include "Position.h"
#include "Ports.h"

Position::Position(HardwareSerial& _serial) : serial(_serial)
{
    serial.println("GPS construido");
    ss = new SoftwareSerial(GPS_RX, 20);
    gps = new TinyGPS();
    ss->begin(4800);
}

bool Position::Acquire(){
    smartdelay(1000);
    gps->f_get_position(&latitude, &longitude);
    if(latitude == TinyGPS::GPS_INVALID_F_ANGLE || longitude == TinyGPS::GPS_INVALID_F_ANGLE){
        return 0;
    }
    return 1;
}

void Position::smartdelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (ss->available())
      gps->encode(ss->read());
  } while (millis() - start < ms);
}

float Position::getLongitude()
{
    return longitude;
}

float Position::getLatitude()
{
    return latitude;
}

