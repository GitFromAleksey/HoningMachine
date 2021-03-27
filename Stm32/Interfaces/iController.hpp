#ifndef INTERFACES_ICONTROLLER_HPP_
#define INTERFACES_ICONTROLLER_HPP_

//typedef enum KeyIdentificator
typedef enum e_KeyIdentificator_
{
  pressKey1 = 1,
  pressKey2,
  pressKey3,
  pressKey4,
  pressKey5,
  pressKey6,
  pressKey7,
  pressKey8,
  pressKey9,
  switchToggle,

  machinePowerOn,
  machinePowerOff,
  verticalFeedMotorOn,
  verticalFeedMotorOff,
  toolLiftUp,
  toolLiftDown,
  toolLiftStop,
  toolRotateRun,
  toolRotateStop,
  toolStop,

  none
} KeyIdentificator;

class iController
{
public:

  virtual void PressKey1() = 0;
  virtual void PressKey2() = 0;
  virtual void PressKey3() = 0;
  virtual void PressKey4() = 0;
  virtual void PressKey5() = 0;
  virtual void PressKey6() = 0;
  virtual void PressKey7() = 0;
  virtual void PressKey8() = 0;
  virtual void PressKey9() = 0;
  virtual void SwitchToggle() = 0;

//  virtual void MachinePowerOn() = 0;
//  virtual void MachinePowerOff() = 0;
  virtual void VerticalFeedMotorOn() = 0;
  virtual void VerticalFeedMotorOff() = 0;
  virtual void ToolLiftUp() = 0;
  virtual void ToolLiftDown() = 0;
  virtual void ToolLiftStop() = 0;
  virtual void ToolRotateRun() = 0;
  virtual void ToolRotateStop() = 0;
  virtual void ToolStop() = 0;

  virtual void KeyEventHandler(KeyIdentificator keyIdent) = 0;

};

#endif /* INTERFACES_ICONTROLLER_HPP_ */
