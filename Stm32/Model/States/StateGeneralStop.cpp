#include "StateGeneralStop.hpp"


cStateGeneralStop::cStateGeneralStop()
{

}
// ----------------------------------------------------------------------------
cStateGeneralStop::~cStateGeneralStop()
{

}
// ----------------------------------------------------------------------------
void cStateGeneralStop::run(void *params)
{
  cController *controller = (cController*)params;
  uint32_t keys_reg = controller->GetKeysRegister();
  
  if( keys_reg & KEY_7 )
  {
    // создать класс "Позиция 0"
    controller->SetCurrentState(new cStatePositionZero());
    delete this;
  }
}
