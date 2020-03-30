#include "queue.hpp"


cQueue::cQueue(uint16_t queueSize) :
m_QueueHead(0),
m_QueueTail(0)
{
	m_QueueSize = queueSize;
	m_QueueArray = new uint8_t(m_QueueSize);
}
// ----------------------------------------------------------------------------

cQueue::~cQueue()
{
	delete[] m_QueueArray;
}
// ----------------------------------------------------------------------------

void cQueue::AddItem(uint8_t *pItem)
{
	++m_QueueHead;
	if(m_QueueHead == m_QueueSize)
		m_QueueHead = 0;
	if(m_QueueHead != m_QueueTail)
		m_QueueArray[m_QueueHead] = *pItem;
}
// ----------------------------------------------------------------------------

uint8_t *cQueue::GetItem()
{
	uint8_t *res = &m_QueueArray[m_QueueTail];
	if(m_QueueTail != m_QueueHead)
		++m_QueueTail;
	if(m_QueueTail == m_QueueSize)
		m_QueueTail = 0;
}
