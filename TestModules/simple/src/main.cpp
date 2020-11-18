//============================================================================
// Name        : simple.cpp
// Author      : Aleksey
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "cKeysReader.h"
#include "DigitalInput.hpp"
#include "DigitalOut.hpp"

using namespace std;

class MDR_PORT
{
	public:
		uint32_t value;
		string name;

		MDR_PORT(string &name):
			value(0),
			name(name)
		{ }
		~MDR_PORT(){}

		void SetValue(uint32_t value)
		{
			this->value = value;
//			cout << name << ": " << value << endl;
		}
};

string UncnownPortStr = "Uncnown port";

string PortInStr = "PORT_IN";
MDR_PORT PORT_IN(PortInStr);
cDigitalInput col_0;
cDigitalInput col_1;
cDigitalInput col_2;
cDigitalInput col_3;

string PortOutStr = "PORT_OUT";
MDR_PORT PORT_OUT(PortOutStr);
cDigitalOut row_0;
cDigitalOut row_1;
cDigitalOut row_2;
cDigitalOut row_3;

cKeysReader keysReader;

void SwitchCallback(void *port, uint16_t pinNumber, bool hi_lo)
{
//	string str = PORT_OUT.name;
//	cout << "SwitchCallback.port:" << str << "; pinNumber:" << pinNumber << "; hi_lo:" << hi_lo << endl;
}

bool CheckStateCallback(void *port, uint16_t pinNumber)
{
	bool res = (PORT_IN.value & (uint32_t)(1<<pinNumber)) == (uint32_t)(1<<pinNumber);
//	string str = PORT_IN.name;
//	cout << "CheckStateCallback.port:" << str << "; pinNumber:" << pinNumber << "; res:" << res << endl;
	return res;
}

void SetupKeys()
{
	row_0.Init(&PORT_OUT, 0, false);
	row_1.Init(&PORT_OUT, 1, false);
	row_2.Init(&PORT_OUT, 2, false);
	row_3.Init(&PORT_OUT, 3, false);
	row_0.SetDoSwitchCallback(SwitchCallback);
	row_1.SetDoSwitchCallback(SwitchCallback);
	row_2.SetDoSwitchCallback(SwitchCallback);
	row_3.SetDoSwitchCallback(SwitchCallback);

	col_0.Init(&PORT_IN, 0, false);
	col_1.Init(&PORT_IN, 1, false);
	col_2.Init(&PORT_IN, 2, false);
	col_3.Init(&PORT_IN, 3, false);
	col_0.SetCheckStateCallback(CheckStateCallback);
	col_1.SetCheckStateCallback(CheckStateCallback);
	col_2.SetCheckStateCallback(CheckStateCallback);
	col_3.SetCheckStateCallback(CheckStateCallback);

	keysReader.SetRowOutput(&row_0, 0);
	keysReader.SetRowOutput(&row_1, 1);
	keysReader.SetRowOutput(&row_2, 2);
	keysReader.SetRowOutput(&row_3, 3);

	keysReader.SetColInput(&col_0, 0);
	keysReader.SetColInput(&col_1, 1);
	keysReader.SetColInput(&col_2, 2);
	keysReader.SetColInput(&col_3, 3);
}

void ReadAllRows(uint32_t keyRow, uint32_t keyCol)
{
	for(int i = 0; i < 4; ++i)
	{
		if(keyRow == (uint32_t)i)
			PORT_IN.SetValue((1<<keyCol));
		else
			PORT_IN.SetValue(0);
		keysReader.run();
	}
}

int main()
{
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	cout << "PORT_OUT.value = " << hex << PORT_OUT.value << endl;
	cout << "PORT_IN.value = " << hex << PORT_IN.value << endl;

	SetupKeys();

	ReadAllRows(3,3);
	keysReader.PrintKeyMatrix();

	ReadAllRows(3,2);
	keysReader.PrintKeyMatrix();

	ReadAllRows(3,1);
	keysReader.PrintKeyMatrix();

	ReadAllRows(3,0);
	keysReader.PrintKeyMatrix();

	return 0;
}
