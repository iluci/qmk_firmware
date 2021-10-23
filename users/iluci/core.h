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

// clang-format off

enum user_custom_keycodes { 
    KC_USER_CUSTOM = SAFE_RANGE, 
    RGB_TG, RGB_EF, RGB_CO, 
    OS_DEFT, OS_WIN, OS_MAC, PSGN,
    NEW_SAFE_RANGE 
};

// clang-format on
