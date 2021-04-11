#include "StateHandHeld.hpp"


cStateHandleHeld::cStateHandleHeld()
{
	m_StateIdentifier = eStateHandHeld;
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
    controller->SetCurrentState(&StateGeneralStop);//(new cStateGeneralStop());
//    delete this;
  }
  else if(keys_reg & KEY_3)
  {
    controller->SetCurrentState(&StateRangeSetting);//(new cStateRangeSetting());
//    delete this;
  }
  else if(keys_reg & KEY_4)
  {
    controller->SetCurrentState(&StateFastReturnToOperation);//(new cStateFastReturnToOperation());
//    delete this;
  }
  else if(keys_reg & KEY_5)
  {
    controller->SetCurrentState(&StateWorking);//(new cStateWorking());
//    delete this;
  }
  else if(keys_reg & KEY_8)
  {
    controller->SetCurrentState(&StateFeedEnabled);//(new cStateFeedEnabled());
//    delete this;
  }
}
