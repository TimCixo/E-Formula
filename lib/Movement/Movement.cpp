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

void Movement::startMoving(){
    int threshold = 10;
    int baseSpeed = 100;
    int leftSpeed, rightSpeed;

    if (abs(this->m_Output) < threshold) {
        leftSpeed = constrain(baseSpeed, 0, 255);
        rightSpeed = constrain(baseSpeed, 0, 255);
    } else {
        leftSpeed = constrain(255 + this->m_Output, 0, 255); 
        rightSpeed = constrain(255 - this->m_Output, 0, 255);
    }
}

void Movement::stop(){
    this->m_LeftMotor.activate(0, true);
    this->m_RightMotor.activate(0, true);
}