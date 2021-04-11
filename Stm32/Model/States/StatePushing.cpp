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
  
//1. Эл.двиг вращения шпинделя  | Выкл            | Выкл
//2. Эл.двиг подачи бабки       | Вкл             | Вкл
//3. Муфта вверх                | Выкл            | Выкл
//5. Муфта ручной               | Выкл            | Выкл

//4. Муфта вниз                 | Вкл             | Выкл
//6. ЭМТ                        | Разблокировано  | Заблокировано

  
  
  if(keys_reg & SWITCH)
  {// ручной
    controller->SetCurrentState(&StateHandleHeld);
  }
  else if(keys_reg & KEY_1)
  {// 
    controller->SetCurrentState(&StatePositionZero);
  }
  else if(keys_reg & KEY_3)
  {// 
    controller->SetCurrentState(&StateRangeSetting);
  }
  else if(keys_reg & KEY_8)
  {//
    controller->SetCurrentState(&StateFeedEnabled);
  }
  else if(keys_reg & KEY_5)
  {//
    controller->SetCurrentState(&StateWorking);
  }
}
