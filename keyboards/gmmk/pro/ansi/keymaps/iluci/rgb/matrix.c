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
#include "matrix.h"
#include "../keymap.h"
#include "rgb/rgb.h"
#include "os/os.h"

extern uint8_t os_mode;

bool enable_side_rgb_matrix = false;
bool enable_idicators       = false;

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    RGB triadic_counter_clockwise_rgb = hsv_to_rgb((HSV){rgb_matrix_config.hsv.h - 85, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v});
    RGB triadic_clockwise_rgb         = hsv_to_rgb((HSV){rgb_matrix_config.hsv.h + 85, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v});
    RGB complimentary_rgb             = hsv_to_rgb((HSV){rgb_matrix_config.hsv.h + 128, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v});

    layer_state_t highest_layer = get_highest_layer(layer_state | default_layer_state);

    if (!enable_side_rgb_matrix) {
        array_rgb_matrix_set_color(rgb_matrix_side, sizeof(rgb_matrix_side), RGB_BLACK);
    }

    if (get_autoshift_state()) {
        rgb_matrix_set_color(LED_CAPS, triadic_counter_clockwise_rgb.r, triadic_counter_clockwise_rgb.g, triadic_counter_clockwise_rgb.b);
    }

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(LED_CAPS, triadic_clockwise_rgb.r, triadic_clockwise_rgb.g, triadic_clockwise_rgb.b);
    }

    if (IS_LAYER_ON(_FN1)) {
        array_rgb_matrix_set_color(rgb_matrix_inactive_fn1, sizeof(rgb_matrix_inactive_fn1), triadic_counter_clockwise_rgb.r, triadic_counter_clockwise_rgb.g, triadic_counter_clockwise_rgb.b);
        rgb_matrix_set_color(LED_BSLS, complimentary_rgb.r, complimentary_rgb.g, complimentary_rgb.b);
    }

    if (enable_idicators || highest_layer == _FN1) {
        if (IS_LAYER_OFF(_DFT)) {
            if (os_mode == WIN_MODE) {
                rgb_matrix_set_color(LED_F2, triadic_clockwise_rgb.r, triadic_clockwise_rgb.g, triadic_clockwise_rgb.b);
            } else if (os_mode == MAC_MODE) {
                rgb_matrix_set_color(LED_F3, triadic_clockwise_rgb.r, triadic_clockwise_rgb.g, triadic_clockwise_rgb.b);
            }
        }
    }

    if (IS_LAYER_ON(_DFT)) {
        rgb_matrix_set_color(LED_F1, triadic_clockwise_rgb.r, triadic_clockwise_rgb.g, triadic_clockwise_rgb.b);
    }
}
