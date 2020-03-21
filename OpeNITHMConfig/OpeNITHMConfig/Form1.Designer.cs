namespace OpeNITHMConfig
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.mnuComPort = new System.Windows.Forms.ToolStripMenuItem();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.mnuFactoryReset = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.mnuExit = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.mnuAbout = new System.Windows.Forms.ToolStripMenuItem();
            this.tmrComPorts = new System.Windows.Forms.Timer(this.components);
            this.grpSliderConfig = new System.Windows.Forms.GroupBox();
            this.grpSliderCalibration = new System.Windows.Forms.GroupBox();
            this.btnCalibrateSlider = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.trkSliderSensitivity = new System.Windows.Forms.TrackBar();
            this.grpReactiveLightsConfig = new System.Windows.Forms.GroupBox();
            this.btnSliderOnColor = new System.Windows.Forms.Button();
            this.btnSliderOffColor = new System.Windows.Forms.Button();
            this.grpAirConfig = new System.Windows.Forms.GroupBox();
            this.btnCalibrateAir = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.trkAirSensitivity = new System.Windows.Forms.TrackBar();
            this.colorDialogOn = new System.Windows.Forms.ColorDialog();
            this.colorDialogOff = new System.Windows.Forms.ColorDialog();
            this.menuStrip1.SuspendLayout();
            this.grpSliderConfig.SuspendLayout();
            this.grpSliderCalibration.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trkSliderSensitivity)).BeginInit();
            this.grpReactiveLightsConfig.SuspendLayout();
            this.grpAirConfig.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trkAirSensitivity)).BeginInit();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(5, 5);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(301, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnuComPort,
            this.mnuFactoryReset,
            this.toolStripSeparator2,
            this.mnuExit});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // mnuComPort
            // 
            this.mnuComPort.DropDown = this.contextMenuStrip1;
            this.mnuComPort.Name = "mnuComPort";
            this.mnuComPort.Size = new System.Drawing.Size(195, 22);
            this.mnuComPort.Text = "Select COM port";
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
            // 
            // mnuFactoryReset
            // 
            this.mnuFactoryReset.Enabled = false;
            this.mnuFactoryReset.Name = "mnuFactoryReset";
            this.mnuFactoryReset.Size = new System.Drawing.Size(195, 22);
            this.mnuFactoryReset.Text = "Factory reset controller";
            this.mnuFactoryReset.Click += new System.EventHandler(this.factoryResetControllerToolStripMenuItem_Click);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(192, 6);
            // 
            // mnuExit
            // 
            this.mnuExit.Name = "mnuExit";
            this.mnuExit.Size = new System.Drawing.Size(195, 22);
            this.mnuExit.Text = "Exit";
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnuAbout});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.helpToolStripMenuItem.Text = "Help";
            // 
            // mnuAbout
            // 
            this.mnuAbout.Name = "mnuAbout";
            this.mnuAbout.Size = new System.Drawing.Size(107, 22);
            this.mnuAbout.Text = "About";
            this.mnuAbout.Click += new System.EventHandler(this.mnuAbout_Click);
            // 
            // tmrComPorts
            // 
            this.tmrComPorts.Enabled = true;
            this.tmrComPorts.Interval = 1000;
            this.tmrComPorts.Tick += new System.EventHandler(this.tmrComPorts_Tick);
            // 
            // grpSliderConfig
            // 
            this.grpSliderConfig.Controls.Add(this.grpSliderCalibration);
            this.grpSliderConfig.Controls.Add(this.grpReactiveLightsConfig);
            this.grpSliderConfig.Enabled = false;
            this.grpSliderConfig.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.grpSliderConfig.Location = new System.Drawing.Point(8, 32);
            this.grpSliderConfig.Name = "grpSliderConfig";
            this.grpSliderConfig.Size = new System.Drawing.Size(294, 260);
            this.grpSliderConfig.TabIndex = 2;
            this.grpSliderConfig.TabStop = false;
            this.grpSliderConfig.Text = "Slider configuration";
            // 
            // grpSliderCalibration
            // 
            this.grpSliderCalibration.Controls.Add(this.btnCalibrateSlider);
            this.grpSliderCalibration.Controls.Add(this.label1);
            this.grpSliderCalibration.Controls.Add(this.trkSliderSensitivity);
            this.grpSliderCalibration.Location = new System.Drawing.Point(6, 137);
            this.grpSliderCalibration.Name = "grpSliderCalibration";
            this.grpSliderCalibration.Size = new System.Drawing.Size(283, 122);
            this.grpSliderCalibration.TabIndex = 3;
            this.grpSliderCalibration.TabStop = false;
            this.grpSliderCalibration.Text = "Touch adjustment";
            // 
            // btnCalibrateSlider
            // 
            this.btnCalibrateSlider.Location = new System.Drawing.Point(6, 79);
            this.btnCalibrateSlider.Name = "btnCalibrateSlider";
            this.btnCalibrateSlider.Size = new System.Drawing.Size(271, 35);
            this.btnCalibrateSlider.TabIndex = 8;
            this.btnCalibrateSlider.Text = "Re-calibrate slider";
            this.btnCalibrateSlider.UseVisualStyleBackColor = true;
            this.btnCalibrateSlider.Click += new System.EventHandler(this.btnCalibrateSlider_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(215, 13);
            this.label1.TabIndex = 7;
            this.label1.Text = "Touch sensitivity (applied during calibration):";
            // 
            // trkSliderSensitivity
            // 
            this.trkSliderSensitivity.Location = new System.Drawing.Point(6, 38);
            this.trkSliderSensitivity.Maximum = 25;
            this.trkSliderSensitivity.Name = "trkSliderSensitivity";
            this.trkSliderSensitivity.Size = new System.Drawing.Size(271, 45);
            this.trkSliderSensitivity.TabIndex = 6;
            // 
            // grpReactiveLightsConfig
            // 
            this.grpReactiveLightsConfig.Controls.Add(this.btnSliderOnColor);
            this.grpReactiveLightsConfig.Controls.Add(this.btnSliderOffColor);
            this.grpReactiveLightsConfig.Enabled = false;
            this.grpReactiveLightsConfig.Location = new System.Drawing.Point(6, 17);
            this.grpReactiveLightsConfig.Name = "grpReactiveLightsConfig";
            this.grpReactiveLightsConfig.Size = new System.Drawing.Size(283, 114);
            this.grpReactiveLightsConfig.TabIndex = 5;
            this.grpReactiveLightsConfig.TabStop = false;
            this.grpReactiveLightsConfig.Text = "Reactive lighting colors";
            // 
            // btnSliderOnColor
            // 
            this.btnSliderOnColor.Location = new System.Drawing.Point(6, 66);
            this.btnSliderOnColor.Name = "btnSliderOnColor";
            this.btnSliderOnColor.Size = new System.Drawing.Size(271, 35);
            this.btnSliderOnColor.TabIndex = 3;
            this.btnSliderOnColor.Text = "Change slider key \"on\" color";
            this.btnSliderOnColor.UseVisualStyleBackColor = true;
            this.btnSliderOnColor.Click += new System.EventHandler(this.btnSliderOnColor_Click);
            // 
            // btnSliderOffColor
            // 
            this.btnSliderOffColor.Location = new System.Drawing.Point(6, 23);
            this.btnSliderOffColor.Name = "btnSliderOffColor";
            this.btnSliderOffColor.Size = new System.Drawing.Size(271, 35);
            this.btnSliderOffColor.TabIndex = 4;
            this.btnSliderOffColor.Text = "Change slider key \"off\" color";
            this.btnSliderOffColor.UseVisualStyleBackColor = true;
            this.btnSliderOffColor.Click += new System.EventHandler(this.btnSliderOffColor_Click);
            // 
            // grpAirConfig
            // 
            this.grpAirConfig.Controls.Add(this.btnCalibrateAir);
            this.grpAirConfig.Controls.Add(this.label2);
            this.grpAirConfig.Controls.Add(this.trkAirSensitivity);
            this.grpAirConfig.Enabled = false;
            this.grpAirConfig.Location = new System.Drawing.Point(12, 298);
            this.grpAirConfig.Name = "grpAirConfig";
            this.grpAirConfig.Size = new System.Drawing.Size(294, 127);
            this.grpAirConfig.TabIndex = 3;
            this.grpAirConfig.TabStop = false;
            this.grpAirConfig.Text = "Air sensor configuration (analog air sensors only)";
            // 
            // btnCalibrateAir
            // 
            this.btnCalibrateAir.Location = new System.Drawing.Point(12, 84);
            this.btnCalibrateAir.Name = "btnCalibrateAir";
            this.btnCalibrateAir.Size = new System.Drawing.Size(271, 35);
            this.btnCalibrateAir.TabIndex = 8;
            this.btnCalibrateAir.Text = "Re-calibrate air sensors";
            this.btnCalibrateAir.UseVisualStyleBackColor = true;
            this.btnCalibrateAir.Click += new System.EventHandler(this.btnCalibrateAir_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 28);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(196, 13);
            this.label2.TabIndex = 7;
            this.label2.Text = "Air sensitivity (applied during calibration):";
            // 
            // trkAirSensitivity
            // 
            this.trkAirSensitivity.Location = new System.Drawing.Point(12, 44);
            this.trkAirSensitivity.Maximum = 25;
            this.trkAirSensitivity.Name = "trkAirSensitivity";
            this.trkAirSensitivity.Size = new System.Drawing.Size(271, 45);
            this.trkAirSensitivity.TabIndex = 6;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(311, 433);
            this.Controls.Add(this.grpAirConfig);
            this.Controls.Add(this.grpSliderConfig);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.MaximizeBox = false;
            this.Name = "MainForm";
            this.Padding = new System.Windows.Forms.Padding(5);
            this.Text = "OpeNITHM Config";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.grpSliderConfig.ResumeLayout(false);
            this.grpSliderCalibration.ResumeLayout(false);
            this.grpSliderCalibration.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trkSliderSensitivity)).EndInit();
            this.grpReactiveLightsConfig.ResumeLayout(false);
            this.grpAirConfig.ResumeLayout(false);
            this.grpAirConfig.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trkAirSensitivity)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem mnuComPort;
        private System.Windows.Forms.ToolStripMenuItem mnuExit;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem mnuAbout;
        private System.Windows.Forms.Timer tmrComPorts;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.GroupBox grpSliderConfig;
        private System.Windows.Forms.GroupBox grpSliderCalibration;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TrackBar trkSliderSensitivity;
        private System.Windows.Forms.GroupBox grpReactiveLightsConfig;
        private System.Windows.Forms.Button btnSliderOnColor;
        private System.Windows.Forms.Button btnSliderOffColor;
        private System.Windows.Forms.Button btnCalibrateSlider;
        private System.Windows.Forms.GroupBox grpAirConfig;
        private System.Windows.Forms.Button btnCalibrateAir;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TrackBar trkAirSensitivity;
        private System.Windows.Forms.ColorDialog colorDialogOn;
        private System.Windows.Forms.ToolStripMenuItem mnuFactoryReset;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ColorDialog colorDialogOff;
    }
}

