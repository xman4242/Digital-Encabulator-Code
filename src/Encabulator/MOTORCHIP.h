#ifndef MOTORCHIP_H
#define MOTORCHIP_H

#include "Adafruit_PWMServoDriver.h"

class MOTORCHIP
{
private:
    
public:

    //PWM Chip 1
    Adafruit_PWMServoDriver PWM1 = Adafruit_PWMServoDriver(0x40);
    //PWM Chip 2
    Adafruit_PWMServoDriver PWM2 = Adafruit_PWMServoDriver(0x41);

};



#endif