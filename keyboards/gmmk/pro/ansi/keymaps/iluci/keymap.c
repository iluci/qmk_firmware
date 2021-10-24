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
#include "util/util.h"
#include "core.h"

// clang-format off

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

led_indicators_config_t led_indicators_config(void) {
    return (led_indicators_config_t){
        .initialized = true,

        .RGB_MATRIX_SIDE =
            {
                LED_LS1,
                LED_RS1,
                LED_LS2,
                LED_RS2,
                LED_LS3,
                LED_RS3,
                LED_LS4,
                LED_RS4,
                LED_LS5,
                LED_RS5,
                LED_LS6,
                LED_RS6,
                LED_LS7,
                LED_RS7,
                LED_LS8,
                LED_RS8,
            },
        .RGB_MATRIX_INCATIVE_FN1 =
            {// OS MODE
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
             LED_Y, LED_U, LED_I, LED_O, LED_P, LED_H, LED_J, LED_K, LED_L, LED_SCLN, LED_QUOT, LED_N, LED_M, LED_COMM, LED_DOT, LED_SLSH},
        .RESET             = LED_BSLS,
        .OS_IDICATOR_LAYER = _FN1,
        .CAPS_LOCK         = LED_CAPS,
        .OS_MODE_DFT       = LED_F1,
        .OS_MODE_WIN       = LED_F2,
        .OS_MODE_MAC       = LED_F3,
    };
}

// void keyboard_post_init_user(void) { debug_enable = true; }

// tap dance

void                  caps_finished(qk_tap_dance_state_t *state, void *user_data);
void                  caps_reset(qk_tap_dance_state_t *state, void *user_data);
qk_tap_dance_action_t tap_dance_actions[] = {[TD_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, caps_finished, caps_reset)};

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
