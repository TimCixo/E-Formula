#pragma once
#include <Arduino.h>

class Diode{
    private:
    uint8_t m_RPin;
    uint8_t m_GPin;
    uint8_t m_BPin;

    public:
    Diode(uint8_t rPin, uint8_t gPin, uint8_t bPin);
    void setup();
    
    void setColor(bool red, bool green, bool blue);
};