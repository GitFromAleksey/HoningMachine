using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HoningMachineConfig
{
    enum eSendingParamType
    {
        paramTypeNone = -1,
    	paramTypeCurrentToolPosition = 1,
        paramTypeCurrentSensor = 2,
        paramTypeUpperToolTipState = 3,
        paramTypeLowerToolTipState = 4
    };

    class cProtocolDeSerializer
    {
        const Byte SIGN_BEGIN_PACKET = (Byte)'<';
        const Byte SIGN_END_PACKET = (Byte)'>';
        private uint MAX_PACKET_LENGHT_BYTES = 11;
        private int DEVICE_NUMBER = 1;
        
        private Byte m_DeviceNumber;
        private bool m_FindBeginPacket;
        private int m_IncomingBytesCounter;
        private Byte[] m_IncomingBytesBuffer;


        class IncomingParam
        {
            private int m_DeviceNumber;
            private eSendingParamType m_ParamType;
            private UInt32 m_Data;
            private string m_ParamName;

            public IncomingParam(int deviceNumber, eSendingParamType type, string paramName)
            {
                m_DeviceNumber = deviceNumber;
                m_ParamType = type;
                m_Data = 0;
                m_ParamName = paramName;
            }

            public void PacketParser(Byte[] buffer, int dataLenght)
            {
                if (m_DeviceNumber == buffer[0])
                {
                    if (m_ParamType == (eSendingParamType)((buffer[2] << 8) | buffer[1]))
                    {
                        //if(CRC8 == buffer[7];
                        m_Data = (UInt32)((buffer[6] << 24) | (buffer[5] << 16) | (buffer[4] << 8) | buffer[3]);
                    }
                }
            }

            public eSendingParamType GetType() { return m_ParamType; }
            public UInt32 GetData() { return m_Data; }

            public string ToString()
            {
                string res = "";
                res += m_ParamName + ": " + m_Data + "\r\n";
                return res;
            }
        }

        private List<IncomingParam> ListOfParameters;

        public cProtocolDeSerializer(Byte deviceNumber)
        {
            m_DeviceNumber = deviceNumber;
            m_FindBeginPacket = false;
            m_IncomingBytesCounter = 0;
            m_IncomingBytesBuffer = new Byte[MAX_PACKET_LENGHT_BYTES];

            ListOfParameters = new List<IncomingParam>();
            ListOfParameters.Add(new IncomingParam(DEVICE_NUMBER, eSendingParamType.paramTypeCurrentSensor, "CurrentSensor"));
            ListOfParameters.Add(new IncomingParam(DEVICE_NUMBER, eSendingParamType.paramTypeCurrentToolPosition, "CurrentToolPosition"));
            ListOfParameters.Add(new IncomingParam(DEVICE_NUMBER, eSendingParamType.paramTypeLowerToolTipState, "LowerToolTipState"));
            ListOfParameters.Add(new IncomingParam(DEVICE_NUMBER, eSendingParamType.paramTypeUpperToolTipState, "UpperToolTipState"));
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

        public UInt32 GetParamValue(eSendingParamType paramType)
        {
        	foreach (IncomingParam param in ListOfParameters)
            {
                if (param.GetType() == paramType)
                    return param.GetData();
            }
            return 0;
        }

        public string ToString()
        {
            string res = "";
            foreach (IncomingParam param in ListOfParameters)
            {
                res += param.ToString();
            }
            return res;
        }

        private void PacketParser(Byte[] buffer, int dataLenght)
        {
            foreach (IncomingParam param in ListOfParameters)
            {
                param.PacketParser(buffer, dataLenght);
            }
            
            //int cnt = 0;
            //int DeviceNumber = buffer[0];
            //int RegisterNumber = (buffer[2] << 8) | buffer[1];
            //int Data = (buffer[6] << 24) | (buffer[5] << 16) | (buffer[4] << 8) | buffer[3];
            //int CRC8 = buffer[7];
        }


    }
}
