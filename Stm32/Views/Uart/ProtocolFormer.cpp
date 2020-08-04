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
void cProtocolFormer::SendCurrentPosition(uint32_t data)
{
	PacketFormingAndSend(paramTypeCurrentToolPosition, data);
}
// ----------------------------------------------------------------------------
void cProtocolFormer::SendCurrent(uint32_t data)
{
	PacketFormingAndSend(paramTypeCurrentSensor, data);
}
// ----------------------------------------------------------------------------
void cProtocolFormer::SendUpperToolTipState(uint32_t data)
{
	PacketFormingAndSend(paramTypeUpperToolTipState, data);
}	
// ----------------------------------------------------------------------------
void cProtocolFormer::SendLowerToolTipState(uint32_t data)
{
	PacketFormingAndSend(paramTypeLowerToolTipState, data);
}
// ----------------------------------------------------------------------------
void cProtocolFormer::PacketFormingAndSend(eSendingParamType param, uint32_t data)
{
	uint8_t cnt = 0;
	uint8_t *pProtocol = NULL;
	t_out_protocol protocol;
	
	protocol.DeviceNumber = 1;
	protocol.ParamType = param;
	protocol.Data = data;
	protocol.CRC8 = 0xAA;
	
	m_pByteSender->AddItem(PACKET_BEGIN_SIGN);
	
	cnt = sizeof(protocol.DeviceNumber);
	pProtocol = (uint8_t*)&protocol.DeviceNumber;
	while(cnt--){m_pByteSender->AddItem(*pProtocol++);}
	
	cnt = sizeof(protocol.ParamType);
	pProtocol = (uint8_t*)&protocol.ParamType;
	while(cnt--){m_pByteSender->AddItem(*pProtocol++);}

	cnt = sizeof(protocol.Data);
	pProtocol = (uint8_t*)&protocol.Data;
	while(cnt--){m_pByteSender->AddItem(*pProtocol++);}
	
	cnt = sizeof(protocol.CRC8);
	pProtocol = (uint8_t*)&protocol.CRC8;
	while(cnt--){m_pByteSender->AddItem(*pProtocol++);}	
	
	m_pByteSender->AddItem(PACKET_END_SIGN);
}
// ----------------------------------------------------------------------------
