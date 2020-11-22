/*
 * cKeyHandler.h
 *
 *  Created on: 21 нояб. 2020 г.
 *      Author: MSPC
 */

#ifndef KEYREADER_CKEYHANDLER_H_
#define KEYREADER_CKEYHANDLER_H_

//#include <iostream>
#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iProcess.hpp"
#include "../Interfaces/iController.hpp"
#include "cKeyBind.h"

class cKeyHandler : public iProcess
{
	public:
		cKeyHandler(uint32_t *matrix, uint8_t rowsCount, uint8_t colsCount);
		virtual ~cKeyHandler();

		virtual void run();

		void AddKeysArray(cKeyBind *keysBindArray, uint8_t size);
		void SetMode(uint8_t rowNum, uint8_t colNum, bool fixed, bool inverted);
		bool KeyIsFixed(uint8_t rowNum, uint8_t colNum);
		bool KeyIsInverted(uint8_t rowNum, uint8_t colNum);

	private:
		uint8_t m_KeyMatrixRowsCount; // кол-во рядов из cKeysReader
		uint8_t m_KeyMatrixColsCount; // кол-во кнопок из cKeysReader
		uint32_t *m_KeyRowMatrixArray; // указатель на массив состояний дискретных входов в cKeysReader
		uint32_t *m_KeyStateMatrixArray; // массив состояний обработанных кнопок на основе настроек m_KeyModeFixingArray и m_KeyModeInverseArray
		uint32_t *m_KeyStateTriggerArray; // триггер для отслеживания события нажатия
		uint32_t *m_KeyModeInverseArray; // настройка инверсии сигнала кнопки
		cKeyBind *m_KeysBindArray; // массив кнопок
		uint8_t m_KeysBindArraySize; // размер массива кнопок

		void ArrayInit(uint32_t *arr, uint8_t size);
};

#endif /* KEYREADER_CKEYHANDLER_H_ */
