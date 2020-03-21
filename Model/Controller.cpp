#include "Controller.hpp"

cController::cController() : m_Machine(nullptr)
{
	std::cout << "cController()" << std::endl;
}
// ----------------------------------------------------------------------------
cController::cController(cMachine *machine)
{
	AddMachine(machine);
	std::cout << "cController(cMachine machine)" << std::endl;
}
// ----------------------------------------------------------------------------
cController::~cController()
{

}
// ----------------------------------------------------------------------------
void cController::AddMachine(cMachine *machine)
{
	if(machine != nullptr)
		m_Machine = machine;
}
// ----------------------------------------------------------------------------
void cController::run()
{
	if(m_Machine == nullptr)
		return;

	m_Machine->run();
}
// ----------------------------------------------------------------------------
