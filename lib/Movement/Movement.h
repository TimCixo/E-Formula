#pragma once
#include <Arduino.h>
#include "Sensor.h"
#include "Motor.h"

class Movement{
    private:
    uint8_t m_Stby;

    int16_t m_BaseSpeed = 0;
    int16_t m_LastError = 0;
    
    double m_Kp = 0;
    double m_Ki = 0; 
    double m_Kd = 0;

    Sensor &m_Sensor;
    Motor &m_LeftMotor;
    Motor &m_RightMotor;

    public:
    Movement(Sensor &sensor, Motor &leftMotor, Motor &rightMotor, uint8_t stby, double kp, double ki, double kd);
    void setup();
    void update();

    void start();
    void stop();
};