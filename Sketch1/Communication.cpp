#include "Externals.cpp"
#include "Functions.h"

int msgCounter = 0;
void HandleCommand(String cmd, long prm1, int prm2, int prm3);


//========================================================
//=====     ParseParams            =======================
//========================================================
void ParseParams(String params)
{
	int index1 = 0;
	int index2 = 0;
	int index3 = 0;
	int index4 = 0;
	param1 = Null;
	param2 = Null;
	param3 = Null;
	param4 = Null;
	String prm = "";
	if (params.length() == 1) return;

	index1 = params.indexOf(",");
	if (index1 == -1) prm = params;
	else  prm = params.substring(0, index1);
	param1 = prm.toInt();

	if (index1 != -1)
	{
		index2 = params.indexOf(",", index1 + 1);
		prm = params.substring(index1 + 1, index2);
		param2 = prm.toInt();
	}
	if (index2 != -1)
	{
		index3 = params.indexOf(",", index2 + 1);
		prm = params.substring(index2 + 1, index3);
		param3 = prm.toInt();
	}
	if (index3 != -1)
	{
		index4 = params.indexOf(",", index3 + 1);
		prm = params.substring(index3 + 1, index4);
		param4 = prm.toInt();
	}
}

//========================================================
//=====     GetSerialMsg           =======================
//========================================================
void GetSerialMsg()
{

	String rxString = Serial.readString();
	RxBuffer = RxBuffer + rxString;

	int index = RxBuffer.indexOf("\n");
	if (index != -1) {
		String commandLine = RxBuffer.substring(0, index);
		RxBuffer = "";

		if (commandLine.substring(0, 1) == "?")
		{
			HandleCommand("?", param1, param2, param3);
			return;
		}
		cmd = commandLine.substring(0, 2);
		String params = commandLine.substring(2);

		ParseParams(params);
		HandleCommand(cmd, param1, param2, param3);
		return;
	}
	return;
	if (index == -1) return;
}
//========================================================
//=====    Report                 ========================
//========================================================
void SendRportMessage()
{
	Serial.print("=======================================================\r\n");
	Serial.print("Position\tx= " + String(positionX) + "\t\tY= " + String(positionY) + "\t\tZ= " + String(positionY) + "\r\n");
	Serial.print("Target\tx= " + String(targetX) + "\t\tY= " + String(targetX) + "\t\tZ= " + String(targetX) + "\r\n");
	Serial.print("AccMinVelocity\t= " + String(AccMinVelocity)+"\r\n");
//	Serial.print("StartVelocity\t= " + String(StartVelocity) + "\r\n");
	Serial.print("CurrentVelocity\t= " + String(CurrentVelocity) + "\r\n");
	Serial.print("Velocity\t= " + String(Velocity) + "\r\n");
	Serial.print("DecPoint\t= " + String(DecPoint) + "\r\n");
	Serial.print("Timer_Interval\t= " + String(Interval) + "\r\n");
	Serial.println("MaxVelocity\t= " + String(MaxVelocity));
	Serial.println("ApproachVelocity= " + String(ApproachVelocity));
	Serial.println("CreepInterval= " + String(CreepInterval));

	Serial.print("EnableSafety= " + String(EnableSafety) + "\r\n");
	Serial.print("xBoundary0= " + String(xBoundary0) + " : " + "xBoundary1= " + String(xBoundary1) + "\r\n");
}
//========================================================
//=====    Send Status Message    ========================
//========================================================
void SendStatusMessage()
{
	if (isTerminal) return;

	Serial.println("<" + String(msgCounter++) +
		":" + String(IsMoving) + String(isHopping) + String(isHoming) + String(isHomeDone) + String(isSafetyError) + String(Is_Ems_On()) + String(SwLimitEnable) +
		":" + String(positionX) +
		":" + String(positionY) +
		":" + String(positionZ) +
		":" + String(voltageF) +
		":" +

		//		":v1 " + String(V001) +
		//		":v2 " + String(V002) +
		//		":v3 " + String(V003) +

		"\tsv:" + String(StartVelocity) +
		"\tcv:" + String(CurrentVelocity) +
		"\tv:" + String(Velocity) +
		"\tmv" + String(MaxVelocity) +
		//		"\tam:" + String(AccMinVelocity) +
				//		":it" + String(Interval) +
		//		"ad" + String(AccDirection) +
		//		"\tcr:" + String(CreepVelocity) +
		"\tit:" + String(Interval) +

		">");
}

//========================================================
//=====      Help                 ========================
//========================================================
void SendHelpMessage()
{
	Serial.println("PcbTester Version 1.20 - Gusti Base"); 
	Serial.println("========================================================");
	Serial.println("mr - Master Reset");
	Serial.println("ex - Exit terminal mode");
	Serial.println("rp - Get report");
	Serial.println("rn - Move Relative");	
	Serial.println("ci - Set Homing Creep_Interval, when velocity = 0.");
	Serial.println("hv - Set Homing Approatch velocity");
	Serial.println("sv - Set velocity.");
	Serial.println("st - Print machine state (Parameters).");
	Serial.println("========================================================");
	Serial.println("?  - Terminal mode - Help Page");
	Serial.println("ex - Exit terminal mode ");
}

