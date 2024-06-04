#include <Arduino.h>
#include <PID_v1.h>
#include "Movement.h"

Movement::Movement(Sensor &sensor, Motor &leftMotor, Motor &rightMotor, uint8_t stby, double kp, double ki, double kd) : m_Sensor(sensor), m_LeftMotor(leftMotor), m_RightMotor(rightMotor), m_Stby(stby), m_Pid(&m_Input, &m_Output, &m_Setpoint, kp, ki, kd, DIRECT){}

void Movement::setup(){
    this->m_Sensor.setup();
    this->m_LeftMotor.setup();
    this->m_RightMotor.setup();
    this->m_Pid.SetMode(AUTOMATIC);

    pinMode(this->m_Stby, OUTPUT);
    digitalWrite(this->m_Stby, HIGH);
}

void Movement::update(){
    this->m_Sensor.update();
    this->m_Input = this->m_Sensor.getValue(); 
    this->m_Pid.Compute();
}

void Movement::start(){
    int baseSpeed = 120;
    int leftSpeed, rightSpeed;
    int speedAdjustment = static_cast<int>(this->m_Output);

    leftSpeed = constrain(baseSpeed + speedAdjustment, 0, 255);
    rightSpeed = constrain(baseSpeed - speedAdjustment, 0, 255);

    this->m_LeftMotor.setSpeed(leftSpeed);
    this->m_RightMotor.setSpeed(rightSpeed);
}

void Movement::stop(){
    this->m_LeftMotor.setSpeed(0);
    this->m_RightMotor.setSpeed(0);
}