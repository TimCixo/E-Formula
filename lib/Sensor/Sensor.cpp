#include <Arduino.h>
#include <QTRSensors.h>
#include "Sensor.h"

Sensor::Sensor(uint8_t pins[8], uint8_t pinLed){
    this->m_PinLed = pinLed;

    memcpy(this->m_Pins, pins, sizeof(pins));
}

void Sensor::setup(){
    this->m_Qtr.setTypeAnalog();
    this->m_Qtr.setSensorPins(this->m_Pins, this->m_SensorCount);
    this->m_Qtr.setEmitterPin(this->m_PinLed);
    
    for (uint16_t i = 0; i < 400; i++){
        this->m_Qtr.calibrate();
    }
}

void Sensor::update(){
    this->m_Value = this->m_Qtr.readLineBlack(this->m_SensorValues);
}

int16_t Sensor::getValue(){
    return this->m_Value;
}
