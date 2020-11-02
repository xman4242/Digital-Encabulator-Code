#ifndef STATE_h
#define STATE_h
class STATE
{

private:
    
public:
STATE();
 volatile bool _AutonArmed = false;
 volatile int _SelectedAutonNum = false;
 volatile int _SelectedScript = 0;
 volatile bool _AutonRunning = false;
 volatile bool _ScriptRunning = false;
 volatile bool _EnableVal = false;

};

#if !defined(NO_GLOBAL_INSTANCES)
  extern STATE State;
#endif


#endif