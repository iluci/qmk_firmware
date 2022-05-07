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

enum layers { _BASE, _FN, _UTIL, _NUM, _RGB };

// clang-format off
//  01, ~      02, 1      03, 2      04, 3      05, 4      06, 5      07, 6      08, 7      09, 8      10, 9      11, 0      12, -_     13, (=+)   14, BackSpc           15, Del
//  16, Tab    17, Q      18, W      19. E      20, R      21, T      22, Y      23, U      24, I      25, O      26, P      27, [{     28, ]}     29, \|                30, Home
//  31, Caps   32, A      33, S      34, D      35, F      36, G      37, H      38, J      39, K      40, L      41, ;:     42, '"                43, Enter             44, End
//  45, Sh_L   46, Z      47, X      48, C      49, V      50, B      51, N      52, M      53, ,<     54, .<     55, /?                56, Sh_R              57, Up     58, Insert
//  59, Ct_L   60, Win_L  62, Alt_L                                   63, SPACE                                              62, FN     63, Ct_R   64, Left   65, Down   66, Right

#   define LED_MAP_LAYOUT( \
    k00,       k01,       k02,       k03,       k04,       k05,       k06,       k07,       k08,       k09,       k10,       k11,       k12,       k13,                  k14, \
    k15,       k16,       k17,       k18,       k19,       k20,       k21,       k22,       k23,       k24,       k25,       k26,       k27,       k28,                  k29, \
    k30,       k31,       k32,       k33,       k34,       k35,       k36,       k37,       k38,       k39,       k40,       k41,                  k42,                  k43, \
    k44,       k45,       k46,       k47,       k48,       k49,       k50,       k51,       k52,       k53,       k54,                  k55,                  k56,       k57, \
    k58,       k59,       k60,                                        k61,                                                   k62,       k63,       k64,       k65,       k66  \
  ) \
  { \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, \
    k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, \
    k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, \
    k60, k61, k62, k63, k64, k65, k66,                \
  }
// clang-format on
