#pragma once
#include <Arduino.h>

class Motor{
    private:
    int8_t mPinPwm;
    int8_t mPinIn1;
    int8_t mPinIn2;

    public:
    Motor(int8_t pinPwm, int8_t pinIn1, int8_t pinIn2);
    void setup();

    void activate(int speed, bool direction);
};