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
        UT_ASSERT_NUM_EQUAL(  0, post_add(x));
        UT_ASSERT_NUM_EQUAL(  1, post_add(x));
        UT_ASSERT_NUM_EQUAL(  2, x);
        UT_ASSERT_NUM_EQUAL(  2, post_dif(x));
        UT_ASSERT_NUM_EQUAL(  1, post_dif(x));
        UT_ASSERT_NUM_EQUAL(  0, x);

        x = 0;
        UT_ASSERT_NUM_EQUAL(  0, x);
        UT_ASSERT_NUM_EQUAL(  1, sum(post_add(x), post_add(x)));
        UT_ASSERT_NUM_EQUAL(  5, sum(post_add(x), post_add(x)));
        UT_ASSERT_NUM_EQUAL(  4, x);
        UT_ASSERT_NUM_EQUAL(  7, sum(post_dif(x), post_dif(x)));
        UT_ASSERT_NUM_EQUAL(  3, sum(post_dif(x), post_dif(x)));
        UT_ASSERT_NUM_EQUAL(  0, x);

        x = 0;
        UT_ASSERT_NUM_EQUAL(  0, x);
        UT_ASSERT_NUM_EQUAL(  1, pref_add(x));
        UT_ASSERT_NUM_EQUAL(  2, pref_add(x));
        UT_ASSERT_NUM_EQUAL(  2, x);
        UT_ASSERT_NUM_EQUAL(  1, pref_dif(x));
        UT_ASSERT_NUM_EQUAL(  0, pref_dif(x));
        UT_ASSERT_NUM_EQUAL(  0, x);

        x = 0;
        UT_ASSERT_NUM_EQUAL(  0, x);
        UT_ASSERT_NUM_EQUAL(  3, sum(pref_add(x), pref_add(x)));
        UT_ASSERT_NUM_EQUAL(  7, sum(pref_add(x), pref_add(x)));
        UT_ASSERT_NUM_EQUAL(  4, x);
        UT_ASSERT_NUM_EQUAL(  5, sum(pref_dif(x), pref_dif(x)));
        UT_ASSERT_NUM_EQUAL(  1, sum(pref_dif(x), pref_dif(x)));
        UT_ASSERT_NUM_EQUAL(  0, x);
    }UT_GROUP_END;
}
