//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_compare) {
    UT_GROUP_BEG(compare) {
        UT_GROUP_BEG(eq) {
            UT_ASSERT_BOOL_TR(eq(      1,      1));
            UT_ASSERT_BOOL_TR(eq(    1.0,    1.0));
            UT_ASSERT_BOOL_TR(eq( 1.0+1I, 1.0+1I));

            UT_ASSERT_BOOL_FL(eq(      1,      2));
            UT_ASSERT_BOOL_FL(eq(    1.0,    1.2));
            UT_ASSERT_BOOL_FL(eq( 1.0+1I, 1.0+2I));
        }UT_GROUP_END;


        UT_GROUP_BEG(nq) {
            UT_ASSERT_BOOL_TR(nq(      1,      2));
            UT_ASSERT_BOOL_TR(nq(    1.0,    2.0));
            UT_ASSERT_BOOL_TR(nq( 1.0+1I, 1.0+2I));

            UT_ASSERT_BOOL_FL(nq(      1,      1));
            UT_ASSERT_BOOL_FL(nq(    1.0,    1.0));
            UT_ASSERT_BOOL_FL(nq( 1.0+1I, 1.0+1I));
        }UT_GROUP_END;


        UT_GROUP_BEG(gt) {
            UT_ASSERT_BOOL_TR(gt(  2,   1));
            UT_ASSERT_BOOL_TR(gt(2.0, 1.0));
        }UT_GROUP_END;


        UT_GROUP_BEG(lt) {
            UT_ASSERT_BOOL_TR(lt(  1,   2));
            UT_ASSERT_BOOL_TR(lt(1.0, 2.0));
        }UT_GROUP_END;


        UT_GROUP_BEG(ge) {
            UT_ASSERT_BOOL_TR(ge(  2,   1));
            UT_ASSERT_BOOL_TR(ge(  2,   2));

            UT_ASSERT_BOOL_TR(ge(2.0, 1.0));
            UT_ASSERT_BOOL_TR(ge(2.0, 2.0));
        }UT_GROUP_END;


        UT_GROUP_BEG(le) {
            UT_ASSERT_BOOL_TR(le(  1,   2));
            UT_ASSERT_BOOL_TR(le(  1,   1));

            UT_ASSERT_BOOL_TR(le(1.0, 2.0));
            UT_ASSERT_BOOL_TR(le(1.0, 1.0));
        }UT_GROUP_END;


        UT_GROUP_BEG(ap) {
            UT_ASSERT_BOOL_TR(ap(   1,   1,  0));
            UT_ASSERT_BOOL_TR(ap(   9,  10,  1));
            UT_ASSERT_BOOL_TR(ap(  90, 100, 10));
            UT_ASSERT_BOOL_TR(ap(-100, -90, 10));

            UT_ASSERT_BOOL_FL(ap(  1,   2,  0));
            UT_ASSERT_BOOL_FL(ap(100, -90, 10));

            UT_ASSERT_BOOL_TR(ap(   1.0,   1.0,  0.0));
            UT_ASSERT_BOOL_TR(ap(   9.0,  10.0,  1.0));
            UT_ASSERT_BOOL_TR(ap(  90.0, 100.0, 10.0));
            UT_ASSERT_BOOL_TR(ap(-100.0, -90.0, 10.0));

            UT_ASSERT_BOOL_FL(ap(  1.0,   2.0,  0.0));
            UT_ASSERT_BOOL_FL(ap(100.0, -90.0, 10.0));
        }UT_GROUP_END;
    }UT_GROUP_END;
}
