#include <stddef.h>
#include <stdint.h>
#include "../Interfaces/iProcess.hpp"
#include "../Interfaces/iController.hpp"
#include "ByteReceiver.hpp"

//typedef struct
//{
//	unsigned DeviceNumber			: 8;	// ����� ����������
//	unsigned CMD							: 8;	// �������
//	unsigned RegisterNumber		: 16;	// ����� ��������
//	unsigned RegistersToRead	: 16;	// ���-�� ��������� ��� ������
//	unsigned DataToWrite			: 32;	// ���� ������� ������, �� ���� ������������
//	unsigned CRC8							: 8;	// ����������� �����
//} t_protocol;

typedef struct
{
	uint8_t DeviceNumber;	// ����� ����������
	uint8_t CMD;	// �������
	uint16_t RegisterNumber;	// ����� ��������
	uint32_t DataToWrite;	// ���� ������� ������, �� ���� ������������
	uint16_t RegistersToRead;	// ���-�� ��������� ��� ������
	uint8_t CRC8;	// ����������� �����
} t_protocol;

class cProtocolDetector : public iProcess
{
	public:
		cProtocolDetector(cByteReceiver *byteReceiver, iController *machineController);
		~cProtocolDetector();
	
		virtual void run();
	
	private:
		cByteReceiver *m_ByteReceiver;
		static const uint16_t m_ArraySize = 20;
		uint16_t m_ArrayCnt;
		uint8_t m_Array[m_ArraySize];
		bool m_IsPacketBegin;
		iController *m_MachineController;
	
		void PacketParse(uint8_t *pData);
};
