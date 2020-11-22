/*
 * cKeyBind.cpp
 *
 *  Created on: 22 нояб. 2020 г.
 *      Author: MSPC
 */

#include "cKeyBind.h"

//class cKeyBind
// ----------------------------------------------------------------------------
// public:
// ----------------------------------------------------------------------------
cKeyBind::cKeyBind():
m_Row(0),
m_Col(0),
m_MachineController(NULL)
{}
// ----------------------------------------------------------------------------
cKeyBind::~cKeyBind(){}
// ----------------------------------------------------------------------------
void cKeyBind::Init(uint8_t row, uint8_t col, KeyIdentificator keyIdent,
		iController *machineController)
{
	m_Col = col;
	m_Row = row;
	m_KeyIdent = keyIdent;
	m_MachineController = machineController;
}
// ----------------------------------------------------------------------------
void cKeyBind::CheckKey(uint8_t row, uint8_t col, uint32_t rowWord)
{
	bool bitMask = ((1<<m_Col) == (1<<col));

	if(row == m_Row)
	{
		if(bitMask)
		{
			m_MachineController->KeyEventHandler(m_KeyIdent);
		}
	}
}
// ----------------------------------------------------------------------------
