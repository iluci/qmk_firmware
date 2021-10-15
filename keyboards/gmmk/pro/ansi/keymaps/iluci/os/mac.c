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

bool is_alt_tabbing = false;

bool handle_mac_action(uint8_t os_action, bool pressed) {
    switch (os_action) {
        case SWITCH_WINDOW:
            if (pressed) {
                register_code16(KC_LGUI);
                register_code16(KC_TAB);
                is_alt_tabbing = true;
            }
            return true;
        case SWITCH_WINDOW_EXIT:
            if (!pressed && is_alt_tabbing) {
                unregister_code16(KC_LGUI);
            }
            return false;
        case SWITCH_WINDOW_NO_DIALOG:
            return execute_moded_keycode(KC_ESC, MOD_BIT(KC_LGUI), pressed);
        case OS_TASK_MANAGER:
            return execute_tapped_keycode(LGUI(LALT(KC_ESC)), pressed);

        case CALC:
            return execute_tapped_keycode(LGUI(KC_EQL), pressed);
        case SGN:
            return execute_tapped_keycode(LALT(KC_MINS), pressed);
        case OS_SCREENSHOT_SNIP:
            return execute_tapped_keycode(LCTL(LSFT(LGUI(KC_4))), pressed);

        case TXT_PREV_WORD:
            return execute_moded_keycode(KC_LEFT, MOD_BIT(KC_LALT), pressed);
        case TXT_NEXT_WORD:
            return execute_moded_keycode(KC_RIGHT, MOD_BIT(KC_LALT), pressed);
        case TXT_START_LINE:
            return execute_moded_keycode(KC_LEFT, MOD_BIT(KC_LGUI), pressed);
        case TXT_END_LINE:
            return execute_moded_keycode(KC_RIGHT, MOD_BIT(KC_LGUI), pressed);
        case TXT_START_DOC:
            return execute_moded_keycode(KC_UP, MOD_BIT(KC_LGUI), pressed);
        case TXT_END_DOC:
            return execute_moded_keycode(KC_DOWN, MOD_BIT(KC_LGUI), pressed);

        case TXT_DEL_NEXT_WORD:
            return execute_moded_keycode(KC_DEL, MOD_BIT(KC_LALT), pressed);
        case TXT_DEL_PREV_WORD:
            return execute_moded_keycode(KC_BSPC, MOD_BIT(KC_LALT), pressed);

        case TXT_BOLD:
            return execute_moded_keycode(KC_B, MOD_BIT(KC_LGUI), pressed);
        case TXT_UNDERLINE:
            return execute_moded_keycode(KC_U, MOD_BIT(KC_LGUI), pressed);
        case TXT_ITALIC:
            return execute_moded_keycode(KC_I, MOD_BIT(KC_LGUI), pressed);
        case TXT_FIND:
            return execute_moded_keycode(KC_F, MOD_BIT(KC_LGUI), pressed);

        case OS_UNDO:
            return execute_moded_keycode(KC_Z, MOD_BIT(KC_LGUI), pressed);
        case OS_REDO:
            return execute_moded_keycode(KC_Z, MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT), pressed);
        case OS_CUT:
            return execute_moded_keycode(KC_X, MOD_BIT(KC_LGUI), pressed);
        case OS_COPY:
            return execute_moded_keycode(KC_C, MOD_BIT(KC_LGUI), pressed);
        case OS_PASTE:
            return execute_moded_keycode(KC_V, MOD_BIT(KC_LGUI), pressed);
        case OS_PASTE_SPECIAL:
            return execute_moded_keycode(KC_Z, MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT), pressed);

        case OS_SELECT_ALL:
            return execute_moded_keycode(KC_A, MOD_BIT(KC_LGUI), pressed);
        case OS_SEARCH:
            return execute_moded_keycode(KC_SPC, MOD_BIT(KC_LGUI), pressed);

        case OS_FORCE_QUIT_APP:
            return execute_moded_keycode(KC_Q, MOD_BIT(KC_LGUI), pressed);
            return LGUI(KC_Q);
        case OS_LOCK_SCREEN:
            return execute_moded_keycode(KC_Q, MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI), pressed);

        case BROW_BOOKMARK:
            return execute_moded_keycode(KC_D, MOD_BIT(KC_LGUI), pressed);
        case BROW_REFRESH:
            return execute_moded_keycode(KC_R, MOD_BIT(KC_LGUI), pressed);
        case BROW_REFRESH_CACHE:
            return execute_moded_keycode(KC_R, MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT), pressed);
        case BROW_NEW_WINDOW:
            return execute_moded_keycode(KC_N, MOD_BIT(KC_LGUI), pressed);
        case BROW_INCOGNITO:
            return execute_moded_keycode(KC_N, MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT), pressed);
        case BROW_NEW_TAB:
            return execute_moded_keycode(KC_T, MOD_BIT(KC_LGUI), pressed);
        case BROW_CLOSE_TAB:
            return execute_moded_keycode(KC_W, MOD_BIT(KC_LGUI), pressed);
        case BROW_OPEN_LAST_CLOSED:
            return execute_moded_keycode(KC_T, MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT), pressed);

        case WINDOW_LEFT_HALF:
            return execute_tapped_keycode(LCTL(KC_LEFT), pressed);
        case WINDOW_RIGHT_HALF:
            return execute_tapped_keycode(LCTL(KC_RGHT), pressed);
        case WINDOW_TOP_HALF:
            return execute_tapped_keycode(LCTL(KC_UP), pressed);
        case WINDOW_LOWER_HALF:
            return execute_tapped_keycode(LCTL(KC_DOWN), pressed);
        case WINDOW_MAXIMIZE:
            return execute_tapped_keycode(LCTL(LGUI(KC_ENT)), pressed);

        default:
            return false;
    }
}
