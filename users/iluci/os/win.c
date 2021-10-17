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
#include "os.h"

bool handle_win_action(uint8_t os_action, bool pressed) {
    switch (os_action) {
        case SGN:
            return execute_tapped_keycode(KC_F9, pressed);
        case OS_SCREENSHOT_SNIP:
            return execute_tapped_keycode(LGUI(LSFT(KC_S)), pressed);

        case OS_REDO:
            return execute_moded_keycode(KC_Y, MOD_BIT(KC_LCTL), pressed);

        case BROW_REFRESH_CACHE:
            return execute_moded_keycode(KC_F5, MOD_BIT(KC_LCTL), pressed);

        case WINDOW_LEFT_HALF:
            return execute_tapped_keycode(KC_LEFT, pressed);
        case WINDOW_RIGHT_HALF:
            return execute_tapped_keycode(KC_RGHT, pressed);
        case WINDOW_TOP_HALF:
            return execute_tapped_keycode(KC_UP, pressed);
        case WINDOW_LOWER_HALF:
            return execute_tapped_keycode(KC_DOWN, pressed);
        case WINDOW_MAXIMIZE:
            execute_tapped_keycode(LALT(KC_SPC), pressed);
            execute_tapped_keycode(KC_X, pressed);
            return true;

        default:
            return false;
    }
}
