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
        	this.trackBarPosition = new System.Windows.Forms.TrackBar();
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
        	this.labelStateOfWork = new System.Windows.Forms.Label();
        	this.menuStrip1.SuspendLayout();
        	((System.ComponentModel.ISupportInitialize)(this.trackBarPosition)).BeginInit();
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
        	this.menuStrip1.Padding = new System.Windows.Forms.Padding(8, 2, 0, 2);
        	this.menuStrip1.Size = new System.Drawing.Size(712, 28);
        	this.menuStrip1.TabIndex = 0;
        	this.menuStrip1.Text = "menuStrip1";
        	// 
        	// fileToolStripMenuItem
        	// 
        	this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
        	        	        	this.exitToolStripMenuItem});
        	this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
        	this.fileToolStripMenuItem.Size = new System.Drawing.Size(44, 24);
        	this.fileToolStripMenuItem.Text = "File";
        	// 
        	// exitToolStripMenuItem
        	// 
        	this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
        	this.exitToolStripMenuItem.Size = new System.Drawing.Size(102, 24);
        	this.exitToolStripMenuItem.Text = "Exit";
        	// 
        	// configToolStripMenuItem
        	// 
        	this.configToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
        	        	        	this.portToolStripMenuItem,
        	        	        	this.openPortToolStripMenuItem,
        	        	        	this.closePortToolStripMenuItem});
        	this.configToolStripMenuItem.Name = "configToolStripMenuItem";
        	this.configToolStripMenuItem.Size = new System.Drawing.Size(65, 24);
        	this.configToolStripMenuItem.Text = "Config";
        	// 
        	// portToolStripMenuItem
        	// 
        	this.portToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
        	        	        	this.toolStripComboBox1});
        	this.portToolStripMenuItem.Name = "portToolStripMenuItem";
        	this.portToolStripMenuItem.Size = new System.Drawing.Size(140, 24);
        	this.portToolStripMenuItem.Text = "Port";
        	this.portToolStripMenuItem.Click += new System.EventHandler(this.portToolStripMenuItem_Click);
        	// 
        	// toolStripComboBox1
        	// 
        	this.toolStripComboBox1.Name = "toolStripComboBox1";
        	this.toolStripComboBox1.Size = new System.Drawing.Size(121, 28);
        	this.toolStripComboBox1.TextChanged += new System.EventHandler(this.toolStripComboBox1_TextChanged);
        	// 
        	// openPortToolStripMenuItem
        	// 
        	this.openPortToolStripMenuItem.Name = "openPortToolStripMenuItem";
        	this.openPortToolStripMenuItem.Size = new System.Drawing.Size(140, 24);
        	this.openPortToolStripMenuItem.Text = "OpenPort";
        	this.openPortToolStripMenuItem.Click += new System.EventHandler(this.openPortToolStripMenuItem_Click);
        	// 
        	// closePortToolStripMenuItem
        	// 
        	this.closePortToolStripMenuItem.Name = "closePortToolStripMenuItem";
        	this.closePortToolStripMenuItem.Size = new System.Drawing.Size(140, 24);
        	this.closePortToolStripMenuItem.Text = "ClosePort";
        	this.closePortToolStripMenuItem.Click += new System.EventHandler(this.closePortToolStripMenuItem_Click);
        	// 
        	// helpToolStripMenuItem
        	// 
        	this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
        	this.helpToolStripMenuItem.Size = new System.Drawing.Size(53, 24);
        	this.helpToolStripMenuItem.Text = "Help";
        	// 
        	// serialPort1
        	// 
        	this.serialPort1.BaudRate = 115200;
        	this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort1_DataReceived);
        	// 
        	// textBoxLog
        	// 
        	this.textBoxLog.Location = new System.Drawing.Point(80, 655);
        	this.textBoxLog.Margin = new System.Windows.Forms.Padding(4);
        	this.textBoxLog.Multiline = true;
        	this.textBoxLog.Name = "textBoxLog";
        	this.textBoxLog.ScrollBars = System.Windows.Forms.ScrollBars.Both;
        	this.textBoxLog.Size = new System.Drawing.Size(601, 172);
        	this.textBoxLog.TabIndex = 1;
        	this.textBoxLog.KeyDown += new System.Windows.Forms.KeyEventHandler(this.MainForm1_KeyDown);
        	// 
        	// textBoxToSend
        	// 
        	this.textBoxToSend.Location = new System.Drawing.Point(16, 33);
        	this.textBoxToSend.Margin = new System.Windows.Forms.Padding(4);
        	this.textBoxToSend.Name = "textBoxToSend";
        	this.textBoxToSend.Size = new System.Drawing.Size(132, 22);
        	this.textBoxToSend.TabIndex = 2;
        	this.textBoxToSend.KeyDown += new System.Windows.Forms.KeyEventHandler(this.textBoxToSend_KeyDown);
        	// 
        	// button1
        	// 
        	this.button1.Location = new System.Drawing.Point(179, 30);
        	this.button1.Margin = new System.Windows.Forms.Padding(4);
        	this.button1.Name = "button1";
        	this.button1.Size = new System.Drawing.Size(141, 28);
        	this.button1.TabIndex = 3;
        	this.button1.Text = "buttonTestSend";
        	this.button1.UseVisualStyleBackColor = true;
        	this.button1.Visible = false;
        	this.button1.Click += new System.EventHandler(this.button1_Click);
        	// 
        	// buttonToolLiftUp
        	// 
        	this.buttonToolLiftUp.Location = new System.Drawing.Point(80, 309);
        	this.buttonToolLiftUp.Margin = new System.Windows.Forms.Padding(4);
        	this.buttonToolLiftUp.Name = "buttonToolLiftUp";
        	this.buttonToolLiftUp.Size = new System.Drawing.Size(171, 28);
        	this.buttonToolLiftUp.TabIndex = 6;
        	this.buttonToolLiftUp.Text = "Подача - ВВЕРХ";
        	this.buttonToolLiftUp.UseVisualStyleBackColor = true;
        	this.buttonToolLiftUp.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	this.buttonToolLiftUp.KeyDown += new System.Windows.Forms.KeyEventHandler(this.MainForm1_KeyDown);
        	// 
        	// buttonToolLiftDown
        	// 
        	this.buttonToolLiftDown.Location = new System.Drawing.Point(80, 345);
        	this.buttonToolLiftDown.Margin = new System.Windows.Forms.Padding(4);
        	this.buttonToolLiftDown.Name = "buttonToolLiftDown";
        	this.buttonToolLiftDown.Size = new System.Drawing.Size(171, 28);
        	this.buttonToolLiftDown.TabIndex = 7;
        	this.buttonToolLiftDown.Text = "Подача - ВНИЗ";
        	this.buttonToolLiftDown.UseVisualStyleBackColor = true;
        	this.buttonToolLiftDown.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonToolLiftStop
        	// 
        	this.buttonToolLiftStop.Location = new System.Drawing.Point(80, 380);
        	this.buttonToolLiftStop.Margin = new System.Windows.Forms.Padding(4);
        	this.buttonToolLiftStop.Name = "buttonToolLiftStop";
        	this.buttonToolLiftStop.Size = new System.Drawing.Size(171, 28);
        	this.buttonToolLiftStop.TabIndex = 8;
        	this.buttonToolLiftStop.Text = "Подача - СТОП";
        	this.buttonToolLiftStop.UseVisualStyleBackColor = true;
        	this.buttonToolLiftStop.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonToolRotateRun
        	// 
        	this.buttonToolRotateRun.Location = new System.Drawing.Point(80, 446);
        	this.buttonToolRotateRun.Margin = new System.Windows.Forms.Padding(4);
        	this.buttonToolRotateRun.Name = "buttonToolRotateRun";
        	this.buttonToolRotateRun.Size = new System.Drawing.Size(171, 28);
        	this.buttonToolRotateRun.TabIndex = 9;
        	this.buttonToolRotateRun.Text = "Вращение - ПУСК";
        	this.buttonToolRotateRun.UseVisualStyleBackColor = true;
        	this.buttonToolRotateRun.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonToolRotateStop
        	// 
        	this.buttonToolRotateStop.Location = new System.Drawing.Point(80, 482);
        	this.buttonToolRotateStop.Margin = new System.Windows.Forms.Padding(4);
        	this.buttonToolRotateStop.Name = "buttonToolRotateStop";
        	this.buttonToolRotateStop.Size = new System.Drawing.Size(171, 28);
        	this.buttonToolRotateStop.TabIndex = 10;
        	this.buttonToolRotateStop.Text = "Вращение - СТОП";
        	this.buttonToolRotateStop.UseVisualStyleBackColor = true;
        	this.buttonToolRotateStop.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonToolStop
        	// 
        	this.buttonToolStop.Location = new System.Drawing.Point(80, 544);
        	this.buttonToolStop.Margin = new System.Windows.Forms.Padding(4);
        	this.buttonToolStop.Name = "buttonToolStop";
        	this.buttonToolStop.Size = new System.Drawing.Size(171, 28);
        	this.buttonToolStop.TabIndex = 11;
        	this.buttonToolStop.Text = "ОСТАНОВ";
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
        	this.labelCurrentToolPosition.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
        	this.labelCurrentToolPosition.Location = new System.Drawing.Point(80, 75);
        	this.labelCurrentToolPosition.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
        	this.labelCurrentToolPosition.Name = "labelCurrentToolPosition";
        	this.labelCurrentToolPosition.Size = new System.Drawing.Size(182, 20);
        	this.labelCurrentToolPosition.TabIndex = 12;
        	this.labelCurrentToolPosition.Text = "CurrentToolPosition:";
        	// 
        	// labelCurrentSensor
        	// 
        	this.labelCurrentSensor.AutoSize = true;
        	this.labelCurrentSensor.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
        	this.labelCurrentSensor.Location = new System.Drawing.Point(16, 849);
        	this.labelCurrentSensor.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
        	this.labelCurrentSensor.Name = "labelCurrentSensor";
        	this.labelCurrentSensor.Size = new System.Drawing.Size(137, 20);
        	this.labelCurrentSensor.TabIndex = 13;
        	this.labelCurrentSensor.Text = "CurrentSensor:";
        	// 
        	// labelUpperToolTipState
        	// 
        	this.labelUpperToolTipState.AutoSize = true;
        	this.labelUpperToolTipState.Location = new System.Drawing.Point(80, 598);
        	this.labelUpperToolTipState.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
        	this.labelUpperToolTipState.Name = "labelUpperToolTipState";
        	this.labelUpperToolTipState.Size = new System.Drawing.Size(132, 17);
        	this.labelUpperToolTipState.TabIndex = 14;
        	this.labelUpperToolTipState.Text = "UpperToolTipState:";
        	// 
        	// labelLowerToolTipState
        	// 
        	this.labelLowerToolTipState.AutoSize = true;
        	this.labelLowerToolTipState.Location = new System.Drawing.Point(80, 634);
        	this.labelLowerToolTipState.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
        	this.labelLowerToolTipState.Name = "labelLowerToolTipState";
        	this.labelLowerToolTipState.Size = new System.Drawing.Size(131, 17);
        	this.labelLowerToolTipState.TabIndex = 15;
        	this.labelLowerToolTipState.Text = "LowerToolTipState:";
        	// 
        	// progressBar1
        	// 
        	this.progressBar1.Location = new System.Drawing.Point(16, 835);
        	this.progressBar1.Margin = new System.Windows.Forms.Padding(4);
        	this.progressBar1.Maximum = 4096;
        	this.progressBar1.Name = "progressBar1";
        	this.progressBar1.Size = new System.Drawing.Size(683, 10);
        	this.progressBar1.Step = 1;
        	this.progressBar1.TabIndex = 16;
        	// 
        	// trackBarPosition
        	// 
        	this.trackBarPosition.BackColor = System.Drawing.SystemColors.ControlDark;
        	this.trackBarPosition.Enabled = false;
        	this.trackBarPosition.Location = new System.Drawing.Point(16, 63);
        	this.trackBarPosition.Margin = new System.Windows.Forms.Padding(4);
        	this.trackBarPosition.Maximum = 4000;
        	this.trackBarPosition.Minimum = -100;
        	this.trackBarPosition.Name = "trackBarPosition";
        	this.trackBarPosition.Orientation = System.Windows.Forms.Orientation.Vertical;
        	this.trackBarPosition.RightToLeft = System.Windows.Forms.RightToLeft.No;
        	this.trackBarPosition.Size = new System.Drawing.Size(56, 764);
        	this.trackBarPosition.TabIndex = 17;
        	this.trackBarPosition.TickFrequency = 10;
        	// 
        	// buttonVerticalFeedMotorOn
        	// 
        	this.buttonVerticalFeedMotorOn.Location = new System.Drawing.Point(80, 204);
        	this.buttonVerticalFeedMotorOn.Margin = new System.Windows.Forms.Padding(4);
        	this.buttonVerticalFeedMotorOn.Name = "buttonVerticalFeedMotorOn";
        	this.buttonVerticalFeedMotorOn.Size = new System.Drawing.Size(171, 28);
        	this.buttonVerticalFeedMotorOn.TabIndex = 18;
        	this.buttonVerticalFeedMotorOn.Text = "Мотор подачи - ПУСК";
        	this.buttonVerticalFeedMotorOn.UseVisualStyleBackColor = true;
        	this.buttonVerticalFeedMotorOn.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonVerticalFeedMotorOff
        	// 
        	this.buttonVerticalFeedMotorOff.Location = new System.Drawing.Point(80, 240);
        	this.buttonVerticalFeedMotorOff.Margin = new System.Windows.Forms.Padding(4);
        	this.buttonVerticalFeedMotorOff.Name = "buttonVerticalFeedMotorOff";
        	this.buttonVerticalFeedMotorOff.Size = new System.Drawing.Size(171, 28);
        	this.buttonVerticalFeedMotorOff.TabIndex = 19;
        	this.buttonVerticalFeedMotorOff.Text = "Мотор подачи - СТОП";
        	this.buttonVerticalFeedMotorOff.UseVisualStyleBackColor = true;
        	this.buttonVerticalFeedMotorOff.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonKey_1
        	// 
        	this.buttonKey_1.Location = new System.Drawing.Point(510, 133);
        	this.buttonKey_1.Margin = new System.Windows.Forms.Padding(4);
        	this.buttonKey_1.Name = "buttonKey_1";
        	this.buttonKey_1.Size = new System.Drawing.Size(171, 28);
        	this.buttonKey_1.TabIndex = 20;
        	this.buttonKey_1.Text = "Key_1(Позиция 0)";
        	this.buttonKey_1.UseVisualStyleBackColor = true;
        	this.buttonKey_1.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonKey_2
        	// 
        	this.buttonKey_2.Location = new System.Drawing.Point(510, 169);
        	this.buttonKey_2.Margin = new System.Windows.Forms.Padding(4);
        	this.buttonKey_2.Name = "buttonKey_2";
        	this.buttonKey_2.Size = new System.Drawing.Size(171, 28);
        	this.buttonKey_2.TabIndex = 21;
        	this.buttonKey_2.Text = "Key_2(толчковый)";
        	this.buttonKey_2.UseVisualStyleBackColor = true;
        	this.buttonKey_2.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonKey_3
        	// 
        	this.buttonKey_3.Location = new System.Drawing.Point(510, 204);
        	this.buttonKey_3.Margin = new System.Windows.Forms.Padding(4);
        	this.buttonKey_3.Name = "buttonKey_3";
        	this.buttonKey_3.Size = new System.Drawing.Size(171, 28);
        	this.buttonKey_3.TabIndex = 22;
        	this.buttonKey_3.Text = "Key_3(уст.диапазона)";
        	this.buttonKey_3.UseVisualStyleBackColor = true;
        	this.buttonKey_3.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonKey_4
        	// 
        	this.buttonKey_4.Location = new System.Drawing.Point(510, 240);
        	this.buttonKey_4.Margin = new System.Windows.Forms.Padding(4);
        	this.buttonKey_4.Name = "buttonKey_4";
        	this.buttonKey_4.Size = new System.Drawing.Size(171, 28);
        	this.buttonKey_4.TabIndex = 23;
        	this.buttonKey_4.Text = "Key_4(уск.возврат в раб.)";
        	this.buttonKey_4.UseVisualStyleBackColor = true;
        	this.buttonKey_4.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonKey_5
        	// 
        	this.buttonKey_5.Location = new System.Drawing.Point(510, 276);
        	this.buttonKey_5.Margin = new System.Windows.Forms.Padding(4);
        	this.buttonKey_5.Name = "buttonKey_5";
        	this.buttonKey_5.Size = new System.Drawing.Size(171, 28);
        	this.buttonKey_5.TabIndex = 24;
        	this.buttonKey_5.Text = "Key_5(работа)";
        	this.buttonKey_5.UseVisualStyleBackColor = true;
        	this.buttonKey_5.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonKey_6
        	// 
        	this.buttonKey_6.Location = new System.Drawing.Point(510, 312);
        	this.buttonKey_6.Margin = new System.Windows.Forms.Padding(4);
        	this.buttonKey_6.Name = "buttonKey_6";
        	this.buttonKey_6.Size = new System.Drawing.Size(171, 28);
        	this.buttonKey_6.TabIndex = 25;
        	this.buttonKey_6.Text = "Key_6(семенящее)";
        	this.buttonKey_6.UseVisualStyleBackColor = true;
        	this.buttonKey_6.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonKey_7
        	// 
        	this.buttonKey_7.Location = new System.Drawing.Point(510, 347);
        	this.buttonKey_7.Margin = new System.Windows.Forms.Padding(4);
        	this.buttonKey_7.Name = "buttonKey_7";
        	this.buttonKey_7.Size = new System.Drawing.Size(171, 28);
        	this.buttonKey_7.TabIndex = 26;
        	this.buttonKey_7.Text = "Key_7(общий стоп)";
        	this.buttonKey_7.UseVisualStyleBackColor = true;
        	this.buttonKey_7.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonKey_8
        	// 
        	this.buttonKey_8.Location = new System.Drawing.Point(510, 383);
        	this.buttonKey_8.Margin = new System.Windows.Forms.Padding(4);
        	this.buttonKey_8.Name = "buttonKey_8";
        	this.buttonKey_8.Size = new System.Drawing.Size(171, 28);
        	this.buttonKey_8.TabIndex = 27;
        	this.buttonKey_8.Text = "Key_8(подача вкл)";
        	this.buttonKey_8.UseVisualStyleBackColor = true;
        	this.buttonKey_8.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonKey_9
        	// 
        	this.buttonKey_9.Location = new System.Drawing.Point(510, 419);
        	this.buttonKey_9.Margin = new System.Windows.Forms.Padding(4);
        	this.buttonKey_9.Name = "buttonKey_9";
        	this.buttonKey_9.Size = new System.Drawing.Size(171, 28);
        	this.buttonKey_9.TabIndex = 28;
        	this.buttonKey_9.Text = "Key_9";
        	this.buttonKey_9.UseVisualStyleBackColor = true;
        	this.buttonKey_9.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// buttonSWITCH
        	// 
        	this.buttonSWITCH.Location = new System.Drawing.Point(80, 133);
        	this.buttonSWITCH.Margin = new System.Windows.Forms.Padding(4);
        	this.buttonSWITCH.Name = "buttonSWITCH";
        	this.buttonSWITCH.Size = new System.Drawing.Size(171, 28);
        	this.buttonSWITCH.TabIndex = 29;
        	this.buttonSWITCH.Text = "SWITCH(ручной)";
        	this.buttonSWITCH.UseVisualStyleBackColor = true;
        	this.buttonSWITCH.Click += new System.EventHandler(this.buttonsMachineDriving_Click);
        	// 
        	// labelStateOfWork
        	// 
        	this.labelStateOfWork.AutoSize = true;
        	this.labelStateOfWork.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
        	this.labelStateOfWork.Location = new System.Drawing.Point(337, 41);
        	this.labelStateOfWork.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
        	this.labelStateOfWork.Name = "labelStateOfWork";
        	this.labelStateOfWork.Size = new System.Drawing.Size(132, 25);
        	this.labelStateOfWork.TabIndex = 30;
        	this.labelStateOfWork.Text = "StateOfWork:";
        	// 
        	// MainForm1
        	// 
        	this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
        	this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
        	this.BackColor = System.Drawing.SystemColors.ControlDark;
        	this.ClientSize = new System.Drawing.Size(712, 902);
        	this.Controls.Add(this.labelStateOfWork);
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
        	this.Controls.Add(this.trackBarPosition);
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
        	this.Controls.Add(this.button1);
        	this.Controls.Add(this.textBoxToSend);
        	this.Controls.Add(this.textBoxLog);
        	this.Controls.Add(this.menuStrip1);
        	this.MainMenuStrip = this.menuStrip1;
        	this.Margin = new System.Windows.Forms.Padding(4);
        	this.Name = "MainForm1";
        	this.Text = "HoningMachineConfig";
        	this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.MainForm1_KeyDown);
        	this.menuStrip1.ResumeLayout(false);
        	this.menuStrip1.PerformLayout();
        	((System.ComponentModel.ISupportInitialize)(this.trackBarPosition)).EndInit();
        	this.ResumeLayout(false);
        	this.PerformLayout();
        }
        private System.Windows.Forms.Label labelStateOfWork;
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
        private System.Windows.Forms.TrackBar trackBarPosition;
        private System.Windows.Forms.Button buttonVerticalFeedMotorOn;
        private System.Windows.Forms.Button buttonVerticalFeedMotorOff;
    }
}

