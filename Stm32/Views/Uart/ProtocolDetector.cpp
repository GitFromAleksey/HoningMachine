#include "ProtocolDetector.hpp"

#define PACKET_BEGIN_SIGN		(uint8_t)'<'
#define PACKET_END_SIGN			(uint8_t)'>'

#define PROTOCOL_CMD_READ_RO_REG			3
#define PROTOCOL_CMD_WRITE_RW_REG			4
#define PROTOCOL_CMD_READ_RW_REG			5

#define PROTOCOL_CMD_MACHINE_PWR_ON		6
#define PROTOCOL_CMD_MACHINE_PWR_OFF	7
#define PROTOCOL_CMD_TOOL_LIFT_UP			8
#define PROTOCOL_CMD_TOOL_LIFT_DOWN		9
#define PROTOCOL_CMD_TOOL_LIFT_STOP		10
#define PROTOCOL_CMD_TOOL_ROTATE_RUN	11
#define PROTOCOL_CMD_TOOL_ROTATE_STOP	12
#define PROTOCOL_CMD_TOOL_STOP				13
#define PROTOCOL_CMD_VERTICAL_FEED_MOTOR_ON		14
#define PROTOCOL_CMD_VERTICAL_FEED_MOTOR_OFF	15

cProtocolDetector::cProtocolDetector(cByteReceiver *byteReceiver, 
																		iController *machineController) :
m_ByteReceiver(NULL),
m_ArrayCnt(0),
m_IsPacketBegin(false),
m_MachineController(NULL)
{
	this->m_ByteReceiver = byteReceiver;
	this->m_MachineController = machineController;
}
// ----------------------------------------------------------------------------
cProtocolDetector::~cProtocolDetector()
{
	
}
// ----------------------------------------------------------------------------	
void cProtocolDetector::run()
{
	if(m_ByteReceiver == NULL)
		return;

	uint8_t tmp = m_ByteReceiver->QueueGetData();

	if(tmp == PACKET_BEGIN_SIGN)
	{
		m_IsPacketBegin = true;
		m_ArrayCnt = 0;
		m_Array[m_ArrayCnt++] = tmp;
		return;
	}
	
	if(m_IsPacketBegin)
	{
		m_Array[m_ArrayCnt++] = tmp;

		if(tmp == PACKET_END_SIGN)
		{
			// TODO обработка полученных данных
			m_IsPacketBegin = false;
			PacketParse(&m_Array[1]);
		}
		if(m_ArrayCnt == m_ArraySize)
		{
			m_ArrayCnt = 0;
			m_IsPacketBegin = false;
		}
	}
	
}
// ----------------------------------------------------------------------------
void cProtocolDetector::PacketParse(uint8_t *pData)
{
	volatile t_protocol *prot = NULL;
	prot = (t_protocol *)pData;

	switch(prot->CMD)
	{
		case PROTOCOL_CMD_READ_RO_REG:
			
			break;
		case PROTOCOL_CMD_WRITE_RW_REG:
			
			break;
		case PROTOCOL_CMD_READ_RW_REG:
			
			break;
		
		case PROTOCOL_CMD_MACHINE_PWR_ON:
			m_MachineController->MachinePowerOn();
			break;
		case PROTOCOL_CMD_MACHINE_PWR_OFF:
			m_MachineController->MachinePowerOff();
			break;
		case PROTOCOL_CMD_TOOL_LIFT_UP:
			m_MachineController->ToolLiftUp();
			break;
		case PROTOCOL_CMD_TOOL_LIFT_DOWN:
			m_MachineController->ToolLiftDown();
			break;
		case PROTOCOL_CMD_TOOL_LIFT_STOP:
			m_MachineController->ToolLiftStop();
			break;
		case PROTOCOL_CMD_TOOL_ROTATE_RUN:
			m_MachineController->ToolRotateRun();
			break;
		case PROTOCOL_CMD_TOOL_ROTATE_STOP:
			m_MachineController->ToolRotateStop();
			break;
		case PROTOCOL_CMD_TOOL_STOP:
			m_MachineController->ToolStop();
			break;
		case PROTOCOL_CMD_VERTICAL_FEED_MOTOR_ON:
			m_MachineController->VerticalFeedMotorOn();
			break;
		case PROTOCOL_CMD_VERTICAL_FEED_MOTOR_OFF:
			m_MachineController->VerticalFeedMotorOff();
			break;
		default:
			break;
	}
}
// ----------------------------------------------------------------------------
