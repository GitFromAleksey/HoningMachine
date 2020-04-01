using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HoningMachineConfig
{
    class cProtocolDeSerializer
    {
        const Byte SIGN_BEGIN_PACKET = (Byte)'<';
        const Byte SIGN_END_PACKET = (Byte)'>';
        private uint MAX_PACKET_LENGHT_BYTES = 11;
        
        private Byte m_DeviceNumber;
        private bool m_FindBeginPacket;
        private int m_IncomingBytesCounter;
        private Byte[] m_IncomingBytesBuffer;
        
        public Func<string> func = null;

        public cProtocolDeSerializer(Byte deviceNumber)
        {
            m_DeviceNumber = deviceNumber;
            m_FindBeginPacket = false;
            m_IncomingBytesCounter = 0;
            m_IncomingBytesBuffer = new Byte[MAX_PACKET_LENGHT_BYTES];
        }

        public void SetFunc(Func<string> func)
        {
            this.func = func;
        }

        public void AddBytes(int[] data)
        {
            for (int cnt = 0; cnt < data.Length; ++cnt)
            {
                if(data[cnt] == SIGN_END_PACKET)
                {
                    m_FindBeginPacket = false;
                    m_IncomingBytesCounter = 0;
                    PacketParser(m_IncomingBytesBuffer, m_IncomingBytesCounter);
                }
                if (m_IncomingBytesCounter == MAX_PACKET_LENGHT_BYTES)
                {
                    m_FindBeginPacket = false;
                    m_IncomingBytesCounter = 0;
                }

                if (m_FindBeginPacket)
                {
                    m_IncomingBytesBuffer[m_IncomingBytesCounter++] = (Byte)data[cnt];
                }

                if (data[cnt] == SIGN_BEGIN_PACKET)
                {
                    m_FindBeginPacket = true;
                    m_IncomingBytesCounter = 0;
                }
            }
        }

        private void PacketParser(Byte[] buffer, int dataLenght)
        {
            int cnt = 0;
            int DeviceNumber = buffer[0];
            int RegisterNumber = (buffer[2] << 8) | buffer[1];
            int Data = (buffer[6] << 24) | (buffer[5] << 16) | (buffer[4] << 8) | buffer[3];
            int CRC8 = buffer[7];
        }

    }
}
