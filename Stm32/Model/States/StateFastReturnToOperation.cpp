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

  if(controller->GetKeysRegister() & KEY_1)
  {
    controller->SetCurrentState(new cStateGeneralStop());
    delete this;
  }
}
