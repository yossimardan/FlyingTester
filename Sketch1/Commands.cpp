#include "Functions.h"
#include "Externals.cpp"


void(*resetFunc) (void) = 0;

void HandleCommand(String cmd, long prm1, int prm2, int prm3)
{

	//========================================================
	if (cmd == "fs")
	{
		if (prm1 != Null)
		{
			StopForce=(prm1==1);
		}
	}

	//========================================================
	if (cmd == "?")
	{
		digitalWrite(ENA_X_PIN, !digitalRead(ENA_X_PIN));
		isTerminal = true;
		Serial.print("Help...   \r\n");
		SendHelpMessage();
		return;
	}

	//========================================================
	if (cmd == "mr")
	{
		NVIC_SystemReset();
	}

	//========================================================
	if (cmd == "rp")
	{
		SendRportMessage();
	}
	//========================================================
	if (cmd == "ca")
	{
		if (prm1 != Null)
		{
			CruiseAlt = prm1;
		}
	}

	// SendRportMessage();
 //========================================================
	if (cmd == "ex")
	{
		isTerminal = false;
	}

	//========================================================
	if (cmd == "va")
	{
		Velocity = max(min(prm1 * MaxVelocity / 100, MaxVelocity), 1);

		Vy = prm1;
		if (Vy > MaxVy) Vy = MaxVy;
		Vz = prm1;
		if (Vz > MaxVz) Vz = MaxVz;

		xAxis.setMaxSpeed(Vx);
		yAxis.setMaxSpeed(Vy);
		zAxis.setMaxSpeed(Vz);

		xAxis.setAcceleration(Vx * 100);
		yAxis.setAcceleration(Vy * 100);
		zAxis.setAcceleration(Vz * 100);
	}
	//========================================================
	if (cmd == "vp")
	{
		if (prm1 != Null)  ApproachVelocity = prm1;
		if (isTerminal) Serial.print("va= " + String(ApproachVelocity) + "\r\n");
	}
	//========================================================
	if (cmd == "vc")
	{
		if (prm1 != Null)  CreepVelocity = prm1;
		if (isTerminal) Serial.print("vc= " + String(CreepVelocity) + "\r\n");
	}
	//========================================================
	if (cmd == "sv")
	{
		SetVelocity(param1);
		if (isTerminal) Serial.println("Velocity= " + String(Velocity));
	}

	if (cmd == "mv")
	{
		if (param1 != Null) MaxVelocity = max(min(param1, 1000), 100);
		if (isTerminal) Serial.println("MaxVelocity= " + String(MaxVelocity));
	}
	if (cmd == "nv")
	{
		if (param1 != Null)	AccMinVelocity = max(min(param1, 10000), 100);
		if (isTerminal) Serial.println("AccMinVelocity= " + String(AccMinVelocity));
	}

	if (cmd == "av")
	{
		if (param1 != Null)	StartVelocity = max(min(param1, 1000), 100);
		if (isTerminal) Serial.println("StartVelocity= " + String(StartVelocity));
	}


	//========================================================
	if (cmd == "ax")
	{
		if (prm1 != Null)AccStepX = max(min(100, prm1), 1);
		if (isTerminal) Serial.print("Ax= " + String(AccStepX) + "\r\n");
	}

	//========================================================
	if (cmd == "we")
	{
		SwLimitEnable = true;
	}

	if (cmd == "wd")
	{
		SwLimitEnable = false;
	}

	if (cmd == "wa")
	{
		if (prm1 != Null && prm2 != Null && prm3 != Null)
		{
			SwLimitX = param1;
			SwLimitY = param2;
			SwLimitZ = param3;
		}
		if (isTerminal) Serial.print(
			"X= " + String(SwLimitX) +
			": Y=" + String(SwLimitY) +
			": Z=" + String(SwLimitZ) +
			"\r\n");
	}


	if (cmd == "wx")
	{
		if (prm1 != Null) SwLimitX = prm1;
		if (isTerminal) Serial.print("SwLimitX = " + String(SwLimitX) + "\r\n");
	}

	if (cmd == "wy")
	{
		if (prm1 != Null) SwLimitY = prm1;
		if (isTerminal) Serial.print("SwLimitY = " + String(SwLimitY) + "\r\n");
	}

	if (cmd == "wz")
	{
		if (prm1 != Null) SwLimitZ = prm1;
		if (isTerminal) Serial.print("SwLimitZ = " + String(SwLimitZ) + "\r\n");
	}
	//========================================================
	//   if (cmd=="hh")
	//   {
	//      if (prm1!= Null)
	//      {
	//        hopHeightCircle=prm1;
	//        if (hopHeightCircle<0) hopHeightCircle = 0;
	//      }
	//      if (isTerminal) Serial.print("hopHeightCircle= "+ String(hopHeightCircle) +"\r\n");    
	//   }

	//========================================================
	if (cmd == "hh")
	{
		if (prm1 != Null)
		{
			HopHeight = prm1;
			if (HopHeight < 0) HopHeight = 0;
		}
		if (isTerminal) Serial.print("HopHeight = " + String(HopHeight) + "\r\n");
	}


	//========================================================
	if (cmd == "vy")
	{
		if (prm1 != Null)
		{
			Vy = prm1;
			if (Vy > MaxVy) Vy = MaxVy;
			yAxis.setMaxSpeed(Vy);
		}
		if (isTerminal) Serial.print("Vy= " + String(Vy) + "\r\n");
	}
	//========================================================
	if (cmd == "ay")
	{
		if (prm1 != Null)
		{
			Ay = prm1;
			if (Ay <= 100) Ay = 100;
			yAxis.setAcceleration(Ay);
		}
		if (isTerminal) Serial.print("Ay= " + String(Ay) + "\r\n");
	}
	//========================================================
	if (cmd == "vz")
	{
		if (prm1 != Null)
		{
			Vz = prm1;
			if (Vz > MaxVz) Vz = MaxVz;
			zAxis.setMaxSpeed(Vz);
		}
		if (isTerminal) Serial.print("Vz= " + String(Vz) + "\r\n");
	}
	//========================================================
	if (cmd == "az")
	{
		if (prm1 != Null)
		{
			Az = prm1;
			if (Az <= 100) Az = 100;
			zAxis.setAcceleration(Az);
		}
		if (isTerminal) Serial.print("Az= " + String(Az) + "\r\n");
	}

	//========================================================
	if (cmd == "sp")
	{
		SetPositionXyz(param1, param2, param3);
	}
	//========================================================
	if (cmd == "sw")
	{
		if (prm1 != Null && prm2 != Null && prm3 != Null)
		{
			xAxis.setCurrentPosition(param1);
			yAxis.setCurrentPosition(param2);
			zAxis.setCurrentPosition(param3);
		}
		if (isTerminal) Serial.print(
			"X= " + String(xAxis.currentPosition()) +
			": Y=" + String(yAxis.currentPosition()) +
			": Z=" + String(zAxis.currentPosition()) +
			"\r\n");
	}
	//========================================================
	if (cmd == "sx")
	{
		if (prm1 != Null)xAxis.setCurrentPosition(param1);
		if (isTerminal) Serial.print("X= " + String(xAxis.currentPosition()) + "\r\n");
	}
	//========================================================
	if (cmd == "sy")
	{
		if (prm1 != Null)yAxis.setCurrentPosition(param1);
		if (isTerminal) Serial.print("Y= " + String(yAxis.currentPosition()) + "\r\n");
	}
	//========================================================
	if (cmd == "sz")
	{
		if (prm1 != Null)zAxis.setCurrentPosition(param1);
		if (isTerminal) Serial.print("Z= " + String(zAxis.currentPosition()) + "\r\n");
	}
	//========================================================
	if (cmd == "mp")
	{
		//MoveToXyz(param1,param2,param3);  
		xAxis.moveTo(param1);
		yAxis.moveTo(param2);
		zAxis.moveTo(param3);
	}

	//========================================================
	if (cmd == "hp")
	{
		HopX = param1;
		HopY = param2;
		HopZ = param3;
		HopHeight = param4;
		if (isHopping || hopState != 0)return;
		hopState = 10;
	}
	//========================================================
	if (cmd == "mx") MoveToX(param1);
	if (cmd == "my") MoveToY(param1);
	if (cmd == "mz") MoveToZ(param1);
	if (cmd == "rx") MoveX(param1);
	if (cmd == "ry") MoveY(param1);
	if (cmd == "rz") MoveZ(param1);

	//========================================================
	if (cmd == "rw")
	{
		xAxis.move(param1);
		yAxis.move(param2);
		zAxis.move(param3);
	}
	//========================================================
	if (cmd == "jx")
	{
		SetVelocity(param1);
		if (param1 >= 0) MoveX(100000);
		else if (param1 < 0) MoveX(-100000);
	}
	//========================================================
	if (cmd == "jy")
	{
		SetVelocity(param1);
		if (param1 >= 0) MoveY(100000);
		else if (param1 < 0) MoveY(-100000);
	}
	//========================================================
	if (cmd == "jz")
	{
		SetVelocity(param1);
		if (param1 >= 0) MoveZ(100000);
		else if (param1 < 0) MoveZ(-100000);
	}
	//========================================================
	if (cmd == "ms")
	{
		StopAll();
		//hopState = 0;
		//isHopping = false;
		//homingState = 0;
		//isHoming = false;
		//StopXyz();
	}
	//========================================================
	if (cmd == "se")
	{
		StopAll();
		//xAxis.stop();
		//yAxis.stop();
		//zAxis.stop();
		//hopState = 0;
		//isHopping = false;
		//homingState = 0;
		//isHoming = false;
		//StopXyz();
	}
	//========================================================

	//========================================================
	if (cmd == "fa")Numerator_A = param1;
	if (cmd == "fb")Numerator_B = param1;
	if (cmd == "fc")Numerator_C = param1;
	//========================================================
	if (cmd == "vf")
	{
		VoltageFactor = (float)param1;
	}
	//========================================================
	if (cmd == "gl")
	{
		SetGroup(1);
	}
	if (cmd == "gh")
	{
		SetGroup(2);
	}
	//========================================================
	if (cmd == "gc")
	{
		//digitalWrite(SELECT_2,true);
		//SetGroup(3);    
	}
	//========================================================
	if (cmd == "gt")
	{
		//  digitalWrite(SELECT_2,false);
		//  if (param1==1)   SetGroup(1);    
		//  if (param1==2)   SetGroup(2);    
		//  if (param1==3)   SetGroup(3);    
	}
	//========================================================
	if (cmd == "sa")    digitalWrite(SELECT_0, param1 == 1);
	//if (cmd=="sb")    digitalWrite(SELECT_1,param1 == 1);
	//if (cmd=="sc")    digitalWrite(SELECT_2,param1 == 1);

	//========================================================
	if (cmd == "bd")
	{
		EnableSafety = false;
	}
	//========================================================
	if (cmd == "bx")
	{
		EnableSafety = true;
		xBoundary0 = param1;
		xBoundary1 = param2;
	}
	//========================================================
	if (cmd == "by")
	{
		EnableSafety = true;
		yBoundary0 = param1;
		yBoundary1 = param2;
	}
	//========================================================
	if (cmd == "bz")
	{
		EnableSafety = true;
		zBoundary0 = param1;
		zBoundary1 = param2;
	}
	//========================================================
	if (cmd == "vs")
	{
		velocitySlow = param1;
		accelerationSlow = param1 * 5;
	}
	//========================================================
	if (cmd == "vf")
	{
		velocityFast = param1;
		accelerationFast = param1 * 5;
	}
	//========================================================
	if (cmd == "hm")
	{
		homingState = 10;
		//SetVelocity(velocityFast);
	}
	//========================================================
	if (cmd == "en")
	{
		digitalWrite(ENA_X_PIN, prm1 != 0);
	}
	//========================================================
	if (cmd == "rl")
	{
		digitalWrite(SELECT_0, prm1 != 0);
	}
	//========================================================
	if (cmd == "da")
	{
		analogWrite(DacOut, prm1);
	}
	//========================================================
	if (cmd == "px")  MoveToX(param1);
	if (cmd == "py")  MoveToY(param1);
	if (cmd == "pz")  MoveToZ(param1);

	//========================================================
	if (cmd == "pa")
	{
		MoveToXyz(param1, param2, param3);
	}
	//========================================================
	if (cmd == "pq")
	{
		MoveToXy(param1, param2);
	}
	//========================================================
	if (cmd == "pr")
	{
		//      SetPositionXyz(param1,param2,param3);
		//Serial.print("x= "+ String(param1) + "y= "+ String(param2) + "z= "+ String(param2) +"\r\n");    
	}
	//========================================================
	   //if (cmd=="pb")
	   //{
	   // positionX =0;
	   // targetX =-param1;
	   // Direction =0;
	   // digitalWrite(Dir_Pin_X,true);
	   // enableX=true;
	   //}

	//========================================================
	if (cmd == "tx")
	{
		xAxis.moveTo(param1);
	}
	if (cmd == "ta")
	{
		if (prm1 != Null)xAxis.setAcceleration(param1);
		if (isTerminal) Serial.print("Acc= " + String(param1) + "\r\n");
	}

	if (cmd == "tm")
	{
		if (prm1 != Null)xAxis.setMaxSpeed(param1);
		if (isTerminal) Serial.print("MaxSpeed= " + String(xAxis.maxSpeed()) + "\r\n");
	}
	if (cmd == "ts")
	{
		if (prm1 != Null)xAxis.setSpeed(param1);
		if (isTerminal) Serial.print("Speed= " + String(xAxis.speed()) + "\r\n");
	}
	//========================================================
	if (cmd == "sn")
	{
		int sensors = 0;
		if (Is_SensorX_On()) sensors = sensors + 1;
		if (Is_SensorY_On()) sensors = sensors + 2;
		if (Is_SensorZ_On()) sensors = sensors + 4;
		if (digitalRead(In0)) sensors = sensors + 16;
		if (digitalRead(In1)) sensors = sensors + 32;
		if (!digitalRead(In2)) sensors = sensors + 64;
		if (!digitalRead(In3)) sensors = sensors + 128;
		Serial.print("sensors= " + String(sensors) + "\r\n");

		digitalWrite(SELECT_0, prm1 != 0);
	}
	//========================================================
	Serial.print("\r\n>");
}
