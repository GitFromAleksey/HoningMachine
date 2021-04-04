#include "StateGeneralStop.hpp"


cStateGeneralStop::cStateGeneralStop()
{
  m_StateIdentifier = StateGeneralStop;
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
    controller->SetCurrentState(new cStatePositionZero());
//    delete this;
  }
  else if( keys_reg & KEY_5 )
  {
    controller->SetCurrentState(new cStateWorking());
//    delete this;
  }
  else if( keys_reg & KEY_8 )
  {
    controller->SetCurrentState(new cStateFeedEnabled());
//    delete this;
  }
//  if(this != controller->GetCurrentState())
//	  delete this;
}
