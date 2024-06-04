#include <Arduino.h>
#include "Button.h"

Button::Button(uint8_t pin){
    this->m_Pin = pin;
}

void Button::setup(){
    pinMode(this->m_Pin, INPUT_PULLUP);

}

void Button::update(){
    bool previousValue = this->m_CurrenValue;
    this->m_CurrenValue = digitalRead(this->m_Pin);

    if(previousValue < this->m_CurrenValue){
        this->m_Toggled = !this->m_Toggled;
    }
}

bool Button::getToggled(){
    return this->m_Toggled;
}