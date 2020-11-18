/*
 * KeysReader.cpp
 *
 *  Created on: 14 нояб. 2020 г.
 *      Author: MSPC
 */

#include "cKeysReader.h"
#ifdef DEBUG_MESSAGES
#include <iostream>
using namespace std;
#endif


cKeysReader::cKeysReader():
		m_IsNextRowSwitched(false),
		m_RowsCounter(0)
{
	for(uint8_t i = 0; i < m_RowsCounterMax; ++i)
	{
		m_pRowsArr[i] = NULL;
		m_KeyCodeArr[i] = 0;
	}
	for(uint8_t i = 0; i < m_ColsCounterMax; ++i)
	{
		m_pColsArr[i] = NULL;
	}
}
// ----------------------------------------------------------------------------
cKeysReader::~cKeysReader() {}
// ----------------------------------------------------------------------------
void cKeysReader::run()
{
	KeysPolling();
	KeysPolling();
}
// ----------------------------------------------------------------------------
bool cKeysReader::SetRowOutput(cDigitalOut *row, uint8_t index)
{
	if(index >= m_RowsCounterMax)
		return false;
	if(row == NULL)
		return false;

	m_pRowsArr[index] = row;

	return true;
}
// ----------------------------------------------------------------------------
bool cKeysReader::SetColInput(cDigitalInput *col, uint8_t index)
{
	if(index >= m_ColsCounterMax)
		return false;
	if(col == NULL)
		return false;

	m_pColsArr[index] = col;

	return true;
}
// ----------------------------------------------------------------------------
uint32_t cKeysReader::PrintKeyMatrix()
{
#ifdef DEBUG_MESSAGES
	cout << "Key Matrix:" << endl;
	for(int i = 0; i < m_RowsCounterMax; ++i)
	{
		std::cout << i << ": 0x" << std::hex << m_KeyCodeArr[i] << std::endl;
	}
#endif
	return 0;// todo функция для теста
}
// ----------------------------------------------------------------------------
// private:
void cKeysReader::KeysPolling()
{
	if(!m_IsNextRowSwitched)
	{
		NextRowSwitch();
		m_IsNextRowSwitched = true;
	}
	else
	{
		NextColRead();
		if(++m_RowsCounter >= m_RowsCounterMax)
			m_RowsCounter = 0;
		m_IsNextRowSwitched = false;
	}
}
// ----------------------------------------------------------------------------
void cKeysReader::NextRowSwitch()
{
	for(int i = 0; i < m_RowsCounterMax; ++i)
	{
		if(m_RowsCounter == i)
			m_pRowsArr[i]->SetOn();
		else
			m_pRowsArr[i]->SetOff();
	}
}
// ----------------------------------------------------------------------------
void cKeysReader::NextColRead()
{
	uint32_t rowCode = 0;
	// читаются все колонки
	for(int i = 0; i < m_ColsCounterMax; ++i)
	{
		m_pColsArr[i]->run(); // используем механизм антидребезга дискретного входа
		if(m_pColsArr[i]->IsOn())
			rowCode |= (uint32_t)(1<<i);
		else
			rowCode &= ~(uint32_t)(1<<i);
	}
	m_KeyCodeArr[m_RowsCounter] = rowCode; // состояние входов опрашиваемого ряда
}
// ----------------------------------------------------------------------------
