#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <Arduino.h>
#include <Arduino.h>

extern long param1,param2,param3;

//========================================================
//=====     Tmc429          ==============================
//========================================================

void Tmc429_Init();
void Tmc429_SetTargetP(int value);
int Tmc429_GetTargetP();
void Tmc429_SetTargetV(int value);
int Tmc429_GetTargetV();
void tmc429_SetVelocityMode();
bool    tmc429_IsConnected();
int     tmc429_GetVersion();
int     tmc429_GetPosition();
void    tmc429_SetMotionProfile(uint32_t vMin, uint32_t vMax, uint32_t accMax);
void    tmc429_SetPosition(int32_t position);
void    tmc429_WriteRegister(uint8_t address, uint32_t value);
int     tmc429_ReadRegister(uint8_t address);
void    Tmc429_StopAll();
//========================================================
//=====     General         ==============================
//========================================================
void Led_Toggle();
void Test1(bool value);
void Test1_Toggle();
void Test2(bool value);
void Test2_Toggle();
void Relay_On();
void Relay_Off();
bool GetRelayState();
bool IsOverVoltageOn();
void SendStatusMessage();
bool IsInMovement();
void SetVelocity(int velocity);
void HandleSafety();
void ParseParams(String params);
void GetSerialMsg();
void HandleCommand(String cmd,long prm1,int prm2,int prm3);
void HandleHopScript();
void HandleHomingScript();
void HandleHomingScript2();
void HandleHomingScriptTest();
void Initialize();

void StopAll();
void SendRportMessage();
void SendHelpMessage();
void ReadVoltage();
void SetGroup(int value);
int  GetGroup();
void AutoScale();
void MoveToXyz(int x,int y,int z);
void MoveX(long value);
void MoveToX(long value);
void SetPositionXyz(long valueX,long valueY,long valueZ);
void RunXyz();
void StopXyz();
void MoveX(long value);
void MoveY(long value);
void MoveZ(long value);
void MoveToXyz(long valueX,long valueY,long valueZ);
void MoveToX(long value);
void MoveToY(long value);
void MoveToZ(long value);
void RunX();
void RunY();
void RunZ();
void MoveTask();
void MoveToXy(long valueX,long valueY);
void HopTask();
void SetVelocity(int value);
bool Is_SensorX_On();
bool Is_SensorY_On();
bool Is_SensorZ_On();
bool Is_Ems_On();


#endif
