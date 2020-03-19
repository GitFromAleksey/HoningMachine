#ifndef MACHINE_DRIVERS_DIGITALOUT_HPP_
#define MACHINE_DRIVERS_DIGITALOUT_HPP_

#include <stdint.h>
#include <iostream>

class cDigitalOut
{
public:
	cDigitalOut();
	~cDigitalOut();

	void Init(void *port, uint16_t pinNumber, bool inversion);
	void SetOn();
	void SetOff();
	bool IsOn();

private:
	void *m_Port;
	uint16_t m_PinNumber;
	bool m_Inversion;
};

#endif /* MACHINE_DRIVERS_DIGITALOUT_HPP_ */
