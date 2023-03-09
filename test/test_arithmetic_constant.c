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
            UT_ASSERT_NUM_EQUAL(  0, zero(0));
            UT_ASSERT_NUM_EQUAL(  0, zero(int));

            UT_ASSERT_TYPE_EQUAL(  0, zero(1));
            UT_ASSERT_TYPE_EQUAL(  0, zero(int));

            UT_ASSERT_TYPE_EQUAL( 0L, zero(long int));
            UT_ASSERT_TYPE_NOT_EQUAL(0.0, zero(int));

            UT_ASSERT_FLT_EQUAL(0.0, zero(0.0));
            UT_ASSERT_FLT_EQUAL(0.0, zero(float));

            UT_ASSERT_TYPE_EQUAL(0.0, zero(1.0));
            UT_ASSERT_TYPE_EQUAL(0.0, zero(double));
            UT_ASSERT_TYPE_NOT_EQUAL(0, zero(double));

            UT_ASSERT_NUM_EQUAL( u16_c(0.0), zero(us8_t));
            UT_ASSERT_TYPE_NOT_EQUAL( u16_c(0.0), zero(us8_t));
        } UT_GROUP_END;

        UT_GROUP_BEG(one) {
            UT_ASSERT_NUM_EQUAL(  1, one(0));
            UT_ASSERT_NUM_EQUAL(  1, one(int));

            UT_ASSERT_FLT_EQUAL(1.0, one(0.0));
            UT_ASSERT_FLT_EQUAL(1.0, one(float));

            UT_ASSERT_TYPE_EQUAL(   1, one( 1  ));
            UT_ASSERT_TYPE_EQUAL( 1.0, one( 1.0));
        } UT_GROUP_END;

        UT_GROUP_BEG(float_point) {
            UT_ASSERT_FLT_EQUAL(              +0.0, pos_zero());
            UT_ASSERT_TYPE_NOT_EQUAL(            1, pos_zero());
            UT_ASSERT_TYPE_EQUAL(      fmax_c(1.0), pos_zero());

            UT_ASSERT_FLT_EQUAL(               -0.0, neg_zero());
            UT_ASSERT_TYPE_NOT_EQUAL(           1  , neg_zero());
            UT_ASSERT_TYPE_EQUAL(       fmax_c(1.0), neg_zero());

            UT_ASSERT_FLT_EQUAL(    +INFINITY, pos_inf());
            UT_ASSERT_TYPE_NOT_EQUAL(       1, pos_inf());
            UT_ASSERT_TYPE_EQUAL(fmax_c(1.0), pos_inf());

            UT_ASSERT_FLT_EQUAL(    -INFINITY, neg_inf());
            UT_ASSERT_TYPE_NOT_EQUAL(       1, neg_inf());
            UT_ASSERT_TYPE_EQUAL(fmax_c(1.0), neg_inf());

            UT_ASSERT_FLT_EQUAL(         +NAN, pos_nan());
            UT_ASSERT_TYPE_NOT_EQUAL(       1, pos_nan());
            UT_ASSERT_TYPE_EQUAL(fmax_c(1.0), pos_nan());

            UT_ASSERT_FLT_EQUAL(         -NAN, neg_nan());
            UT_ASSERT_TYPE_NOT_EQUAL(       1, neg_nan());
            UT_ASSERT_TYPE_EQUAL(fmax_c(1.0), neg_nan());
        }UT_GROUP_END;
    }UT_GROUP_END;
}
