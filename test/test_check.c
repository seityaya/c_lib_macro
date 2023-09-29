// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_check.h"

UT_FUNC_GEN(test_check) {
    UT_GROUP_BEG(COMPILE_NO_SIDE_EFFECT_VARIABLE) {
        int a = 1;
        COMPILE_NO_SIDE_EFFECT_VARIABLE(a, A);
        UT_ASSERT_NUM_EQ(1, A);

        int b = 1;
        COMPILE_NO_SIDE_EFFECT_VARIABLE(b++, B);
        UT_ASSERT_NUM_EQ(2, b);
        UT_ASSERT_NUM_EQ(1, B);

        int c = 1;
        COMPILE_NO_SIDE_EFFECT_VARIABLE(++c, C);
        UT_ASSERT_NUM_EQ(2, c);
        UT_ASSERT_NUM_EQ(2, C);
    }
    UT_GROUP_END;

    UT_GROUP_BEG(COMPTIME_CHECK) {
        int a = 0;
        COMPTIME_CHECK_IS_RUNTIME_VALUE(a); // NOT WARN - OK
        // COMPTIME_CHECK_IS_COMPTIME_VALUE(a); // NOT WARN - ERROR

#define A 1
        COMPTIME_CHECK_IS_COMPTIME_VALUE(A); // NOT WARN - OK
        // COMPTIME_CHECK_IS_RUNTIME_VALUE(A);  // NOT WARN - ERROR
#undef A

        enum {
            B,
        };
        COMPTIME_CHECK_IS_COMPTIME_VALUE(B); // NOT WARN - OK
        // COMPTIME_CHECK_IS_RUNTIME_VALUE(B);  // NOT WARN - ERROR
    }
    UT_GROUP_END;

    UT_GROUP_BEG(COMPTIME_ASSERT) {
        COMPTIME_ASSERT(true); // NOT WARN - OK
        // COMPTIME_ASSERT(false); // NOT WARN - ERROR
    } UT_GROUP_END;
}
