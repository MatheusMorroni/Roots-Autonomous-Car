#ifndef CONTROL_H
#define CONTROL_H
#include "Ports.h"
#include <Servo.h>
#define MAX_VEL_VOLT 1024

class Control {
    Servo servo;
    public:
        Control();
        //Aceita valores de -100 a 100(ré e frente) para vel e 0 a 10 para accel
        void speedAccel(int _speed, unsigned short _accel);
        //Mesmo que acima mas sem acelerar (abrupto)
        void speed(int _speed);
        //Recebe valor de -90 a 90 graus (0=centro)
        void turn(int _turn);
        //Retorna rotacao do servo
        int servoState();
};


#endif
