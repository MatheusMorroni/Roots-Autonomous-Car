#include "Control.h"

void Control::begin(){
    pinMode(LED, OUTPUT);
    pinMode(BOTAO, INPUT);
}

void Control::piscaLed(int x, int t){
    int i;
    for (i = 1; i <= x; i++){
        digitalWrite(LED, 1);
        delay(t);
        digitalWrite(LED, 0);
        delay(t);
    }
}

bool Control::botaoApertado(){
    if (digitalRead(BOTAO)) return 1;
    return 0;
}

int Control::botaoPressionado(){
    int start = millis();
    if (digitalRead(BOTAO)){
        while(digitalRead(BOTAO)){
            delay(1);
        }
        return millis()-start;
    }
    else return 0;
}
