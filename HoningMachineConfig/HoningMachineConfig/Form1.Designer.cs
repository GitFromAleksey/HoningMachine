namespace HoningMachineConfig
{
    partial class MainForm1
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
        	this.components = new System.ComponentModel.Container();
        	this.menuStrip1 = new System.Windows.Forms.MenuStrip();
        	this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	this.configToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	this.portToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	this.toolStripComboBox1 = new System.Windows.Forms.ToolStripComboBox();
        	this.openPortToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	this.closePortToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
        	this.textBoxLog = new System.Windows.Forms.TextBox();
        	this.textBoxToSend = new System.Windows.Forms.TextBox();
        	this.button1 = new System.Windows.Forms.Button();
        	this.buttonMachinePwrOn = new System.Windows.Forms.Button();
        	this.buttonMachinePwrOff = new System.Windows.Forms.Button();
        	this.buttonToolLiftUp = new System.Windows.Forms.Button();
        	this.buttonToolLiftDown = new System.Windows.Forms.Button();
        	this.buttonToolLiftStop = new System.Windows.Forms.Button();
        	this.buttonToolRotateRun = new System.Windows.Forms.Button();
        	this.buttonToolRotateStop = new System.Windows.Forms.Button();
        	this.buttonToolStop = new System.Windows.Forms.Button();
        	this.timer1 = new System.Windows.Forms.Timer(this.components);
        	this.labelCurrentToolPosition = new System.Windows.Forms.Label();
        	this.labelCurrentSensor = new System.Windows.Forms.Label();
        	this.labelUpperToolTipState = new System.Windows.Forms.Label();
        	this.labelLowerToolTipState = new System.Windows.Forms.Label();
        	this.progressBar1 = new System.Windows.Forms.ProgressBar();
        	this.trackBar1 = new System.Windows.Forms.TrackBar();
        	this.buttonVerticalFeedMotorOn = new System.Windows.Forms.Button();
        	this.buttonVerticalFeedMotorOff = new System.Windows.Forms.Button();
        	this.buttonKey_1 = new System.Windows.Forms.Button();
        	this.buttonKey_2 = new System.Windows.Forms.Button();
        	this.buttonKey_3 = new System.Windows.Forms.Button();
        	this.buttonKey_4 = new System.Windows.Forms.Button();
        	this.buttonKey_5 = new System.Windows.Forms.Button();
        	this.buttonKey_6 = new System.Windows.Forms.Button();
        	this.buttonKey_7 = new System.Windows.Forms.Button();
        	this.buttonKey_8 = new System.Windows.Forms.Button();
        	this.buttonKey_9 = new System.Windows.Forms.Button();
        	this.buttonSWITCH = new System.Windows.Forms.Button();
        	this.menuStrip1.SuspendLayout();
        	((System.ComponentModel.ISupportInitialize)(this.trackBar1)).BeginInit();
        	this.SuspendLayout();
        	// 
        	// menuStrip1
        	// 
        	this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
        	        	        	this.fileToolStripMenuItem,
        	        	        	this.configToolStripMenuItem,
        	        	        	this.helpToolStripMenuItem});
        	this.menuStrip1.Location = new System.Drawing.Point(0, 0);
        	this.menuStrip1.Name = "menuStrip1";
        	this.menuStrip1.Size = new System.Drawing.Size(955, 24);
        	this.menuStrip1.TabIndex = 0;
        	this.menuStrip1.Text = "menuStrip1";
        	// 
        	// fileToolStripMenuItem
        	// 
        	this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
        	        	        	this.exitToolStripMenuItem});
        	this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
        	this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
        	this.fileToolStripMenuItem.Text = "File";
        	// 
        	// exitToolStripMenuItem
        	// 
        	this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
        	this.exitToolStripMenuItem.Size = new System.Drawing.Size(92, 22);
        	this.exitToolStripMenuItem.Text = "Exit";
        	// 
        	// configToolStripMenuItem
        	// 
        	this.configToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
        	        	        	this.portToolStripMenuItem,
        	        	        	this.openPortToolStripMenuItem,
        	        	        	this.closePortToolStripMenuItem});
        	this.configToolStripMenuItem.Name = "configToolStripMenuItem";
        	this.configToolStripMenuItem.Size = new System.Drawing.Size(55, 20);
        	this.configToolStripMenuItem.Text = "Config";
        	// 
        	// portToolStripMenuItem
        	// 
        	this.portToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
        	        	        	this.toolStripComboBox1});
        	this.portToolStripMenuItem.Name = "portToolStripMenuItem";
        	this.portToolStripMenuItem.Size = new System.Drawing.Size(125, 22);
        	this.portToolStripMenuItem.Text = "Port";
        	this.portToolStripMenuItem.Click += new System.EventHandler(this.portToolStripMenuItem_Click);
        	// 
        	// toolStripComboBox1
        	// 
        	this.toolStripComboBox1.Name = "toolStripComboBox1";
        	this.toolStripComboBox1.Size = new System.Drawing.Size(121, 23);
        	this.toolStripComboBox1.TextChanged += new System.EventHandler(this.toolStripComboBox1_TextChanged);
        	// 
        	// openPortToolStripMenuItem
        	// 
        	this.openPortToolStripMenuItem.Name = "openPortToolStripMenuItem";
        	this.openPortToolStripMenuItem.Size = new System.Drawing.Size(125, 22);
        	this.openPortToolStripMenuItem.Text = "OpenPort";
        	this.openPortToolStripMenuItem.Click += new System.EventHandler(this.openPortToolStripMenuItem_Click);
        	// 
        	// closePortToolStripMenuItem
        	// 
        	this.closePortToolStripMenuItem.Name = "closePortToolStripMenuItem";
        	this.closePortToolStripMenuItem.Size = new System.Drawing.Size(125, 22);
        	this.closePortToolStripMenuItem.Text = "ClosePort";
        	this.closePortToolStripMenuItem.Click += new System.EventHandler(this.closePortToolStripMenuItem_Click);
        	// 
        	// helpToolStripMenuItem
        	// 
        	this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
        	this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
        	this.helpToolStripMenuItem.Text = "Help";
        	// 
        	// serialPort1
        	// 
        	this.serialPort1.BaudRate = 115200;
        	this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort1_DataReceived);
        	// 
        	// textBoxLog
        	// 
        	this.textBoxLog.Location = new System.Drawing.Point(12, 66);
        	this.textBoxLog.Multiline = true;
        	this.textBoxLog.Name = "textBoxLog";
        	this.textBoxLog.ScrollBars = System.Windows.Forms.ScrollBars.Both;
        	this.textBoxLog.Size = new System.Drawing.Size(333, 392);
        	this.textBoxLog.TabIndex = 1;
        	this.textBoxLog.KeyDown += new System.Windows.Forms.KeyEventHandler(this.MainForm1_KeyDown);
        	// 
        	// textBoxToSend
        	// 
        	this.textBoxToSend.Location = new System.Drawing.Point(12, 27);
        	this.textBoxToSend.Name = "textBoxToSend";
        	this.textBoxToSend.Size = new System.Drawing.Size(100, 20);
        	this.textBoxToSend.TabIndex = 2;
        	this.textBoxToSend.KeyDown += new System.Windows.Forms.KeyEventHandler(this.textBoxToSend_KeyDown);
        	// 
        	// button1
        	// 
        	this.button1.Location = new System.Drawing.Point(134, 24);
        	this.button1.Name = "button1";
        	this.button1.Size = new System.Drawing.Size(106, 23);
        	this.button1.TabIndex = 3;
        	this.button1.Text = "buttonTestSend";
        	this.button1.UseVisualStyleBackColor = true;
        	this.button1.Click += new System.EventHandler(this.button1_Click);
        	// 
        	// buttonMachinePwrOn
        	// 
        	this.buttonMachinePwrOn.Location = new System.Drawing.Point(352, 372);
        	this.buttonMachinePwrOn.Name = "buttonMachinePwrOn";
        	this.buttonMachinePwrOn.Size = new System.Drawing.Size(128, 23);
        	this.buttonMachinePwrOn.TabIndex = 4;
        	this.buttonMachinePwrOn.Text = "MachinePwrOn";
        	this.buttonMachinePwrOn.UseVisualStyleBackColor = true;
        	this.buttonMachinePwrOn.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonMachinePwrOff
        	// 
        	this.buttonMachinePwrOff.Location = new System.Drawing.Point(352, 401);
        	this.buttonMachinePwrOff.Name = "buttonMachinePwrOff";
        	this.buttonMachinePwrOff.Size = new System.Drawing.Size(128, 23);
        	this.buttonMachinePwrOff.TabIndex = 5;
        	this.buttonMachinePwrOff.Text = "MachinePwrOff";
        	this.buttonMachinePwrOff.UseVisualStyleBackColor = true;
        	this.buttonMachinePwrOff.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonToolLiftUp
        	// 
        	this.buttonToolLiftUp.Location = new System.Drawing.Point(620, 372);
        	this.buttonToolLiftUp.Name = "buttonToolLiftUp";
        	this.buttonToolLiftUp.Size = new System.Drawing.Size(128, 23);
        	this.buttonToolLiftUp.TabIndex = 6;
        	this.buttonToolLiftUp.Text = "ToolLiftUp";
        	this.buttonToolLiftUp.UseVisualStyleBackColor = true;
        	this.buttonToolLiftUp.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	this.buttonToolLiftUp.KeyDown += new System.Windows.Forms.KeyEventHandler(this.MainForm1_KeyDown);
        	// 
        	// buttonToolLiftDown
        	// 
        	this.buttonToolLiftDown.Location = new System.Drawing.Point(620, 401);
        	this.buttonToolLiftDown.Name = "buttonToolLiftDown";
        	this.buttonToolLiftDown.Size = new System.Drawing.Size(128, 23);
        	this.buttonToolLiftDown.TabIndex = 7;
        	this.buttonToolLiftDown.Text = "ToolLiftDown";
        	this.buttonToolLiftDown.UseVisualStyleBackColor = true;
        	this.buttonToolLiftDown.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonToolLiftStop
        	// 
        	this.buttonToolLiftStop.Location = new System.Drawing.Point(620, 430);
        	this.buttonToolLiftStop.Name = "buttonToolLiftStop";
        	this.buttonToolLiftStop.Size = new System.Drawing.Size(128, 23);
        	this.buttonToolLiftStop.TabIndex = 8;
        	this.buttonToolLiftStop.Text = "ToolLiftStop";
        	this.buttonToolLiftStop.UseVisualStyleBackColor = true;
        	this.buttonToolLiftStop.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonToolRotateRun
        	// 
        	this.buttonToolRotateRun.Location = new System.Drawing.Point(754, 372);
        	this.buttonToolRotateRun.Name = "buttonToolRotateRun";
        	this.buttonToolRotateRun.Size = new System.Drawing.Size(128, 23);
        	this.buttonToolRotateRun.TabIndex = 9;
        	this.buttonToolRotateRun.Text = "ToolRotateRun";
        	this.buttonToolRotateRun.UseVisualStyleBackColor = true;
        	this.buttonToolRotateRun.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonToolRotateStop
        	// 
        	this.buttonToolRotateStop.Location = new System.Drawing.Point(754, 401);
        	this.buttonToolRotateStop.Name = "buttonToolRotateStop";
        	this.buttonToolRotateStop.Size = new System.Drawing.Size(128, 23);
        	this.buttonToolRotateStop.TabIndex = 10;
        	this.buttonToolRotateStop.Text = "ToolRotateStop";
        	this.buttonToolRotateStop.UseVisualStyleBackColor = true;
        	this.buttonToolRotateStop.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonToolStop
        	// 
        	this.buttonToolStop.Location = new System.Drawing.Point(754, 430);
        	this.buttonToolStop.Name = "buttonToolStop";
        	this.buttonToolStop.Size = new System.Drawing.Size(128, 23);
        	this.buttonToolStop.TabIndex = 11;
        	this.buttonToolStop.Text = "ToolStop";
        	this.buttonToolStop.UseVisualStyleBackColor = true;
        	this.buttonToolStop.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// timer1
        	// 
        	this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
        	// 
        	// labelCurrentToolPosition
        	// 
        	this.labelCurrentToolPosition.AutoSize = true;
        	this.labelCurrentToolPosition.Location = new System.Drawing.Point(354, 66);
        	this.labelCurrentToolPosition.Name = "labelCurrentToolPosition";
        	this.labelCurrentToolPosition.Size = new System.Drawing.Size(102, 13);
        	this.labelCurrentToolPosition.TabIndex = 12;
        	this.labelCurrentToolPosition.Text = "CurrentToolPosition:";
        	// 
        	// labelCurrentSensor
        	// 
        	this.labelCurrentSensor.AutoSize = true;
        	this.labelCurrentSensor.Location = new System.Drawing.Point(354, 95);
        	this.labelCurrentSensor.Name = "labelCurrentSensor";
        	this.labelCurrentSensor.Size = new System.Drawing.Size(77, 13);
        	this.labelCurrentSensor.TabIndex = 13;
        	this.labelCurrentSensor.Text = "CurrentSensor:";
        	// 
        	// labelUpperToolTipState
        	// 
        	this.labelUpperToolTipState.AutoSize = true;
        	this.labelUpperToolTipState.Location = new System.Drawing.Point(352, 119);
        	this.labelUpperToolTipState.Name = "labelUpperToolTipState";
        	this.labelUpperToolTipState.Size = new System.Drawing.Size(100, 13);
        	this.labelUpperToolTipState.TabIndex = 14;
        	this.labelUpperToolTipState.Text = "UpperToolTipState:";
        	// 
        	// labelLowerToolTipState
        	// 
        	this.labelLowerToolTipState.AutoSize = true;
        	this.labelLowerToolTipState.Location = new System.Drawing.Point(352, 148);
        	this.labelLowerToolTipState.Name = "labelLowerToolTipState";
        	this.labelLowerToolTipState.Size = new System.Drawing.Size(100, 13);
        	this.labelLowerToolTipState.TabIndex = 15;
        	this.labelLowerToolTipState.Text = "LowerToolTipState:";
        	// 
        	// progressBar1
        	// 
        	this.progressBar1.Location = new System.Drawing.Point(246, 24);
        	this.progressBar1.Maximum = 4096;
        	this.progressBar1.Name = "progressBar1";
        	this.progressBar1.Size = new System.Drawing.Size(627, 23);
        	this.progressBar1.Step = 1;
        	this.progressBar1.TabIndex = 16;
        	// 
        	// trackBar1
        	// 
        	this.trackBar1.Enabled = false;
        	this.trackBar1.Location = new System.Drawing.Point(890, 24);
        	this.trackBar1.Maximum = 4096;
        	this.trackBar1.Name = "trackBar1";
        	this.trackBar1.Orientation = System.Windows.Forms.Orientation.Vertical;
        	this.trackBar1.Size = new System.Drawing.Size(45, 434);
        	this.trackBar1.TabIndex = 17;
        	// 
        	// buttonVerticalFeedMotorOn
        	// 
        	this.buttonVerticalFeedMotorOn.Location = new System.Drawing.Point(486, 372);
        	this.buttonVerticalFeedMotorOn.Name = "buttonVerticalFeedMotorOn";
        	this.buttonVerticalFeedMotorOn.Size = new System.Drawing.Size(128, 23);
        	this.buttonVerticalFeedMotorOn.TabIndex = 18;
        	this.buttonVerticalFeedMotorOn.Text = "VerticalFeedMotorOn";
        	this.buttonVerticalFeedMotorOn.UseVisualStyleBackColor = true;
        	this.buttonVerticalFeedMotorOn.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonVerticalFeedMotorOff
        	// 
        	this.buttonVerticalFeedMotorOff.Location = new System.Drawing.Point(486, 401);
        	this.buttonVerticalFeedMotorOff.Name = "buttonVerticalFeedMotorOff";
        	this.buttonVerticalFeedMotorOff.Size = new System.Drawing.Size(128, 23);
        	this.buttonVerticalFeedMotorOff.TabIndex = 19;
        	this.buttonVerticalFeedMotorOff.Text = "VerticalFeedMotorOff";
        	this.buttonVerticalFeedMotorOff.UseVisualStyleBackColor = true;
        	this.buttonVerticalFeedMotorOff.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonKey_1
        	// 
        	this.buttonKey_1.Location = new System.Drawing.Point(745, 61);
        	this.buttonKey_1.Name = "buttonKey_1";
        	this.buttonKey_1.Size = new System.Drawing.Size(128, 23);
        	this.buttonKey_1.TabIndex = 20;
        	this.buttonKey_1.Text = "Key_1";
        	this.buttonKey_1.UseVisualStyleBackColor = true;
        	this.buttonKey_1.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonKey_2
        	// 
        	this.buttonKey_2.Location = new System.Drawing.Point(745, 90);
        	this.buttonKey_2.Name = "buttonKey_2";
        	this.buttonKey_2.Size = new System.Drawing.Size(128, 23);
        	this.buttonKey_2.TabIndex = 21;
        	this.buttonKey_2.Text = "Key_2";
        	this.buttonKey_2.UseVisualStyleBackColor = true;
        	this.buttonKey_2.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonKey_3
        	// 
        	this.buttonKey_3.Location = new System.Drawing.Point(745, 119);
        	this.buttonKey_3.Name = "buttonKey_3";
        	this.buttonKey_3.Size = new System.Drawing.Size(128, 23);
        	this.buttonKey_3.TabIndex = 22;
        	this.buttonKey_3.Text = "Key_3";
        	this.buttonKey_3.UseVisualStyleBackColor = true;
        	this.buttonKey_3.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonKey_4
        	// 
        	this.buttonKey_4.Location = new System.Drawing.Point(745, 148);
        	this.buttonKey_4.Name = "buttonKey_4";
        	this.buttonKey_4.Size = new System.Drawing.Size(128, 23);
        	this.buttonKey_4.TabIndex = 23;
        	this.buttonKey_4.Text = "Key_4";
        	this.buttonKey_4.UseVisualStyleBackColor = true;
        	this.buttonKey_4.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonKey_5
        	// 
        	this.buttonKey_5.Location = new System.Drawing.Point(745, 177);
        	this.buttonKey_5.Name = "buttonKey_5";
        	this.buttonKey_5.Size = new System.Drawing.Size(128, 23);
        	this.buttonKey_5.TabIndex = 24;
        	this.buttonKey_5.Text = "Key_5";
        	this.buttonKey_5.UseVisualStyleBackColor = true;
        	this.buttonKey_5.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonKey_6
        	// 
        	this.buttonKey_6.Location = new System.Drawing.Point(745, 206);
        	this.buttonKey_6.Name = "buttonKey_6";
        	this.buttonKey_6.Size = new System.Drawing.Size(128, 23);
        	this.buttonKey_6.TabIndex = 25;
        	this.buttonKey_6.Text = "Key_6";
        	this.buttonKey_6.UseVisualStyleBackColor = true;
        	this.buttonKey_6.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonKey_7
        	// 
        	this.buttonKey_7.Location = new System.Drawing.Point(745, 235);
        	this.buttonKey_7.Name = "buttonKey_7";
        	this.buttonKey_7.Size = new System.Drawing.Size(128, 23);
        	this.buttonKey_7.TabIndex = 26;
        	this.buttonKey_7.Text = "Key_7";
        	this.buttonKey_7.UseVisualStyleBackColor = true;
        	this.buttonKey_7.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonKey_8
        	// 
        	this.buttonKey_8.Location = new System.Drawing.Point(745, 264);
        	this.buttonKey_8.Name = "buttonKey_8";
        	this.buttonKey_8.Size = new System.Drawing.Size(128, 23);
        	this.buttonKey_8.TabIndex = 27;
        	this.buttonKey_8.Text = "Key_8";
        	this.buttonKey_8.UseVisualStyleBackColor = true;
        	this.buttonKey_8.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonKey_9
        	// 
        	this.buttonKey_9.Location = new System.Drawing.Point(745, 293);
        	this.buttonKey_9.Name = "buttonKey_9";
        	this.buttonKey_9.Size = new System.Drawing.Size(128, 23);
        	this.buttonKey_9.TabIndex = 28;
        	this.buttonKey_9.Text = "Key_9";
        	this.buttonKey_9.UseVisualStyleBackColor = true;
        	this.buttonKey_9.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonSWITCH
        	// 
        	this.buttonSWITCH.Location = new System.Drawing.Point(611, 61);
        	this.buttonSWITCH.Name = "buttonSWITCH";
        	this.buttonSWITCH.Size = new System.Drawing.Size(128, 23);
        	this.buttonSWITCH.TabIndex = 29;
        	this.buttonSWITCH.Text = "SWITCH";
        	this.buttonSWITCH.UseVisualStyleBackColor = true;
        	this.buttonSWITCH.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// MainForm1
        	// 
        	this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
        	this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
        	this.ClientSize = new System.Drawing.Size(955, 473);
        	this.Controls.Add(this.buttonSWITCH);
        	this.Controls.Add(this.buttonKey_9);
        	this.Controls.Add(this.buttonKey_8);
        	this.Controls.Add(this.buttonKey_7);
        	this.Controls.Add(this.buttonKey_6);
        	this.Controls.Add(this.buttonKey_5);
        	this.Controls.Add(this.buttonKey_4);
        	this.Controls.Add(this.buttonKey_3);
        	this.Controls.Add(this.buttonKey_2);
        	this.Controls.Add(this.buttonKey_1);
        	this.Controls.Add(this.buttonVerticalFeedMotorOff);
        	this.Controls.Add(this.buttonVerticalFeedMotorOn);
        	this.Controls.Add(this.trackBar1);
        	this.Controls.Add(this.progressBar1);
        	this.Controls.Add(this.labelLowerToolTipState);
        	this.Controls.Add(this.labelUpperToolTipState);
        	this.Controls.Add(this.labelCurrentSensor);
        	this.Controls.Add(this.labelCurrentToolPosition);
        	this.Controls.Add(this.buttonToolStop);
        	this.Controls.Add(this.buttonToolRotateStop);
        	this.Controls.Add(this.buttonToolRotateRun);
        	this.Controls.Add(this.buttonToolLiftStop);
        	this.Controls.Add(this.buttonToolLiftDown);
        	this.Controls.Add(this.buttonToolLiftUp);
        	this.Controls.Add(this.buttonMachinePwrOff);
        	this.Controls.Add(this.buttonMachinePwrOn);
        	this.Controls.Add(this.button1);
        	this.Controls.Add(this.textBoxToSend);
        	this.Controls.Add(this.textBoxLog);
        	this.Controls.Add(this.menuStrip1);
        	this.MainMenuStrip = this.menuStrip1;
        	this.Name = "MainForm1";
        	this.Text = "HoningMachineConfig";
        	this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.MainForm1_KeyDown);
        	this.menuStrip1.ResumeLayout(false);
        	this.menuStrip1.PerformLayout();
        	((System.ComponentModel.ISupportInitialize)(this.trackBar1)).EndInit();
        	this.ResumeLayout(false);
        	this.PerformLayout();
        }
        private System.Windows.Forms.Button buttonSWITCH;
        private System.Windows.Forms.Button buttonKey_9;
        private System.Windows.Forms.Button buttonKey_8;
        private System.Windows.Forms.Button buttonKey_7;
        private System.Windows.Forms.Button buttonKey_6;
        private System.Windows.Forms.Button buttonKey_5;
        private System.Windows.Forms.Button buttonKey_4;
        private System.Windows.Forms.Button buttonKey_3;
        private System.Windows.Forms.Button buttonKey_2;
        private System.Windows.Forms.Button buttonKey_1;

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem configToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem portToolStripMenuItem;
        private System.Windows.Forms.ToolStripComboBox toolStripComboBox1;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.IO.Ports.SerialPort serialPort1;
        public System.Windows.Forms.TextBox textBoxLog;
        private System.Windows.Forms.ToolStripMenuItem openPortToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem closePortToolStripMenuItem;
        private System.Windows.Forms.TextBox textBoxToSend;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button buttonMachinePwrOn;
        private System.Windows.Forms.Button buttonMachinePwrOff;
        private System.Windows.Forms.Button buttonToolLiftUp;
        private System.Windows.Forms.Button buttonToolLiftDown;
        private System.Windows.Forms.Button buttonToolLiftStop;
        private System.Windows.Forms.Button buttonToolRotateRun;
        private System.Windows.Forms.Button buttonToolRotateStop;
        private System.Windows.Forms.Button buttonToolStop;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Label labelCurrentToolPosition;
        private System.Windows.Forms.Label labelCurrentSensor;
        private System.Windows.Forms.Label labelUpperToolTipState;
        private System.Windows.Forms.Label labelLowerToolTipState;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.TrackBar trackBar1;
        private System.Windows.Forms.Button buttonVerticalFeedMotorOn;
        private System.Windows.Forms.Button buttonVerticalFeedMotorOff;
    }
}

