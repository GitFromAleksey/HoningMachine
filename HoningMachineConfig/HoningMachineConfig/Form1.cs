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
        public MainForm1()
        {
            InitializeComponent();
            // разворачиваем форму на весь экран
            this.WindowState = FormWindowState.Maximized;
        }

        // вывод списка com портов
        private void portToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStripComboBox1.Items.Clear();
            toolStripComboBox1.Items.AddRange(SerialPort.GetPortNames());
        }
    }
}
