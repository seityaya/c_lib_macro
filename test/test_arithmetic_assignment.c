//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_arithmetic.h"

#include "malloc.h"

UT_FUNC_GEN(test_arithmetic_assignment) {
    UT_GROUP_BEG(assignment_raw) {
        int x = 1;
        double y = 2.5;
        UT_ASSERT_FLT_EQ(2.5, y);

        UT_ASSERT_NUM_EQ(  1, x);
        as(x, (int)(y));
        UT_ASSERT_NUM_EQ(  2, x);
    } UT_GROUP_END;


    UT_GROUP_BEG(assignment) {
        is8_t x = 0;
        UT_ASSERT_NUM_EQ(i8_c(0), x);
        as(x, i8_c(1));
        UT_ASSERT_NUM_EQ(i8_c(1), x);

        fmax_t y = 1.0;
        UT_ASSERT_FLT_EQ(fmax_c(1.0), y);
        as(y, fmax_c(2));
        UT_ASSERT_FLT_EQ(fmax_c(2.0), y);
    } UT_GROUP_END;


    UT_GROUP_BEG(swap) {
        is8_t x = 0;
        is8_t y = 1;

        UT_ASSERT_NUM_EQ(i8_c(0), x);
        UT_ASSERT_NUM_EQ(i8_c(1), y);
        swap(x, y);
        UT_ASSERT_NUM_EQ(i8_c(1), x);
        UT_ASSERT_NUM_EQ(i8_c(0), y);
    } UT_GROUP_END;
}
