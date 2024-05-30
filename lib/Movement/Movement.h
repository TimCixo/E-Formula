#pragma once
#include <Arduino.h>
#include <PID_v1.h>
#include "Sensor.h"
#include "Motor.h"

class Movement{
    private:
    double mSetpoint = 3500;
    double mInput, mOutput;
    
    Sensor mSensor;
    Motor mLeftMotor;
    Motor mRightMotor;
    PID mPid;

    public:
    Movement(Sensor &sensor, Motor &leftMotor, Motor &rightMotor, double kp, double ki, double kd);
    void setup();
    void update();

    void startMoving();
    void stop();
};