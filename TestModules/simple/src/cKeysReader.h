/*
 * KeysReader.h
 *
 *  Created on: 14 нояб. 2020 г.
 *      Author: MSPC
 */

#ifndef CKEYSREADER_H_
#define CKEYSREADER_H_

#include <stdint.h>
#include "iProcess.hpp"
#include "DigitalOut.hpp"
#include "DigitalInput.hpp"

#define DEBUG_MESSAGES

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

		uint32_t PrintKeyMatrix();

	private:
		bool m_IsNextRowSwitched;
		uint8_t m_RowsCounter;
		const static uint8_t m_RowsCounterMax = 4;
		const static uint8_t m_ColsCounterMax = 4;
		cDigitalOut *m_pRowsArr[m_RowsCounterMax];
		cDigitalInput *m_pColsArr[m_ColsCounterMax];
		uint32_t m_KeyCodeArr[m_RowsCounterMax];

		void NextRowSwitch();
		void NextColRead();
		void KeysPolling();
};

#endif /* CKEYSREADER_H_ */
