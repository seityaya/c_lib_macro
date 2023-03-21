//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_constant) {
    UT_GROUP_BEG(constant) {
        UT_GROUP_BEG(zero) {
            UT_ASSERT_NUM_EQ(   0,   zero(0));
            UT_ASSERT_NUM_EQ(   0, zero(int));

            UT_ASSERT_TYPE_EQ(  0, zero(1));
            UT_ASSERT_TYPE_EQ( 0L, zero(long int));
            UT_ASSERT_TYPE_NQ(  0, zero(long int));
            UT_ASSERT_TYPE_NQ(0.0, zero(int));

            UT_ASSERT_FLT_EQ(0.0, zero(0.0));
            UT_ASSERT_FLT_EQ(0.0, zero(float));

            UT_ASSERT_TYPE_EQ(0.0, zero(1.0));
            UT_ASSERT_TYPE_EQ(0.0, zero(double));
            UT_ASSERT_TYPE_NQ(  0, zero(double));

            UT_ASSERT_TYPE_NQ( u16_c(0.0), zero(us32_t));
        } UT_GROUP_END;


        UT_GROUP_BEG(one) {
            UT_ASSERT_NUM_EQ(    1, one(    0));
            UT_ASSERT_NUM_EQ(    1, one(  int));

            UT_ASSERT_FLT_EQ(  1.0, one(  0.0));
            UT_ASSERT_FLT_EQ(  1.0, one(float));

            UT_ASSERT_TYPE_EQ(   1, one(    1));
            UT_ASSERT_TYPE_EQ( 1.0, one(  1.0));
        } UT_GROUP_END;


        UT_GROUP_BEG(float_point) {
            UT_ASSERT_FLT_EQ(       fmax_c(+0.0), pos(zero(fmax_t)));
            UT_ASSERT_TYPE_NQ(             1, pos(zero(fmax_t)));
            UT_ASSERT_TYPE_EQ(       fmax_c(1.0), pos(zero(fmax_t)));

            UT_ASSERT_FLT_EQ(       fmax_c(-0.0), neg(zero(fmax_t)));
            UT_ASSERT_TYPE_NQ(             1, neg(zero(fmax_t)));
            UT_ASSERT_TYPE_EQ(       fmax_c(1.0), neg(zero(fmax_t)));

            UT_ASSERT_FLT_EQ(          +INFINITY, pos(inf(fmax_t)));
            UT_ASSERT_TYPE_NQ(             1, pos(inf(fmax_t)));
            UT_ASSERT_TYPE_EQ(       fmax_c(1.0), pos(inf(fmax_t)));

            UT_ASSERT_FLT_EQ(          -INFINITY, neg(inf(fmax_t)));
            UT_ASSERT_TYPE_NQ(             1, neg(inf(fmax_t)));
            UT_ASSERT_TYPE_EQ(       fmax_c(1.0), neg(inf(fmax_t)));

            UT_ASSERT_FLT_EQ(               +NAN, pos(nan(fmax_t)));
            UT_ASSERT_TYPE_NQ(             1, pos(nan(fmax_t)));
            UT_ASSERT_TYPE_EQ(       fmax_c(1.0), pos(nan(fmax_t)));

            UT_ASSERT_FLT_EQ(               -NAN, neg(nan(fmax_t)));
            UT_ASSERT_TYPE_NQ(             1, neg(nan(fmax_t)));
            UT_ASSERT_TYPE_EQ(       fmax_c(1.0), neg(nan(fmax_t)));
        }UT_GROUP_END;
    }UT_GROUP_END;
}
