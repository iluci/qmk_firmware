/* Copyright 2023 iluci

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

enum layers { _QWRTY, _CLMK, _LOWER, _RAISE, _ADJST, _NUM };

enum custom_keycodes { KC_QWRTY = NEW_SAFE_RANGE, KC_CLMK, KC_LOWER, KC_RAISE, KC_ADJST };

// clang-format off

#ifdef RGB_MATRIX_ENABLE
#   define LED_MAP_LAYOUT( \
    /*  .-----------------------------------------------------------.                               .-----------------------------------------------------------. */ \
            k00   ,   k01   ,   k02   ,   k03   ,   k04   ,   k05   ,                                   k06   ,   k07   ,   k08   ,   k09   ,   k10   ,   k11   ,    \
    /*  |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------| */ \
            k12   ,   k13   ,   k14   ,   k15   ,   k16   ,   k17   ,                                   k18   ,   k19   ,   k20   ,   k21   ,   k22   ,   k23   ,    \
    /*  |---------+---------+---------+---------+---------+---------|                               |---------+---------+---------+---------+---------+---------| */ \
            k24   ,   k25   ,   k26   ,   k27   ,   k28   ,   k29   ,                                   k30   ,   k31   ,   k32   ,   k33   ,   k34   ,   k35   ,    \
    /*  |---------+---------+---------+---------+---------+---------|---------.           .---------|---------+---------+---------+---------+---------+---------| */ \
            k36   ,   k37   ,   k38   ,   k39   ,   k40   ,   k41   ,                                   k42   ,   k43   ,   k44   ,   k45   ,   k46   ,   k47   ,    \
    /*  '-----------------------------------------------------------/---------/           \---------\-----------------------------------------------------------' */ \
                            k48   ,   k49    ,   k50   ,   k51   ,     k52   ,                 k53   ,      k54   ,   k55   ,   k56   ,   k57                        \
    /*                  '--------------------------------- ------------------'              '---------------------------------------------------'                 */ \
  ) \
  { \
    LED_TRANS, LED_TRANS, LED_TRANS, LED_TRANS, LED_TRANS, LED_TRANS, \
    k48, k36, k24, k12, k00, k01, k13, k25, k37, k49, k50, \
    k38, k26, k14, k02, k03, k15, k27, k39, k51, k52, k40, \
    k28, k16, k04, k05, k17, k29, k41, LED_TRANS, \
    LED_TRANS, LED_TRANS, LED_TRANS, LED_TRANS, LED_TRANS, LED_TRANS, \
    k57, k47, k35, k23, k11, k10, k22, k34, k46, k56, k55, \
    k45, k33, k21, k09, k08, k20, k32, k44, k54, k53, k43, \
    k31, k19, k07, k06, k18, k30, k42, LED_TRANS \
  }
#endif

// clang-format on
