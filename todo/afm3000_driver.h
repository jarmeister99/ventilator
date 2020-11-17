#include <wiringPi.h>
#include <wiringPiI2C.h>

#define AFM3000_ADDRESS 0x40
#define READ_FLOW_COLLECTION_DATA 0x10

#define FLOW_COLLECTION_OFFSET 32000
#define FLOW_COLLECTION_SCALE 142.8 // 142.8 for oxygen

uint16_t read_afm3000_data();
