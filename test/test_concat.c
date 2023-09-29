// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_concat.h"

UT_FUNC_GEN(test_concat) {
    UT_GROUP_BEG(macro_delay) {
        UT_ASSERT_STR_EQ("a", MACRO_DELAY("a"));
    } UT_GROUP_END;

    UT_GROUP_BEG(str) {
        UT_GROUP_BEG(str_1) {
            UT_ASSERT_STR_EQ("\"a\"", STR_1("a"));
        } UT_GROUP_END;

        UT_GROUP_BEG(str_2) {
            UT_ASSERT_STR_EQ("\"a\"", STR_2("a"));
        } UT_GROUP_END;

        UT_GROUP_BEG(str_3) {
            UT_ASSERT_STR_EQ("\"a\"", STR_3("a"));
        } UT_GROUP_END;
    } UT_GROUP_END;

    UT_GROUP_BEG(cat) {
        UT_GROUP_BEG(cat_1) {
            UT_ASSERT_STR_EQ("ab", STR_2(CAT_1(a, b)));

            int ab = 1;
            UT_ASSERT_NUM_EQ(1, CAT_1(a, b));
        } UT_GROUP_END;

        UT_GROUP_BEG(cat_2) {
            UT_ASSERT_STR_EQ("ab", STR_2(CAT_2(a, b)));

            int ab = 1;
            UT_ASSERT_NUM_EQ(1, CAT_2(a, b));
        } UT_GROUP_END;

        UT_GROUP_BEG(cat_3) {
            UT_ASSERT_STR_EQ("ab", STR_2(CAT_3(a, b)));

            int ab = 1;
            UT_ASSERT_NUM_EQ(1, CAT_3(a, b));
        } UT_GROUP_END;
    } UT_GROUP_END;

    UT_GROUP_BEG(cat_va) {
        UT_GROUP_BEG(cat_va_3) {
            UT_ASSERT_STR_EQ("abc", STR_3(CAT_VA_3(a, b, c)));

            int abc = 1;
            UT_ASSERT_NUM_EQ(1, CAT_VA_3(a, b, c));
        } UT_GROUP_END;
    } UT_GROUP_END;
}
