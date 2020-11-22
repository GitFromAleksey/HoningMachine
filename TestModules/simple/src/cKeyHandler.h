/*
 * cKeyHandler.h
 *
 *  Created on: 21 нояб. 2020 г.
 *      Author: MSPC
 */

#ifndef CKEYHANDLER_H_
#define CKEYHANDLER_H_

#include <iostream>
#include <stdint.h>
#include <stddef.h>
#include "../../../Stm32/Interfaces/iProcess.hpp"
#include "../../../Stm32/Interfaces/iController.hpp"

class cKeyBind
{
	public:
		std::string name;

		cKeyBind();
		virtual ~cKeyBind();

		void Init(uint8_t row, uint8_t col, KeyIdentificator keyIdent, iController *machineController);
		void CheckKey(uint8_t row, uint8_t col, uint32_t rowWord);

	private:
		// координаты кнопки в матрице
		uint8_t m_Row;
		uint8_t m_Col;
		KeyIdentificator m_KeyIdent;
		iController *m_MachineController; // интерфейс контроллера станка
};

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

#endif /* CKEYHANDLER_H_ */
