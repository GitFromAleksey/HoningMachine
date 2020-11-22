/*
 * KeysReader.h
 *
 *  Created on: 14 нояб. 2020 г.
 *      Author: MSPC
 */

#ifndef KEYREADER_CKEYSREADER_H_
#define KEYREADER_CKEYSREADER_H_

#include <stdint.h>
#include "../../../../Stm32/Interfaces/iProcess.hpp"
#include "../../../../Stm32/Interfaces/iController.hpp"
#include "../DigitalOut.hpp"
#include "../DigitalInput.hpp"
#include "cKeyHandler.h"

//#define DEBUG_MESSAGES

// чтение входов происходит в 2 такта.
// первый такт включается ряд, второй - происходит чтение

class cKeysReader : public iProcess
{
	public:
		cKeysReader();
		virtual ~cKeysReader();

		virtual void run();

		bool SetRowOutput(cDigitalOut *row, uint8_t index);
		bool SetColInput(cDigitalInput *col, uint8_t index);
		void AddKeysArray(cKeyBind *keysArray, uint8_t size);

	private:
		bool m_IsNextRowSwitched;
		uint8_t m_RowsCounter;
		const static uint8_t m_RowsCounterMax = 4; // количество рядов кнопок
		const static uint8_t m_ColsCounterMax = 4; // кол-во используемых бит в колонке
		cDigitalOut *m_pRowsArr[m_RowsCounterMax];
		cDigitalInput *m_pColsArr[m_ColsCounterMax];
		uint32_t m_KeyRowMatrix[m_RowsCounterMax];
		cKeyHandler *m_KeyHandler;

		void NextRowSwitch();
		void NextColRead();
		void KeysPolling();
};

#endif /* KEYREADER_CKEYSREADER_H_ */
