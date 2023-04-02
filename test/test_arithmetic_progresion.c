//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_progresion) {
    UT_GROUP_BEG(progresion) {
        UT_GROUP_BEG(arithmetic) {
            imax_t a = 0;
            imax_t b = 2;
            UT_GROUP_BEG(get) {
                UT_ASSERT_NUM_EQ(imax_c(-2), progresion_arithmetic(a, b, -1));
                UT_ASSERT_NUM_EQ(imax_c( 0), progresion_arithmetic(a, b,  0));
                UT_ASSERT_NUM_EQ(imax_c( 2), progresion_arithmetic(a, b,  1));

                UT_ASSERT_NUM_NQ(imax_c(-1), progresion_arithmetic(a, b,  0));
                UT_ASSERT_NUM_NQ(imax_c( 1), progresion_arithmetic(a, b,  0));
            } UT_GROUP_END;

            UT_GROUP_BEG(is) {
                UT_ASSERT_BOOL_TR(is_progresion_arithmetic(a, b, imax_c(-2)));
                UT_ASSERT_BOOL_TR(is_progresion_arithmetic(a, b, imax_c( 0)));
                UT_ASSERT_BOOL_TR(is_progresion_arithmetic(a, b, imax_c( 2)));

                UT_ASSERT_BOOL_FL(is_progresion_arithmetic(a, b, imax_c(-1)));
                UT_ASSERT_BOOL_FL(is_progresion_arithmetic(a, b, imax_c( 1)));

                UT_ASSERT_BOOL_TR(is_progresion_arithmetic(a, b, progresion_arithmetic(a, b, 0)));
                UT_ASSERT_BOOL_TR(is_progresion_arithmetic(a, b, progresion_arithmetic(a, b, 1)));
                UT_ASSERT_BOOL_TR(is_progresion_arithmetic(a, b, progresion_arithmetic(a, b, 2)));
            } UT_GROUP_END;
        } UT_GROUP_END;

        UT_GROUP_BEG(geometric) {
            fmax_t a = 2;
            fmax_t b = 2;
            UT_GROUP_BEG(get) {
                UT_ASSERT_FLT_EQ(fmax_c(0.25), progresion_geometric(a, b, -3));
                UT_ASSERT_FLT_EQ(fmax_c( 0.5), progresion_geometric(a, b, -2));
                UT_ASSERT_FLT_EQ(fmax_c( 1.0), progresion_geometric(a, b, -1));
                UT_ASSERT_FLT_EQ(fmax_c( 2.0), progresion_geometric(a, b,  0));
                UT_ASSERT_FLT_EQ(fmax_c( 4.0), progresion_geometric(a, b,  1));
                UT_ASSERT_FLT_EQ(fmax_c( 8.0), progresion_geometric(a, b,  2));
                UT_ASSERT_FLT_EQ(fmax_c(16.0), progresion_geometric(a, b,  3));
            } UT_GROUP_END;

            UT_GROUP_BEG(is) {
                UT_ASSERT_BOOL_TR(is_progresion_geometric(a, b,  fmax_c( 0.5)));
                UT_ASSERT_BOOL_TR(is_progresion_geometric(a, b,  fmax_c( 1.0)));
                UT_ASSERT_BOOL_TR(is_progresion_geometric(a, b,  fmax_c( 2.0)));

                UT_ASSERT_BOOL_FL(is_progresion_geometric(a, b, fmax_c(-1.0)));
                UT_ASSERT_BOOL_FL(is_progresion_geometric(a, b, fmax_c( 3.0)));

                UT_ASSERT_BOOL_TR(is_progresion_geometric(a, b, progresion_geometric(a, b, 0)));
                UT_ASSERT_BOOL_TR(is_progresion_geometric(a, b, progresion_geometric(a, b, 1)));
                UT_ASSERT_BOOL_TR(is_progresion_geometric(a, b, progresion_geometric(a, b, 2)));
            } UT_GROUP_END;
        } UT_GROUP_END;

        UT_GROUP_BEG(harmonic) {
            fmax_t a = 1;
            fmax_t b = 2;
            UT_GROUP_BEG(get) {
                UT_ASSERT_FLT_EQ_E(fmax_c(-0.200000), progresion_harmonic(a, b, -3), 0.0001);
                UT_ASSERT_FLT_EQ_E(fmax_c(-0.333333), progresion_harmonic(a, b, -2), 0.0001);
                UT_ASSERT_FLT_EQ_E(fmax_c(-1.000000), progresion_harmonic(a, b, -1), 0.0001);
                UT_ASSERT_FLT_EQ_E(fmax_c( 1.000000), progresion_harmonic(a, b,  0), 0.0001);
                UT_ASSERT_FLT_EQ_E(fmax_c( 0.333333), progresion_harmonic(a, b,  1), 0.0001);
                UT_ASSERT_FLT_EQ_E(fmax_c( 0.200000), progresion_harmonic(a, b,  2), 0.0001);
                UT_ASSERT_FLT_EQ_E(fmax_c( 0.142857), progresion_harmonic(a, b,  3), 0.0001);
                UT_ASSERT_FLT_EQ_E(fmax_c( 0.111111), progresion_harmonic(a, b,  4), 0.0001);
            } UT_GROUP_END;

            UT_GROUP_BEG(is) {
                UT_ASSERT_BOOL_TR(is_progresion_harmonic(a, b,  fmax_c(1.00)));
                UT_ASSERT_BOOL_TR(is_progresion_harmonic(a, b,  fmax_c(0.3333333333333333)));
                UT_ASSERT_BOOL_TR(is_progresion_harmonic(a, b,  fmax_c(0.20)));
                UT_ASSERT_BOOL_TR(is_progresion_harmonic(a, b,  fmax_c(0.142857)));
                UT_ASSERT_BOOL_TR(is_progresion_harmonic(a, b,  fmax_c(0.111111)));

                UT_ASSERT_BOOL_FL(is_progresion_geometric(a, b, fmax_c(0.3)));
                UT_ASSERT_BOOL_FL(is_progresion_geometric(a, b, fmax_c(0)));

                UT_ASSERT_BOOL_TR(is_progresion_harmonic(a, b, progresion_harmonic(a, b, 0)));
                UT_ASSERT_BOOL_TR(is_progresion_harmonic(a, b, progresion_harmonic(a, b, 1)));
                UT_ASSERT_BOOL_TR(is_progresion_harmonic(a, b, progresion_harmonic(a, b, 2)));
            } UT_GROUP_END;
        } UT_GROUP_END;
    } UT_GROUP_END;
}
