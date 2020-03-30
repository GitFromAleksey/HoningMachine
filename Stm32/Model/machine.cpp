/*
 * machine.cpp
 *
 *  Created on: 19 мар. 2020 г.
 *      Author: borzenkov
 */
#include "../Model/machine.hpp"

// ----------------------------------------------------------------------------
cMachine::cMachine():
		m_MachineState(machineStateNone),
		m_ToolState(toolStateNone),
		m_CurrentPosition(0),
		m_UpperTipPosition(0),
		m_LowerTipPosition(0),
		m_PositionScale(0),
		ControllerEventCallback(NULL)
{

}
// ----------------------------------------------------------------------------
cMachine::~cMachine(){}
// ----------------------------------------------------------------------------
void cMachine::Init(t_MachineInitStruct initStruct)
{
	m_MachinePowerSwitch = initStruct.MachinePowerSwitch;
	m_VerticalFeedMotorSwitch = initStruct.VerticalFeedMotorSwitch;
	m_RotatedMotorToolSwitch = initStruct.RotatedMotorToolSwitch;
	m_ToolLiftUpSwitch = initStruct.ToolLiftUpSwitch;
	m_ToolLiftDownSwich = initStruct.ToolLiftDownSwich;

	m_UpperToolTip = initStruct.UpperToolTip;
	m_LowerToolTip = initStruct.LowerToolTip;

	m_ToolPositionSensor = initStruct.ToolPositionSensor;
	m_CurrentSensor = initStruct.CurrentSensor;
}
// ----------------------------------------------------------------------------
void cMachine::run()
{
	if( m_UpperToolTip->IsOn() )
	{ ToolLiftStop(); }
	if( m_LowerToolTip->IsOn() )
	{}
}
// ----------------------------------------------------------------------------
void cMachine::MachinePowerOn()
{
	m_MachinePowerSwitch->SetOn();
}
// ----------------------------------------------------------------------------
void cMachine::MachinePowerOff()
{
	m_MachinePowerSwitch->SetOff();
}
// ----------------------------------------------------------------------------
void cMachine::ToolLiftUp()
{
	m_ToolLiftDownSwich->SetOff();
	m_ToolLiftUpSwitch->SetOn();
}
// ----------------------------------------------------------------------------
void cMachine::ToolLiftDown()
{
	m_ToolLiftUpSwitch->SetOff();
	m_ToolLiftDownSwich->SetOn();
}
// ----------------------------------------------------------------------------
void cMachine::ToolLiftStop()
{
	m_ToolLiftDownSwich->SetOff();
	m_ToolLiftUpSwitch->SetOff();
}
// ----------------------------------------------------------------------------
void cMachine::ToolRotateRun()
{
	m_RotatedMotorToolSwitch->SetOn();
}
// ----------------------------------------------------------------------------
void cMachine::ToolRotateStop()
{
	m_RotatedMotorToolSwitch->SetOff();
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
	return m_RotatedMotorToolSwitch->IsOn();
}
// ----------------------------------------------------------------------------
bool cMachine::ToolIsLiftUp()
{
	return m_ToolLiftUpSwitch->IsOn();
}
// ----------------------------------------------------------------------------
bool cMachine::ToolIsLiftDown()
{
	return m_ToolLiftDownSwich->IsOn();
}
// ----------------------------------------------------------------------------
bool cMachine::ToolIsStoped()
{
	return (m_ToolLiftDownSwich->IsOn() &&
			m_ToolLiftUpSwitch->IsOn() &&
			m_RotatedMotorToolSwitch->IsOn());
}
// ----------------------------------------------------------------------------
uint32_t cMachine::GetCurrentPosotion()const
{
	return m_CurrentPosition;
}
// ----------------------------------------------------------------------------
