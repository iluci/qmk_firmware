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

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define CUSTOM_FONT
#define CUSTOM_LAYER_READ // if you remove this it causes issues - needs better guarding
// #define SPLIT_LAYER_STATE_ENABLE

#define RGB_DI_PIN D3

#ifdef RGB_MATRIX_ENABLE
#    define RGBLED_NUM 72
#    define RGB_MATRIX_LED_COUNT RGBLED_NUM
// #    define POWER_DOWN_DISABLE_RGB
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGB_MATRIX_SPLIT \
        { 36, 36 }
#    define SPLIT_TRANSPORT_MIRROR
#endif

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_SPLIT
#    define RGBLED_NUM 70
#    define RGB_SPLIT \
        { 36, 36 }
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_SLEEP
// #define RGBLIGHT_EFFECT_BREATHING
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #define RGBLIGHT_EFFECT_SNAKE
// #define RGBLIGHT_EFFECT_KNIGHT
// #define RGBLIGHT_EFFECT_CHRISTMAS
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #define RGBLIGHT_EFFECT_RGB_TEST
// #define RGBLIGHT_EFFECT_ALTERNATING
// #define RGBLIGHT_EFFECT_TWINKLE
#endif

// //#define USE_MATRIX_I2C

// #define TAPPING_FORCE_HOLD
// #ifdef TAPPING_TERM
//     #undef TAPPING_TERM
//     #define TAPPING_TERM 200
// #endif
// #define ENCODER_DIRECTION_FLIP

// #define MOUSE_EXTENDED_REPORT
// // #define POINTING_DEVICE_MOTION_PIN_ACTIVE_LOW
