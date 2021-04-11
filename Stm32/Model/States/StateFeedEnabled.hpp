// подача включена
#ifndef _STATE_FEED_ENABLED_HPP_
#define _STATE_FEED_ENABLED_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iState.hpp"
#include "../Model/Controller.hpp"
#include "../../Model/States/AllStates.hpp"


class cStateFeedEnabled : public iState
{
public:
  cStateFeedEnabled();
  virtual ~cStateFeedEnabled();
  
  virtual void run(void *params);

};

#endif /* _STATE_FEED_ENABLED_HPP_ */
