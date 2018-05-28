#include "Motor.h"

Motor::Motor(){
    pinMode(DIR_MOTOR_D, OUTPUT);
    pinMode(DIR_MOTOR_E, OUTPUT);
    pinMode(PWM_MOTOR_D, OUTPUT);
    pinMode(PWM_MOTOR_E, OUTPUT);
    minVel = MIN_VAL;

}

void Motor::defVel(short _vel){
    if (_vel>=0&&_vel<=4){
        minVel = map(_vel, 1, 4, MIN_VAL, 220);
    }
}

void Motor::parar(){
    digitalWrite(DIR_MOTOR_D, 0);
    digitalWrite(DIR_MOTOR_E, 0);
    analogWrite(PWM_MOTOR_D, 255);
    analogWrite(PWM_MOTOR_E, 255);
}

void Motor::avancar(short _angulo){
    if (_angulo < -10 || _angulo>10) return;
    digitalWrite(DIR_MOTOR_D, 0);
    digitalWrite(DIR_MOTOR_E, 0);
    if (_angulo>0){
        analogWrite(PWM_MOTOR_D, 255-minVel-map(_angulo, 0,10,255-minVel, 255));
        analogWrite(PWM_MOTOR_E, 255-minVel);
    }
    if (_angulo<0){
        analogWrite(PWM_MOTOR_E, 255-minVel-map(_angulo, 0,-10,255-minVel, 255));
        analogWrite(PWM_MOTOR_D, 255-minVel);
    }
    if (_angulo==0){
        analogWrite(PWM_MOTOR_E, 255-minVel);
        analogWrite(PWM_MOTOR_D, 255-minVel);
    }
}

void Motor::voltar(short _angulo){
    if (_angulo < -10 || _angulo>10) return;
    digitalWrite(DIR_MOTOR_D, 1);
    digitalWrite(DIR_MOTOR_E, 1);
    if (_angulo>0){
        analogWrite(PWM_MOTOR_D, 255-minVel-map(_angulo, 0,10,255-minVel, 255));
        analogWrite(PWM_MOTOR_E, 255-minVel);
    }
    if (_angulo<0){
        analogWrite(PWM_MOTOR_E, 255-minVel-map(_angulo, 0,-10,255-minVel, 255));
        analogWrite(PWM_MOTOR_D, 255-minVel);
    }
    if (_angulo==0){
        analogWrite(PWM_MOTOR_E, 255-minVel);
        analogWrite(PWM_MOTOR_D, 255-minVel);
    }
}

void  Motor::rotacionar(short _angulo){
    if(_angulo>0 && angulo<=10){
        digitalWrite(DIR_MOTOR_D, 0);
        digitalWrite(DIR_MOTOR_E, 1);
        analogWrite(PWM_MOTOR_E, 255-map(_angulo, 0,10, 140, 255));
        analogWrite(PWM_MOTOR_D, 255-map(_angulo, 0,10, 140, 255));
    }
    if(_angulo>0 && angulo<=10){
        digitalWrite(DIR_MOTOR_D, 1);
        digitalWrite(DIR_MOTOR_E, 0);
        analogWrite(PWM_MOTOR_E, 255-map(_angulo, 0,10, 140, 255));
        analogWrite(PWM_MOTOR_D, 255-map(_angulo, 0,10, 140, 255));
    }
    if (_angulo == 0){
        digitalWrite(DIR_MOTOR_D, 0);
        digitalWrite(DIR_MOTOR_E, 0);
        analogWrite(PWM_MOTOR_E, 255);
        analogWrite(PWM_MOTOR_D, 255);
    }
}