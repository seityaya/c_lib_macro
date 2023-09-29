// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_bit.h"

UT_FUNC_GEN(test_bit_cnt) {
    UT_GROUP_BEG(cnt) {
        UT_GROUP_BEG(to_byte) {
            UT_ASSERT_NUM_EQ(imax_c(0) , bit_cnt_to_byte(0));
            UT_ASSERT_NUM_EQ(imax_c(8) , bit_cnt_to_byte(1));
            UT_ASSERT_NUM_EQ(imax_c(16), bit_cnt_to_byte(2));
            UT_ASSERT_NUM_EQ(imax_c(32), bit_cnt_to_byte(4));
            UT_ASSERT_NUM_EQ(imax_c(64), bit_cnt_to_byte(8));
        } UT_GROUP_END;
        UT_GROUP_BEG(to_type) {
            UT_ASSERT_NUM_EQ(imax_c( 8), bit_cnt_to_type( i8_c(0)));
            UT_ASSERT_NUM_EQ(imax_c(16), bit_cnt_to_type(i16_c(0)));
            UT_ASSERT_NUM_EQ(imax_c(32), bit_cnt_to_type(i32_c(0)));
            UT_ASSERT_NUM_EQ(imax_c(64), bit_cnt_to_type(i64_c(0)));
            UT_ASSERT_NUM_EQ(imax_c( 8), bit_cnt_to_type( u8_c(0)));
            UT_ASSERT_NUM_EQ(imax_c(16), bit_cnt_to_type(u16_c(0)));
            UT_ASSERT_NUM_EQ(imax_c(32), bit_cnt_to_type(u32_c(0)));
            UT_ASSERT_NUM_EQ(imax_c(64), bit_cnt_to_type(u64_c(0)));
            UT_ASSERT_NUM_EQ(imax_c(32), bit_cnt_to_type(f32_c(0)));
            UT_ASSERT_NUM_EQ(imax_c(64), bit_cnt_to_type(f64_c(0)));
        } UT_GROUP_END;
    }UT_GROUP_END;
}
