/* Copyright 2023 iluci
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
#define SPLIT_USB_DETECT

#define USB_POLLING_INTERVAL_MS 1

#define RGB_DI_PIN D3

#ifdef RGB_MATRIX_ENABLE
#    define RGBLED_NUM 72
#    define RGB_MATRIX_LED_COUNT RGBLED_NUM
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGB_MATRIX_SPLIT \
        { 36, 36 }
#    define SPLIT_TRANSPORT_MIRROR
#    define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
#    define RGB_DISABLE_WHEN_USB_SUSPENDED true
#endif

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_SPLIT
#    define RGBLED_NUM 72
#    define RGB_SPLIT \
        { 36, 36 }
#    define RGBLIGHT_LIMIT_VAL 120
// #    define RGBLIGHT_SLEEP
// #    define RGBLIGHT_EFFECT_BREATHING
// #    define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #    define RGBLIGHT_EFFECT_SNAKE
// #    define RGBLIGHT_EFFECT_KNIGHT
// #    define RGBLIGHT_EFFECT_CHRISTMAS
// #    define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #    define RGBLIGHT_EFFECT_RGB_TEST
// #    define RGBLIGHT_EFFECT_ALTERNATING
#endif

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE

// #define MOUSE_EXTENDED_REPORT
// // #define POINTING_DEVICE_MOTION_PIN_ACTIVE_LOW
