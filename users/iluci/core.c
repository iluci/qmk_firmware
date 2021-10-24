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
#include "core.h"
#include "os/os.h"
#include "util/util.h"

__attribute__((weak)) bool process_record_user_keymap(uint16_t keycode, keyrecord_t *record) { return true; }
__attribute__((weak)) void rgb_matrix_indicators_keymap(uint8_t led_min, uint8_t led_max) {}

__attribute__((weak)) led_indicators_config_t led_indicators_config(void) { return (led_indicators_config_t){}; }

extern bool    enable_idicators;
extern uint8_t os_mode;

bool enable_idicators       = false;
bool enable_side_rgb_matrix = false;

// macros

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool handled = false;
    bool pressed = record->event.pressed;

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
            return false;
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
            return false;
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
            return false;
    }

    handled = os_macros(keycode, pressed);
    if (handled) {
        return false;
    }

    return process_record_user_keymap(keycode, record);
}

// end macros

// rgb

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    led_indicators_config_t indicators = led_indicators_config();

    if (indicators.initialized) {
        if (!enable_side_rgb_matrix) {
            //TODO: reenable
            // rgb_matrix_disable_leds(indicators.RGB_MATRIX_SIDE, sizeof(indicators.RGB_MATRIX_SIDE));
        }

        if (IS_LAYER_ON(indicators.OS_IDICATOR_LAYER)) {
            rgb_matrix_set_color_leds(indicators.RGB_MATRIX_INCATIVE_FN1, sizeof(indicators.RGB_MATRIX_INCATIVE_FN1), triadic_counter_clockwise_rgb());
            rgb_matrix_set_color_led(indicators.RESET, complimentary_rgb());
        }

        if (get_autoshift_state()) {
            rgb_matrix_set_color_led(indicators.CAPS_LOCK, triadic_counter_clockwise_rgb());
        }

        if (host_keyboard_led_state().caps_lock) {
            rgb_matrix_set_color_led(indicators.CAPS_LOCK, triadic_clockwise_rgb());
        }

        if (enable_idicators || IS_LAYER_ON(indicators.OS_IDICATOR_LAYER)) {
            if (os_mode == OS_MODE_WIN) {
                rgb_matrix_set_color_led(indicators.OS_MODE_WIN, triadic_clockwise_rgb());
            } else if (os_mode == OS_MODE_MAC) {
                rgb_matrix_set_color_led(indicators.OS_MODE_MAC, triadic_clockwise_rgb());
            }
        }

        if (os_mode == OS_MODE_DFT) {
            rgb_matrix_set_color_led(indicators.OS_MODE_DFT, triadic_clockwise_rgb());
        }
    }

    rgb_matrix_indicators_keymap(led_min, led_max);
}

#ifdef POWER_DOWN_DISABLE_RGB
void suspend_power_down_user() { rgb_matrix_set_suspend_state(true); }

void suspend_wakeup_init_user() { rgb_matrix_set_suspend_state(false); }
#endif

// end rgb
