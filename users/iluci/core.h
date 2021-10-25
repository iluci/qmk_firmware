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

#pragma once

#include QMK_KEYBOARD_H

#define MODS_SHIFT (get_mods() & MOD_MASK_SHIFT)
#define MODS_CTRL (get_mods() & MOD_MASK_CTRL)
#define MODS_ALT (get_mods() & MOD_MASK_ALT)
#define MODS_GUI (get_mods() & MOD_MASK_GUI)

#define RGB_TCC hsv_to_rgb((HSV){rgb_matrix_config.hsv.h - 85, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v})
#define RGB_TC hsv_to_rgb((HSV){rgb_matrix_config.hsv.h + 85, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v})
#define RGB_C hsv_to_rgb((HSV){rgb_matrix_config.hsv.h + 128, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v})

typedef enum {
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD,
} td_state_t;

enum td_codes { TD_CAPS };

// clang-format off

typedef enum { 
    LED_TRANS,
    LED_SIDE,
    LED_CAPS,
    LED_TC, LED_TCC, LED_COM,
    LED_B_DFT, LED_B_WIN, LED_B_MAC,
    LED_DFT, LED_WIN, LED_MAC,
} led_map_t;

enum user_custom_keycodes { 
    KC_USER_CUSTOM = SAFE_RANGE, 
    RGB_TG, RGB_EF, RGB_CO, 
    OS_DEFT, OS_WIN, OS_MAC, PSGN,
    NEW_SAFE_RANGE 
};

// clang-format on
