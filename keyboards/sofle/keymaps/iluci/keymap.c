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
// SOFLE RGB
#include <stdio.h>
#include QMK_KEYBOARD_H
#include "keymap.h"
#include "core.h"
#include "os/os.h"
#include "keymap.h"

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// [_LAYER] = LAYOUT(
//     /*
//     *   .-----------------------------------------------------------.                               .-----------------------------------------------------------.
//     *   | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |                               | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
//     *   |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
//     *   | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |                               | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
//     *   |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
//     *   | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |                               | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
//     *   |---------+---------+---------+---------+---------+---------|---------.           .---------|---------+---------+---------+---------+---------+---------|
//     *   | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |           | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
//     *   '-----------------------------------------------------------/---------/           \---------\-----------------------------------------------------------'
//     *                   | XXXXXXX | XXXXXXX  | XXXXXXX | XXXXXXX | / XXXXXXX /             \ XXXXXXX \  | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
//     *                   '---------------------------------------------------'               '---------------------------------------------------'
//     */
//     //  .-----------------------------------------------------------.                               .-----------------------------------------------------------.
//           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                 XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
//     //  |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
//           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                 XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
//     //  |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
//           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                 XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
//     //  |---------+---------+---------+---------+---------+---------|---------.           .---------|---------+---------+---------+---------+---------+---------|
//           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,             XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
//     //  '-----------------------------------------------------------/---------/           \---------\-----------------------------------------------------------'
//                           XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX ,   XXXXXXX ,               XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
//     //                  '--------------------------------- ------------------'              '---------------------------------------------------'
// ),
    [_BASE] = LAYOUT(
    /*
    *   .-----------------------------------------------------------.                               .-----------------------------------------------------------.
    *   |   ESC   |    1    |    2    |    3    |    4    |    5    |                               |    6    |    7    |    8    |    9    |   10    |  BSPC   |
    *   |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
    *   |   TAB   |    Q    |    W    |    E    |    R    |    T    |                               |    Y    |    U    |    I    |    O    |    P    |    \    |
    *   |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
    *   |  LCTR   |    A    |    S    |    D    |    F    |    G    |                               |    H    |    J    |    K    |    L    |    ;    |    '    |
    *   |---------+---------+---------+---------+---------+---------|---------.           .---------|---------+---------+---------+---------+---------+---------|
    *   |  LShift |    Z    |    X    |    C    |    V    |    B    |   MUTE  |           | XXXXXXX |    N    |    M    |    ,    |    .    |    /    |  RShift |
    *   '-----------------------------------------------------------/---------/           \---------\-----------------------------------------------------------'
    *                   |  LGui   |  LAlt    | XXXXXXX |  LOWER  | /  SPACE  /             \  ENTER  \  |  RAISE  | XXXXXXX |    [    |    ]    |
    *                   '---------------------------------------------------'               '---------------------------------------------------'
    */
    //  .-----------------------------------------------------------.                               .-----------------------------------------------------------.
          KC_ESC  ,  KC_1   ,  KC_2   ,  KC_3   ,  KC_4   ,  KC_5   ,                                  KC_6   ,  KC_7   ,  KC_8   ,  KC_9   ,  KC_0   , KC_BSPC ,
    //  |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
          KC_TAB  ,  KC_Q   ,  KC_W   ,  KC_E   ,  KC_R   ,  KC_T   ,                                  KC_Y   ,  KC_U   ,  KC_I   ,  KC_O   ,  KC_P   , KC_BSLS ,
    //  |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
          KC_LCTL ,  KC_A   ,  KC_S   ,  KC_D   ,  KC_F   ,  KC_G   ,                                  KC_H   ,  KC_J   ,  KC_K   ,  KC_L   , KC_SCLN , KC_QUOT ,
    //  |---------+---------+---------+---------+---------+---------|---------.           .---------|---------+---------+---------+---------+---------+---------|
          KC_LSFT ,  KC_Z   ,  KC_X   ,  KC_C   ,  KC_V   ,  KC_B   , KC_MUTE ,             XXXXXXX ,  KC_N   ,  KC_M   , KC_COMM ,  KC_DOT , KC_SLSH , KC_RSFT ,
    //  '-----------------------------------------------------------/---------/           \---------\-----------------------------------------------------------'
                          KC_LGUI , KC_LALT  , XXXXXXX , MO(_LOWER),  KC_SPC ,               KC_ENT  , MO(_RAISE) , XXXXXXX , KC_LBRC , KC_RBRC
    //                  '--------------------------------- ------------------'              '---------------------------------------------------'
    ),
    [_LOWER] = LAYOUT(
    /*
    *   .-----------------------------------------------------------.                               .-----------------------------------------------------------.
    *   |    `    |   F1    |   F2    |   F3    |   F4    |   F5    |                               |   F6    |   F7    |   F8    |   F9    |  F10    |   DEL   |
    *   |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
    *   | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |                               | XXXXXXX | XXXXXXX |   UP    |   F11   |   F12   | XXXXXXX |
    *   |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
    *   | _______ | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |                               | XXXXXXX |  LEFT   |  DOWN   |  RIGHT  | XXXXXXX | XXXXXXX |
    *   |---------+---------+---------+---------+---------+---------|---------.           .---------|---------+---------+---------+---------+---------+---------|
    *   | _______ | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |           | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
    *   '-----------------------------------------------------------/---------/           \---------\-----------------------------------------------------------'
    *                   | _______ | _______  | XXXXXXX | _______ | / _______ /             \ _______ \  | _______ | XXXXXXX | XXXXXXX | XXXXXXX |
    *                   '---------------------------------------------------'               '---------------------------------------------------'
    */
    //  .-----------------------------------------------------------.                               .-----------------------------------------------------------.
          KC_GRV  ,  KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,                                  KC_F6  ,  KC_F7  ,  KC_F8  ,  KC_F9  , KC_F10  , KC_DEL  ,
    //  |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
          XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                 KC_MINS  , KC_EQL ,  KC_UP  , KC_F11  , KC_F12  , KC_HOME ,
    //  |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
          _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                 XXXXXXX , KC_LEFT , KC_DOWN , KC_RIGHT, XXXXXXX ,  KC_END ,
    //  |---------+---------+---------+---------+---------+---------|---------.           .---------|---------+---------+---------+---------+---------+---------|
          _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,             XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,KC_INSERT,
    //  '-----------------------------------------------------------/---------/           \---------\-----------------------------------------------------------'
                          _______ , _______  , XXXXXXX , _______ ,   _______ ,               _______ ,    _______ , XXXXXXX , XXXXXXX , XXXXXXX
    //                  '--------------------------------- ------------------'              '---------------------------------------------------'
    ),
    [_RAISE] = LAYOUT(
    /*
    *   .-----------------------------------------------------------.                               .-----------------------------------------------------------.
    *   | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |                               | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
    *   |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
    *   | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |                               | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
    *   |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
    *   | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |                               | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
    *   |---------+---------+---------+---------+---------+---------|---------.           .---------|---------+---------+---------+---------+---------+---------|
    *   | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |           | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
    *   '-----------------------------------------------------------/---------/           \---------\-----------------------------------------------------------'
    *                   | XXXXXXX | XXXXXXX  | XXXXXXX | XXXXXXX | / XXXXXXX /             \ XXXXXXX \  | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
    *                   '---------------------------------------------------'               '---------------------------------------------------'
    */
    //  .-----------------------------------------------------------.                               .-----------------------------------------------------------.
          XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                 XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    //  |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
          XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                 XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    //  |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
          XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                 XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    //  |---------+---------+---------+---------+---------+---------|---------.           .---------|---------+---------+---------+---------+---------+---------|
          XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,             XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    //  '-----------------------------------------------------------/---------/           \---------\-----------------------------------------------------------'
                          XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX ,   XXXXXXX ,               XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
    //                  '--------------------------------- ------------------'              '---------------------------------------------------'
    ),
    [_UTIL] = LAYOUT(
    /*
    *   .-----------------------------------------------------------.                               .-----------------------------------------------------------.
    *   | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |                               | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
    *   |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
    *   | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |                               | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
    *   |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
    *   | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |                               | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
    *   |---------+---------+---------+---------+---------+---------|---------.           .---------|---------+---------+---------+---------+---------+---------|
    *   | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |           | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
    *   '-----------------------------------------------------------/---------/           \---------\-----------------------------------------------------------'
    *                   | XXXXXXX | XXXXXXX  | XXXXXXX | XXXXXXX | / XXXXXXX /             \ XXXXXXX \  | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
    *                   '---------------------------------------------------'               '---------------------------------------------------'
    */
    //  .-----------------------------------------------------------.                               .-----------------------------------------------------------.
          XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                 XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    //  |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
          XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                 XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    //  |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
          XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                 XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    //  |---------+---------+---------+---------+---------+---------|---------.           .---------|---------+---------+---------+---------+---------+---------|
          XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,             XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    //  '-----------------------------------------------------------/---------/           \---------\-----------------------------------------------------------'
                          XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX ,   XXXXXXX ,               XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
    //                  '--------------------------------- ------------------'              '---------------------------------------------------'
    )
};

