#include <Arduino.h>
#include <PID_v1.h>
#include "Movement.h"

Movement::Movement(Sensor &sensor, Motor &leftMotor, Motor &rightMotor, double kp, double ki, double kd) : mSensor(sensor), mLeftMotor(leftMotor), mRightMotor(rightMotor), mPid(&mInput, &mOutput, &mSetpoint, kd, ki, kd, DIRECT){}

void Movement::setup(){
    this->mSensor.setup();
    this->mLeftMotor.setup();
    this->mRightMotor.setup();
    this->mPid.SetMode(AUTOMATIC);
}

void Movement::update(){
    this->mSensor.update();
    this->mInput = this->mSensor.getValue(); 
    this->mPid.Compute(); 

    Serial.print(this->mInput);
    Serial.print(" ");
    Serial.println(this->mOutput);

}

void Movement::startMoving(){
    int threshold = 10;
    int baseSpeed = 100;
    int leftSpeed, rightSpeed;
    
    Serial.println(this->mOutput);

    if (abs(this->mOutput) < threshold) {
        leftSpeed = constrain(baseSpeed, 0, 255);
        rightSpeed = constrain(baseSpeed, 0, 255);
    } else {
        leftSpeed = constrain(255 + this->mOutput, 0, 255); 
        rightSpeed = constrain(255 - this->mOutput, 0, 255);
    }
}

void Movement::stop(){
    this->mLeftMotor.activate(0, true);
    this->mRightMotor.activate(0, true);
}