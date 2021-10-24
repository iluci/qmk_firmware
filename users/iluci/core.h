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

typedef struct led_indicators_config_t {
    bool initialized;

    uint8_t RGB_MATRIX_SIDE[50];
    uint8_t RGB_MATRIX_INCATIVE_FN1[50];
    uint8_t RESET;
    uint8_t CAPS_LOCK;
    uint8_t OS_IDICATOR_LAYER;
    uint8_t OS_MODE_DFT;
    uint8_t OS_MODE_WIN;
    uint8_t OS_MODE_MAC;

} led_indicators_config_t;

// clang-format off

enum user_custom_keycodes { 
    KC_USER_CUSTOM = SAFE_RANGE, 
    RGB_TG, RGB_EF, RGB_CO, 
    OS_DEFT, OS_WIN, OS_MAC, PSGN,
    NEW_SAFE_RANGE 
};

// clang-format on
