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
  uint32_t keys_reg = controller->GetKeysRegister();

  if(keys_reg & KEY_6)
  {
    controller->SetCurrentState(new cStateSemenMovement());
    delete this;
  }
}
