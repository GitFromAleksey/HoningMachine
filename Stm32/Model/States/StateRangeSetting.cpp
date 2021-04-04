#include "StateRangeSetting.hpp"


cStateRangeSetting::cStateRangeSetting()
{
	m_StateIdentifier = StateRangeSetting;
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
    controller->SetCurrentState(new cStatePositionZero());
    delete this;
  }
  else if(keys_reg & KEY_7)
  {
    controller->SetCurrentState(new cStateGeneralStop());
    delete this;
  }
  else if(keys_reg & SWITCH)
  {
    controller->SetCurrentState(new cStateHandleHeld());
    delete this;
  }
  else if(keys_reg & KEY_5)
  {
    controller->SetCurrentState(new cStateWorking());
    delete this;
  }
  else if(keys_reg & KEY_8)
  {
    controller->SetCurrentState(new cStateFeedEnabled());
    delete this;
  }
}
