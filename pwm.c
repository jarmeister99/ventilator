#include <wiringPi.h>

void initializePWM(){
        // make PWM use mark-space mode
        pwmSetMode(PWM_MODE_MS);

        pwmSetRange(1000); // 20 ms period
        pwmSetClock(1080); // 20 ms period
}
