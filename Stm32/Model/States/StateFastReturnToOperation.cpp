#include "StateFastReturnToOperation.hpp"


cStateFastReturnToOperation::cStateFastReturnToOperation()
{

}
// ----------------------------------------------------------------------------
cStateFastReturnToOperation::~cStateFastReturnToOperation()
{

}
// ----------------------------------------------------------------------------
void cStateFastReturnToOperation::run(void *params)
{
  cController *controller = (cController*)params;
  uint32_t keys_reg = controller->GetKeysRegister();

  if(keys_reg & KEY_1)
  {
    controller->SetCurrentState(new cStateGeneralStop());
    delete this;
  }
}
