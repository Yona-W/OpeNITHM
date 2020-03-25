using System;
using System.Drawing;
using System.Linq;
using System.IO.Ports;
using System.Threading;
using System.Windows.Forms;

namespace OpeNITHMConfig
{
    public partial class MainForm : Form
    {
        // magic byte for the header in config commands
        private const byte CONFIG_FLAG = 0xBB;

        // config command opcodes
        private const byte CMD_PRINT_INFO = 0x11;
        private const byte CMD_CHANGE_ON_COLOR = 0x22;
        private const byte CMD_CHANGE_OFF_COLOR = 0x33;
        private const byte CMD_CALIBRATE_SLIDER = 0x44;
        private const byte CMD_CALIBRATE_AIR_SENSORS = 0x55;
        private const byte CMD_FACTORY_RESET = 0x66;

        // the "maximum" sensitivity values, that we subtract the value of the sensitivity slider from
        // to send to the controller. lower values sent to the controller result in higher sensitivity
        // so we do the subtraction
        private const int MAX_SLIDER_SENSITIVITY = 95;
        private const int MAX_AIR_SENSITIVITY = 55;

        // default values for the sensitivity sliders
        private const int DEFAULT_TOUCH_SENSITIVITY = 19;
        private const int DEFAULT_AIR_SENSITIVITY = 15;

        // default key colors
        private Color ON_COLOR = Color.Purple;
        private Color OFF_COLOR = Color.Yellow;

        /// <summary>
        /// Whether or not the controller is connected
        /// </summary>
        private bool isConnected;

        /// <summary>
        /// The port used to communicate with the controller
        /// </summary>
        private SerialPort serialPort;

        public MainForm()
        {
            InitializeComponent();

            serialPort = new SerialPort();
            serialPort.BaudRate = 115200;
            serialPort.Parity = Parity.None;
            serialPort.DataBits = 8;
            serialPort.StopBits = StopBits.One;
            serialPort.Handshake = Handshake.None;
            serialPort.ReadTimeout = 1000;
            serialPort.WriteTimeout = 1000;

            isConnected = false;
        }

        /// <summary>
        /// Enables the appropriate sets of controls in the main form
        /// </summary>
        /// <param name="analogAirSensors"></param>
        private void enableControls(bool analogAirSensors)
        {
            grpSliderConfig.Enabled = true;
            grpReactiveLightsConfig.Enabled = true;
            mnuFactoryReset.Enabled = true;

            if (analogAirSensors)
            {
                grpAirConfig.Enabled = true;
                grpAirConfig.Text = "Air sensor configuration";
            }
        }

        /// <summary>
        /// Disables all the main form controls
        /// </summary>
        private void disableControls()
        {
            grpSliderConfig.Enabled = false;
            grpReactiveLightsConfig.Enabled = false;
            mnuFactoryReset.Enabled = false;
            grpAirConfig.Enabled = false;
            grpAirConfig.Text = "Air sensor configuration (analog air sensors only)";
        }

        /// <summary>
        /// Sends a command and its arguments to the controller
        /// </summary>
        /// <param name="command"></param>
        /// <param name="args"></param>
        /// <param name="close"></param>
        private void sendCommand(byte command, byte[] args, bool close = true)
        {
            try
            {
                if (isConnected)
                {
                    byte[] data = new byte[200];

                    // command header
                    data[0] = CONFIG_FLAG;
                    data[1] = CONFIG_FLAG;

                    // command opcode
                    data[2] = command;

                    // command data
                    Array.Copy(args, 0, data, 3, args.Length);

                    // send the data
                    serialPort.Open();
                    serialPort.Write(data, 0, 200);

                    if (close)
                        serialPort.Close();
                }
            }
            catch (InvalidOperationException)
            {
                // serial port was likely closed
                isConnected = false;
                disableControls();
            }
        }

