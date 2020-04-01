#ifndef PROTOCOL_FORMER_H
#define PROTOCOL_FORMER_H

#include <stddef.h>
#include <stdint.h>
#include "../Interfaces/iProcess.hpp"
#include "../Interfaces/iView.hpp"
#include "ByteSender.hpp"

typedef enum
{
	CurrentPosition = 1
} teSendingParam;

typedef struct
{
	uint8_t DeviceNumber;	// ����� ����������
	uint8_t CMD;	// �������
	uint16_t RegisterNumber;	// ����� ��������
	uint32_t DataToWrite;	// ���� ������� ������, �� ���� ������������
	uint16_t RegistersToRead;	// ���-�� ��������� ��� ������
	uint8_t CRC8;	// ����������� �����
} t_out_protocol;

class cProtocolFormer : public iProcess, public iView
{
	public:
		cProtocolFormer(cByteSender *pByteSender);
		~cProtocolFormer();
	
		virtual void run();
	
		virtual void SendCurrentPosition(uint32_t position);
	
	private:
		cByteSender *m_pByteSender;
	
		void PacketFormingAndSend(teSendingParam param, uint32_t data);
};

#endif /* PROTOCOL_FORMER_H */
