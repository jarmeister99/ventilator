#ifndef SYSTEM_H
#define SYSTEM_H

#include "oxygen_valve.h"
#include "dht11_driver.h"
#include "intake_fan.h"
#include "humidifier.h"

// THRESHOLDS
#define INTAKE_FLOW_RATE_LOW_THRESHOLD 5
#define INTAKE_FLOW_RATE_HIGH_THRESHOLD 50

#define INTAKE_HUMIDITY_LOW_THRESHOLD 5
#define INTAKE_HUMIDITY_HIGH_THRESHOLD 50

// Contains the state of the system
typedef struct{
	OxygenLevel oxygenLevel;
        AirIntakeLevel airIntakeLevel;
        HumidifierLevel humidifierLevel;
	float intakeHumidity;
	float intakeTemperature;
	float intakeFlowRate;
} SystemControl;

extern SystemControl systemControl; // make available to others

// ---------- PROTOTYPES ---------- //
void sysReadDHT11();

#endif
