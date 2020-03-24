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

	void Init(void (*_CallbackChangeState)(), void (*_CallbackSetHi)(),
				void (*_CallbackSetLo)(), bool inversion);
	bool IsOn();

private:
	bool m_Iversion;

	void (*CallbackChangeState)();
	void (*CallbackSetHi)();
	void (*CallbackSetLo)();

};

#endif /* DRIVERS_DIGITALINPUT_HPP_ */
