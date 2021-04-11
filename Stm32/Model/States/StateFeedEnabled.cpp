#include "StateFeedEnabled.hpp"


cStateFeedEnabled::cStateFeedEnabled()
{
	m_StateIdentifier = eStateFeedEnabled;
}
// ----------------------------------------------------------------------------
cStateFeedEnabled::~cStateFeedEnabled()
{

}
// ----------------------------------------------------------------------------
void cStateFeedEnabled::run(void *params)
{
  cController *controller = (cController*)params;
  uint32_t keys_reg = controller->GetKeysRegister();

//1. Эл.двиг вращения шпинделя  - Выкл 
//2. Эл.двиг подачи бабки - Вкл (средняя скорость вращения)*
//3. Муфта вверх - Выкл \ Вкл 
//4. Муфта вниз - Вкл \ Выкл
//5. Муфта ручной - Выкл
//6. ЭМТ - Вкл (разблокировано)

//1. Эл.двиг вращения шпинделя  - Выкл 
//2. Эл.двиг подачи бабки - Вкл (заданая пользователем скорость)
//3. Муфта вверх - Выкл
//4. Муфта вниз - Выкл
//5. Муфта ручной - Выкл
//6. ЭМТ - Выкл (заблокировано)


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
  else if(keys_reg & KEY_5)
  {
    controller->SetCurrentState(&StateWorking);
  }
}
