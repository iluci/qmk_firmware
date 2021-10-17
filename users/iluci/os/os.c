
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

uint8_t os_mode        = WIN_MODE;

bool handle_os_action(uint8_t os_action, bool pressed) {
    switch (os_mode) {
        case WIN_MODE:
            return handle_win_action(os_action, pressed);
        case MAC_MODE:
            return handle_mac_action(os_action, pressed);
        default:
            return false;
    }
}

bool handle_os_mod_mask_action(uint8_t os_action, bool pressed, uint8_t mod_mask) {
    uint8_t initial_mod_state = get_mods();

    del_mods(mod_mask);
    bool handled = handle_os_action(os_action, pressed);

    set_mods(initial_mod_state);
    return handled;
}

bool execute_tapped_keycode(uint16_t keycode, bool pressed) {
    if (pressed) {
        tap_code16(keycode);
    }
    return true;
}

bool execute_moded_keycode(uint16_t keycode, uint8_t mod_mask, bool pressed) {
    if (pressed) {
        add_mods(mod_mask);
        register_code16(keycode);

    } else {
        del_mods(mod_mask);
        unregister_code16(keycode);
    }

    return true;
}
