#ifndef DRIVERS_DIGITALOUT_HPP_
#define DRIVERS_DIGITALOUT_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iProcess.hpp"
//#include <iostream>

class cDigitalOut : public iProcess
{
public:
	cDigitalOut();
	~cDigitalOut();

	virtual void run();

	void Init(void *port, uint16_t pinNumber, bool inversion);
	void SetDoSwitchCallback(void (*SwitchCallback)(void *port, uint16_t pinNumber, bool hi_lo));
	void SetCheckStateCallback(bool (*CheckStateCallback)(void *port, uint16_t pinNumber));
	void SetOn();
	void SetOff();
	void Toggle();
	bool IsOn();

private:
	void *m_Port;
	uint16_t m_PinNumber;
	bool m_Inversion;

	void (*SwitchCallback)(void *port, uint16_t pinNumber, bool hi_lo);
	bool (*CheckStateCallback)(void *port, uint16_t pinNumber);
};

#endif /* DRIVERS_DIGITALOUT_HPP_ */
