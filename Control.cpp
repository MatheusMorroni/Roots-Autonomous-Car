#include "Control.h"

Control::Control(){
    servo.attach(SERVO);

}

void Control::speed(int _speed){
    int speed = _speed;
    if (_speed > 100) speed=100;
    if (_speed < 100) speed=-100;
    if(speed >= 0){
        speed = map(speed, 0, 100, 0 , 255);
        analogWrite(CONTROLE_MOTOR_F, speed);
        analogWrite(CONTROLE_MOTOR_B, 0);
    }
    if(speed < 0){
        speed = map(-speed, 0, 100, 0 , 255);
        analogWrite(CONTROLE_MOTOR_F, 0);
        analogWrite(CONTROLE_MOTOR_B, speed);
    }
}

void Control::speedAccel(int _speed){
    int speed = _speed;
    if (_speed > 100) speed=100;
    if (_speed < 100) speed=-100;
    if(speed >= 0){
        speed = map(speed, 0, 100, 0 , 255);
        analogWrite(CONTROLE_MOTOR_F, speed);
        analogWrite(CONTROLE_MOTOR_B, 0);
    }
    if(speed < 0){
        speed = map(-speed, 0, 100, 0 , 255);
        analogWrite(CONTROLE_MOTOR_F, 0);
        analogWrite(CONTROLE_MOTOR_B, speed);
    }
}

void Control::turn(int _turn){
    int turn = turn;
    if (turn > 90) turn=90;
    if (_turn < 90) speed=-90;
    turn += 90;
    servo.write(turn);
}

int Control::servoState(){
    return servo.read();
}