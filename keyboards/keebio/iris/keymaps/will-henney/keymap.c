// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layer {
    _MAIN,
    _FN1,
    _FN2,
    _FN3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRAVE,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENTER,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME,          KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_ENT, TL_LOWR, KC_LSFT,                     KC_SPC,  TL_UPPR, KC_BSPC
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC, _______,  KC_HOME,   KC_UP,  KC_END, _______,                            _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, KC_LGUI,        KC_RGUI, _______, _______, KC_DQUO, _______, KC_PIPE, KC_DQUO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_DEL,                    KC_DEL,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
 //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_GRAVE,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
	 KC_DELETE, _______, KC_PGUP, KC_UP, KC_PGDN, _______,                           _______, KC_MINUS, KC_EQUAL, KC_LBRC, KC_RBRC, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, KC_LALT,        KC_RALT, _______, _______, KC_QUOTE, _______, KC_BSLS, KC_QUOTE, 
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  
  [_FN3] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
				  ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
#   if defined(KEYBOARD_keebio_iris_rev7) || defined(KEYBOARD_keebio_iris_rev8)
    [_MAIN] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_FN1] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_HOME, KC_END), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_HOME, KC_END) },
    [_FN2] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [_FN3] = { ENCODER_CCW_CW(RGB_SPD, RGB_SPI), ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_UP, KC_DOWN) },
#   else
    [_MAIN] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN1] = { ENCODER_CCW_CW(KC_HOME, KC_END), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_FN2] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [_FN3] = { ENCODER_CCW_CW(RGB_SPD, RGB_SPI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
#   endif
};
#endif


// Combos copied from my moonlander config


/* Single modifiers are each two adjacent keys on home row */
const uint16_t PROGMEM combo_RCTL[] = { KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_LCTL[] = { KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM combo_RALT[] = { KC_L, KC_K, COMBO_END};
const uint16_t PROGMEM combo_LALT[] = { KC_S, KC_D, COMBO_END};
/* CMD has inward finger movement */
const uint16_t PROGMEM combo_RGUI[] = { KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM combo_LGUI[] = { KC_F, KC_G, COMBO_END};
/* Double modifiers are on bottom row OPT CTL and CMD CTL */
const uint16_t PROGMEM combo_RALT_CTL[] = { KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo_LALT_CTL[] = { KC_V, KC_C, COMBO_END};
const uint16_t PROGMEM combo_RGUI_CTL[] = { KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_LGUI_CTL[] = { KC_C, KC_X, COMBO_END};
/* And inward finger movement for CMD OPT */
const uint16_t PROGMEM combo_RGUI_ALT[] = { KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM combo_LGUI_ALT[] = { KC_B, KC_V, COMBO_END};
/* Triple modifiers are trigraph on top row */
const uint16_t PROGMEM combo_RGUI_ALT_CTL[] = { KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_LGUI_ALT_CTL[] = { KC_R, KC_E, KC_W, COMBO_END};

// Make sure that COMBO_COUNT in config.h is consistent witn the
// number of combos defined here
combo_t key_combos[] = {
    COMBO(combo_RCTL, KC_RCTL),
    COMBO(combo_LCTL, KC_LCTL),
	COMBO(combo_RALT, KC_RALT),
    COMBO(combo_LALT, KC_LALT),
    COMBO(combo_RGUI, KC_RGUI),
    COMBO(combo_LGUI, KC_LGUI),
    COMBO(combo_RALT_CTL, RALT(KC_RCTL)),
	COMBO(combo_LALT_CTL, LALT(KC_LCTL)),
    COMBO(combo_RGUI_CTL, RGUI(KC_RCTL)),
	COMBO(combo_LGUI_CTL, LGUI(KC_LCTL)),
    COMBO(combo_RGUI_ALT, RGUI(KC_RALT)),
    COMBO(combo_LGUI_ALT, LGUI(KC_RALT)),
	COMBO(combo_RGUI_ALT_CTL, RALT(RGUI(KC_RCTL))),
    COMBO(combo_LGUI_ALT_CTL, LALT(LGUI(KC_LCTL))),
};


