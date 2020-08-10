#ifndef INTERFACES_STATE_HPP_
#define INTERFACES_STATE_HPP_

#include <stdint.h>

class iState
{
public:

  virtual void run(void *params) = 0;

};

#endif /* INTERFACES_STATE_HPP_ */
