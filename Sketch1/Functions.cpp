#include "Functions.h"
#include "Externals.cpp"

long voltBuffer[1024];
int avgSamples = 256;


//===============================
//=====     StopAll		  =======
//===============================
void StopAll()
{
	xAxis.stop();
	yAxis.stop();
	zAxis.stop();
	hopState = 0;
	isHopping = false;
	homingState = 0;
	isHoming = false;
	StopXyz();
}


//===============================
//=====     Min Max       =======
//===============================


//===============================
//=====     ReadVoltage   =======
//===============================
void ReadVoltage()
{
	// VoltageFactor= 20.0;
	long sum = 0;
	long v = analogRead(ANALOG_IN_PIN);
	vIndex = (vIndex + 1) % avgSamples;
	voltBuffer[vIndex] = v;
	for (int i = 0; i < avgSamples; i++) sum += voltBuffer[i];
	voltageF = (float)sum / avgSamples * VoltageFactor / 1000000;
}

//===============================
//=====     MoveToXyz     =======
//===============================
void MoveToXyz(int x, int y, int z)
{
	//  double alpha=0;
	//  int dx= abs(x-(xAxis.currentPosition()));
	//  int dy= abs(y-(yAxis.currentPosition()));
	//  
	//  if (dy==0) alpha = PI/2;
	//  else alpha =abs(atan((double)(dy/dx)));
	//
	//  double vx= Velocity * cos(alpha);
	//  double vy= Velocity * sin(alpha);
	//  xAxis.setSpeed(vx);
	//  yAxis.setSpeed(vy);
	//  xAxis.moveTo(x);
	//  yAxis.moveTo(y);
	//
	//   Serial.print("alpha= "+ String(alpha)+" : " + 
	//                "vx= "+ String(vx)+" : "+
	//                "vy= "+ String(vy)+" : "+
	//                "\r\n");    
}



//===============================
//=====     AutoScale     =======
//===============================
void AutoScale()
{
	int  g = GetGroup();
	if (IsOverVoltageOn())
	{
		SetGroup(2);
		return;
	}

	switch (g)
	{
	case 1:
		if (voltageF > 3) SetGroup(2);
		break;
	case 2:
		if (voltageF < 2.5)  SetGroup(1);
		break;
	}

}


//===============================
//=====     SetGroup      =======
//===============================
void SetGroup(int value)
{
	if (value == 1)
	{
		Relay_On();
		VoltageFactor = 975;
	}
	if (value == 2)
	{
		Relay_Off();
		VoltageFactor = 4882;
	}
}
//===============================
//=====     GetGroup      =======
//===============================
int GetGroup()
{
	if (GetRelayState()) return 1;
	else return 2;
}


bool IsInMovement()
{
	return xAxis.isRunning() || yAxis.isRunning() || zAxis.isRunning();
}


//===============================
//=====     HandleSafety  =======
//===============================
void HandleSafety()
{
	if (Is_Ems_On())
	{
		StopAll();
		isHomeDone = false;

	}

	if (!SwLimitEnable) return;

	if (positionX >= SwLimitX || positionY >= SwLimitY || positionZ <= SwLimitZ || positionZ <= CruiseAlt)
	{
		isSafetyError = true;
		errorId = 101;
	}
	else
	{
		isSafetyError = false;
		errorId = 0;
	}
	//
	//  
	//  if(!EnableSafety) return;
	//  if  ( xAxis.currentPosition() >= xBoundary1  ||
	//      xAxis.currentPosition() <= xBoundary0  ||
	//      yAxis.currentPosition() >= yBoundary1  ||
	//      yAxis.currentPosition() <= yBoundary0  ||
	//      zAxis.currentPosition() >= zBoundary1  ||
	//      zAxis.currentPosition() <= zBoundary0
	//      )
	//      {
	//        xAxis.stop();
	//        yAxis.stop();
	//        zAxis.stop();
	//        isSafetyError = true;
	//        errorId = 101;
	//       }
	//       else
	//       {
	//          isSafetyError = false;
	//          errorId = 0;
	//       }
	//
}
