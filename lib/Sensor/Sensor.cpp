#include <Arduino.h>
#include <QTRSensors.h>
#include "Sensor.h"

Sensor::Sensor(uint8_t pins[8], uint8_t pinLed){
    for(int i = 0; i < 8; i++){
        this->m_Pins[i] = pins[i];
    }

    this->m_PinLed = pinLed;
}

void Sensor::setup(){
    this->m_Qtr.setTypeAnalog();
    this->m_Qtr.setSensorPins(this->m_Pins, this->mSensorCount);
    this->m_Qtr.setEmitterPin(this->m_PinLed);
    
    for (uint16_t i = 0; i < 400; i++){
        this->m_Qtr.calibrate();
    }
}

void Sensor::update(){
    this->m_Value = this->m_Qtr.readLineBlack(this->m_SensorValues);
}

int Sensor::getValue(){
    return this->m_Value;
}
