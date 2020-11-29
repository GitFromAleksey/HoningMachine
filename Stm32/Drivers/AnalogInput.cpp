#include "AnalogInput.hpp"

cAnalogInput::cAnalogInput() :
m_Scale(1),//(0.2442),
m_DataRaw(0),
m_DataAcc(0),
m_AvgDiv(9),
m_DataAvg(0)
//m_DataScaling(0),
//m_MaxValue(0)
{
//std::cout << "cAnalogInput::cAnalogInput()" << std::endl;
}
// ----------------------------------------------------------------------------
cAnalogInput::~cAnalogInput()
{

}
// ----------------------------------------------------------------------------
void cAnalogInput::run()
{
  // TODO доделать реализацию
}
// ----------------------------------------------------------------------------
void cAnalogInput::Init()
{
  //std::cout << "cAnalogInput::Init()" << std::endl;
}
// ----------------------------------------------------------------------------
void cAnalogInput::SetDataFromADC(uint32_t data)
{
  m_DataRaw = data * m_Scale;
  CalcAverage(m_DataRaw);
}
// ----------------------------------------------------------------------------
uint32_t cAnalogInput::GetAverageData()const
{
  return m_DataAvg;
}
// ----------------------------------------------------------------------------
void cAnalogInput::CalcAverage(uint32_t data)
{
  m_DataAcc -= m_DataAvg;
  m_DataAcc += data;
  m_DataAvg = m_DataAcc>>m_AvgDiv;
}
