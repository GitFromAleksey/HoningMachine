#ifndef INTERFACES_STATE_HPP_
#define INTERFACES_STATE_HPP_

#include <stdint.h>

typedef enum
{
  StateFastReturnToOperation,
  StateFeedEnabled,
  StateFeedIsDisabled,
  StateGeneralStop,
  StateHandHeld,
  StatePositionZero,
  StateRangeSetting,
  StateSemenMovement,
  StateSlowSpeed,
  StateWorking,
  StatePushing
} t_state_identifier;

class iState
{
public:
  virtual ~iState(){}
  virtual void run(void *params) = 0;
  t_state_identifier getStateIdentifier()const { return m_StateIdentifier; }
protected:

  t_state_identifier m_StateIdentifier;
};

#endif /* INTERFACES_STATE_HPP_ */
