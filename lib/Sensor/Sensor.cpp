#include <Arduino.h>
#include <QTRSensors.h>
#include "Sensor.h"

Sensor::Sensor(int8_t pins[8], int8_t pinLed){
    for(int i = 0; i < 8; i++){
        this->mPins[i] = pins[i];
    }

    this->mPinLed = pinLed;
}

void Sensor::setup(){
    this->mQtr.setTypeAnalog();
    this->mQtr.setSensorPins((const uint8_t[]){A0, A1, A2, A3, A4, A5, A6, A7}, this->mSensorCount);
    this->mQtr.setEmitterPin(this->mPinLed);
    
    for (uint16_t i = 0; i < 400; i++)
    {
        this->mQtr.calibrate();
    }
}

void Sensor::update(){
    this->mValue  = this->mQtr.readLineBlack(this->mSensorValues);
    
    for (uint8_t i = 0; i < this->mSensorCount; i++)
    {
        Serial.print(this->mSensorValues[i]);
        Serial.print('\t');
    }
    Serial.println(this->mValue );
}

int Sensor::getValue(){
    return this->mValue;
}
