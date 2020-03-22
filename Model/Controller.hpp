#ifndef MODEL_CONTROLLER_HPP_
#define MODEL_CONTROLLER_HPP_

#include <iostream>
#include "../Interfaces/iController.hpp"
#include "../Interfaces/iProcess.hpp"
#include "../Model/machine.hpp"


class cController : public iController, public iProcess
{
public:
	cController();
	cController(cMachine *machine);
	~cController();

	virtual void run();

	void AddMachine(cMachine *machine);

	void EventsHandler(MacineEvent event);

private:
	cMachine *m_Machine;
};

#endif /* MODEL_CONTROLLER_HPP_ */
