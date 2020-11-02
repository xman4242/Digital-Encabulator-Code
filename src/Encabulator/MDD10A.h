#pragma once
#ifndef MDD10A_h
#define MDD10A_h

#include "MOTORCHIP.h"

class MDD10A
{
private:
    int MasterSpeed = 0;
    int WriteSpeed = 0;
    int MasterDir = 0;
    int PWMChip = 0;
    int PWMPin = 0;
    int DirChip = 0;
    int DirPin = 0;
    int IndexNum = 0;
    bool Reversed = false;
    int PWMChipArray[12] = {1,1,1,1,1,1,2,2,2,2,2,2};
    int DirChipArray[12] = {1,1,1,1,1,1,2,2,2,2,2,2};
    int PWMPinArray[12] = {0,2,4,6,8,10,12,14,0,2,4,6};
    int DirPinArray[12] = {1,3,5,7,9,11,13,15,1,3,5,7};
    MOTORCHIP Chip; 

public:
    //Constructor for the motor class
    MDD10A(int MotorNum, bool isReversed);

    void SetSpeed(float Speed);
    void Write();
    void Stop();

    

    
};






#endif //MDD10A_h