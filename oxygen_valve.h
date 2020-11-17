#ifndef OXYGEN_VALVE_H
#define OXYGEN_VALVE_H

// The GPIO pin used to provide a software PWM to the oxygen valve servo
// (use wiringPi number)
#define OXYGEN_VALVE_PWM 23

// Contains the available software states of the oxygen release valve
//
// The oxygen release valve is adjusted using a 300 degree servo. The valve contains 12 discrete click locations located in 30 degree intervals.
//
// LEVEL0	  0 degrees (NO AIR FLOW)
// LEVEL1	 30 degrees
// LEVEL2	 60 degrees
// LEVEL3	 90 degrees
// LEVEL4	120 degrees
// LEVEL5	150 degrees
// LEVEL6	180 degrees
// LEVEL7	210 degrees
// LEVEL8	240 degrees
// LEVEL9	270 degrees
// LEVEL10	300 degrees (MAX AIR FLOW)
typedef enum {OXY_LEVEL0, OXY_LEVEL1, OXY_LEVEL2, OXY_LEVEL3, OXY_LEVEL4, OXY_LEVEL5, OXY_LEVEL6, OXY_LEVEL7, OXY_LEVEL8, OXY_LEVEL9, OXY_LEVEL10} OxygenLevel;

// ------------- PROTOTYPES --------------
int initializeOxygenValve(); // initialize oxygen valve PWM settings and set to default state
void setOxygenValve(OxygenLevel level); // change oxygen valve to given level

#endif