#ifdef RGB_MATRIX_ENABLE
#undef _______
#define _______ LED_TRANS

const led_map_t PROGMEM led_map[][RGBLED_NUM] = {
// [_LAYER] = LED_MAP_LAYOUT(
//     /*
//     *   .-----------------------------------------------------------.                               .-----------------------------------------------------------.
//     *   |   ESC   |    1    |    2    |    3    |    4    |    5    |                               |    6    |    7    |    8    |    9    |   10    |  BSPC   |
//     *   |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
//     *   |   TAB   |    Q    |    W    |    E    |    R    |    T    |                               |    Y    |    U    |    I    |    O    |    P    |    \    |
//     *   |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
//     *   |  LCTR   |    A    |    S    |    D    |    F    |    G    |                               |    H    |    J    |    K    |    L    |    ;    |    '    |
//     *   |---------+---------+---------+---------+---------+---------|---------.           .---------|---------+---------+---------+---------+---------+---------|
//     *   |  LShift |    Z    |    X    |    C    |    V    |    B    |         |           |         |    N    |    M    |    ,    |    .    |    /    |  RShift |
//     *   '-----------------------------------------------------------/---------/           \---------\-----------------------------------------------------------'
//     *                   |  LGui   |  LAlt    | XXXXXXX |  LOWER  | /  SPACE  /             \  ENTER  \  |  RAISE  | XXXXXXX |    [    |    ]    |
//     *                   '---------------------------------------------------'               '---------------------------------------------------'
//     */
//     //  .-----------------------------------------------------------.                               .-----------------------------------------------------------.
//           _______ , _______ , _______ , _______ , _______ , _______ ,                                 _______ , _______ , _______ , _______ , _______ , _______ ,
//     //  |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
//           _______ , _______ , _______ , _______ , _______ , _______ ,                                 _______ , _______ , _______ , _______ , _______ , _______ ,
//     //  |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
//           _______ , _______ , _______ , _______ , _______ , _______ ,                                 _______ , _______ , _______ , _______ , _______ , _______ ,
//     //  |---------+---------+---------+---------+---------+---------|---------.           .---------|---------+---------+---------+---------+---------+---------|
//           _______ , _______ , _______ , _______ , _______ , _______ ,                                 _______ , _______ , _______ , _______ , _______ , _______ ,
//     //  '-----------------------------------------------------------/---------/           \---------\-----------------------------------------------------------'
//                           _______ , _______  , _______ , _______ ,   _______ ,               _______ ,    _______ , _______ , _______ , _______
//     //                  '--------------------------------- ------------------'              '---------------------------------------------------'
// ),
[_BASE] = LED_MAP_LAYOUT(
    /*
    *   .-----------------------------------------------------------.                               .-----------------------------------------------------------.
    *   |   ESC   |    1    |    2    |    3    |    4    |    5    |                               |    6    |    7    |    8    |    9    |   10    |  BSPC   |
    *   |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
    *   |   TAB   |    Q    |    W    |    E    |    R    |    T    |                               |    Y    |    U    |    I    |    O    |    P    |    \    |
    *   |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
    *   |  LCTR   |    A    |    S    |    D    |    F    |    G    |                               |    H    |    J    |    K    |    L    |    ;    |    '    |
    *   |---------+---------+---------+---------+---------+---------|---------.           .---------|---------+---------+---------+---------+---------+---------|
    *   |  LShift |    Z    |    X    |    C    |    V    |    B    |         |           |         |    N    |    M    |    ,    |    .    |    /    |  RShift |
    *   '-----------------------------------------------------------/---------/           \---------\-----------------------------------------------------------'
    *                   |  LGui   |  LAlt    | XXXXXXX |  LOWER  | /  SPACE  /             \  ENTER  \  |  RAISE  | XXXXXXX |    [    |    ]    |
    *                   '---------------------------------------------------'               '---------------------------------------------------'
    */
    //  .-----------------------------------------------------------.                               .-----------------------------------------------------------.
          _______ , _______ , _______ , _______ , _______ , _______ ,                                 _______ , _______ , _______ , _______ , _______ , _______ ,
    //  |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
          _______ , _______ , _______ , _______ , _______ , _______ ,                                 _______ , _______ , _______ , _______ , _______ , _______ ,
    //  |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------|
          _______ , _______ , _______ , _______ , _______ , _______ ,                                 _______ , _______ , _______ , _______ , _______ , _______ ,
    //  |---------+---------+---------+---------+---------+---------|---------.           .---------|---------+---------+---------+---------+---------+---------|
          _______ , _______ , _______ , _______ , _______ , _______ ,                                 _______ , _______ , _______ , _______ , _______ , _______ ,
    //  '-----------------------------------------------------------/---------/           \---------\-----------------------------------------------------------'
                          _______ , _______  , _______ , _______ ,   _______ ,               _______ ,    _______ , _______ , _______ , _______
    //                  '--------------------------------- ------------------'              '---------------------------------------------------'
),
};

