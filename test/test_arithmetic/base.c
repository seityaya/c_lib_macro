// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_base) {
    UT_GROUP_BEG(as) {
        UT_GROUP_BEG(is_as) {
            is8_t y = 0;
            UT_ASSERT_BOOL_TR(is_as(y, i8_c(127)));
            UT_ASSERT_BOOL_TR(is_as(y, i8_c(-128)));

            UT_ASSERT_BOOL_FL(is_as(y, i16_c(128)));
            UT_ASSERT_BOOL_FL(is_as(y, i16_c(-129)));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(as_truncate) {
            is8_t x = 0;
            f32_t y = 0;

            UT_ASSERT_BOOL_TR(as(x, i8_c(1)));
            UT_ASSERT_NUM_EQ(x, i8_c(1));

            UT_ASSERT_BOOL_TR(as(y, f32_c(1.1)));
            UT_ASSERT_FLT_EQ(y, f32_c(1.1));

            UT_ASSERT_BOOL_TR(as(x, i8_c(f32_c(2.2))));
            UT_ASSERT_NUM_EQ(x, i8_c(2));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(as_chk) {
            is8_t y = 0;
            is8_t x = 0;
            is16_t X = 0;
            is16_t Y = 0;

            x = 127;
            y = 1;
            UT_ASSERT_BOOL_TR(as_chk(y, x));
            UT_ASSERT_NUM_EQ(y, i8_c(127));

            x = -128;
            y = 1;
            UT_ASSERT_BOOL_TR(as_chk(y, x));
            UT_ASSERT_NUM_EQ(y, i8_c(-128));

            X = 128;
            y = 1;
            UT_ASSERT_BOOL_FL(as_chk(y, X));
            UT_ASSERT_NUM_EQ(y, i8_c(1));

            X = -129;
            y = 1;
            UT_ASSERT_BOOL_FL(as_chk(y, X));
            UT_ASSERT_NUM_EQ(y, i8_c(1));

            X = 128;
            Y = 1;
            UT_ASSERT_BOOL_TR(as_chk(Y, X));
            UT_ASSERT_NUM_EQ(Y, i16_c(128));

            X = -129;
            Y = 1;
            UT_ASSERT_BOOL_TR(as_chk(Y, X));
            UT_ASSERT_NUM_EQ(Y, i16_c(-129));

            f64_t F = 1.1;
            f32_t f = 1;
            UT_ASSERT_BOOL_TR(as_chk(f, F));
            UT_ASSERT_FLT_EQ(f, f32_c(1.1));

            F = DBL_MAX;
            f = 1;
            UT_ASSERT_BOOL_FL(as_chk(f, F));
            UT_ASSERT_FLT_EQ(f, f32_c(1));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(swap) {
            is8_t x = 0;
            is8_t y = 1;

            UT_ASSERT_NUM_EQ(i8_c(0), x);
            UT_ASSERT_NUM_EQ(i8_c(1), y);

            UT_ASSERT_BOOL_TR(swap(x, y));

            UT_ASSERT_NUM_EQ(i8_c(1), x);
            UT_ASSERT_NUM_EQ(i8_c(0), y);

            UT_ASSERT_BOOL_TR(swap(x, y));

            UT_ASSERT_NUM_EQ(i8_c(0), x);
            UT_ASSERT_NUM_EQ(i8_c(1), y);
        }
        UT_GROUP_END;
    }
    UT_GROUP_END;

    UT_GROUP_BEG(absolute) {
        UT_GROUP_BEG(is_abs) {
            UT_ASSERT_BOOL_TR(is_abs(i8_c(-1)));
            UT_ASSERT_BOOL_TR(is_abs(i8_c(0)));
            UT_ASSERT_BOOL_TR(is_abs(i8_c(1)));

            UT_ASSERT_BOOL_TR(is_abs(i8_c(-127)));
            UT_ASSERT_BOOL_FL(is_abs(i8_c(-128)));

            UT_ASSERT_BOOL_TR(is_abs(u8_c(-1)));
            UT_ASSERT_BOOL_TR(is_abs(u8_c(0)));
            UT_ASSERT_BOOL_TR(is_abs(u8_c(1)));

            UT_ASSERT_BOOL_TR(is_abs(u8_c(-127)));
            UT_ASSERT_BOOL_TR(is_abs(u8_c(-128)));

            UT_ASSERT_BOOL_TR(is_abs(f32_c(1.1)));
            UT_ASSERT_BOOL_TR(is_abs(f32_c(-1.1)));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(abs) {
            UT_ASSERT_NUM_EQ(i8_c(1), abs(i8_c(-1)));
            UT_ASSERT_NUM_EQ(i8_c(0), abs(i8_c(0)));
            UT_ASSERT_NUM_EQ(i8_c(1), abs(i8_c(1)));

            UT_ASSERT_NUM_EQ(i8_c(127), abs(i8_c(-127)));
            UT_ASSERT_NUM_EQ(i8_c(-128), abs(i8_c(-128)));

            UT_ASSERT_NUM_EQ(u8_c(255), abs(u8_c(-1)));
            UT_ASSERT_NUM_EQ(u8_c(0), abs(u8_c(0)));
            UT_ASSERT_NUM_EQ(u8_c(1), abs(u8_c(1)));

            UT_ASSERT_NUM_EQ(u8_c(129), abs(u8_c(-127)));
            UT_ASSERT_NUM_EQ(u8_c(128), abs(u8_c(-128)));

            UT_ASSERT_FLT_EQ(f32_c(1.1), abs(f32_c(1.1)));
            UT_ASSERT_FLT_EQ(f32_c(1.1), abs(f32_c(-1.1)));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(abs_chk) {
            is8_t res_i = 0;
            f32_t res_f = 0;
            UT_ASSERT_BOOL_TR(abs_chk(res_i, i8_c(-1)));
            UT_ASSERT_NUM_EQ(res_i, i8_c(1));

            UT_ASSERT_BOOL_TR(abs_chk(res_i, i8_c(0)));
            UT_ASSERT_NUM_EQ(res_i, i8_c(0));

            UT_ASSERT_BOOL_TR(abs_chk(res_i, i8_c(1)));
            UT_ASSERT_NUM_EQ(res_i, i8_c(1));

            res_i = 33;
            UT_ASSERT_BOOL_TR(abs_chk(res_i, i8_c(-127)));
            UT_ASSERT_NUM_EQ(res_i, i8_c(127));

            res_i = 33;
            UT_ASSERT_BOOL_FL(abs_chk(res_i, i8_c(-128)));
            UT_ASSERT_NUM_EQ(res_i, i8_c(33));

            UT_ASSERT_BOOL_TR(abs_chk(res_f, f32_c(1.1)));
            UT_ASSERT_FLT_EQ(res_f, f32_c(1.1));

            UT_ASSERT_BOOL_TR(abs_chk(res_f, f32_c(-1.1)));
            UT_ASSERT_FLT_EQ(res_f, f32_c(1.1));
        }
        UT_GROUP_END;
    }
    UT_GROUP_END;

    UT_GROUP_BEG(dis) {
        UT_ASSERT_NUM_EQ(i8_c(0), dis(i8_c(0), i8_c(0)));
        UT_ASSERT_NUM_EQ(i8_c(0), dis(i8_c(1), i8_c(1)));
        UT_ASSERT_NUM_EQ(i8_c(0), dis(i8_c(-1), i8_c(-1)));
        UT_ASSERT_NUM_EQ(i8_c(1), dis(i8_c(0), i8_c(1)));
        UT_ASSERT_NUM_EQ(i8_c(1), dis(i8_c(1), i8_c(0)));
        UT_ASSERT_NUM_EQ(i8_c(2), dis(i8_c(-1), i8_c(+1)));
        UT_ASSERT_NUM_EQ(i8_c(3), dis(i8_c(0), i8_c(3)));
        UT_ASSERT_NUM_EQ(i8_c(2), dis(i8_c(1), i8_c(3)));
        UT_ASSERT_NUM_EQ(i8_c(2), dis(i8_c(-1), i8_c(-3)));
        UT_ASSERT_NUM_EQ(i8_c(3), dis(i8_c(0), i8_c(-3)));
        UT_ASSERT_NUM_EQ(i8_c(6), dis(i8_c(-3), i8_c(+3)));

        UT_ASSERT_FLT_EQ(f32_c(1.1), dis(f32_c(0.0), f32_c(1.1)));
        UT_ASSERT_FLT_EQ(f32_c(1.1), dis(f32_c(0.0), f32_c(-1.1)));

        is8_t x = +127;
        is8_t y = -128;
        UT_ASSERT_NUM_EQ(u8_c(255), u8_c(dis(x, y)));
    }
    UT_GROUP_END;
}
