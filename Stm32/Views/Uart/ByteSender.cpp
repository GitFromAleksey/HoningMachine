#include "ByteSender.hpp"

cByteSender::cByteSender(uint16_t bufSize) :
cQueue(bufSize),
SendByteCallback(NULL)
{
	
}
// ----------------------------------------------------------------------------
cByteSender::~cByteSender()
{
	
}
// ----------------------------------------------------------------------------
void cByteSender::run()
{
	if(SendByteCallback == NULL)
		return;
	
	if(IsData())
	{
		uint8_t data = GetItem();
		SendByteCallback(&data);
	}
}
// ----------------------------------------------------------------------------
void cByteSender::AddOutputData(uint8_t *data, uint8_t size)
{
	while(size-- > 0)
	{
		AddItem(*data);
	}
}
// ----------------------------------------------------------------------------
void cByteSender::SetSendByteCallback(bool (*SendByteCallback)(uint8_t *data))
{
	this->SendByteCallback = SendByteCallback;
}
// ----------------------------------------------------------------------------
