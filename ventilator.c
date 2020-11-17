#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include "oxygen_valve.h"
#include "intake_fan.h"
#include "humidifier.h"
#include "system.h"
#include "pwm.h"

// Initialize system state
SystemControl systemControl = {
	.oxygenLevel = OXY_LEVEL0, // default to no oxygen flow
        .airIntakeLevel = IF_OFF, // default to no air intake
        .humidifierLevel = HUM_OFF, // default to humidifier off
	.intakeHumidity = 0.0F, // no humidity by default
	.intakeTemperature = 0.0F, // 0 degrees by default
	.intakeFlowRate = 0.0F // no flow by default
};

int main(int argc, char **argv){
	wiringPiSetup();
        initializePWM();
	initializeOxygenValve();
        initializeAirIntakeFan();
        initializeHumidifier();

	while(1){
		// read humidity & temp sensor
		sysReadDHT11();
		// if we are below lower threshold
		if (systemControl.intakeHumidity < INTAKE_HUMIDITY_LOW_THRESHOLD){
			
		}
		// if we are above upper threshold
		else if (systemControl.intakeHumidity > INTAKE_HUMIDITY_HIGH_THRESHOLD){
		
		}

		// read flow rate sensor
		// TODO: implement
		// if we are below lower threshold
		if (systemControl.intakeFlowRate < INTAKE_FLOW_RATE_LOW_THRESHOLD){
		
		}
		// if we are above upper threshold
		else if (systemControl.intakeFlowRate > INTAKE_FLOW_RATE_HIGH_THRESHOLD){
			
		}
	}
}
