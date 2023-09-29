// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_base_unar) {
    UT_GROUP_BEG(unar) {
        is8_t x = 0;
        UT_ASSERT_NUM_EQ(i8_c(0), x);
        UT_ASSERT_NUM_EQ(i8_c(1), un_inc_first(x));
        UT_ASSERT_NUM_EQ(i8_c(2), un_inc_first(x));
        UT_ASSERT_NUM_EQ(i8_c(2), x);
        UT_ASSERT_NUM_EQ(i8_c(1), un_dec_first(x));
        UT_ASSERT_NUM_EQ(i8_c(0), un_dec_first(x));
        UT_ASSERT_NUM_EQ(i8_c(0), x);

        x = 0;
        UT_ASSERT_NUM_EQ(i8_c(0), x);
        UT_ASSERT_NUM_EQ(i8_c(3), sum(un_inc_first(x), un_inc_first(x)));
        UT_ASSERT_NUM_EQ(i8_c(7), sum(un_inc_first(x), un_inc_first(x)));
        UT_ASSERT_NUM_EQ(i8_c(4), x);
        UT_ASSERT_NUM_EQ(i8_c(5), sum(un_dec_first(x), un_dec_first(x)));
        UT_ASSERT_NUM_EQ(i8_c(1), sum(un_dec_first(x), un_dec_first(x)));
        UT_ASSERT_NUM_EQ(i8_c(0), x);

        x = 0;
        UT_ASSERT_NUM_EQ(i8_c(0), x);
        UT_ASSERT_NUM_EQ(i8_c(0), un_inc_after(x));
        UT_ASSERT_NUM_EQ(i8_c(1), un_inc_after(x));
        UT_ASSERT_NUM_EQ(i8_c(2), x);
        UT_ASSERT_NUM_EQ(i8_c(2), un_dec_after(x));
        UT_ASSERT_NUM_EQ(i8_c(1), un_dec_after(x));
        UT_ASSERT_NUM_EQ(i8_c(0), x);

        x = 127;
        UT_ASSERT_NUM_EQ(i8_c(127), un_inc_after(x));
        UT_ASSERT_NUM_EQ(i8_c(-128), un_inc_after(x));

        x = 0;
        UT_ASSERT_NUM_EQ(i8_c(0), x);
        UT_ASSERT_NUM_EQ(i8_c(1), sum(un_inc_after(x), un_inc_after(x)));
        UT_ASSERT_NUM_EQ(i8_c(5), sum(un_inc_after(x), un_inc_after(x)));
        UT_ASSERT_NUM_EQ(i8_c(4), x);
        UT_ASSERT_NUM_EQ(i8_c(7), sum(un_dec_after(x), un_dec_after(x)));
        UT_ASSERT_NUM_EQ(i8_c(3), sum(un_dec_after(x), un_dec_after(x)));
        UT_ASSERT_NUM_EQ(i8_c(0), x);
    } UT_GROUP_END;
}
