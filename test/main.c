//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_debug.h"

int main() {
    unit_test_t MyUnTest = {0};
    unit_test_sett_t MyUnSett = { .map = false,
                                  .suse = false,
                                  .stat = true,
                                  .fold = false
                                };

    unit_test_func_t MyUnFunc[] = { {0},
                                    {test_arithmetic, 1},
                                    {test_bit,        1},
                                    {test_bool,       1},
                                    {test_debug,      0},
                                    {test_sugar,      1},
                                    {0}
                                  };

    unit_test_init(&MyUnTest, MyUnFunc, &MyUnSett);

    unit_test_start(&MyUnTest);
    unit_test_stats(&MyUnTest);

    return 0;
}
