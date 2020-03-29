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
	void SetDataFromADC(uint32_t data);

private:
	uint32_t m_Scale;
	uint32_t m_DataRaw;
	int32_t m_DataAcc;
	uint8_t m_AvgDiv;
	uint32_t m_DataAvg;
	uint32_t m_DataScaling;
	uint32_t m_MaxValue;

	void CalcAverage(uint32_t data);
	
};

#endif /* DRIVERS_ANALOGINPUT_HPP_ */
