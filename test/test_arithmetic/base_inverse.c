// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_base_inverse) {
    UT_GROUP_BEG(inverse_element) {
        UT_GROUP_BEG(additive) {
            UT_GROUP_BEG(is_inv_add) {
                UT_ASSERT_BOOL_TR(is_inv_add( i8_c(  -1)));
                UT_ASSERT_BOOL_TR(is_inv_add( i8_c(   0)));
                UT_ASSERT_BOOL_TR(is_inv_add( i8_c(   1)));

                UT_ASSERT_BOOL_TR(is_inv_add( i8_c(-127)));
                UT_ASSERT_BOOL_FL(is_inv_add( i8_c(-128)));

                UT_ASSERT_BOOL_FL(is_inv_add( u8_c(  -1)));
                UT_ASSERT_BOOL_TR(is_inv_add( u8_c(   0)));
                UT_ASSERT_BOOL_FL(is_inv_add( u8_c(   1)));

                UT_ASSERT_BOOL_FL(is_inv_add( u8_c(-127)));
                UT_ASSERT_BOOL_FL(is_inv_add( u8_c(-128)));

                UT_ASSERT_BOOL_TR(is_inv_add(f32_c( 1.1)));
                UT_ASSERT_BOOL_TR(is_inv_add(f32_c(-1.1)));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(inv_add) {
                UT_ASSERT_NUM_EQ( i8_c(   1), inv_add( i8_c(  -1)));
                UT_ASSERT_NUM_EQ( i8_c(   0), inv_add( i8_c(   0)));
                UT_ASSERT_NUM_EQ( i8_c(  -1), inv_add( i8_c(   1)));

                UT_ASSERT_NUM_EQ( i8_c( 127), inv_add( i8_c(-127)));
                UT_ASSERT_NUM_EQ( i8_c(-128), inv_add( i8_c(-128)));

                UT_ASSERT_NUM_EQ( u8_c(   1), inv_add( u8_c(  -1)));
                UT_ASSERT_NUM_EQ( u8_c(   0), inv_add( u8_c(   0)));
                UT_ASSERT_NUM_EQ( u8_c(  -1), inv_add( u8_c(   1)));

                UT_ASSERT_NUM_EQ( u8_c( 127), inv_add( u8_c(-127)));
                UT_ASSERT_NUM_EQ( u8_c( 128), inv_add( u8_c(-128)));

                UT_ASSERT_FLT_EQ(f32_c(-1.1), inv_add(f32_c( 1.1)));
                UT_ASSERT_FLT_EQ(f32_c( 1.1), inv_add(f32_c(-1.1)));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(inv_add_chk) {
                is8_t res_i = 0;
                f32_t res_f = 0;
                UT_ASSERT_BOOL_TR(inv_add_chk(res_i, i8_c(-1)));
                UT_ASSERT_NUM_EQ(res_i, i8_c(1));

                UT_ASSERT_BOOL_TR(inv_add_chk(res_i, i8_c(0)));
                UT_ASSERT_NUM_EQ(res_i, i8_c(0));

                UT_ASSERT_BOOL_TR(inv_add_chk(res_i, i8_c(1)));
                UT_ASSERT_NUM_EQ(res_i, i8_c(-1));

                res_i = 33;
                UT_ASSERT_BOOL_TR(inv_add_chk(res_i, i8_c(-127)));
                UT_ASSERT_NUM_EQ(res_i, i8_c(127));

                res_i = 33;
                UT_ASSERT_BOOL_FL(inv_add_chk(res_i, i8_c(-128)));
                UT_ASSERT_NUM_EQ(res_i, i8_c(33));

                UT_ASSERT_BOOL_TR(inv_add_chk(res_f, f32_c(1.1)));
                UT_ASSERT_FLT_EQ(res_f, f32_c(-1.1));

                UT_ASSERT_BOOL_TR(inv_add_chk(res_f, f32_c(-1.1)));
                UT_ASSERT_FLT_EQ(res_f, f32_c(1.1));
            }
            UT_GROUP_END;
        }
        UT_GROUP_END;

        UT_GROUP_BEG(multiplication) {
            UT_GROUP_BEG(is_inv_mul) {
                UT_ASSERT_BOOL_FL(is_inv_mul(f32_c(+0.0)));
                UT_ASSERT_BOOL_FL(is_inv_mul(f32_c( 0.0)));
                UT_ASSERT_BOOL_FL(is_inv_mul(f32_c(-0.0)));

                UT_ASSERT_BOOL_TR(is_inv_mul(f32_c( 1.1)));
                UT_ASSERT_BOOL_TR(is_inv_mul(f32_c(-1.1)));

                UT_ASSERT_BOOL_TR(is_inv_mul(f32_c( 10.1)));
                UT_ASSERT_BOOL_TR(is_inv_mul(f32_c(-10.1)));

                UT_ASSERT_BOOL_TR(is_inv_mul(f32_c( 99.1)));
                UT_ASSERT_BOOL_TR(is_inv_mul(f32_c(-99.1)));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(inv_mul) {
                UT_ASSERT_FLT_EQ(f32_c(pos_inf(f32_t)), inv_mul(f32_c(  +0.0)));
                UT_ASSERT_FLT_EQ(f32_c(pos_inf(f32_t)), inv_mul(f32_c(   0.0)));
                UT_ASSERT_FLT_EQ(f32_c(neg_inf(f32_t)), inv_mul(f32_c(  -0.0)));

                UT_ASSERT_FLT_EQ(f32_c(             8), inv_mul(f32_c( 0.125)));
                UT_ASSERT_FLT_EQ(f32_c(            -8), inv_mul(f32_c(-0.125)));

                UT_ASSERT_FLT_EQ(f32_c(         0.125), inv_mul(f32_c(     8)));
                UT_ASSERT_FLT_EQ(f32_c(        -0.125), inv_mul(f32_c(    -8)));

                UT_ASSERT_FLT_EQ(f32_c(     0.0078125), inv_mul(f32_c(   128)));
                UT_ASSERT_FLT_EQ(f32_c(    -0.0078125), inv_mul(f32_c(  -128)));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(inv_mul_chk) {
                f32_t res_f = 33;

                UT_ASSERT_BOOL_FL(inv_mul_chk(res_f, f32_c(+0.0)));
                UT_ASSERT_FLT_EQ(res_f, f32_c(33));
                UT_ASSERT_BOOL_FL(inv_mul_chk(res_f, f32_c( 0.0)));
                UT_ASSERT_FLT_EQ(res_f, f32_c(33));
                UT_ASSERT_BOOL_FL(inv_mul_chk(res_f, f32_c(-0.0)));
                UT_ASSERT_FLT_EQ(res_f, f32_c(33));

                UT_ASSERT_BOOL_TR(inv_mul_chk(res_f, f32_c( 8)));
                UT_ASSERT_FLT_EQ(res_f, f32_c(+0.125));

                UT_ASSERT_BOOL_TR(inv_mul_chk(res_f, f32_c(-8)));
                UT_ASSERT_FLT_EQ(res_f, f32_c(-0.125));
            }
            UT_GROUP_END;
        }
        UT_GROUP_END;
    }
    UT_GROUP_END;
}
