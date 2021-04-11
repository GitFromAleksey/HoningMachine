#ifndef _ALL_STATES_H_
#define _ALL_STATES_H_

#include "../Interfaces/iState.hpp"

#include "../../Model/States/StateFastReturnToOperation.hpp"
#include "../../Model/States/StateFeedEnabled.hpp"
#include "../../Model/States/StateFeedIsDisabled.hpp"
#include "../../Model/States/StateGeneralStop.hpp"
#include "../../Model/States/StateHandHeld.hpp"
#include "../../Model/States/StatePositionZero.hpp"
#include "../../Model/States/StateRangeSetting.hpp"
#include "../../Model/States/StateSemenMovement.hpp"
#include "../../Model/States/StateSlowSpeed.hpp"
#include "../../Model/States/StateWorking.hpp"
#include "../../Model/States/StatePushing.hpp"


class cStateFastReturnToOperation;
class cStateFeedEnabled;
class cStateFeedIsDisabled;
class cStateGeneralStop;
class cStateHandleHeld;
class cStatePositionZero;
class cStateRangeSetting;
class cStateSemenMovement;
class cStateSlowSpeed;
class cStateWorking;
class cStatePushing;

extern cStateFastReturnToOperation StateFastReturnToOperation;
extern cStateFeedEnabled           StateFeedEnabled;
extern cStateFeedIsDisabled        StateFeedIsDisabled;
extern cStateGeneralStop           StateGeneralStop;
extern cStateHandleHeld            StateHandleHeld;
extern cStatePositionZero          StatePositionZero;
extern cStateRangeSetting          StateRangeSetting;
extern cStateSemenMovement         StateSemenMovement;
extern cStateSlowSpeed             StateSlowSpeed;
extern cStateWorking               StateWorking;
extern cStatePushing               StatePushing;



#endif /* _ALL_STATES_H_ */
