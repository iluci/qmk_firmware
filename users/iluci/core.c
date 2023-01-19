/* Copyright 2021 iluci

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
ou should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "core.h"
#include "os/os.h"

// extern const led_map_t led_map[][DRIVER_LED_TOTAL];
extern uint8_t         os_mode;
extern bool            is_one_shot_df_os_mode;

bool enable_side_rgb_matrix = false;
bool enable_idicators       = false;

__attribute__((weak)) bool process_record_user_keymap(uint16_t keycode, keyrecord_t *record) { return true; }
__attribute__((weak)) void rgb_matrix_indicators_keymap(uint8_t led_min, uint8_t led_max) {}

// macros

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool handled = false;
    bool pressed = record->event.pressed;

    switch (keycode) {
        case RGB_TGI:
            if (pressed) {
                enable_idicators = !enable_idicators;
            }
            return false;
        case RGB_TGS:
            if (pressed) {
                enable_side_rgb_matrix = !enable_side_rgb_matrix;
            }
            return false;
        #ifdef RGB_MATRIX_ENABLE
        case RGB_SI:
            if (pressed) {
                rgb_matrix_increase_speed();
            }
            return false;
        case RGB_SD:
            if (pressed) {
                rgb_matrix_decrease_speed();
            }
            return false;
        #endif
    }

    handled = os_macros(keycode, pressed);
    if (handled) {
        return false;
    }

    return process_record_user_keymap(keycode, record);
}

// end macros

// tap dance
#ifdef TAP_DANCE_ENABLE

void                  caps_finished(qk_tap_dance_state_t *state, void *user_data);
void                  caps_reset(qk_tap_dance_state_t *state, void *user_data);
qk_tap_dance_action_t tap_dance_actions[] = {[TDC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, caps_finished, caps_reset)};

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return TD_SINGLE_TAP;
        else
            return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->pressed)
            return TD_DOUBLE_HOLD;
        else
            return TD_DOUBLE_TAP;
    } else if (state->count == 3) {
        if (state->pressed)
            return TD_TRIPLE_HOLD;
        else
            return TD_TRIPLE_TAP;
    } else
        return TD_UNKNOWN;
}

void caps_finished(qk_tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD:
            register_code16(KC_CAPS);
            break;
        case TD_DOUBLE_TAP:
            set_one_shot_df_os_mode();
            break;
        default:
            break;
    }
}

void caps_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD:
            unregister_code16(KC_CAPS);
            break;
        default:
            break;
    }
}

#endif

// end tap dance

// rgb
#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_set_color_led(uint8_t led, RGB color) { rgb_matrix_set_color(led, color.r, color.g, color.b); };

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    int layer = get_highest_layer(layer_state);

    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        led_map_t led = pgm_read_byte(&led_map[layer][i]);

        switch (led) {
            case LED_TRANS: {
                break;
            }
            case LED_SIDE: {
                if (!enable_side_rgb_matrix) {
                    rgb_matrix_set_color(i, RGB_BLACK);
                }
                break;
            }
            case LED_CAPS: {
                if (host_keyboard_led_state().caps_lock) {
                    rgb_matrix_set_color_led(i, RGB_TC);
                }
                break;
            }
            case LED_TC: {
                rgb_matrix_set_color_led(i, RGB_TC);
                break;
            }
            case LED_TCC: {
                rgb_matrix_set_color_led(i, RGB_TCC);
                break;
            }
            case LED_COM: {
                rgb_matrix_set_color_led(i, RGB_C);
                break;
            }
            case LED_B_DFT: {
                if ((enable_idicators && os_mode == OS_MODE_DFT) || is_one_shot_df_os_mode) {
                    rgb_matrix_set_color_led(i, RGB_TC);
                }
                break;
            }
            case LED_B_WIN: {
                if (enable_idicators && os_mode == OS_MODE_WIN) {
                    rgb_matrix_set_color_led(i, RGB_TC);
                }
                break;
            }
            case LED_B_MAC: {
                if (enable_idicators && os_mode == OS_MODE_MAC) {
                    rgb_matrix_set_color_led(i, RGB_TC);
                }
                break;
            }
            case LED_DFT: {
                if (os_mode == OS_MODE_DFT) {
                    rgb_matrix_set_color_led(i, RGB_TC);
                } else {
                    rgb_matrix_set_color_led(i, RGB_TCC);
                }
                break;
            }
            case LED_WIN: {
                if (os_mode == OS_MODE_WIN) {
                    rgb_matrix_set_color_led(i, RGB_TC);
                } else {
                    rgb_matrix_set_color_led(i, RGB_TCC);
                }
                break;
            }
            case LED_MAC: {
                if (os_mode == OS_MODE_MAC) {
                    rgb_matrix_set_color_led(i, RGB_TC);
                } else {
                    rgb_matrix_set_color_led(i, RGB_TCC);
                }
                break;
            }
        }
    }

    rgb_matrix_indicators_keymap(led_min, led_max);
}
#endif

#ifdef POWER_DOWN_DISABLE_RGB
void suspend_power_down_user() { rgb_matrix_set_suspend_state(true); }

void suspend_wakeup_init_user() { rgb_matrix_set_suspend_state(false); }
#endif

// end rgb