#undef _______
#define _______ KC_TRNS
#endif

// clang-format on

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00};

    oled_write_P(qmk_logo, false);
}

static void print_status(void) {
    led_t led_state = host_keyboard_led_state();

    oled_write_ln_P(PSTR("CPSLK"), false);
    oled_write_ln_P(led_state.caps_lock ? PSTR("On") : PSTR("Off"), false);

    oled_write_ln_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case _UTIL:
            oled_write_ln_P(PSTR("Util"), false);
            break;

        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status();
    } else {
        render_logo();
    }
    return false;
}

#endif

/*
#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
    {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, hsv}
#define SET_UNDERGLOW(hsv) \
    {1, 6, hsv}, \
    {35+1, 6,hsv}
#define SET_NUMPAD(hsv)     \
    {35+15, 5, hsv},\
      {35+22, 3, hsv},\
      {35+27, 3, hsv}
#define SET_NUMROW(hsv) \
    {10, 2, hsv}, \
        {20, 2, hsv}, \
        {30, 2, hsv}, \
      {35+ 10, 2, hsv}, \
      {35+ 20, 2, hsv}, \
      {35+ 30, 2, hsv}
#define SET_INNER_COL(hsv)	\
    {33, 4, hsv}, \
      {35+ 33, 4, hsv}

#define SET_OUTER_COL(hsv) \
    {7, 4, hsv}, \
      {35+ 7, 4, hsv}
#define SET_THUMB_CLUSTER(hsv) 	\
    {25, 2, hsv}, \
      {35+ 25, 2, hsv}
#define SET_LAYER_ID(hsv) 	\
    {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
        {1, 6, hsv}, \
    {35+1, 6, hsv}, \
        {7, 4, hsv}, \
      {35+ 7, 4, hsv}, \
        {25, 2, hsv}, \
      {35+ 25, 2, hsv}




*/

