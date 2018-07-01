#include "Arduino.h"
#include "SoftwareSerial.h"
#include "TinyGPS.h"

#ifndef POSITION_H
#define POSITION_H


class Position
{
    public:
        void begin();
        virtual ~Position();
        void Acquire();
        float getLongitude();
        float getLatitude();
        bool sinalOK();
    protected:

    private:
        float latitude;
        float longitude;
        TinyGPS *GPS;
        SoftwareSerial *rxTx;
        long unsigned int age;
        float sats;

};

#endif // POSITION_H
