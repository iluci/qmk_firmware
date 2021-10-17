
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

enum os_modes { WIN_MODE, MAC_MODE };

enum os_actions {
    // More here https://en.wikipedia.org/wiki/Table_of_keyboard_shortcuts

    SWITCH_WINDOW,
    SWITCH_WINDOW_EXIT,
    SWITCH_WINDOW_NO_DIALOG,
    OS_TASK_MANAGER,

    SGN,
    CALC,
    OS_SCREENSHOT_SNIP,

    TXT_PREV_WORD,
    TXT_NEXT_WORD,
    TXT_START_LINE,
    TXT_END_LINE,
    TXT_START_DOC,
    TXT_END_DOC,

    TXT_DEL_NEXT_WORD,
    TXT_DEL_PREV_WORD,

    TXT_BOLD,
    TXT_UNDERLINE,
    TXT_ITALIC,
    TXT_FIND,

    OS_UNDO,
    OS_REDO,
    OS_CUT,
    OS_COPY,
    OS_PASTE,
    OS_PASTE_SPECIAL,

    OS_SELECT_ALL,
    OS_SEARCH,

    OS_FORCE_QUIT_APP,
    OS_LOCK_SCREEN,

    BROW_BOOKMARK,
    BROW_REFRESH,
    BROW_REFRESH_CACHE,
    BROW_NEW_WINDOW,
    BROW_INCOGNITO,
    BROW_NEW_TAB,
    BROW_CLOSE_TAB,
    BROW_OPEN_LAST_CLOSED,

    WINDOW_LEFT_HALF,
    WINDOW_RIGHT_HALF,
    WINDOW_TOP_HALF,
    WINDOW_LOWER_HALF,
    WINDOW_MAXIMIZE
};

bool handle_os_action(uint8_t os_action, bool pressed);
bool handle_mac_action(uint8_t os_action, bool pressed);
bool handle_win_action(uint8_t os_action, bool pressed);

bool handle_os_mod_mask_action(uint8_t os_action, bool pressed, uint8_t mod_mask);

bool execute_tapped_keycode(uint16_t keycode, bool pressed);
bool execute_moded_keycode(uint16_t keycode, uint8_t mod_mask, bool pressed);
