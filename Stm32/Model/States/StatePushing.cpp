#include "StatePushing.hpp"


cStatePushing::cStatePushing()
{
	m_StateIdentifier = StatePushing;
}
// ----------------------------------------------------------------------------
cStatePushing::~cStatePushing()
{

}
// ----------------------------------------------------------------------------
void cStatePushing::run(void *params)
{
  cController *controller = (cController*)params;
  uint32_t keys_reg = controller->GetKeysRegister();

  controller->VerticalFeedMotorOn();
  controller->ToolLiftUp();
  
  if(keys_reg & SWITCH)
  {// ручной
    controller->SetCurrentState(new cStateHandleHeld());
    delete this;
  }
  else if(keys_reg & KEY_1)
  {// 
    controller->SetCurrentState(new cStatePositionZero());
    delete this;
  }
  else if(keys_reg & KEY_3)
  {// 
    controller->SetCurrentState(new cStateRangeSetting());
    delete this;
  }
  else if(keys_reg & KEY_8)
  {//
    controller->SetCurrentState(new cStateFeedEnabled());
    delete this;
  }
  else if(keys_reg & KEY_5)
  {//
    controller->SetCurrentState(new cStateWorking());
    delete this;
  }
}
