#ifndef _QUEUE_H
#define _QUEUE_H

#include <stddef.h>
#include <stdint.h>


class cQueue
{
	public:
		cQueue(uint16_t queueSize);
		~cQueue();
	
		void AddItem(uint8_t item);
		uint8_t GetItem();
		uint16_t GetQueueSize();
	
	private:
		uint16_t m_QueueSize;
		uint8_t *m_QueueArray;
		uint16_t m_QueueHead;
		uint16_t m_QueueTail;
		bool m_HeadCaughtTail;
	
		uint16_t Increment(uint16_t val);
};

#endif /* _QUEUE_H */
