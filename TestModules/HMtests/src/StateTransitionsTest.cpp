#include "../catch2/catch.hpp"

#define STATE_TRANSITION_TEST

#include "../Model/Controller.hpp"

TEST_CASE("States test")
{
//	t_MachineInitStruct machineInit;
//	machineInit.CurrentSensor = NULL;
//	machineInit.LowerToolTip = NULL;
//	machineInit.MiddleToolTip = NULL;
//	machineInit.RotatedMotorToolSwitch = NULL;
//	machineInit.ToolLiftDownSwich = NULL;
//	machineInit.ToolLiftUpSwitch = NULL;
//	machineInit.ToolPositionSensor = NULL;
//	machineInit.UpperToolTip = NULL;
//	machineInit.VerticalFeedMotorSwitch = NULL;
//
//	cMachine machine;
//	machine.Init(machineInit);

	cController controller;
	controller.AddMachine(NULL);

	iState *sgs;

	SECTION("cStateGeneralStop test")
	{
		sgs = new cStateGeneralStop();
		controller.SetCurrentState(sgs);
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateGeneralStop);
		controller.PressKey1();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStatePositionZero);

		sgs = new cStateGeneralStop();
		controller.SetCurrentState(sgs);
		REQUIRE( sgs->getStateIdentifier() == eStateGeneralStop);
		controller.PressKey5();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateWorking);

		sgs = new cStateGeneralStop();
		controller.SetCurrentState(sgs);
		REQUIRE( sgs->getStateIdentifier() == eStateGeneralStop);
		controller.PressKey8();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateFeedEnabled);
	}

	SECTION("cStatePositionZero test")
	{
		controller.SetCurrentState(new cStatePositionZero());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStatePositionZero);
		controller.SwitchToggle();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateHandHeld);
		controller.SwitchToggle();

		controller.SetCurrentState(new cStatePositionZero());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStatePositionZero);
		controller.PressKey2();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStatePushing);

		controller.SetCurrentState(new cStatePositionZero());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStatePositionZero);
		controller.PressKey4();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateFastReturnToOperation);

		controller.SetCurrentState(new cStatePositionZero());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStatePositionZero);
		controller.PressKey7();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateGeneralStop);
	}

	SECTION("cStateHandHeld test")
	{
		controller.SetCurrentState(new cStateHandleHeld());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateHandHeld);
		controller.PressKey7();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateGeneralStop);

		controller.SetCurrentState(new cStateHandleHeld());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateHandHeld);
		controller.PressKey3();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateRangeSetting);

		controller.SetCurrentState(new cStateHandleHeld());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateHandHeld);
		controller.PressKey4();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateFastReturnToOperation);

		controller.SetCurrentState(new cStateHandleHeld());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateHandHeld);
		controller.PressKey5();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateWorking);

		controller.SetCurrentState(new cStateHandleHeld());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateHandHeld);
		controller.PressKey8();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateFeedEnabled);
	}

	SECTION("cStatePushing test")
	{
		controller.SetCurrentState(new cStatePushing());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStatePushing);
		controller.SwitchToggle();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateHandHeld);
		controller.SwitchToggle();

		controller.SetCurrentState(new cStatePushing());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStatePushing);
		controller.PressKey1();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStatePositionZero);

		controller.SetCurrentState(new cStatePushing());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStatePushing);
		controller.PressKey3();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateRangeSetting);

		controller.SetCurrentState(new cStatePushing());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStatePushing);
		controller.PressKey5();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateWorking);

		controller.SetCurrentState(new cStatePushing());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStatePushing);
		controller.PressKey8();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateFeedEnabled);
	}

	SECTION("cStateFastReturnToOperation test")
	{
		controller.SetCurrentState(new cStateFastReturnToOperation());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateFastReturnToOperation);
		controller.PressKey1();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStatePositionZero);

		controller.SetCurrentState(new cStateFastReturnToOperation());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateFastReturnToOperation);
		controller.SwitchToggle();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateHandHeld);
		controller.SwitchToggle();

		controller.SetCurrentState(new cStateFastReturnToOperation());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateFastReturnToOperation);
		controller.PressKey7();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateGeneralStop);

		controller.SetCurrentState(new cStateFastReturnToOperation());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateFastReturnToOperation);
		controller.PressKey5();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateWorking);

		controller.SetCurrentState(new cStateFastReturnToOperation());
		sgs = controller.GetCurrentState();
		t_state_identifier state = sgs->getStateIdentifier();
		REQUIRE( state == eStateFastReturnToOperation);
		controller.PressKey8();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateFeedEnabled);
	}

	SECTION("cStateRangeSetting test")
	{
		controller.SetCurrentState(new cStateRangeSetting());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateRangeSetting);
		controller.PressKey1();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == eStatePositionZero);

		controller.SetCurrentState(new cStateRangeSetting());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateRangeSetting);
		controller.PressKey7();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == eStateGeneralStop);

		controller.SetCurrentState(new cStateRangeSetting());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateRangeSetting);
		controller.PressKey5();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == eStateWorking);

		controller.SetCurrentState(new cStateRangeSetting());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateRangeSetting);
		controller.PressKey6();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == eStateSemenMovement);

		controller.SetCurrentState(new cStateRangeSetting());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateRangeSetting);
		controller.PressKey8();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == eStateFeedEnabled);
	}

	SECTION("cStateRangeSetting test")
	{
		controller.SetCurrentState(new cStateFeedEnabled());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateFeedEnabled);
		controller.PressKey1();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == eStatePositionZero);

		controller.SetCurrentState(new cStateFeedEnabled());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateFeedEnabled);
		controller.SwitchToggle();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == eStateHandHeld);
		controller.SwitchToggle();

		controller.SetCurrentState(new cStateFeedEnabled());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateFeedEnabled);
		controller.PressKey7();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == eStateGeneralStop);

		controller.SetCurrentState(new cStateFeedEnabled());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateFeedEnabled);
		controller.PressKey5();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == eStateWorking);
	}

	SECTION("cStateWorking test")
	{
		controller.SetCurrentState(new cStateWorking());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateWorking);
		controller.PressKey1();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == eStatePositionZero);

		controller.SetCurrentState(new cStateWorking());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateWorking);
		controller.SwitchToggle();
		controller.run();
		controller.SwitchToggle();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == eStateHandHeld);

		controller.SetCurrentState(new cStateWorking());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateWorking);
		controller.PressKey7();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == eStateGeneralStop);

		controller.SetCurrentState(new cStateWorking());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateWorking);
		controller.PressKey8();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == eStateFeedEnabled);
	}

	SECTION("cStateSemenMovement test")
	{
		controller.SetCurrentState(new cStateSemenMovement());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateSemenMovement);
		controller.PressKey1();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == eStatePositionZero);

		controller.SetCurrentState(new cStateSemenMovement());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateSemenMovement);
		controller.SwitchToggle();
		controller.run();
		controller.SwitchToggle();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == eStateHandHeld);

		controller.SetCurrentState(new cStateSemenMovement());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateSemenMovement);
		controller.PressKey7();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == eStateGeneralStop);

		controller.SetCurrentState(new cStateSemenMovement());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateSemenMovement);
		controller.PressKey5();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == eStateWorking);

		controller.SetCurrentState(new cStateSemenMovement());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == eStateSemenMovement);
		controller.PressKey8();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == eStateFeedEnabled);
	}
}
