/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

/* will-henney 2022-03-17: Home row modifiers with Mod-Tap. The length
   of time that is considered a hold is controlled by TAPPING_TERM
   parameter in config.h */
#define M_S_CMD MT(MOD_LGUI, KC_S)
#define M_Q_CMD MT(MOD_LGUI, KC_Q)
#define M_D_OPT MT(MOD_LALT, KC_D)
#define M_F_CTL MT(MOD_LCTL, KC_F)
#define M_L_CMD MT(MOD_RGUI, KC_L)
#define M_K_OPT MT(MOD_RALT, KC_K)
#define M_J_CTL MT(MOD_RCTL, KC_J)

/* will-henney 2022-03-18: Layer taps to combine layer-activation (on
   hold) with another key (on tap). I use these so that arrow keys
   either side of space bar can double as RAISE and LOWER */
#define LT_L(kc) LT(_LOWER, kc)
#define LT_R(kc) LT(_RAISE, kc)
#define LT_L_RT LT_L(KC_RGHT)
#define LT_R_UP LT_R(KC_UP)
#define LT_Z LT(_SPANISH, KC_Z)
#define LT_SLASH LT(_SPANISH, KC_SLASH)

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _SPANISH,
  _USPANISH
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT,
  A_ACC,
  E_ACC,
  I_ACC,
  O_ACC,
  U_ACC,
  N_TIL,
  QMK_UP,
  EMK_UP,
  A_UACC,
  E_UACC,
  I_UACC,
  O_UACC,
  U_UACC,
  N_UTIL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |Q/CMD |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  =   |   A  |S/CMD |D/OPT |F/CTL |   G  |   H  |J/CTL |K/OPT |L/CMD |   ;  |Enter |                      
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift| Z [*]|   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  | / [*]|Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   '  |   \  | Left |Right |Lower |    Space    |Raise |  Up  | Down |   [  |  ]   | 
 * `-----------------------------------------------------------------------------------'
 * [*] Activates SPANISH layer on hold
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  M_Q_CMD, KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_EQL,  KC_A,    M_S_CMD, M_D_OPT, M_F_CTL, KC_G,    KC_H,    M_J_CTL, M_K_OPT, M_L_CMD, KC_SCLN, KC_ENT,
  KC_LSFT, LT_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  LT_SLASH, KC_RSFT,
  KC_QUOT, KC_BSLS, KC_LEFT, KC_RGHT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL,
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_DEL,
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT,
  BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |      |      |  Up  |      |      |      |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      | Left | Down | Right|      |      |      |  "   |      |  |   |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Home | End  |      |             |      | Pg Up| Pg Dn|      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, 
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  KC_DEL,  _______, _______, KC_UP  , _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_DQUO, _______, KC_PIPE, KC_DQUO,
  _______, _______, KC_HOME, KC_END, _______, _______, _______,MO(_ADJUST), KC_PGUP, KC_PGDN, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |      |      |  Up  |      |      |      |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      | Left | Down | Right|      |      |      |  '   |      |  \   |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Home | End  |      |             |      | Pg Up| Pg Dn|      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, 
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_DEL,  _______, _______, KC_UP  , _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_QUOT, _______, KC_BSLS, KC_QUOT,
  _______, _______, KC_HOME, KC_END,MO(_ADJUST),_______,_______, _______, KC_PGUP, KC_PGDN, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* SPANISH - lower case accented letters
 * ,-----------------------------------------------------------------------------------.
 * |      |   ¡  |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ¡  |      |   é  |      |      |      |   ú  |   í  |   ó  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   á  |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   ñ  |      |      |      |   ¿  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SPANISH] = LAYOUT_preonic_grid(
  _______, EMK_UP,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, EMK_UP, _______, E_ACC,   _______, _______, _______, U_ACC,   I_ACC,   O_ACC,   _______, _______,
  _______, A_ACC,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  MO(_USPANISH), _______, _______, _______, _______, _______, N_TIL, _______, _______, _______, QMK_UP, MO(_USPANISH),
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* USPANISH - upper case accented letters
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   É  |      |      |      |   Ú  |   Í  |   Ó  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   Á  |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   Ñ  |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_USPANISH] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, E_UACC,  _______, _______, _______, U_UACC,  I_UACC,  O_UACC,  _______, _______,
  _______, A_UACC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, N_UTIL,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QWERTY:
	if (record->event.pressed) {
	  set_single_persistent_default_layer(_QWERTY);
	}
	return false;
	break;
  case COLEMAK:
	if (record->event.pressed) {
	  set_single_persistent_default_layer(_COLEMAK);
	}
	return false;
	break;
  case DVORAK:
	if (record->event.pressed) {
	  set_single_persistent_default_layer(_DVORAK);
	}
	return false;
	break;
  case LOWER:
	if (record->event.pressed) {
	  layer_on(_LOWER);
	  update_tri_layer(_LOWER, _RAISE, _ADJUST);
	} else {
	  layer_off(_LOWER);
	  update_tri_layer(_LOWER, _RAISE, _ADJUST);
	}
	return false;
	break;
  case RAISE:
	if (record->event.pressed) {
	  layer_on(_RAISE);
	  update_tri_layer(_LOWER, _RAISE, _ADJUST);
	} else {
	  layer_off(_RAISE);
	  update_tri_layer(_LOWER, _RAISE, _ADJUST);
	}
	return false;
	break;
  case BACKLIT:
	if (record->event.pressed) {
	  register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
	  backlight_step();
#endif
#ifdef RGBLIGHT_ENABLE
	  rgblight_step();
#endif
#ifdef __AVR__
	  writePinLow(E6);
#endif
	} else {
	  unregister_code(KC_RSFT);
#ifdef __AVR__
	  writePinHigh(E6);
#endif
	}
	return false;
	break;
  case EMK_UP:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_1)));
	  
    }
    break;
  case E_ACC:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_E)) SS_DELAY(30) SS_TAP(X_E));
	  
    }
    break;
  case A_ACC:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_E)) SS_DELAY(30) SS_TAP(X_A));
	  
    }
    break;
  case U_ACC:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_E)) SS_DELAY(30) SS_TAP(X_U));
	  
    }
    break;
  case I_ACC:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_E)) SS_DELAY(30) SS_TAP(X_I));
	  
    }
    break;
  case O_ACC:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_E)) SS_DELAY(30) SS_TAP(X_O));
	  
    }
    break;
  case N_TIL:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_N)) SS_DELAY(30) SS_TAP(X_N));

    }
    break;
  case QMK_UP:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_SLASH))));

    }
    break;
  case E_UACC:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_E)) SS_DELAY(30) SS_LSFT(SS_TAP(X_E)));

    }
    break;
  case A_UACC:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_E)) SS_DELAY(30) SS_LSFT(SS_TAP(X_A)));

    }
    break;
  case U_UACC:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_E)) SS_DELAY(30) SS_LSFT(SS_TAP(X_U)));

    }
    break;
  case I_UACC:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_E)) SS_DELAY(30) SS_LSFT(SS_TAP(X_I)));

    }
    break;
  case O_UACC:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_E)) SS_DELAY(30) SS_LSFT(SS_TAP(X_O)));

    }
    break;
  case N_UTIL:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_N)) SS_DELAY(30) SS_LSFT(SS_TAP(X_N)));

    }
    break;
  }
  return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
