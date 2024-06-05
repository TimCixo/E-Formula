#include <Arduino.h>
#include "Button.h"
#include "Motor.h"
#include "Sensor.h"
#include "Movement.h"
#include "Diode.h"

double KP = 0.08, KI = 1.3, KD = 0;

Button BUTTON(12);
Sensor SENSOR((uint8_t[]){A0, A1, A2, A3, A4, A5, A6, A7}, 13);
Motor LEFT_MOTOR(9, 8, 7);
Motor RIGHT_MOTOR(3, 5, 4);
Diode DIODE(2, 10, 11);

Movement MOVEMENT(SENSOR, LEFT_MOTOR, RIGHT_MOTOR, DIODE, 6, KP, KI, KD);

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