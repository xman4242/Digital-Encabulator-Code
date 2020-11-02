#include "ROBOT.h"

ROBOT::ROBOT() :
//Motor Constructors Here. Takes the actual motor number, then whether it is reversed or not. You must reverse 1 drive motor 
DriveRight(1,false),
DriveLeft(2, true),
Lift(3,false),
Claw(4,false),
Motor5(5,false),
Motor6(6,false),
Motor7(7,false),
Motor8(8,false),
Motor9(9,false),
Motor10(10,false),
Motor11(11,false),
Motor12(12,false),
//Encoder Constructors only take pin numbers. 
LeftEnc(LeftEncoderPin1,LeftEncoderPin2),
RightEnc(RightEncoderPin1,RightEncoderPin2),
Auton(*this) 
{  
}


//Init Motor controller, pins, and PS4
void ROBOT::Setup()
{   
    //Make sure you change this address! You can't have the same one as anyone else
    PS4.begin("03:03:03:03:03:03");
    Serial.println("PS4 Ready");

    //Sets the LED next to the USB port on. 
    pinMode(OnboardLED, OUTPUT);
    digitalWrite(OnboardLED, HIGH);
    //REOFF pinMode
    pinMode(ReoffPin, INPUT);
    
}

void ROBOT::Loop()
{   
   
    //Read the controller
    //Need some PS4 wrapper functions
    //This caused MC lib to fail

    if(PS4.data.analog.stick.ly > 10 || PS4.data.analog.stick.ly < -10)
    {
        DriveLeftSpeed = (PS4.data.analog.stick.ly)*2;
    }
    
    if(PS4.data.analog.stick.ry > 10 || PS4.data.analog.stick.ry < -10)
    {
        DriveRightSpeed = (PS4.data.analog.stick.ry)*2;
    }
    
    if(PrecisonMode)
    {
        DriveLeftSpeed = (PS4.data.analog.stick.ly);
        DriveRightSpeed = (PS4.data.analog.stick.ry);
    }
           
    LiftSpeed = (PS4.data.analog.button.r2)-(PS4.data.analog.button.l2);
    ClawSpeed = (PS4.data.button.l1-PS4.data.button.r1)*255;

    if(PS4.data.button.circle == 1)
    {
        PrecisonMode = !PrecisonMode;
        LargeRumble = 255; 
    }

    if(PS4.data.button.up)
    {
       Auton.ClearSelection();
       LargeRumble = 100;
    }

    if(PS4.data.button.right == 1)
    {
        Auton.SelectNextAuton();
        LargeRumble = 100;
    }

    if(PS4.data.button.down == 1)
    {
        Auton.ToggleArmed();
        LargeRumble = 100;
    }

    if(PS4.data.button.left == 1)
    {
        Auton.SelectPrevAuton();
        LargeRumble = 100;
    }

    if(PS4.data.button.options)
    {
        State._AutonArmed = !State._AutonArmed;
        LargeRumble = 255;
    }

    if(PS4.data.button.share)
    {
       State._SelectedScript = 1;
       LargeRumble = 255;
    }

    //Only write to the motor contollers every 20 milliseconds
    if(NextMotorTime < millis())
    {   
        //Only set speeds from controller when auton isn't running
        if(!Auton.IsRunning())
        {
            DriveRight.SetSpeed(DriveRightSpeed);
            DriveLeft.SetSpeed(DriveLeftSpeed);
            Lift.SetSpeed(LiftSpeed);
            Claw.SetSpeed(ClawSpeed);
        }
        
        DriveRight.Write();
        DriveLeft.Write();
        Lift.Write();
        Claw.Write();
        NextMotorTime = NextMotorTime + 20;
    }

    //Read the sensors
    State._EnableVal = digitalRead(ReoffPin);
    LeftEncVal = LeftEnc.read();
    RightEncVal = RightEnc.read();

    //Only write to display and PS4 controller Every 250 milliseconds
    if(NextDisplayTime < millis())
    {
        //Write display and PS4 remote

        //PrecisonMode
        if(PrecisonMode)
        {   
            //You can use this fancy function to write to the screen, or one of its overloads
            Brain.DrawString("Precison Mode!");
        }

        //Auton Writing
        if(State._SelectedAutonNum != 0)
        {
            Brain.DrawString(2,"Auton" + State._SelectedAutonNum);
        }

        if(State._AutonArmed)
        {
            Brain.DrawString(2,"Armed" + State._SelectedAutonNum);
        }

        else
        {
            Brain.DrawString(2,"Digital Encabulator!");
            //Or you can call brain.screen directly. Be sure to call clear display and set the cursor
            Brain.Screen.setCursor(32,32);
            Brain.Screen.setTextSize(1);
            Brain.Screen.print(PS4.data.status.battery, DEC);
            Brain.Screen.println(" / 16");
            Brain.Screen.display();
        }

        //Rumble goes from 0 to 255
        PS4.setRumble(SmallRumble, LargeRumble);
        //Standard RGB Led, defaults to blue
        PS4.setLed(0,0,255);
        PS4.sendToController();
        //Change the rumble to zero after we write it
        LargeRumble = 0;
        SmallRumble = 0;
        NextDisplayTime = NextDisplayTime + 250;
    }  
}

