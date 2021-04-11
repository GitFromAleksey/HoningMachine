// ускоренный возврат в рабочий ход
#ifndef _STATE_FAST_RETURN_TO_OPERATION_HPP_
#define _STATE_FAST_RETURN_TO_OPERATION_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iState.hpp"
#include "../Model/Controller.hpp"
#include "../../Model/States/AllStates.hpp"

// ускоренный возврат в рабочий ход
class cStateFastReturnToOperation : public iState
{
public:
  cStateFastReturnToOperation();
  virtual ~cStateFastReturnToOperation();
  
  virtual void run(void *params);

};

#endif /* _STATE_FAST_RETURN_TO_OPERATION_HPP_ */