// #ifdef RGBLIGHT_ENABLE
// char layer_state_str[70];
// // Now define the array of layers. Later layers take precedence

// // QWERTY,
// // Light on inner column and underglow
// const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
//   SET_LAYER_ID(HSV_RED)

// );
// const rgblight_segment_t PROGMEM layer_colemakdh_lights[] = RGBLIGHT_LAYER_SEGMENTS(
//   SET_LAYER_ID(HSV_PINK)
// );

// // _NUM,
// // Light on outer column and underglow
// const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
// 	SET_LAYER_ID(HSV_TEAL)

// );
// // _SYMBOL,
// // Light on inner column and underglow
// const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
// 	SET_LAYER_ID(HSV_BLUE)

//     );
// // _COMMAND,
// // Light on inner column and underglow
// const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
//   SET_LAYER_ID(HSV_PURPLE)
// );

// //_NUMPAD
// const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
// 	SET_INDICATORS(HSV_ORANGE),
//     SET_UNDERGLOW(HSV_ORANGE),
// 	SET_NUMPAD(HSV_BLUE),
//     {7, 4, HSV_ORANGE},
//     {25, 2, HSV_ORANGE},
//     {35+6, 4, HSV_ORANGE},
//     {35+25, 2, HSV_ORANGE}
//     );
// // _SWITCHER   // light up top row
// const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(
// 	SET_LAYER_ID(HSV_GREEN),
// 	SET_NUMROW(HSV_GREEN)
// );

