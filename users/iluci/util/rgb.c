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

RGB triadic_counter_clockwise_rgb(void) { return hsv_to_rgb((HSV){rgb_matrix_config.hsv.h - 85, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v}); }
RGB triadic_clockwise_rgb(void) { return hsv_to_rgb((HSV){rgb_matrix_config.hsv.h + 85, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v}); }
RGB complimentary_rgb(void) { return hsv_to_rgb((HSV){rgb_matrix_config.hsv.h + 128, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v}); }

void rgb_matrix_set_color_led(uint8_t led, RGB color) { rgb_matrix_set_color(led, color.r, color.g, color.b); };
void rgb_matrix_set_color_leds(uint8_t* rgb_array, uint8_t rgb_array_size, RGB color) {
    for (unsigned int i = 0; i < rgb_array_size; i++) {
        rgb_matrix_set_color_led(rgb_array[i], color);
    }
};

void rgb_matrix_disable_leds(uint8_t* rgb_array, uint8_t rgb_array_size) {
    for (unsigned int i = 0; i < rgb_array_size; i++) {
        rgb_matrix_set_color(rgb_array[i], RGB_BLACK);
    }
}