        /// <summary>
        /// Connects to a new controller and initializaes our values
        /// </summary>
        /// <param name="port"></param>
        /// <param name="sender"></param>
        private void ConnectToController(string port, ToolStripMenuItem sender)
        {
            serialPort.PortName = port;

            // get the current info from the controller
            isConnected = true;
            //enableControls(false);
            sendCommand(CMD_PRINT_INFO, new byte[]{}, false);
            Thread.Sleep(500);

            byte[] info = new byte[200];

            try
            {
                serialPort.Read(info, 0, 200);
                serialPort.Close();

                bool isAnalogAir = (info[0] == 0x11);
                colorDialogOn.Color = Color.FromArgb(info[1], info[2], info[3]);
                colorDialogOff.Color = Color.FromArgb(info[4], info[5], info[6]);
                trkSliderSensitivity.Value = MAX_SLIDER_SENSITIVITY - info[7];
                trkAirSensitivity.Value = MAX_AIR_SENSITIVITY - info[8];
                
                enableControls(isAnalogAir);
            }
            catch (TimeoutException ex)
            {
                // serial timeout, don't enable anything
                isConnected = false;
                sender.Enabled = false;
                disableControls();
            }
        }

        /// <summary>
        /// Show the "About" dialog
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void mnuAbout_Click(object sender, EventArgs e)
        {
            MessageBox.Show("This tool is a configuration application for any OpeNITHM controllers running the following firmware: https://github.com/skogaby/OpeNITHM",
                "About",
                MessageBoxButtons.OK);
        }

        /// <summary>
        /// Changes the color of the slider's "on" lights in reactive lighting mode
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnSliderOnColor_Click(object sender, EventArgs e)
        {
            if (colorDialogOn.ShowDialog() == DialogResult.OK)
            {
                sendCommand(CMD_CHANGE_ON_COLOR, new byte[] {
                    colorDialogOn.Color.R,
                    colorDialogOn.Color.G,
                    colorDialogOn.Color.B
                });
            }
        }

        /// <summary>
        /// Changes the color of the slider's "off" lights in reactive lighting mode
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnSliderOffColor_Click(object sender, EventArgs e)
        {
            if (colorDialogOff.ShowDialog() == DialogResult.OK)
            {
                sendCommand(CMD_CHANGE_OFF_COLOR, new byte[] {
                    colorDialogOff.Color.R,
                    colorDialogOff.Color.G,
                    colorDialogOff.Color.B
                });
            }
        }

        /// <summary>
        /// Forces a re-calibration of the touch slider
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnCalibrateSlider_Click(object sender, EventArgs e)
        {
            sendCommand(CMD_CALIBRATE_SLIDER, new byte[] { (byte) (MAX_SLIDER_SENSITIVITY - trkSliderSensitivity.Value) });
        }

        /// <summary>
        /// Forces a re-calibration of the air sensors
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnCalibrateAir_Click(object sender, EventArgs e)
        {
            sendCommand(CMD_CALIBRATE_AIR_SENSORS, new byte[] { (byte) (MAX_AIR_SENSITIVITY - trkAirSensitivity.Value) });
        }

        /// <summary>
        /// Every time the timer ticks, we'll refresh the COM ports on the file submenu
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void tmrComPorts_Tick(object sender, EventArgs e)
        {
            // read the available COM ports
            string[] ports = SerialPort.GetPortNames();

            // update the menu if the set doesn't match what we have loaded
            mnuComPort.Enabled = (ports.Length != 0);

            if (mnuComPort.DropDownItems.Count != ports.Length)
            {
                mnuComPort.DropDownItems.Clear();

                foreach (string port in ports)
                {
                    // set the click handler for the menu items
                    ToolStripItem item = new ToolStripMenuItem(port, null, new EventHandler(delegate (Object o, EventArgs a)
                    {
                        ConnectToController(((ToolStripItem) o).Text, (ToolStripMenuItem) o);
                        ((ToolStripMenuItem) o).Checked = true;
                    }));

                    mnuComPort.DropDownItems.Add(item);
                }
            }

            // if we were connected and now the selected port is no longer present,
            // assume we disconnected
            if (isConnected && !ports.Contains(serialPort.PortName))
            {
                isConnected = false;
                disableControls();
            }
        }

        /// <summary>
        /// Clears the controller's EEPROM and re-initializes the default settings / goes through calibration again
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void factoryResetControllerToolStripMenuItem_Click(object sender, EventArgs e)
        {
            colorDialogOn.Color = ON_COLOR;
            colorDialogOff.Color = OFF_COLOR;
            trkSliderSensitivity.Value = DEFAULT_TOUCH_SENSITIVITY;
            trkAirSensitivity.Value = DEFAULT_AIR_SENSITIVITY;

            sendCommand(CMD_FACTORY_RESET, new byte[] { });
        }
    }
}
