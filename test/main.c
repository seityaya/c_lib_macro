//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"

int main(void) {
    unit_test_t MyUnTest = {0};

    unit_test_sett_t MyUnSett = { .map =  false,
                                  .suse = false,
                                  .stat = true,
                                  .fold = false
                                };

    unit_test_func_t MyUnFunc[] = { {0},
                                    {(void*)test_arithmetic_constant,      1},
                                    {(void*)test_arithmetic_unar,          1},
                                    {(void*)test_arithmetic_assignment,    1},
                                    {(void*)test_arithmetic_segment,       1},
                                    {(void*)test_arithmetic_decomposition, 1},
                                    {(void*)test_arithmetic_iter,          1},
                                    {(void*)test_arithmetic_math,          1},
                                    {(void*)test_arithmetic_math_chk,      1},
                                    {(void*)test_arithmetic_compare,       1},
                                    {(void*)test_arithmetic_parity,        1},
                                    {(void*)test_arithmetic_round,         1},
                                    {(void*)test_arithmetic_minmax,        1},
                                    {(void*)test_arithmetic_progresion,    1},
                                    {(void*)test_arithmetic_series,        1},
                                    {(void*)test_arithmetic_combinatoric,  1},
                                    {(void*)test_bit,                      1},
                                    {(void*)test_bool,                     1},
                                    {(void*)test_debug,                    0},
                                    {(void*)test_rand,                     1},
                                    {(void*)test_sugar,                    0},
                                    {0}
                                  };

    unit_test_init(&MyUnTest, MyUnFunc, &MyUnSett);

    unit_test_start(&MyUnTest);

    unit_test_stats(&MyUnTest);

    return 0;
}
