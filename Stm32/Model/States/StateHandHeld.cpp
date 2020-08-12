#include "StateHandHeld.hpp"


cStateHandleHeld::cStateHandleHeld()
{

}
// ----------------------------------------------------------------------------
cStateHandleHeld::~cStateHandleHeld()
{

}
// ----------------------------------------------------------------------------
void cStateHandleHeld::run(void *params)
{
  cController *controller = (cController*)params;

  if(controller->GetKeysRegister() & KEY_1)
  {
    controller->SetCurrentState(new cStateGeneralStop());
    delete this;
  }
  else if(controller->GetKeysRegister() & KEY_3)
  {
    controller->SetCurrentState(new cStateRangeSetting());
    delete this;
  }
}
