#ifndef _QUEUE_H
#define _QUEUE_H

//#define DEBUG_MESSAGES_PRINT

#include <stddef.h>
#include <stdint.h>

#ifdef DEBUG_MESSAGES_PRINT
#include <iostream>
using namespace std;
#endif

#define SIZE 50   /* Размер круговой очереди */

class cQueue
{
	public:
		cQueue(uint16_t queueSize);
		~cQueue();

		bool isFull();
		bool IsData();
		bool isEmpty();
		void AddItem(uint8_t element);
		int8_t GetItem();

		void display();

	private:
		uint8_t m_QueueArray[SIZE];
		int8_t m_Front;
		int8_t m_Rear;
};

#endif /* _QUEUE_H */
