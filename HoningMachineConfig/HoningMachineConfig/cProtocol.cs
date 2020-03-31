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
    
    class cProtocol
    {
        const Byte CMD_READ = 3;
        const Byte CMD_WRITE = 4;
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
            request.CMD = CMD_READ;
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
            request.CMD = CMD_WRITE;
            request.RegisterNumber = registerNumber;
            request.RegistersToRead = 9;
            request.DataToWrite = 0x12345678;
            request.CRC8 = 0xAA;

            return SerealizeProtocol(request);
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
