#include "StateSlowSpeed.hpp"


cStateSlowSpeed::cStateSlowSpeed()
{

}
// ----------------------------------------------------------------------------
cStateSlowSpeed::~cStateSlowSpeed()
{

}
// ----------------------------------------------------------------------------
void cStateSlowSpeed::run(void *params)
{
  cController *controller = (cController*)params;

  if( (controller->GetKeysRegister() & KEY_1) == KEY_1 )
  {
    controller->SetCurrentState(new cStateGeneralStop());
    delete this;
  }
}
