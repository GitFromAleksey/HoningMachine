#include "StatePositionZero.hpp"


cStatePositionZero::cStatePositionZero()
{
	m_StateIdentifier = StatePositionZero;
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
    controller->SetCurrentState(new cStatePushing()); //толчковый
    delete this;
  }
  else if(keys_reg & KEY_4)
  {//ускоренный возврат в рабочий ход
    controller->SetCurrentState(new cStateFastReturnToOperation());
    delete this;
  }
  else if(keys_reg & KEY_7)
  {//ускоренный возврат в рабочий ход
    controller->SetCurrentState(new cStateGeneralStop());
    delete this;
  }

}
