#include "Motor.h"

void Motor::begin(){
    pinMode(IA_MOTOR_D, OUTPUT);
    pinMode(IA_MOTOR_E, OUTPUT);
    pinMode(IB_MOTOR_D, OUTPUT);
    pinMode(IB_MOTOR_E, OUTPUT);
    minVel = MIN_VAL;

}

short Motor::defVel(short _vel){
    if (_vel>=0&&_vel<=4){
        minVel = map(_vel, 0, 4, MIN_VAL, 220);
    }
    return minVel;
}

void Motor::parar(){
    analogWrite(IA_MOTOR_D, 0);
    analogWrite(IA_MOTOR_E, 0);
    analogWrite(IB_MOTOR_D, 0);
    analogWrite(IB_MOTOR_E, 0);
    delay(100);
}

void Motor::avancar(short _angulo){
    if (_angulo < -10 || _angulo>10) return;
    analogWrite(IB_MOTOR_D, 0);
    analogWrite(IB_MOTOR_E, 0);
    delay(100);
    if (_angulo>0){
        analogWrite(IA_MOTOR_D,map(_angulo, 0,10,minVel, 255));
        Serial.println(map(_angulo, 0,10,minVel, 255));
        Serial.println(minVel);
        analogWrite(IA_MOTOR_E, minVel);
    }
    if (_angulo<0){
        analogWrite(IA_MOTOR_E, map(_angulo, 0,-10,minVel, 255));
        Serial.println(map(_angulo, 0,-10,minVel, 255));
        Serial.println(minVel);
        analogWrite(IA_MOTOR_D, minVel);
    }
    if (_angulo==0){
        analogWrite(IA_MOTOR_E, minVel);
        analogWrite(IA_MOTOR_D, minVel);
    }
}

void Motor::voltar(short _angulo){
    if (_angulo < -10 || _angulo>10) return;
    analogWrite(IA_MOTOR_D, 0);
    analogWrite(IA_MOTOR_E, 0);
    delay(100);
        if (_angulo>0){
        analogWrite(IB_MOTOR_D,map(_angulo, 0,10,minVel, 255));
        analogWrite(IB_MOTOR_E, minVel);
    }
    if (_angulo<0){
        analogWrite(IB_MOTOR_E, map(_angulo, 0,-10,minVel, 255));
        analogWrite(IB_MOTOR_D, minVel);
    }
    if (_angulo==0){
        analogWrite(IB_MOTOR_E, minVel);
        analogWrite(IB_MOTOR_D, minVel);
    }
}

void  Motor::rotacionar(short _angulo){
    if(_angulo>0 && _angulo<=10){
        analogWrite(IB_MOTOR_D, 0);
        analogWrite(IA_MOTOR_E, 0);
        delay(100);
        analogWrite(IB_MOTOR_E, map(_angulo, 0,10, minVel, 255));
        analogWrite(IA_MOTOR_D, map(_angulo, 0,10, minVel, 255));
    }
    if(_angulo<0 && _angulo>=-10){
        analogWrite(IA_MOTOR_D, 0);
        analogWrite(IB_MOTOR_E, 0);
        delay(100);
        analogWrite(IA_MOTOR_E, map(_angulo, 0,-10, minVel, 255));
        analogWrite(IB_MOTOR_D, map(_angulo, 0,-10, minVel, 255));
    }
    if (_angulo == 0){
        analogWrite(IA_MOTOR_D, 0);
        analogWrite(IA_MOTOR_E, 0);
        analogWrite(IB_MOTOR_E, 0);
        analogWrite(IB_MOTOR_D, 0);
    }
}

void Motor::teste(){
    analogWrite(IA_MOTOR_D, 0);
    analogWrite(IA_MOTOR_E, 0);
    analogWrite(IB_MOTOR_D, 0);
    analogWrite(IB_MOTOR_E, 0);

    delay(1000);

    analogWrite(IA_MOTOR_D,255);
    analogWrite(IA_MOTOR_E, 0);
    delay(2000);
    analogWrite(IA_MOTOR_D, 0);
    analogWrite(IA_MOTOR_E, 0);
    delay(100);
    analogWrite(IA_MOTOR_D,0);
    analogWrite(IA_MOTOR_E, 255);
    delay(2000);
    analogWrite(IA_MOTOR_D, 0);
    analogWrite(IA_MOTOR_E, 0);
    analogWrite(IB_MOTOR_D, 0);
    analogWrite(IB_MOTOR_E, 0);
    delay(100);
    analogWrite(IB_MOTOR_D,255);
    analogWrite(IB_MOTOR_E, 0);
    delay(2000);
    analogWrite(IA_MOTOR_D, 0);
    analogWrite(IA_MOTOR_E, 0);
    delay(100);
    analogWrite(IB_MOTOR_D,0);
    analogWrite(IB_MOTOR_E, 255);
    delay(2000);
    analogWrite(IA_MOTOR_D, 0);
    analogWrite(IA_MOTOR_E, 0);

}
