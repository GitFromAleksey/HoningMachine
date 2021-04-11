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

// 1. Эл.двиг вращения шпинделя:  Выкл,           Выкл
// 2. Эл.двиг подачи бабки:       Вкл,            Вкл
// 3. Муфта движения бабки вверх: Вкл,            Выкл 
// 4. Муфта вниз:                 Выкл,           Выкл
// 5. Муфта ручной:               Выкл,           Выкл
// 6. Электро тормоз:             Разблокирован,  Заблокирован


  controller->VerticalFeedMotorOn();
  controller->ToolLiftUp();
  
  if(keys_reg & SWITCH)
  {
    controller->SetCurrentState(&StateHandleHeld);
  }
  else if(keys_reg & KEY_2)
  {
    controller->SetCurrentState(&StatePushing);
  }
  else if(keys_reg & KEY_4)
  {//ускоренный возврат в рабочий ход
    controller->SetCurrentState(&StateFastReturnToOperation);
  }
  else if(keys_reg & KEY_7)
  {//ускоренный возврат в рабочий ход
    controller->SetCurrentState(&StateGeneralStop);
  }

}
