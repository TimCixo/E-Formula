#include <Arduino.h>
#include "Motor.h"

Motor::Motor(int8_t pinPwm, int8_t pinIn1, int8_t pinIn2){
    this->mPinPwm = pinPwm;
    this->mPinIn1 = pinIn1;
    this->mPinIn2 = pinIn2;
}

void Motor::setup(){
    pinMode(this->mPinPwm, OUTPUT);
    pinMode(this->mPinIn1, OUTPUT);
    pinMode(this->mPinIn2, OUTPUT);
}

void Motor::activate(int speed, bool direction){
    if(direction){
        digitalWrite(mPinIn1, HIGH);
        digitalWrite(mPinIn2, LOW);
    }
    else{
        digitalWrite(mPinIn1, LOW);
        digitalWrite(mPinIn2, HIGH);
    }

    analogWrite(mPinPwm, speed);
}