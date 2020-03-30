#ifndef _QUEUE_H
#define _QUEUE_H

#include <stddef.h>
#include <stdint.h>


class cQueue
{
	public:
		cQueue(uint16_t queueSize);
		~cQueue();
	
		void AddItem(uint8_t *pItem);
		uint8_t *GetItem();
	
	private:
		uint16_t m_QueueSize;
		uint8_t *m_QueueArray;
		uint16_t m_QueueHead;
		uint16_t m_QueueTail;
};

#endif /* _QUEUE_H */
