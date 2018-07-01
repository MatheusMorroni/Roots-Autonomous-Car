#include "Arduino.h"
#include "HardwareSerial.h"
#ifndef COMM_H
#define COMM_H

class Comm{
    public:
        // Comm(int _baud, HardwareSerial& serial);
        void begin(HardwareSerial& serial);
        void commPrint(String m);
        void telemetriaGeral();
        void telemetriaBussola();
        void telemetriaMotor();
        void telemetriaGPS();
    private:
        int baud;
        bool defMod=0;

};

#endif // COMPASS_H
