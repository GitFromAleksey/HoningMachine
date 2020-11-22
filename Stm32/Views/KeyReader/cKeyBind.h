/*
 * cKeyBind.h
 *
 *  Created on: 22 нояб. 2020 г.
 *      Author: MSPC
 */

#ifndef KEYREADER_CKEYBIND_H_
#define KEYREADER_CKEYBIND_H_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iProcess.hpp"
#include "../Interfaces/iController.hpp"


class cKeyBind
{
	public:
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

#endif /* KEYREADER_CKEYBIND_H_ */
