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
            UT_GROUP_BEG(value&address) {
                init_val(A, int);
                init_val(B, char);
                UT_ASSERT_NUM_EQUAL(0, A);
                UT_ASSERT_CHAR_EQUAL( (char)'\0', B);

                init_ptr(a, int);
                init_ptr(b, char);
                UT_ASSERT_TYPE_EQUAL((int*){0}, a);
                UT_ASSERT_TYPE_EQUAL((char*){'\0'}, b);
                UT_ASSERT_PTR_EQUAL(NULL, a);
                UT_ASSERT_PTR_EQUAL(NULL, b);

                crete_val(i, 1.0);
                UT_ASSERT_FLT_EQUAL(1.0, i);
                UT_ASSERT_TYPE_EQUAL( (double){0}, i);

                crete_ptr(p, i);
                UT_ASSERT_PTR_EQUAL(p, &i);
                UT_ASSERT_TYPE_EQUAL( (double*){0}, p);


            } UT_GROUP_END;

            UT_GROUP_BEG(as) {
                int x = 1;
                double y = 2.5;
                UT_ASSERT_FLT_EQUAL(2.5, y);

                UT_ASSERT_NUM_EQUAL(  1, x);
                as(x, (int)(y));
                UT_ASSERT_NUM_EQUAL(  2, x);
            } UT_GROUP_END;

            UT_GROUP_BEG(swap) {
                int A =  10;
                int B = -10;
                UT_ASSERT_NUM_EQUAL( 10, A);
                UT_ASSERT_NUM_EQUAL(-10, B);
                swap(A, B);
                UT_ASSERT_NUM_EQUAL(-10, A);
                UT_ASSERT_NUM_EQUAL( 10, B);
            } UT_GROUP_END;


            UT_GROUP_BEG(eq) {
                UT_ASSERT_BOOL_TRUE(eq(1, 1));
            }UT_GROUP_END;

            UT_GROUP_BEG(nq) {
                UT_ASSERT_BOOL_TRUE(nq(1, 2));
            }UT_GROUP_END;

            UT_GROUP_BEG(gt) {
                UT_ASSERT_BOOL_TRUE(gt(2, 1));
            }UT_GROUP_END;

            UT_GROUP_BEG(lt) {
                UT_ASSERT_BOOL_TRUE(lt(1, 2));
            }UT_GROUP_END;

            UT_GROUP_BEG(ge) {
                UT_ASSERT_BOOL_TRUE(ge(2, 1));
                UT_ASSERT_BOOL_TRUE(ge(2, 2));
            }UT_GROUP_END;

            UT_GROUP_BEG(le) {
                UT_ASSERT_BOOL_TRUE(le(1, 2));
                UT_ASSERT_BOOL_TRUE(le(1, 1));
            }UT_GROUP_END;

            UT_GROUP_BEG(ap) {
                UT_ASSERT_BOOL_TRUE(ap(   1,   1,  0));
                UT_ASSERT_BOOL_TRUE(ap(   9,  10,  1));
                UT_ASSERT_BOOL_TRUE(ap(  90, 100, 10));
                UT_ASSERT_BOOL_TRUE(ap(-100, -90, 10));

                UT_ASSERT_BOOL_FALSE(ap(  1,   2,  0));
                UT_ASSERT_BOOL_FALSE(ap(100, -90, 10));
            }UT_GROUP_END;

            UT_GROUP_BEG(get_int) {
                UT_ASSERT_NUM_EQUAL(   2, get_int(   2));
                UT_ASSERT_NUM_EQUAL(  -2, get_int(  -2));

                UT_ASSERT_FLT_EQUAL( 2.0, get_int( 2.1));
                UT_ASSERT_FLT_EQUAL(-2.0, get_int(-2.1));
                UT_ASSERT_FLT_EQUAL( 2.0, get_int( 2.0));
                UT_ASSERT_FLT_EQUAL(-2.0, get_int(-2.0));
                UT_ASSERT_FLT_EQUAL( 1.0, get_int( 1.9));
                UT_ASSERT_FLT_EQUAL(-1.0, get_int(-1.9));
                UT_ASSERT_FLT_EQUAL( 1.0, get_int( 1.1));
                UT_ASSERT_FLT_EQUAL(-1.0, get_int(-1.1));
            }UT_GROUP_END;

            UT_GROUP_BEG(get_rem) {
                UT_ASSERT_NUM_EQUAL(   0, get_rem(   2));
                UT_ASSERT_NUM_EQUAL(  -0, get_rem(  -2));

                UT_ASSERT_FLT_EQUAL( 0.1, get_rem( 2.1));
                UT_ASSERT_FLT_EQUAL(-0.1, get_rem(-2.1));
                UT_ASSERT_FLT_EQUAL( 0.0, get_rem( 2.0));
                UT_ASSERT_FLT_EQUAL( 0.0, get_rem(-2.0));
                UT_ASSERT_FLT_EQUAL( 0.9, get_rem( 1.9));
                UT_ASSERT_FLT_EQUAL(-0.9, get_rem(-1.9));
                UT_ASSERT_FLT_EQUAL( 0.1, get_rem( 1.1));
                UT_ASSERT_FLT_EQUAL(-0.1, get_rem(-1.1));
            }UT_GROUP_END;
        }UT_GROUP_END;

        UT_GROUP_BEG(sig) {
            UT_ASSERT_NUM_EQUAL( +1, sig(i_8_c(   1)));
            UT_ASSERT_NUM_EQUAL( +1, sig(i_8_c(   2)));
            UT_ASSERT_NUM_EQUAL( -1, sig(i_8_c(  -1)));
            UT_ASSERT_NUM_EQUAL( -1, sig(i_8_c(  -2)));
            UT_ASSERT_NUM_EQUAL(  0, sig(i_8_c(   0)));
            UT_ASSERT_NUM_EQUAL(  0, sig( 0.0));
            UT_ASSERT_NUM_EQUAL(  1, sig( 0.1));
            UT_ASSERT_NUM_EQUAL( -1, sig(-0.1));

            UT_ASSERT_BOOL(sig(2) == sig(2));

            int a = -1;
            UT_ASSERT_NUM_EQUAL( -1, sig(a));
            UT_ASSERT_NUM_EQUAL( -1, a);
            UT_ASSERT_NUM_EQUAL( -1, sig(a++));
            UT_ASSERT_NUM_EQUAL(  0, a);

            a = -1;
            UT_ASSERT_NUM_EQUAL( -1, sig(a));
            UT_ASSERT_NUM_EQUAL( -1, a);
            UT_ASSERT_NUM_EQUAL( -1, sig(a--));
            UT_ASSERT_NUM_EQUAL( -2, a);
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


        UT_GROUP_BEG(is_pos) {
            UT_ASSERT_BOOL_FALSE(is_pos(+0.0));
            UT_ASSERT_BOOL_FALSE(is_pos(   0));
            UT_ASSERT_BOOL_FALSE(is_pos(  -1));
            UT_ASSERT_BOOL_FALSE(is_pos(-1.1));

            UT_ASSERT_BOOL_TRUE(is_pos(  +1));
            UT_ASSERT_BOOL_TRUE(is_pos(+1.0));
        } UT_GROUP_END;

        UT_GROUP_BEG(is_neg) {
            UT_ASSERT_BOOL_FALSE(is_neg(-0.0));
            UT_ASSERT_BOOL_FALSE(is_neg(   0));
            UT_ASSERT_BOOL_FALSE(is_neg(   1));
            UT_ASSERT_BOOL_FALSE(is_neg( 1.1));

            UT_ASSERT_BOOL_TRUE(is_neg(  -1));
            UT_ASSERT_BOOL_TRUE(is_neg(-1.0));
        } UT_GROUP_END;

        UT_GROUP_BEG(is_zero) {
            UT_ASSERT_BOOL_TRUE(is_zero(+0.0));
            UT_ASSERT_BOOL_TRUE(is_zero(-0.0));
            UT_ASSERT_BOOL_TRUE(is_zero(   0));

            UT_ASSERT_BOOL_FALSE(is_zero( 1));
            UT_ASSERT_BOOL_FALSE(is_zero(-1));
        } UT_GROUP_END;

        UT_GROUP_BEG(is_pos_or_zero) {
            UT_ASSERT_BOOL_FALSE(is_pos_or_zero(  -1));
            UT_ASSERT_BOOL_FALSE(is_pos_or_zero(-1.1));

            UT_ASSERT_BOOL_TRUE(is_pos_or_zero(+0.0));
            UT_ASSERT_BOOL_TRUE(is_pos_or_zero(   0));
            UT_ASSERT_BOOL_TRUE(is_pos_or_zero(  +1));
            UT_ASSERT_BOOL_TRUE(is_pos_or_zero(+1.0));
        } UT_GROUP_END;

        UT_GROUP_BEG(is_neg_or_zero) {
            UT_ASSERT_BOOL_FALSE(is_neg_or_zero(   1));
            UT_ASSERT_BOOL_FALSE(is_neg_or_zero( 1.1));

            UT_ASSERT_BOOL_TRUE(is_neg_or_zero(-0.0));
            UT_ASSERT_BOOL_TRUE(is_neg_or_zero(   0));
            UT_ASSERT_BOOL_TRUE(is_neg_or_zero(  -1));
            UT_ASSERT_BOOL_TRUE(is_neg_or_zero(-1.0));
        } UT_GROUP_END;



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

            UT_ASSERT_NUM_EQUAL( 13, div(4.0, 0.3));
            UT_ASSERT_NUM_EQUAL(-13, div(4.0,-0.3));
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
#define DIV_MOD(x, y) ((y) * div(x, y) + mod(x, y)) == (x)
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
            UT_ASSERT_FLT_EQUAL(8.0, pow( 2.0,  3.0));
            UT_ASSERT_FLT_EQUAL(3.0, pow( 9.0,  0.5));
            UT_ASSERT_FLT_EQUAL(0.33333333333333333, pow( 9.0, -0.5));
        } UT_GROUP_END;

        UT_GROUP_BEG(rot) {
            UT_ASSERT_FLT_EQUAL(4.0, rot(16.0,  2.0));
            UT_ASSERT_FLT_EQUAL(2.0, rot( 8.0,  3.0));
            UT_ASSERT_FLT_EQUAL(9.0, rot( 3.0,  0.5));
            UT_ASSERT_NFLT_EQUAL(9.0, rot( 0.33333333333333333333333, -0.5), 0.00000000000001);
        } UT_GROUP_END;

        UT_GROUP_BEG(log) {
            UT_ASSERT_FLT_EQUAL(3.0, log(8.0 , 2.0 ));
            UT_ASSERT_FLT_EQUAL(2.0, log(9.0 , 3.0));
            UT_ASSERT_FLT_EQUAL(0.33333333333333333, log( 9.0, -0.5));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_int) {
            UT_ASSERT_FLT_EQUAL( 1.0, round_int(0.9));
            UT_ASSERT_FLT_EQUAL( 1.0, round_int(1.0));
            UT_ASSERT_FLT_EQUAL( 1.0, round_int(1.1));
            UT_ASSERT_FLT_EQUAL( 1.0, round_int(1.49));
            UT_ASSERT_FLT_EQUAL( 2.0, round_int(1.50));
            UT_ASSERT_FLT_EQUAL( 2.0, round_int(1.51));
            UT_ASSERT_FLT_EQUAL( 2.0, round_int(1.9));
            UT_ASSERT_FLT_EQUAL( 2.0, round_int(2.1));

            UT_ASSERT_FLT_EQUAL(-1.0, round_int(-0.9));
            UT_ASSERT_FLT_EQUAL(-1.0, round_int(-1.0));
            UT_ASSERT_FLT_EQUAL(-1.0, round_int(-1.1));
            UT_ASSERT_FLT_EQUAL(-1.0, round_int(-1.49));
            UT_ASSERT_FLT_EQUAL(-2.0, round_int(-1.50));
            UT_ASSERT_FLT_EQUAL(-2.0, round_int(-1.51));
            UT_ASSERT_FLT_EQUAL(-2.0, round_int(-1.9));
            UT_ASSERT_FLT_EQUAL(-2.0, round_int(-2.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_up) {
            UT_ASSERT_FLT_EQUAL( 1.0, round_up(0.9));
            UT_ASSERT_FLT_EQUAL( 1.0, round_up(1.0));
            UT_ASSERT_FLT_EQUAL( 2.0, round_up(1.1));
            UT_ASSERT_FLT_EQUAL( 2.0, round_up(1.49));
            UT_ASSERT_FLT_EQUAL( 2.0, round_up(1.50));
            UT_ASSERT_FLT_EQUAL( 2.0, round_up(1.51));
            UT_ASSERT_FLT_EQUAL( 2.0, round_up(1.9));
            UT_ASSERT_FLT_EQUAL( 3.0, round_up(2.1));

            UT_ASSERT_FLT_EQUAL(-0.0, round_up(-0.9));
            UT_ASSERT_FLT_EQUAL(-1.0, round_up(-1.0));
            UT_ASSERT_FLT_EQUAL(-1.0, round_up(-1.1));
            UT_ASSERT_FLT_EQUAL(-1.0, round_up(-1.49));
            UT_ASSERT_FLT_EQUAL(-1.0, round_up(-1.50));
            UT_ASSERT_FLT_EQUAL(-1.0, round_up(-1.51));
            UT_ASSERT_FLT_EQUAL(-1.0, round_up(-1.9));
            UT_ASSERT_FLT_EQUAL(-2.0, round_up(-2.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_dn) {
            UT_ASSERT_FLT_EQUAL( 0.0, round_dn(0.9));
            UT_ASSERT_FLT_EQUAL( 1.0, round_dn(1.0));
            UT_ASSERT_FLT_EQUAL( 1.0, round_dn(1.1));
            UT_ASSERT_FLT_EQUAL( 1.0, round_dn(1.49));
            UT_ASSERT_FLT_EQUAL( 1.0, round_dn(1.50));
            UT_ASSERT_FLT_EQUAL( 1.0, round_dn(1.51));
            UT_ASSERT_FLT_EQUAL( 1.0, round_dn(1.9));
            UT_ASSERT_FLT_EQUAL( 2.0, round_dn(2.1));

            UT_ASSERT_FLT_EQUAL(-1.0, round_dn(-0.9));
            UT_ASSERT_FLT_EQUAL(-1.0, round_dn(-1.0));
            UT_ASSERT_FLT_EQUAL(-2.0, round_dn(-1.1));
            UT_ASSERT_FLT_EQUAL(-2.0, round_dn(-1.49));
            UT_ASSERT_FLT_EQUAL(-2.0, round_dn(-1.50));
            UT_ASSERT_FLT_EQUAL(-2.0, round_dn(-1.51));
            UT_ASSERT_FLT_EQUAL(-2.0, round_dn(-1.9));
            UT_ASSERT_FLT_EQUAL(-3.0, round_dn(-2.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_zero) {
            UT_ASSERT_FLT_EQUAL( 0.0, round_zero(0.9));
            UT_ASSERT_FLT_EQUAL( 1.0, round_zero(1.0));
            UT_ASSERT_FLT_EQUAL( 1.0, round_zero(1.1));
            UT_ASSERT_FLT_EQUAL( 1.0, round_zero(1.49));
            UT_ASSERT_FLT_EQUAL( 1.0, round_zero(1.50));
            UT_ASSERT_FLT_EQUAL( 1.0, round_zero(1.51));
            UT_ASSERT_FLT_EQUAL( 1.0, round_zero(1.9));
            UT_ASSERT_FLT_EQUAL( 2.0, round_zero(2.1));

            UT_ASSERT_FLT_EQUAL(-0.0, round_zero(-0.9));
            UT_ASSERT_FLT_EQUAL(-1.0, round_zero(-1.0));
            UT_ASSERT_FLT_EQUAL(-1.0, round_zero(-1.1));
            UT_ASSERT_FLT_EQUAL(-1.0, round_zero(-1.49));
            UT_ASSERT_FLT_EQUAL(-1.0, round_zero(-1.50));
            UT_ASSERT_FLT_EQUAL(-1.0, round_zero(-1.51));
            UT_ASSERT_FLT_EQUAL(-1.0, round_zero(-1.9));
            UT_ASSERT_FLT_EQUAL(-2.0, round_zero(-2.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_inf) {
            UT_ASSERT_FLT_EQUAL( 1.0, round_inf(0.9));
            UT_ASSERT_FLT_EQUAL( 1.0, round_inf(1.0));
            UT_ASSERT_FLT_EQUAL( 2.0, round_inf(1.1));
            UT_ASSERT_FLT_EQUAL( 2.0, round_inf(1.49));
            UT_ASSERT_FLT_EQUAL( 2.0, round_inf(1.50));
            UT_ASSERT_FLT_EQUAL( 2.0, round_inf(1.51));
            UT_ASSERT_FLT_EQUAL( 2.0, round_inf(1.9));
            UT_ASSERT_FLT_EQUAL( 3.0, round_inf(2.1));

            UT_ASSERT_FLT_EQUAL(-1.0, round_inf(-0.9));
            UT_ASSERT_FLT_EQUAL(-1.0, round_inf(-1.0));
            UT_ASSERT_FLT_EQUAL(-2.0, round_inf(-1.1));
            UT_ASSERT_FLT_EQUAL(-2.0, round_inf(-1.49));
            UT_ASSERT_FLT_EQUAL(-2.0, round_inf(-1.50));
            UT_ASSERT_FLT_EQUAL(-2.0, round_inf(-1.51));
            UT_ASSERT_FLT_EQUAL(-2.0, round_inf(-1.9));
            UT_ASSERT_FLT_EQUAL(-3.0, round_inf(-2.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_math_eps) {
            UT_ASSERT_FLT_EQUAL( 1.0, round_int_eps( 0.9 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.0, round_int_eps( 1.0 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.0, round_int_eps( 1.1 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, round_int_eps( 1.49, 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, round_int_eps( 1.50, 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, round_int_eps( 1.51, 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, round_int_eps( 1.9 , 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, round_int_eps( 2.1 , 0.5));

            UT_ASSERT_FLT_EQUAL(-1.0, round_int_eps(-0.9 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.0, round_int_eps(-1.0 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.0, round_int_eps(-1.1 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, round_int_eps(-1.49, 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, round_int_eps(-1.50, 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, round_int_eps(-1.51, 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, round_int_eps(-1.9 , 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, round_int_eps(-2.1 , 0.5));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_up_eps) {
            UT_ASSERT_FLT_EQUAL( 1.0, round_up_eps( 0.9 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.0, round_up_eps( 1.0 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, round_up_eps( 1.1 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, round_up_eps( 1.49, 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, round_up_eps( 1.50, 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, round_up_eps( 1.51, 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, round_up_eps( 1.9 , 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, round_up_eps( 2.0 , 0.5));
            UT_ASSERT_FLT_EQUAL( 2.5, round_up_eps( 2.1 , 0.5));

            UT_ASSERT_FLT_EQUAL(-0.5, round_up_eps(-0.9 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.0, round_up_eps(-1.0 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.0, round_up_eps(-1.1 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.0, round_up_eps(-1.49, 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, round_up_eps(-1.50, 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, round_up_eps(-1.51, 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, round_up_eps(-1.9 , 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, round_up_eps(-2.0 , 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, round_up_eps(-2.1 , 0.5));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_dn_eps) {
            UT_ASSERT_FLT_EQUAL( 0.5, round_dn_eps( 0.9 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.0, round_dn_eps( 1.0 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.0, round_dn_eps( 1.1 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.0, round_dn_eps( 1.49, 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, round_dn_eps( 1.50, 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, round_dn_eps( 1.51, 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, round_dn_eps( 1.9 , 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, round_dn_eps( 2.0 , 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, round_dn_eps( 2.1 , 0.5));

            UT_ASSERT_FLT_EQUAL(-1.0, round_dn_eps(-0.9 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.0, round_dn_eps(-1.0 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, round_dn_eps(-1.1 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, round_dn_eps(-1.49, 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, round_dn_eps(-1.50, 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, round_dn_eps(-1.51, 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, round_dn_eps(-1.9 , 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, round_dn_eps(-2.0 , 0.5));
            UT_ASSERT_FLT_EQUAL(-2.5, round_dn_eps(-2.1 , 0.5));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_zero_eps) {
            UT_ASSERT_FLT_EQUAL( 0.5, round_zero_eps( 0.9 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.0, round_zero_eps( 1.0 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.0, round_zero_eps( 1.1 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.0, round_zero_eps( 1.49, 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, round_zero_eps( 1.50, 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, round_zero_eps( 1.51, 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, round_zero_eps( 1.9 , 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, round_zero_eps( 2.0 , 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, round_zero_eps( 2.1 , 0.5));

            UT_ASSERT_FLT_EQUAL(-0.5, round_zero_eps(-0.9 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.0, round_zero_eps(-1.0 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.0, round_zero_eps(-1.1 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.0, round_zero_eps(-1.49, 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, round_zero_eps(-1.50, 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, round_zero_eps(-1.51, 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, round_zero_eps(-1.9 , 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, round_zero_eps(-2.0 , 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, round_zero_eps(-2.1 , 0.5));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_inf_eps) {
            UT_ASSERT_FLT_EQUAL( 1.0, round_inf_eps( 0.9 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.0, round_inf_eps( 1.0 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, round_inf_eps( 1.1 , 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, round_inf_eps( 1.49, 0.5));
            UT_ASSERT_FLT_EQUAL( 1.5, round_inf_eps( 1.50, 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, round_inf_eps( 1.51, 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, round_inf_eps( 1.9 , 0.5));
            UT_ASSERT_FLT_EQUAL( 2.0, round_inf_eps( 2.0 , 0.5));
            UT_ASSERT_FLT_EQUAL( 2.5, round_inf_eps( 2.1 , 0.5));

            UT_ASSERT_FLT_EQUAL(-1.0, round_inf_eps(-0.9 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.0, round_inf_eps(-1.0 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, round_inf_eps(-1.1 , 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, round_inf_eps(-1.49, 0.5));
            UT_ASSERT_FLT_EQUAL(-1.5, round_inf_eps(-1.50, 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, round_inf_eps(-1.51, 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, round_inf_eps(-1.9 , 0.5));
            UT_ASSERT_FLT_EQUAL(-2.0, round_inf_eps(-2.0 , 0.5));
            UT_ASSERT_FLT_EQUAL(-2.5, round_inf_eps(-2.1 , 0.5));
        } UT_GROUP_END;

        UT_GROUP_BEG(min) {
            UT_ASSERT_NUM_EQUAL(  1, min( 1, 2));
            UT_ASSERT_NUM_EQUAL( -2, min(-1,-2));
        } UT_GROUP_END;

        UT_GROUP_BEG(max) {
            UT_ASSERT_NUM_EQUAL(  2, max( 1, 2));
            UT_ASSERT_NUM_EQUAL( -1, max(-1,-2));
        } UT_GROUP_END;

        UT_GROUP_BEG(min_not_zero) {
            UT_ASSERT_NUM_EQUAL(  1, min_not_zero( 1, 2));
            UT_ASSERT_NUM_EQUAL( -2, min_not_zero(-1,-2));

            UT_ASSERT_NUM_EQUAL(  1, min_not_zero( 1, 0));
            UT_ASSERT_NUM_EQUAL( -1, min_not_zero(-1, 0));
        } UT_GROUP_END;

        UT_GROUP_BEG(max_not_zero) {
            UT_ASSERT_NUM_EQUAL(  2, max_not_zero( 1, 2));
            UT_ASSERT_NUM_EQUAL( -1, max_not_zero(-1,-2));

            UT_ASSERT_NUM_EQUAL(  1, max_not_zero( 1, 0));
            UT_ASSERT_NUM_EQUAL( -1, max_not_zero(-1, 0));
        } UT_GROUP_END;

        UT_GROUP_BEG(minmax) {
            int min =  10;
            int max = -10;
            UT_ASSERT_NUM_EQUAL( 10, min);
            UT_ASSERT_NUM_EQUAL(-10, max);
            minmax_set(min, max, 0);
            UT_ASSERT_NUM_EQUAL(  0, min);
            UT_ASSERT_NUM_EQUAL(  0, max);
            minmax_set(min, max, 10);
            UT_ASSERT_NUM_EQUAL(  0, min);
            UT_ASSERT_NUM_EQUAL( 10, max);
            minmax_set(min, max, -10);
            UT_ASSERT_NUM_EQUAL(-10, min);
            UT_ASSERT_NUM_EQUAL( 10, max);
        } UT_GROUP_END;

        UT_GROUP_BEG(minmax_not_zero) {
            int min =  10;
            int max = -10;
            UT_ASSERT_NUM_EQUAL( 10, min);
            UT_ASSERT_NUM_EQUAL(-10, max);
            minmax_not_zero_set(min, max, 0);
            UT_ASSERT_NUM_EQUAL( 10, min);
            UT_ASSERT_NUM_EQUAL(-10, max);
            minmax_not_zero_set(min, max, 10);
            UT_ASSERT_NUM_EQUAL( 10, min);
            UT_ASSERT_NUM_EQUAL( 10, max);
            minmax_not_zero_set(min, max, -10);
            UT_ASSERT_NUM_EQUAL(-10, min);
            UT_ASSERT_NUM_EQUAL( 10, max);
        } UT_GROUP_END;
    } UT_GROUP_END;
}
