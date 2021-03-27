//============================================================================
// Name        : HMtests.cpp
// Author      : Aleksey
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch2/catch.hpp"


#include "../Drivers/AnalogInput.hpp"
#include "../Drivers/DigitalInput.hpp"


TEST_CASE("Analog inputs tests")
{
	cAnalogInput ai;

	ai.Init();
	ai.SetScale(1);

	SECTION("AnalogInput test")
	{
		ai.SetDataFromADC(1);

		REQUIRE(ai.GetAverageData() == 0);

		for(int i = 0; i < 511; ++i)
		{
		ai.SetDataFromADC(1);
		}
		REQUIRE(ai.GetAverageData() == 1);
	}
}

bool CheckStateCallback(void *port, uint16_t pinNumber)
{
	if(port != nullptr)
	{
		if(pinNumber == 15)
			{ return true; }
	}

	return false;
}

TEST_CASE("Digital inputs test")
{
	uint32_t any_address = 0;
	void *port = (void*)&any_address;
	uint16_t pinNumber = 15;
	bool inversion = true;
	cDigitalInput di;
	di.SetCheckStateCallback(CheckStateCallback);

	SECTION("DI port == nullptr")
	{
		port = nullptr;
		di.Init(port, pinNumber, inversion);
		di.SetCheckStateCallback(CheckStateCallback);
		di.run();
		REQUIRE(di.IsOn() == false);
	}

	SECTION("DI port != nullptr")
	{
		pinNumber = 15;
		port = (void*)&any_address;
		inversion = false;
		di.Init(port, pinNumber, inversion);
		di.run();
		REQUIRE(di.IsOn() == true);
	}

	SECTION("DI debounce test")
	{
		pinNumber = 15;
		port = (void*)&any_address;
		inversion = false;
		di.Init(port, pinNumber, inversion);
		di.SetDebounceCntValue(3);
		di.run();
		di.run();
		di.run();
		di.run();
		REQUIRE(di.IsOn() == true);
	}
}

#ifndef CATCH_CONFIG_MAIN
int main()
{
	cout << "!!!Honing Machine Tests!!!" << endl;

	REQUIRE(1==0);

	return 0;
}
#endif /* CATCH_CONFIG_MAIN */
