#include <AccelStepper.h>
#include <SAMDTimerInterrupt.h>
void Initialize()
{
  pinMode(Pulse_Pin_X, OUTPUT);
  pinMode(Dir_Pin_X, OUTPUT);
  pinMode(Pulse_Pin_Y, OUTPUT);
  pinMode(Dir_Pin_Y, OUTPUT);
  pinMode(Pulse_Pin_Z, OUTPUT);
  pinMode(Dir_Pin_Z, OUTPUT);
  pinMode(ENA_X_PIN, OUTPUT);
  pinMode(SELECT_0, OUTPUT);
  pinMode(TEST1_PIN, OUTPUT);
  pinMode(TEST2_PIN, OUTPUT);
  pinMode(DacOut, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(SENSOR_X_PIN, INPUT_PULLUP);
  pinMode(SENSOR_Y_PIN, INPUT_PULLUP);
  pinMode(SENSOR_Z_PIN, INPUT_PULLUP);
  pinMode(SENSOR_EMS_PIN, INPUT_PULLUP);
  pinMode(OVER, INPUT);
  pinMode(In0, INPUT_PULLUP);
  pinMode(In1, INPUT_PULLUP);
  pinMode(In2, INPUT);
  pinMode(In3, INPUT);
  analogReference(AR_EXTERNAL);
  analogWriteResolution(10);
  analogReadResolution(12);
  
  Serial.begin(38400);
  Serial.setTimeout(10);
  
  xAxis.setPinsInverted(true);
  
  digitalWrite(SELECT_0,false);
  //digitalWrite(SELECT_1,false);
  //digitalWrite(SELECT_2,true);
 
  //xAxis.moveTo(10000);
 // xAxis.setMaxSpeed(Vx);
 // yAxis.setMaxSpeed(Vy);
 // zAxis.setMaxSpeed(Vz);
 // xAxis.setAcceleration(Ax);
 // yAxis.setAcceleration(Ay);
 // zAxis.setAcceleration(Az);
  SetGroup(3);
}
