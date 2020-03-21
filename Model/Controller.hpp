#ifndef MODEL_CONTROLLER_HPP_
#define MODEL_CONTROLLER_HPP_

#include <iostream>
#include "../Interfaces/iController.hpp"
#include "../Model/machine.hpp"

class cController : public iController
{
public:
	cController();
	cController(cMachine *machine);
	~cController();

	void AddMachine(cMachine *machine);

private:
	cMachine *m_Machine;
};

#endif /* MODEL_CONTROLLER_HPP_ */
