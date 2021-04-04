#include "StateSlowSpeed.hpp"


cStateSlowSpeed::cStateSlowSpeed()
{
	m_StateIdentifier = StateSlowSpeed;
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
    controller->SetCurrentState(new cStateGeneralStop());
    delete this;
  }
  else if( keys_reg & KEY_3 )
  {
    controller->SetCurrentState(new cStateRangeSetting());
    delete this;
  }
}
