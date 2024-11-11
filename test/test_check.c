// Author                 : Seityagiya Terlekchi
// Contacts               : terlekchiseityaya@gmail.com
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2024 Seityagiya Terlekchi. All rights reserved.

#include "yaya_check.h"

int test_check(void) {
    int a = 1;
    COMPILE_NO_SIDE_EFFECT_VARIABLE(a, A);
    if (A != 2) {
        return -1;
    }

    int b = 1;
    COMPILE_NO_SIDE_EFFECT_VARIABLE(b++, B);
    if (B != 2) {
        return -1;
    }

    int c = 1;
    COMPILE_NO_SIDE_EFFECT_VARIABLE(++c, C);
    if (C != 2) {
        return -1;
    }

    int d = 0;
    COMPTIME_CHECK_IS_RUNTIME_VALUE(d); // NOT WARN - OK
    // COMPTIME_CHECK_IS_COMPTIME_VALUE(d); // NOT WARN - ERROR

#define D 1
    COMPTIME_CHECK_IS_COMPTIME_VALUE(D); // NOT WARN - OK
    // COMPTIME_CHECK_IS_RUNTIME_VALUE(D);  // NOT WARN - ERROR
#undef D

    enum {
        D,
    };
    COMPTIME_CHECK_IS_COMPTIME_VALUE(D); // NOT WARN - OK
    // COMPTIME_CHECK_IS_RUNTIME_VALUE(D); // NOT WARN - ERROR

    COMPTIME_ASSERT((1 == 1)); // NOT WARN - OK
    // COMPTIME_ASSERT((1 != 1)); // NOT WARN - ERROR

    return 0;
}
