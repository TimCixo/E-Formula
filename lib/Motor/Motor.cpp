#include <Arduino.h>
#include "Motor.h"

Motor::Motor(uint8_t pinPwm, uint8_t pinIn1, uint8_t pinIn2){
    this->m_PinPwm = pinPwm;
    this->m_PinIn1 = pinIn1;
    this->m_PinIn2 = pinIn2;
}

void Motor::setup(){
    pinMode(this->m_PinPwm, OUTPUT);
    pinMode(this->m_PinIn1, OUTPUT);
    pinMode(this->m_PinIn2, OUTPUT);
}

void Motor::activate(int speed, bool direction){
    if(direction){
        digitalWrite(m_PinIn1, HIGH);
        digitalWrite(m_PinIn2, LOW);
    }
    else{
        digitalWrite(m_PinIn1, LOW);
        digitalWrite(m_PinIn2, HIGH);
    }

    analogWrite(m_PinPwm, speed);
}