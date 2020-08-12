#include "StateRangeSetting.hpp"


cStateRangeSetting::cStateRangeSetting()
{

}
// ----------------------------------------------------------------------------
cStateRangeSetting::~cStateRangeSetting()
{

}
// ----------------------------------------------------------------------------
void cStateRangeSetting::run(void *params)
{
  cController *controller = (cController*)params;

  if(controller->GetKeysRegister() & KEY_1)
  {
    controller->SetCurrentState(new cStateGeneralStop());
    delete this;
  }
  else if(controller->GetKeysRegister() & KEY_5)
  {
    controller->SetCurrentState(new cStateWorking());
    delete this;
  }
  else if(controller->GetKeysRegister() & KEY_8)
  {
    controller->SetCurrentState(new cStateFeedEnabled());
    delete this;
  }
}
