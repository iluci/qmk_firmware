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

enum os_modes { WIN_MODE, MAC_MODE };

// clang-format off

enum custom_keycodes { 
    FOO = SAFE_RANGE, 
    RGB_TG, RGB_EF, RGB_CO, 
    WIN, MAC, DEFAULT, 
    PSGN
};

// clang-format on

enum layers { _BASE, _DFT, _FN1 };

typedef enum { TD_UNKNOWN, TD_SINGLE_TAP, TD_SINGLE_HOLD, TD_DOUBLE_TAP, TD_DOUBLE_HOLD, TD_TRIPLE_TAP, TD_TRIPLE_HOLD } td_state_t;

enum td_codes { TD_CAPS, TD_TAB };
