//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_segment) {
    UT_GROUP_BEG(segment) {
        UT_GROUP_BEG(get_int) {
            UT_ASSERT_NUM_EQUAL(  +2, get_int(i8_c(+2)));
            UT_ASSERT_NUM_EQUAL(  -2, get_int(i8_c(-2)));

            UT_ASSERT_FLT_EQUAL( 2.0, get_int( 2.1));
            UT_ASSERT_FLT_EQUAL(-2.0, get_int(-2.1));
            UT_ASSERT_FLT_EQUAL( 2.0, get_int( 2.0));
            UT_ASSERT_FLT_EQUAL(-2.0, get_int(-2.0));
            UT_ASSERT_FLT_EQUAL( 1.0, get_int( 1.9));
            UT_ASSERT_FLT_EQUAL(-1.0, get_int(-1.9));
            UT_ASSERT_FLT_EQUAL( 1.0, get_int( 1.1));
            UT_ASSERT_FLT_EQUAL(-1.0, get_int(-1.1));

            UT_ASSERT_NUM_EQUAL(INT_MAX , get_int(INT_MAX));
            UT_ASSERT_NUM_EQUAL(UINT_MAX, get_int(UINT_MAX));

            UT_ASSERT_TYPE_EQUAL(get_int((umax_t)(-1.1)), umax_c(0));
            UT_ASSERT_TYPE_EQUAL(get_int((imax_t)(-1.1)), imax_c(0));

            UT_ASSERT_TYPE_NOT_EQUAL(get_int((umax_t)(-1.1)), imax_c(0));
            UT_ASSERT_TYPE_NOT_EQUAL(get_int((imax_t)(-1.1)), umax_c(0));
        }UT_GROUP_END;

        UT_GROUP_BEG(get_rem) {
            UT_ASSERT_NUM_EQUAL(  0, get_rem(   2));
            UT_ASSERT_NUM_EQUAL(  0, get_rem(  -2));

            UT_ASSERT_FLT_EQUAL( 0.1, get_rem( 2.1));
            UT_ASSERT_FLT_EQUAL(-0.1, get_rem(-2.1));
            UT_ASSERT_FLT_EQUAL( 0.0, get_rem( 2.0));
            UT_ASSERT_FLT_EQUAL( 0.0, get_rem(-2.0));
            UT_ASSERT_FLT_EQUAL( 0.9, get_rem( 1.9));
            UT_ASSERT_FLT_EQUAL(-0.9, get_rem(-1.9));
            UT_ASSERT_FLT_EQUAL( 0.1, get_rem( 1.1));
            UT_ASSERT_FLT_EQUAL(-0.1, get_rem(-1.1));
        }UT_GROUP_END;

        UT_GROUP_BEG(get_real) {
            complex x = 2.0 + 3.0I;
            UT_ASSERT_FLT_EQUAL( 2.0, get_real(x));

            x = -2.0 + 3.0I;
            UT_ASSERT_FLT_EQUAL(-2.0, get_real(x));
        }UT_GROUP_END;

        UT_GROUP_BEG(get_imag) {
            complex x = 2.0 + 3.0I;
            UT_ASSERT_FLT_EQUAL( 3.0, get_imag(x));

            x = 2.0 - 3.0I;
            UT_ASSERT_FLT_EQUAL(-3.0, get_imag(x));
        }UT_GROUP_END;
    }UT_GROUP_END;
}
