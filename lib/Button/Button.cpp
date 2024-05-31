#include <Arduino.h>
#include "Button.h"

Button::Button(uint8_t pin){
    this->m_Pin = pin;
}

void Button::setup(){
    pinMode(this->m_Pin, INPUT_PULLUP);

}

void Button::update(){
    this->m_CurrenValue = digitalRead(this->m_Pin);

    if(this->m_PreviousValue < this->m_CurrenValue){
        this->m_TurnOn = !this->m_TurnOn;
    }

    this->m_PreviousValue = this->m_CurrenValue;
}

bool Button::getTurnOn(){
    return this->m_TurnOn;
}