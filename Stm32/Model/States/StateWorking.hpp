// работа
#ifndef _STATE_WORKING_HPP_
#define _STATE_WORKING_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iState.hpp"
#include "../Model/Controller.hpp"
#include "../../Model/States/AllStates.hpp"


class cStateWorking : public iState
{
public:
  cStateWorking();
  virtual ~cStateWorking();
  
  virtual void run(void *params);

};

#endif /* _STATE_WORKING_HPP_ */
