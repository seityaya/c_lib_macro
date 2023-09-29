// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_base_logical) {
    UT_GROUP_BEG(logical) {
        UT_GROUP_BEG(bool) {
            UT_GROUP_BEG(log_not) {
                UT_ASSERT_BIT_EQ(true, log_not(false));
                UT_ASSERT_BIT_EQ(false, log_not(true));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(log_and) {
                UT_ASSERT_BIT_EQ(false, log_and(false, false));
                UT_ASSERT_BIT_EQ(false, log_and(false, true));
                UT_ASSERT_BIT_EQ(false, log_and(true, false));
                UT_ASSERT_BIT_EQ(true , log_and(true, true));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(log_and_each) {
                UT_ASSERT_BIT_EQ(false, log_and_each(false, false));
                UT_ASSERT_BIT_EQ(false, log_and_each(false, true));
                UT_ASSERT_BIT_EQ(false, log_and_each(true, false));
                UT_ASSERT_BIT_EQ(true, log_and_each(true, true));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(log_or) {
                UT_ASSERT_BIT_EQ(false, log_or(false, false));
                UT_ASSERT_BIT_EQ(true, log_or(false, true));
                UT_ASSERT_BIT_EQ(true, log_or(true, false));
                UT_ASSERT_BIT_EQ(true, log_or(true, true));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(log_or_each) {
                UT_ASSERT_BIT_EQ(false, log_or_each(false, false));
                UT_ASSERT_BIT_EQ(true, log_or_each(false, true));
                UT_ASSERT_BIT_EQ(true, log_or_each(true, false));
                UT_ASSERT_BIT_EQ(true, log_or_each(true, true));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(log_nand) {
                UT_ASSERT_BIT_EQ(true, log_nand(false, false));
                UT_ASSERT_BIT_EQ(true, log_nand(false, true));
                UT_ASSERT_BIT_EQ(true, log_nand(true, false));
                UT_ASSERT_BIT_EQ(false, log_nand(true, true));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(log_nor) {
                UT_ASSERT_BIT_EQ(true, log_nor(false, false));
                UT_ASSERT_BIT_EQ(false, log_nor(false, true));
                UT_ASSERT_BIT_EQ(false, log_nor(true, false));
                UT_ASSERT_BIT_EQ(false, log_nor(true, true));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(log_xand) {
                UT_ASSERT_BIT_EQ(true, log_xand(false, false));
                UT_ASSERT_BIT_EQ(false, log_xand(false, true));
                UT_ASSERT_BIT_EQ(false, log_xand(true, false));
                UT_ASSERT_BIT_EQ(true, log_xand(true, true));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(log_xor) {
                UT_ASSERT_BIT_EQ(false, log_xor(false, false));
                UT_ASSERT_BIT_EQ(true, log_xor(false, true));
                UT_ASSERT_BIT_EQ(true, log_xor(true, false));
                UT_ASSERT_BIT_EQ(false, log_xor(true, true));
            }
            UT_GROUP_END;
        }
        UT_GROUP_END;

        UT_GROUP_BEG(compare) {
            UT_GROUP_BEG(eq) {
                UT_ASSERT_BOOL_TR(eq(1, 1));
                UT_ASSERT_BOOL_TR(eq(1.0, 1.0));
                UT_ASSERT_BOOL_TR(eq(1.0 + 1I, 1.0 + 1I));

                UT_ASSERT_BOOL_FL(eq(1, 2));
                UT_ASSERT_BOOL_FL(eq(1.0, 1.2));
                UT_ASSERT_BOOL_FL(eq(1.0 + 1I, 1.0 + 2I));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(nq) {
                UT_ASSERT_BOOL_TR(ne(1, 2));
                UT_ASSERT_BOOL_TR(ne(1.0, 2.0));
                UT_ASSERT_BOOL_TR(ne(1.0 + 1I, 1.0 + 2I));

                UT_ASSERT_BOOL_FL(ne(1, 1));
                UT_ASSERT_BOOL_FL(ne(1.0, 1.0));
                UT_ASSERT_BOOL_FL(ne(1.0 + 1I, 1.0 + 1I));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(gt) {
                UT_ASSERT_BOOL_TR(gt(2, 1));
                UT_ASSERT_BOOL_TR(gt(2.0, 1.0));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(lt) {
                UT_ASSERT_BOOL_TR(lt(1, 2));
                UT_ASSERT_BOOL_TR(lt(1.0, 2.0));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(ge) {
                UT_ASSERT_BOOL_TR(ge(2, 1));
                UT_ASSERT_BOOL_TR(ge(2, 2));

                UT_ASSERT_BOOL_TR(ge(2.0, 1.0));
                UT_ASSERT_BOOL_TR(ge(2.0, 2.0));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(le) {
                UT_ASSERT_BOOL_TR(le(1, 2));
                UT_ASSERT_BOOL_TR(le(1, 1));

                UT_ASSERT_BOOL_TR(le(1.0, 2.0));
                UT_ASSERT_BOOL_TR(le(1.0, 1.0));
            }
            UT_GROUP_END;

            UT_GROUP_BEG(ap) {
                UT_ASSERT_BOOL_TR(ap(1, 1, 0));
                UT_ASSERT_BOOL_TR(ap(9, 10, 1));
                UT_ASSERT_BOOL_TR(ap(90, 100, 10));
                UT_ASSERT_BOOL_TR(ap(-100, -90, 10));
                UT_ASSERT_BOOL_TR(ap(-128, -127, 1));
                UT_ASSERT_BOOL_TR(ap(+127, -128, 255));

                UT_ASSERT_BOOL_FL(ap(1, 2, 0));
                UT_ASSERT_BOOL_FL(ap(100, -90, 10));

                UT_ASSERT_BOOL_TR(ap(1.0, 1.0, 0.0));
                UT_ASSERT_BOOL_TR(ap(9.0, 10.0, 1.0));
                UT_ASSERT_BOOL_TR(ap(90.0, 100.0, 10.0));
                UT_ASSERT_BOOL_TR(ap(-100.0, -90.0, 10.0));

                UT_ASSERT_BOOL_FL(ap(1.0, 2.0, 0.0));
                UT_ASSERT_BOOL_FL(ap(100.0, -90.0, 10.0));
            }
            UT_GROUP_END;
        }
        UT_GROUP_END;
    }
    UT_GROUP_END;
}
