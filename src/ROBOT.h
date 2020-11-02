#ifndef ROBOT_h
#define ROBOT_h
//Includes
#include"Encabulator/ENCABULATOR.h"
#include "PS4Controller.h"
#include"Encabulator/MDD10A.h"
#include"Encoder.h"
#include "Autonomous/AUTONOMOUS.h"
#include"STATE.h"

class ROBOT
{
private:

public:
    ROBOT();
    //Functions
    void Setup();
    void Loop();
    
    
    //Vars
    //Create Temporary variables for drive speed for all new motors
    int16_t DriveRightSpeed = 0;
    int16_t DriveLeftSpeed = 0;
    int16_t LiftSpeed = 0;
    int16_t ClawSpeed = 0;
    long NextMotorTime = 0;
    long NextDisplayTime = 0;
    bool PrecisonMode = false;
    int SmallRumble = 0;
    int LargeRumble = 0;
    int LeftEncVal = 0;
    int RightEncVal = 0;

    //The Class for the main behind-the-scenes Functions
    ENCABULATOR Brain;
    //Class for the PS4 Controller
    PS4Controller PS4;
    //Auton Class
    AUTONOMOUS Auton;
    //State Class
    STATE State;

    //All the motors
    //Change the name to whatever you want - make sure to change it in Robot.cpp!
     
    //Right Drive Motor
    MDD10A DriveRight;
    //Left Drive Motor
    MDD10A DriveLeft;
    //Lift Motor
    MDD10A Lift;
    //Claw Motor
    MDD10A Claw;
    //User Motor 5
    MDD10A Motor5;
    //User Motor 6
    MDD10A Motor6;
    //User Motor 7
    MDD10A Motor7;
    //User Motor 8
    MDD10A Motor8;
    //User Motor 9
    MDD10A Motor9;
    //User Motor 10
    MDD10A Motor10;
    //User Motor 11
    MDD10A Motor11;
    //User Motor 12
    MDD10A Motor12;

    //Some encoders - any you add need to be declared here and in Robot.cpp

    //Left Encoder 
    Encoder LeftEnc;
    //Right Encoder
    Encoder RightEnc;

    //Pinouts and config
    const int OnboardLED = 13;
    //The pin number for the ReoffPin
    static const int ReoffPin = 39;
    //Number of Autons
    static const int NumberofAutons = 4;
    //Encoder pinouts
    const int LeftEncoderPin1 = 0;
    const int LeftEncoderPin2 = 0;
    const int RightEncoderPin1 = 0;
    const int RightEncoderPin2 = 0;  
    
    

};
#endif