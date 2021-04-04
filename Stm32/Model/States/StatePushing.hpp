// позиция 0
#ifndef _STATE_PUSHING_HPP_
#define _STATE_PUSHING_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iState.hpp"
#include "../Model/Controller.hpp"
#include "AllStates.hpp"

// толчковый
class cStatePushing : public iState
{
public:
  cStatePushing();
  ~cStatePushing();
  
  virtual void run(void *params);

};

#endif /* _STATE_PUSHING_HPP_ */
