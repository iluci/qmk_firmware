/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
   Copyright 2021 iluci

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "print.h"
#include "keymap.h"
#include "os/os.h"

extern bool    enable_side_rgb_matrix;
extern bool    enable_idicators;
extern bool    enable_autoshift;
extern uint8_t os_mode;

td_state_t cur_dance(qk_tap_dance_state_t *state);
void       caps_finished(qk_tap_dance_state_t *state, void *user_data);
void       caps_reset(qk_tap_dance_state_t *state, void *user_data);

qk_tap_dance_action_t tap_dance_actions[] = {[TD_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, caps_finished, caps_reset)};

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//    ESC          F1        F2       F3       F4       F5       F6       F7       F8       F9       F10       F11       F12      Prt               Rotary(Mute)
//    ~            1         2        3        4        5        6        7        8        9        0          -        (=)      BackSpc           Del
//    Tab          Q         W        E        R        T        Y        U        I        O        P         [         ]        \                 PgUp
//    Caps         A         S        D        F        G        H        J        K        L        ;         "                  Enter             PgDn
//    Sh_L                   Z        X        C        V        B        N        M        ,        .         ?                  Sh_R     Up       End
//    Ct_L         Win_L     Alt_L                               SPACE                               Alt_R     FN        Ct_R     Left     Down     Right

  [_BASE] = LAYOUT(
      KC_ESC,      KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,  KC_PSCR,          KC_LOCK,
      KC_GRV,      KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,          KC_DEL,
      KC_TAB,      KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,          KC_HOME,
      TD(TD_CAPS), KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,           KC_ENT,           KC_END,
      KC_LSFT,     KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT,          KC_UP,   KC_INSERT,
      KC_LCTL,     KC_LGUI,  KC_LALT,                            KC_SPC,                             KC_RALT,  TT(_FN1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_DFT] = LAYOUT(
      _______,     _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______,          _______,
      _______,     _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______,          _______,
      _______,     _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______,          _______,
      _______,     _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,           _______,          _______,
      _______,     _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______,          _______, _______,
      _______,     _______,  _______,                            _______,                            _______,  _______,  _______, _______, _______, _______
  ),

  [_FN1] = LAYOUT(
      _______,     TG(_DFT), WIN,     MAC,     _______, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, _______, _______,  _______,  _______, KC_CALC,          KC_MUTE,
      _______,     _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______,          RGB_TG,
      _______,     KC_BTN1,  KC_MS_U, KC_BTN1, _______, _______, PSGN,    KC_P7,   KC_P8,   KC_P9,   KC_PAST,  _______,  _______, RESET,            RGB_EF,
      _______,     KC_MS_L,  KC_MS_D, KC_MS_R, _______, _______, KC_P0,   KC_P4,   KC_P5,   KC_P6,   KC_PMNS,  KC_PSLS,           _______,          RGB_CO,
      _______,     _______,  _______, _______, _______, _______, KC_PDOT, KC_P1,   KC_P2,   KC_P3,   KC_PPLS,            _______,          _______, RGB_VAI,
      _______,     _______,  _______,                            _______,                            _______,  _______,  _______, _______, _______, _______
  )
};

// clang-format on

// tap dance

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return TD_SINGLE_TAP;
        else
            return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->pressed)
            return TD_DOUBLE_HOLD;
        else
            return TD_DOUBLE_TAP;
    } else if (state->count == 3) {
        if (state->pressed)
            return TD_TRIPLE_HOLD;
        else
            return TD_TRIPLE_TAP;
    } else
        return TD_UNKNOWN;
}

void caps_finished(qk_tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD:
            register_code16(KC_CAPS);
            break;
        case TD_DOUBLE_TAP:
            set_oneshot_layer(_DFT, ONESHOT_START);
            break;
        case TD_TRIPLE_TAP:
            autoshift_toggle();
            break;
        default:
            break;
    }
}

void caps_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD:
            unregister_code16(KC_CAPS);
            break;
        case TD_DOUBLE_TAP:
            clear_oneshot_layer_state(ONESHOT_PRESSED);
            break;
        default:
            break;
    }
}

// end tap dance

// encoder

void encoder_execute(uint16_t counterClockwiseAction, uint16_t clockwiseAction, bool clockwise) {
    if (clockwise) {
        tap_code16(clockwiseAction);
    } else {
        tap_code16(counterClockwiseAction);
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (IS_LAYER_ON(_FN1)) {
            encoder_execute(KC_VOLU, KC_VOLD, clockwise);
        } else {
            uint8_t initial_mod_state = get_mods();
            bool    is_any_ctrl       = initial_mod_state & MOD_MASK_CTRL;
            bool    is_any_alt        = initial_mod_state & MOD_MASK_ALT;

            if (is_any_ctrl && is_any_alt) {
                unregister_code16(KC_LALT);
                unregister_code16(KC_RALT);
                unregister_code16(KC_LCTL);
                unregister_code16(KC_RCTL);

                for (unsigned int i = 0; i < 20; i++) {
                    encoder_execute(KC_UP, KC_DOWN, clockwise);
                }
            } else if (is_any_ctrl) {
                unregister_code16(KC_LCTL);
                unregister_code16(KC_RCTL);

                encoder_execute(KC_UP, KC_DOWN, clockwise);
            } else {
                encoder_execute(KC_WH_U, KC_WH_D, clockwise);
            }

            set_mods(initial_mod_state);
        }

        return false;
    }

    return true;
}

