using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace HoningMachineConfig
{
    public partial class MainForm1 : Form
    {
        const Byte DEVICE_NUMBER = 1;
        private cProtocolSerializer m_ProtocolSerializer;
        private cProtocolDeSerializer m_ProtocolDeSerializer;
        
        public MainForm1()
        {
            InitializeComponent();
            // разворачиваем форму на весь экран
            //this.WindowState = FormWindowState.Maximized;

            m_ProtocolSerializer = new cProtocolSerializer(DEVICE_NUMBER);
            m_ProtocolDeSerializer = new cProtocolDeSerializer(DEVICE_NUMBER);
            //m_ProtocolDeSerializer.SetFunc(Logging);
            timer1.Enabled = true;
        }

        // вывод списка com портов
        private void portToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStripComboBox1.Items.Clear();
            toolStripComboBox1.Items.AddRange(SerialPort.GetPortNames());
        }

        private void toolStripComboBox1_TextChanged(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
                return;
            serialPort1.PortName = toolStripComboBox1.Text;
            Logging("Selected new port name: " + toolStripComboBox1.Text);
        }

        private void openPortToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                Logging("serialPort1.IsOpen");
            }

            try
            {
                serialPort1.Open();
                toolStripComboBox1.Enabled = false;
            }
            catch (Exception ex)
            {
                Logging("serialPort1.Open() error: " + ex.Message);
            }
            finally
            {
                Logging("serialPort1.Open() sucsess");
            }
        }

        private void closePortToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                serialPort1.Close();
                toolStripComboBox1.Enabled = true;
                Logging("serialPort1.Close()");
            }
        }

        private async void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            int bytesToRead = serialPort1.BytesToRead;
            int bytesCnt = 0;
            int[] buf = new int[bytesToRead];
            string str = "";
            TextBox tb = textBoxLog;

            while (bytesCnt < bytesToRead)
            {
                buf[bytesCnt++] = serialPort1.ReadByte();
            }

            m_ProtocolDeSerializer.AddBytes(buf);

            bytesCnt = 0;
            while (bytesCnt < bytesToRead)
            {
                str += buf[bytesCnt++].ToString() + ',';
            }

            str += "\r\n";
            //str = m_ProtocolDeSerializer.ToString();
            //this.textBoxLog.BeginInvoke((MethodInvoker)(() => this.textBoxLog.Text = str));
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            labelCurrentToolPosition.Text = "CurrentToolPosition: " + m_ProtocolDeSerializer.GetParamValue(eSendingParamType.paramTypeCurrentToolPosition);
            labelCurrentSensor.Text = "CurrentSensor: " + m_ProtocolDeSerializer.GetParamValue(eSendingParamType.paramTypeCurrentSensor);
            labelUpperToolTipState.Text = "UpperToolTipState: " + m_ProtocolDeSerializer.GetParamValue(eSendingParamType.paramTypeUpperToolTipState);
            labelLowerToolTipState.Text = "LowerToolTipState: " + m_ProtocolDeSerializer.GetParamValue(eSendingParamType.paramTypeLowerToolTipState);

            progressBar1.Value = (int)m_ProtocolDeSerializer.GetParamValue(eSendingParamType.paramTypeCurrentSensor);
            trackBar1.Value = (int)m_ProtocolDeSerializer.GetParamValue(eSendingParamType.paramTypeCurrentToolPosition);
        }

        private void textBoxToSend_KeyDown(object sender, KeyEventArgs e)
        {
            if (!serialPort1.IsOpen)
                return;
            serialPort1.Write(textBoxToSend.Text);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
                return;

            //Byte[] request =  m_Protocol.GetRequestToRead(8);
            Byte[] request = m_ProtocolSerializer.GetRequestToWhite(9);

            serialPort1.Write(request, 0, request.Length);
        }

        private void buttonsMachineDriving_Click(object sender, EventArgs e)
            //private void buttonMachinePwrOn_Click(object sender, EventArgs e)
        {

            if(sender == buttonMachinePwrOn)
            { SendData(m_ProtocolSerializer.GetCommand(ProtocolCommands.PROTOCOL_CMD_MACHINE_PWR_ON)); }
            if (sender == buttonMachinePwrOff)
            { SendData(m_ProtocolSerializer.GetCommand(ProtocolCommands.PROTOCOL_CMD_MACHINE_PWR_OFF)); }
            if (sender == buttonToolLiftUp)
            { SendData(m_ProtocolSerializer.GetCommand(ProtocolCommands.PROTOCOL_CMD_TOOL_LIFT_UP));  }
            if (sender == buttonToolLiftDown)
            { SendData(m_ProtocolSerializer.GetCommand(ProtocolCommands.PROTOCOL_CMD_TOOL_LIFT_DOWN));  }
            if (sender == buttonToolLiftStop)
            { SendData(m_ProtocolSerializer.GetCommand(ProtocolCommands.PROTOCOL_CMD_TOOL_LIFT_STOP));  }
            if (sender == buttonToolRotateRun)
            { SendData(m_ProtocolSerializer.GetCommand(ProtocolCommands.PROTOCOL_CMD_TOOL_ROTATE_RUN));  }
            if (sender == buttonToolRotateStop)
            { SendData(m_ProtocolSerializer.GetCommand(ProtocolCommands.PROTOCOL_CMD_TOOL_ROTATE_STOP)); }
            if (sender == buttonToolStop)
            { SendData(m_ProtocolSerializer.GetCommand(ProtocolCommands.PROTOCOL_CMD_TOOL_STOP)); }
            if (sender == buttonVerticalFeedMotorOn)
            { SendData(m_ProtocolSerializer.GetCommand(ProtocolCommands.PROTOCOL_CMD_VERTICAL_FEED_MOTOR_ON)); }
            if (sender == buttonVerticalFeedMotorOff)
            { SendData(m_ProtocolSerializer.GetCommand(ProtocolCommands.PROTOCOL_CMD_VERTICAL_FEED_MOTOR_OFF)); }
            
			if (sender == buttonSWITCH)
			{ SendData(m_ProtocolSerializer.GetCommand(ProtocolCommands.PROTOCOL_CMD_SWITCH_TOGGLE)); }
			if (sender == buttonKey_1)
			{ SendData(m_ProtocolSerializer.GetCommand(ProtocolCommands.PROTOCOL_CMD_PRESS_KEY_1)); }
			if (sender == buttonKey_2)
			{ SendData(m_ProtocolSerializer.GetCommand(ProtocolCommands.PROTOCOL_CMD_PRESS_KEY_2)); }
			if (sender == buttonKey_3)
			{ SendData(m_ProtocolSerializer.GetCommand(ProtocolCommands.PROTOCOL_CMD_PRESS_KEY_3)); }
			if (sender == buttonKey_4)
			{ SendData(m_ProtocolSerializer.GetCommand(ProtocolCommands.PROTOCOL_CMD_PRESS_KEY_4)); }
			if (sender == buttonKey_5)
			{ SendData(m_ProtocolSerializer.GetCommand(ProtocolCommands.PROTOCOL_CMD_PRESS_KEY_5)); }
			if (sender == buttonKey_6)
			{ SendData(m_ProtocolSerializer.GetCommand(ProtocolCommands.PROTOCOL_CMD_PRESS_KEY_6)); }
			if (sender == buttonKey_7)
			{ SendData(m_ProtocolSerializer.GetCommand(ProtocolCommands.PROTOCOL_CMD_PRESS_KEY_7)); }
			if (sender == buttonKey_8)
			{ SendData(m_ProtocolSerializer.GetCommand(ProtocolCommands.PROTOCOL_CMD_PRESS_KEY_8)); }
			if (sender == buttonKey_9)
			{ SendData(m_ProtocolSerializer.GetCommand(ProtocolCommands.PROTOCOL_CMD_PRESS_KEY_9)); }
            
        }

        private void SendData(Byte[] data)
        {
            if(serialPort1.IsOpen)
                serialPort1.Write(data, 0, data.Length);
        }

        private void Logging(string text)
        {
            textBoxLog.Text += text + "\r\n";
        }

        private void MainForm1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyData == Keys.Delete)
            {
                textBoxLog.Clear();
            }
            if (e.KeyValue == 85) // U
            {
                if (e.Control)
                    buttonToolLiftUp.PerformClick();
            }
            if (e.KeyValue == 68) // D
            {
                if(e.Control)
                    buttonToolLiftDown.PerformClick();
            }
            if (e.KeyValue == 83) // S
            {
                if (e.Control)
                    buttonToolLiftStop.PerformClick();
            }
        }


    }
}
