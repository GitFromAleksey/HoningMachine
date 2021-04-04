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
		REQUIRE( sgs->getStateIdentifier() == StateGeneralStop);
		controller.PressKey1();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StatePositionZero);

		sgs = new cStateGeneralStop();
		controller.SetCurrentState(sgs);
		REQUIRE( sgs->getStateIdentifier() == StateGeneralStop);
		controller.PressKey5();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateWorking);

		sgs = new cStateGeneralStop();
		controller.SetCurrentState(sgs);
		REQUIRE( sgs->getStateIdentifier() == StateGeneralStop);
		controller.PressKey8();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateFeedEnabled);
	}

	SECTION("cStatePositionZero test")
	{
		controller.SetCurrentState(new cStatePositionZero());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StatePositionZero);
		controller.SwitchToggle();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateHandHeld);
		controller.SwitchToggle();

		controller.SetCurrentState(new cStatePositionZero());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StatePositionZero);
		controller.PressKey2();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StatePushing);

		controller.SetCurrentState(new cStatePositionZero());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StatePositionZero);
		controller.PressKey4();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateFastReturnToOperation);

		controller.SetCurrentState(new cStatePositionZero());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StatePositionZero);
		controller.PressKey7();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateGeneralStop);
	}

	SECTION("cStateHandHeld test")
	{
		controller.SetCurrentState(new cStateHandleHeld());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateHandHeld);
		controller.PressKey7();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateGeneralStop);

		controller.SetCurrentState(new cStateHandleHeld());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateHandHeld);
		controller.PressKey3();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateRangeSetting);

		controller.SetCurrentState(new cStateHandleHeld());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateHandHeld);
		controller.PressKey4();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateFastReturnToOperation);

		controller.SetCurrentState(new cStateHandleHeld());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateHandHeld);
		controller.PressKey5();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateWorking);

		controller.SetCurrentState(new cStateHandleHeld());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateHandHeld);
		controller.PressKey8();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateFeedEnabled);
	}

	SECTION("cStatePushing test")
	{
		controller.SetCurrentState(new cStatePushing());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StatePushing);
		controller.SwitchToggle();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateHandHeld);
		controller.SwitchToggle();

		controller.SetCurrentState(new cStatePushing());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StatePushing);
		controller.PressKey1();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StatePositionZero);

		controller.SetCurrentState(new cStatePushing());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StatePushing);
		controller.PressKey3();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateRangeSetting);

		controller.SetCurrentState(new cStatePushing());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StatePushing);
		controller.PressKey5();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateWorking);

		controller.SetCurrentState(new cStatePushing());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StatePushing);
		controller.PressKey8();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateFeedEnabled);
	}

	SECTION("cStateFastReturnToOperation test")
	{
		controller.SetCurrentState(new cStateFastReturnToOperation());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateFastReturnToOperation);
		controller.PressKey1();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StatePositionZero);

		controller.SetCurrentState(new cStateFastReturnToOperation());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateFastReturnToOperation);
		controller.SwitchToggle();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateHandHeld);
		controller.SwitchToggle();

		controller.SetCurrentState(new cStateFastReturnToOperation());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateFastReturnToOperation);
		controller.PressKey7();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateGeneralStop);

		controller.SetCurrentState(new cStateFastReturnToOperation());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateFastReturnToOperation);
		controller.PressKey5();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateWorking);

		controller.SetCurrentState(new cStateFastReturnToOperation());
		sgs = controller.GetCurrentState();
		t_state_identifier state = sgs->getStateIdentifier();
		REQUIRE( state == StateFastReturnToOperation);
		controller.PressKey8();
		controller.run();
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateFeedEnabled);
	}

	SECTION("cStateRangeSetting test")
	{
		controller.SetCurrentState(new cStateRangeSetting());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateRangeSetting);
		controller.PressKey1();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == StatePositionZero);

		controller.SetCurrentState(new cStateRangeSetting());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateRangeSetting);
		controller.PressKey7();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == StateGeneralStop);

		controller.SetCurrentState(new cStateRangeSetting());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateRangeSetting);
		controller.PressKey5();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == StateWorking);

		controller.SetCurrentState(new cStateRangeSetting());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateRangeSetting);
		controller.PressKey6();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == StateSemenMovement);

		controller.SetCurrentState(new cStateRangeSetting());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateRangeSetting);
		controller.PressKey8();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == StateFeedEnabled);
	}

	SECTION("cStateRangeSetting test")
	{
		controller.SetCurrentState(new cStateFeedEnabled());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateFeedEnabled);
		controller.PressKey1();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == StatePositionZero);

		controller.SetCurrentState(new cStateFeedEnabled());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateFeedEnabled);
		controller.SwitchToggle();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == StateHandHeld);
		controller.SwitchToggle();

		controller.SetCurrentState(new cStateFeedEnabled());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateFeedEnabled);
		controller.PressKey7();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == StateGeneralStop);

		controller.SetCurrentState(new cStateFeedEnabled());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateFeedEnabled);
		controller.PressKey5();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == StateWorking);
	}

	SECTION("cStateWorking test")
	{
		controller.SetCurrentState(new cStateWorking());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateWorking);
		controller.PressKey1();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == StatePositionZero);

		controller.SetCurrentState(new cStateWorking());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateWorking);
		controller.SwitchToggle();
		controller.run();
		controller.SwitchToggle();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == StateHandHeld);

		controller.SetCurrentState(new cStateWorking());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateWorking);
		controller.PressKey7();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == StateGeneralStop);

		controller.SetCurrentState(new cStateWorking());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateWorking);
		controller.PressKey8();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == StateFeedEnabled);
	}

	SECTION("cStateSemenMovement test")
	{
		controller.SetCurrentState(new cStateSemenMovement());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateSemenMovement);
		controller.PressKey1();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == StatePositionZero);

		controller.SetCurrentState(new cStateSemenMovement());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateSemenMovement);
		controller.SwitchToggle();
		controller.run();
		controller.SwitchToggle();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == StateHandHeld);

		controller.SetCurrentState(new cStateSemenMovement());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateSemenMovement);
		controller.PressKey7();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == StateGeneralStop);

		controller.SetCurrentState(new cStateSemenMovement());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateSemenMovement);
		controller.PressKey5();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == StateWorking);

		controller.SetCurrentState(new cStateSemenMovement());
		sgs = controller.GetCurrentState();
		REQUIRE( sgs->getStateIdentifier() == StateSemenMovement);
		controller.PressKey8();
		controller.run();
		REQUIRE( controller.GetCurrentState()->getStateIdentifier() == StateFeedEnabled);
	}
}
