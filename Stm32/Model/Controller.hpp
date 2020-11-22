#ifndef MODEL_CONTROLLER_HPP_
#define MODEL_CONTROLLER_HPP_


#include <stddef.h>
#include "../Interfaces/iController.hpp"
#include "../Interfaces/iProcess.hpp"
#include "../Interfaces/iView.hpp"
#include "../Model/machine.hpp"

#include "../Interfaces/iState.hpp"
#include "../Model/States/StateGeneralStop.hpp"
#include "../Model/States/StatePositionZero.hpp"


#define KEY_1   (uint32_t)(1<<0)
#define KEY_2   (uint32_t)(1<<1)
#define KEY_3   (uint32_t)(1<<2)
#define KEY_4   (uint32_t)(1<<3)
#define KEY_5   (uint32_t)(1<<4)
#define KEY_6   (uint32_t)(1<<5)
#define KEY_7   (uint32_t)(1<<6)
#define KEY_8   (uint32_t)(1<<7)
#define KEY_9   (uint32_t)(1<<8)
#define SWITCH  (uint32_t)(1<<9)

class cController : public iController, public iProcess
{
public:
  cController();
  cController(cMachine *machine);
  ~cController();

  virtual void run();

  void SetCurrentState(iState *state);
  void AddMachine(cMachine *machine);
  void AddView(iView *view);
  void SetGetTicksCallback(uint32_t (*GetTicksCallback)());

  void EventsHandler(MachineEvent event);

  virtual void PressKey1(){ m_KeysRegister |= KEY_1; }
  virtual void PressKey2(){ m_KeysRegister |= KEY_2; }
  virtual void PressKey3(){ m_KeysRegister |= KEY_3; }
  virtual void PressKey4(){ m_KeysRegister |= KEY_4; }
  virtual void PressKey5(){ m_KeysRegister |= KEY_5; }
  virtual void PressKey6(){ m_KeysRegister |= KEY_6; }
  virtual void PressKey7(){ m_KeysRegister |= KEY_7; }
  virtual void PressKey8(){ m_KeysRegister |= KEY_8; }
  virtual void PressKey9(){ m_KeysRegister |= KEY_9; }
  virtual void SwitchToggle() // переключатель с фиксацией
  {
    m_KeysRegister ^= SWITCH;
//    if( (m_KeysRegister & SWITCH) == SWITCH )
//    { m_KeysRegister &= ~SWITCH; }
//    else
//    { m_KeysRegister |= SWITCH; }
  }
  uint32_t GetKeysRegister()
  {
    uint32_t tmp = m_KeysRegister;
    m_KeysRegister &= ~(KEY_1|KEY_2|KEY_3|KEY_4|KEY_5|KEY_6|KEY_7|KEY_8|KEY_9);
    return tmp;
  }

  // реализация методов интерфейса iController
  virtual void MachinePowerOn();
  virtual void MachinePowerOff();
  virtual void VerticalFeedMotorOn();
  virtual void VerticalFeedMotorOff();
  virtual void ToolLiftUp();
  virtual void ToolLiftDown();
  virtual void ToolLiftStop();
  virtual void ToolRotateRun();
  virtual void ToolRotateStop();
  virtual void ToolStop();

  virtual void KeyEventHandler(KeyIdentificator keyIdent);

private:
  uint32_t m_Ticks;
  uint32_t m_TicksSendRepeat;
  cMachine *m_Machine;
  iView *m_View; // TODO можно сделать массивом для рассылки нескольким View
  iState *m_CurrentState;
  uint32_t m_KeysRegister;

  uint32_t (*GetTicksCallback)();
};

#endif /* MODEL_CONTROLLER_HPP_ */
