#pragma once
#include <Arduino.h>

class Motor{
    private:
    uint8_t m_PinPwm;
    uint8_t m_PinIn1;
    uint8_t m_PinIn2;

    public:
    Motor(uint8_t pinPwm, uint8_t pinIn1, uint8_t pinIn2);
    void setup();

    void activate(int speed, bool direction);
};