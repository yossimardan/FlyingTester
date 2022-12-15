#include "Functions.h"
#include "Externals.cpp"

void  Led_Toggle()
{
	digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}
//============================================================
bool  IsOverVoltageOn()
{
	return !digitalRead(OVER);
}

//============================================================
void  Relay_On()
{
	digitalWrite(SELECT_0, true);
}
void   Relay_Off()
{
	digitalWrite(SELECT_0, false);
}

bool  GetRelayState()
{
	return digitalRead(SELECT_0);
}

//============================================================
bool  Is_SensorX_On()
{
	return !digitalRead(SENSOR_X_PIN);
}
//============================================================
bool  Is_SensorY_On()
{
	return !digitalRead(SENSOR_Y_PIN);
}
//============================================================
bool  Is_SensorZ_On()
{
	return !digitalRead(SENSOR_Z_PIN);
}
//============================================================
bool  Is_Ems_On()
{
	return false; // remove
	return digitalRead(SENSOR_EMS_PIN);
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
	digitalWrite(TEST1_PIN, !value);
}
void Test1_Toggle()
{
	digitalWrite(TEST1_PIN, !digitalRead(TEST1_PIN));
}

//===============================
//=====     Test2         =======
//===============================
void Test2(bool value)
{
	digitalWrite(TEST2_PIN, !value);
}
void Test2_Toggle()
{
	digitalWrite(TEST2_PIN, !digitalRead(TEST2_PIN));
}
