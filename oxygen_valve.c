#include <wiringPi.h>
#include <unistd.h>
#include "system.h"
#include "pwm.h"
#include "oxygen_valve.h"

// Initialize oxygen valve driver 
//
// Oxygen valve driver uses a hardware PWM
int initializeOxygenValve(){
	// initialize oxygen release servo control pin
	pinMode(OXYGEN_VALVE_PWM, PWM_OUTPUT);
	setOxygenValve(systemControl.oxygenLevel); // set default oxygen value
}

// Generate a PWM for the servo that generates the rotation required by the given oxygen level
// 
// A hardware generated PWM is used
//
// 0   degrees = 500 us pulse (25)
// 30  degrees = 700 us pulse (35)
// 60  degrees = 900 us pulse (45)
// 90  degrees = 900 us pulse (55)
// 120 degrees = 900 us pulse (65)

void setOxygenValve(OxygenLevel level){
	systemControl.oxygenLevel = level; // save level to system control
	pwmWrite(OXYGEN_VALVE_PWM, PULSE_500US + (PULSE_200US * level));
	usleep(100000); // wait 100ms TODO: handle more gracefully
}
