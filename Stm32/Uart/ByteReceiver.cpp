#include "ByteReceiver.hpp"

cByteReceiver::cByteReceiver() :
m_ReceiveData(0),
m_ArraySize(1),
m_ReceiveArray(NULL),
m_ArrayHead(0),
m_ArrayTail(0),
GetByteCallback(NULL)
{
	CreateReceiveArray(m_ArraySize);
}
cByteReceiver::cByteReceiver(uint16_t bufSize) :
m_ReceiveData(0),
m_ArraySize(bufSize),
m_ReceiveArray(NULL),
m_ArrayHead(0),
m_ArrayTail(0),
GetByteCallback(NULL)
{
	CreateReceiveArray(m_ArraySize);
}
// ----------------------------------------------------------------------------
cByteReceiver::~cByteReceiver()
{
	
}
// ----------------------------------------------------------------------------
void cByteReceiver::run()
{
	if(this->GetByteCallback != NULL)
		if(this->GetByteCallback(&m_ReceiveData))
			QueueAddData(m_ReceiveData);
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
	if(size == 0) 
		return;
	m_ArraySize = size;
	m_ReceiveArray = new uint8_t[m_ArraySize];
}
// ----------------------------------------------------------------------------
void cByteReceiver::QueueAddData(uint8_t data)
{
	if(m_ArrayHead == m_ArrayTail)
		return;
	m_ReceiveArray_[m_ArrayHead++] = data;//m_ReceiveArray[m_ArrayHead++] = data;
	if(m_ArrayHead == m_ArraySize)
		m_ArrayHead = 0;
}
// ----------------------------------------------------------------------------
uint8_t cByteReceiver::QueueGetData()
{
	
}
