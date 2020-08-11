#ifndef _STATE_START_HPP_
#define _STATE_START_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iState.hpp"
#include "Controller.hpp"


class cStateGeneralStop : public iState
{
public:
  cStateGeneralStop();
  ~cStateGeneralStop();
  
  virtual void run(void *params);

};

#endif /* _STATE_START_HPP_ */
