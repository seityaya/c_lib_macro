// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

UT_FUNC_GEN(test_arithmetic_base_conv);
UT_FUNC_GEN(test_arithmetic_base_inverse);
UT_FUNC_GEN(test_arithmetic_base_isnum);
UT_FUNC_GEN(test_arithmetic_base_iter);
UT_FUNC_GEN(test_arithmetic_base_logical);
UT_FUNC_GEN(test_arithmetic_base_math_chk);
UT_FUNC_GEN(test_arithmetic_base_math);
UT_FUNC_GEN(test_arithmetic_base_minmax);
UT_FUNC_GEN(test_arithmetic_base_segment);
UT_FUNC_GEN(test_arithmetic_base_unar);
UT_FUNC_GEN(test_arithmetic_base);
UT_FUNC_GEN(test_arithmetic_combinatoric);
UT_FUNC_GEN(test_arithmetic_progresion);
UT_FUNC_GEN(test_arithmetic_round);
UT_FUNC_GEN(test_arithmetic_series);

UT_FUNC_GEN(test_bit_check);
UT_FUNC_GEN(test_bit_cnt);
UT_FUNC_GEN(test_bit_logical);
UT_FUNC_GEN(test_bit_mask);
UT_FUNC_GEN(test_bit_position);
UT_FUNC_GEN(test_bit_shift);

UT_FUNC_GEN(test_argcount);
UT_FUNC_GEN(test_bool);
UT_FUNC_GEN(test_check);
UT_FUNC_GEN(test_concat);
UT_FUNC_GEN(test_debug);
UT_FUNC_GEN(test_endian);
UT_FUNC_GEN(test_flag);
UT_FUNC_GEN(test_rand);
UT_FUNC_GEN(test_sugar);
UT_FUNC_GEN(test_type);
UT_FUNC_GEN(test_unused);

int main(void) {
    unit_test_p MyUnTest = nullptr;

    unit_test_sett_t MyUnSett = {
        .suse = false,
        .stat = true,
    };

    // clang-format off
    unit_test_func_t MyUnFunc[] = {
        {test_arithmetic_base_conv        , 1},
        {test_arithmetic_base_inverse     , 1},
        {test_arithmetic_base_isnum       , 1},
        {test_arithmetic_base_iter        , 1},
        {test_arithmetic_base_logical     , 1},
        {test_arithmetic_base_math_chk    , 1},
        {test_arithmetic_base_math        , 1},
        {test_arithmetic_base_minmax      , 1},
        {test_arithmetic_base_segment     , 1},
        {test_arithmetic_base_unar        , 1},
        {test_arithmetic_base             , 1},
        {test_arithmetic_combinatoric     , 1},
        {test_arithmetic_progresion       , 1},
        {test_arithmetic_round            , 1},
        {test_arithmetic_series           , 1},
        {test_bit_check                   , 1},
        {test_bit_cnt                     , 1},
        {test_bit_logical                 , 1},
        {test_bit_mask                    , 1},
        {test_bit_position                , 1},
        {test_bit_shift                   , 1},
        {test_argcount                    , 1},
        {test_bool                        , 1},
        {test_check                       , 1},
        {test_concat                      , 1},
        {test_debug                       , 0},
        {test_endian                      , 1},
        {test_flag                        , 1},
        {test_rand                        , 1},
        {test_sugar                       , 1},
        {test_type                        , 1},
        {test_unused                      , 1},
        {NULL                             , 0},
    };
    // clang-format on

    unit_test_init(&MyUnTest, MyUnFunc, &MyUnSett);

    unit_test_print(MyUnTest);

    unit_test_start(MyUnTest);

    unit_test_stats(MyUnTest);

    unit_test_free(&MyUnTest);

    return 0;
}
