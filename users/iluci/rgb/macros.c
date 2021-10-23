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
#include "rgb.h"
#include "../util/util.h"

bool enable_idicators       = false;
bool enable_side_rgb_matrix = false;

bool rgb_macros(uint16_t keycode, bool pressed) {
    switch (keycode) {
        case RGB_TG:
            if (pressed) {
                if (is_any_ctrl()) {
                    enable_side_rgb_matrix = !enable_side_rgb_matrix;
                } else if (is_any_alt()) {
                    enable_idicators = !enable_idicators;
                } else {
                    rgb_matrix_toggle();
                }
            }
            return true;
        case RGB_EF:
            if (pressed) {
                if (is_any_ctrl()) {
                    if (is_any_shift()) {
                        rgb_matrix_decrease_speed();
                    } else {
                        rgb_matrix_increase_speed();
                    }
                } else {
                    if (is_any_shift()) {
                        rgb_matrix_step_reverse();
                    } else {
                        rgb_matrix_step();
                    }
                }
            }
            return true;
        case RGB_CO:
            if (pressed) {
                if (is_any_ctrl()) {
                    if (is_any_shift()) {
                        rgb_matrix_decrease_sat();
                    } else {
                        rgb_matrix_increase_sat();
                    }
                } else {
                    if (is_any_shift()) {
                        rgb_matrix_decrease_hue();
                    } else {
                        rgb_matrix_increase_hue();
                    }
                }
            }
            return true;
    }

    return false;
}
