#include "MDD10A.h"

//Input Motor Number from 1-12, and if the motor should be reversed or not.
MDD10A::MDD10A(int MotorNum, bool isReversed)
{   
    isReversed = Reversed;
    IndexNum = MotorNum - 1;
    //Stores the pinouts of the motors in arrays
    PWMPin = PWMPinArray[IndexNum];
    DirPin = DirPinArray[IndexNum];
    PWMChip = PWMChipArray[IndexNum];
    DirChip = DirChipArray[IndexNum];
    
}

//Stores the value to write to the motor controllers next time Write() is called
void MDD10A::SetSpeed(float Speed)
{   
    //Checks if it is set as reversed
    if(Reversed)
    {
        Speed = Speed*-1;
    }

    if(Speed > 0)
    {
        MasterDir = 1;
    }
    
    if(Speed <= 0)
    {
        MasterDir = 0;
    }

    MasterSpeed = abs(Speed);

    if(MasterSpeed > 255) MasterSpeed = 255;

    if(MasterSpeed > 0)
    {
        MasterSpeed = map(MasterSpeed,0,255,0,4095);
    }

    else
    {
        MasterSpeed = 0;
    }

    if(IndexNum == 0)
    {   
        Serial.print("Drive Right Speed");
        Serial.println(MasterSpeed);
        Serial.print("Drive Right Direction");
        Serial.println(MasterDir);
    }
    
}

//Actually does the writing to the motor controllers. Only call about every 20 milliseconds
void MDD10A::Write()
{
    if(PWMChip == 1)
    {
        Chip.PWM1.setPWM(PWMPin,0,MasterSpeed);
    }

    if(PWMChip ==2)
    {
        Chip.PWM2.setPWM(PWMPin,0,MasterSpeed);
    }

    if(DirChip == 1)
    {
        if(MasterDir == 0) Chip.PWM1.setPWM(DirPin,0,4096);

        if(MasterDir == 1) Chip.PWM1.setPWM(DirPin, 4096, 0);
    }

    if(DirChip == 2)
    {
        if(MasterDir == 0) Chip.PWM2.setPWM(DirPin,0,4096);

        if(MasterDir == 1) Chip.PWM2.setPWM(DirPin, 4096, 0);
    }
}

//Instantly stops the motor 
void MDD10A::Stop()
{   
    SetSpeed(0);
    Write();
}
