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

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//                 ESC        F1         F2         F3         F4         F5         F6         F7         F8         F9         F10        F11        F12        Prt                   Rotary(Mute)
//                 ~          1          2          3          4          5          6          7          8          9          0           -         (=)        BackSpc               Del
//                 Tab        Q          W          E          R          T          Y          U          I          O          P          [          ]          \                     Home
//                 Caps       A          S          D          F          G          H          J          K          L          ;          "                     Enter                 End
//                 Sh_L       Z          X          C          V          B          N          M          ,          .          ?                     Sh_R                  Up         Ins
//                 Ct_L       Win_L      Alt_L                                       SPACE                                       Alt_R      FN         Ct_R       Left       Down       Right

    [_BASE] = LAYOUT(
                   KC_ESC,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_PSCR,              KC_LOCK,
                   KC_GRV,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,   KC_EQL,    KC_BSPC,              KC_DEL,
                   KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_LBRC,   KC_RBRC,   KC_BSLS,              KC_HOME,
                   TD(TDC),   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,              KC_ENT,               KC_END,
                   KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,              KC_RSFT,              KC_UP,     KC_INSERT,
                   KC_LCTL,   KC_LGUI,   KC_LALT,                                    KC_SPC,                                     KC_RALT,   MO(_FN1),  KC_RCTL,   KC_LEFT,   KC_DOWN,   KC_RGHT
    ),
    [_FN1] = LAYOUT(
                   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              KC_MUTE,
                   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              OS_DEFT,
                   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_PSCR,   _______,   _______,   _______,              OS_WIN,
                   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_MPLY,   KC_MPRV,   KC_MNXT,   KC_MSTP,   _______,              _______,              OS_MAC,
                   _______,   _______,   _______,   KC_CALC,   _______,   _______,   _______,   KC_MUTE,   KC_VOLD,   KC_VOLU,   _______,              _______,              _______,   _______,
                   _______,   _______,   _______,                                    _______,                                    TT(_UTIL), _______,   _______,   _______,   _______,   _______
    ),
    [_UTIL] = LAYOUT(
                   TG(_UTIL), _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,
                   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              RGB_TG,
                   _______,   KC_BTN1,   KC_MS_U,   KC_BTN1,   KC_WH_U,   _______,   PSGN,      KC_P7,     KC_P8,     KC_P9,     KC_PAST,   _______,   _______,   RESET,                RGB_EF,
                   _______,   KC_MS_L,   KC_MS_D,   KC_MS_R,   KC_WH_D,   _______,   KC_P0,     KC_P4,     KC_P5,     KC_P6,     KC_PMNS,   KC_PSLS,              _______,              RGB_CO,
                   _______,   _______,   _______,   _______,   _______,   _______,   KC_PDOT,   KC_P1,     KC_P2,     KC_P3,     KC_PPLS,              _______,              _______,   RGB_VAI,
                   _______,   _______,   _______,                                    _______,                                    _______,   _______,   _______,   _______,   _______,   _______
    )
};

#ifdef _______
#undef _______
#define _______ LED_TRANS

const led_map_t PROGMEM led_map[][DRIVER_LED_TOTAL] = {
    [_BASE] = LED_MAP_LAYOUT(
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                         _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              LED_B_DFT, _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              LED_B_WIN, _______,
        _______,   LED_CAPS,  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,              LED_B_MAC, _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,              _______,   _______,   _______,
        _______,   _______,   _______,   _______,                                    _______,                                    _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,                                                                                                                                                                                   _______,
        _______,                                                                                                                                                                                   _______
    ),
    [_FN1] = LED_MAP_LAYOUT(
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                         _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              LED_DFT,   _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   LED_COM,   _______,   _______,   _______,              LED_WIN,   _______,
        _______,   LED_CAPS,  _______,   _______,   _______,   _______,   _______,   _______,   LED_TCC,   LED_TCC,   LED_TCC,   LED_TCC,   _______,              _______,              LED_MAC,   _______,
        _______,   _______,   _______,   _______,   LED_COM,   _______,   _______,   _______,   LED_TCC,   LED_TCC,   LED_TCC,   _______,              _______,              _______,   _______,   _______,
        _______,   _______,   _______,   _______,                                    _______,                                    _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,                                                                                                                                                                                   _______,
        _______,                                                                                                                                                                                   _______
    ),
    [_UTIL] = LED_MAP_LAYOUT(
        _______,   LED_TC,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                         _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              LED_TCC,   _______,
        _______,   _______,   LED_COM,   LED_TCC,   LED_COM,   LED_COM,   _______,   LED_COM,   LED_TCC,   LED_TCC,   LED_TCC,   LED_COM,   _______,   _______,   LED_TC,               LED_TCC,   _______,
        _______,   LED_CAPS,  LED_TCC,   LED_TCC,   LED_TCC,   LED_COM,   _______,   LED_COM,   LED_TCC,   LED_TCC,   LED_TCC,   LED_COM,   LED_COM,              _______,              LED_TCC,   _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   LED_COM,   LED_TCC,   LED_TCC,   LED_TCC,   LED_COM,              _______,              _______,   LED_TCC,   _______, 
        _______,   _______,   _______,   _______,                                    _______,                                    _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,                                                                                                                                                                                   _______,
        _______,                                                                                                                                                                                   _______
    ),
};

#undef _______
#define _______ KC_TRNS
#endif

// clang-format on

bool is_fn_layer(void) { return IS_LAYER_ON(_FN1); }
