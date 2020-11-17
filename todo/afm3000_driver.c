#include <wiringPiI2C.h>	
#include "system.h"


// TODO: Implement CRC checking
uint16_t read_afm3000_data(){
	uint16_t telemetry;
	uint8_t high, low, crc;
	wiringPiI2CWrite(AFM3000_ADDRESS, READ_FLOW_COLLECTION_DATA);
	high = wiringPiI2CRead(AFM3000_ADDRESS);
	low = wiringPiI2CRead(AFM3000_ADDRESS);
	crc = wiringPiI2CRead(AFM3000_ADDRESS);
	telemetry = (high << 8) | low;
	if (

}

void setup()
{
	Wire.begin();
	Serial.begin(9600);
	int high,low,c = 0;
 
	delay(1000);

	Wire.beginTransmission(byte(0x40)); /* transmit to device ID #064 (0x40) */
	Wire.write(byte(0x10));      
	Wire.write(byte(0x00));      
	Wire.endTransmission(); 

	delay(5);

	Wire.requestFrom(0x40, 3); /* FIRST TRANSMISSION ALWAYS FAULTY AS PER DATASHEET, THAT'S WHY THERE ARE TWO CYCLES OF REQUESTS*/
	high = Wire.read(); /* first received byte */
	low = Wire.read(); /* second received byte  */
	crc = Wire.read(); /* third received byte  */
	Wire.endTransmission();
	Serial.print(high); 
	Serial.print(low);
	Serial.println(c);

	delay(5);
 
	Wire.requestFrom(0x40, 3); /* FIRST REAL DATA */
	high = Wire.read(); /* first received byte */
	low = Wire.read(); /* second received byte */
	crc = Wire.read(); /* third received byte */
	Wire.endTransmission();
	Serial.print(high);
	Serial.print(low);
	Serial.println(c);

	delay(5);
}

uint8_t crc8(const uint8_t data, uint8_t crc) {
	crc ^= data;

	for (uint8_t i = 8; i; --i) {
		crc = ( crc & 0x80 ) ? (crc << 1) ^ 0x31 : (crc << 1);
	}
	return crc;
}

void loop(){
	int offset = 32000; /* Offset for the sensor */
	float scale = 142.8; /* Scale factors-  N2: 140.0 | O2: 142.8 */

 
	Wire.requestFrom(0x40, 3); /* read 3 bytes from device with address 0x40 1. Top half of 16-byte data 2. Bottom half of 16-bit data 3. CRC stuffs*/
	uint16_t high = Wire.read(); /* first received byte stored here. uint16_t because other half will be thrown into it */
	uint8_t low = Wire.read(); /* second received byte stored here */
	uint8_t crc = Wire.read(); /* crc stored */
	uint8_t mycrc = 0xFF; /* initialize crc var */
	mycrc = crc8(a, mycrc); /* let first byte through CRC calc */
	mycrc = crc8(b, mycrc); /* + second byte (16-bit) */
	if (mycrc != crc) { /* check if the calculated and the received CRC byte matches */
		Serial.println("Error: wrong CRC");
	}
	high = (high << 8) | low; /* 8bit + 8bit => 16bit */
	high >>= 2; /* remove the two least significant bits, I DON'T KNOW IF THIS IS COMPLETELY NECCESSARY */
	float Flow = ((float)high - offset) / scale;
	Serial.println(high); /* raw data to serial interface */
	Serial.println(Flow); /* calculated flow to serial interface */

	delay(25);
}
