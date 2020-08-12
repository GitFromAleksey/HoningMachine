#include "Controller.hpp"

cController::cController():
m_Ticks(0),
m_TicksSendRepeat(100),
m_Machine(NULL),
m_View(NULL),
m_KeysRegister(0)
{
  SetCurrentState(new cStateGeneralStop());
}
// ----------------------------------------------------------------------------
cController::cController(cMachine *machine)
{
  AddMachine(machine);
}
// ----------------------------------------------------------------------------
cController::~cController()
{

}
// ----------------------------------------------------------------------------
void cController::AddMachine(cMachine *machine)
{
  if(machine != NULL)
    m_Machine = machine;
}
// ----------------------------------------------------------------------------
void cController::AddView(iView *view)
{
  m_View = view;
}
// ----------------------------------------------------------------------------
void cController::SetGetTicksCallback(uint32_t (*GetTicksCallback)())
{
  this->GetTicksCallback = GetTicksCallback;
}
// ----------------------------------------------------------------------------
void cController::SetCurrentState(iState *state)
{
  m_CurrentState = state;
}
// ----------------------------------------------------------------------------
void cController::run()
{
  if(m_Machine == NULL)
    return;

  if(m_CurrentState != NULL)
  {
    m_CurrentState->run(this);
  }
  
  if(GetTicksCallback != NULL)
  {
    if((GetTicksCallback() - m_Ticks) > m_TicksSendRepeat)
    {
      m_Ticks = GetTicksCallback();
      m_View->SendCurrentPosition( m_Machine->GetCurrentPosition());
      m_View->SendCurrent( m_Machine->GetCurrent());
      m_View->SendLowerToolTipState(m_Machine->GetLowerToolTipState());
      m_View->SendUpperToolTipState(m_Machine->GetUpperToolTipState());
    }
  }
}
// ----------------------------------------------------------------------------
void cController::EventsHandler(MachineEvent event)
{
  switch(event)
  {
    case evUpperTipReached:
      break;
    case evLowerTipReached:
      break;

    default:
      break;
  }
}
// ----------------------------------------------------------------------------
// реализация методов интерфейса iController
void cController::MachinePowerOn()
{
  m_Machine->MachinePowerOn();
}
// ----------------------------------------------------------------------------
void cController::MachinePowerOff()
{
  m_Machine->MachinePowerOff();
}
// ----------------------------------------------------------------------------
void cController::VerticalFeedMotorOn()
{
  m_Machine->VerticalFeedMotorOn();
}
// ----------------------------------------------------------------------------
void cController::VerticalFeedMotorOff()
{
  m_Machine->VerticalFeedMotorOff();
}
// ----------------------------------------------------------------------------
void cController::ToolLiftUp()
{
  m_Machine->ToolLiftUp();
}
// ----------------------------------------------------------------------------
void cController::ToolLiftDown()
{
  m_Machine->ToolLiftDown();
}
// ----------------------------------------------------------------------------
void cController::ToolLiftStop()
{
  m_Machine->ToolLiftStop();
}
// ----------------------------------------------------------------------------
void cController::ToolRotateRun()
{
  m_Machine->ToolRotateRun();
}
// ----------------------------------------------------------------------------
void cController::ToolRotateStop()
{
  m_Machine->ToolRotateStop();
}
// ----------------------------------------------------------------------------
void cController::ToolStop()
{
  m_Machine->ToolStop();
}
// конец реализации методов интерфейса iController
// ----------------------------------------------------------------------------
