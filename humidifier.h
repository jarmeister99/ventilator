#ifndef HUMIDIFIER_H
#define HUMIDIFIER_H

#define HUMIDIFIER_CONTROL_PIN -1

// Contains available humidifier software states
typedef enum {HUM_OFF, HUM_ON} HumidifierLevel;

void initializeHumidifier();
void toggleHumidifier();

#endif
