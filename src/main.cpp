#include <Arduino.h>
#include "Button.h"
#include "Motor.h"
#include "Sensor.h"
#include "Movement.h"

double KP = 0.15, KI = 0.8, KD = 0;

Button BUTTON(12);
Sensor SENSOR((uint8_t[]){A0, A1, A2, A3, A4, A5, A6, A7}, 13);
Motor LEFT_MOTOR(9, 8, 7);
Motor RIGHT_MOTOR(3, 5, 4);

Movement MOVEMENT(SENSOR, LEFT_MOTOR, RIGHT_MOTOR, KP, KI, KD);

void setup(){
    Serial.begin(9600);

    pinMode(6, OUTPUT);
    digitalWrite(6, HIGH);

    BUTTON.setup();
    MOVEMENT.setup();
}

void loop(){
    BUTTON.update();
    MOVEMENT.update();

    if(BUTTON.getToggled()){
        MOVEMENT.start();
    }
    else{
        MOVEMENT.stop();
    }
}