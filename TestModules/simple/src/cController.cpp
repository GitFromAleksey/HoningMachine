/*
 * cController.cpp
 *
 *  Created on: 21 нояб. 2020 г.
 *      Author: MSPC
 */

#include "cController.h"

cController::cController()
{

}

cController::~cController()
{

}

void cController::PressKey1(){cout << "cController::PressKey1()" << endl;}
void cController::PressKey2(){cout << "cController::PressKey2()" << endl;}
void cController::PressKey3(){cout << "cController::PressKey3()" << endl;}
void cController::PressKey4(){cout << "cController::PressKey4()" << endl;}
void cController::PressKey5(){cout << "cController::PressKey5()" << endl;}
void cController::PressKey6(){cout << "cController::PressKey6()" << endl;}
void cController::PressKey7(){cout << "cController::PressKey7()" << endl;}
void cController::PressKey8(){cout << "cController::PressKey8()" << endl;}
void cController::PressKey9(){cout << "cController::PressKey9()" << endl;}
void cController::SwitchToggle(){cout << "cController::SwitchToggle()" << endl;}

void cController::MachinePowerOn()		{cout << "cController::MachinePowerOn()" << endl;}
void cController::MachinePowerOff()		{cout << "cController::MachinePowerOff()" << endl;}
void cController::VerticalFeedMotorOn()	{cout << "cController::VerticalFeedMotorOn()" << endl;}
void cController::VerticalFeedMotorOff(){cout << "cController::VerticalFeedMotorOff()" << endl;}
void cController::ToolLiftUp()			{cout << "cController::ToolLiftUp()" << endl;}
void cController::ToolLiftDown()		{cout << "cController::ToolLiftDown()" << endl;}
void cController::ToolLiftStop()		{cout << "cController::ToolLiftStop()" << endl;}
void cController::ToolRotateRun()		{cout << "cController::ToolRotateRun()" << endl;}
void cController::ToolRotateStop()		{cout << "cController::ToolRotateStop()" << endl;}
void cController::ToolStop()			{cout << "cController::ToolStop()" << endl;}

void cController::KeyEventHandler(KeyIdentificator keyIdent)
{
  switch(keyIdent)
  {
    case pressKey1:
      PressKey1();
      break;
    case pressKey2:
      PressKey2();
      break;
    case pressKey3:
      PressKey3();
      break;
    case pressKey4:
      PressKey4();
      break;
    case pressKey5:
      PressKey5();
      break;
    case pressKey6:
      PressKey6();
      break;
    case pressKey7:
      PressKey7();
      break;
    case pressKey8:
      PressKey8();
      break;
    case pressKey9:
      PressKey9();
      break;
    case machinePowerOn:
      MachinePowerOn();
      break;
    case machinePowerOff:
      MachinePowerOff();
      break;
    case verticalFeedMotorOn:
      VerticalFeedMotorOn();
      break;
    case verticalFeedMotorOff:
      VerticalFeedMotorOff();
      break;
    case toolLiftUp:
      ToolLiftUp();
      break;
    case toolLiftDown:
      ToolLiftDown();
      break;
    case toolLiftStop:
      ToolLiftStop();
      break;
    case toolRotateRun:
      ToolRotateRun();
      break;
    case toolRotateStop:
      ToolRotateStop();
      break;
    case toolStop:
      ToolStop();
      break;
    default:
      break;
  }
}
