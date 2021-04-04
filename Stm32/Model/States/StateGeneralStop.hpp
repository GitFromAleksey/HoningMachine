// Общий СТОП
#ifndef _STATE_GENERAL_STOP_HPP_
#define _STATE_GENERAL_STOP_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iState.hpp"
#include "../Model/Controller.hpp"


class cStateGeneralStop : public iState
{
public:
  cStateGeneralStop();
  virtual ~cStateGeneralStop();
  
  virtual void run(void *params);

};

#endif /* _STATE_GENERAL_STOP_HPP_ */
