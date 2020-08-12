// позиция 0
#ifndef _STATE_START_HPP_
#define _STATE_START_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iState.hpp"
#include "Controller.hpp"
#include "AllStates.hpp"


class cStatePositionZero : public iState
{
public:
  cStatePositionZero();
  ~cStatePositionZero();
  
  virtual void run(void *params);

};

#endif /* _STATE_START_HPP_ */
