#include "Arduino.h"
#include "HMC5883L.h"
#include "Comm.h"
#include "Control.h"
#include "HardwareSerial.h"
#define DECLINATION 0.3339
#ifndef COMPASS_H
#define COMPASS_H



class Compass{
    public:
        Compass(HardwareSerial& _serial, Control& _control);
        float angulo();
        void definePrecisao(int p);
        void calibrar();
        
    private:
        HardwareSerial& serial;
        HMC5883L compass;
        Control& control;
        float heading;
        Vector norm;
        float headingDegrees;
        float declinationAngle;
};

#endif // COMPASS_H
