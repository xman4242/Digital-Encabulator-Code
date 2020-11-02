#include "AUTONOMOUS.h"
#include "ROBOT.h"

AUTONOMOUS::AUTONOMOUS(ROBOT &refRobot) : Robot(refRobot)
{

}

//Does nothing. 
void AUTONOMOUS::Setup()
{
    
}

//Checks for armed and selected autonomous
void AUTONOMOUS::Loop()
{      
    IsEnabled = State._EnableVal;
    Armed = Robot.State._AutonArmed;
    SelectedAuton = Robot.State._SelectedAutonNum;
    //Serial.println(SelectedAuton);

    if(Armed && IsEnabled)
    {
        if(SelectedAuton == 1) RunAuton1();
        if(SelectedAuton == 2) RunAuton2();
        if(SelectedAuton == 3) RunAuton3();
        if(SelectedAuton == 4) RunAuton4();
        Robot.State._SelectedAutonNum = 0;
        Robot.State._AutonArmed = false;
    }

    //Add additional scripts here
    if(SelectedScript == 1) RunScript1();

    delay(20);
}

//User-defined autonomous 1
void AUTONOMOUS::RunAuton1()
{   
    Serial.println("Auton 1 Running!");
    DriveForMillis(5000, 255, -255);
}

//User-defined autonomous 2
void AUTONOMOUS::RunAuton2()
{
    
}

//User-defined autonomous 3
void AUTONOMOUS::RunAuton3()
{
    
}

//User-defined autonomous 4
void AUTONOMOUS::RunAuton4()
{

}

//Scripts are for mini-driver control autonomous routines. 
//For example, if you press the circle button in a match, raise the lift to a certian height. 

//User-defined script 1
void AUTONOMOUS::RunScript1()
{
    State._ScriptRunning = true;
    State._ScriptRunning = false;
    
}

//This is the place to define autonomous helper funtions. A few sample ones included below. They all work the same way. You set a motor to a speed,
//ranging from -255 to 255, and then delay for a certian time. When the time is up, stop the motor.

void AUTONOMOUS::DriveForMillis(long Time, int LeftSpeed, int RightSpeed)
{   
    State._AutonRunning = true;
    Robot.DriveRight.SetSpeed(RightSpeed);
    Robot.DriveLeft.SetSpeed(LeftSpeed);
    delay(Time);
    Robot.DriveRight.Stop();
    Robot.DriveLeft.Stop();
    State._AutonRunning = false;
}

void AUTONOMOUS::LiftForMillis(long Time, int LiftSpeed)
{   
    State._AutonRunning = true;
    Robot.Lift.SetSpeed(LiftSpeed);
    delay(Time);
    Robot.Lift.Stop();
    State._AutonRunning = false;
}

void AUTONOMOUS::ClawForMillis(long Time, int ClawSpeed)
{
    State._AutonRunning = true;
    Robot.Claw.SetSpeed(ClawSpeed);
    delay(Time);
    Robot.Claw.Stop();
    State._AutonRunning = false;
}


//All of these functions are for the controller to use to select auton and scripts. You shouldn't have to change them. 
void AUTONOMOUS::SelectNextAuton()
{

    if( State._SelectedAutonNum == Robot.NumberofAutons)
    {
         State._SelectedAutonNum = 1;
    }

    else
    {
         State._SelectedAutonNum++;
    }
    

}

void AUTONOMOUS::SelectPrevAuton()
{

    if( State._SelectedAutonNum == 1)
    {
         State._SelectedAutonNum = Robot.NumberofAutons;
    }

    else
    {
         State._SelectedAutonNum--;
    }

}

void AUTONOMOUS::ToggleArmed()
{
     State._AutonArmed =! State._AutonArmed;
}

void AUTONOMOUS::ClearSelection()
{
     State._SelectedAutonNum = 0;
}

int AUTONOMOUS::GetSelectedAuton()
{
    return  State._SelectedAutonNum;
}

bool AUTONOMOUS::GetArmedState()

{
    return  State._AutonArmed;
}

bool AUTONOMOUS::IsRunning()

{   if(State._AutonRunning || State._ScriptRunning)
    {
        return true;
    }
    
    else
    {
        return false;
    }
}

void AUTONOMOUS::RunScript(int Script)
{
    SelectedScript = Script;
}

void AUTONOMOUS::Arm()
{
    State._AutonArmed = true;
}
