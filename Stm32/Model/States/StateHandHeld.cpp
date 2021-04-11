#include "StateHandHeld.hpp"


cStateHandleHeld::cStateHandleHeld()
{
	m_StateIdentifier = eStateHandHeld;
}
// ----------------------------------------------------------------------------
cStateHandleHeld::~cStateHandleHeld()
{

}
// ----------------------------------------------------------------------------
void cStateHandleHeld::run(void *params)
{
  cController *controller = (cController*)params;
  uint32_t keys_reg = controller->GetKeysRegister();

//1. Эл.двиг вращения шпинделя: Выкл
//2. Эл.двиг подачи бабки:      Выкл
//3. Муфта вверх:               Выкл
//4. Муфта вниз:                Выкл
//5. Муфта ручной:              Вкл
//6. ЭМТ:                       Разблокировано


  if(keys_reg & KEY_7)
  {
    controller->SetCurrentState(&StateGeneralStop);
  }
  else if(keys_reg & KEY_3)
  {
    controller->SetCurrentState(&StateRangeSetting);
  }
  else if(keys_reg & KEY_4)
  {
    controller->SetCurrentState(&StateFastReturnToOperation);
  }
  else if(keys_reg & KEY_5)
  {
    controller->SetCurrentState(&StateWorking);
  }
  else if(keys_reg & KEY_8)
  {
    controller->SetCurrentState(&StateFeedEnabled);
  }
}
