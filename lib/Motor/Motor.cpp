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

    digitalWrite(m_PinIn1, HIGH);
    digitalWrite(m_PinIn2, LOW);
}

void Motor::setSpeed(int speed){
    analogWrite(m_PinPwm, speed);
}