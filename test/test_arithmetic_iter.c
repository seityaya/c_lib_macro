//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_iter) {
    UT_GROUP_BEG(iter) {
        UT_GROUP_BEG(prev_num) {
            UT_ASSERT_NUM_EQ(u8_c(   1), num_prev(u8_c(   2)));
            UT_ASSERT_NUM_EQ(u8_c(   0), num_prev(u8_c(   1)));
            UT_ASSERT_NUM_EQ(u8_c(   0), num_prev(u8_c(   0)));

            UT_ASSERT_NUM_EQ(i8_c(   1), num_prev(i8_c(   2)));
            UT_ASSERT_NUM_EQ(i8_c(   0), num_prev(i8_c(   1)));
            UT_ASSERT_NUM_EQ(i8_c(  -1), num_prev(i8_c(   0)));
            UT_ASSERT_NUM_EQ(i8_c(-128), num_prev(i8_c(-128)));
            UT_ASSERT_NUM_EQ(i8_c( 126), num_prev(i8_c( 127)));
        } UT_GROUP_END;


        UT_GROUP_BEG(next_num) {
            UT_ASSERT_NUM_EQ(u8_c( 255), num_next(u8_c( 255)));
            UT_ASSERT_NUM_EQ(u8_c(   1), num_next(u8_c(   0)));
            UT_ASSERT_NUM_EQ(u8_c(   2), num_next(u8_c(   1)));

            UT_ASSERT_NUM_EQ(i8_c(   0), num_next(i8_c(  -1)));
            UT_ASSERT_NUM_EQ(i8_c(   1), num_next(i8_c(   0)));
            UT_ASSERT_NUM_EQ(i8_c(   2), num_next(i8_c(   1)));
            UT_ASSERT_NUM_EQ(i8_c(-127), num_next(i8_c(-128)));
            UT_ASSERT_NUM_EQ(i8_c( 127), num_next(i8_c( 127)));
        } UT_GROUP_END;

        UT_GROUP_BEG(num_after) {
            UT_ASSERT_NUM_EQ(u8_c(   0), num_after(u8_c(   0), u8_c(    0)));
            UT_ASSERT_NUM_EQ(u8_c(   1), num_after(u8_c(   1), u8_c(    1)));

            UT_ASSERT_NUM_EQ(i8_c(   1), num_after(i8_c(   0), i8_c(    3)));
            UT_ASSERT_NUM_EQ(i8_c(   2), num_after(i8_c(   1), i8_c(    3)));
            UT_ASSERT_NUM_EQ(i8_c(   3), num_after(i8_c(   2), i8_c(    3)));
            UT_ASSERT_NUM_EQ(i8_c(   3), num_after(i8_c(   3), i8_c(    3)));

            UT_ASSERT_NUM_EQ(i8_c(  -1), num_after(i8_c(   0), i8_c(   -3)));
            UT_ASSERT_NUM_EQ(i8_c(  -2), num_after(i8_c(  -1), i8_c(   -3)));
            UT_ASSERT_NUM_EQ(i8_c(  -3), num_after(i8_c(  -2), i8_c(   -3)));
            UT_ASSERT_NUM_EQ(i8_c(  -3), num_after(i8_c(  -3), i8_c(   -3)));
        } UT_GROUP_END;

        UT_GROUP_BEG(prev_next_float) {
            UT_ASSERT_FLT_EQ(fmax_c(1.0), num_next(num_prev(fmax_c(1.0L))));
            UT_ASSERT_FLT_EQ(fmax_c(1.0), num_prev(num_next(fmax_c(1.0L))));
        } UT_GROUP_END;
    } UT_GROUP_END;
}
