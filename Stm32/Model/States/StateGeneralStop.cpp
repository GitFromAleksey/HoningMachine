#include "StateGeneralStop.hpp"
#include "Controller.hpp"

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
  if( (controller->GetKeysRegister() & KEY_7) == KEY_7 )
  {
    // создать класс "Позиция 0"
    // controller->SetCurrentState("Позиция 0");
    delete this;
  }
}
