#include QMK_KEYBOARD_H
#define _TOOLS 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_5x4(
    OSL(_TOOLS),  KC_PSLS, KC_PAST, KC_PMNS,
	KC_P7,   KC_P8,   KC_MS_UP,   KC_PPLS,
	KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
	KC_P1,   KC_P2,   KC_P3,   KC_PENT,
	KC_P0,   KC_P0,   KC_PDOT, KC_PENT
  ),

  [_TOOLS] = LAYOUT_ortho_5x4(
	KC_NO,
	KC_Y,
	KC_NO,
	KC_NO,
	KC_NO,
	KC_NO,
	KC_NO,
	KC_NO,
	KC_NO,
	KC_NO,
	KC_NO,
	KC_NO,
	KC_NO,
	KC_NO,
	KC_NO,
	KC_NO,
	KC_NO,
	KC_NO,
	KC_NO,
	KC_NO
  )
};
