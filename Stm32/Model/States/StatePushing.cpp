#include "StatePushing.hpp"


cStatePushing::cStatePushing()
{
	m_StateIdentifier = eStatePushing;
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
    controller->SetCurrentState(&StateHandleHeld);//(new StateHandleHeld());
//    delete this;
  }
  else if(keys_reg & KEY_1)
  {// 
    controller->SetCurrentState(&StatePositionZero);//(new StatePositionZero());
//    delete this;
  }
  else if(keys_reg & KEY_3)
  {// 
    controller->SetCurrentState(&StateRangeSetting);//(new StateRangeSetting());
//    delete this;
  }
  else if(keys_reg & KEY_8)
  {//
    controller->SetCurrentState(&StateFeedEnabled);//(new StateFeedEnabled());
//    delete this;
  }
  else if(keys_reg & KEY_5)
  {//
    controller->SetCurrentState(&StateWorking);//(new StateWorking());
//    delete this;
  }
}
