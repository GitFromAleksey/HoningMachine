#include "StateFeedIsDisabled.hpp"


cStateFeedIsDisabled::cStateFeedIsDisabled()
{
	m_StateIdentifier = eStateFeedIsDisabled;
}
// ----------------------------------------------------------------------------
cStateFeedIsDisabled::~cStateFeedIsDisabled()
{

}
// ----------------------------------------------------------------------------
void cStateFeedIsDisabled::run(void *params)
{
  cController *controller = (cController*)params;
  uint32_t keys_reg = controller->GetKeysRegister();

  if(keys_reg & KEY_1)
  {
    controller->SetCurrentState(&StateGeneralStop);//(new cStateGeneralStop());
//    delete this;
  }
  else if(keys_reg & KEY_5)
  {
    controller->SetCurrentState(&StateWorking);//(new cStateWorking());
//    delete this;
  }
  else if(keys_reg & SWITCH)
  {
    controller->SetCurrentState(&StateHandleHeld);//(new cStateHandleHeld());
//    delete this;
  }
}
