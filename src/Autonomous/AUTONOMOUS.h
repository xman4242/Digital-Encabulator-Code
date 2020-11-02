#pragma once

class ROBOT;

class AUTONOMOUS
{
private:
    ROBOT &Robot;
    //Private Vars

    void RunAuton1();
    void RunAuton2();
    void RunAuton3();
    void RunAuton4();
    void RunScript1();
    
    //The value coming from the ReoffPin
    bool IsEnabled = false;
    int SelectedScript = 0;
    volatile bool Armed = false;
    volatile int SelectedAuton = 0;

    //Autonomous helper functions
    void DriveForMillis(long Time, int LeftSpeed, int RightSpeed);
    void LiftForMillis(long Time, int LiftSpeed);
    void ClawForMillis(long Time, int ClawSpeed);

public:
    AUTONOMOUS(ROBOT &refRobot);
    //Public vars and functions
    void Setup();
    void Loop();
    void SelectNextAuton();
    void SelectPrevAuton();
    void ToggleArmed();
    void Arm();
    void ClearSelection();
    int GetSelectedAuton();
    bool GetArmedState();
    bool IsRunning();
    void RunScript(int Script);
    
};
