//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_decomposition) {

    char a =  10;
    char A = -10;

    int b =  20;
    int B = -20;

    float x =  10.25;
    float X = -10.25;

    double y =  10.25;
    double Y = -10.25;

    long double z =  10.25;
    long double Z = -10.25;

    bool_t k = true;
    bool_t K = false;

    UT_GROUP_BEG(get_sign) {
        UT_ASSERT_NUM_EQUAL( +1, get_sign(a));
        UT_ASSERT_NUM_EQUAL( -1, get_sign(A));

        UT_ASSERT_NUM_EQUAL( +1, get_sign(b));
        UT_ASSERT_NUM_EQUAL( -1, get_sign(B));

        UT_ASSERT_NUM_EQUAL( +1, get_sign(x));
        UT_ASSERT_NUM_EQUAL( -1, get_sign(X));

        UT_ASSERT_NUM_EQUAL( +1, get_sign(y));
        UT_ASSERT_NUM_EQUAL( -1, get_sign(Y));

        UT_ASSERT_NUM_EQUAL( +1, get_sign(z));
        UT_ASSERT_NUM_EQUAL( -1, get_sign(Z));

        UT_ASSERT_NUM_EQUAL(  0, get_sign(k));
        UT_ASSERT_NUM_EQUAL(  0, get_sign(K));

        UT_ASSERT_NUM_EQUAL( +1, get_sign(i8_c(   1)));
        UT_ASSERT_NUM_EQUAL( +1, get_sign(i8_c(   2)));
        UT_ASSERT_NUM_EQUAL( -1, get_sign(i8_c(  -1)));
        UT_ASSERT_NUM_EQUAL( -1, get_sign(i8_c(  -2)));
        UT_ASSERT_NUM_EQUAL(  0, get_sign(i8_c(   0)));
        UT_ASSERT_NUM_EQUAL(  1, get_sign( 0.0));
        UT_ASSERT_NUM_EQUAL( -1, get_sign(-0.0));
        UT_ASSERT_NUM_EQUAL(  1, get_sign( 0.1));
        UT_ASSERT_NUM_EQUAL( -1, get_sign(-0.1));

        UT_ASSERT_BOOL(get_sign(2) == get_sign(2));

        int a = -1;
        UT_ASSERT_NUM_EQUAL( -1, get_sign(a));
        UT_ASSERT_NUM_EQUAL( -1, a);
        UT_ASSERT_NUM_EQUAL( -1, get_sign(a++));
        UT_ASSERT_NUM_EQUAL(  0, a);

        a = -1;
        UT_ASSERT_NUM_EQUAL( -1, get_sign(a));
        UT_ASSERT_NUM_EQUAL( -1, a);
        UT_ASSERT_NUM_EQUAL( -1, get_sign(a--));
        UT_ASSERT_NUM_EQUAL( -2, a);
    } UT_GROUP_END;

    UT_GROUP_BEG(components_float) {
        UT_GROUP_BEG(get_mantissa) {
            UT_ASSERT_FLT_EQUAL( 0.640625, get_mantissa(x));
            UT_ASSERT_FLT_EQUAL( 0.640625, get_mantissa(X));

            UT_ASSERT_FLT_EQUAL( 0.640625, get_mantissa(y));
            UT_ASSERT_FLT_EQUAL( 0.640625, get_mantissa(Y));

            UT_ASSERT_FLT_EQUAL( 0.640625, get_mantissa(z));
            UT_ASSERT_FLT_EQUAL( 0.640625, get_mantissa(Z));
        } UT_GROUP_END;

        UT_GROUP_BEG(get_mantissa) {
            UT_ASSERT_NUM_EQUAL( 4, get_exponent(x));
            UT_ASSERT_NUM_EQUAL( 4, get_exponent(X));

            UT_ASSERT_NUM_EQUAL( 4, get_exponent(y));
            UT_ASSERT_NUM_EQUAL( 4, get_exponent(Y));

            UT_ASSERT_NUM_EQUAL( 4, get_exponent(z));
            UT_ASSERT_NUM_EQUAL( 4, get_exponent(Z));
        } UT_GROUP_END;

        UT_GROUP_BEG(destruc_struct_2) {
#define S_M_2E(x) (get_sign(x) * get_mantissa(x) * pow(2.0, typecast(0.0, get_exponent(x))))
            UT_ASSERT_FLT_EQUAL(  10.25, S_M_2E(x));
            UT_ASSERT_FLT_EQUAL( -10.25, S_M_2E(X));
        } UT_GROUP_END;

        UT_GROUP_BEG(destruc_struct_10) {
#define S_M_10E(x) x //(get_sign(x) * get_mantissa10(x) * pow(2, get_mantissa10(x)))
            UT_ASSERT_FLT_EQUAL(  10.25, S_M_10E(x));
            UT_ASSERT_FLT_EQUAL( -10.25, S_M_10E(X));
        } UT_GROUP_END;
    } UT_GROUP_END;
}
