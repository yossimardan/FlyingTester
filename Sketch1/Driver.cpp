#include "Functions.h"
#include "Externals.cpp"

void  Led_Toggle()
{
	//	digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}
//============================================================
bool  IsOverVoltageOn()
{
}

//============================================================
void  Relay_On()
{
}
void   Relay_Off()
{
}

bool  GetRelayState()
{
}

//============================================================
bool  Is_SensorX_On()
{
}
//============================================================
bool  Is_SensorY_On()
{
}
//============================================================
bool  Is_SensorZ_On()
{
}
//============================================================
bool  Is_Ems_On()
{
}
//============================================================
void SetVelocity(int value)
{
	if (value != Null)
	{
		value = (value * MaxVelocity) / 100;
		Velocity = max(min(abs(value), MaxVelocity), 0);
	}
}
//===============================
//=====     Test1         =======
//===============================
void Test1(bool value)
{
	digitalWrite(TEST1, value);
}
void Test1_Toggle()
{
	digitalWrite(TEST1, !digitalRead(TEST1));
}

//===============================
//=====     Test2         =======
//===============================
void Test2(bool value)
{
	digitalWrite(TEST2, value);
}
void Test2_Toggle()
{
	digitalWrite(TEST2, !digitalRead(TEST2));
}
