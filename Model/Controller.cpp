#include "Controller.hpp"

cController::cController() : m_Machine(NULL)
{
	//std::cout << "cController()" << std::endl;
}
// ----------------------------------------------------------------------------
cController::cController(cMachine *machine)
{
	AddMachine(machine);
//	std::cout << "cController(cMachine *machine)" << std::endl;
}
// ----------------------------------------------------------------------------
cController::~cController()
{

}
// ----------------------------------------------------------------------------
void cController::AddMachine(cMachine *machine)
{
	if(machine != NULL)
		m_Machine = machine;
}
// ----------------------------------------------------------------------------
void cController::run()
{
	if(m_Machine == NULL)
		return;

	m_Machine->run();
}
// ----------------------------------------------------------------------------
void cController::EventsHandler(MacineEvent event)
{
	switch(event)
	{
	case evUpperTipReached:
		break;
	case evLowerTipReached:
		break;

	default:
		break;
	}
}
