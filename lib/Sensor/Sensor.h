#pragma once
#include <Arduino.h>
#include <QTRSensors.h>

class Sensor{
    private:
    static const int mSensorCount = 8;

    int8_t mPins[8];
    int8_t mPinLed;

    int mValue = 0;
    uint16_t mSensorValues[mSensorCount];
    QTRSensors mQtr;

    public:
    Sensor(int8_t pins[8], int8_t pinLed);
    void setup();
    void update();

    int getValue();
};