// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_base_conv) {
    UT_GROUP_BEG(convert_sign) {
        UT_GROUP_BEG(positiv) {
            UT_GROUP_BEG(is_to_pos) {
                UT_ASSERT_BOOL_TR(is_to_pos(i8_c(-1)));
                UT_ASSERT_BOOL_TR(is_to_pos(i8_c(0)));
                UT_ASSERT_BOOL_TR(is_to_pos(i8_c(1)));

                UT_ASSERT_BOOL_TR(is_to_pos(i8_c(-127)));
                UT_ASSERT_BOOL_FL(is_to_pos(i8_c(-128)));

                UT_ASSERT_BOOL_TR(is_to_pos(u8_c(-1)));
                UT_ASSERT_BOOL_TR(is_to_pos(u8_c(0)));
                UT_ASSERT_BOOL_TR(is_to_pos(u8_c(1)));

                UT_ASSERT_BOOL_TR(is_to_pos(f32_c(1.1)));
                UT_ASSERT_BOOL_TR(is_to_pos(f32_c(-1.1)));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(to_pos) {
                UT_ASSERT_NUM_EQ(i8_c(1), to_pos(i8_c(-1)));
                UT_ASSERT_NUM_EQ(i8_c(0), to_pos(i8_c(0)));
                UT_ASSERT_NUM_EQ(i8_c(1), to_pos(i8_c(1)));

                UT_ASSERT_NUM_EQ(i8_c(127), to_pos(i8_c(-127)));
                UT_ASSERT_NUM_EQ(i8_c(-128), to_pos(i8_c(-128)));

                UT_ASSERT_NUM_EQ(u8_c(255), to_pos(u8_c(-1)));
                UT_ASSERT_NUM_EQ(u8_c(0), to_pos(u8_c(0)));
                UT_ASSERT_NUM_EQ(u8_c(1), to_pos(u8_c(1)));

                UT_ASSERT_FLT_EQ(f32_c(1.1), to_pos(f32_c(1.1)));
                UT_ASSERT_FLT_EQ(f32_c(1.1), to_pos(f32_c(-1.1)));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(to_pos_chk) {
                is8_t res_i = 0;
                f32_t res_f = 0;
                UT_ASSERT_BOOL_TR(to_pos_chk(res_i, i8_c(-1)));
                UT_ASSERT_NUM_EQ(res_i, i8_c(1));

                UT_ASSERT_BOOL_TR(to_pos_chk(res_i, i8_c(0)));
                UT_ASSERT_NUM_EQ(res_i, i8_c(0));

                UT_ASSERT_BOOL_TR(to_pos_chk(res_i, i8_c(1)));
                UT_ASSERT_NUM_EQ(res_i, i8_c(1));

                res_i = 33;
                UT_ASSERT_BOOL_TR(to_pos_chk(res_i, i8_c(-127)));
                UT_ASSERT_NUM_EQ(res_i, i8_c(127));

                res_i = 33;
                UT_ASSERT_BOOL_FL(to_pos_chk(res_i, i8_c(-128)));
                UT_ASSERT_NUM_EQ(res_i, i8_c(33));

                UT_ASSERT_BOOL_TR(to_pos_chk(res_f, f32_c(1.1)));
                UT_ASSERT_FLT_EQ(res_f, f32_c(1.1));

                UT_ASSERT_BOOL_TR(to_pos_chk(res_f, f32_c(-1.1)));
                UT_ASSERT_FLT_EQ(res_f, f32_c(1.1));
            }
            UT_GROUP_END;
        }
        UT_GROUP_END;

        UT_GROUP_BEG(negativ) {
            UT_GROUP_BEG(is_to_neg) {
                UT_ASSERT_BOOL_TR(is_to_neg(i8_c(-1)));
                UT_ASSERT_BOOL_TR(is_to_neg(i8_c(0)));
                UT_ASSERT_BOOL_TR(is_to_neg(i8_c(1)));

                UT_ASSERT_BOOL_TR(is_to_neg(i8_c(-127)));
                UT_ASSERT_BOOL_TR(is_to_neg(i8_c(-128)));

                UT_ASSERT_BOOL_FL(is_to_neg(u8_c(-1)));
                UT_ASSERT_BOOL_FL(is_to_neg(u8_c(0)));
                UT_ASSERT_BOOL_FL(is_to_neg(u8_c(1)));

                UT_ASSERT_BOOL_TR(is_to_neg(f32_c(1.1)));
                UT_ASSERT_BOOL_TR(is_to_neg(f32_c(-1.1)));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(to_neg) {
                UT_ASSERT_NUM_EQ(i8_c(-1), to_neg(i8_c(-1)));
                UT_ASSERT_NUM_EQ(i8_c(0), to_neg(i8_c(0)));
                UT_ASSERT_NUM_EQ(i8_c(-1), to_neg(i8_c(1)));

                UT_ASSERT_NUM_EQ(i8_c(-127), to_neg(i8_c(-127)));
                UT_ASSERT_NUM_EQ(i8_c(-128), to_neg(i8_c(-128)));

                UT_ASSERT_NUM_EQ(u8_c(255), to_neg(u8_c(-1)));
                UT_ASSERT_NUM_EQ(u8_c(0), to_neg(u8_c(0)));
                UT_ASSERT_NUM_EQ(u8_c(1), to_neg(u8_c(1)));

                UT_ASSERT_FLT_EQ(f32_c(-1.1), to_neg(f32_c(1.1)));
                UT_ASSERT_FLT_EQ(f32_c(-1.1), to_neg(f32_c(-1.1)));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(to_neg_chk) {
                is8_t res_i = 0;
                f32_t res_f = 0;
                UT_ASSERT_BOOL_TR(to_neg_chk(res_i, i8_c(-1)));
                UT_ASSERT_NUM_EQ(res_i, i8_c(-1));

                UT_ASSERT_BOOL_TR(to_neg_chk(res_i, i8_c(0)));
                UT_ASSERT_NUM_EQ(res_i, i8_c(0));

                UT_ASSERT_BOOL_TR(to_neg_chk(res_i, i8_c(1)));
                UT_ASSERT_NUM_EQ(res_i, i8_c(-1));

                res_i = 33;
                UT_ASSERT_BOOL_TR(to_neg_chk(res_i, i8_c(-127)));
                UT_ASSERT_NUM_EQ(res_i, i8_c(-127));

                res_i = 33;
                UT_ASSERT_BOOL_TR(to_neg_chk(res_i, i8_c(-128)));
                UT_ASSERT_NUM_EQ(res_i, i8_c(-128));

                UT_ASSERT_BOOL_TR(to_neg_chk(res_f, f32_c(1.1)));
                UT_ASSERT_FLT_EQ(res_f, f32_c(-1.1));

                UT_ASSERT_BOOL_TR(to_neg_chk(res_f, f32_c(-1.1)));
                UT_ASSERT_FLT_EQ(res_f, f32_c(-1.1));
            }
            UT_GROUP_END;
        }
        UT_GROUP_END;
    }
    UT_GROUP_END;
}
