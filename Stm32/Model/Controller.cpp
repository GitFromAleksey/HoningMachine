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
//void cController::MachinePowerOn()
//{
////  m_Machine->MachinePowerOn(); // TODO ненужная кнопка
//}
// ----------------------------------------------------------------------------
//void cController::MachinePowerOff()
//{
////  m_Machine->MachinePowerOff(); // TODO ненужная кнопка
//}
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
// ----------------------------------------------------------------------------
void cController::KeyEventHandler(KeyIdentificator keyIdent)
{
  switch(keyIdent)
  {
    case pressKey1:
      PressKey1();
      break;
    case pressKey2:
      PressKey2();
      break;
    case pressKey3:
      PressKey3();
      break;
    case pressKey4:
      PressKey4();
      break;
    case pressKey5:
      PressKey5();
      break;
    case pressKey6:
      PressKey6();
      break;
    case pressKey7:
      PressKey7();
      break;
    case pressKey8:
      PressKey8();
      break;
    case pressKey9:
      PressKey9();
      break;
    case switchToggle:
      SwitchToggle();
      break;
//    case machinePowerOn:
//      MachinePowerOn();
//      break;
//    case machinePowerOff:
//      MachinePowerOff();
//      break;
    case verticalFeedMotorOn:
      VerticalFeedMotorOn();
      break;
    case verticalFeedMotorOff:
      VerticalFeedMotorOff();
      break;
    case toolLiftUp:
      ToolLiftUp();
      break;
    case toolLiftDown:
      ToolLiftDown();
      break;
    case toolLiftStop:
      ToolLiftStop();
      break;
    case toolRotateRun:
      ToolRotateRun();
      break;
    case toolRotateStop:
      ToolRotateStop();
      break;
    case toolStop:
      ToolStop();
      break;
    default:
      break;
  }
}
// конец реализации методов интерфейса iController
// ----------------------------------------------------------------------------
