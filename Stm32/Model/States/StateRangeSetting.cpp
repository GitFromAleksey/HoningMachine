#include "StateRangeSetting.hpp"


cStateRangeSetting::cStateRangeSetting()
{
	m_StateIdentifier = eStateRangeSetting;
}
// ----------------------------------------------------------------------------
cStateRangeSetting::~cStateRangeSetting()
{

}
// ----------------------------------------------------------------------------
void cStateRangeSetting::run(void *params)
{
  cController *controller = (cController*)params;
  uint32_t keys_reg = controller->GetKeysRegister();

  if(keys_reg & KEY_1)
  {
    controller->SetCurrentState(&StatePositionZero);//(new cStatePositionZero());
//    delete this;
  }
  else if(keys_reg & KEY_7)
  {
    controller->SetCurrentState(&StateGeneralStop);//(new cStateGeneralStop());
//    delete this;
  }
  else if(keys_reg & SWITCH)
  {
    controller->SetCurrentState(&StateHandleHeld);//(new cStateHandleHeld());
//    delete this;
  }
  else if(keys_reg & KEY_5)
  {
    controller->SetCurrentState(&StateWorking);//(new cStateWorking());
//    delete this;
  }
  else if(keys_reg & KEY_6)
  {
    controller->SetCurrentState(&StateSemenMovement);//(new cStateSemenMovement());
//    delete this;
  }
  else if(keys_reg & KEY_8)
  {
    controller->SetCurrentState(&StateFeedEnabled);//(new cStateFeedEnabled());
//    delete this;
  }
}
