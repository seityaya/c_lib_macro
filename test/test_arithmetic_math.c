//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_math) {
    UT_GROUP_BEG(math) {
        UT_GROUP_BEG(sum) {
            UT_ASSERT_NUM_EQUAL( 2, sum( 1, 1));
            UT_ASSERT_NUM_EQUAL( 0, sum(-1, 1));

            UT_ASSERT_FLT_EQUAL( 0.2, sum( 0.1, 0.1));
            UT_ASSERT_FLT_EQUAL( 0.0, sum(-0.1, 0.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(dif) {
            UT_ASSERT_NUM_EQUAL( 0, dif( 1, 1));
            UT_ASSERT_NUM_EQUAL(-2, dif(-1, 1));

            UT_ASSERT_FLT_EQUAL( 0.0, dif( 0.1, 0.1));
            UT_ASSERT_FLT_EQUAL(-0.2, dif(-0.1, 0.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(mul) {
            UT_ASSERT_NUM_EQUAL( 1, mul( 1, 1));
            UT_ASSERT_NUM_EQUAL(-1, mul(-1, 1));

            UT_ASSERT_FLT_EQUAL( 0.01, mul( 0.1, 0.1));
            UT_ASSERT_FLT_EQUAL(-0.01, mul(-0.1, 0.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(div) {
            UT_ASSERT_NUM_EQUAL( 2, div(5, 2));
            UT_ASSERT_NUM_EQUAL(-2, div(5,-2));
            UT_ASSERT_NUM_EQUAL( 3, div(6, 2));
            UT_ASSERT_NUM_EQUAL(-3, div(6,-2));

            UT_ASSERT_NUM_EQUAL(-2, div(-5,2));
            UT_ASSERT_NUM_EQUAL(-3, div(-6,2));

            UT_ASSERT_FLT_EQUAL( 13.0, div(4.0,   0.3));
            UT_ASSERT_FLT_EQUAL(-13.0, div(4.0,  -0.3));

            UT_ASSERT_FLT_EQUAL( 3.0,  div(12.77, 3.4));
            UT_ASSERT_FLT_EQUAL(-3.0,  div(12.77,-3.4));

        } UT_GROUP_END;

        UT_GROUP_BEG(mod) {
            UT_ASSERT_NUM_EQUAL(   1, mod( 4,  3));
            UT_ASSERT_NUM_EQUAL(   1, mod( 5,  2));
            UT_ASSERT_NUM_EQUAL(   1, mod( 5, -2));
            UT_ASSERT_NUM_EQUAL(   0, mod( 6,  2));
            UT_ASSERT_NUM_EQUAL(   0, mod( 6, -2));

            UT_ASSERT_NUM_EQUAL(  -1, mod(-5,  2));
            UT_ASSERT_NUM_EQUAL(   0, mod(-6,  2));

            UT_ASSERT_FLT_EQUAL( 0.1, mod( 4.0, 0.3));
            UT_ASSERT_FLT_EQUAL( 0.1, mod( 4.0,-0.3));
            UT_ASSERT_FLT_EQUAL(-0.1, mod(-4.0, 0.3));
            UT_ASSERT_FLT_EQUAL(-0.1, mod(-4.0,-0.3));
        } UT_GROUP_END;

        UT_GROUP_BEG(div_mod) {
#define DIV_MOD(x, y) (((y) * div(x, y) + mod(x, y)) == (x))
            UT_ASSERT_BOOL_TRUE(DIV_MOD( 5, 2));
            UT_ASSERT_BOOL_TRUE(DIV_MOD( 5,-2));
            UT_ASSERT_BOOL_TRUE(DIV_MOD( 6, 2));
            UT_ASSERT_BOOL_TRUE(DIV_MOD( 6,-2));
            UT_ASSERT_BOOL_TRUE(DIV_MOD(-6, 2));
            UT_ASSERT_BOOL_TRUE(DIV_MOD(-6,-2));

            UT_ASSERT_BOOL_TRUE(DIV_MOD(-5, 2));
            UT_ASSERT_BOOL_TRUE(DIV_MOD(-6, 2));

            UT_ASSERT_BOOL_TRUE(DIV_MOD( 4.0, 0.3));
            UT_ASSERT_BOOL_TRUE(DIV_MOD( 4.0,-0.3));
            UT_ASSERT_BOOL_TRUE(DIV_MOD(-4.0, 0.3));
            UT_ASSERT_BOOL_TRUE(DIV_MOD(-4.0,-0.3));
        } UT_GROUP_END;

        UT_GROUP_BEG(qut) {
            UT_ASSERT_FLT_EQUAL( 0.3333333333333333, qut( 1.0,  3.0));
            UT_ASSERT_FLT_EQUAL( 1.3333333333333333, qut( 4.0,  3.0));
            UT_ASSERT_FLT_EQUAL( 1.25, qut( 5.0,  4.0));
            UT_ASSERT_FLT_EQUAL( 1.0, qut( 5.0,  5.0));
            UT_ASSERT_FLT_EQUAL( 0.0, qut( 0.0,  5.0));
            UT_ASSERT_FLT_EQUAL( INFINITY, qut( 5.0,  0.0));

            UT_ASSERT_FLT_EQUAL( -0.3333333333333333, qut( -1.0,  3.0));
            UT_ASSERT_FLT_EQUAL( -1.3333333333333333, qut( -4.0,  3.0));
            UT_ASSERT_FLT_EQUAL( -1.25, qut( -5.0,  4.0));
            UT_ASSERT_FLT_EQUAL( -1.0, qut( -5.0,  5.0));
            UT_ASSERT_FLT_EQUAL( -0.0, qut( -0.0,  5.0));
            UT_ASSERT_FLT_EQUAL( -INFINITY, qut( -5.0,  0.0));
        } UT_GROUP_END;

        UT_GROUP_BEG(pow) {
            UT_ASSERT_FLT_EQUAL(8.0, powm( 2.0,  3.0));
            UT_ASSERT_FLT_EQUAL(3.0, powm( 9.0,  0.5));
            UT_ASSERT_FLT_EQUAL(0.33333333333333333, pow( 9.0, -0.5));
        } UT_GROUP_END;

        UT_GROUP_BEG(rot) {
            UT_ASSERT_FLT_EQUAL(4.0, root(16.0,  2.0));
            UT_ASSERT_FLT_EQUAL(2.0, root( 8.0,  3.0));
            UT_ASSERT_FLT_EQUAL(9.0, root( 3.0,  0.5));
            UT_ASSERT_NFLT_EQUAL(9.0, root( 0.33333333333333333333333, -0.5), 0.00000000000001);
        } UT_GROUP_END;

        UT_GROUP_BEG(log) {
            UT_ASSERT_FLT_EQUAL(3.0, logm(8.0 , 2.0 ));
            UT_ASSERT_FLT_EQUAL(2.0, logm(9.0 , 3.0));
            UT_ASSERT_FLT_EQUAL(0.33333333333333333, logm( 9.0, -0.5));
        } UT_GROUP_END;

        UT_GROUP_BEG(dis) {
            UT_ASSERT_NUM_EQUAL(   0, dis( 0,  0));
            UT_ASSERT_NUM_EQUAL(   0, dis( 1,  1));
            UT_ASSERT_NUM_EQUAL(   0, dis(-1, -1));

            UT_ASSERT_NUM_EQUAL(   1, dis( 0,  1));
            UT_ASSERT_NUM_EQUAL(   1, dis( 1,  0));
            UT_ASSERT_NUM_EQUAL(   2, dis(-1, +1));

            UT_ASSERT_NUM_EQUAL(   3, dis( 0,  3));
            UT_ASSERT_NUM_EQUAL(   2, dis( 1,  3));
            UT_ASSERT_NUM_EQUAL(   2, dis(-1, -3));
            UT_ASSERT_NUM_EQUAL(   3, dis( 0, -3));

            UT_ASSERT_NUM_EQUAL(   6, dis(-3, +3));

            UT_ASSERT_FLT_EQUAL( 1.1, dis( 0.0,  1.1));
            UT_ASSERT_FLT_EQUAL( 1.1, dis( 0.0, -1.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(abs) {
            UT_ASSERT_NUM_EQUAL(   0, abs( 0));
            UT_ASSERT_NUM_EQUAL(   1, abs( 1));
            UT_ASSERT_NUM_EQUAL(   1, abs(-1));

            UT_ASSERT_FLT_EQUAL( 1.1, abs( 1.1));
            UT_ASSERT_FLT_EQUAL( 1.1, abs(-1.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(positiv) {
            UT_ASSERT_NUM_EQUAL(   0, pos( 0));
            UT_ASSERT_NUM_EQUAL(   1, pos( 1));
            UT_ASSERT_NUM_EQUAL(   1, pos(-1));

            UT_ASSERT_FLT_EQUAL( 1.1, pos( 1.1));
            UT_ASSERT_FLT_EQUAL( 1.1, pos(-1.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(negativ) {
            UT_ASSERT_NUM_EQUAL(  -0, neg( 0));
            UT_ASSERT_NUM_EQUAL(  -1, neg( 1));
            UT_ASSERT_NUM_EQUAL(  -1, neg(-1));

            UT_ASSERT_FLT_EQUAL(-1.1, neg( 1.1));
            UT_ASSERT_FLT_EQUAL(-1.1, neg(-1.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(gcd) {
            UT_ASSERT_NUM_EQUAL( 4, gcd(umax_c(16), umax_c( 20)));
            UT_ASSERT_NUM_EQUAL( 7, gcd(umax_c(21), umax_c(  7)));
            UT_ASSERT_NUM_EQUAL( 1, gcd(umax_c(36), umax_c(  5)));
            UT_ASSERT_NUM_EQUAL( 5, gcd(umax_c(35), umax_c(  5)));
        } UT_GROUP_END;

        UT_GROUP_BEG(lcm) {
            UT_ASSERT_NUM_EQUAL(  80, lcm(umax_c(16), umax_c(20)));
            UT_ASSERT_NUM_EQUAL(  21, lcm(umax_c(21), umax_c( 7)));
            UT_ASSERT_NUM_EQUAL( 180, lcm(umax_c(36), umax_c( 5)));
            UT_ASSERT_NUM_EQUAL( 180, lcm(umax_c(36), umax_c( 5)));
        } UT_GROUP_END;
    } UT_GROUP_END;
}
