using System;
using System.Linq;
using System.IO.Ports;
using System.Windows.Forms;

namespace OpeNITHMConfig
{
    public partial class MainForm : Form
    {
        // magic byte for the header in config commands
        private const byte CONFIG_FLAG = 0xBB;

        // config command opcodes
        private const byte CMD_CHANGE_LIGHT_MODE = 0x11;
        private const byte CMD_CHANGE_ON_COLOR = 0x22;
        private const byte CMD_CHANGE_OFF_COLOR = 0x33;
        private const byte CMD_CALIBRATE_SLIDER = 0x44;
        private const byte CMD_CALIBRATE_AIR_SENSORS = 0x55;

        // light modes for the change light mode command
        private const byte LIGHT_MODE_SERIAL = 0x00;
        private const byte LIGHT_MODE_REACTIVE = 0x01;

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
        /// <param name="reactiveLighting"></param>
        /// <param name="analogAirSensors"></param>
        private void enableControls(bool reactiveLighting, bool analogAirSensors)
        {
            grpSliderConfig.Enabled = true;
            grpReactiveLightsConfig.Enabled = reactiveLighting;
            grpAirConfig.Enabled = analogAirSensors;
        }

        /// <summary>
        /// Disables all the main form controls
        /// </summary>
        private void disableControls()
        {
            grpSliderConfig.Enabled = false;
            grpReactiveLightsConfig.Enabled = false;
            grpAirConfig.Enabled = false;
        }

        /// <summary>
        /// Connects to a new controller and initializes our values
        /// </summary>
        /// <param name="port"></param>
        private void ConnectToController(string port)
        {
            serialPort.PortName = port;
            isConnected = true;
            enableControls(true, true);
        }

        /// <summary>
        /// Sends a command and its arguments to the controller
        /// </summary>
        /// <param name="command"></param>
        /// <param name="args"></param>
        private void sendCommand(byte command, byte[] args)
        {
            try
            {
                if (isConnected)
                {
                    byte[] data = new byte[100];

                    // command header
                    data[0] = CONFIG_FLAG;
                    data[1] = CONFIG_FLAG;

                    // command opcode
                    data[2] = command;

                    // command data
                    Array.Copy(args, 0, data, 3, args.Length);

                    // send the data
                    serialPort.Open();
                    serialPort.Write(data, 0, 100);
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
        /// Changes the lighting mode of the controller
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnChangeLightMode_Click(object sender, EventArgs e)
        {
            byte lightMode = (radHidLighting.Checked ? LIGHT_MODE_SERIAL : LIGHT_MODE_REACTIVE);

            sendCommand(CMD_CHANGE_LIGHT_MODE, new byte[] { lightMode });
        }

        /// <summary>
        /// Changes the color of the slider's "on" lights in reactive lighting mode
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnSliderOnColor_Click(object sender, EventArgs e)
        {
            if (colorDialog.ShowDialog() == DialogResult.OK)
            {
                sendCommand(CMD_CHANGE_ON_COLOR, new byte[] {
                    colorDialog.Color.R,
                    colorDialog.Color.G,
                    colorDialog.Color.B
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
            if (colorDialog.ShowDialog() == DialogResult.OK)
            {
                sendCommand(CMD_CHANGE_OFF_COLOR, new byte[] {
                    colorDialog.Color.R,
                    colorDialog.Color.G,
                    colorDialog.Color.B
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
            sendCommand(CMD_CALIBRATE_SLIDER, new byte[] { (byte) trkSliderSensitivity.Value });
        }

        /// <summary>
        /// Forces a re-calibration of the air sensors
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnCalibrateAir_Click(object sender, EventArgs e)
        {
            sendCommand(CMD_CALIBRATE_AIR_SENSORS, new byte[] { (byte) trkAirSensitivity.Value });
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
                        ConnectToController(((ToolStripItem)o).Text);
                        ((ToolStripMenuItem)o).Checked = true;
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
    }
}
