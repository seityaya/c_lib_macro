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

            UT_GROUP_BEG(compare) {

            }UT_GROUP_END;

            UT_GROUP_BEG(compare) {

            }UT_GROUP_END;
        }UT_GROUP_END;


        UT_GROUP_BEG(sig) {
            UT_ASSERT_NUM_EQUAL( +1, SIG(i08c(   1)));
            UT_ASSERT_NUM_EQUAL( +1, SIG(i08c(   2)));
            UT_ASSERT_NUM_EQUAL( -1, SIG(i08c(  -1)));
            UT_ASSERT_NUM_EQUAL( -1, SIG(i08c(  -2)));
            UT_ASSERT_NUM_EQUAL(  0, SIG(i08c(   0)));
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
            UT_ASSERT_NUM_EQUAL( 1, MOD(5, 2));
            UT_ASSERT_NUM_EQUAL( 1, MOD(5,-2));
            UT_ASSERT_NUM_EQUAL( 0, MOD(6, 2));
            UT_ASSERT_NUM_EQUAL( 0, MOD(6,-2));

            UT_ASSERT_NUM_EQUAL(-1, MOD(-5,2));
            UT_ASSERT_NUM_EQUAL( 0, MOD(-6,2));

            //            UT_ASSERT_NUM_EQUAL( 13.0, MOD(4.0, 0.3));
            //            UT_ASSERT_NUM_EQUAL(-13.0, MOD(4.0,-0.3));

            //            UT_ASSERT_NUM_EQUAL(-13.0, 4 % 3);
        } UT_GROUP_END;

        UT_GROUP_BEG(div_mod) {
#define DIV_MOD(x, y) ((y) * DIV(x, y) + MOD(x, y)) == (x)
            UT_ASSERT_BOOL_TRUE(DIV_MOD(5, 2));
            UT_ASSERT_BOOL_TRUE(DIV_MOD(5,-2));
            UT_ASSERT_BOOL_TRUE(DIV_MOD(6, 2));
            UT_ASSERT_BOOL_TRUE(DIV_MOD(6,-2));

            UT_ASSERT_BOOL_TRUE(DIV_MOD(-5, 2));
            UT_ASSERT_BOOL_TRUE(DIV_MOD(-6, 2));

            //            UT_ASSERT_NUM_EQUAL( 13.0, DIV(4.0, 0.3));
            //            UT_ASSERT_NUM_EQUAL(-13.0, DIV(4.0,-0.3));
        } UT_GROUP_END;

    } UT_GROUP_END;
}
