#include "AnalogInput.hpp"

cAnalogInput::cAnalogInput() :
m_Scale(0),
m_DataRaw(0),
m_DataScaling(0),
m_MaxValue(0)
{
//std::cout << "cAnalogInput::cAnalogInput()" << std::endl;
}
// ----------------------------------------------------------------------------
cAnalogInput::~cAnalogInput()
{

}
// ----------------------------------------------------------------------------
void cAnalogInput::Init()
{
	//std::cout << "cAnalogInput::Init()" << std::endl;
}
// ----------------------------------------------------------------------------
