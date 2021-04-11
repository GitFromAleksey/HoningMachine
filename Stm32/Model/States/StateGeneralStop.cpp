#include "StateGeneralStop.hpp"


cStateGeneralStop::cStateGeneralStop()
{
  m_StateIdentifier = eStateGeneralStop;
}
// ----------------------------------------------------------------------------
cStateGeneralStop::~cStateGeneralStop() {}
// ----------------------------------------------------------------------------
void cStateGeneralStop::run(void *params)
{
  cController *controller = (cController*)params;
  uint32_t keys_reg = controller->GetKeysRegister();
  
  controller->ToolLiftStop();
  controller->VerticalFeedMotorOff();
  controller->ToolRotateStop();
  
  if( keys_reg & KEY_1 )
  {
    controller->SetCurrentState(&StatePositionZero);//(new cStatePositionZero());
//    delete this;
  }
  else if( keys_reg & KEY_5 )
  {
    controller->SetCurrentState(&StateWorking);//(new cStateWorking());
//    delete this;
  }
  else if( keys_reg & KEY_8 )
  {
    controller->SetCurrentState(&StateFeedEnabled);//(new cStateFeedEnabled());
//    delete this;
  }
}
