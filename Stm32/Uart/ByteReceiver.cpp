#include "ByteReceiver.hpp"

cByteReceiver::cByteReceiver() :
m_Queue(NULL),
GetByteCallback(NULL)
{

}
cByteReceiver::cByteReceiver(uint16_t bufSize) :
m_Queue(NULL),
GetByteCallback(NULL)
{
	m_Queue = new cQueue(bufSize);
}
// ----------------------------------------------------------------------------
cByteReceiver::~cByteReceiver()
{
	
}
// ----------------------------------------------------------------------------
void cByteReceiver::run()
{
	uint8_t receiveData = 0;
	if(this->GetByteCallback != NULL)
		if(this->GetByteCallback(&receiveData))
			QueueAddData(receiveData);
}
// ----------------------------------------------------------------------------
void cByteReceiver::SetByteCalback(bool (*GetByteCallback)(uint8_t *data))
{
	if(GetByteCallback != NULL)
	{
		this->GetByteCallback = GetByteCallback;
	}
}
// ----------------------------------------------------------------------------
void cByteReceiver::CreateReceiveArray(uint16_t size)
{

}
// ----------------------------------------------------------------------------
void cByteReceiver::QueueAddData(uint8_t data)
{
	m_Queue->AddItem(data);
}
// ----------------------------------------------------------------------------
uint8_t cByteReceiver::QueueGetData()
{
	return m_Queue->GetItem();
}
