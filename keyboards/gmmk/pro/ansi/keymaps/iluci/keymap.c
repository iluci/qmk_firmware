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
#include "rgb/rgb.h"
#include "util/util.h"

// clang-format off

// 67, Side 01  0, ESC        6, F1          12, F2         18, F3       23, F4       28, F5        34, F6       39, F7       44, F8         50, F9        56, F10        61, F11        66, F12        69, Prt        Rotary(Mute)    68, Side 12
// 70, Side 02  1, ~          7, 1           13, 2          19, 3        24, 4        29, 5         35, 6        40, 7        45, 8          51, 9         57, 0          62, -_         78, (=+)       85, BackSpc    72, Del         71, Side 13
// 73, Side 03  2, Tab        8, Q           14, W          20. E        25, R        30, T         36, Y        41, U        46, I          52, O         58, P          63, [{         89, ]}         93, \|         75, Home        74, Side 14
// 76, Side 04  3, Caps       9, A           15, S          21, D        26, F        31, G         37, H        42, J        47, K          53, L         59, ;:         64, '"                        96, Enter      86, End         77, Side 15
// 80, Side 05  4, Sh_L       10, Z          16, X          22, C        27, V        32, B         38, N        43, M        48, ,<         54, .<        60, /?                        90, Sh_R       94, Up         82, Insert      81, Side 16
// 83, Side 06  5, Ct_L       11,Win_L       17, Alt_L                                33, SPACE                               49, Alt_R      55, FN                       65, Ct_R       95, Left       97, Down       79, Right       84, Side 17
// 87, Side 07                                                                                                                                                                                                                         88, Side 18
// 91, Side 08                                                                                                                                                                                                                         92, Side 19

enum rgb_matrix {
  LED_LS1 = 67, LED_ESC = 0,  LED_F1 = 6,    LED_F2 = 12,   LED_F3 = 18, LED_F4 = 23, LED_F5 = 28,  LED_F6 = 34, LED_F7 = 39, LED_F8 = 44,   LED_F9 = 50,  LED_F10 = 56,  LED_F11 = 61,  LED_F12 = 66,  LED_PRT = 69,                 /* Rotary */    LED_RS1 = 68,
  LED_LS2 = 70, LED_GRV = 1,  LED_1 = 7,     LED_2 = 13,    LED_3 = 19,  LED_4 = 24,  LED_5 = 29,   LED_6 = 35,  LED_7 = 40,  LED_8 = 45,    LED_9 = 51,   LED_0 = 57,    LED_MINS = 62, LED_EQL = 78,  LED_BSPC = 85,                LED_DEL = 72,   LED_RS2 = 71,
  LED_LS3 = 73, LEB_TAB = 2,  LED_Q = 8,     LED_W = 14,    LED_E = 20,  LED_R = 25,  LED_T = 30,   LED_Y = 36,  LED_U = 41,  LED_I = 46,    LED_O = 52,   LED_P = 58,    LED_LBRC = 63, LED_RBRC = 89, LED_BSLS = 93,                LED_HOME = 75,  LED_RS3 = 74,
  LED_LS4 = 76, LED_CAPS = 3, LED_A = 9,     LED_S = 15,    LED_D = 21,  LED_F = 26,  LED_G = 31,   LED_H = 37,  LED_J = 42,  LED_K = 47,    LED_L = 53,   LED_SCLN = 59, LED_QUOT = 64,                LED_ENT = 96,                 LED_END = 86,   LED_RS4 = 77,
  LED_LS5 = 80, LED_LSFT = 4, LED_Z = 10,    LED_X = 16,    LED_C = 22,  LED_V = 27,  LED_B = 32,   LED_N = 38,  LED_M = 43,  LED_COMM = 48, LED_DOT = 54, LED_SLSH = 60,                LED_RSFT = 90,                LED_UP = 94,   LED_INS = 82,   LED_RS5 = 81,
  LED_LS6 = 83, LED_LCTL = 5, LED_LWIN = 11, LED_LALT = 17,                                         LED_SPC = 33,                                          LED_RALT = 49, LED_FN = 55,   LED_RCTL = 65, LED_LEFT = 95, LED_DOWN = 97, LED_RIGHT = 79, LED_RS6 = 84,
  LED_LS7 = 87,                                                                                                                                                                                                                                       LED_RS7 = 88,
  LED_LS8 = 91,                                                                                                                                                                                                                                       LED_RS8 = 92,
};

