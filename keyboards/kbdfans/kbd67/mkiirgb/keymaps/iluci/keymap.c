/* Copyright 2021 iluci

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
#include "keymap.h"
#include "core.h"
#include "os/os.h"

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//      ESC        1         2        3        4        5        6        7        8        9        0          -          (=)       BackSpc               Del
//      Tab        Q         W        E        R        T        Y        U        I        O        P          [          ]         \          ```           Home
//      Caps       A         S        D        F        G        H        J        K        L        ;          "                    Enter                 End
//      Sh_L       Z         X        C        V        B        N        M        ,        .        ?                     Sh_R                 Up         Ins
//      Ct_L       Win_L     Alt_L                               SPACE                                          FN         Ct_R      Left       Down       Right
//    [-1] = LAYOUT_65_ansi_blocker(
//         _______,   _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______,   _______,   _______,   _______,              _______,
//         _______,   _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______,   _______,   _______,   _______,              _______,
//         _______,   _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______,   _______,              _______,              _______,
//         _______,   _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______,   _______,                         _______,   _______,
//         _______,   _______,  _______,                            _______,                                        _______,   _______,   _______,   _______,   _______
//    ),
//    [-1] = LAYOUT_65_ansi_blocker(
//         XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              XXXXXXX,
//         XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              XXXXXXX,
//         XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,              XXXXXXX,              XXXXXXX,
//         XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,                         XXXXXXX,   XXXXXXX,
//         XXXXXXX,   XXXXXXX,  XXXXXXX,                            XXXXXXX,                                        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX
//    ),
    [_BASE] = LAYOUT_65_ansi_blocker(
        KC_ESC,    KC_1,     KC_2,    KC_3,    KC_4,     KC_5,     KC_6,    KC_7,     KC_8,    KC_9,    KC_0,      KC_MINS,   KC_EQL,   KC_BSPC,               KC_DEL,
        KC_TAB,    KC_Q,     KC_W,    KC_E,    KC_R,     KC_T,     KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,      KC_LBRC,   KC_RBRC,  KC_BSLASH,             KC_HOME,
        KC_CAPS,   KC_A,     KC_S,    KC_D,    KC_F,     KC_G,     KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN,   KC_QUOT,             KC_ENT,                KC_END,
        KC_LSFT,   KC_Z,     KC_X,    KC_C,    KC_V,     KC_B,     KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH,   KC_RSFT,                         KC_UP,     KC_INSERT,
        KC_LCTL,   KC_LGUI,  KC_LALT,                              KC_SPC,                                         MO(_FN),  MO(_UTIL), KC_LEFT,    KC_DOWN,   KC_RIGHT
    ),
    [_FN] = LAYOUT_65_ansi_blocker(
        KC_GRV,    KC_F1,    KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,    KC_F11,    KC_F12,    _______,              OS_DEFT,
        _______,   _______,  _______, _______, _______,  _______,  _______, _______,  _______, _______, _______,   _______,   _______,   _______,              OS_WIN,
        _______,   _______,  _______, _______, _______,  _______,  _______, _______,  _______, _______, _______,   _______,              _______,              OS_MAC,
        _______,   _______,  _______, _______, _______,  _______,  _______, _______,  _______, _______, _______,   _______,                         _______,   _______,
        _______,   _______,  _______,                              _______,                                        _______,   _______,   _______,   _______,   _______
    ),
    [_UTIL] = LAYOUT_65_ansi_blocker(
        TG(_UTIL), XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TG(_NUM),
        XXXXXXX,   KC_BTN1,  KC_MS_U, KC_BTN1, KC_WH_U,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, KC_PSCR,   XXXXXXX,   XXXXXXX,   RESET,                TG(_RGB),
        XXXXXXX,   KC_MS_L,  KC_MS_D, KC_MS_R, KC_WH_D,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,              XXXXXXX,              XXXXXXX,
        XXXXXXX,   XXXXXXX,  XXXXXXX, KC_CALC, XXXXXXX,  XXXXXXX,  XXXXXXX, KC_MUTE,  KC_VOLD, KC_VOLU, XXXXXXX,   XXXXXXX,                         XXXXXXX,   XXXXXXX,
        XXXXXXX,   XXXXXXX,  XXXXXXX,                              XXXXXXX,                                        XXXXXXX,   _______,   XXXXXXX,   XXXXXXX,   XXXXXXX
    ),
    [_NUM] = LAYOUT_65_ansi_blocker(
        TG(_NUM),  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              XXXXXXX,
        XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  PSGN,    KC_P7,   KC_P8,    KC_P9,   KC_PAST,   XXXXXXX,   XXXXXXX,   XXXXXXX,              XXXXXXX,
        XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  KC_P0,   KC_P4,   KC_P5,    KC_P6,   KC_PMNS,   KC_PSLS,              XXXXXXX,              XXXXXXX,
        XXXXXXX,   XXXXXXX,  XXXXXXX, KC_CALC, XXXXXXX,  XXXXXXX,  KC_PDOT, KC_P1,   KC_P2,    KC_P3,   KC_PPLS,   XXXXXXX,                         XXXXXXX,   XXXXXXX,
        XXXXXXX,   XXXXXXX,  XXXXXXX,                              XXXXXXX,                                        _______,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX
    ),
    [_RGB] = LAYOUT_65_ansi_blocker(
        TG(_RGB),  RGB_M_P,  RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G,  RGB_M_T, RGB_M_TW,  RGB_SD,    RGB_SI,    XXXXXXX,              RGB_TOG,
        XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              RGB_TGI,
        XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,   XXXXXXX,              XXXXXXX,              RGB_TGS,
        XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, RGB_RMOD, RGB_MOD, XXXXXXX,   XXXXXXX,                         RGB_VAI,   XXXXXXX,
        XXXXXXX,   XXXXXXX,  XXXXXXX,                              XXXXXXX,                                        XXXXXXX,   XXXXXXX,   RGB_HUD,   RGB_VAD,   RGB_HUI
   ),
};

#undef _______
#define _______ LED_TRANS

// LED_CAPS LED_TCC LED_COM
const led_map_t PROGMEM led_map[][DRIVER_LED_TOTAL] = {
    [_BASE] = LED_MAP_LAYOUT(
        _______,   _______,  _______, _______, _______,  _______,  _______, _______, _______,  _______, _______,   _______,   _______,  _______,               LED_B_DFT,
        _______,   _______,  _______, _______, _______,  _______,  _______, _______, _______,  _______, _______,   _______,   _______,  _______,               LED_B_WIN,
        LED_CAPS,  _______,  _______, _______, _______,  _______,  _______, _______, _______,  _______, _______,   _______,             _______,               LED_B_MAC,
        _______,   _______,  _______, _______, _______,  _______,  _______, _______, _______,  _______, _______,   _______,                         _______,   _______,
        _______,   _______,  _______,                              _______,                                        _______,   _______,  _______,    _______,   _______
    ),
    [_FN] = LED_MAP_LAYOUT(
        _______,   _______,  _______, _______, _______,  _______,  _______, _______, _______,  _______, _______,   _______,   _______,  _______,               LED_DFT,
        _______,   _______,  _______, _______, _______,  _______,  _______, _______, _______,  _______, _______,   _______,   _______,  _______,               LED_WIN,
        LED_CAPS,  _______,  _______, _______, _______,  _______,  _______, _______, _______,  _______, _______,   _______,             _______,               LED_MAC,
        _______,   _______,  _______, _______, _______,  _______,  _______, _______, _______,  _______, _______,   _______,                         _______,   _______,
        _______,   _______,  _______,                              _______,                                        _______,   _______,  _______,    _______,   _______
    ),
    [_UTIL] = LED_MAP_LAYOUT(
        LED_COM,   _______,  _______, _______, _______,  _______,  _______, _______, _______,  _______, _______,   _______,   _______,  _______,               LED_COM,
        _______,   LED_TCC,  LED_COM, LED_TCC, LED_TCC,  _______,  _______, _______, _______,  _______, _______,   _______,   _______,  LED_COM,               LED_COM,
        _______,   LED_COM,  LED_COM, LED_COM, LED_TCC,  _______,  _______, _______, _______,  _______, _______,   _______,             _______,               _______,
        _______,   _______,  _______, LED_TCC, _______,  _______,  _______, LED_COM, LED_TCC,  LED_TCC, _______,   _______,                         _______,   _______,
        _______,   _______,  _______,                              _______,                                        _______,   _______,  _______,    _______,   _______
    ),
    [_NUM] = LED_MAP_LAYOUT(
        LED_COM,   _______,  _______, _______, _______,  _______,  _______, _______, _______,  _______, _______,   _______,   _______,  _______,               _______,
        _______,   _______,  _______, _______, _______,  _______,  LED_TCC, LED_COM, LED_COM,  LED_COM, LED_TCC,   _______,   _______,  _______,               _______,
        _______,   _______,  _______, _______, _______,  _______,  LED_COM, LED_COM, LED_COM,  LED_COM, LED_TCC,   LED_TCC,             _______,               _______,
        _______,   _______,  _______, LED_TCC, _______,  _______,  LED_TCC, LED_COM, LED_COM,  LED_COM, LED_TCC,   _______,                         _______,   _______,
        _______,   _______,  _______,                              _______,                                        _______,   _______,  _______,    _______,   _______
    ),
    [_RGB] = LED_MAP_LAYOUT(
        LED_COM,   LED_TCC,  LED_TCC, LED_TCC, LED_TCC,  LED_TCC,  LED_TCC, LED_TCC, LED_TCC,  LED_TCC, LED_TCC,   LED_TCC,   LED_TCC,  _______,               LED_TCC,
        _______,   _______,  _______, _______, _______,  _______,  _______, _______, _______,  _______, _______,   _______,   _______,  _______,               LED_TCC,
        _______,   _______,  _______, _______, _______,  _______,  _______, _______, _______,  _______, _______,   _______,             _______,               LED_TCC,
        _______,   _______,  _______, _______, _______,  _______,  _______, _______, _______,  _______, _______,   _______,                         LED_TCC,   _______,
        _______,   _______,  _______,                              _______,                                        _______,   _______,  LED_TCC,    LED_TCC,   LED_TCC
    ),
};

#undef _______
#define _______ KC_TRNS

// clang-format on


os_mode = OS_MODE_DFT
