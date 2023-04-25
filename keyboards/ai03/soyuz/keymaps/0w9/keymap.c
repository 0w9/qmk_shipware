#include QMK_KEYBOARD_H
#include "quantum/keymap_extras/keymap_german_mac_iso.h"
#include "quantum/keymap_extras/sendstring_german_mac_iso.h"

#define _TOOLS 1
#define _UNICODE 14

enum CUSTOM_KEYCODES {
	GIT_ADD__PLUS = HYPR(KC_NUM),
	CLEAR_TERMINAL__MINUS = HYPR(KC_C),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
	case GIT_ADD__PLUS:
		if(record->event.pressed) {
			SEND_STRING("git add . && git commit -m 'Updates.' && git push \n");
			return true;
		}
		break;

	case CLEAR_TERMINAL__MINUS:
		if(record->event.pressed) {
			SEND_STRING("clear");
			return true;
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
    KC_P7,   KC_P8,   KC_MS_UP,   KC_PPLS,
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
	)
};
