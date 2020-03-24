#include "DigitalInput.hpp"

cDigitalInput::cDigitalInput() :
	m_Port(NULL),
	m_PinNumber(0),
	m_Iversion(false),
	CallbackChangeState(NULL)
{

}
// ----------------------------------------------------------------------------
cDigitalInput::~cDigitalInput()
{

}
// ----------------------------------------------------------------------------
void cDigitalInput::Init(void *port, uint16_t pinNumber, bool inversion)
{
	if(port == NULL) return;
	
	this->m_Port = port;
	this->m_PinNumber = pinNumber;
	this->m_Iversion = inversion;
}
// ----------------------------------------------------------------------------
void cDigitalInput::SetCheckStateCallback(bool (*CheckStateCallback)(void *port, uint16_t pinNumber))
{
	if(CheckStateCallback != NULL)
		this->CheckStateCallback = CheckStateCallback;
}
// ----------------------------------------------------------------------------
bool cDigitalInput::IsOn()
{
	if((this->CheckStateCallback == NULL) || (this->m_Port == NULL)) return false;
	
	return CheckStateCallback(this->m_Port, this->m_PinNumber);
}
// ----------------------------------------------------------------------------
