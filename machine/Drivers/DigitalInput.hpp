#ifndef MACHINE_DRIVERS_DIGITALINPUT_HPP_
#define MACHINE_DRIVERS_DIGITALINPUT_HPP_

#include <stdint.h>
#include <iostream>

class cDigitalInput
{
public:
	cDigitalInput();
	~cDigitalInput();

	void Init(void (*_CallbackChangeState)(), void (*_CallbackSetHi)(),
				void (*_CallbackSetLo)(), bool inversion);
	void IsOn();

private:
	bool m_Ivversion;

	void (*CallbackChangeState)();
	void (*CallbackSetHi)();
	void (*CallbackSetLo)();

};

#endif /* MACHINE_DRIVERS_DIGITALINPUT_HPP_ */
