/*
 * machine.hpp
 *
 *  Created on: 19 мар. 2020 г.
 *      Author: borzenkov
 */

#ifndef MODEL_MACHINE_HPP_
#define MODEL_MACHINE_HPP_

#include <stdint.h>
#include <stddef.h>
//#include <iostream>

#include "../Drivers/AnalogInput.hpp"
#include "../Drivers/DigitalInput.hpp"
#include "../Drivers/DigitalOut.hpp"
#include "../Interfaces/iProcess.hpp"

//namespace Machine
//{
enum MachineEvent
{
  evUpperTipReached,
  evLowerTipReached,
  evAnyError
};

enum MachineStates
{
  machineError,
  machineOk,
  machineStateNone
};

enum ToolStates
{
  toolNotInitialazed,
  toolInitialazed,
  toolErrorInitialized,
  toolErrorUpperTip,
  toolErrorLowerTip,
  toolErrorPositionSensor,
  toolStateNone
};

typedef struct
{
  cDigitalOut *MachinePowerSwitch;
  cDigitalOut *VerticalFeedMotorSwitch;
  cDigitalOut *RotatedMotorToolSwitch;
  cDigitalOut *ToolLiftUpSwitch;
  cDigitalOut *ToolLiftDownSwich;

  cDigitalInput *UpperToolTip;
  cDigitalInput *MiddleToolTip;
  cDigitalInput *LowerToolTip;

  cAnalogInput *ToolPositionSensor;
  cAnalogInput *CurrentSensor;
} t_MachineInitStruct;

//}

class cMachine : public iProcess
{
public:

  cMachine();
  ~cMachine();

  void Init(t_MachineInitStruct initStruct);
  virtual void run();

  void MachinePowerOn();
  void MachinePowerOff();
  void VerticalFeedMotorOn();
  void VerticalFeedMotorOff();
  void ToolLiftUp();
  void ToolLiftDown();
  void ToolLiftStop();
  void ToolRotateRun();
  void ToolRotateStop();
  void ToolStop();

  bool ToolIsRotate();
  bool ToolIsLiftUp();
  bool ToolIsLiftDown();
  bool ToolIsStoped();

  uint32_t GetCurrentPosition()const;
  uint32_t GetCurrent()const;
  uint32_t GetUpperToolTipState()const;
  uint32_t GetLowerToolTipState()const;

  void SetErrorCallback(void (*ControllerEventCallback)(MachineEvent event));

//  void SetPositionSensor(cAnalogInput *posSens);
//  void SetCurrentSensor(cAnalogInput *curSens);

private:
  MachineStates m_MachineState;
  ToolStates m_ToolState;
  int32_t m_CurrentPosition;   // текущая позиция, мм
  uint32_t m_UpperToolPosition; // верхнее положение инсрумента(размерность АЦП)
  uint32_t m_LowerToolPosition; // нижнее положение инсрумента(размерность АЦП)
  float m_PositionScale;        // коэф пересчёта АЦП в мм
  uint32_t m_ToolTraectoryLen;  // длина хода инструмента, мм

  cDigitalOut *m_MachinePowerSwitch;
  cDigitalOut *m_VerticalFeedMotorSwitch;
  cDigitalOut *m_RotatedMotorToolSwitch;
  cDigitalOut *m_ToolLiftUpSwitch;
  cDigitalOut *m_ToolLiftDownSwich;

  cDigitalInput *m_UpperToolTip;
  cDigitalInput *m_MiddlerToolTip;
  cDigitalInput *m_LowerToolTip;

  cAnalogInput *m_ToolPositionSensor;
  cAnalogInput *m_CurrentSensor;

  void (*ControllerEventCallback)(MachineEvent event);

  void CalcPositionScale();
  void CalcCurrentPosition();
};

#endif /* MODEL_MACHINE_HPP_ */
