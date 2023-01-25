//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.01
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic) {
    UT_GROUP_BEG(arithmetic) {
        UT_GROUP_BEG(compare) {
            UT_GROUP_BEG(as) {
                int x = 1;
                double_t y = 2.5;
                UT_ASSERT_FLT_EQUAL(2.5, y);

                UT_ASSERT_NUM_EQUAL(  1, x);
                AS(x, (int)(y));
                UT_ASSERT_NUM_EQUAL(  2, x);
            }UT_GROUP_END;

            UT_GROUP_BEG(swap) {
                int A =  10;
                int B = -10;
                UT_ASSERT_NUM_EQUAL( 10, A);
                UT_ASSERT_NUM_EQUAL(-10, B);
                SWAP(A, B);
                UT_ASSERT_NUM_EQUAL(-10, A);
                UT_ASSERT_NUM_EQUAL( 10, B);
            } UT_GROUP_END;


            UT_GROUP_BEG(eq) {
                UT_ASSERT_BOOL_TRUE(EQ(1, 1));
            }UT_GROUP_END;

            UT_GROUP_BEG(nq) {
                UT_ASSERT_BOOL_TRUE(NQ(1, 2));
            }UT_GROUP_END;

            UT_GROUP_BEG(gt) {
                UT_ASSERT_BOOL_TRUE(GT(2, 1));
            }UT_GROUP_END;

            UT_GROUP_BEG(lt) {
                UT_ASSERT_BOOL_TRUE(LT(1, 2));
            }UT_GROUP_END;

            UT_GROUP_BEG(ge) {
                UT_ASSERT_BOOL_TRUE(GE(2, 1));
                UT_ASSERT_BOOL_TRUE(GE(2, 2));
            }UT_GROUP_END;

            UT_GROUP_BEG(le) {
                UT_ASSERT_BOOL_TRUE(LE(1, 2));
                UT_ASSERT_BOOL_TRUE(LE(1, 1));
            }UT_GROUP_END;

            UT_GROUP_BEG(ap) {
                UT_ASSERT_BOOL_TRUE(AP(   1,   1,  0));
                UT_ASSERT_BOOL_TRUE(AP(   9,  10,  1));
                UT_ASSERT_BOOL_TRUE(AP(  90, 100, 10));
                UT_ASSERT_BOOL_TRUE(AP(-100, -90, 10));

                UT_ASSERT_BOOL_FALSE(AP(  1,   2,  0));
                UT_ASSERT_BOOL_FALSE(AP(100, -90, 10));
            }UT_GROUP_END;

            UT_GROUP_BEG(get_int) {
                UT_ASSERT_NUM_EQUAL(   2, GET_INT(   2));
                UT_ASSERT_NUM_EQUAL(  -2, GET_INT(  -2));

                UT_ASSERT_FLT_EQUAL( 2.0, GET_INT( 2.1));
                UT_ASSERT_FLT_EQUAL(-2.0, GET_INT(-2.1));
                UT_ASSERT_FLT_EQUAL( 2.0, GET_INT( 2.0));
                UT_ASSERT_FLT_EQUAL(-2.0, GET_INT(-2.0));
                UT_ASSERT_FLT_EQUAL( 1.0, GET_INT( 1.9));
                UT_ASSERT_FLT_EQUAL(-1.0, GET_INT(-1.9));
                UT_ASSERT_FLT_EQUAL( 1.0, GET_INT( 1.1));
                UT_ASSERT_FLT_EQUAL(-1.0, GET_INT(-1.1));
            }UT_GROUP_END;

            UT_GROUP_BEG(get_rem) {
                UT_ASSERT_NUM_EQUAL(   0, GET_REM(   2));
                UT_ASSERT_NUM_EQUAL(  -0, GET_REM(  -2));

                UT_ASSERT_FLT_EQUAL( 0.1, GET_REM( 2.1));
                UT_ASSERT_FLT_EQUAL(-0.1, GET_REM(-2.1));
                UT_ASSERT_FLT_EQUAL( 0.0, GET_REM( 2.0));
                UT_ASSERT_FLT_EQUAL( 0.0, GET_REM(-2.0));
                UT_ASSERT_FLT_EQUAL( 0.9, GET_REM( 1.9));
                UT_ASSERT_FLT_EQUAL(-0.9, GET_REM(-1.9));
                UT_ASSERT_FLT_EQUAL( 0.1, GET_REM( 1.1));
                UT_ASSERT_FLT_EQUAL(-0.1, GET_REM(-1.1));
            }UT_GROUP_END;
        }UT_GROUP_END;

        UT_GROUP_BEG(sig) {
            UT_ASSERT_NUM_EQUAL( +1, SIG(i_8_c(   1)));
            UT_ASSERT_NUM_EQUAL( +1, SIG(i_8_c(   2)));
            UT_ASSERT_NUM_EQUAL( -1, SIG(i_8_c(  -1)));
            UT_ASSERT_NUM_EQUAL( -1, SIG(i_8_c(  -2)));
            UT_ASSERT_NUM_EQUAL(  0, SIG(i_8_c(   0)));
            UT_ASSERT_NUM_EQUAL(  0, SIG( 0.0));
            UT_ASSERT_NUM_EQUAL(  1, SIG( 0.1));
            UT_ASSERT_NUM_EQUAL( -1, SIG(-0.1));

            UT_ASSERT_BOOL(SIG(2) == SIG(2));

            int a = -1;
            UT_ASSERT_NUM_EQUAL( -1, SIG(a));
            UT_ASSERT_NUM_EQUAL( -1, a);
            UT_ASSERT_NUM_EQUAL( -1, SIG(a++));
            UT_ASSERT_NUM_EQUAL(  0, a);

            a = -1;
            UT_ASSERT_NUM_EQUAL( -1, SIG(a));
            UT_ASSERT_NUM_EQUAL( -1, a);
            UT_ASSERT_NUM_EQUAL( -1, SIG(a--));
            UT_ASSERT_NUM_EQUAL( -2, a);
        } UT_GROUP_END;

        UT_GROUP_BEG(positiv) {
            UT_ASSERT_NUM_EQUAL(   0, POSITIV( 0));
            UT_ASSERT_NUM_EQUAL(   1, POSITIV( 1));
            UT_ASSERT_NUM_EQUAL(   1, POSITIV(-1));

            UT_ASSERT_FLT_EQUAL( 1.1, POSITIV( 1.1));
            UT_ASSERT_FLT_EQUAL( 1.1, POSITIV(-1.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(negativ) {
            UT_ASSERT_NUM_EQUAL(  -0, NEGITIV( 0));
            UT_ASSERT_NUM_EQUAL(  -1, NEGITIV( 1));
            UT_ASSERT_NUM_EQUAL(  -1, NEGITIV(-1));

            UT_ASSERT_FLT_EQUAL(-1.1, NEGITIV( 1.1));
            UT_ASSERT_FLT_EQUAL(-1.1, NEGITIV(-1.1));
        } UT_GROUP_END;


        UT_GROUP_BEG(is_pos) {
            UT_ASSERT_BOOL_FALSE(IS_POS(+0.0));
            UT_ASSERT_BOOL_FALSE(IS_POS(   0));
            UT_ASSERT_BOOL_FALSE(IS_POS(  -1));
            UT_ASSERT_BOOL_FALSE(IS_POS(-1.1));

            UT_ASSERT_BOOL_TRUE(IS_POS(  +1));
            UT_ASSERT_BOOL_TRUE(IS_POS(+1.0));
        } UT_GROUP_END;

        UT_GROUP_BEG(is_neg) {
            UT_ASSERT_BOOL_FALSE(IS_NEG(-0.0));
            UT_ASSERT_BOOL_FALSE(IS_NEG(   0));
            UT_ASSERT_BOOL_FALSE(IS_NEG(   1));
            UT_ASSERT_BOOL_FALSE(IS_NEG( 1.1));

            UT_ASSERT_BOOL_TRUE(IS_NEG(  -1));
            UT_ASSERT_BOOL_TRUE(IS_NEG(-1.0));
        } UT_GROUP_END;

        UT_GROUP_BEG(is_zero) {
            UT_ASSERT_BOOL_TRUE(IS_ZERO(+0.0));
            UT_ASSERT_BOOL_TRUE(IS_ZERO(-0.0));
            UT_ASSERT_BOOL_TRUE(IS_ZERO(   0));

            UT_ASSERT_BOOL_FALSE(IS_ZERO( 1));
            UT_ASSERT_BOOL_FALSE(IS_ZERO(-1));
        } UT_GROUP_END;

        UT_GROUP_BEG(is_pos_&_zero) {
            UT_ASSERT_BOOL_FALSE(IS_POS_AND_ZERO(  -1));
            UT_ASSERT_BOOL_FALSE(IS_POS_AND_ZERO(-1.1));

            UT_ASSERT_BOOL_TRUE(IS_POS_AND_ZERO(+0.0));
            UT_ASSERT_BOOL_TRUE(IS_POS_AND_ZERO(   0));
            UT_ASSERT_BOOL_TRUE(IS_POS_AND_ZERO(  +1));
            UT_ASSERT_BOOL_TRUE(IS_POS_AND_ZERO(+1.0));
        } UT_GROUP_END;

        UT_GROUP_BEG(is_neg_&_zero) {
            UT_ASSERT_BOOL_FALSE(IS_NEG_AND_ZERO(   1));
            UT_ASSERT_BOOL_FALSE(IS_NEG_AND_ZERO( 1.1));

            UT_ASSERT_BOOL_TRUE(IS_NEG_AND_ZERO(-0.0));
            UT_ASSERT_BOOL_TRUE(IS_NEG_AND_ZERO(   0));
            UT_ASSERT_BOOL_TRUE(IS_NEG_AND_ZERO(  -1));
            UT_ASSERT_BOOL_TRUE(IS_NEG_AND_ZERO(-1.0));
        } UT_GROUP_END;



        UT_GROUP_BEG(sum) {
            UT_ASSERT_NUM_EQUAL( 2, SUM( 1, 1));
            UT_ASSERT_NUM_EQUAL( 0, SUM(-1, 1));

            UT_ASSERT_FLT_EQUAL( 0.2, SUM( 0.1, 0.1));
            UT_ASSERT_FLT_EQUAL( 0.0, SUM(-0.1, 0.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(dif) {
            UT_ASSERT_NUM_EQUAL( 0, DIF( 1, 1));
            UT_ASSERT_NUM_EQUAL(-2, DIF(-1, 1));

            UT_ASSERT_FLT_EQUAL( 0.0, DIF( 0.1, 0.1));
            UT_ASSERT_FLT_EQUAL(-0.2, DIF(-0.1, 0.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(mul) {
            UT_ASSERT_NUM_EQUAL( 1, MUL( 1, 1));
            UT_ASSERT_NUM_EQUAL(-1, MUL(-1, 1));

            UT_ASSERT_FLT_EQUAL( 0.01, MUL( 0.1, 0.1));
            UT_ASSERT_FLT_EQUAL(-0.01, MUL(-0.1, 0.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(div) {
            UT_ASSERT_NUM_EQUAL( 2, DIV(5, 2));
            UT_ASSERT_NUM_EQUAL(-2, DIV(5,-2));
            UT_ASSERT_NUM_EQUAL( 3, DIV(6, 2));
            UT_ASSERT_NUM_EQUAL(-3, DIV(6,-2));

            UT_ASSERT_NUM_EQUAL(-2, DIV(-5,2));
            UT_ASSERT_NUM_EQUAL(-3, DIV(-6,2));

            UT_ASSERT_NUM_EQUAL( 13, DIV(4.0, 0.3));
            UT_ASSERT_NUM_EQUAL(-13, DIV(4.0,-0.3));
        } UT_GROUP_END;

        UT_GROUP_BEG(mod) {
            UT_ASSERT_NUM_EQUAL(   1, MOD( 4,  3));
            UT_ASSERT_NUM_EQUAL(   1, MOD( 5,  2));
            UT_ASSERT_NUM_EQUAL(   1, MOD( 5, -2));
            UT_ASSERT_NUM_EQUAL(   0, MOD( 6,  2));
            UT_ASSERT_NUM_EQUAL(   0, MOD( 6, -2));

            UT_ASSERT_NUM_EQUAL(  -1, MOD(-5,  2));
            UT_ASSERT_NUM_EQUAL(   0, MOD(-6,  2));

            UT_ASSERT_FLT_EQUAL( 0.1, MOD( 4.0, 0.3));
            UT_ASSERT_FLT_EQUAL( 0.1, MOD( 4.0,-0.3));
            UT_ASSERT_FLT_EQUAL(-0.1, MOD(-4.0, 0.3));
            UT_ASSERT_FLT_EQUAL(-0.1, MOD(-4.0,-0.3));
        } UT_GROUP_END;

        UT_GROUP_BEG(div_mod) {
#define DIV_MOD(x, y) ((y) * DIV(x, y) + MOD(x, y)) == (x)
            UT_ASSERT_BOOL_TRUE(DIV_MOD(5, 2));
            UT_ASSERT_BOOL_TRUE(DIV_MOD(5,-2));
            UT_ASSERT_BOOL_TRUE(DIV_MOD(6, 2));
            UT_ASSERT_BOOL_TRUE(DIV_MOD(6,-2));

            UT_ASSERT_BOOL_TRUE(DIV_MOD(-5, 2));
            UT_ASSERT_BOOL_TRUE(DIV_MOD(-6, 2));

            UT_ASSERT_BOOL_TRUE(DIV_MOD( 4.0, 0.3));
            UT_ASSERT_BOOL_TRUE(DIV_MOD( 4.0,-0.3));
            UT_ASSERT_BOOL_TRUE(DIV_MOD(-4.0, 0.3));
            UT_ASSERT_BOOL_TRUE(DIV_MOD(-4.0,-0.3));
        } UT_GROUP_END;

        UT_GROUP_BEG(qut) {
            UT_ASSERT_FLT_EQUAL( 0.3333333333333333, QUT( 1.0,  3.0));
            UT_ASSERT_FLT_EQUAL( 1.3333333333333333, QUT( 4.0,  3.0));
            UT_ASSERT_FLT_EQUAL( 1.25, QUT( 5.0,  4.0));
            UT_ASSERT_FLT_EQUAL( 1.0, QUT( 5.0,  5.0));
            UT_ASSERT_FLT_EQUAL( 0.0, QUT( 0.0,  5.0));
            UT_ASSERT_FLT_EQUAL( INFINITY, QUT( 5.0,  0.0));

            UT_ASSERT_FLT_EQUAL( -0.3333333333333333, QUT( -1.0,  3.0));
            UT_ASSERT_FLT_EQUAL( -1.3333333333333333, QUT( -4.0,  3.0));
            UT_ASSERT_FLT_EQUAL( -1.25, QUT( -5.0,  4.0));
            UT_ASSERT_FLT_EQUAL( -1.0, QUT( -5.0,  5.0));
            UT_ASSERT_FLT_EQUAL( -0.0, QUT( -0.0,  5.0));
            UT_ASSERT_FLT_EQUAL( -INFINITY, QUT( -5.0,  0.0));
        } UT_GROUP_END;

        UT_GROUP_BEG(pow) {
            UT_ASSERT_FLT_EQUAL(8.0, POW( 2.0,  3.0));
            UT_ASSERT_FLT_EQUAL(3.0, POW( 9.0,  0.5));
            UT_ASSERT_FLT_EQUAL(0.33333333333333333, POW( 9.0, -0.5));
        } UT_GROUP_END;

        UT_GROUP_BEG(rot) {
            UT_ASSERT_FLT_EQUAL(4.0, ROT(16.0,  2.0));
            UT_ASSERT_FLT_EQUAL(2.0, ROT( 8.0,  3.0));
            UT_ASSERT_FLT_EQUAL(9.0, ROT( 3.0,  0.5));
            UT_ASSERT_NFLT_EQUAL(9.0, ROT( 0.33333333333333333333333, -0.5), 0.00000000000001);
        } UT_GROUP_END;

        UT_GROUP_BEG(log) {
            UT_ASSERT_FLT_EQUAL(3.0, LOG(8.0 , 2.0 ));
            UT_ASSERT_FLT_EQUAL(2.0, LOG(9.0 , 3.0));
            UT_ASSERT_FLT_EQUAL(0.33333333333333333, LOG( 9.0, -0.5));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_int) {
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_INT(0.9));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_INT(1.0));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_INT(1.1));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_INT(1.49));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_INT(1.50));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_INT(1.51));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_INT(1.9));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_INT(2.1));

            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_INT(-0.9));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_INT(-1.0));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_INT(-1.1));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_INT(-1.49));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_INT(-1.50));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_INT(-1.51));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_INT(-1.9));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_INT(-2.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_up) {
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_UP(0.9));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_UP(1.0));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_UP(1.1));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_UP(1.49));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_UP(1.50));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_UP(1.51));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_UP(1.9));
            UT_ASSERT_FLT_EQUAL( 3.0, ROUND_UP(2.1));

            UT_ASSERT_FLT_EQUAL(-0.0, ROUND_UP(-0.9));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_UP(-1.0));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_UP(-1.1));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_UP(-1.49));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_UP(-1.50));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_UP(-1.51));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_UP(-1.9));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_UP(-2.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_dn) {
            UT_ASSERT_FLT_EQUAL( 0.0, ROUND_DN(0.9));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_DN(1.0));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_DN(1.1));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_DN(1.49));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_DN(1.50));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_DN(1.51));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_DN(1.9));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_DN(2.1));

            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_DN(-0.9));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_DN(-1.0));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_DN(-1.1));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_DN(-1.49));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_DN(-1.50));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_DN(-1.51));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_DN(-1.9));
            UT_ASSERT_FLT_EQUAL(-3.0, ROUND_DN(-2.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_zero) {
            UT_ASSERT_FLT_EQUAL( 0.0, ROUND_ZERO(0.9));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_ZERO(1.0));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_ZERO(1.1));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_ZERO(1.49));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_ZERO(1.50));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_ZERO(1.51));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_ZERO(1.9));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_ZERO(2.1));

            UT_ASSERT_FLT_EQUAL(-0.0, ROUND_ZERO(-0.9));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_ZERO(-1.0));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_ZERO(-1.1));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_ZERO(-1.49));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_ZERO(-1.50));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_ZERO(-1.51));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_ZERO(-1.9));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_ZERO(-2.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_inf) {
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_INF(0.9));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_INF(1.0));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_INF(1.1));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_INF(1.49));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_INF(1.50));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_INF(1.51));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_INF(1.9));
            UT_ASSERT_FLT_EQUAL( 3.0, ROUND_INF(2.1));

            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_INF(-0.9));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_INF(-1.0));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_INF(-1.1));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_INF(-1.49));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_INF(-1.50));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_INF(-1.51));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_INF(-1.9));
            UT_ASSERT_FLT_EQUAL(-3.0, ROUND_INF(-2.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_math_eps) {
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_INT_EPS( 0.9 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_INT_EPS( 1.0 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_INT_EPS( 1.1 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, ROUND_INT_EPS( 1.49, 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, ROUND_INT_EPS( 1.50, 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, ROUND_INT_EPS( 1.51, 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_INT_EPS( 1.9 , 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_INT_EPS( 2.1 , 0.5));

            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_INT_EPS(-0.9 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_INT_EPS(-1.0 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_INT_EPS(-1.1 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, ROUND_INT_EPS(-1.49, 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, ROUND_INT_EPS(-1.50, 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, ROUND_INT_EPS(-1.51, 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_INT_EPS(-1.9 , 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_INT_EPS(-2.1 , 0.5));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_up_eps) {
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_UP_EPS( 0.9 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_UP_EPS( 1.0 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, ROUND_UP_EPS( 1.1 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, ROUND_UP_EPS( 1.49, 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, ROUND_UP_EPS( 1.50, 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_UP_EPS( 1.51, 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_UP_EPS( 1.9 , 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_UP_EPS( 2.0 , 0.5));
            UT_ASSERT_FLT_EQUAL( 2.5, ROUND_UP_EPS( 2.1 , 0.5));

            UT_ASSERT_FLT_EQUAL(-0.5, ROUND_UP_EPS(-0.9 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_UP_EPS(-1.0 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_UP_EPS(-1.1 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_UP_EPS(-1.49, 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, ROUND_UP_EPS(-1.50, 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, ROUND_UP_EPS(-1.51, 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, ROUND_UP_EPS(-1.9 , 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_UP_EPS(-2.0 , 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_UP_EPS(-2.1 , 0.5));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_dn_eps) {
            UT_ASSERT_FLT_EQUAL( 0.5, ROUND_DN_EPS( 0.9 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_DN_EPS( 1.0 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_DN_EPS( 1.1 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_DN_EPS( 1.49, 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, ROUND_DN_EPS( 1.50, 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, ROUND_DN_EPS( 1.51, 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, ROUND_DN_EPS( 1.9 , 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_DN_EPS( 2.0 , 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_DN_EPS( 2.1 , 0.5));

            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_DN_EPS(-0.9 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_DN_EPS(-1.0 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, ROUND_DN_EPS(-1.1 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, ROUND_DN_EPS(-1.49, 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, ROUND_DN_EPS(-1.50, 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_DN_EPS(-1.51, 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_DN_EPS(-1.9 , 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_DN_EPS(-2.0 , 0.5));
            UT_ASSERT_FLT_EQUAL(-2.5, ROUND_DN_EPS(-2.1 , 0.5));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_zero_eps) {
            UT_ASSERT_FLT_EQUAL( 0.5, ROUND_ZERO_EPS( 0.9 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_ZERO_EPS( 1.0 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_ZERO_EPS( 1.1 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_ZERO_EPS( 1.49, 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, ROUND_ZERO_EPS( 1.50, 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, ROUND_ZERO_EPS( 1.51, 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, ROUND_ZERO_EPS( 1.9 , 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_ZERO_EPS( 2.0 , 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_ZERO_EPS( 2.1 , 0.5));

            UT_ASSERT_FLT_EQUAL(-0.5, ROUND_ZERO_EPS(-0.9 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_ZERO_EPS(-1.0 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_ZERO_EPS(-1.1 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_ZERO_EPS(-1.49, 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, ROUND_ZERO_EPS(-1.50, 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, ROUND_ZERO_EPS(-1.51, 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, ROUND_ZERO_EPS(-1.9 , 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_ZERO_EPS(-2.0 , 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_ZERO_EPS(-2.1 , 0.5));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_inf_eps) {
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_INF_EPS( 0.9 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.0, ROUND_INF_EPS( 1.0 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, ROUND_INF_EPS( 1.1 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, ROUND_INF_EPS( 1.49, 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, ROUND_INF_EPS( 1.50, 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_INF_EPS( 1.51, 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_INF_EPS( 1.9 , 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, ROUND_INF_EPS( 2.0 , 0.5));
            UT_ASSERT_FLT_EQUAL( 2.5, ROUND_INF_EPS( 2.1 , 0.5));

            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_INF_EPS(-0.9 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.0, ROUND_INF_EPS(-1.0 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, ROUND_INF_EPS(-1.1 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, ROUND_INF_EPS(-1.49, 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, ROUND_INF_EPS(-1.50, 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_INF_EPS(-1.51, 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_INF_EPS(-1.9 , 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, ROUND_INF_EPS(-2.0 , 0.5));
            UT_ASSERT_FLT_EQUAL(-2.5, ROUND_INF_EPS(-2.1 , 0.5));
        } UT_GROUP_END;

        UT_GROUP_BEG(min) {
            UT_ASSERT_NUM_EQUAL(  1, MIN( 1, 2));
            UT_ASSERT_NUM_EQUAL( -2, MIN(-1,-2));
        } UT_GROUP_END;

        UT_GROUP_BEG(max) {
            UT_ASSERT_NUM_EQUAL(  2, MAX( 1, 2));
            UT_ASSERT_NUM_EQUAL( -1, MAX(-1,-2));
        } UT_GROUP_END;

        UT_GROUP_BEG(min_not_zero) {
            UT_ASSERT_NUM_EQUAL(  1, MIN_NOT_ZERO( 1, 2));
            UT_ASSERT_NUM_EQUAL( -2, MIN_NOT_ZERO(-1,-2));

            UT_ASSERT_NUM_EQUAL(  1, MIN_NOT_ZERO( 1, 0));
            UT_ASSERT_NUM_EQUAL( -1, MIN_NOT_ZERO(-1, 0));
        } UT_GROUP_END;

        UT_GROUP_BEG(max_not_zero) {
            UT_ASSERT_NUM_EQUAL(  2, MAX_NOT_ZERO( 1, 2));
            UT_ASSERT_NUM_EQUAL( -1, MAX_NOT_ZERO(-1,-2));

            UT_ASSERT_NUM_EQUAL(  1, MAX_NOT_ZERO( 1, 0));
            UT_ASSERT_NUM_EQUAL( -1, MAX_NOT_ZERO(-1, 0));
        } UT_GROUP_END;

        UT_GROUP_BEG(minmax) {
            int min =  10;
            int max = -10;
            UT_ASSERT_NUM_EQUAL( 10, min);
            UT_ASSERT_NUM_EQUAL(-10, max);
            MINMAX_SET(min, max, 0);
            UT_ASSERT_NUM_EQUAL(  0, min);
            UT_ASSERT_NUM_EQUAL(  0, max);
            MINMAX_SET(min, max, 10);
            UT_ASSERT_NUM_EQUAL(  0, min);
            UT_ASSERT_NUM_EQUAL( 10, max);
            MINMAX_SET(min, max, -10);
            UT_ASSERT_NUM_EQUAL(-10, min);
            UT_ASSERT_NUM_EQUAL( 10, max);
        } UT_GROUP_END;

        UT_GROUP_BEG(minmax_not_zero) {
            int min =  10;
            int max = -10;
            UT_ASSERT_NUM_EQUAL( 10, min);
            UT_ASSERT_NUM_EQUAL(-10, max);
            MINMAX_NOT_ZERO_SET(min, max, 0);
            UT_ASSERT_NUM_EQUAL( 10, min);
            UT_ASSERT_NUM_EQUAL(-10, max);
            MINMAX_NOT_ZERO_SET(min, max, 10);
            UT_ASSERT_NUM_EQUAL( 10, min);
            UT_ASSERT_NUM_EQUAL( 10, max);
            MINMAX_NOT_ZERO_SET(min, max, -10);
            UT_ASSERT_NUM_EQUAL(-10, min);
            UT_ASSERT_NUM_EQUAL( 10, max);
        } UT_GROUP_END;
    } UT_GROUP_END;
}
