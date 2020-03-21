#include "DigitalInput.hpp"

cDigitalInput::cDigitalInput() :
	m_Ivversion(false),
	CallbackChangeState(nullptr),
	CallbackSetHi(nullptr),
	CallbackSetLo(nullptr)
{
	std::cout << "cDigitalInput::cDigitalInput()" << std::endl;
}
// ----------------------------------------------------------------------------
cDigitalInput::~cDigitalInput()
{

}
// ----------------------------------------------------------------------------
void cDigitalInput::Init(void (*_CallbackChangeState)(), void (*_CallbackSetHi)(),
						void (*_CallbackSetLo)(), bool inversion)
{
	CallbackChangeState = (_CallbackChangeState == nullptr) ? (nullptr) : (_CallbackChangeState);
	CallbackSetHi = (_CallbackSetHi == nullptr) ? (nullptr) : (_CallbackSetHi);
	CallbackSetLo = (_CallbackSetLo == nullptr) ? (nullptr) : (_CallbackSetLo);
	m_Ivversion = inversion;
}
// ----------------------------------------------------------------------------
bool cDigitalInput::IsOn()
{
	return false;
}
// ----------------------------------------------------------------------------
