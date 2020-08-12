#include "StateSemenMovement.hpp"


cStateSemenMovement::cStateSemenMovement()
{

}
// ----------------------------------------------------------------------------
cStateSemenMovement::~cStateSemenMovement()
{

}
// ----------------------------------------------------------------------------
void cStateSemenMovement::run(void *params)
{
  cController *controller = (cController*)params;

  if(controller->GetKeysRegister() & KEY_1)
  {
    controller->SetCurrentState(new cStateGeneralStop());
    delete this;
  }
}
