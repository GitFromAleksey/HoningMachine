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
  uint32_t keys_reg = controller->GetKeysRegister();

  if(keys_reg & KEY_1)
  {
    controller->SetCurrentState(new cStateGeneralStop());
    delete this;
  }
}
