#include "KeyBoard.hpp"

cKeyBoard::cKeyBoard()
{
//  m_KeysArray = new cArray<cDigitalInput>();
}
// ----------------------------------------------------------------------------
cKeyBoard::~cKeyBoard()
{

}
// ----------------------------------------------------------------------------
void cKeyBoard::run()
{
	
}
// ----------------------------------------------------------------------------
void cKeyBoard::AddKey(cDigitalInput *key)
{
  m_KeysArray.AddItem(key);
}
// ----------------------------------------------------------------------------
