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


//#include "StateFastReturnToOperation.hpp"
//#include "StateFeedEnabled.hpp"
//#include "StateFeedIsDisabled.hpp"
//#include "StateGeneralStop.hpp"
//#include "StateHandHeld.hpp"
//#include "StatePositionZero.hpp"
//#include "StateRangeSetting.hpp"
//#include "StateSemenMovement.hpp"
//#include "StateSlowSpeed.hpp"
//#include "StateWorking.hpp"
//#include "StatePushing.hpp"

//void StatesOfMachineInit();

//cStateFastReturnToOperation StateFastReturnToOperation;


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

//extern iState* StateFastReturnToOperation;
//extern iState* StateFeedEnabled;
//extern iState* StateFeedIsDisabled;
//extern iState* StateGeneralStop;
//extern iState* StateHandleHeld;
//extern iState* StatePositionZero;
//extern iState* StateRangeSetting;
//extern iState* StateSemenMovement;
//extern iState* StateSlowSpeed;
//extern iState* StateWorking;
//extern iState* StatePushing;



#endif /* _ALL_STATES_H_ */
