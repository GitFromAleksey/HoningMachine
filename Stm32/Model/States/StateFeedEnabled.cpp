#include "StateFeedEnabled.hpp"


cStateFeedEnabled::cStateFeedEnabled()
{

}
// ----------------------------------------------------------------------------
cStateFeedEnabled::~cStateFeedEnabled()
{

}
// ----------------------------------------------------------------------------
void cStateFeedEnabled::run(void *params)
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
  else if(keys_reg & KEY_9)
  {
    controller->SetCurrentState(new cStateFeedIsDisabled());
    delete this;
  }
}
