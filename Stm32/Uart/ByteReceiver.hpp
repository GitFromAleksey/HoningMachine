#ifndef BYTE_RECEIVER_HPP_
#define BYTE_RECEIVER_HPP_

//#include <iostream>
#include <stddef.h>
#include <stdint.h>
#include "../Interfaces/iProcess.hpp"
#include "queue.hpp"


class cByteReceiver : public iProcess // TODO наверное нужно былонаследоваться от очереди
{
public:
	cByteReceiver(uint16_t bufSize);
	~cByteReceiver();

	virtual void run();
	void SetByteCalback(bool (*GetByteCallback)(uint8_t *data));
	uint8_t QueueGetData();

private:
	cQueue *m_Queue;
	bool (*GetByteCallback)(uint8_t *data);

	void CreateReceiveArray(uint16_t size);
	void QueueAddData(uint8_t data);	
};

#endif /* BYTE_RECEIVER_HPP_ */
