#include <Arduino.h>
#include "Diode.h"

Diode::Diode(uint8_t rPin, uint8_t gPin, uint8_t bPin){
    this->m_RPin = rPin;
    this->m_GPin = gPin;
    this->m_BPin = bPin;
}

void Diode::setup(){
    pinMode(this->m_RPin, OUTPUT);
    pinMode(this->m_GPin, OUTPUT);
    pinMode(this->m_BPin, OUTPUT);
}

void Diode::setColor(bool red, bool green, bool blue){
    digitalWrite(this->m_RPin, red);
    digitalWrite(this->m_GPin, green);
    digitalWrite(this->m_BPin, blue);
}