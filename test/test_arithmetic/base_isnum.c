// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_base_isnum) {
    UT_GROUP_BEG(parity) {
        UT_GROUP_BEG(is_pos) {
            UT_ASSERT_BOOL_FL(is_pos(+0.0));
            UT_ASSERT_BOOL_FL(is_pos(0));
            UT_ASSERT_BOOL_FL(is_pos(-1));
            UT_ASSERT_BOOL_FL(is_pos(-1.1));

            UT_ASSERT_BOOL_TR(is_pos(+1));
            UT_ASSERT_BOOL_TR(is_pos(+1.0));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(is_neg) {
            UT_ASSERT_BOOL_FL(is_neg(-0.0));
            UT_ASSERT_BOOL_FL(is_neg(0));
            UT_ASSERT_BOOL_FL(is_neg(1));
            UT_ASSERT_BOOL_FL(is_neg(1.1));

            UT_ASSERT_BOOL_TR(is_neg(-1));
            UT_ASSERT_BOOL_TR(is_neg(-1.0));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(is_zero) {
            UT_ASSERT_BOOL_TR(is_zero(+0.0));
            UT_ASSERT_BOOL_TR(is_zero(-0.0));
            UT_ASSERT_BOOL_TR(is_zero(0));

            UT_ASSERT_BOOL_FL(is_zero(1));
            UT_ASSERT_BOOL_FL(is_zero(-1));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(is_pos_or_zero) {
            UT_ASSERT_BOOL_FL(is_pos_or_zero(-1));
            UT_ASSERT_BOOL_FL(is_pos_or_zero(-1.1));

            UT_ASSERT_BOOL_TR(is_pos_or_zero(+0.0));
            UT_ASSERT_BOOL_TR(is_pos_or_zero(0));
            UT_ASSERT_BOOL_TR(is_pos_or_zero(+1));
            UT_ASSERT_BOOL_TR(is_pos_or_zero(+1.0));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(is_neg_or_zero) {
            UT_ASSERT_BOOL_FL(is_neg_or_zero(1));
            UT_ASSERT_BOOL_FL(is_neg_or_zero(1.1));

            UT_ASSERT_BOOL_TR(is_neg_or_zero(-0.0));
            UT_ASSERT_BOOL_TR(is_neg_or_zero(0));
            UT_ASSERT_BOOL_TR(is_neg_or_zero(-1));
            UT_ASSERT_BOOL_TR(is_neg_or_zero(-1.0));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(is_even) {
            UT_ASSERT_BOOL_TR(is_even(-2));
            UT_ASSERT_BOOL_TR(is_even(0));
            UT_ASSERT_BOOL_TR(is_even(+2));

            UT_ASSERT_BOOL_FL(is_even(-1));
            UT_ASSERT_BOOL_FL(is_even(+1));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(is_odd) {
            UT_ASSERT_BOOL_TR(is_odd(-1));
            UT_ASSERT_BOOL_TR(is_odd(+1));

            UT_ASSERT_BOOL_FL(is_odd(-2));
            UT_ASSERT_BOOL_FL(is_odd(0));
            UT_ASSERT_BOOL_FL(is_odd(+2));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(is_prime) {
            UT_ASSERT_BOOL_TR(is_prime(2));
            UT_ASSERT_BOOL_TR(is_prime(3));
            UT_ASSERT_BOOL_TR(is_prime(5));
            UT_ASSERT_BOOL_TR(is_prime(7));
            UT_ASSERT_BOOL_TR(is_prime(11));

            UT_ASSERT_BOOL_FL(is_prime(1));
            UT_ASSERT_BOOL_FL(is_prime(4));
            UT_ASSERT_BOOL_FL(is_prime(6));
            UT_ASSERT_BOOL_FL(is_prime(8));
            UT_ASSERT_BOOL_FL(is_prime(9));
            UT_ASSERT_BOOL_FL(is_prime(10));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(is_fp_fin) {
            UT_ASSERT_BOOL_TR(is_fp_fin(1.0));
            UT_ASSERT_BOOL_TR(is_fp_fin(-1.0));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(is_fp_nan) {
            UT_ASSERT_BOOL_TR(is_fp_nan(to_pos(nan(fmax_t))));
            UT_ASSERT_BOOL_TR(is_fp_nan(to_neg(nan(fmax_t))));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(is_fp_inf) {
            UT_ASSERT_BOOL_TR(is_fp_inf(pos_inf(fmax_t)));
            UT_ASSERT_BOOL_TR(is_fp_inf(neg_inf(fmax_t)));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(is_fp_nor) {
            UT_ASSERT_BOOL_TR(is_fp_nor(1.0));
            UT_ASSERT_BOOL_TR(is_fp_nor(-1.0));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(is_fp_sub) {
            UT_ASSERT_BOOL_TR(is_fp_sub(DBL_MIN / 2));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(is_fp_zero) {
            UT_ASSERT_BOOL_TR(is_fp_zero( 0.0));
            UT_ASSERT_BOOL_TR(is_fp_zero(+0.0));
            UT_ASSERT_BOOL_TR(is_fp_zero(-0.0));

            UT_ASSERT_BOOL_FL(is_fp_zero( 1.0));
            UT_ASSERT_BOOL_FL(is_fp_zero(+1.0));
            UT_ASSERT_BOOL_FL(is_fp_zero(-1.0));

            UT_ASSERT_BOOL_FL(is_fp_zero( 11.1));
            UT_ASSERT_BOOL_FL(is_fp_zero(+11.1));
            UT_ASSERT_BOOL_FL(is_fp_zero(-11.1));
        }
        UT_GROUP_END;

        UT_GROUP_BEG(fp_classify) {
            UT_ASSERT_BOOL_TR(fp_class(pos_inf(fmax_t)) == FP_INFINITE);
            UT_ASSERT_BOOL_TR(fp_class(neg_inf(fmax_t)) == FP_INFINITE);

            UT_ASSERT_BOOL_TR(fp_class(to_pos(nan(fmax_t))) == FP_NAN);
            UT_ASSERT_BOOL_TR(fp_class(to_neg(nan(fmax_t))) == FP_NAN);

            UT_ASSERT_BOOL_TR(fp_class(+0.0) == FP_ZERO);
            UT_ASSERT_BOOL_TR(fp_class(-0.0) == FP_ZERO);
            UT_ASSERT_BOOL_TR(fp_class( 0.0) == FP_ZERO);

            UT_ASSERT_BOOL_TR(fp_class(1.0)  == FP_NORMAL);
            UT_ASSERT_BOOL_TR(fp_class(-1.0) == FP_NORMAL);

            UT_ASSERT_BOOL_TR(fp_class(DBL_MIN / 2) == FP_SUBNORMAL);
        }
        UT_GROUP_END;
    }
    UT_GROUP_END;
}
