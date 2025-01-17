// Author                 : Seityagiya Terlekchi
// Contacts               : terlekchiseityaya@gmail.com
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2025 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_concat.h"

int test_concat(void) {
    {
        ASSERT_STR_EQ("a", MACRO_DELAY("a"));

        int a = 1;
        ASSERT_NUM_EQ(1, MACRO_DELAY(a));
    }

    {
        ASSERT_STR_EQ("a", STR_1(a));
        ASSERT_STR_EQ("\"a\"", STR_1("a"));

        ASSERT_STR_EQ("a", STR_2(a));
        ASSERT_STR_EQ("\"a\"", STR_2("a"));

        ASSERT_STR_EQ("a", STR_3(a));
        ASSERT_STR_EQ("\"a\"", STR_3("a"));
    }

    {
        ASSERT_STR_EQ("ab", STR_2(CAT_1(a, b)));

        int ab = 1;
        ASSERT_NUM_EQ(1, CAT_1(a, b));
        ASSERT_STR_EQ("ab", STR_2(CAT_2(a, b)));
        ASSERT_NUM_EQ(1, CAT_2(a, b));

        ASSERT_STR_EQ("ab", STR_2(CAT_3(a, b)));
        ASSERT_NUM_EQ(1, CAT_3(a, b));
    }

    {
        ASSERT_STR_EQ("abc", STR_3(CAT_VA_3(a, b, c)));

        int abc = 1;
        ASSERT_NUM_EQ(1, CAT_VA_3(a, b, c));
    }
    return 0;
}
