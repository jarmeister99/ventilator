#include <wiringPiI2C.h>
#include <wiringPi.h>
#include "i2c.h"

int initializeI2C(){
	int fd;
	fd = wiringPiI2CSetup(VENTILATOR_ADDRESS);
	return fd;
}
