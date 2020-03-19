/*
 * machine.hpp
 *
 *  Created on: 19 мар. 2020 г.
 *      Author: borzenkov
 */

#ifndef MACHINE_MACHINE_HPP_
#define MACHINE_MACHINE_HPP_

#include <stdint.h>

//namespace Machine
//{

enum MachineStates
{
	machineError,
	machineOk,
	none
};

enum ToolStates
{
	toolNotInitialazed,
	toolInitialazed,
	toolErrorInitialized,
	toolErrorUpperTip,
	toolErrorLowerTip,
	toolErrorPositionSensor,
	none
};

//}

class cMachine
{
public:

	cMachine();
	~cMachine();

	void MachinePowerOn();
	void ToolLiftUp();
	void ToolLiftDown();
	void ToolLiftStop();
	void ToolRotateRun();
	void ToolRotateStop();
	void ToolStop();

	bool ToolIsRotate()const;
	bool ToolIsLiftUp()const;
	bool ToolIsLiftDown()const;
	bool ToolIsStoped()const;

	uint32_t GetCurrentPosotion()const;

	void SetErrorCallback(void (*ErrorCallback)());

private:
	MachineStates m_MachineState;
	ToolStates m_ToolState;
	uint32_t m_CurrentPosition;
	uint32_t m_UpperTipPosition;
	uint32_t m_LowerTipPosition;
	uint32_t m_PositionScale;

	void (*ErrorCallback)();
};


#endif /* MACHINE_MACHINE_HPP_ */
