//============================================================================
// Name        : QueueTest.cpp
// Author      : Aleksey
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdint.h>

#include "queue.hpp"

using namespace std;

int main()
{
	cout << "!!!Hello World!!!" << endl;

	static const uint16_t QueueSize = 5;
	uint8_t queueItem = 1;

	cQueue q(QueueSize);

	q.display();

	q.AddItem(queueItem++);
	q.AddItem(queueItem++);
	q.AddItem(queueItem++);
	q.AddItem(queueItem++);
	q.AddItem(queueItem++);
	q.AddItem(queueItem++);

	q.display();

	cout << "IsData() = " << q.IsData() << endl;
	cout << "deQueue() = " << (int)q.GetItem() << endl;
	cout << "deQueue() = " << (int)q.GetItem() << endl;
	cout << "deQueue() = " << (int)q.GetItem() << endl;
	cout << "deQueue() = " << (int)q.GetItem() << endl;
	cout << "deQueue() = " << (int)q.GetItem() << endl;
	cout << "deQueue() = " << (int)q.GetItem() << endl;

	cout << "IsData() = " << q.IsData() << endl;

	return 0;
}
