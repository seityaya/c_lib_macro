// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_base_const) {
    UT_GROUP_BEG(constant) {
        UT_GROUP_BEG(zero) {
            UT_ASSERT_NUM_EQ(0,          zero(0));
            UT_ASSERT_NUM_EQ(0,          zero(int));
            UT_ASSERT_FLT_EQ(0.0,        zero(0.0));
            UT_ASSERT_FLT_EQ(f32_c(0.0), zero(f32_t));

            UT_ASSERT_TYP_EQ(0,          zero(1));
            UT_ASSERT_TYP_EQ(0L,         zero(long int));
            UT_ASSERT_TYP_EQ(0.0,        zero(1.0));
            UT_ASSERT_TYP_EQ(0.0,        zero(double));

            UT_ASSERT_TYP_NQ(0,          zero(long int));
            UT_ASSERT_TYP_NQ(0.0,        zero(int));
            UT_ASSERT_TYP_NQ(0,          zero(double));
            UT_ASSERT_TYP_NQ(u16_c(0.0), zero(us32_t));
        } UT_GROUP_END;

        UT_GROUP_BEG(one) {
            UT_ASSERT_NUM_EQ(1,  one(0));
            UT_ASSERT_NUM_EQ(1, one(int));
            UT_ASSERT_FLT_EQ(1.0, one(0.0));
            UT_ASSERT_FLT_EQ(f32_c(1.0), one(f32_t));

            UT_ASSERT_TYP_EQ(1, one(1));
            UT_ASSERT_TYP_EQ(1L, one(long int));
            UT_ASSERT_TYP_EQ(1.0, one(1.0));
            UT_ASSERT_TYP_EQ(1.0, one(double));

            UT_ASSERT_TYP_NQ(1, one(long int));
            UT_ASSERT_TYP_NQ(1.0, one(int));
            UT_ASSERT_TYP_NQ(1, one(double));
            UT_ASSERT_TYP_NQ(u16_c(1.0), one(us32_t));
        } UT_GROUP_END;

        UT_GROUP_BEG(lim_zero) {
            UT_ASSERT_FLT_EQ(fmax_c(+0.0), to_pos(zero(fmax_t)));
            UT_ASSERT_TYP_EQ(fmax_c(1.0), to_pos(zero(fmax_t)));
            UT_ASSERT_TYP_NQ(1, to_pos(zero(fmax_t)));

            UT_ASSERT_FLT_EQ(fmax_c(-0.0), to_neg(zero(fmax_t)));
            UT_ASSERT_TYP_EQ(fmax_c(1.0), to_neg(zero(fmax_t)));
            UT_ASSERT_TYP_NQ(1, to_neg(zero(fmax_t)));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(inf) {
            UT_ASSERT_FLT_EQ(fmax_c(+INFINITY), pos_inf(fmax_t));
            UT_ASSERT_TYP_EQ(fmax_c(1.0),       pos_inf(fmax_t));
            UT_ASSERT_TYP_NQ(1,                 pos_inf(fmax_t));

            UT_ASSERT_FLT_EQ(fmax_c(-INFINITY), neg_inf(fmax_t));
            UT_ASSERT_TYP_EQ(fmax_c(1.0),       neg_inf(fmax_t));
            UT_ASSERT_TYP_NQ(1,                 neg_inf(fmax_t));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(nan) {
            UT_ASSERT_FLT_EQ(fmax_c(+NAN), to_pos(nan(fmax_t)));
            UT_ASSERT_TYP_EQ(fmax_c(1.0), to_pos(nan(fmax_t)));
            UT_ASSERT_TYP_NQ(1, to_pos(nan(fmax_t)));

            UT_ASSERT_FLT_EQ(fmax_c(-NAN), to_neg(nan(fmax_t)));
            UT_ASSERT_TYP_EQ(fmax_c(1.0), to_neg(nan(fmax_t)));
            UT_ASSERT_TYP_NQ(1, to_neg(nan(fmax_t)));
        }
        UT_GROUP_END;
    }
    UT_GROUP_END;
}
