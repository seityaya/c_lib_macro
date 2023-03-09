//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_unar) {
    UT_GROUP_BEG(unar) {
        int8_t x = 0;
        UT_ASSERT_NUM_EQUAL(  0, x);
        UT_ASSERT_NUM_EQUAL(  0, posadd(x));
        UT_ASSERT_NUM_EQUAL(  1, posadd(x));
        UT_ASSERT_NUM_EQUAL(  2, x);
        UT_ASSERT_NUM_EQUAL(  2, posdif(x));
        UT_ASSERT_NUM_EQUAL(  1, posdif(x));
        UT_ASSERT_NUM_EQUAL(  0, x);

        x = 0;
        UT_ASSERT_NUM_EQUAL(  0, x);
        UT_ASSERT_NUM_EQUAL(  1, sum(posadd(x), posadd(x)));
        UT_ASSERT_NUM_EQUAL(  5, sum(posadd(x), posadd(x)));
        UT_ASSERT_NUM_EQUAL(  4, x);
        UT_ASSERT_NUM_EQUAL(  7, sum(posdif(x), posdif(x)));
        UT_ASSERT_NUM_EQUAL(  3, sum(posdif(x), posdif(x)));
        UT_ASSERT_NUM_EQUAL(  0, x);

        x = 0;
        UT_ASSERT_NUM_EQUAL(  0, x);
        UT_ASSERT_NUM_EQUAL(  1, preadd(x));
        UT_ASSERT_NUM_EQUAL(  2, preadd(x));
        UT_ASSERT_NUM_EQUAL(  2, x);
        UT_ASSERT_NUM_EQUAL(  1, predif(x));
        UT_ASSERT_NUM_EQUAL(  0, predif(x));
        UT_ASSERT_NUM_EQUAL(  0, x);

        x = 0;
        UT_ASSERT_NUM_EQUAL(  0, x);
        UT_ASSERT_NUM_EQUAL(  3, sum(preadd(x), preadd(x)));
        UT_ASSERT_NUM_EQUAL(  7, sum(preadd(x), preadd(x)));
        UT_ASSERT_NUM_EQUAL(  4, x);
        UT_ASSERT_NUM_EQUAL(  5, sum(predif(x), predif(x)));
        UT_ASSERT_NUM_EQUAL(  1, sum(predif(x), predif(x)));
        UT_ASSERT_NUM_EQUAL(  0, x);
    }UT_GROUP_END;
}
