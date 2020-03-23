#ifndef DRIVERS_ANALOGINPUT_HPP_
#define DRIVERS_ANALOGINPUT_HPP_

#include <stdint.h>
#include <stddef.h>
//#include <iostream>

class cAnalogInput
{
public:
	cAnalogInput();
	~cAnalogInput();

	void Init();

private:
	uint32_t m_Scale;
	uint32_t m_DataRaw;
	uint32_t m_DataScaling;
	uint32_t m_MaxValue;
};

#endif /* DRIVERS_ANALOGINPUT_HPP_ */
