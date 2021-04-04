#include "StateFeedIsDisabled.hpp"


cStateFeedIsDisabled::cStateFeedIsDisabled()
{
	m_StateIdentifier = StateFeedIsDisabled;
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
    controller->SetCurrentState(new cStateGeneralStop());
    delete this;
  }
  else if(keys_reg & KEY_5)
  {
    controller->SetCurrentState(new cStateWorking());
    delete this;
  }
  else if(keys_reg & SWITCH)
  {
    controller->SetCurrentState(new cStateHandleHeld());
    delete this;
  }
}
