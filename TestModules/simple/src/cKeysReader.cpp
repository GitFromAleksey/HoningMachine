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
		m_Rows(0),
		m_Cols(0),
		m_RowsCounter(0)
{
	for(uint8_t i = 0; i < m_RowsCounterMax; ++i)
	{
		m_pRowsArr[i] = nullptr;
	}
	for(uint8_t i = 0; i < m_ColsCounterMax; ++i)
	{
		m_pColsArr[i] = nullptr;
	}
#ifdef DEBUG_MESSAGES
	std::cout << "cKeysReader::m_RowsCounterMax:" << (int)m_RowsCounterMax << std::endl;
	std::cout << "cKeysReader::m_RowsCounterMax:" << (int)m_ColsCounterMax << std::endl;
#endif
}
// ----------------------------------------------------------------------------
cKeysReader::~cKeysReader() {}
// ----------------------------------------------------------------------------
void cKeysReader::run()
{
#ifdef DEBUG_MESSAGES
cout << "cKeysReader::run().m_RowsCounter = " << (int)m_RowsCounter << endl;
#endif
	KeysPolling();
#ifdef DEBUG_MESSAGES
cout << "cKeysReader::run().m_Rows = " << hex << m_Rows << endl;
#endif
	m_RowsCounter = (++m_RowsCounter >= m_RowsCounterMax)?(0):(m_RowsCounter);
}
// ----------------------------------------------------------------------------
bool cKeysReader::SetRowOutput(cDigitalOut *row, uint8_t index)
{
	if(index >= m_RowsCounterMax)
		return false;
	if(row == nullptr)
		return false;

	m_pRowsArr[index] = row;
#ifdef DEBUG_MESSAGES
cout << "cKeysReader::m_pRowsArr[" << (int)index << "] = " << m_pRowsArr[index] << endl;
#endif
	return true;
}
// ----------------------------------------------------------------------------
bool cKeysReader::SetColInput(cDigitalInput *col, uint8_t index)
{
	if(index >= m_ColsCounterMax)
		return false;
	if(col == nullptr)
		return false;

	m_pColsArr[index] = col;
#ifdef DEBUG_MESSAGES
cout << "cKeysReader::m_pColsArr[" << (int)index << "] = " << m_pColsArr[index] << endl;
#endif
	return true;
}
// ----------------------------------------------------------------------------
uint32_t cKeysReader::GetColState()
{
	return m_Cols;
}
// ----------------------------------------------------------------------------
// private:
void cKeysReader::KeysPolling()
{
	if(!m_IsNextRowSwitched)
	{
		NextRowSwitsh();
		m_IsNextRowSwitched = true;
	}
	else
	{
		NextColRead();
		m_IsNextRowSwitched = false;
	}
}
// ----------------------------------------------------------------------------
void cKeysReader::NextRowSwitsh()
{
	m_Rows = 0;

	for(int i = 0; i < m_RowsCounterMax; ++i)
	{
		if(m_RowsCounter == i)
		{
			m_Rows = static_cast<uint32_t>(1<<m_RowsCounter);
			m_pRowsArr[i]->SetOn();
		}
		else
			m_pRowsArr[i]->SetOff();
	}
}

void cKeysReader::NextColRead()
{
	for(int i = 0; i < m_ColsCounterMax; ++i)
	{
		if(m_pColsArr[i]->IsOn())
			m_Cols |= (1<<i);
		else
			m_Cols &= ~(1<<i);
	}
}
// ----------------------------------------------------------------------------
