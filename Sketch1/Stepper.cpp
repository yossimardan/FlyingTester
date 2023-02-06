#include "Externals.cpp"
#include "Functions.h"


//=============================================--
//=====       MoveToSetting    ================
//=============================================
void MoveToSetting(long target,long position,int directionPin)
{
	CurrentVelocity = 0;
	AccStep = 1;
	DecPoint = abs(target - position) / 2;
	DecPoint = min(DecPoint, Velocity);
	Direction = (target > position);
	digitalWrite(directionPin, Direction); 
}

////=============================================
////=====       MoveToX          ================
////=============================================
//void MoveToX(long value)
//{
//	AccStep = 1;
//	//CurrentVelocity = 0;
//	targetX = value;
//	DecPoint = abs(targetX - positionX) / 2;
//	DecPoint = min(DecPoint, Velocity);
//	Direction = (targetX > positionX);
//	digitalWrite(Dir_Pin_X, Direction);
//	enableX = true;
//}
////=============================================
////=====       MoveToY          ================
////=============================================
//void MoveToY(long value)
//{
//	AccStep = 1;
//	CurrentVelocity = 0;
//	targetY = value;
//	DecPoint = abs(targetY - positionY) / 2;
//	DecPoint = min(DecPoint, Velocity);
//	Direction = (targetY > positionY);
//	digitalWrite(Dir_Pin_Y, Direction);
//	enableY = true;
//}
////=============================================
////=====       MoveToZ          ================
////=============================================
//void MoveToZ(long value)
//{
//	AccStep = 1;
//	CurrentVelocity = 0;
//	targetZ = value;
//	DecPoint = abs(targetZ - positionZ) / 2;
//	DecPoint = min(DecPoint, Velocity);
//	Direction = (targetZ > positionZ);
//	digitalWrite(Dir_Pin_Z, Direction);
//	enableZ = true;
//
//}

//=============================================
//=====       MoveToX          ================
//=============================================
void MoveToX(long value)
{
	targetX = value;
	enableX = true;
}

//=============================================
//=====       MoveToY          ================
//=============================================
void MoveToY(long value)
{
	targetY = value;
	enableY = true;
}
//=============================================
//=====       MoveToZ          ================
//=============================================
void MoveToZ(long value)
{
	targetZ = value;
	enableZ = true;
}
//=============================================
//=====       MoveX            ================
//=============================================
void MoveX(long value)
{
	MoveToX(positionX + value);
}
//=============================================
//=====       MoveY            ================
//=============================================
void MoveY(long value)
{
	MoveToY(positionY + value);
}

//=============================================
//=====       MoveZ            ================
//=============================================
void MoveZ(long value)
{
	MoveToZ(positionZ + value);
}

//=============================================
//=====       RunX             ================
//=============================================
void RunX()
{
	if (Is_SensorX_On() && !Direction)
	{
		enableX = false;
		return;
	}

	if (SwLimitEnable && (!isHoming) && Direction && positionX > SwLimitX)
	{
		enableX = false;
		return;
	}

	if (SwLimitEnable && (!isHoming) && positionZ < CruiseAlt)
	{
		enableX = false;
		return;
	}

	if (enableX)
	{
		if (positionX != targetX)
		{
		}
		else enableX = false;
	}
}
//=============================================
//=====       RunY             ================
//=============================================
void RunY()
{
	if (Is_SensorY_On() && !Direction)
	{
		enableY = false;
		return;
	}


	if (SwLimitEnable && (!isHoming) && Direction && positionY > SwLimitY)
	{
		enableY = false;
		return;
	}

	if (SwLimitEnable && (!isHoming) && positionZ < CruiseAlt)
	{
		enableY = false;
		return;
	}

	if (enableY)
	{
	}
}
//=============================================
//=====       RunZ             ================
//=============================================
void RunZ()
{
	if (Is_SensorZ_On() && Direction)
	{
		enableZ = false;
		return;
	}
	if (SwLimitEnable && (!isHoming) && (!Direction) && positionZ < SwLimitZ)
	{
		enableZ = false;
		return;
	}

	if (enableZ)
	{
		if (positionZ != targetZ)
		{
		}
		else enableZ = false;
	}
}

//=============================================
//=====       RunXyz           ================
//=============================================
void RunXyz()
{
	RunX();
	RunY();
	RunZ();
}
//=============================================
//=====       SetPosition      ================
//=============================================
void SetPositionXyz(long valueX, long valueY, long valueZ)
{
	positionX = valueX;
	positionY = valueY;
	positionZ = valueZ;
}


//=============================================
//=====       StopX          ================
//=============================================
void StopX()
{
	long stopDist = 250;
	if (Direction) targetX = positionX + stopDist;
	else targetX = positionX - stopDist;
	AccStep = -1;
}

void StopY()
{
	long stopDist = 250;
	if (Direction) targetY = positionY + stopDist;
	else targetY = positionY - stopDist;
	AccStep = -1;
}

void StopZ()
{
	long stopDist = 250;
	if (Direction) targetZ = positionZ + stopDist;
	else targetZ = positionZ - stopDist;
	AccStep = -1;
}


//=============================================
//=====       StopXyz          ================
//=============================================
void StopXyz()
{
	if (enableX) StopX();
	if (enableY) StopY();
	if (enableZ) StopZ();
}
//=============================================
//=====       MoveToXyz        ================
//=============================================
void MoveToXy(long valueX, long valueY)
{

	//accX = 500;
	targetX = valueX;
	targetY = valueY;
	MoveState = 10;
}
//=============================================
//=====       MoveToXyz        ================
//=============================================
void MoveToXyz(long valueX, long valueY, long valueZ)
{
	//accX = 500;
	MoveToX(valueX);
	MoveToY(valueY);
	MoveToZ(valueZ);
}
//=============================================
//=====       MoveXyz          ================
//=============================================
void MoveXyz(long valueX, long valueY, long valueZ)
{
	MoveX(valueX);
	MoveY(valueY);
	MoveZ(valueZ);
}
