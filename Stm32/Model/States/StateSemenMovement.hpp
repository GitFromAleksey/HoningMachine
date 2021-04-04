// работа
#ifndef _STATE_SEMEN_MOVEMENT_HPP_
#define _STATE_SEMEN_MOVEMENT_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iState.hpp"
#include "../Model/States/StateGeneralStop.hpp"
#include "../Model/Controller.hpp"


class cStateSemenMovement : public iState
{
public:
  cStateSemenMovement();
  ~cStateSemenMovement();
  
  virtual void run(void *params);

};

#endif /* _STATE_SEMEN_MOVEMENT_HPP_ */
