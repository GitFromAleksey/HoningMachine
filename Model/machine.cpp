/*
 * machine.cpp
 *
 *  Created on: 19 ���. 2020 �.
 *      Author: borzenkov
 */
#include "../Model/machine.hpp"

// ----------------------------------------------------------------------------
cMachine::cMachine():
		m_MachineState(MachineStates::machineStateNone),
		m_ToolState(ToolStates::toolStateNone),
		m_CurrentPosition(0),
		m_UpperTipPosition(0),
		m_LowerTipPosition(0),
		m_PositionScale(0),
		ErrorCallback(nullptr)
{
	std::cout << "cMachine::cMachine():" << std::endl;
}
// ----------------------------------------------------------------------------
cMachine::~cMachine(){}
// ----------------------------------------------------------------------------
void cMachine::run()
{
	if(m_UpperToolTip.IsOn() || m_LowerToolTip.IsOn())
	{ ToolLiftStop(); }
}
// ----------------------------------------------------------------------------
void cMachine::MachinePowerOn()
{
	m_IO_MachinePowerSwitch.SetOn();
}
// ----------------------------------------------------------------------------
void cMachine::MachinePowerOff()
{
	m_IO_MachinePowerSwitch.SetOff();
}
// ----------------------------------------------------------------------------
void cMachine::ToolLiftUp()
{
	m_ToolLiftDownSwich.SetOff();
	m_ToolLiftUpSwitch.SetOn();
}
// ----------------------------------------------------------------------------
void cMachine::ToolLiftDown()
{
	m_ToolLiftUpSwitch.SetOff();
	m_ToolLiftDownSwich.SetOn();
}
// ----------------------------------------------------------------------------
void cMachine::ToolLiftStop()
{
	m_ToolLiftDownSwich.SetOff();
	m_ToolLiftUpSwitch.SetOff();
}
// ----------------------------------------------------------------------------
void cMachine::ToolRotateRun()
{
	m_RotatedMotorToolSwitch.SetOn();
}
// ----------------------------------------------------------------------------
void cMachine::ToolRotateStop()
{
	m_RotatedMotorToolSwitch.SetOff();
}
// ----------------------------------------------------------------------------
void cMachine::ToolStop()
{
	ToolLiftStop();
	ToolRotateStop();
}
// ----------------------------------------------------------------------------
bool cMachine::ToolIsRotate()
{
	return m_RotatedMotorToolSwitch.IsOn();
}
// ----------------------------------------------------------------------------
bool cMachine::ToolIsLiftUp()
{
	return m_ToolLiftUpSwitch.IsOn();
}
// ----------------------------------------------------------------------------
bool cMachine::ToolIsLiftDown()
{
	return m_ToolLiftDownSwich.IsOn();
}
// ----------------------------------------------------------------------------
bool cMachine::ToolIsStoped()
{
	return (m_ToolLiftDownSwich.IsOn() &&
			m_ToolLiftUpSwitch.IsOn() &&
			m_RotatedMotorToolSwitch.IsOn());
}
// ----------------------------------------------------------------------------
uint32_t cMachine::GetCurrentPosotion()const
{
	return m_CurrentPosition;
}
// ----------------------------------------------------------------------------