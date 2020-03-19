/*
 * machine.cpp
 *
 *  Created on: 19 ���. 2020 �.
 *      Author: borzenkov
 */
#include "machine.hpp"


cMachine::cMachine():
		m_MachineState(MachineStates::none),
		m_ToolState(MachineStates::none),
		m_CurrentPosition(0),
		m_UpperTipPosition(0),
		m_LowerTipPosition(0),
		m_PositionScale(0)
{

}

cMachine::~cMachine()
{

}
