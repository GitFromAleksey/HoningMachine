/*
 * machine.hpp
 *
 *  Created on: 19 мар. 2020 г.
 *      Author: borzenkov
 */

#ifndef MODEL_MACHINE_HPP_
#define MODEL_MACHINE_HPP_

#include <stdint.h>
#include <stddef.h>
//#include <iostream>

#include "../Drivers/AnalogInput.hpp"
#include "../Drivers/DigitalInput.hpp"
#include "../Drivers/DigitalOut.hpp"
#include "../Interfaces/iProcess.hpp"

//namespace Machine
//{
enum MacineEvent
{
	evUpperTipReached,
	evLowerTipReached,
	evAnyError
};

enum MachineStates
{
	machineError,
	machineOk,
	machineStateNone
};

enum ToolStates
{
	toolNotInitialazed,
	toolInitialazed,
	toolErrorInitialized,
	toolErrorUpperTip,
	toolErrorLowerTip,
	toolErrorPositionSensor,
	toolStateNone
};

//}

class cMachine : public iProcess
{
public:

	cMachine();
	~cMachine();

	virtual void run();

	void MachinePowerOn();
	void MachinePowerOff();
	void ToolLiftUp();
	void ToolLiftDown();
	void ToolLiftStop();
	void ToolRotateRun();
	void ToolRotateStop();
	void ToolStop();

	bool ToolIsRotate();
	bool ToolIsLiftUp();
	bool ToolIsLiftDown();
	bool ToolIsStoped();

	uint32_t GetCurrentPosotion()const;

	void SetErrorCallback(void (*ControllerEventCallback)(MacineEvent event));

	void SetPositionSensor(cAnalogInput *posSens);
	void SetCurrentSensor(cAnalogInput *curSens);

private:
	MachineStates m_MachineState;
	ToolStates m_ToolState;
	uint32_t m_CurrentPosition;
	uint32_t m_UpperTipPosition;
	uint32_t m_LowerTipPosition;
	uint32_t m_PositionScale;

	cDigitalOut m_IO_MachinePowerSwitch;
	cDigitalOut m_VerticalFeedMotorSwitch;
	cDigitalOut m_RotatedMotorToolSwitch;
	cDigitalOut m_ToolLiftUpSwitch;
	cDigitalOut m_ToolLiftDownSwich;

	cDigitalInput m_UpperToolTip;
	cDigitalInput m_LowerToolTip;

	cAnalogInput *m_ToolPositionSensor;
	cAnalogInput *m_CurrentSensor;

	void (*ControllerEventCallback)(MacineEvent event);
};

#endif /* MODEL_MACHINE_HPP_ */
