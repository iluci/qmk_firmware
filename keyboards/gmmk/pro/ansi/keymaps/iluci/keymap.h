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

// clang-format off

enum custom_keycodes { 
    FOO = SAFE_RANGE, 
    RGB_TG, RGB_EF, RGB_CO, 
    WIN, MAC, DEFAULT, 
    PSGN
};

// 67, Side 01  0, ESC        6, F1          12, F2         18, F3       23, F4       28, F5        34, F6       39, F7       44, F8         50, F9        56, F10        61, F11        66, F12        69, Prt        Rotary(Mute)    68, Side 12
// 70, Side 02  1, ~          7, 1           13, 2          19, 3        24, 4        29, 5         35, 6        40, 7        45, 8          51, 9         57, 0          62, -_         78, (=+)       85, BackSpc    72, Del         71, Side 13
// 73, Side 03  2, Tab        8, Q           14, W          20. E        25, R        30, T         36, Y        41, U        46, I          52, O         58, P          63, [{         89, ]}         93, \|         75, Home        74, Side 14
// 76, Side 04  3, Caps       9, A           15, S          21, D        26, F        31, G         37, H        42, J        47, K          53, L         59, ;:         64, '"                        96, Enter      86, End         77, Side 15
// 80, Side 05  4, Sh_L       10, Z          16, X          22, C        27, V        32, B         38, N        43, M        48, ,<         54, .<        60, /?                        90, Sh_R       94, Up         82, Insert      81, Side 16
// 83, Side 06  5, Ct_L       11,Win_L       17, Alt_L                                33, SPACE                               49, Alt_R      55, FN                       65, Ct_R       95, Left       97, Down       79, Right       84, Side 17
// 87, Side 07                                                                                                                                                                                                                         88, Side 18
// 91, Side 08                                                                                                                                                                                                                         92, Side 19

enum rgb_matrix {
  LED_LS1 = 67, LED_ESC = 0,  LED_F1 = 6,    LED_F2 = 12,   LED_F3 = 18, LED_F4 = 23, LED_F5 = 28,  LED_F6 = 34, LED_F7 = 39, LED_F8 = 44,   LED_F9 = 50,  LED_F10 = 56,  LED_F11 = 61,  LED_F12 = 66,  LED_PRT = 69,                 /* Rotary */    LED_RS1 = 68,
  LED_LS2 = 70, LED_GRV = 1,  LED_1 = 7,     LED_2 = 13,    LED_3 = 19,  LED_4 = 24,  LED_5 = 29,   LED_6 = 35,  LED_7 = 40,  LED_8 = 45,    LED_9 = 51,   LED_0 = 57,    LED_MINS = 62, LED_EQL = 78,  LED_BSPC = 85,                LED_DEL = 72,   LED_RS2 = 71,
  LED_LS3 = 73, LEB_TAB = 2,  LED_Q = 8,     LED_W = 14,    LED_E = 20,  LED_R = 25,  LED_T = 30,   LED_Y = 36,  LED_U = 41,  LED_I = 46,    LED_O = 52,   LED_P = 58,    LED_LBRC = 63, LED_RBRC = 89, LED_BSLS = 93,                LED_HOME = 75,  LED_RS3 = 74,
  LED_LS4 = 76, LED_CAPS = 3, LED_A = 9,     LED_S = 15,    LED_D = 21,  LED_F = 26,  LED_G = 31,   LED_H = 37,  LED_J = 42,  LED_K = 47,    LED_L = 53,   LED_SCLN = 59, LED_QUOT = 64,                LED_ENT = 96,                 LED_END = 86,   LED_RS4 = 77,
  LED_LS5 = 80, LED_LSFT = 4, LED_Z = 10,    LED_X = 16,    LED_C = 22,  LED_V = 27,  LED_B = 32,   LED_N = 38,  LED_M = 43,  LED_COMM = 48, LED_DOT = 54, LED_SLSH = 60,                LED_RSFT = 90,                LED_UP = 94,   LED_INS = 82,   LED_RS5 = 81,
  LED_LS6 = 83, LED_LCTL = 5, LED_LWIN = 11, LED_LALT = 17,                                         LED_SPC = 33,                                          LED_RALT = 49, LED_FN = 55,   LED_RCTL = 65, LED_LEFT = 95, LED_DOWN = 97, LED_RIGHT = 79, LED_RS6 = 84,
  LED_LS7 = 87,                                                                                                                                                                                                                                       LED_RS7 = 88,
  LED_LS8 = 91,                                                                                                                                                                                                                                       LED_RS8 = 92,
};

// clang-format on

enum layers { _BASE, _DFT, _FN1 };

typedef enum { TD_UNKNOWN, TD_SINGLE_TAP, TD_SINGLE_HOLD, TD_DOUBLE_TAP, TD_DOUBLE_HOLD, TD_TRIPLE_TAP, TD_TRIPLE_HOLD } td_state_t;

enum td_codes { TD_CAPS, TD_TAB };
