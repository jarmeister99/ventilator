#include <wiringPi.h>
#include <unistd.h>
#include "system.h"
#include "humidifier.h"

void initializeHumidifier(){
    pinMode(HUMIDIFIER_CONTROL_PIN, OUTPUT);
}

void toggleHumidifier(){
    digitalWrite(HUMIDIFIER_CONTROL_PIN, 0); // control pin low 
    usleep(500000); // wait 500 ms
    digitalWrite(HUMIDIFIER_CONTROL_PIN, 1); // control pin high
    systemControl.humidifierLevel ^= 1; // toggle humidifier level 
}
