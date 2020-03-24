#include "DigitalInput.hpp"

cDigitalInput::cDigitalInput() :
	m_Iversion(false),
	CallbackChangeState(NULL),
	CallbackSetHi(NULL),
	CallbackSetLo(NULL)
{
//	std::cout << "cDigitalInput::cDigitalInput()" << std::endl;
}
// ----------------------------------------------------------------------------
cDigitalInput::~cDigitalInput()
{

}
// ----------------------------------------------------------------------------
void cDigitalInput::Init(void (*_CallbackChangeState)(), void (*_CallbackSetHi)(),
						void (*_CallbackSetLo)(), bool inversion)
{
	CallbackChangeState = (_CallbackChangeState == NULL) ? (NULL) : (_CallbackChangeState);
	CallbackSetHi = (_CallbackSetHi == NULL) ? (NULL) : (_CallbackSetHi);
	CallbackSetLo = (_CallbackSetLo == NULL) ? (NULL) : (_CallbackSetLo);
	m_Iversion = inversion;
}
// ----------------------------------------------------------------------------
bool cDigitalInput::IsOn()
{
	return false;
}
// ----------------------------------------------------------------------------
