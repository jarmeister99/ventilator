/* Bradley Weeks 11/02/20 /*
/* Raspberry Pi 4+ Humidity Sensor Code */
/* Prints out humidity to console */
/* Modified by Jared Foster 11/16/2020 */

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#define MAXTIMINGS	85
#define DHTPIN		7
int dht11_dat[5] = { 0, 0, 0, 0, 0 };
 
int read_dht11_dat(float *temp, float *humidity)
{
	uint8_t laststate	= HIGH;
	uint8_t counter		= 0;
	uint8_t j		= 0;
	uint8_t i		= 0;
        
        /* erase mem */
	dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0; // clear DHT memory
 
	pinMode( DHTPIN, OUTPUT ); // configure DHT pin as output
	digitalWrite( DHTPIN, LOW ); // bring DHT pin low
	usleep(18000); // wait 18 ms
	digitalWrite( DHTPIN, HIGH ); // bring DHT pin high
	usleep(40); // wait 40 us
	pinMode(DHTPIN, INPUT); // switch DHTPIN to input
 
	for (i = 0; i < MAXTIMINGS; i++){
		counter = 0; // start counter at 0
		while (digitalRead(DHTPIN) == laststate) // constant poll state
		{
			// if state is unchanged
			counter++; // increment count
			usleep(1); // delay 1 us
			if (counter == 255) // break after 255 unchanged state checks
			{
				break;
			}
		}
		laststate = digitalRead(DHTPIN); // save current pin results
 
		if (counter == 255) // break after 255 counts
			break;
 
		if ((i >= 4) && (i % 2 == 0)) //
		{
			dht11_dat[j / 8] <<= 1;
			if ( counter > 16 )
				dht11_dat[j / 8] |= 1;
			j++;
		}
	}
 
	if ( (j >= 40) && (dht11_dat[4] == ( (dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF) ) )
	{
		*humidity = (float)dht11_dat[0] + ((float)dht11_dat[1] / 100); // save humidity to output buffer
		*temp = (float)dht11_dat[2] + ((float)dht11_dat[3] / 100); // save temperature to output buffer
		return 0; 
	}
	else{
		return -1;
	}
}
 
