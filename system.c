#include <wiringPi.h>
#include "system.h"
#include "dht11_driver.h"

void sysReadDHT11(){
	// TODO: Error checking
	read_dht11_dat(&(systemControl.intakeTemperature), &(systemControl.intakeHumidity)); // read DHT11 and save to systemcontrol
}
