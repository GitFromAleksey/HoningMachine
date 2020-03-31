#include "ProtocolDetector.hpp"

#define PACKET_BEGIN_SIGN		(uint8_t)'<'
#define PACKET_END_SIGN			(uint8_t)'>'

cProtocolDetector::cProtocolDetector(cByteReceiver *byteReceiver) :
m_ByteReceiver(NULL),
m_ArrayCnt(0),
m_IsPacketBegin(false)
{
	this->m_ByteReceiver = byteReceiver;
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
