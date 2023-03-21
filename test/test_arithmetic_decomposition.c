//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_decomposition) {

    is8_t a =  10;
    is8_t A = -10;

    int b =  20;
    int B = -20;

    f32_t x = f32_c( 10.25);
    f32_t X = f32_c(-10.25);

    f64_t y = f64_c( 2050.50);
    f64_t Y = f64_c(-2050.50);

    f128_t z = f128_c( 58987.25);
    f128_t Z = f128_c(-58987.25);

    UT_GROUP_BEG(get_sign) {
        UT_ASSERT_NUM_EQ( i8_c(+1), get_sign(a));
        UT_ASSERT_NUM_EQ( i8_c(-1), get_sign(A));

        UT_ASSERT_NUM_EQ( +1, get_sign(b));
        UT_ASSERT_NUM_EQ( -1, get_sign(B));

        UT_ASSERT_FLT_EQ( f32_c(+1), get_sign(x));
        UT_ASSERT_FLT_EQ( f32_c(-1), get_sign(X));

        UT_ASSERT_FLT_EQ( f64_c(+1), get_sign(y));
        UT_ASSERT_FLT_EQ( f64_c(-1), get_sign(Y));

        UT_ASSERT_FLT_EQ( f128_c(+1), get_sign(z));
        UT_ASSERT_FLT_EQ( f128_c(-1), get_sign(Z));

        UT_ASSERT_NUM_EQ(  i8_c(+1), get_sign(i8_c(   1)));
        UT_ASSERT_NUM_EQ(  i8_c(+1), get_sign(i8_c(   2)));
        UT_ASSERT_NUM_EQ(  i8_c(-1), get_sign(i8_c(  -1)));
        UT_ASSERT_NUM_EQ(  i8_c(-1), get_sign(i8_c(  -2)));
        UT_ASSERT_NUM_EQ(  i8_c( 0), get_sign(i8_c(   0)));
        UT_ASSERT_FLT_EQ(fmax_c( 1), get_sign(fmax_c( 0.0)));
        UT_ASSERT_FLT_EQ(fmax_c(-1), get_sign(fmax_c(-0.0)));
        UT_ASSERT_FLT_EQ(fmax_c( 1), get_sign(fmax_c( 0.1)));
        UT_ASSERT_FLT_EQ(fmax_c(-1), get_sign(fmax_c(-0.1)));

        UT_ASSERT_BOOL(get_sign(2) == get_sign(2));

        int a = -1;
        UT_ASSERT_NUM_EQ( -1, get_sign(a));
        UT_ASSERT_NUM_EQ( -1, a);
        UT_ASSERT_NUM_EQ( -1, get_sign(a++));
        UT_ASSERT_NUM_EQ(  0, a);

        a = -1;
        UT_ASSERT_NUM_EQ( -1, get_sign(a));
        UT_ASSERT_NUM_EQ( -1, a);
        UT_ASSERT_NUM_EQ( -1, get_sign(a--));
        UT_ASSERT_NUM_EQ( -2, a);
    } UT_GROUP_END;


    UT_GROUP_BEG(components_float) {
        UT_GROUP_BEG(get_mantissa) {
            UT_ASSERT_FLT_EQ( 0.640625, get_mantissa(x));
            UT_ASSERT_FLT_EQ( 0.640625, get_mantissa(X));

            UT_ASSERT_FLT_EQ( 0.5006103515625, get_mantissa(y));
            UT_ASSERT_FLT_EQ( 0.5006103515625, get_mantissa(Y));

            UT_ASSERT_FLT_EQ( 0.900074005126953125, get_mantissa(z));
            UT_ASSERT_FLT_EQ( 0.900074005126953125, get_mantissa(Z));
        } UT_GROUP_END;

        UT_GROUP_BEG(get_exponent) {
            UT_ASSERT_NUM_EQ(imax_c( 4), get_exponent(x));
            UT_ASSERT_NUM_EQ(imax_c( 4), get_exponent(X));

            UT_ASSERT_NUM_EQ(imax_c(12), get_exponent(y));
            UT_ASSERT_NUM_EQ(imax_c(12), get_exponent(Y));

            UT_ASSERT_NUM_EQ(imax_c(16), get_exponent(z));
            UT_ASSERT_NUM_EQ(imax_c(16), get_exponent(Z));
        } UT_GROUP_END;


        UT_GROUP_BEG(destruc_struct_2) {
#define S_M_2E(x) (get_sign(x) * get_mantissa(x) * powm(typecast(x, 2.0), typecast(x, get_exponent(x))))
            UT_ASSERT_FLT_EQ(  10.25, S_M_2E(x));
            UT_ASSERT_FLT_EQ( -10.25, S_M_2E(X));
        } UT_GROUP_END;

        UT_GROUP_BEG(get_mantissa10) {
            UT_ASSERT_FLT_EQ_E( f32_c(1.0249998569488525390625), get_mantissa10(x), 0.00000000001);
            UT_ASSERT_FLT_EQ_E( f32_c(1.0249998569488525390625), get_mantissa10(X), 0.00000000001);

            UT_ASSERT_FLT_EQ_E( f64_c(2.050499999999998212985019563348032534122467041015625000), get_mantissa10(y), 0.00000000001);
            UT_ASSERT_FLT_EQ_E( f64_c(2.050499999999998212985019563348032534122467041015625000), get_mantissa10(Y), 0.00000000001);

            UT_ASSERT_FLT_EQ_E( f128_c(5.89872500000000000346458972622087912895949557423591613769531250), get_mantissa10(z), 0.00000000001);
            UT_ASSERT_FLT_EQ_E( f128_c(5.89872500000000000346458972622087912895949557423591613769531250), get_mantissa10(Z), 0.00000000001);
        } UT_GROUP_END;


        UT_GROUP_BEG(get_exponent10) {
            UT_ASSERT_NUM_EQ(imax_c(1), get_exponent10(x));
            UT_ASSERT_NUM_EQ(imax_c(1), get_exponent10(X));

            UT_ASSERT_NUM_EQ(imax_c(3), get_exponent10(y));
            UT_ASSERT_NUM_EQ(imax_c(3), get_exponent10(Y));

            UT_ASSERT_NUM_EQ(imax_c(4), get_exponent10(z));
            UT_ASSERT_NUM_EQ(imax_c(4), get_exponent10(Z));
        } UT_GROUP_END;


        UT_GROUP_BEG(destruc_struct_10) {
#define S_M_10E(x) (get_sign(x) * get_mantissa10(x) * powm(typecast(x, 10.0), typecast(x, get_exponent10(x))))
            UT_ASSERT_FLT_EQ_E( x, S_M_10E(x), 0.00001);
            UT_ASSERT_FLT_EQ_E( X, S_M_10E(X), 0.00001);

            UT_ASSERT_FLT_EQ_E( y, S_M_10E(y), 0.00001);
            UT_ASSERT_FLT_EQ_E( Y, S_M_10E(Y), 0.00001);

            UT_ASSERT_FLT_EQ_E( z, S_M_10E(z), 0.00001);
            UT_ASSERT_FLT_EQ_E( Z, S_M_10E(Z), 0.00001);
        } UT_GROUP_END;
    } UT_GROUP_END;
}
