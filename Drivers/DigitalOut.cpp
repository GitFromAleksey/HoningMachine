#include "DigitalOut.hpp"

cDigitalOut::cDigitalOut() :
	m_Port(nullptr),
	m_PinNumber(0),
	m_Inversion(false)
{
	std::cout << "cDigitalOut::cDigitalOut()" << std::endl;
}
// ----------------------------------------------------------------------------
cDigitalOut::~cDigitalOut()
{

}
// ----------------------------------------------------------------------------
void cDigitalOut::Init(void *port, uint16_t pinNumber, bool inversion)
{
	m_Port = port;
	m_PinNumber = pinNumber;
	m_Inversion = inversion;
}
// ----------------------------------------------------------------------------
void cDigitalOut::SetOn()
{

}
// ----------------------------------------------------------------------------
void cDigitalOut::SetOff()
{

}
// ----------------------------------------------------------------------------
bool cDigitalOut::IsOn()
{
	return false;
}
// ----------------------------------------------------------------------------