uint8_t rgb_matrix_side[] = { 
  LED_LS1, LED_RS1,
  LED_LS2, LED_RS2,
  LED_LS3, LED_RS3,
  LED_LS4, LED_RS4,
  LED_LS5, LED_RS5,
  LED_LS6, LED_RS6,
  LED_LS7, LED_RS7,
  LED_LS8, LED_RS8,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//    ESC          F1        F2       F3       F4       F5       F6       F7       F8       F9       F10       F11       F12      Prt               Rotary(Mute)
//    ~            1         2        3        4        5        6        7        8        9        0          -        (=)      BackSpc           Del
//    Tab          Q         W        E        R        T        Y        U        I        O        P         [         ]        \                 Home
//    Caps         A         S        D        F        G        H        J        K        L        ;         "                  Enter             End
//    Sh_L                   Z        X        C        V        B        N        M        ,        .         ?                  Sh_R     Up       Ins
//    Ct_L         Win_L     Alt_L                               SPACE                               Alt_R     FN        Ct_R     Left     Down     Right

  [_BASE] = LAYOUT(
      KC_ESC,      KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,  KC_PSCR,          KC_LOCK,
      KC_GRV,      KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,          KC_DEL,
      KC_TAB,      KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,          KC_HOME,
      TD(TD_CAPS), KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,           KC_ENT,           KC_END,
      KC_LSFT,     KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT,          KC_UP,   KC_INSERT,
      KC_LCTL,     KC_LGUI,  KC_LALT,                            KC_SPC,                             KC_RALT,  TT(_FN1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_FN1] = LAYOUT(
      _______,     OS_DEFT,  OS_WIN,  OS_MAC,  _______, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, _______, _______,  _______,  _______, KC_CALC,          KC_MUTE,
      _______,     _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______,          RGB_TG,
      _______,     KC_BTN1,  KC_MS_U, KC_BTN1, _______, _______, PSGN,    KC_P7,   KC_P8,   KC_P9,   KC_PAST,  _______,  _______, RESET,            RGB_EF,
      _______,     KC_MS_L,  KC_MS_D, KC_MS_R, _______, _______, KC_P0,   KC_P4,   KC_P5,   KC_P6,   KC_PMNS,  KC_PSLS,           _______,          RGB_CO,
      _______,     _______,  _______, _______, _______, _______, KC_PDOT, KC_P1,   KC_P2,   KC_P3,   KC_PPLS,            _______,          _______, RGB_VAI,
      _______,     _______,  _______,                            _______,                            _______,  _______,  _______, _______, _______, _______
  )
};

// clang-format on

bool           enable_side_rgb_matrix = false;
bool           enable_idicators       = false;
extern uint8_t os_mode;

void caps_finished(qk_tap_dance_state_t *state, void *user_data);
void caps_reset(qk_tap_dance_state_t *state, void *user_data);

qk_tap_dance_action_t tap_dance_actions[] = {[TD_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, caps_finished, caps_reset)};

// tap dance

void caps_finished(qk_tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD:
            register_code16(KC_CAPS);
            break;
        case TD_DOUBLE_TAP:
            set_one_shot_df_os_mode();
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
    bool pressed = record->event.pressed;

    switch (keycode) {
        case RGB_TG:
            if (pressed) {
                if (is_any_ctrl()) {
                    enable_side_rgb_matrix = !enable_side_rgb_matrix;
                } else if (is_any_alt()) {
                    enable_idicators = !enable_idicators;
                } else {
                    rgb_matrix_toggle();
                }
            }
            return false;
        case RGB_EF:
            if (pressed) {
                if (is_any_ctrl()) {
                    if (is_any_shift()) {
                        rgb_matrix_decrease_speed();
                    } else {
                        rgb_matrix_increase_speed();
                    }
                } else {
                    if (is_any_shift()) {
                        rgb_matrix_step_reverse();
                    } else {
                        rgb_matrix_step();
                    }
                }
            }
            return false;
        case RGB_CO:
            if (pressed) {
                if (is_any_ctrl()) {
                    if (is_any_shift()) {
                        rgb_matrix_decrease_sat();
                    } else {
                        rgb_matrix_increase_sat();
                    }
                } else {
                    if (is_any_shift()) {
                        rgb_matrix_decrease_hue();
                    } else {
                        rgb_matrix_increase_hue();
                    }
                }
            }
            return false;
    }

    bool handled = os_macros(keycode, pressed);
    if (handled) {
        return false;
    }

    return true;
}

// end macros

void keyboard_post_init_user(void) { debug_enable = true; }

uint8_t rgb_matrix_inactive_fn1[] = {
    // OS MODE
    LED_F1, LED_F2, LED_F3, LED_F4,
    // Media keys
    LED_F5, LED_F6, LED_F7, LED_F8,
    // RGB CONTROL
    LED_DEL, LED_HOME, LED_END, LED_INS,
    // Mouse
    LED_Q, LED_W, LED_E, LED_A, LED_S, LED_D,
    // Calc
    LED_PRT,
    // Keypad
    LED_Y, LED_U, LED_I, LED_O, LED_P, LED_H, LED_J, LED_K, LED_L, LED_SCLN, LED_QUOT, LED_N, LED_M, LED_COMM, LED_DOT, LED_SLSH

};

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!enable_side_rgb_matrix) {
        rgb_matrix_disable_leds(rgb_matrix_side, sizeof(rgb_matrix_side));
    }

    if (get_autoshift_state()) {
        rgb_matrix_set_color_led(LED_CAPS, triadic_counter_clockwise_rgb());
    }

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color_led(LED_CAPS, triadic_clockwise_rgb());
    }

    if (IS_LAYER_ON(_FN1)) {
        rgb_matrix_set_color_leds(rgb_matrix_inactive_fn1, sizeof(rgb_matrix_inactive_fn1), triadic_counter_clockwise_rgb());
        rgb_matrix_set_color_led(LED_BSLS, complimentary_rgb());
    }

    if (enable_idicators || IS_LAYER_ON(_FN1)) {
        if (os_mode == OS_MODE_WIN) {
            rgb_matrix_set_color_led(LED_F2, triadic_clockwise_rgb());
        } else if (os_mode == OS_MODE_MAC) {
            rgb_matrix_set_color_led(LED_F3, triadic_clockwise_rgb());
        }
    }

    if (os_mode == OS_MODE_DFT) {
        rgb_matrix_set_color_led(LED_F1, triadic_clockwise_rgb());
    }
}
