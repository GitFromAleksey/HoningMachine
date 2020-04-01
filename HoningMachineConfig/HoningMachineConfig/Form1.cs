﻿using System;
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
        private cProtocol m_Protocol;
        
        public MainForm1()
        {
            InitializeComponent();
            // разворачиваем форму на весь экран
            //this.WindowState = FormWindowState.Maximized;

            m_Protocol = new cProtocol(1);
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
            bytesCnt = 0;
            while (bytesCnt < bytesToRead)
            {
                str += buf[bytesCnt++].ToString() + ',';
            }

            str += "\r\n";
            this.textBoxLog.BeginInvoke((MethodInvoker)(() => this.textBoxLog.Text += str));

        }

        private void textBoxLog_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyData == Keys.Delete)
            {
                textBoxLog.Clear();
            }
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
            Byte[] request = m_Protocol.GetRequestToWhite(9);

            serialPort1.Write(request, 0, request.Length);
        }

        private void buttonsMachineDriving_Click(object sender, EventArgs e)
            //private void buttonMachinePwrOn_Click(object sender, EventArgs e)
        {
            Byte[] request;
            
            if(sender == buttonMachinePwrOn)
            {
                request = m_Protocol.GetCommand(ProtocolCommands.PROTOCOL_CMD_MACHINE_PWR_ON);
                serialPort1.Write(request, 0, request.Length);
            }
            if (sender == buttonMachinePwrOff)
            {
                request = m_Protocol.GetCommand(ProtocolCommands.PROTOCOL_CMD_MACHINE_PWR_OFF);
                serialPort1.Write(request, 0, request.Length);
            }

        }

        void Logging(string text)
        {
            textBoxLog.Text += text + "\r\n";
        }





    }
}
