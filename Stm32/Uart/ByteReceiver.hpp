#ifndef BYTE_RECEIVER_HPP_
#define BYTE_RECEIVER_HPP_

//#include <iostream>
#include <stddef.h>
#include <stdint.h>
#include "../Interfaces/iProcess.hpp"


class cByteReceiver : public iProcess
{
public:
	cByteReceiver();
	cByteReceiver(uint16_t bufSize);
	~cByteReceiver();

	virtual void run();
	void SetByteCalback(bool (*GetByteCallback)(uint8_t *data));

private:
	uint8_t m_ReceiveData;
	uint16_t m_ArraySize;
	uint8_t *m_ReceiveArray;
uint8_t m_ReceiveArray_[10];
	uint16_t m_ArrayHead;
	uint16_t m_ArrayTail;
	bool (*GetByteCallback)(uint8_t *data);

	void CreateReceiveArray(uint16_t size);
	void QueueAddData(uint8_t data);
	uint8_t QueueGetData();
};

#endif /* BYTE_RECEIVER_HPP_ */