// const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(

//     layer_qwerty_lights,
// 	layer_num_lights,// overrides layer 1
// 	layer_symbol_lights,
//     layer_command_lights,
// 	layer_numpad_lights,
// 	layer_switcher_lights,  // Overrides other layers
// 	layer_colemakdh_lights
// );

// layer_state_t layer_state_set_user(layer_state_t state) {
// 	rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_QWERTY));
// 	rgblight_set_layer_state(7, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_COLEMAKDH));

// 	rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
// 	rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
// 	rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
// 	rgblight_set_layer_state(4, layer_state_cmp(state, _NUMPAD));
// 	rgblight_set_layer_state(5, layer_state_cmp(state, _SWITCH));
//     return state;
// }
// void keyboard_post_init_user(void) {
//     // Enable the LED layers
//     rgblight_layers = my_rgb_layers;

// 	rgblight_mode(10);// haven't found a way to set this in a more useful way

// }
// #endif

// // bool process_record_user(uint16_t keycode, keyrecord_t *record) {
// //     switch (keycode) {
// //         case KC_QWERTY:
// //             if (record->event.pressed) {
// //                 set_single_persistent_default_layer(_QWERTY);
// //             }
// //             return false;
// //         case KC_COLEMAK:
// //             if (record->event.pressed) {
// //                 set_single_persistent_default_layer(_COLEMAK);
// //             }
// //             return false;
// //         case KC_COLEMAKDH:
// //             if (record->event.pressed) {
// //                 set_single_persistent_default_layer(_COLEMAKDH);
// //             }
// //             return false;
// //         case KC_LOWER:
// //             if (record->event.pressed) {
// //                 layer_on(_LOWER);
// //                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
// //             } else {
// //                 layer_off(_LOWER);
// //                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
// //             }
// //             return false;
// //         case KC_RAISE:
// //             if (record->event.pressed) {
// //                 layer_on(_RAISE);
// //                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
// //             } else {
// //                 layer_off(_RAISE);
// //                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
// //             }
// //             return false;
// //         case KC_ADJUST:
// //             if (record->event.pressed) {
// //                 layer_on(_ADJUST);
// //             } else {
// //                 layer_off(_ADJUST);
// //             }
// //             return false;
// //         case KC_D_MUTE:
// //             if (record->event.pressed) {
// //                 register_mods(mod_config(MOD_MEH));
// //                 register_code(KC_UP);
// //             } else {
// //                 unregister_mods(mod_config(MOD_MEH));
// //                 unregister_code(KC_UP);
// //             }
// //     }
// //     return true;
// // }

// #ifdef ENCODER_ENABLE

// bool encoder_update_user(uint8_t index, bool clockwise) {
//     if (index == 0) {
//         if (clockwise) {
//             tap_code(KC_VOLU);
//         } else {
//             tap_code(KC_VOLD);
//         }
// 		} else if (index == 1) {
// 			switch (get_highest_layer(layer_state)) {
// 				case _COLEMAK:
// 				case _QWERTY:
// 				case _COLEMAKDH:
// 					if (clockwise) {
// 						tap_code(KC_PGDN);
// 					} else {
// 						tap_code(KC_PGUP);
// 					}
// 				break;
// 			case _RAISE:
// 			case _LOWER:
// 					if (clockwise) {
// 						tap_code(KC_DOWN);
// 					} else {
// 						tap_code(KC_UP);
// 					}
// 				break;
// 			default:
// 					if (clockwise) {
// 						tap_code(KC_WH_D);
// 					} else {
// 						tap_code(KC_WH_U);
// 					}
// 				break;
// 		}
//     }
//     return true;
// }

// #endif
