#include "StateFeedIsDisabled.hpp"


cStateFeedIsDisabled::cStateFeedIsDisabled()
{

}
// ----------------------------------------------------------------------------
cStateFeedIsDisabled::~cStateFeedIsDisabled()
{

}
// ----------------------------------------------------------------------------
void cStateFeedIsDisabled::run(void *params)
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
  else if(controller->GetKeysRegister() & SWITCH)
  {
    controller->SetCurrentState(new cStateHandleHeld());
    delete this;
  }
}
