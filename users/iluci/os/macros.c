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
#include "../util/util.h"

bool os_macros(uint16_t keycode, bool pressed) {
    bool    handled           = false;
    uint8_t initial_mod_state = get_mods();

    switch (keycode) {
        case KC_RALT:
        case KC_LALT:
            handled = handle_os_action(SWITCH_WINDOW_EXIT, pressed);
            break;
        case KC_TAB:
            if (is_any_alt()) {
                del_mods(MOD_MASK_ALT);
                handled = handle_os_action(SWITCH_WINDOW, pressed);
                if (!handled) {
                    set_mods(initial_mod_state);
                }
            }
            break;
        case KC_ESC:
            if (is_any_alt()) {
                handled = handle_os_mod_mask_action(SWITCH_WINDOW_NO_DIALOG, pressed, MOD_MASK_ALT);
            } else if (is_any_ctrl() && is_any_shift()) {
                handled = handle_os_mod_mask_action(OS_TASK_MANAGER, pressed, MOD_MASK_CS);
            }
            break;

        case KC_CALC:
            handled = handle_os_mod_mask_action(CALC, pressed, 0);
            break;
        case PSGN:
            handled = handle_os_mod_mask_action(SGN, pressed, 0);
            break;
        case KC_PSCR:
            handled = handle_os_mod_mask_action(OS_SCREENSHOT_SNIP, pressed, 0);
            break;

        case KC_LEFT:
            if (is_any_ctrl() && is_any_gui()) {
                handled = handle_os_mod_mask_action(WINDOW_LEFT_HALF, pressed, MOD_MASK_CTRL);
            } else if (is_any_ctrl() && !is_any_alt()) {
                handled = handle_os_mod_mask_action(TXT_PREV_WORD, pressed, MOD_MASK_CTRL);
            }
            break;
        case KC_RGHT:
            if (is_any_ctrl() && is_any_gui()) {
                handled = handle_os_mod_mask_action(WINDOW_RIGHT_HALF, pressed, MOD_MASK_CTRL);
            } else if (is_any_ctrl() && !is_any_alt()) {
                handled = handle_os_mod_mask_action(TXT_NEXT_WORD, pressed, MOD_MASK_CTRL);
            }
            break;
        case KC_UP:
            if (is_any_ctrl() && is_any_gui()) {
                handled = handle_os_mod_mask_action(WINDOW_TOP_HALF, pressed, MOD_MASK_CTRL);
            }
            break;
        case KC_DOWN:
            if (is_any_ctrl() && is_any_gui()) {
                handled = handle_os_mod_mask_action(WINDOW_LOWER_HALF, pressed, MOD_MASK_CTRL);
            }
            break;
        case KC_HOME:
            if (is_any_ctrl()) {
                handled = handle_os_mod_mask_action(TXT_START_DOC, pressed, MOD_MASK_CTRL);
            } else {
                handled = handle_os_mod_mask_action(TXT_START_LINE, pressed, 0);
            }
            break;
        case KC_END:
            if (is_any_ctrl()) {
                handled = handle_os_mod_mask_action(TXT_END_DOC, pressed, MOD_MASK_CTRL);
            } else {
                handled = handle_os_mod_mask_action(TXT_END_LINE, pressed, 0);
            }
            break;

        case KC_DEL:
            if (is_any_ctrl()) {
                handled = handle_os_mod_mask_action(TXT_DEL_NEXT_WORD, pressed, MOD_MASK_CTRL);
            }
            break;
        case KC_BSPC:
            if (is_any_ctrl()) {
                handled = handle_os_mod_mask_action(TXT_DEL_PREV_WORD, pressed, MOD_MASK_CTRL);
            }
            break;

        case KC_B:
            if (is_any_ctrl()) {
                handled = handle_os_mod_mask_action(TXT_BOLD, pressed, MOD_MASK_CTRL);
            }
            break;
        case KC_U:
            if (is_any_ctrl()) {
                handled = handle_os_mod_mask_action(TXT_UNDERLINE, pressed, MOD_MASK_CTRL);
            }
            break;
        case KC_I:
            if (is_any_ctrl()) {
                handled = handle_os_mod_mask_action(TXT_ITALIC, pressed, MOD_MASK_CTRL);
            }
            break;
        case KC_F:
            if (is_any_ctrl()) {
                handled = handle_os_mod_mask_action(TXT_FIND, pressed, MOD_MASK_CTRL);
            }
            break;

        case KC_Z:
            if (is_any_ctrl()) {
                if (is_any_alt()) {
                    handled = handle_os_mod_mask_action(OS_REDO, pressed, MOD_MASK_CA);
                } else {
                    handled = handle_os_mod_mask_action(OS_UNDO, pressed, MOD_MASK_CTRL);
                }
            }
            break;
        case KC_X:
            if (is_any_ctrl()) {
                handled = handle_os_mod_mask_action(OS_CUT, pressed, MOD_MASK_CTRL);
            }
            break;
        case KC_C:
            if (is_any_ctrl()) {
                handled = handle_os_mod_mask_action(OS_COPY, pressed, MOD_MASK_CTRL);
            }
            break;
        case KC_V:
            if (is_any_ctrl()) {
                handled = handle_os_mod_mask_action(OS_PASTE, pressed, MOD_MASK_CTRL);
            } else if (is_any_gui()) {
                handled = handle_os_mod_mask_action(OS_PASTE_SPECIAL, pressed, MOD_MASK_GUI);
            }
            break;

        case KC_A:
            if (is_any_ctrl()) {
                handled = handle_os_mod_mask_action(OS_SELECT_ALL, pressed, MOD_MASK_CTRL);
            }
            break;
        case KC_S:
            if (is_any_gui()) {
                handled = handle_os_mod_mask_action(OS_SEARCH, pressed, MOD_MASK_GUI);
            }
            break;
        case KC_F4:
            if (is_any_alt()) {
                handled = handle_os_mod_mask_action(OS_FORCE_QUIT_APP, pressed, MOD_MASK_ALT);
            }
            break;
        case KC_L:
            if (is_any_gui()) {
                handled = handle_os_mod_mask_action(OS_LOCK_SCREEN, pressed, MOD_MASK_GUI);
            }
            break;

        case KC_D:
            if (is_any_ctrl()) {
                handled = handle_os_mod_mask_action(BROW_BOOKMARK, pressed, MOD_MASK_CTRL);
            }
            break;
        case KC_R:
            if (is_any_ctrl()) {
                if (is_any_shift()) {
                    handled = handle_os_mod_mask_action(BROW_REFRESH_CACHE, pressed, MOD_MASK_CS);
                } else {
                    handled = handle_os_mod_mask_action(BROW_REFRESH, pressed, MOD_MASK_CTRL);
                }
            }
            break;
        case KC_N:
            if (is_any_ctrl()) {
                if (is_any_shift()) {
                    handled = handle_os_mod_mask_action(BROW_INCOGNITO, pressed, MOD_MASK_CS);
                } else {
                    handled = handle_os_mod_mask_action(BROW_NEW_WINDOW, pressed, MOD_MASK_CTRL);
                }
            }
            break;
        case KC_T:
            if (is_any_ctrl()) {
                if (is_any_shift()) {
                    handled = handle_os_mod_mask_action(BROW_OPEN_LAST_CLOSED, pressed, MOD_MASK_CS);
                } else {
                    handled = handle_os_mod_mask_action(BROW_NEW_TAB, pressed, MOD_MASK_CTRL);
                }
            }
            break;
        case KC_W:
            if (is_any_ctrl()) {
                handled = handle_os_mod_mask_action(BROW_CLOSE_TAB, pressed, MOD_MASK_CTRL);
            }
            break;

        case KC_ENT:
            if (is_any_ctrl() && is_any_gui()) {
                handled = handle_os_mod_mask_action(WINDOW_MAXIMIZE, pressed, MOD_MASK_CG);
                del_mods(MOD_MASK_GUI);
            }
            break;
    }

    return handled;
}
