#ifndef DRIVERS_ANALOGINPUT_HPP_
#define DRIVERS_ANALOGINPUT_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iProcess.hpp"
//#include <iostream>

class cAnalogInput : public iProcess
{
public:
  cAnalogInput();
  ~cAnalogInput();

  virtual void run();

  void Init();
  void SetDataFromADC(uint32_t data);
  uint32_t GetAverageData()const;

private:
  float m_Scale; // коффициент приведения входного сигнала к единицам измерения
  uint32_t m_DataRaw; // сырые входные данные
  int32_t m_DataAcc; // аккумулятор для рассчёта скользящего среднего
  uint8_t m_AvgDiv; // дедитель для рассчёта скользящего среднего
  uint32_t m_DataAvg; // рассчитанное среднее значение
//  uint32_t m_DataScaling; // TODO не используется
//  uint32_t m_MaxValue; // ограничение максимального значения(пока не мспользуется)

  void CalcAverage(uint32_t data);
  
};

#endif /* DRIVERS_ANALOGINPUT_HPP_ */
