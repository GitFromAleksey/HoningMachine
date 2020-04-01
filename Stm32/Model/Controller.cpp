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
// ----------------------------------------------------------------------------
// реализация методов интерфейса iController
void cController::MachinePowerOn()
{
	m_Machine->MachinePowerOn();
}
// ----------------------------------------------------------------------------
void cController::MachinePowerOff()
{
	m_Machine->MachinePowerOff();
}
// ----------------------------------------------------------------------------
void cController::ToolLiftUp()
{
	m_Machine->ToolLiftUp();
}
// ----------------------------------------------------------------------------
void cController::ToolLiftDown()
{
	m_Machine->ToolLiftDown();
}
// ----------------------------------------------------------------------------
void cController::ToolLiftStop()
{
	m_Machine->ToolLiftStop();
}
// ----------------------------------------------------------------------------
void cController::ToolRotateRun()
{
	m_Machine->ToolRotateRun();
}
// ----------------------------------------------------------------------------
void cController::ToolRotateStop()
{
	m_Machine->ToolRotateStop();
}
// ----------------------------------------------------------------------------
void cController::ToolStop()
{
	m_Machine->ToolStop();
}
// конец реализации методов интерфейса iController
// ----------------------------------------------------------------------------
