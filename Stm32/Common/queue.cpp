#include "queue.hpp"


cQueue::cQueue(uint16_t queueSize):
m_Front(-1),
m_Rear(-1)
{}
// ----------------------------------------------------------------------------
cQueue::~cQueue() {}
// ----------------------------------------------------------------------------
bool cQueue::isFull()
{
	if( (m_Front == 0) && (m_Rear == SIZE - 1) )
	{
		return true;
	}
	if(m_Front == m_Rear + 1)
	{
		return true;
	}
	return false;
}
// ----------------------------------------------------------------------------
bool cQueue::IsData()
{
	return !isEmpty();
}
// ----------------------------------------------------------------------------
bool cQueue::isEmpty()
{
	if(m_Front == -1)
		return true;
	else
		return false;
}
// ----------------------------------------------------------------------------
void cQueue::AddItem(uint8_t element)
{
	if(isFull())
	{
#ifdef DEBUG_MESSAGES_PRINT
		cout << "Queue is full";
#endif
	}
	else
	{
		if(m_Front == -1)
			m_Front = 0;

		m_Rear = (m_Rear + 1) % SIZE;
		m_QueueArray[m_Rear] = element;
#ifdef DEBUG_MESSAGES_PRINT
		cout << endl << "Inserted " << (int)element << endl;
#endif
	}
}
// ----------------------------------------------------------------------------
int8_t cQueue::GetItem()
{
	uint8_t element;

	if(isEmpty())
	{
#ifdef DEBUG_MESSAGES_PRINT
		cout << "Queue is empty" << endl;
#endif
		return(-1);
	}
	else
	{
		element = m_QueueArray[m_Front];

		if(m_Front == m_Rear)
		{
			m_Front = -1;
			m_Rear = -1;
		} /* Q имеет только один элемент, поэтому мы удаляем очередь после удаления. */
		else
		{
			m_Front = (m_Front + 1) % SIZE;
		}
		return(element);
	}
}
// ----------------------------------------------------------------------------
void cQueue::display()
{
#ifdef DEBUG_MESSAGES_PRINT
	/* Функция для отображения статуса круговой очереди */
	uint8_t i;

	if(isEmpty())
	{
		cout << endl << "Empty Queue" << endl;
	}
	else
	{
		cout << "Front -> " << m_Front;
		cout << endl << "Items -> ";

		for( i = m_Front; i != m_Rear; i = (i + 1) % SIZE )
			cout << (int)m_QueueArray[i];

		cout << (int)m_QueueArray[i];
		cout << endl << "Rear -> " << (int)m_Rear;
	}
	cout << endl;
#endif
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
