#pragma once
#include <Arduino.h>

class Button
{
private:
    uint8_t m_Pin;

    bool m_PreviousValue = true;
    bool m_CurrenValue = false;
    bool m_Toggled = false;

public:
    explicit Button(uint8_t pin);
    void setup();
    void update();

    bool getToggled();
};