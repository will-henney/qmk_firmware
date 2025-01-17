// Copyright 2023 Danny Nguyen (@nooges) and William Henney (@will-henney)
// SPDX-License-Identifier: GPL-2.0-or-later

// Key layout for Iris split keyboard with home-row modifiers

#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _NUMPAD 4

// set up homerow mods
#define GUI_Q MT(MOD_LGUI, KC_Q)
#define HM_A MT(MOD_LGUI, KC_A)
#define HM_S MT(MOD_LALT, KC_S)
#define HM_D MT(MOD_LCTL, KC_D)
#define HM_F MT(MOD_LSFT, KC_F)
#define HM_J MT(MOD_RSFT, KC_J)
#define HM_K MT(MOD_RCTL, KC_K)
#define HM_L MT(MOD_RALT, KC_L)
#define HM_SCLN MT(MOD_RGUI, KC_SCLN)

// Alternative LALT to  replace weak left ring finger
#define HM_C MT(MOD_LALT, KC_C)

// 2024-01-08 - I decided dedicated layer keys is better
/* // dual use of the bottom row layer switch keys */
/* #define LT_RAISE LT(_RAISE, KC_SPC) */
/* #define LT_LOWER LT(_LOWER, KC_ENT) */


// 2024-01-08 - Remove this failed experiment. It proved to be
// unnecessary in the end because I never ditched the thumb layer keys
//
/* // and also add more RAISE layer switch keys on the inside column of home row */
/* // */
/* #define HM_G LT(_RAISE, KC_G) */
/* #define HM_H LT(_RAISE, KC_H) */

/* // The reason for making both sides be RAISE is that we can use a */
/* // combo to get LOWER */
/* // */
/* // The reason that this makes logical sense is that the LOWER layer */
/* // has mainly shifted versions of keys in the RAISE layer, so we have */
/* // a combo with the home row SHIFT mod */
/* enum combos { */
/*   HJ_LOWER, */
/*   FG_LOWER, */
/* }; */
/* const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END}; */
/* const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END}; */
/* combo_t key_combos[] = { */
/*   [HJ_LOWER] = COMBO(hj_combo, MO(_LOWER)), */
/*   [FG_LOWER] = COMBO(fg_combo, MO(_LOWER)), */
/* }; */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRAVE,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     MO(_NUMPAD), HM_A, HM_S,    HM_D,    HM_F,    KC_G,                               KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN, KC_ENTER,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    HM_C,    KC_V,    KC_B,    KC_HOME,          KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
	                                KC_TAB, MO(_LOWER), KC_ENT,                   KC_SPC, MO(_RAISE), KC_GRAVE
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC, _______,  KC_LEFT,   KC_UP,  KC_RIGHT, CW_TOGG,                            _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_HOME, KC_DOWN, KC_END, _______, KC_LGUI,        KC_RGUI, _______, _______, KC_DQUO, _______, KC_PIPE, KC_DQUO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_DEL, _______, KC_BSPC,                    KC_DEL, MO(_ADJUST), KC_BSPC
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
 //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_GRAVE,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
	 KC_ESC,  _______, KC_LEFT, KC_UP, KC_RIGHT, CW_TOGG,                           _______, KC_MINUS, KC_EQUAL, KC_LBRC, KC_RBRC, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_PGUP, KC_DOWN, KC_PGDN, _______, KC_LALT,         KC_RALT, _______, _______, KC_QUOTE, _______, KC_BSLS, KC_QUOTE, 
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_DEL, MO(_ADJUST), KC_BSPC,                 KC_DEL,  _______, KC_BSPC
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  
  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, EE_CLR,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUMPAD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_PSLS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PAST, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          DT_PRNT, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   KC_P0,   KC_PDOT, KC_BSPC
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
};
        
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
#   if defined(KEYBOARD_keebio_iris_rev7) || defined(KEYBOARD_keebio_iris_rev8)
    [_QWERTY] = { ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_WH_L, KC_WH_R)},
	[_LOWER] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
	[_RAISE] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_SPD, RGB_SPI), ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
    [_NUMPAD] = { ENCODER_CCW_CW(RGB_SPD, RGB_SPI), ENCODER_CCW_CW(DT_DOWN, DT_UP), ENCODER_CCW_CW(DT_DOWN, DT_UP), ENCODER_CCW_CW(DT_DOWN, DT_UP) },
#   else
    [_QWERTY] = { ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
    [_LOWER] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
	[_RAISE] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_SPD, RGB_SPI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [_NUMPAD] = { ENCODER_CCW_CW(RGB_SPD, RGB_SPI), ENCODER_CCW_CW(DT_DOWN, DT_UP) },
#   endif
};
#endif


#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case HM_A: case HM_S: case HM_L: case HM_SCLN:
	// Weaker fingers get a longer tapping term since it is harder to
	// tap crisply with fingers 3 and 4
	return TAPPING_TERM + 100;
  default:
	return TAPPING_TERM;
  }
}
#endif
