#ifndef BYTE_SENDER_HPP_
#define BYTE_SENDER_HPP_

#include <stddef.h>
#include <stdint.h>
#include "../Interfaces/iProcess.hpp"
//#include "../Interfaces/iView.hpp"
#include "queue.hpp"

class cByteSender : public iProcess, public cQueue
{
	public:
		cByteSender(uint16_t bufSize);
		~cByteSender();
	
		virtual void run();
	
		void AddOutputData(uint8_t *data, uint8_t size);
		void SetSendByteCallback(bool (*SendByteCallback)(uint8_t *data));
	
	private:
		bool (*SendByteCallback)(uint8_t *data);
};

#endif /* BYTE_SENDER_HPP_ */
