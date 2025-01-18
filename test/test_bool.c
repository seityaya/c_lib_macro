// Author                 : Seityagiya Terlekchi
// Contacts               : terlekchiseityaya@gmail.com
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2025 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_bool.h"
#include "yaya_type.h"

bool_t b_t = true;
bool_t b_f = false;

int test_bool(void) {
    ASSERT_BOOL_TR(true);
    ASSERT_BOOL_FL(false);

    ASSERT_BOOL_TR(b_t);
    ASSERT_BOOL_FL(b_f);

    bool_t A = false;
    ASSERT_BOOL_FL(A);
    A = 0;
    ASSERT_BOOL_FL(A);

    A = true;
    ASSERT_BOOL_TR(A);
    A = 1;
    ASSERT_BOOL_TR(A);
    A = 2;
    ASSERT_BOOL_TR(A);

    ASSERT_NUM_NQ(s8_c(true), s8_c(0));
    ASSERT_NUM_EQ(s8_c(false), s8_c(0));

    return 0;
}
