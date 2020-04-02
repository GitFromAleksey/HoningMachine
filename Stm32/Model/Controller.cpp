#include "Controller.hpp"

cController::cController() : 
m_Ticks(0),
m_TicksSendRepeat(100),
m_Machine(NULL),
m_View(NULL)
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
void cController::AddView(iView *view)
{
	m_View = view;
}
// ----------------------------------------------------------------------------
void  cController::SetGetTicksCallback(uint32_t (*GetTicksCallback)())
{
	this->GetTicksCallback = GetTicksCallback;
}
// ----------------------------------------------------------------------------
void cController::run()
{
	if(m_Machine == NULL)
		return;

	if(GetTicksCallback != NULL)
	{
		if((GetTicksCallback() - m_Ticks) > m_TicksSendRepeat)
		{
			m_Ticks = GetTicksCallback();
			m_View->SendCurrentPosition( m_Machine->GetCurrentPosition());
			m_View->SendCurrent( m_Machine->GetCurrent());
		}
	}
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
