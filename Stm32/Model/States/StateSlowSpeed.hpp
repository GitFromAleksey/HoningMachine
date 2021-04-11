// малый ход
#ifndef _STATE_SLOW_SPEED_HPP_
#define _STATE_SLOW_SPEED_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iState.hpp"
#include "../Model/Controller.hpp"
#include "../../Model/States/AllStates.hpp"


class cStateSlowSpeed : public iState
{
public:
  cStateSlowSpeed();
  virtual ~cStateSlowSpeed();
  
  virtual void run(void *params);

};

#endif /* _STATE_SLOW_SPEED_HPP_ */
