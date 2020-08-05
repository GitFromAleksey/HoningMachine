#include "queue.hpp"


cQueue::cQueue(uint16_t queueSize) :
m_QueueHead(0),
m_QueueTail(0),
m_HeadCaughtTail(false)
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

void cQueue::AddItem(uint8_t item)
{
	if(!m_HeadCaughtTail)
	{
		m_QueueArray[m_QueueHead] = item;
		m_QueueHead = Increment(m_QueueHead);
	}

	if(m_QueueHead == m_QueueTail)
	{
		m_HeadCaughtTail = true;
	}
	else
	{
		m_HeadCaughtTail = false;
	}
}
// ----------------------------------------------------------------------------
bool cQueue::IsData()
{
	return (m_QueueTail != m_QueueHead);
}
// ----------------------------------------------------------------------------
uint8_t cQueue::GetItem()
{
	uint8_t res = 0;

	if(m_QueueTail != m_QueueHead)
	{
		m_HeadCaughtTail = false;
		res = m_QueueArray[m_QueueTail];
		m_QueueTail = Increment(m_QueueTail);
	}
	
//	if(Increment(m_QueueTail) != m_QueueHead)
//	{
//		m_HeadCaughtTail = false;
//		res = m_QueueArray[m_QueueTail];
//		m_QueueTail = Increment(m_QueueTail);
//	}
//	else
//	{
//		// TODO здесь мы постоянно отсылаем элемент головы, если уперлись в голову
//		// нужно будет обыграть этот момент. 
//		// Например возвращать bool, а данные по указателю
//		res = m_QueueArray[m_QueueTail];
//	}
	
	return res;
}
// ----------------------------------------------------------------------------
uint16_t cQueue::GetQueueSize()
{
	return m_QueueSize;
}
// ----------------------------------------------------------------------------
uint16_t cQueue::Increment(uint16_t val)
{
	return ((val + 1) == m_QueueSize)?(0):(++val);
}
