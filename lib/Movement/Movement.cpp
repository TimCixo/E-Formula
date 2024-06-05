#include <Arduino.h>
#include "Movement.h"

Movement::Movement(Sensor &sensor, Motor &leftMotor, Motor &rightMotor, uint8_t stby, double kp, double ki, double kd) : m_Sensor(sensor), m_LeftMotor(leftMotor), m_RightMotor(rightMotor), m_Stby(stby), m_Kp(kp), m_Ki(ki), m_Kd(kd) {}

void Movement::setup()
{
    this->m_Sensor.setup();
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
    int16_t position = this->m_Sensor.getValue() - 3500;
    int16_t speedAdjustment = this->m_Kp * position + this->m_Ki * (position - this->m_LastError);
    
    this->m_LastError = position;

    int16_t leftMotorSpeed = constrain(this->m_BaseSpeed + speedAdjustment, 0, 255);
    int16_t rightMotorSpeed = constrain(this->m_BaseSpeed - speedAdjustment, 0, 255);

    Serial.print("position:\t");
    Serial.print(position);
    Serial.print("\tspeed:\t");
    Serial.print(speedAdjustment);
    Serial.print("\terror:\t");
    Serial.print(this->m_LastError);
    Serial.print("\tleft:\t");
    Serial.print(rightMotorSpeed);
    Serial.print("\tright:\t");
    Serial.println(leftMotorSpeed);

    this->m_LeftMotor.setSpeed(leftMotorSpeed);
    this->m_RightMotor.setSpeed(rightMotorSpeed);
}

void Movement::stop()
{
    this->m_LeftMotor.setSpeed(0);
    this->m_RightMotor.setSpeed(0);
}