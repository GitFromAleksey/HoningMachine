// ручной
#ifndef _STATE_HANDLE_HELD_HPP_
#define _STATE_HANDLE_HELD_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iState.hpp"
#include "../Model/Controller.hpp"
#include "../../Model/States/AllStates.hpp"


class cStateHandleHeld : public iState
{
public:
  cStateHandleHeld();
  virtual ~cStateHandleHeld();
  
  virtual void run(void *params);

};

#endif /* _STATE_HANDLE_HELD_HPP_ */
