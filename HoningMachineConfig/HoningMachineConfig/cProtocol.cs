using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HoningMachineConfig
{
    struct RequestProtocol
    {
        public Byte DeviceNumber;
        public Byte CMD;
        public UInt16 RegisterNumber;
        public UInt16 RegistersToRead;
        public UInt32 DataToWrite;
        public Byte CRC8;
    }
    
    enum ProtocolCommands
    {
        CMD_READ_RO_REG = 3,
        CMD_WRITE_RW_REG = 4,
        CMD_READ_RW_REG = 5,

        PROTOCOL_CMD_MACHINE_PWR_ON = 6,
        PROTOCOL_CMD_MACHINE_PWR_OFF = 7,
        PROTOCOL_CMD_TOOL_LIFT_UP = 8,
        PROTOCOL_CMD_TOOL_LIFT_DOWN = 9,
        PROTOCOL_CMD_TOOL_LIFT_STOP = 10,
        PROTOCOL_CMD_TOOL_ROTATE_RUN = 11,
        PROTOCOL_CMD_TOOL_ROTATE_STOP = 12,
        PROTOCOL_CMD_TOOL_STOP = 13
    }

    class cProtocol
    {
        const Byte CMD_READ_RO_REG = 3;
        const Byte CMD_WRITE_RW_REG = 4;
        const Byte CMD_READ_RW_REG = 5;

        const Byte SIGN_BEGIN_PACKET = (Byte)'<';
        const Byte SIGN_END_PACKET = (Byte)'>';

        private Byte m_DeviceNumber;
        
        public cProtocol(Byte deviceNumber)
        {
            m_DeviceNumber = deviceNumber;
        }

        public Byte[] GetRequestToRead(UInt16 registerNumber)
        {
            RequestProtocol request;
            Byte[] b = new Byte[13];
            
            request.DeviceNumber = m_DeviceNumber;
            request.CMD = CMD_READ_RO_REG;
            request.RegisterNumber = registerNumber;
            request.RegistersToRead = 9;
            request.DataToWrite = 0x12345678;
            request.CRC8 = 0xAA;

            return SerealizeProtocol(request);
        }

        public Byte[] GetRequestToWhite(UInt16 registerNumber)
        {
            RequestProtocol request;

            request.DeviceNumber = m_DeviceNumber;
            request.CMD = CMD_WRITE_RW_REG;
            request.RegisterNumber = registerNumber;
            request.RegistersToRead = 9;
            request.DataToWrite = 0x12345678;
            request.CRC8 = 0xAA;

            return SerealizeProtocol(request);
        }

        public Byte[] GetCommand(ProtocolCommands cmd)
        {
            return SerealizeProtocol(FillProtocol(cmd, 0, 0, 0));
        }

        private RequestProtocol FillProtocol(ProtocolCommands cmd, UInt16 registerNumber, UInt16 registersToRead, UInt32 dataToWrite)
        {
            RequestProtocol protocol = new RequestProtocol();

            protocol.DeviceNumber = m_DeviceNumber;
            protocol.CMD = (Byte)cmd;
            protocol.RegisterNumber = registerNumber;
            protocol.RegistersToRead = registersToRead;
            protocol.DataToWrite = dataToWrite;
            CalcCrc8(ref protocol);

            return protocol;
        }

        private void CalcCrc8(ref RequestProtocol protocol)
        {
            protocol.CRC8 = 0xAA;    // TODO пока заглушка
        }

        private Byte[] SerealizeProtocol(RequestProtocol request)
        {
            Byte[] b = new Byte[13];
            int cnt = 0;

            b[cnt++] = SIGN_BEGIN_PACKET;

            b[cnt++] = request.DeviceNumber;

            b[cnt++] = request.CMD;

            b[cnt++] = (Byte)(request.RegisterNumber & 0xFF);
            b[cnt++] = (Byte)((request.RegisterNumber >> 8) & 0xFF);

            b[cnt++] = (Byte)((request.DataToWrite) & 0xFF);
            b[cnt++] = (Byte)((request.DataToWrite >> 8) & 0xFF);
            b[cnt++] = (Byte)((request.DataToWrite >> 16) & 0xFF);
            b[cnt++] = (Byte)((request.DataToWrite >> 24) & 0xFF);

            b[cnt++] = (Byte)(request.RegistersToRead & 0xFF);
            b[cnt++] = (Byte)((request.RegistersToRead >> 8) & 0xFF);

            b[cnt++] = request.CRC8;
            b[cnt] = SIGN_END_PACKET;

            return b;
        }
    }
}
