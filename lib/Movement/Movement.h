#pragma once
#include <Arduino.h>
#include <PID_v1.h>
#include "Sensor.h"
#include "Motor.h"

class Movement{
    private:
    
    Sensor m_Sensor;
    Motor m_LeftMotor;
    Motor m_RightMotor;
    PID m_Pid;

    double m_Setpoint = 3500;
    double m_Input = 0; 
    double m_Output = 0;

    public:
    Movement(Sensor &sensor, Motor &leftMotor, Motor &rightMotor, double kp, double ki, double kd);
    void setup();
    void update();

    void start();
    void stop();
};