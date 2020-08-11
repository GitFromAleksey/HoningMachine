#include "StateStart.hpp"


cStateStart::cStateStart()
{

}
// ----------------------------------------------------------------------------
cStateStart::~cStateStart()
{

}
// ----------------------------------------------------------------------------
void cStateStart::run(void *params)
{
  cController *controller = (cController*)params;
  
  if(controller->GetKeysRegister() & KEY_7)
  {
    controller->MachinePowerOn();
    controller->SetCurrentState(NULL);
    delete this;
  }
}
