#include <Arduino.h>
#include "Button.h"
#include "Motor.h"
#include "Sensor.h"
#include "Movement.h"

double KP = 0.08, KI = 1.3, KD = 0;

Button BUTTON(12);
Sensor SENSOR((uint8_t[]){A0, A1, A2, A3, A4, A5, A6, A7}, 13);
Motor RIGHT_MOTOR(9, 7, 8);
Motor LEFT_MOTOR(3, 5, 4);

Movement MOVEMENT(SENSOR, RIGHT_MOTOR, LEFT_MOTOR, 6, KP, KI, KD);

void setup(){
    Serial.begin(9600);

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