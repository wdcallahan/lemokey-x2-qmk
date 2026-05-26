/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

enum layers{
  BASE,
  MOUSE,
  SCROLL,
  EXTRA,
};
enum custom_keycodes {
    N_RALT = SAFE_RANGE,
    N_FN,
    N_MENU,
    N_INS,
    N_RSFT,
};
#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_104_ansi(
        KC_ESC,               KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,   KC_F12,     KC_PSCR,  KC_SCRL,  KC_PAUS,
        KC_GRV,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,    N_INS,    KC_HOME,  KC_PGUP,  TG(MOUSE),  KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,  KC_P7,      KC_P8,    KC_P9,    KC_PPLS,
        PB_11,	    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                   KC_P4,      KC_P5,    KC_P6,
        KC_LSFT,              KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              N_RSFT,               KC_UP,              KC_P1,      KC_P2,    KC_P3,    KC_PENT,
        KC_LCTL,    KC_LWIN,  KC_LALT,                                KC_SPC,                                 N_RALT,   N_FN,       N_MENU,   PB_28,      KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,                KC_PDOT         ),

    [MOUSE] = LAYOUT_104_ansi(
        _______,              _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,    _______,  _______,  _______,
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,    _______,  _______,  _______,  _______,    _______,  _______,  _______,
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,    KC_BTN1,  KC_BTN3,  KC_BTN2,  _______,    _______,  _______,  _______,
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,    _______,  _______,
        MO(SCROLL),           _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              MO(SCROLL),           KC_MS_U,            _______,    _______,  _______,  _______,
        _______,    _______,  _______,                                _______,                                _______,  _______,    _______,  _______,    KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,              _______         ),

    [SCROLL] = LAYOUT_104_ansi(
        _______,              _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,    _______,  _______,  _______,
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,    _______,  _______,  _______,  _______,   _______,  _______,  _______,
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,    _______,  _______,  _______,  _______,   _______,  _______,  _______,
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,   _______,  _______,
        _______,              _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,              KC_WH_U,            _______,   _______,  _______,  _______,
        _______,    _______,  _______,                                _______,                                _______,  _______,    _______,  _______,    KC_WH_L,  KC_WH_D,  KC_WH_R,  _______,             _______         ),
    [EXTRA] = LAYOUT_104_ansi(
        _______,              _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,    _______,  _______,  _______,
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,    _______,  _______,  _______,  _______,   _______,  _______,  _______,
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,    _______,  _______,  _______,  _______,   _______,  _______,  _______,
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,   _______,  _______,
        _______,              _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,              _______,            _______,   _______,  _______,  _______,
        _______,    _______,  _______,                                _______,                                _______,  _______,    _______,  _______,    _______,  _______,  _______,  _______,             _______         ),
};

// clang-format on

typedef struct {
    uint16_t keycode;
    uint16_t tap;
    uint16_t hold;
    bool active;
    bool interrupted;
    bool hold_registered;
} nova_dual_t;

static nova_dual_t nova_duals[] = {
    { N_RALT, PB_12,  PB_25,   false, false, false },
    { N_FN,   KC_APP, KC_RCTL, false, false, false },
    { N_MENU, PB_26,  PB_27,   false, false, false },
    { N_INS,  KC_INS, PB_29,   false, false, false },
    { N_RSFT, KC_CAPS, KC_RSFT, false, false, false },
};

static nova_dual_t *find_nova_dual(uint16_t keycode) {
    for (uint8_t i = 0; i < ARRAY_SIZE(nova_duals); i++) {
        if (nova_duals[i].keycode == keycode) {
            return &nova_duals[i];
        }
    }
    return NULL;
}

static void promote_other_pending_duals(uint16_t keycode) {
    for (uint8_t i = 0; i < ARRAY_SIZE(nova_duals); i++) {
        nova_dual_t *d = &nova_duals[i];

        if (!d->active || d->keycode == keycode || d->hold_registered) {
            continue;
        }

        d->interrupted = true;
        d->hold_registered = true;
        register_code16(d->hold);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        promote_other_pending_duals(keycode);
    }

    nova_dual_t *d = find_nova_dual(keycode);

    if (d == NULL) {
        return true;
    }

    if (record->event.pressed) {
        d->active = true;
        d->interrupted = false;
        d->hold_registered = false;
        return false;
    }

    if (d->hold_registered) {
        unregister_code16(d->hold);
    } else if (!d->interrupted) {
        tap_code16(d->tap);
    }

    d->active = false;
    d->interrupted = false;
    d->hold_registered = false;
    return false;
}
