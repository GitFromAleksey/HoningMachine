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

  if(controller->GetKeysRegister() & KEY_1)
  {
    controller->SetCurrentState(new cStateGeneralStop());
    delete this;
  }
  else if(controller->GetKeysRegister() & KEY_5)
  {
    controller->SetCurrentState(new cStateWorking());
    delete this;
  }
  else if(controller->GetKeysRegister() & KEY_9)
  {
    controller->SetCurrentState(new cStateFeedIsDisabled());
    delete this;
  }
}
