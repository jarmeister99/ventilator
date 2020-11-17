#ifndef INTAKE_FAN_H
#define INTAKE_FAN_H

// The GPIO pin used to provide a software PWM to the air intake fan
// (use wiringPi number)
#define AIR_INTAKE_PWM -1

// Contains the available software states of the air intake fan
typedef enum {IF_OFF, IF_LOW, IF_MED, IF_HIGH} AirIntakeLevel;

// ------------- PROTOTYPES --------------
int initializeAirIntakeFan(); // initialize air intake fan PWM settings and set to default state
void setAirIntakeFan(AirIntakeLevel); //change air intake fan level to given level

#endif
