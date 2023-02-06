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
	//========================================================
	if (cmd == "mt")
	{
        Target = param1;
    }

	//========================================================
	if (cmd == "st")
	{
		SendRportMessage();
	}
	//========================================================
	Serial.print("\r\n>");
}
