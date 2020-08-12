#include "StatePositionZero.hpp"


cStatePositionZero::cStatePositionZero()
{

}
// ----------------------------------------------------------------------------
cStatePositionZero::~cStatePositionZero()
{

}
// ----------------------------------------------------------------------------
void cStatePositionZero::run(void *params)
{
  cController *controller = (cController*)params;
  
  if(controller->GetKeysRegister() & SWITCH)
  {
    controller->SetCurrentState(new cStateHandleHeld());
    delete this;
  }
  else if(controller->GetKeysRegister() & KEY_2)
  {
    controller->SetCurrentState(new cStateSlowSpeed());
    delete this;
  }
  else if(controller->GetKeysRegister() & KEY_4)
  {
    controller->SetCurrentState(new cStateFastReturnToOperation());
    delete this;
  }

}
