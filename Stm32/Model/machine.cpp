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
{}
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
  m_MiddlerToolTip = initStruct.MiddleToolTip;
  m_LowerToolTip = initStruct.LowerToolTip;

  m_ToolPositionSensor = initStruct.ToolPositionSensor;
  m_CurrentSensor = initStruct.CurrentSensor;
  
  m_MachinePowerSwitch->SetOff();
  m_VerticalFeedMotorSwitch->SetOff();
  m_RotatedMotorToolSwitch->SetOff();
  m_ToolLiftUpSwitch->SetOff();
  m_ToolLiftDownSwich->SetOff();
}
// ----------------------------------------------------------------------------
void cMachine::run()
{
  if( m_UpperToolTip->IsOn() )
  {
    if(ToolIsLiftUp())
    { ToolLiftStop(); }
  }
  if( m_LowerToolTip->IsOn() )
  {
    if(ToolIsLiftDown())
    { ToolLiftStop(); }
  }
  m_CurrentPosition = m_ToolPositionSensor->GetAverageData();
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
void cMachine::VerticalFeedMotorOn()
{
  m_VerticalFeedMotorSwitch->SetOn();
}
// ----------------------------------------------------------------------------
void cMachine::VerticalFeedMotorOff()
{
  m_VerticalFeedMotorSwitch->SetOff();
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
uint32_t cMachine::GetCurrentPosition()const
{
  return m_CurrentPosition;
}
// ----------------------------------------------------------------------------
uint32_t cMachine::GetCurrent()const
{
  return m_CurrentSensor->GetAverageData();
}
// ----------------------------------------------------------------------------
uint32_t cMachine::GetUpperToolTipState()const
{
  return (m_UpperToolTip->IsOn()) ? (1) : (0);
}
// ----------------------------------------------------------------------------
uint32_t cMachine::GetLowerToolTipState()const
{
  return (m_LowerToolTip->IsOn()) ? (1) : (0);
}
// ----------------------------------------------------------------------------
