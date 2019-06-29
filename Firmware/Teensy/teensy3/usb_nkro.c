// Via https://dawnmist.dreamwidth.org/1250.html
#include "usb_dev.h"
#include "usb_nkro.h"
#include "core_pins.h" // for yield()
#include "keylayouts.h"
//#include "HardwareSerial.h"
#include <string.h> // for memcpy()

#ifdef NKRO_INTERFACE // defined by usb_dev.h -> usb_desc.h

// byte0: which modifier keys are currently pressed
//  1=left ctrl,    2=left shift,   4=left alt,    8=left gui
//  16=right ctrl, 32=right shift, 64=right alt, 128=right gui
// bytes1-NKRO_SIZE: which keys are currently pressed, one bit
// per key for codes 0 to ((8*NKRO_REPORT_SIZE) - 1)
uint8_t nkro_report_data[NKRO_SIZE];

// protocol setting from the host.  We use exactly the same report
// either way, so this variable only stores the setting since we
// are required to be able to report which setting is in use.
uint8_t nkro_protocol=1;

// the idle configuration, how often we send the report to the
// host (ms * 4) even when it hasn't changed
uint8_t nkro_idle_config=125;

// count until idle timeout
uint8_t nkro_idle_count=0;


// NKRO Keyboard
void usb_nkro_reset_keys()
{
    uint8_t index;
    for (index=0; index < NKRO_SIZE; index++)
    {
        nkro_report_data[index] = 0;
    }
}

void usb_nkro_reset_key(uint8_t usb_keycode)
{
    uint8_t bit = usb_keycode % 8;
    uint8_t byte = (usb_keycode / 8) + 1;

    if (usb_keycode >= 240 && usb_keycode <= 247)
    {
        // Reset a modifier key
        nkro_report_data[0] &= ~(1<< bit);
    }
    else if (byte > 0 && byte <= NKRO_REPORT_KEYS)
    {
        nkro_report_data[byte] &= ~(1 << bit);
    }
}

void usb_nkro_set_key(uint8_t usb_keycode)
{
    uint8_t bit = usb_keycode % 8;
    uint8_t byte = (usb_keycode / 8) + 1;

    if (usb_keycode >= 240 && usb_keycode <= 247)
    {
        // Reset a modifier key
        nkro_report_data[0] |= (1 << bit);
    }
    else if (byte > 0 && byte <= NKRO_REPORT_KEYS)
    {
        nkro_report_data[byte] |= (1 << bit);
    }
}

// Maximum number of transmit packets to queue so we don't starve other endpoints for memory
#define TX_PACKET_LIMIT 4

static uint8_t transmit_previous_timeout=0;

// When the PC isn't listening, how long do we wait before discarding data?
#define TX_TIMEOUT_MSEC 50

#if F_CPU == 96000000
  #define TX_TIMEOUT (TX_TIMEOUT_MSEC * 596)
#elif F_CPU == 48000000
  #define TX_TIMEOUT (TX_TIMEOUT_MSEC * 428)
#elif F_CPU == 24000000
  #define TX_TIMEOUT (TX_TIMEOUT_MSEC * 262)
#endif


int usb_nkro_send_nkro_now(void)
{
        uint32_t wait_count=0;
        usb_packet_t *tx_packet;

	while (1) {
		if (!usb_configuration) {
			return -1;
		}
		if (usb_tx_packet_count(NKRO_ENDPOINT) < TX_PACKET_LIMIT) {
			tx_packet = usb_malloc();
			if (tx_packet) break;
		}
		if (++wait_count > TX_TIMEOUT || transmit_previous_timeout) {
			transmit_previous_timeout = 1;
			return -1;
		}
		yield();
	}
	memcpy(tx_packet->buf, nkro_report_data, NKRO_SIZE);
	tx_packet->len = NKRO_SIZE;
	usb_tx(NKRO_ENDPOINT, tx_packet);
        
    return 0;

}

#endif // NKRO_INTERFACE