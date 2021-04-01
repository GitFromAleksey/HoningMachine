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
  uint32_t keys_reg = controller->GetKeysRegister();

  controller->VerticalFeedMotorOn();
  controller->ToolLiftUp();
  
  if(keys_reg & SWITCH)
  {
    controller->SetCurrentState(new cStateHandleHeld());
    delete this;
  }
  else if(keys_reg & KEY_2)
  {
    controller->SetCurrentState(new cStateSlowSpeed());
    delete this;
  }
  else if(keys_reg & KEY_4)
  {
    controller->SetCurrentState(new cStateFastReturnToOperation());
    delete this;
  }

}
