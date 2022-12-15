//
//extern long param1,param2,param3;
#include <AccelStepper.h>

extern float voltageF;
extern float VoltageFactor;
extern int vIndex;
extern int startIndex;
extern bool StopPending;

extern bool StopForce ;

extern int   AccStep;

extern bool IsMoving;
extern long HopHeight;
extern long HopX;
extern long HopY;
extern long HopZ;

extern bool SwLimitEnable;
extern long SwLimitX;
extern long SwLimitY;
extern long SwLimitZ;
extern int   V001;
extern int   V002;
extern int   V003;

extern int  DecPoint;
extern int  Velocity;
extern int  CreepVelocity;
extern int 	StartVelocity;
extern long   positionX;
extern long   targetX;
extern bool   Direction;
extern bool   enableX;
extern int   AccStepX;
extern long   accDistX;
extern int    AccDirection;
extern int    CurrentVelocity;
extern int    Interval;
extern int    ExInterval;

extern  int    MaxVelocity;
extern int     AccMinVelocity;
extern long   positionY;
extern long   targetY;
extern bool   enableY;
extern long   accY;
extern long   accDistY;
extern int    AccDirectionY;
extern int    vY;
extern int    maxVy;


extern int   MoveState;
extern bool   Direction;


extern long positionZ;
extern long targetZ;
extern bool enableZ;
extern long accZ;
extern int    maxVz;



extern int In2;
extern int In3;
extern int DacOut;
extern int TEST1_PIN;
extern int TEST2_PIN;
extern int Pulse_Pin_X;
extern int Dir_Pin_X;
extern int Pulse_Pin_Y;
extern int Dir_Pin_Y;
extern int Pulse_Pin_Z;
extern int Dir_Pin_Z;
extern int ENA_X_PIN;
extern int ENA_Y_PIN;
extern int OVER;
extern int SELECT_0;
extern  int SENSOR_X_PIN;
extern  int SENSOR_Y_PIN;
extern  int SENSOR_Z_PIN;
extern  int SENSOR_EMS_PIN;
extern  int In0;
extern  int In1;

extern int ApproachVelocity;
extern int CreepVelocity;

extern int Numerator_A;
extern int Numerator_B;
extern int Numerator_C;

extern long voltage;

extern  int ANALOG_IN_PIN;

//extern AccelStepper xAxis(1, Pulse_Pin_X, Dir_Pin_X);
extern AccelStepper xAxis;
extern AccelStepper yAxis;
extern AccelStepper zAxis;

extern int stepsToMilimetersDivider;

//======Velocity============
extern int velocitySlow;
extern int accelerationSlow;
extern int velocityFast;
extern int accelerationFast;
extern int velocityVerySlow;
extern int accelerationVerySlow;

extern  int MaxVx;
extern  int MaxVy;
extern  int MaxVz;
extern  int Null;

extern int Vx;
extern int Ax;
extern int Vy;
extern int Ay;
extern int Vz;
extern int Az;

extern int Velocity;


/*
int accelerationSlow = 2000;
int accelerationFast =14000;
int velocitySlow = 1000;
int velocityFast = 7000;
*/

//=======Safety==========
extern bool EnableSafety;
extern int xBoundary0;
extern int xBoundary1;
extern int yBoundary0;
extern int yBoundary1;
extern int zBoundary0;
extern int zBoundary1;
extern int zLock2DMovement;
extern int CruiseAlt;

extern int hopHeightCard;
extern int hopHeightCircle;


extern String RxBuffer;
extern String cmd;
extern long param1, param2, param3, param4;
extern int currentStatus;
extern int hopState;
extern bool isHopping;
extern bool isHomeDone;
extern int moveForward;
extern int moveBackward;

extern bool isTerminal;
extern bool    isSafetyError;
extern int     errorId;

extern int homingState;
extern bool isHoming;
extern bool homingXFinished;
extern bool homingYFinished;

//=============================================
//=====    Homing      ========================
//=============================================
extern int   HomingOffsetX;
extern int   HomingOffsetY;
extern int   HomingOffsetZ;
extern int   homingX;
extern int   homingY;
extern int   homingZ;
