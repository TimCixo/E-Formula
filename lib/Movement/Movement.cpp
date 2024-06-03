#include <Arduino.h>
#include <PID_v1.h>
#include "Movement.h"

Movement::Movement(Sensor &sensor, Motor &leftMotor, Motor &rightMotor, double kp, double ki, double kd) : m_Sensor(sensor), m_LeftMotor(leftMotor), m_RightMotor(rightMotor), m_Pid(&m_Input, &m_Output, &m_Setpoint, kd, ki, kd, DIRECT){}

void Movement::setup(){
    this->m_Sensor.setup();
    this->m_LeftMotor.setup();
    this->m_RightMotor.setup();
    this->m_Pid.SetMode(AUTOMATIC);
}

void Movement::update(){
    this->m_Sensor.update();
    this->m_Input = this->m_Sensor.getValue(); 
    this->m_Pid.Compute(); 
}

void Movement::start(){
    int baseSpeed = 100;
    int leftSpeed, rightSpeed;
    int speedAdjustment = static_cast<int>(this->m_Output);

    rightSpeed = constrain(baseSpeed - speedAdjustment, 0, 255);
    leftSpeed = constrain(baseSpeed + speedAdjustment, 0, 255);

    this->m_LeftMotor.setSpeed(leftSpeed);
    this->m_RightMotor.setSpeed(rightSpeed);
}

void Movement::stop(){
    this->m_LeftMotor.setSpeed(0);
    this->m_RightMotor.setSpeed(0);
}