/*
 * cController.h
 *
 *  Created on: 21 нояб. 2020 г.
 *      Author: MSPC
 */

#ifndef CCONTROLLER_H_
#define CCONTROLLER_H_

#include <iostream>
#include "../../../Stm32/Interfaces/iController.hpp"

using namespace std;

class cController : public iController
{
public:
	cController();
	virtual ~cController();

	virtual void PressKey1();
	virtual void PressKey2();
	virtual void PressKey3();
	virtual void PressKey4();
	virtual void PressKey5();
	virtual void PressKey6();
	virtual void PressKey7();
	virtual void PressKey8();
	virtual void PressKey9();
	virtual void SwitchToggle();

	virtual void MachinePowerOn();
	virtual void MachinePowerOff();
	virtual void VerticalFeedMotorOn();
	virtual void VerticalFeedMotorOff();
	virtual void ToolLiftUp();
	virtual void ToolLiftDown();
	virtual void ToolLiftStop();
	virtual void ToolRotateRun();
	virtual void ToolRotateStop();
	virtual void ToolStop();

	void KeyEventHandler(KeyIdentificator keyIdent);
};

#endif /* CCONTROLLER_H_ */
