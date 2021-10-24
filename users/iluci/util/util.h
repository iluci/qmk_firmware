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

void encoder_execute(uint16_t counterClockwiseAction, uint16_t clockwiseAction, bool clockwise);

// TODO check if you can use this
// #define MODS_SHIFT ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT)
// #define MODS_CTRL  ((get_mods() | get_oneshot_mods()) & MOD_MASK_CTRL)
// #define MODS_ALT   ((get_mods() | get_oneshot_mods()) & MOD_MASK_ALT)
// #define MODS_GUI   ((get_mods() | get_oneshot_mods()) & MOD_MASK_GUI)

bool is_any_ctrl(void);
bool is_any_gui(void);
bool is_any_alt(void);
bool is_any_shift(void);

typedef enum { TD_UNKNOWN, TD_SINGLE_TAP, TD_SINGLE_HOLD, TD_DOUBLE_TAP, TD_DOUBLE_HOLD, TD_TRIPLE_TAP, TD_TRIPLE_HOLD } td_state_t;

// td_state_t cur_dance(qk_tap_dance_state_t* state);

RGB triadic_counter_clockwise_rgb(void);
RGB triadic_clockwise_rgb(void);
RGB complimentary_rgb(void);

void rgb_matrix_set_color_led(uint8_t led, RGB color);
void rgb_matrix_set_color_leds(uint8_t* rgb_array, uint8_t rgb_array_size, RGB color);

void rgb_matrix_disable_leds(uint8_t* rgb_array, uint8_t rgb_array_size);
