#include "StateWorking.hpp"


cStateWorking::cStateWorking()
{

}
// ----------------------------------------------------------------------------
cStateWorking::~cStateWorking()
{

}
// ----------------------------------------------------------------------------
void cStateWorking::run(void *params)
{
  cController *controller = (cController*)params;

  if(controller->GetKeysRegister() & KEY_6)
  {
    controller->SetCurrentState(new cStateSemenMovement());
    delete this;
  }
}
