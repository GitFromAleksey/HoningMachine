#include "StateFastReturnToOperation.hpp"


cStateFastReturnToOperation::cStateFastReturnToOperation()
{
	m_StateIdentifier = eStateFastReturnToOperation;
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
    controller->SetCurrentState(&StatePositionZero);//(new cStatePositionZero());
//    delete this;
  }
  else if(keys_reg & SWITCH)
  {
    controller->SetCurrentState(&StateHandleHeld);//(new cStateHandleHeld());
//    delete this;
  }
  else if(keys_reg & KEY_7)
  {
    controller->SetCurrentState(&StateGeneralStop);//(new cStateGeneralStop());
//    delete this;
  }
  else if(keys_reg & KEY_5)
  {
    controller->SetCurrentState(&StateWorking);//(new cStateWorking());
//    delete this;
  }
  else if(keys_reg & KEY_8)
  {
    controller->SetCurrentState(&StateFeedEnabled);//(new cStateFeedEnabled());
//    delete this;
  }
}
