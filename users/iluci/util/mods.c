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

bool is_any_ctrl(void) { return get_mods() & MOD_MASK_CTRL; }
bool is_any_gui(void) { return get_mods() & MOD_MASK_GUI; }
bool is_any_alt(void) { return get_mods() & MOD_MASK_ALT; }
bool is_any_shift(void) { return get_mods() & MOD_MASK_SHIFT; }
