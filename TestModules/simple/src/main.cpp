//============================================================================
// Name        : simple.cpp
// Author      : Aleksey
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "DigitalInput.hpp"
#include "DigitalOut.hpp"
#include "../../../Stm32/Interfaces/iController.hpp"
#include "cController.h"
#include "KeyReader/cKeysReader.h"
#include "KeyReader/cKeyBind.h"

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

cKeysReader KeysReader;
cController MachineController;
cKeyBind KeysArray[4*4];

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

// конфигурация класса опроса клавиатуры
void SetupKeyReader(cKeyBind *keysArray, uint8_t size)
{
// конфигурация дискретных выходов рядов
	row_0.Init(&PORT_OUT, 0, false);
	row_1.Init(&PORT_OUT, 1, false);
	row_2.Init(&PORT_OUT, 2, false);
	row_3.Init(&PORT_OUT, 3, false);
	row_0.SetDoSwitchCallback(SwitchCallback);
	row_1.SetDoSwitchCallback(SwitchCallback);
	row_2.SetDoSwitchCallback(SwitchCallback);
	row_3.SetDoSwitchCallback(SwitchCallback);

// конфигурация дискретных входов колонок
	col_0.Init(&PORT_IN, 0, false);
	col_1.Init(&PORT_IN, 1, false);
	col_2.Init(&PORT_IN, 2, false);
	col_3.Init(&PORT_IN, 3, false);
	col_0.SetCheckStateCallback(CheckStateCallback);
	col_1.SetCheckStateCallback(CheckStateCallback);
	col_2.SetCheckStateCallback(CheckStateCallback);
	col_3.SetCheckStateCallback(CheckStateCallback);

// добавление рядов в класс опроса клавиатуры
	KeysReader.SetRowOutput(&row_0, 0);
	KeysReader.SetRowOutput(&row_1, 1);
	KeysReader.SetRowOutput(&row_2, 2);
	KeysReader.SetRowOutput(&row_3, 3);
// добавление колонок в класс опроса клавиатуры
	KeysReader.SetColInput(&col_0, 0);
	KeysReader.SetColInput(&col_1, 1);
	KeysReader.SetColInput(&col_2, 2);
	KeysReader.SetColInput(&col_3, 3);
// добавление массива настроенных кнопок в класс считывателя
	KeysReader.AddKeysArray(keysArray, size);
}

// настройка кнопок(связь положения кнопки в матрице с методом контроллера станка)
void SetupKeysArray()
{
	uint8_t i = 0;

	// 0-й ряд кнопок
	KeysArray[i++].Init(0, 0, pressKey1, &MachineController);
	KeysArray[i++].Init(0, 1, pressKey2, &MachineController);
	KeysArray[i++].Init(0, 2, pressKey3, &MachineController);
	KeysArray[i++].Init(0, 3, pressKey4, &MachineController);
	// 1-й ряд кнопок
	KeysArray[i++].Init(1, 0, pressKey5, &MachineController);
	KeysArray[i++].Init(1, 1, pressKey6, &MachineController);
	KeysArray[i++].Init(1, 2, pressKey7, &MachineController);
	KeysArray[i++].Init(1, 3, pressKey8, &MachineController);
	// 2-й ряд кнопок
	KeysArray[i++].Init(2, 0, pressKey9, &MachineController);
	KeysArray[i++].Init(2, 1, switchToggle, &MachineController);
	KeysArray[i++].Init(2, 2, machinePowerOn, &MachineController);
	KeysArray[i++].Init(2, 3, machinePowerOff, &MachineController);
	// 3-й ряд кнопок
	KeysArray[i++].Init(3, 0, verticalFeedMotorOn, &MachineController);
	KeysArray[i++].Init(3, 1, verticalFeedMotorOff, &MachineController);
	KeysArray[i++].Init(3, 2, toolLiftUp, &MachineController);
	KeysArray[i++].Init(3, 3, toolLiftDown, &MachineController);
}

void ReadAllRows(uint32_t keyRow, uint32_t keyCol)
{
	for(int i = 0; i < 4; ++i)
	{
		if(keyRow == (uint32_t)i)
			PORT_IN.SetValue((1<<keyCol));
		else
			PORT_IN.SetValue(0);
		KeysReader.run();
	}
}

int main()
{
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	cout << "PORT_OUT.value = " << hex << PORT_OUT.value << endl;
	cout << "PORT_IN.value = " << hex << PORT_IN.value << endl;

	SetupKeysArray();
	SetupKeyReader(KeysArray, sizeof(KeysArray)/sizeof(cKeyBind));


	ReadAllRows(3,3);

	ReadAllRows(3,2);

	ReadAllRows(3,1);

	ReadAllRows(3,0);

	ReadAllRows(3,3);

	return 0;
}
