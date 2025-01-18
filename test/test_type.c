// Author                 : Seityagiya Terlekchi
// Contacts               : terlekchiseityaya@gmail.com
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2025 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_type.h"

int test_type(void) {
    {
        char c = 0;
        ASSERT_STR_EQ("char", base_type_full_name(c));

        char *cp = NULL;
        ASSERT_STR_EQ("point to char", base_type_full_name(cp));
    }

    {
        char c = 0;
        ASSERT_STR_EQ("chr", base_type_spec(c));

        char *cp = NULL;
        ASSERT_STR_EQ("str", base_type_spec(cp));
    }

    {
        char c = 0;
        ASSERT_NUM_EQ(BASE_TYPE_GROUP_CHAR, base_type_group(c));

        char *cp = NULL;
        ASSERT_NUM_EQ(BASE_TYPE_GROUP_CHAR_P, base_type_group(cp));
    }

    {
        signed char sc = 0;
        ASSERT_NUM_EQ(BASE_TYPE_SIGN_SIGNUM, base_type_sign(sc));

        unsigned char uc = 0;
        ASSERT_NUM_EQ(BASE_TYPE_SIGN_UNSIGNUM, base_type_sign(uc));

        void *p = NULL;
        ASSERT_NUM_EQ(BASE_TYPE_SIGN_UNDEFINED, base_type_sign(p));
    }

    {
        char c = 0;
        ASSERT_NUM_EQ('a', base_type_uid(c));

        char *cp = NULL;
        ASSERT_NUM_EQ('A', base_type_uid(cp));
    }

    {
        char c = 0;
        ASSERT_STR_EQ("c", base_type_print(c));

        char *cp = NULL;
        ASSERT_STR_EQ("s", base_type_print(cp));
    }

    {
        nullptr_t n = nullptr;
    }
    return 0;
}
