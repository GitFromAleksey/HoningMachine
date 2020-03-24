#ifndef DRIVERS_DIGITALINPUT_HPP_
#define DRIVERS_DIGITALINPUT_HPP_

#include <stdint.h>
#include <stddef.h>
//#include <iostream>


class cDigitalInput
{
public:
	cDigitalInput();
	~cDigitalInput();

	void Init(void *port, uint16_t pinNumber, bool inversion);
	void SetCheckStateCallback(bool (*CheckStateCallback)(void *port, uint16_t pinNumber));
	bool IsOn();

private:
	void *m_Port;
	uint16_t m_PinNumber;
	bool m_Iversion;

	bool (*CheckStateCallback)(void *port, uint16_t pinNumber);
	void (*CallbackChangeState)();
};

#endif /* DRIVERS_DIGITALINPUT_HPP_ */
