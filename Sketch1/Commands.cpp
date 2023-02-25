#include "Functions.h"
#include "Externals.cpp"

  
void(*resetFunc) (void) = 0;

void HandleCommand(String cmd, long prm1, int prm2, int prm3)
{
	//========================================================
	if (cmd == "?")
	{
		isTerminal = true;
		Serial.print("Help...   \r\n");
		SendHelpMessage();
		return;
	}

    if (cmd == "q")
    {
        Test1_Toggle();
        isTerminal = false;
    }

	//========================================================
	if (cmd == "rp")
	{
		SendRportMessage();
	}

    if (cmd == "va")
    {
        Vmin = param1;
        tmc429_SetMotionProfile(Vmin,Vmax,AccMax);
    }

    if (cmd == "vb")
    {
        Vmax = param1*1000;
        tmc429_SetMotionProfile(Vmin, Vmax, AccMax);
    }

    if (cmd == "vc")
    {
        AccMax = param1*1000;
        tmc429_SetMotionProfile(Vmin, Vmax, AccMax);
    }

    if (cmd == "sp")
    {
//        tmc429_SetVelocityMode();
//        Tmc429_SetTargetV(0);
        tmc429_SetPosition(param1);
    }
    if (cmd == "xx")
    {
        tmc429_SetPosition(param1*1000);
    }

    if (cmd == "ma")
    {
        tmc429_SetPositionMode();
        Tmc429_SetTargetP(param1*1000);
    }
    if (cmd == "sv")
    {
        Tmc429_SetTargetV(param1*1000);
    }
    if (cmd == "st")
    {
        Tmc429_StopAll();
    }

    if (cmd == "vm")
    {
        tmc429_SetVelocityMode();
    }

    if (cmd == "pm")
    {
        tmc429_SetPositionMode();
    }
    if (cmd == "in")
    {
        Tmc429_Init();
    }




    //========================================================
	Serial.print("\r\n>");
}
