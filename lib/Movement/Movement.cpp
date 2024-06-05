#include <Arduino.h>
#include "Movement.h"

Movement::Movement(Sensor &sensor, Motor &leftMotor, Motor &rightMotor, Diode &diode, uint8_t stby, double kp, double ki, double kd) : m_Sensor(sensor), m_LeftMotor(leftMotor), m_RightMotor(rightMotor), m_Diode(diode), m_Stby(stby), m_Kp(kp), m_Ki(ki), m_Kd(kd) {}

void Movement::setup()
{
    this->m_Diode.setColor(1, 0, 0);

    this->m_Sensor.setup();

    this->m_Diode.setColor(0, 1, 0);

    this->m_LeftMotor.setup();
    this->m_RightMotor.setup();

    pinMode(this->m_Stby, OUTPUT);
    digitalWrite(this->m_Stby, HIGH);
}

void Movement::update()
{
    this->m_Sensor.update();
}

void Movement::start()
{
    this->m_Diode.setColor(0, 0, 1);

    int16_t position = this->m_Sensor.getValue() - 3500;
    int16_t speedAdjustment = this->m_Kp * position + this->m_Ki * (position - m_LastError);
    
    this->m_LastError = position;

    int16_t rightMotorSpeed = constrain(this->m_BaseSpeed - speedAdjustment, 0, 255);
    int16_t leftMotorSpeed = constrain(this->m_BaseSpeed + speedAdjustment, 0, 255);

    this->m_LeftMotor.setSpeed(leftMotorSpeed);
    this->m_RightMotor.setSpeed(rightMotorSpeed);
}

void Movement::stop()
{
    this->m_Diode.setColor(0, 1, 0);

    this->m_LeftMotor.setSpeed(0);
    this->m_RightMotor.setSpeed(0);
}