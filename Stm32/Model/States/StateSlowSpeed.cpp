#include "StateSlowSpeed.hpp"


cStateSlowSpeed::cStateSlowSpeed()
{
	m_StateIdentifier = eStateSlowSpeed;
}
// ----------------------------------------------------------------------------
cStateSlowSpeed::~cStateSlowSpeed()
{

}
// ----------------------------------------------------------------------------
void cStateSlowSpeed::run(void *params)
{
  cController *controller = (cController*)params;
  uint32_t keys_reg = controller->GetKeysRegister();
  
  if( keys_reg & KEY_1 )
  {
    controller->SetCurrentState(&StateGeneralStop);
  }
  else if( keys_reg & KEY_3 )
  {
    controller->SetCurrentState(&StateRangeSetting);
  }
}
