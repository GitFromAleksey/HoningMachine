#include "StateHandHeld.hpp"


cStateHandleHeld::cStateHandleHeld()
{
	m_StateIdentifier = StateHandHeld;
}
// ----------------------------------------------------------------------------
cStateHandleHeld::~cStateHandleHeld()
{

}
// ----------------------------------------------------------------------------
void cStateHandleHeld::run(void *params)
{
  cController *controller = (cController*)params;
  uint32_t keys_reg = controller->GetKeysRegister();

  if(keys_reg & KEY_7)
  {
    controller->SetCurrentState(new cStateGeneralStop());
    delete this;
  }
  else if(keys_reg & KEY_3)
  {
    controller->SetCurrentState(new cStateRangeSetting());
    delete this;
  }
  else if(keys_reg & KEY_4)
  {
    controller->SetCurrentState(new cStateFastReturnToOperation());
    delete this;
  }
  else if(keys_reg & KEY_5)
  {
    controller->SetCurrentState(new cStateWorking());
    delete this;
  }
  else if(keys_reg & KEY_8)
  {
    controller->SetCurrentState(new cStateFeedEnabled());
    delete this;
  }
}
