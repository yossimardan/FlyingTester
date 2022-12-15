#include <AccelStepper.h>
#include <SAMDTimerInterrupt.h>
#include "Functions.h"
#include "Variables.h"
SAMDTimer InterruptTimerX(TIMER_TC3);
//SAMDTimer InterruptTimerY(TIMER_TCC);

int  accTarget;
int  accStart;
int  StartVelocity;
byte counter = 0;

void setup()
{
    Initialize();
    MaxVelocity = 500;
    StartVelocity = 600;
    CurrentVelocity = 600;
    DecPoint = MaxVelocity;
    MoveState = 0;
    Velocity = 400;
    SetGroup(2);
    InterruptTimerX.attachInterruptInterval(1000, TimerHandlerX);
    //InterruptTimerY.attachInterruptInterval(1000, TimerHandlerY);
}

//========================================================
//=====     TimerHandler           =======================
//========================================================
void TimerHandlerX(void)
{

    Test2(true);
    CurrentVelocity = CurrentVelocity + AccStep * 1;
    CurrentVelocity = min(CurrentVelocity, Velocity);
    int interval = StartVelocity - CurrentVelocity;
    if (Velocity < 1) interval = CreepVelocity;
    CurrentVelocity = CurrentVelocity + AccStep * 1;
    CurrentVelocity = max(min(CurrentVelocity, MaxVelocity), 0);
    //CurrentVelocity = MaxVelocity;
    if (enableX) RunX();
    if (enableY) RunY();
    if (enableZ) RunZ();
    IsMoving = (enableX || enableY || enableZ);
    Test2(false);
    Test1(true);
    InterruptTimerX.setInterval(interval, TimerHandlerX);
    Test1(false);
}

//========================================================
//=====     Main Loop       ==============================
//========================================================
void loop()
{
    ReadVoltage();
    counter++;
    Led_Toggle();

    if (counter > 50)
    {
        counter = 0;
        MoveTask();
        HopTask();
        GetSerialMsg();
        AutoScale();
        HandleHopScript();
        HandleHomingScript2();
        SendStatusMessage();
        HandleSafety();
    }
}