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
        UT_GROUP_BEG(prev_int) {
            UT_ASSERT_NUM_EQ(u8_c(  1), prev_num(u8_c(2)));
            UT_ASSERT_NUM_EQ(u8_c(  0), prev_num(u8_c(1)));
            UT_ASSERT_NUM_EQ(u8_c(255), prev_num(u8_c(0)));

            UT_ASSERT_NUM_EQ(i8_c(  1), prev_num(i8_c(2)));
            UT_ASSERT_NUM_EQ(i8_c(  0), prev_num(i8_c(1)));
            UT_ASSERT_NUM_EQ(i8_c( -1), prev_num(i8_c(0)));
        } UT_GROUP_END;


        UT_GROUP_BEG(next_int) {
            UT_ASSERT_NUM_EQ(u8_c(0), next_num(u8_c(255)));
            UT_ASSERT_NUM_EQ(u8_c(1), next_num(u8_c(  0)));
            UT_ASSERT_NUM_EQ(u8_c(2), next_num(u8_c(  1)));

            UT_ASSERT_NUM_EQ(i8_c(0), next_num(i8_c(-1)));
            UT_ASSERT_NUM_EQ(i8_c(1), next_num(i8_c( 0)));
            UT_ASSERT_NUM_EQ(i8_c(2), next_num(i8_c( 1)));
        } UT_GROUP_END;


        UT_GROUP_BEG(prev_next_float) {
            UT_ASSERT_FLT_EQ(fmax_c(1.0), next_num(prev_num(1.0)));
            UT_ASSERT_FLT_EQ(fmax_c(1.0), prev_num(next_num(1.0)));
        } UT_GROUP_END;
    } UT_GROUP_END;
}
