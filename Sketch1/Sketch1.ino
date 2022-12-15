#include <AccelStepper.h>
#include <SAMDTimerInterrupt.h>
#include "Functions.h"
#include "Variables.h"
SAMDTimer InterruptTimerX(TIMER_TC3);
//SAMDTimer InterruptTimerY(TIMER_TCC);

int  accTarget;
int  accStart;

int counter = 0;
int intervalCounter = 0;

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

	/* MaxVelocity = 10000;
	 AccMinVelocity = 2000;
	 StartVelocity = 500;
	 CurrentVelocity = 0;
	 DecPoint = MaxVelocity;
	 MoveState = 0;
	 Velocity = 5000;
	 AccStepX = 10;*/

	InterruptTimerX.attachInterruptInterval(50, TimerHandlerX);
}

int Calc_Interval()
{
	CreepVelocity = 2000;
	CurrentVelocity = CurrentVelocity + AccStep * 1;				// Accelerate
	CurrentVelocity = min(CurrentVelocity, Velocity);				//	CurrentVelocity < Velocity
	CurrentVelocity = max(min(CurrentVelocity, MaxVelocity), 0);	//  0 < CurrentVelocity < MaxVelocity
	Interval = StartVelocity - CurrentVelocity;
	if (Velocity < 10) Interval = CreepVelocity;
	//Interval = CreepVelocity;
}

//========================================================
//=====     TimerHandler           =======================
//========================================================
void TimerHandlerX(void)
{
	//1233eqwweewqewqw8798
	Test1(true);
	intervalCounter--;
	if (intervalCounter <= 0) {
		Test2(true);
		intervalCounter = Interval/20;
		Calc_Interval();
		if (enableX) RunX();
		if (enableY) RunY();
		if (enableZ) RunZ();
		IsMoving = (enableX || enableY || enableZ);
		//delayMicroseconds(120);
		//InterruptTimerX.setInterval(Interval, TimerHandlerX);
	}
	Test1(false);
	Test2(false);
}

//========================================================
//=====     Main Loop       ==============================
//========================================================
void loop()
{
	//delay(1);
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
		HandleHomingScript2();
		SendStatusMessage();
		HandleSafety();
	}
}