#include "ProtocolFormer.hpp"

#define PACKET_BEGIN_SIGN		(uint8_t)'<'
#define PACKET_END_SIGN			(uint8_t)'>'

cProtocolFormer::cProtocolFormer(cByteSender *pByteSender):
m_pByteSender(pByteSender)
{

}
// ----------------------------------------------------------------------------
cProtocolFormer::~cProtocolFormer()
{
	
}
// ----------------------------------------------------------------------------
void cProtocolFormer::run()
{

}
// ----------------------------------------------------------------------------
// реализация методов  интерфейса iView
void cProtocolFormer::SendCurrentPosition(uint32_t position)
{
	PacketFormingAndSend(CurrentPosition, position);
}
// ----------------------------------------------------------------------------
void cProtocolFormer::PacketFormingAndSend(teSendingParam param, uint32_t data)
{
	m_pByteSender->AddItem(PACKET_BEGIN_SIGN);
	
	m_pByteSender->AddItem(PACKET_END_SIGN);
}
// ----------------------------------------------------------------------------
