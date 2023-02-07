#include "Functions.h"
#include "Variables.h"

#include <Arduino.h>
#include <SPI.h>
#include <Streaming.h>
#include <TMC429.h>
//
const long BAUD = 115200;
const int LOOP_DELAY = 20;
int counter = 0;

void setup()
{
	Initialize();
    Tmc429_Init();
	isTerminal = false;

    // Setup serial communications
    Serial.begin(BAUD);
}

//========================================================
//=====     Main Loop       ==============================
//========================================================
void loop()
{
	delay(10);
	counter++;
	Test1_Toggle();
	
	if (counter > 10)
	{
//		counter = 0;
		GetSerialMsg();
		SendStatusMessage();

        delay(100);

        uint32_t chipId = 0;
        for (int i = 0; i < 17; i = i + 8) {
            chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
        }

        Target_State = Tmc429_GetTargetP();
        IsConnected = tmc429_IsConnected();
        Target_State = tmc429_GetVersion();
        Position = tmc429_GetPosition();

        //tmc429_SetVelocityMode();
        //Tmc429_SetTarget(Target);
//        Serial.println(String(counter) +": target_position: " + String(Target_State));
//        Serial.println("Motor clk freq:" + String(ledcReadFreq(0)));
//        Serial.println("communicating\t= " + String(communicating));
//        Serial.println("RxBuffer\t= " + String(DebugCounter++));
        delay(LOOP_DELAY);

	}
}