#include <Arduino.h>
#include <PID_v1.h>
#include "Button.h"
#include "Motor.h"
#include "Sensor.h"
#include "Movement.h"

double KP = 0.08, KI = 0, KD = 1.3;

Button BUTTON(12);
Sensor SENSOR((uint8_t[]){A0, A1, A2, A3, A4, A5, A6, A7}, 13);
Motor LEFT_MOTOR(3, 5, 4);
Motor RIGHT_MOTOR(8, 6, 7);

Movement MOVEMENT(SENSOR, LEFT_MOTOR, RIGHT_MOTOR, KP, KI, KD);

void setup(){
    Serial.begin(9600);

    BUTTON.setup();
    MOVEMENT.setup();
}

void loop(){
    BUTTON.update();
    MOVEMENT.update();

    if(BUTTON.getTurnOn()){
        MOVEMENT.startMoving();
    }
    else{
        MOVEMENT.stop();
    }
}