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
#include "programmable_button.h"

enum layers{
  BASE,
  MOUSE,
  SCROLL,
  EXTRA,
};
enum custom_keycodes {
    N_RCTL = SAFE_RANGE,
    N_FN,
    N_MENU,
    N_INS,
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
        KC_LSFT,              KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,      KC_P2,    KC_P3,    KC_PENT,
        KC_LCTL,    KC_LWIN,  KC_LALT,                                KC_SPC,                                 PB_28,    N_FN,       N_MENU,   N_RCTL,     KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,                KC_PDOT         ),

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
#define NOVA_NUMLOCK_REASSERT_DELAY 50
#define NOVA_NUMLOCK_WATCHDOG_INTERVAL 1000

static bool nova_numlock_reassert_pending = true;
static uint32_t nova_numlock_reassert_timer = 0;

static void nova_request_numlock_reassert(void) {
    nova_numlock_reassert_pending = true;
    nova_numlock_reassert_timer = timer_read32();
}

static void nova_numlock_guard_task(void) {
    if (nova_numlock_reassert_pending &&
        timer_elapsed32(nova_numlock_reassert_timer) >= NOVA_NUMLOCK_REASSERT_DELAY) {

        nova_numlock_reassert_pending = false;

        if (!host_keyboard_led_state().num_lock) {
            tap_code(KC_NUM_LOCK);
        }
    }

    if (!host_keyboard_led_state().num_lock &&
        timer_elapsed32(nova_numlock_reassert_timer) >= NOVA_NUMLOCK_WATCHDOG_INTERVAL) {
        nova_request_numlock_reassert();
    }
}

void keyboard_post_init_user(void) {
    nova_request_numlock_reassert();
}

bool led_update_user(led_t led_state) {
    if (!led_state.num_lock) {
        nova_request_numlock_reassert();
    }

    return true;
}

void housekeeping_task_user(void) {
    nova_numlock_guard_task();
}
typedef enum {
    NOVA_NORMAL,
    NOVA_PB,
} nova_action_type_t;

typedef struct {
    nova_action_type_t type;
    uint16_t code;
} nova_action_t;

typedef struct {
    uint16_t keycode;
    nova_action_t tap;
    nova_action_t hold;
    bool active;
    bool interrupted;
    bool hold_registered;
} nova_dual_t;

#define NORMAL_ACTION(kc) { NOVA_NORMAL, (kc) }
#define PB_ACTION(index)  { NOVA_PB,     (index) }

static nova_dual_t nova_duals[] = {
    { N_RCTL, PB_ACTION(12),          PB_ACTION(25),      false, false, false },
    { N_FN,   NORMAL_ACTION(KC_MENU), NORMAL_ACTION(KC_RCTL), false, false, false },
    { N_MENU, PB_ACTION(26),         NORMAL_ACTION(KC_APP), false, false, false },
    { N_INS,  NORMAL_ACTION(KC_INS), PB_ACTION(29),      false, false, false },
};

static void nova_register_action(nova_action_t action) {
    if (action.type == NOVA_PB) {
        programmable_button_register((uint8_t)action.code);
    } else {
        register_code16(action.code);
    }
}

static void nova_unregister_action(nova_action_t action) {
    if (action.type == NOVA_PB) {
        programmable_button_unregister((uint8_t)action.code);
    } else {
        unregister_code16(action.code);
    }
}

static void nova_tap_action(nova_action_t action) {
    if (action.type == NOVA_PB) {
        programmable_button_register((uint8_t)action.code);
        programmable_button_unregister((uint8_t)action.code);
    } else {
        tap_code16(action.code);
    }
}

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
        nova_register_action(d->hold);
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
        nova_unregister_action(d->hold);
    } else if (!d->interrupted) {
        nova_tap_action(d->tap);
    }

    d->active = false;
    d->interrupted = false;
    d->hold_registered = false;
    return false;
}
