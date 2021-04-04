// работа
#ifndef _STATE_WORKING_HPP_
#define _STATE_WORKING_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iState.hpp"
#include "AllStates.hpp"
#include "../Model/Controller.hpp"


class cStateWorking : public iState
{
public:
  cStateWorking();
  virtual ~cStateWorking();
  
  virtual void run(void *params);

};

#endif /* _STATE_WORKING_HPP_ */
