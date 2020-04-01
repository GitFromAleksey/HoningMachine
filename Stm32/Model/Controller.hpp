#ifndef MODEL_CONTROLLER_HPP_
#define MODEL_CONTROLLER_HPP_

//#include <iostream>
#include <stddef.h>
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

	// реализация методов интерфейса iController
	virtual void MachinePowerOn();
	virtual void MachinePowerOff();
	virtual void ToolLiftUp();
	virtual void ToolLiftDown();
	virtual void ToolLiftStop();
	virtual void ToolRotateRun();
	virtual void ToolRotateStop();
	virtual void ToolStop();

private:
	cMachine *m_Machine;
};

#endif /* MODEL_CONTROLLER_HPP_ */
