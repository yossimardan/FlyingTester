#include "Functions.h"
#include "Extern_Variables.cpp"


void HopTask()
{
	switch (hopState)
	{
	case 10:
		SetVelocity(MaxVelocity);
		isHopping = true;
		MoveToZ(HopHeight);
		hopState = 20;
		break;

	case 20:
		if (!IsMoving) hopState = 30;
		break;

	case 30:
		MoveToX(HopX);
		//MoveToY(HopY);
		hopState = 40;
		break;

	case 40:
		if (!IsMoving) hopState = 50;
		break;

	case 50:
		MoveToY(HopY);
		hopState = 60;
		break;

	case 60:
		if (!IsMoving) hopState = 70;
		break;

	case 70:
		MoveToZ(HopZ);
		hopState = 80;
		break;

	case 80:  if (!IsMoving) hopState = 100; break;

	case 100:
		isHopping = false;
		hopState = 00;
		break;

	}
}

void MoveTask()
{

	switch (MoveState)
	{
	case 10:
		MoveToX(targetX);
		MoveState = 20;
		break;

	case 20:
		if (!enableX)
		{
			MoveState = 30;
		}
		break;

	case 30:
		MoveToY(targetY);
		MoveState = 40;
		break;

	case 40:
		if (!enableY)
		{
			MoveState = 00;
		}
		break;
	}
}
