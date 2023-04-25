#include QMK_KEYBOARD_H
#include "quantum/keymap_extras/keymap_german_mac_iso.h"
#include "quantum/keymap_extras/sendstring_german_mac_iso.h"

#define _TOOLS 1
#define _UNICODE 14
#define _FUN 15

enum CUSTOM_KEYCODES {
	GIT_ADD__PLUS = HYPR(KC_NUM),
	CLEAR_TERMINAL__MINUS = HYPR(KC_C),
	SEND_WPM__MINUS = HYPR(KC_MS_UP)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
	case GIT_ADD__PLUS:
		if(record->event.pressed) {
			send_string("git add . && git commit -m 'Updates.' && git push \n");
			return true;
		}
		break;

	case CLEAR_TERMINAL__MINUS:
		if(record->event.pressed) {
			SEND_STRING("clear");
			return true;
		}
		break;

	case SEND_WPM__MINUS:

		// Sends the current WPM as a text.

		if(record->event.pressed) {
			uint8_t wpm = get_current_wpm();
			char wpm_str[4];
			sprintf(wpm_str, "%d", wpm);
			char text[] = "The current WPM is: ";
			strcat(text, wpm_str);

			send_string(text);
			return false;
		}
		break;
	default: 
		return true;
	}	

	return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  	[0] = LAYOUT_ortho_5x4(
		GIT_ADD__PLUS,  KC_PSLS, KC_PAST, CLEAR_TERMINAL__MINUS,
		SEND_WPM__MINUS,   KC_P8,   KC_MS_UP,   KC_PPLS,
		KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
		KC_P1,   KC_P2,   KC_P3,   KC_PDOT,
		KC_P0,   KC_P0,   KC_PDOT, KC_NO
	),
  
  	[_TOOLS] = LAYOUT_ortho_5x4(
		KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO
	),	

  	[_UNICODE] = LAYOUT_ortho_5x4(
		KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO
	),
	
	[_FUN] = LAYOUT_ortho_5x4(
		KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO
	)
};
