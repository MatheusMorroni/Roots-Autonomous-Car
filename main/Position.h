#include "Arduino.h"
#include "SoftwareSerial.h"
#include "TinyGPS.h"
#include "HardwareSerial.h"
#include "Ports.h"

#ifndef POSITION_H
#define POSITION_H


class Position
{
    public:
        Position(HardwareSerial& _serial);
        bool Acquire();
        float getLongitude();
        float getLatitude();
        void smartdelay(unsigned long ms);
    protected:

    private:
        float latitude;
        float longitude;
        float age;
        HardwareSerial& serial;
        TinyGPS* gps;
        SoftwareSerial* ss;
        float sats;

};

#endif // POSITION_H
