#include <wiringPi.h>
#include <unistd.h>
#include "system.h"
#include "intake_fan.h"
#include "pwm.h"

int initializeAirIntakeFan(){
    	// initialize air intake fan control pin
	pinMode(AIR_INTAKE_PWM, PWM_OUTPUT);
	setAirIntakeFan(systemControl.airIntakeLevel); // set default air intake level
}

void setAirIntakeFan(AirIntakeLevel level){
    	systemControl.airIntakeLevel = level; // save level to system control
	pwmWrite(OXYGEN_VALVE_PWM, level * PULSE_6MS); // 30% duty cycle per level 
	usleep(100000); // wait 100ms TODO: handle more gracefully
}
