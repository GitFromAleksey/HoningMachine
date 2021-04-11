// подача отключена
#ifndef _STATE_FEED_IS_DISABLED_HPP_
#define _STATE_FEED_IS_DISABLED_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iState.hpp"
#include "../Model/Controller.hpp"
#include "../../Model/States/AllStates.hpp"


class cStateFeedIsDisabled : public iState
{
public:
  cStateFeedIsDisabled();
  virtual ~cStateFeedIsDisabled();
  
  virtual void run(void *params);

};

#endif /* _STATE_FEED_IS_DISABLED_HPP_ */
