/*
 * machine.cpp
 *
 *  Created on: 19 ���. 2020 �.
 *      Author: borzenkov
 */
#include "machine.hpp"


cMachine::cMachine():
		m_MachineState(MachineStates::machineNone),
		m_ToolState(ToolStates::toolNone),
		m_CurrentPosition(0),
		m_UpperTipPosition(0),
		m_LowerTipPosition(0),
		m_PositionScale(0)
{
	std::cout << "cMachine::cMachine():" << std::endl;
}

cMachine::~cMachine()
{

}
