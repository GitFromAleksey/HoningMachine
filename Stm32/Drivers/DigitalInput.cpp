#include "DigitalInput.hpp"

cDigitalInput::cDigitalInput() :
	m_Port(NULL),
	m_PinNumber(0),
	m_Iversion(false),
	m_State(false),
	CheckStateCallback(NULL),
	CallbackChangeState(NULL)
{

}
cDigitalInput::cDigitalInput(void *port, uint16_t pinNumber, bool inversion) :
	m_Port(port),
	m_PinNumber(pinNumber),
	m_Iversion(inversion),
	m_State(false),
	CheckStateCallback(NULL),
	CallbackChangeState(NULL)
{
	
}
// ----------------------------------------------------------------------------
cDigitalInput::~cDigitalInput()
{

}
// ----------------------------------------------------------------------------
void cDigitalInput::run()
{
	bool state;
	
	if(m_Port != NULL)
	{
		if(CheckStateCallback != NULL)
		{
			state = (m_Iversion)?(!CheckStateCallback(m_Port, m_PinNumber)):(CheckStateCallback(m_Port, m_PinNumber));
			if(m_State != state)
			{
				if(++m_DebounceCnt > m_DebounceCntVal)
				{
					m_State = state;
					m_DebounceCnt = 0;
				}
			}
			else
			{
				m_DebounceCnt = 0;
			}			
		}
	}
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
void cDigitalInput::SetDebounceCntValue(uint16_t debounceCntVal)
{
	
}
// ----------------------------------------------------------------------------
bool cDigitalInput::IsOn()
{
	return m_State;
}
// ----------------------------------------------------------------------------
