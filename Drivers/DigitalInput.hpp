#ifndef DRIVERS_DIGITALINPUT_HPP_
#define DRIVERS_DIGITALINPUT_HPP_

#include <stdint.h>
#include <iostream>

class cDigitalInput
{
public:
	cDigitalInput();
	~cDigitalInput();

	void Init(void (*_CallbackChangeState)(), void (*_CallbackSetHi)(),
				void (*_CallbackSetLo)(), bool inversion);
	bool IsOn();

private:
	bool m_Ivversion;

	void (*CallbackChangeState)();
	void (*CallbackSetHi)();
	void (*CallbackSetLo)();

};

#endif /* DRIVERS_DIGITALINPUT_HPP_ */
