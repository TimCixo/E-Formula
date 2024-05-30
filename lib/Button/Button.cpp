#include <Arduino.h>
#include "Button.h"

Button::Button(int8_t pin){
    this->mPin = pin;
}

void Button::setup(){
    pinMode(this->mPin, INPUT_PULLUP);

}

void Button::update(){
    this->mCurrenValue = digitalRead(this->mPin);

    if(this->mPreviousValue < this->mCurrenValue){
        this->mTurnOn = !this->mTurnOn;
    }

    this->mPreviousValue = this->mCurrenValue;
}

bool Button::getTurnOn(){
    return this->mTurnOn;
}