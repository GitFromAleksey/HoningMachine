#ifndef _STATE_START_HPP_
#define _STATE_START_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iState.hpp"
#include "Controller.hpp"


class cStateStart : public iState
{
public:
  cStateStart();
  ~cStateStart();
  
  virtual void run(void *params);

};

#endif /* _STATE_START_HPP_ */
