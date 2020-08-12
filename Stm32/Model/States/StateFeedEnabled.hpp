// подача включена
#ifndef _STATE_FEED_ENABLED_HPP_
#define _STATE_FEED_ENABLED_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iState.hpp"
#include "StateGeneralStop.hpp"
#include "Controller.hpp"


class cStateFeedEnabled : public iState
{
public:
  cStateFeedEnabled();
  ~cStateFeedEnabled();
  
  virtual void run(void *params);

};

#endif /* _STATE_FEED_ENABLED_HPP_ */