// end encoder

// macros

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t initial_mod_state = get_mods();
    bool    pressed           = record->event.pressed;

    bool is_any_ctrl  = initial_mod_state & MOD_MASK_CTRL;
    bool is_any_gui   = initial_mod_state & MOD_MASK_GUI;
    bool is_any_alt   = initial_mod_state & MOD_MASK_ALT;
    bool is_any_shift = initial_mod_state & MOD_MASK_SHIFT;

    switch (keycode) {
        case RGB_TG:
            if (pressed) {
                if (is_any_ctrl) {
                    enable_side_rgb_matrix = !enable_side_rgb_matrix;
                } else if (is_any_alt) {
                    enable_idicators = !enable_idicators;
                } else {
                    rgb_matrix_toggle();
                }
            }
            return false;
        case RGB_EF:
            if (pressed) {
                if (is_any_ctrl) {
                    if (is_any_shift) {
                        rgb_matrix_decrease_speed();
                    } else {
                        rgb_matrix_increase_speed();
                    }
                } else {
                    if (is_any_shift) {
                        rgb_matrix_step_reverse();
                    } else {
                        rgb_matrix_step();
                    }
                }
            }
            return false;
        case RGB_CO:
            if (pressed) {
                if (is_any_ctrl) {
                    if (is_any_shift) {
                        rgb_matrix_decrease_sat();
                    } else {
                        rgb_matrix_increase_sat();
                    }
                } else {
                    if (is_any_shift) {
                        rgb_matrix_decrease_hue();
                    } else {
                        rgb_matrix_increase_hue();
                    }
                }
            }
            return false;
        case WIN:
            layer_off(_DFT);
            pressed && (os_mode = WIN_MODE);
            return false;
            break;
        case MAC:
            layer_off(_DFT);
            pressed && (os_mode = MAC_MODE);
            return false;
            break;
    }

    if (IS_LAYER_OFF(_DFT)) {
        bool handled = false;

        switch (keycode) {
            case KC_RALT:
            case KC_LALT:
                handled = handle_os_action(SWITCH_WINDOW_EXIT, pressed);
                break;
            case KC_TAB:
                if (is_any_alt) {
                    del_mods(MOD_MASK_ALT);
                    handled = handle_os_action(SWITCH_WINDOW, pressed);
                    if (!handled) {
                        set_mods(initial_mod_state);
                    }
                }
                break;
            case KC_ESC:
                if (is_any_alt) {
                    handled = handle_os_mod_mask_action(SWITCH_WINDOW_NO_DIALOG, pressed, MOD_MASK_ALT);
                } else if (is_any_ctrl && is_any_shift) {
                    handled = handle_os_mod_mask_action(OS_TASK_MANAGER, pressed, MOD_MASK_CS);
                }
                break;

            case KC_CALC:
                handled = handle_os_mod_mask_action(CALC, pressed, 0);
                break;
            case PSGN:
                handled = handle_os_mod_mask_action(SGN, pressed, 0);
                break;
            case KC_PSCR:
                handled = handle_os_mod_mask_action(OS_SCREENSHOT_SNIP, pressed, 0);
                break;

            case KC_LEFT:
                if (is_any_ctrl && is_any_gui) {
                    handled = handle_os_mod_mask_action(WINDOW_LEFT_HALF, pressed, MOD_MASK_CTRL);
                } else if (is_any_ctrl && !is_any_alt) {
                    handled = handle_os_mod_mask_action(TXT_PREV_WORD, pressed, MOD_MASK_CTRL);
                }
                break;
            case KC_RGHT:
                if (is_any_ctrl && is_any_gui) {
                    handled = handle_os_mod_mask_action(WINDOW_RIGHT_HALF, pressed, MOD_MASK_CTRL);
                } else if (is_any_ctrl && !is_any_alt) {
                    handled = handle_os_mod_mask_action(TXT_NEXT_WORD, pressed, MOD_MASK_CTRL);
                }
                break;
            case KC_UP:
                if (is_any_ctrl && is_any_gui) {
                    handled = handle_os_mod_mask_action(WINDOW_TOP_HALF, pressed, MOD_MASK_CTRL);
                }
                break;
            case KC_DOWN:
                if (is_any_ctrl && is_any_gui) {
                    handled = handle_os_mod_mask_action(WINDOW_LOWER_HALF, pressed, MOD_MASK_CTRL);
                }
                break;
            case KC_HOME:
                if (is_any_ctrl) {
                    handled = handle_os_mod_mask_action(TXT_START_DOC, pressed, MOD_MASK_CTRL);
                } else {
                    handled = handle_os_mod_mask_action(TXT_START_LINE, pressed, 0);
                }
                break;
            case KC_END:
                if (is_any_ctrl) {
                    handled = handle_os_mod_mask_action(TXT_END_DOC, pressed, MOD_MASK_CTRL);
                } else {
                    handled = handle_os_mod_mask_action(TXT_END_LINE, pressed, 0);
                }
                break;

            case KC_DEL:
                if (is_any_ctrl) {
                    handled = handle_os_mod_mask_action(TXT_DEL_NEXT_WORD, pressed, MOD_MASK_CTRL);
                }
                break;
            case KC_BSPC:
                if (is_any_ctrl) {
                    handled = handle_os_mod_mask_action(TXT_DEL_PREV_WORD, pressed, MOD_MASK_CTRL);
                }
                break;

            case KC_B:
                if (is_any_ctrl) {
                    handled = handle_os_mod_mask_action(TXT_BOLD, pressed, MOD_MASK_CTRL);
                }
                break;
            case KC_U:
                if (is_any_ctrl) {
                    handled = handle_os_mod_mask_action(TXT_UNDERLINE, pressed, MOD_MASK_CTRL);
                }
                break;
            case KC_I:
                if (is_any_ctrl) {
                    handled = handle_os_mod_mask_action(TXT_ITALIC, pressed, MOD_MASK_CTRL);
                }
                break;
            case KC_F:
                if (is_any_ctrl) {
                    handled = handle_os_mod_mask_action(TXT_FIND, pressed, MOD_MASK_CTRL);
                }
                break;

            case KC_Z:
                if (is_any_ctrl) {
                    if (is_any_alt) {
                        handled = handle_os_mod_mask_action(OS_REDO, pressed, MOD_MASK_CA);
                    } else {
                        handled = handle_os_mod_mask_action(OS_UNDO, pressed, MOD_MASK_CTRL);
                    }
                }
                break;
            case KC_X:
                if (is_any_ctrl) {
                    handled = handle_os_mod_mask_action(OS_CUT, pressed, MOD_MASK_CTRL);
                }
                break;
            case KC_C:
                if (is_any_ctrl) {
                    handled = handle_os_mod_mask_action(OS_COPY, pressed, MOD_MASK_CTRL);
                }
                break;
            case KC_V:
                if (is_any_ctrl) {
                    handled = handle_os_mod_mask_action(OS_PASTE, pressed, MOD_MASK_CTRL);
                } else if (is_any_gui) {
                    handled = handle_os_mod_mask_action(OS_PASTE_SPECIAL, pressed, MOD_MASK_GUI);
                }
                break;

            case KC_A:
                if (is_any_ctrl) {
                    handled = handle_os_mod_mask_action(OS_SELECT_ALL, pressed, MOD_MASK_CTRL);
                }
                break;
            case KC_S:
                if (is_any_gui) {
                    handled = handle_os_mod_mask_action(OS_SEARCH, pressed, MOD_MASK_GUI);
                }
                break;
            case KC_F4:
                if (is_any_alt) {
                    handled = handle_os_mod_mask_action(OS_FORCE_QUIT_APP, pressed, MOD_MASK_ALT);
                }
                break;
            case KC_L:
                if (is_any_gui) {
                    handled = handle_os_mod_mask_action(OS_LOCK_SCREEN, pressed, MOD_MASK_GUI);
                }
                break;

            case KC_D:
                if (is_any_ctrl) {
                    handled = handle_os_mod_mask_action(BROW_BOOKMARK, pressed, MOD_MASK_CTRL);
                }
                break;
            case KC_R:
                if (is_any_ctrl) {
                    if (is_any_shift) {
                        handled = handle_os_mod_mask_action(BROW_REFRESH_CACHE, pressed, MOD_MASK_CS);
                    } else {
                        handled = handle_os_mod_mask_action(BROW_REFRESH, pressed, MOD_MASK_CTRL);
                    }
                }
                break;
            case KC_N:
                if (is_any_ctrl) {
                    if (is_any_shift) {
                        handled = handle_os_mod_mask_action(BROW_INCOGNITO, pressed, MOD_MASK_CS);
                    } else {
                        handled = handle_os_mod_mask_action(BROW_NEW_WINDOW, pressed, MOD_MASK_CTRL);
                    }
                }
                break;
            case KC_T:
                if (is_any_ctrl) {
                    if (is_any_shift) {
                        handled = handle_os_mod_mask_action(BROW_OPEN_LAST_CLOSED, pressed, MOD_MASK_CS);
                    } else {
                        handled = handle_os_mod_mask_action(BROW_NEW_TAB, pressed, MOD_MASK_CTRL);
                    }
                }
                break;
            case KC_W:
                if (is_any_ctrl) {
                    handled = handle_os_mod_mask_action(BROW_CLOSE_TAB, pressed, MOD_MASK_CTRL);
                }
                break;

            case KC_ENT:
                if (is_any_ctrl && is_any_gui) {
                    handled = handle_os_mod_mask_action(WINDOW_MAXIMIZE, pressed, MOD_MASK_CG);
                    del_mods(MOD_MASK_GUI);
                }
                break;
        }

        if (handled) {
            return false;
        }
    }

    return true;
}

// end macros

void keyboard_post_init_user(void) { debug_enable = true; }
