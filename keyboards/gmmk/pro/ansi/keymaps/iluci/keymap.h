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

#include "core.h"

enum custom_keycodes { KC_CUSTOM = NEW_SAFE_RANGE };

enum layers { _BASE, _FN1, _UTIL };

// clang-format off
//  67, S1     00, ESC    06, F1     12, F2     18, F3     23, F4     28, F5     34, F6     39, F7     44, F8     50, F9     56, F10    61, F11    66, F12    69, Prt                          68, S12
//  70, S2     01, ~      07, 1      13, 2      19, 3      24, 4      29, 5      35, 6      40, 7      45, 8      51, 9      57, 0      62, -_     78, (=+)   85, BackSpc           72, Del    71, S13
//  73, S3     02, Tab    08, Q      14, W      20. E      25, R      30, T      36, Y      41, U      46, I      52, O      58, P      63, [{     89, ]}     93, \|                75, Home   74, S14
//  76, S4     03, Caps   09, A      15, S      21, D      26, F      31, G      37, H      42, J      47, K      53, L      59, ;:     64, '"                96, Enter             86, End    77, S15
//  80, S5     04, Sh_L   10, Z      16, X      22, C      27, V      32, B      38, N      43, M      48, ,<     54, .<     60, /?                90, Sh_R              94, Up     82, Insert 81, S16
//  83, S6     05, Ct_L   11,Win_L   17, Alt_L                                   33, SPACE                                   49, Alt_R  55, FN     65, Ct_R   95, Left   97, Down   79, Right  84, S17
//  87, S7                                                                                                                                                                                     88, S18
//  91, S8                                                                                                                                                                                     92, S19

#   define LED_MAP_LAYOUT( \
    k67,       k00,       k06,       k12,       k18,       k23,       k28,       k34,       k39,       k44,       k50,       k56,       k61,       k66,       k69,                             k68, \
    k70,       k01,       k07,       k13,       k19,       k24,       k29,       k35,       k40,       k45,       k51,       k57,       k62,       k78,       k85,                  k72,       k71, \
    k73,       k02,       k08,       k14,       k20,       k25,       k30,       k36,       k41,       k46,       k52,       k58,       k63,       k89,       k93,                  k75,       k74, \
    k76,       k03,       k09,       k15,       k21,       k26,       k31,       k37,       k42,       k47,       k53,       k59,       k64,                  k96,                  k86,       k77, \
    k80,       k04,       k10,       k16,       k22,       k27,       k32,       k38,       k43,       k48,       k54,       k60,                  k90,                  k94,       k82,       k81, \
    k83,       k05,       k11,       k17,                                        k33,                                        k49,       k55,       k65,       k95,       k97,       k79,       k84, \
    k87,                                                                                                                                                                                       k88, \
    k91,                                                                                                                                                                                       k92  \
  ) \
  { \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, \
    k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, \
    k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, \
    k60, k61, k62, k63, k64, k65, k66, k67, k68, k69, \
    k70, k71, k72, k73, k74, k75, k76, k77, k78, k79, \
    k80, k81, k82, k83, k84, k85, k86, k87, k88, k89, \
    k90, k91, k92, k93, k94, k95, k96, k97,           \
  }
// clang-format on
