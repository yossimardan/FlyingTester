
//========================================================
//=====   GPIO  MAPPING     ==============================
//========================================================

int TEST1 = 16;
int TEST2 = 17;

int TXD1_PIN = 15;
int RXD1_PIN = 4;

//HardwareSerial Com;
//========================================================
//=====   TM429             ==============================
//========================================================
//uint8_t    A002;
int     A001;
int     Target_State;
int     Target;
int     Position;
int     Config;
bool    IsConnected;
int     Vmin = 100;
int     Vmax = 50000;
int     AccMax = 100000;
//============================================================


int startIndex;
int vIndex;

bool StopPending = false;
bool StopForce = false;

bool IsMoving;
long HopHeight;
long HopX;
long HopY;
long HopZ;

bool SwLimitEnable;
long SwLimitX;
long SwLimitY;
long SwLimitZ;


int   MoveState;
long  positionX;
long  targetX;
bool  Direction;
bool  enableX;
//long  AccX;
long  accDistX;
int   AccDirection;

int   MaxVelocity;
int   AccMinVelocity;
int   StartVelocity;

int   CurrentVelocity;
int   DecPoint;
int   Interval;
int   ExInterval;

int   V001;
int   V002;
int   V003;

long positionY;
long targetY;
bool enableY;
long accY;
long  accDistY;
int   AccDirectionY;
int   vY;
int   maxVy;

long positionZ;
long targetZ;
bool enableZ;
long accZ;
int  maxVz;
int  AccStep;


int Numerator_A = 352;
int Numerator_B = 589;
int Numerator_C = 1930;

//int Denominator_A =1
//int Denominator_B =1
//int Denominator_C =1


/*
static Extern  const int SENSOR_X_PIN      = A1;
static const int SENSOR_Y_PIN      = A2;
static const int SENSOR_Z_PIN   = A3;
static const int SENSOR_Z_DOWN_PIN = A4;
 */


float voltageF;
long  voltage;
float VoltageFactor = 975;



int stepsToMilimetersDivider = 200;

//======Velocity============
int velocitySlow = 4000;
int accelerationSlow = 30000;
int velocityFast = 8000;
int accelerationFast = 40000;
int velocityVerySlow = 1000;
int accelerationVerySlow = 2000;


int MaxVx = 120000;
int MaxVy = 20000;
int MaxVz = 20000;
int Null = -1;

int Vx = 10000;
int AccStepX = 1;
int Vy = 10000;
int Ay = 1000000;
int Vz = 10000;
int Az = 1000000;

int Velocity = 100;


/*
int accelerationSlow = 2000;
int accelerationFast =14000;
int velocitySlow = 1000;
int velocityFast = 7000;
*/

//=============================================
//=====    Safety      ========================
//=============================================
bool EnableSafety = false;
int xBoundary0 = -1000;//0 * stepsToMilimetersDivider;
int xBoundary1 = 50000;//255 * stepsToMilimetersDivider;
int yBoundary0 = -1000;//0 * stepsToMilimetersDivider;
int yBoundary1 = 50000;//180 * stepsToMilimetersDivider;
int zBoundary0 = -1000;//0 * stepsToMilimetersDivider;
int zBoundary1 = 50000;//30 *stepsToMilimetersDivider;

int CruiseAlt = 2000;

//=============================================
int zLock2DMovement = 0 * stepsToMilimetersDivider;

int hopHeightCard = 30 * stepsToMilimetersDivider; //40
int hopHeightCircle = 20 * stepsToMilimetersDivider;


//String  RxBuffer = "";
String  cmd = "";
long    param1, param2, param3, param4;
int     currentStatus = 0;
int     hopState = 0;
bool    isHopping = false;
bool    isSafetyError = false;
int     errorId = 0;

int moveForward = 0;
int moveBackward = 0;

bool isTerminal = false;

//=============================================
//=====    Homing      ========================
//=============================================
int   homingState = 0;
bool  homingXFinished = false;
bool  homingYFinished = false;
bool  isHoming = false;
bool  isHomeDone = false;
int   ApproachVelocity;
int   CreepVelocity = 2;
int   CreepInterval;
int   HomingOffsetX;
int   HomingOffsetY;
int   HomingOffsetZ;
int   homingX = 0;
int   homingY = 0;
int   homingZ = 0;
