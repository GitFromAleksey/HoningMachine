#ifndef PROTOCOL_FORMER_H
#define PROTOCOL_FORMER_H

#include <stddef.h>
#include <stdint.h>
#include "../Interfaces/iProcess.hpp"
#include "../Interfaces/iView.hpp"
#include "ByteSender.hpp"

typedef enum
{
	paramTypeCurrentToolPosition = 1,
	paramTypeCurrentSensor = 2,
	paramTypeUpperToolTipState = 3,
	paramTypeLowerToolTip = 4
} eSendingParamType;


typedef struct
{
	uint8_t DeviceNumber;	// номер устройства
	uint16_t ParamType;	// номер регистра
	uint32_t Data;	// если команда чтения, то поле игнорируется
	uint8_t CRC8;	// контрольная сумма
} t_out_protocol;

class cProtocolFormer : public iProcess, public iView
{
	public:
		cProtocolFormer(cByteSender *pByteSender);
		~cProtocolFormer();
	
		virtual void run();
	
		virtual void SendCurrentPosition(uint32_t position);
		virtual void SendCurrent(uint32_t position);
	
	private:
		cByteSender *m_pByteSender;
	
		void PacketFormingAndSend(eSendingParamType param, uint32_t data);
};

#endif /* PROTOCOL_FORMER_H */
