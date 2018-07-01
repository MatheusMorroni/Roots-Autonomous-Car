#include "Arduino.h"
#include "Ports.h"

#ifndef CONTROL_H
#define CONTROL_H

class Control{
    public:
        void begin();
        void piscaLed(int x, int t);
        bool botaoApertado();
        int botaoPressionado();
    private:


};

#endif // CONTROL_H
