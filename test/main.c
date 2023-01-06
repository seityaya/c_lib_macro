//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2022 Seityagiya Terlekchi. All rights reserved.

#include "unit_test.h"

int main()
{
    unit_test_t MyUnTest = {0};
    unit_test_sett_t MyUnSett = {0};

    unit_test_init(&MyUnTest, unit_test_func, &MyUnSett);

    unit_test_start_all(&MyUnTest);
    unit_test_print_result(&MyUnTest);
    unit_test_print_stats(&MyUnTest);

    return 0;
}
