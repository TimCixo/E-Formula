#pragma once
#include <Arduino.h>
#include "Sensor.h"
#include "Motor.h"
#include "Diode.h"

class Movement{
    private:
    uint8_t m_Stby;

    int16_t m_BaseSpeed = 120;
    int16_t m_LastError = 0;
    
    double m_Kp = 0;
    double m_Ki = 0; 
    double m_Kd = 0;

    Sensor &m_Sensor;
    Motor &m_LeftMotor;
    Motor &m_RightMotor;
    Diode &m_Diode;

    public:
    Movement(Sensor &sensor, Motor &leftMotor, Motor &rightMotor, Diode &diode, uint8_t stby);
    void setup();
    void update();

    void setPidParameters(double kp, double ki, double kd);
    void setBaseSpeed(uint16_t baseSpeed);
    void start();
    void stop();
};
