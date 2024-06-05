#pragma once
#include <Arduino.h>
#include <QTRSensors.h>

class Sensor{
    private:
    static const int m_SensorCount = 8;

    uint8_t m_Pins[8];
    uint8_t m_PinLed;

    int16_t m_Value = 0;
    uint16_t m_SensorValues[m_SensorCount];
    QTRSensors m_Qtr;

    public:
    Sensor(uint8_t pins[m_SensorCount], uint8_t pinLed);
    void setup();
    void update();

    int16_t getValue();
};