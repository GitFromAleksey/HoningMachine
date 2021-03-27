#include "DigitalOut.hpp"

cDigitalOut::cDigitalOut() :
	m_Port(NULL),
	m_PinNumber(0),
	m_Inversion(false),
	SwitchCallback(NULL),
	CheckStateCallback(NULL)
{

}
// ----------------------------------------------------------------------------
cDigitalOut::~cDigitalOut()
{

}
// ----------------------------------------------------------------------------
void cDigitalOut::run()
{
	// TODO доделать реализацию
}
// ----------------------------------------------------------------------------
void cDigitalOut::Init(void *port, uint16_t pinNumber, bool inversion)
{
	m_Port = port;
	m_PinNumber = pinNumber;
	m_Inversion = inversion;
}
// ----------------------------------------------------------------------------
void cDigitalOut::SetDoSwitchCallback(void (*SwitchCallback)(void *port, uint16_t pinNumber, bool hi_lo))
{
	if(SwitchCallback != NULL)
		this->SwitchCallback = SwitchCallback;
}
// ----------------------------------------------------------------------------
void cDigitalOut::SetCheckStateCallback(bool (*CheckStateCallback)(void *port, uint16_t pinNumber))
{
	if(CheckStateCallback != NULL)
		this->CheckStateCallback = CheckStateCallback;
}
// ----------------------------------------------------------------------------
void cDigitalOut::SetOn()
{
	if((this->SwitchCallback == NULL) || (this->m_Port == NULL)) return;
	
	this->SwitchCallback(this->m_Port, this->m_PinNumber, !m_Inversion);
}
// ----------------------------------------------------------------------------
void cDigitalOut::SetOff()
{
	if((this->SwitchCallback == NULL) || (this->m_Port == NULL)) return;

	this->SwitchCallback(this->m_Port, this->m_PinNumber, m_Inversion);
}
// ----------------------------------------------------------------------------
void cDigitalOut::Toggle()
{
	(IsOn()) ? (SetOff()) : (SetOn());
}
// ----------------------------------------------------------------------------
bool cDigitalOut::IsOn()
{
  bool state = false;

  if((this->CheckStateCallback == NULL) || (this->m_Port == NULL)) return false;

  state = CheckStateCallback(this->m_Port, this->m_PinNumber);
  state = (this->m_Inversion)?(!state):(state);

  return state;
}
// ----------------------------------------------------------------------------
