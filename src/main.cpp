#include <Arduino.h>
#include "Button.h"
#include "Motor.h"
#include "Sensor.h"
#include "Movement.h"
#include "Diode.h"

const uint16_t BASE_SPEED = 150;
const double KP = 0.024, KI = 0.06, KD = 0.14;

Button BUTTON(12);
Sensor SENSOR((uint8_t[]){A0, A1, A2, A3, A4, A5, A6, A7}, 13);
Motor LEFT_MOTOR(9, 7, 8);
Motor RIGHT_MOTOR(3, 5, 4); // Motors too
Diode DIODE(10, 11, 2);

Movement MOVEMENT(SENSOR, LEFT_MOTOR, RIGHT_MOTOR, DIODE, 6);

void setup(){
    Serial.begin(9600);

    BUTTON.setup();
    MOVEMENT.setup();

    MOVEMENT.setBaseSpeed(BASE_SPEED);
    MOVEMENT.setPidParameters(KP, KI, KD);
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
