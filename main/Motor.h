#include "Arduino.h"
#ifndef MOTOR_H
#define MOTOR_H
#include "Ports.h"
#define MIN_VAL 160 //(255 - 140)

class Motor {
    public:
        void begin();
        void avancar(short _angulo);
        void voltar(short _angulo);
        short defVel(short _vel);
        void rotacionar(short _angulo);
        void parar();
        void teste();
    
    private:
        short minVel;

};


#endif
