/*
 * main.cpp
 *
 *  Created on: 19 мар. 2020 г.
 *      Author: borzenkov
 */

#include <iostream>

#include "../Model/machine.hpp"
#include "../Model/Controller.hpp"


int main()
{
	cMachine machine;
	cController controller(&machine);

	std::cout << "-> Machine is create!!! <-" << std::endl;

}


