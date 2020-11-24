/*
 * cKeyHandler.cpp
 *
 *  Created on: 21 нояб. 2020 г.
 *      Author: MSPC
 */

#include "cKeyHandler.h"

cKeyHandler::cKeyHandler(uint32_t *matrix, uint8_t rowsCount, uint8_t colsCount)
{
	if(matrix == NULL)
		return;

	m_KeyRowMatrixArray = matrix;
	m_KeyMatrixRowsCount = rowsCount;
	m_KeyMatrixColsCount = colsCount;

	m_KeyStateMatrixArray = new uint32_t[rowsCount]; // TODO тут виснет
	ArrayInit(m_KeyStateMatrixArray, rowsCount);
	m_KeyStateTriggerArray = new uint32_t[rowsCount];
	ArrayInit(m_KeyStateTriggerArray, rowsCount);
	m_KeyModeInverseArray = new uint32_t[rowsCount];
	ArrayInit(m_KeyModeInverseArray, rowsCount);
}
// ----------------------------------------------------------------------------
cKeyHandler::~cKeyHandler()
{
  delete [] m_KeyStateMatrixArray;
  delete [] m_KeyStateTriggerArray;
  delete [] m_KeyModeInverseArray;
}
// ----------------------------------------------------------------------------
void cKeyHandler::run()
{
	if(m_KeyRowMatrixArray == NULL)
		return;

	uint32_t bitMask = 0;
	bool bitIsChanged = false;
	// обход массива  с кнопками и определение нажатий
	for(uint8_t rowIndex = 0; rowIndex < m_KeyMatrixRowsCount; ++rowIndex)
	{
		if(m_KeyRowMatrixArray[rowIndex] != m_KeyStateMatrixArray[rowIndex])
		{ // если считанный ряд не равен состоянию кнопок
			for(uint8_t bitIndex = 0; bitIndex < m_KeyMatrixColsCount; ++bitIndex)
			{// ищем несовпадающие биты
				bitMask = (uint32_t)(1<<bitIndex);
				bitIsChanged = ((m_KeyStateMatrixArray[rowIndex] & bitMask) != (m_KeyRowMatrixArray[rowIndex] & bitMask));

				if(bitIsChanged)
				{
					if((m_KeyRowMatrixArray[rowIndex] & bitMask) == bitMask)
					{
//						std::cout << "m_KeysBindArray = " << m_KeyRowMatrixArray[rowIndex] << std::endl;
						m_KeyStateMatrixArray[rowIndex] |= bitMask;
						for(uint8_t i = 0; i < m_KeysBindArraySize; ++i)
						{
//							std::cout << "m_KeysBindArray[" << (int)i << "]" << std::endl;
							m_KeysBindArray[i].CheckKey(rowIndex, bitIndex, m_KeyStateMatrixArray[rowIndex]);
						}
					}
					else
					{
						m_KeyStateMatrixArray[rowIndex] &= ~bitMask;
					}
				}
			}
		}
	}
}
// ----------------------------------------------------------------------------
void cKeyHandler::AddKeysArray(cKeyBind *keysBindArray, uint8_t size)
{
	if(keysBindArray == NULL)
		return;
	m_KeysBindArray = keysBindArray;
	m_KeysBindArraySize = size;
//	std::cout << "cKeyHandler::sizeof(keysBindArray)" << (int)m_KeysBindArraySize << std::endl;
}
// ----------------------------------------------------------------------------
// private:
// ----------------------------------------------------------------------------
void cKeyHandler::ArrayInit(uint32_t *arr, uint8_t size)
{
	for(uint8_t i = 0; i < size; ++i)
	{
		arr[i] = 0;
	}
}
