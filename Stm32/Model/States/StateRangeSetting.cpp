#include "StateRangeSetting.hpp"


cStateRangeSetting::cStateRangeSetting()
{
	m_StateIdentifier = eStateRangeSetting;
}
// ----------------------------------------------------------------------------
cStateRangeSetting::~cStateRangeSetting()
{

}
// ----------------------------------------------------------------------------
void cStateRangeSetting::run(void *params)
{
  cController *controller = (cController*)params;
  uint32_t keys_reg = controller->GetKeysRegister();

// Соответсвуют режиму cStateFastReturnToOperation (ускоренных возврат в рабочий режим)

// Верхнее и нижнее значения рабочего диапазона могут быть изменены в любой 
// момент времени и из любого состояния путем выбора соответсвующей графы на 
// дисплее и изменения спомощю "КРУТИЛКИ"


  if(keys_reg & KEY_1)
  {
    controller->SetCurrentState(&StatePositionZero);
  }
  else if(keys_reg & KEY_7)
  {
    controller->SetCurrentState(&StateGeneralStop);
  }
  else if(keys_reg & SWITCH)
  {
    controller->SetCurrentState(&StateHandleHeld);
  }
  else if(keys_reg & KEY_5)
  {
    controller->SetCurrentState(&StateWorking);
  }
  else if(keys_reg & KEY_6)
  {
    controller->SetCurrentState(&StateSemenMovement);
  }
  else if(keys_reg & KEY_8)
  {
    controller->SetCurrentState(&StateFeedEnabled);
  }
}
