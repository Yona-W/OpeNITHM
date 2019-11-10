// Via https://dawnmist.dreamwidth.org/1250.html
#ifndef USBnkro_h_
#define USBnkro_h_

#include "keylayouts.h"

#if defined(USB_NKRO) || defined(USB_SERIAL_NKRO)

#include <inttypes.h>

// C language implementation
#ifdef __cplusplus
extern "C" {
#endif
void usb_nkro_reset_keys();
void usb_nkro_reset_key(uint8_t key);
void usb_nkro_set_key(uint8_t key);
int usb_nkro_send_nkro_now();
#ifdef __cplusplus
}
#endif



// C interface
#ifdef __cplusplus
#include "Stream.h"

class usb_nkro_class
{
        public:
        void reset_keys() { usb_nkro_reset_keys(); }
        void reset_key(uint8_t key) { usb_nkro_reset_key(key); }
		void reset_key_ascii(char key) {usb_nkro_reset_key(keycodes_ascii[key-0x20]); }
        void set_key(uint8_t key) { usb_nkro_set_key(key); }
		void set_key_ascii(char key) {usb_nkro_set_key(keycodes_ascii[key-0x20]); }
        int send_nkro_now(void) { return usb_nkro_send_nkro_now(); }
};

extern usb_nkro_class Nkro;

#endif // __cplusplus

#endif // USB_NKRO
#endif // USBnkro_h_