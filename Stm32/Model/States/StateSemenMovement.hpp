// работа
#ifndef _STATE_SEMEN_MOVEMENT_HPP_
#define _STATE_SEMEN_MOVEMENT_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iState.hpp"
//#include "../Model/States/StateGeneralStop.hpp"
#include "../Model/Controller.hpp"
#include "../../Model/States/AllStates.hpp"


class cStateSemenMovement : public iState
{
public:
  cStateSemenMovement();
  virtual ~cStateSemenMovement();
  
  virtual void run(void *params);

};

#endif /* _STATE_SEMEN_MOVEMENT_HPP_ */
