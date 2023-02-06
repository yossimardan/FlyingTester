#include "Externals.cpp"
#include "Functions.h"

void Initialize()
{
	pinMode(TEST1, OUTPUT);
	pinMode(TEST2, OUTPUT);


	//pinMode(Pulse_Pin_X, OUTPUT);
	//pinMode(Dir_Pin_X, OUTPUT);
	//pinMode(Pulse_Pin_Y, OUTPUT);
	//pinMode(Dir_Pin_Y, OUTPUT);
	//pinMode(Pulse_Pin_Z, OUTPUT);
	//pinMode(Dir_Pin_Z, OUTPUT);
	//pinMode(ENA_X_PIN, OUTPUT);
	//pinMode(SELECT_0, OUTPUT);
	//pinMode(TEST1_PIN, OUTPUT);
	//pinMode(TEST2_PIN, OUTPUT);
	//pinMode(DacOut, OUTPUT);
	//pinMode(LED_BUILTIN, OUTPUT);

	//pinMode(SENSOR_X_PIN, INPUT_PULLUP);
	//pinMode(SENSOR_Y_PIN, INPUT_PULLUP);
	//pinMode(SENSOR_Z_PIN, INPUT_PULLUP);
	//pinMode(SENSOR_EMS_PIN, INPUT_PULLUP);
	//pinMode(OVER, INPUT);
	//pinMode(In0, INPUT_PULLUP);
	//pinMode(In1, INPUT_PULLUP);
	//pinMode(In2, INPUT);
	//pinMode(In3, INPUT);
	//analogReadResolution(12);

	Serial.begin(115200);
	Serial.setTimeout(10);
	//digitalWrite(SELECT_0, false);

	//CreepInterval = 800;
	//ApproachVelocity = 50;
	//HomingOffsetX = 100;
	//HomingOffsetY = 100;
	//HomingOffsetZ = 100;

	//SetGroup(3);
}
