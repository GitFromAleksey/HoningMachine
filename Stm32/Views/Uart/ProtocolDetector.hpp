#include <stddef.h>
#include <stdint.h>
#include "../Interfaces/iProcess.hpp"
#include "../Interfaces/iController.hpp"
#include "ByteReceiver.hpp"

//typedef struct
//{
//	unsigned DeviceNumber			: 8;	// номер устройства
//	unsigned CMD							: 8;	// команда
//	unsigned RegisterNumber		: 16;	// номер регистра
//	unsigned RegistersToRead	: 16;	// кол-во регистров для чтения
//	unsigned DataToWrite			: 32;	// если команда чтения, то поле игнорируется
//	unsigned CRC8							: 8;	// контрольная сумма
//} t_protocol;

typedef struct
{
	uint8_t DeviceNumber;	// номер устройства
	uint8_t CMD;	// команда
	uint16_t RegisterNumber;	// номер регистра
	uint32_t DataToWrite;	// если команда чтения, то поле игнорируется
	uint16_t RegistersToRead;	// кол-во регистров для чтения
	uint8_t CRC8;	// контрольная сумма
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
