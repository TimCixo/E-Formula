#pragma once
#include <Arduino.h>

class Button
{
private:
    int8_t mPin;

    bool mPreviousValue = true;
    bool mCurrenValue = false;
    bool mTurnOn = false;

public:
    explicit Button(int8_t pin);
    void setup();
    void update();

    bool getTurnOn();
};