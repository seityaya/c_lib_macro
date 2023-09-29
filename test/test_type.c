// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_type.h"

UT_FUNC_GEN(test_type) {
    UT_GROUP_BEG(base_type_full_name) {
        char c = 0;
        UT_ASSERT_STR_EQ("char", base_type_full_name(c));

        char *cp = NULL;
        UT_ASSERT_STR_EQ("point to char", base_type_full_name(cp));
    } UT_GROUP_END;

    UT_GROUP_BEG(base_type_spec) {
        char c = 0;
        UT_ASSERT_STR_EQ("chr", base_type_spec(c));

        char *cp = NULL;
        UT_ASSERT_STR_EQ("str", base_type_spec(cp));
    } UT_GROUP_END;

    UT_GROUP_BEG(base_type_group) {
        char c = 0;
        UT_ASSERT_NUM_EQ(BASE_TYPE_GROUP_CHAR, base_type_group(c));

        char *cp = NULL;
        UT_ASSERT_NUM_EQ(BASE_TYPE_GROUP_CHAR_P, base_type_group(cp));
    } UT_GROUP_END;

    UT_GROUP_BEG(base_type_sign) {
        signed char sc = 0;
        UT_ASSERT_NUM_EQ(BASE_TYPE_SIGN_SIGNUM, base_type_sign(sc));

        unsigned char uc = 0;
        UT_ASSERT_NUM_EQ(BASE_TYPE_SIGN_UNSIGNUM, base_type_sign(uc));

        void *p = NULL;
        UT_ASSERT_NUM_EQ(BASE_TYPE_SIGN_UNDEFINED, base_type_sign(p));
    } UT_GROUP_END;

    UT_GROUP_BEG(base_type_uid) {
        char c = 0;
        UT_ASSERT_NUM_EQ('a', base_type_uid(c));

        char *cp = NULL;
        UT_ASSERT_NUM_EQ('A', base_type_uid(cp));
    } UT_GROUP_END;

    UT_GROUP_BEG(base_type_print) {
        char c = 0;
        UT_ASSERT_STR_EQ("c", base_type_print(c));

        char *cp = NULL;
        UT_ASSERT_STR_EQ("s", base_type_print(cp));
    } UT_GROUP_END;
}
