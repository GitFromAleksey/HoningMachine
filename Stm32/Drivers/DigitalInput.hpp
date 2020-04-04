#ifndef DRIVERS_DIGITALINPUT_HPP_
#define DRIVERS_DIGITALINPUT_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iProcess.hpp"
//#include <iostream>


class cDigitalInput : public iProcess
{
public:
	cDigitalInput();
	cDigitalInput(void *port, uint16_t pinNumber, bool inversion);
	~cDigitalInput();

	virtual void run();

	void Init(void *port, uint16_t pinNumber, bool inversion);
	void SetCheckStateCallback(bool (*CheckStateCallback)(void *port, uint16_t pinNumber));
	void SetDebounceCntValue(uint16_t debounceCntVal);
	bool IsOn();

private:
	void *m_Port;
	uint16_t m_PinNumber;
	bool m_Iversion;
	bool m_State;
	uint16_t m_DebounceCnt;
	uint16_t m_DebounceCntVal;

	bool (*CheckStateCallback)(void *port, uint16_t pinNumber);
	void (*CallbackChangeState)(); // ��� ����������� ��� ������ ����������� �� �������
};

#endif /* DRIVERS_DIGITALINPUT_HPP_ */
