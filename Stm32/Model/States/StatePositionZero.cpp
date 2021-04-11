#include "StatePositionZero.hpp"


cStatePositionZero::cStatePositionZero()
{
	m_StateIdentifier = eStatePositionZero;
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
    controller->SetCurrentState(&StateHandleHeld);//(new cStateHandleHeld());
//    delete this;
  }
  else if(keys_reg & KEY_2)
  {
    controller->SetCurrentState(&StatePushing);//(new cStatePushing()); //толчковый
//    delete this;
  }
  else if(keys_reg & KEY_4)
  {//ускоренный возврат в рабочий ход
    controller->SetCurrentState(&StateFastReturnToOperation);//(new cStateFastReturnToOperation());
//    delete this;
  }
  else if(keys_reg & KEY_7)
  {//ускоренный возврат в рабочий ход
    controller->SetCurrentState(&StateGeneralStop);//(new cStateGeneralStop());
//    delete this;
  }

}
