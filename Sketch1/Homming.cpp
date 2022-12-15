#include "Functions.h"
#include "Externals.cpp"

void HandleHomingScript2()
{
  switch(homingState)
  {
//==============================================================
//========================    Z HOMING     =====================
//==============================================================
      case 10: // Z HOMING START
        EnableSafety = false;
        isHoming = true;
        isHomeDone = false;
        SendStatusMessage();
        
        if(!Is_SensorZ_On())
        {
          SetVelocity(ApproachVelocity);
          MoveZ(1000000);
          homingState = 20;
        }
        else homingState = 30;
        break;

      case 20:
        if(!IsMoving) homingState = 30;
        break;

      case 30:
            SetVelocity(CreepVelocity);   
            MoveZ(-10000);
            homingState = 40;
        break;

      case 40:
        if(!Is_SensorZ_On())
        {
            homingZ = positionZ;
            StopXyz();
            homingState = 45;
        }
        break;

      case 45:
        if(!IsMoving) homingState = 50;
        break;

//==============================================================
//========================    X HOMING     =====================
//==============================================================
      case 50:
        if(!Is_SensorX_On())
        {
          SetVelocity(ApproachVelocity);
          MoveX(-1000000);
          homingState = 60;
        }
        else homingState = 70;
        break;

      case 60:
        if(!IsMoving) homingState = 70;
        break;

      case 70:
            SetVelocity(CreepVelocity);   
            MoveX(10000);
            homingState = 80;
        break;

      case 80:
        if(!Is_SensorX_On())
        {
            homingX = positionX;
            StopXyz();
            homingState = 85;
        }
        break;

      case 85:
        if(!IsMoving) homingState = 90;
        break;

//==============================================================
//========================    Y HOMING     =====================
//==============================================================
      case 90:
        if(!Is_SensorY_On())
        {
          SetVelocity(ApproachVelocity);
          MoveY(-1000000);
          homingState = 100;
        }
        else homingState = 110;
        break;

      case 100:
        if(!IsMoving) homingState = 110;
        break;

      case 110:
            SetVelocity(CreepVelocity);   
            MoveY(10000);
            homingState = 120;
        break;

      case 120:
        if(!Is_SensorY_On())
        {
            homingY = positionY;
            StopXyz();
            homingState = 130;
        }
        break;

      case 130:
        if(!IsMoving) homingState = 200;
        break;

    case 200:
        isSafetyError = false;
        EnableSafety = true;
        isHoming = false;
        isHomeDone = true;
        homingState = 0;
        SendStatusMessage();
        SetVelocity(100);
        SetPositionXyz(0,0,0);
        break;
  }
}
