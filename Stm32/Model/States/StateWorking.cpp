#include "StateWorking.hpp"


cStateWorking::cStateWorking()
{
	m_StateIdentifier = eStateWorking;
}
// ----------------------------------------------------------------------------
cStateWorking::~cStateWorking()
{

}
// ----------------------------------------------------------------------------
void cStateWorking::run(void *params)
{
  cController *controller = (cController*)params;
  uint32_t keys_reg = controller->GetKeysRegister();

//1. Эл.двиг вращения шпинделя  - Вкл (заданя скорость)**
//2. Эл.двиг подачи бабки - Вкл (заданная скорость)**
//3. Муфта вверх - Вкл \ выкл
//4. Муфта вниз - Выкл \ Вкл
//5. Муфта ручной - Выкл
//6. ЭМТ - Вкл (разблокировано)

// Состояние входов\выходов соответсует выбраному режиму


  if(keys_reg & KEY_1)
  {
    controller->SetCurrentState(&StatePositionZero);
  }
  else if(keys_reg & SWITCH)
  {
    controller->SetCurrentState(&StateHandleHeld);
  }
  else if(keys_reg & KEY_7)
  {
    controller->SetCurrentState(&StateGeneralStop);
  }
  else if(keys_reg & KEY_8)
  {
    controller->SetCurrentState(&StateFeedEnabled);
  }
}
