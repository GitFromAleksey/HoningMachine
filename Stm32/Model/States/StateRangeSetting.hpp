// установка диапазона
#ifndef _STATE_RANGE_SETTING_HPP_
#define _STATE_RANGE_SETTING_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iState.hpp"
#include "StateGeneralStop.hpp"
#include "../Model/Controller.hpp"


class cStateRangeSetting : public iState
{
public:
  cStateRangeSetting();
  ~cStateRangeSetting();
  
  virtual void run(void *params);

};

#endif /* _STATE_RANGE_SETTING_HPP_ */
