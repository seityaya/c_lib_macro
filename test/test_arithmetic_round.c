//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_round) {
    UT_GROUP_BEG(round) {
        UT_GROUP_BEG(round_int) {
            UT_ASSERT_FLT_EQ( 1.0, round_int(0.9));
            UT_ASSERT_FLT_EQ( 1.0, round_int(1.0));
            UT_ASSERT_FLT_EQ( 1.0, round_int(1.1));
            UT_ASSERT_FLT_EQ( 1.0, round_int(1.49));
            UT_ASSERT_FLT_EQ( 2.0, round_int(1.50));
            UT_ASSERT_FLT_EQ( 2.0, round_int(1.51));
            UT_ASSERT_FLT_EQ( 2.0, round_int(1.9));
            UT_ASSERT_FLT_EQ( 2.0, round_int(2.1));

            UT_ASSERT_FLT_EQ(-1.0, round_int(-0.9));
            UT_ASSERT_FLT_EQ(-1.0, round_int(-1.0));
            UT_ASSERT_FLT_EQ(-1.0, round_int(-1.1));
            UT_ASSERT_FLT_EQ(-1.0, round_int(-1.49));
            UT_ASSERT_FLT_EQ(-2.0, round_int(-1.50));
            UT_ASSERT_FLT_EQ(-2.0, round_int(-1.51));
            UT_ASSERT_FLT_EQ(-2.0, round_int(-1.9));
            UT_ASSERT_FLT_EQ(-2.0, round_int(-2.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_up) {
            UT_ASSERT_FLT_EQ( 1.0, round_up(0.9));
            UT_ASSERT_FLT_EQ( 1.0, round_up(1.0));
            UT_ASSERT_FLT_EQ( 2.0, round_up(1.1));
            UT_ASSERT_FLT_EQ( 2.0, round_up(1.49));
            UT_ASSERT_FLT_EQ( 2.0, round_up(1.50));
            UT_ASSERT_FLT_EQ( 2.0, round_up(1.51));
            UT_ASSERT_FLT_EQ( 2.0, round_up(1.9));
            UT_ASSERT_FLT_EQ( 3.0, round_up(2.1));

            UT_ASSERT_FLT_EQ(-0.0, round_up(-0.9));
            UT_ASSERT_FLT_EQ(-1.0, round_up(-1.0));
            UT_ASSERT_FLT_EQ(-1.0, round_up(-1.1));
            UT_ASSERT_FLT_EQ(-1.0, round_up(-1.49));
            UT_ASSERT_FLT_EQ(-1.0, round_up(-1.50));
            UT_ASSERT_FLT_EQ(-1.0, round_up(-1.51));
            UT_ASSERT_FLT_EQ(-1.0, round_up(-1.9));
            UT_ASSERT_FLT_EQ(-2.0, round_up(-2.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_dn) {
            UT_ASSERT_FLT_EQ( 0.0, round_dn(0.9));
            UT_ASSERT_FLT_EQ( 1.0, round_dn(1.0));
            UT_ASSERT_FLT_EQ( 1.0, round_dn(1.1));
            UT_ASSERT_FLT_EQ( 1.0, round_dn(1.49));
            UT_ASSERT_FLT_EQ( 1.0, round_dn(1.50));
            UT_ASSERT_FLT_EQ( 1.0, round_dn(1.51));
            UT_ASSERT_FLT_EQ( 1.0, round_dn(1.9));
            UT_ASSERT_FLT_EQ( 2.0, round_dn(2.1));

            UT_ASSERT_FLT_EQ(-1.0, round_dn(-0.9));
            UT_ASSERT_FLT_EQ(-1.0, round_dn(-1.0));
            UT_ASSERT_FLT_EQ(-2.0, round_dn(-1.1));
            UT_ASSERT_FLT_EQ(-2.0, round_dn(-1.49));
            UT_ASSERT_FLT_EQ(-2.0, round_dn(-1.50));
            UT_ASSERT_FLT_EQ(-2.0, round_dn(-1.51));
            UT_ASSERT_FLT_EQ(-2.0, round_dn(-1.9));
            UT_ASSERT_FLT_EQ(-3.0, round_dn(-2.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_zero) {
            UT_ASSERT_FLT_EQ( 0.0, round_zero(0.9));
            UT_ASSERT_FLT_EQ( 1.0, round_zero(1.0));
            UT_ASSERT_FLT_EQ( 1.0, round_zero(1.1));
            UT_ASSERT_FLT_EQ( 1.0, round_zero(1.49));
            UT_ASSERT_FLT_EQ( 1.0, round_zero(1.50));
            UT_ASSERT_FLT_EQ( 1.0, round_zero(1.51));
            UT_ASSERT_FLT_EQ( 1.0, round_zero(1.9));
            UT_ASSERT_FLT_EQ( 2.0, round_zero(2.1));

            UT_ASSERT_FLT_EQ(-0.0, round_zero(-0.9));
            UT_ASSERT_FLT_EQ(-1.0, round_zero(-1.0));
            UT_ASSERT_FLT_EQ(-1.0, round_zero(-1.1));
            UT_ASSERT_FLT_EQ(-1.0, round_zero(-1.49));
            UT_ASSERT_FLT_EQ(-1.0, round_zero(-1.50));
            UT_ASSERT_FLT_EQ(-1.0, round_zero(-1.51));
            UT_ASSERT_FLT_EQ(-1.0, round_zero(-1.9));
            UT_ASSERT_FLT_EQ(-2.0, round_zero(-2.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_inf) {
            UT_ASSERT_FLT_EQ( 1.0, round_inf(0.9));
            UT_ASSERT_FLT_EQ( 1.0, round_inf(1.0));
            UT_ASSERT_FLT_EQ( 2.0, round_inf(1.1));
            UT_ASSERT_FLT_EQ( 2.0, round_inf(1.49));
            UT_ASSERT_FLT_EQ( 2.0, round_inf(1.50));
            UT_ASSERT_FLT_EQ( 2.0, round_inf(1.51));
            UT_ASSERT_FLT_EQ( 2.0, round_inf(1.9));
            UT_ASSERT_FLT_EQ( 3.0, round_inf(2.1));

            UT_ASSERT_FLT_EQ(-1.0, round_inf(-0.9));
            UT_ASSERT_FLT_EQ(-1.0, round_inf(-1.0));
            UT_ASSERT_FLT_EQ(-2.0, round_inf(-1.1));
            UT_ASSERT_FLT_EQ(-2.0, round_inf(-1.49));
            UT_ASSERT_FLT_EQ(-2.0, round_inf(-1.50));
            UT_ASSERT_FLT_EQ(-2.0, round_inf(-1.51));
            UT_ASSERT_FLT_EQ(-2.0, round_inf(-1.9));
            UT_ASSERT_FLT_EQ(-3.0, round_inf(-2.1));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_math_eps) {
            //            UT_ASSERT_FLT_EQUAL(   5, round_int_eps(   3 ,   5));
            UT_ASSERT_FLT_EQ( 1.0, round_eps( 0.9 , 0.5, round_int));
            UT_ASSERT_FLT_EQ( 1.0, round_eps( 1.0 , 0.5, round_int));
            UT_ASSERT_FLT_EQ( 1.0, round_eps( 1.1 , 0.5, round_int));
            UT_ASSERT_FLT_EQ( 1.5, round_eps( 1.49, 0.5, round_int));
            UT_ASSERT_FLT_EQ( 1.5, round_eps( 1.50, 0.5, round_int));
            UT_ASSERT_FLT_EQ( 1.5, round_eps( 1.51, 0.5, round_int));
            UT_ASSERT_FLT_EQ( 2.0, round_eps( 1.9 , 0.5, round_int));
            UT_ASSERT_FLT_EQ( 2.0, round_eps( 2.1 , 0.5, round_int));

            UT_ASSERT_FLT_EQ(-1.0, round_eps(-0.9 , 0.5, round_int));
            UT_ASSERT_FLT_EQ(-1.0, round_eps(-1.0 , 0.5, round_int));
            UT_ASSERT_FLT_EQ(-1.0, round_eps(-1.1 , 0.5, round_int));
            UT_ASSERT_FLT_EQ(-1.5, round_eps(-1.49, 0.5, round_int));
            UT_ASSERT_FLT_EQ(-1.5, round_eps(-1.50, 0.5, round_int));
            UT_ASSERT_FLT_EQ(-1.5, round_eps(-1.51, 0.5, round_int));
            UT_ASSERT_FLT_EQ(-2.0, round_eps(-1.9 , 0.5, round_int));
            UT_ASSERT_FLT_EQ(-2.0, round_eps(-2.1 , 0.5, round_int));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_up_eps) {
            UT_ASSERT_FLT_EQ( 1.0, round_eps( 0.9 , 0.5, round_up));
            UT_ASSERT_FLT_EQ( 1.0, round_eps( 1.0 , 0.5, round_up));
            UT_ASSERT_FLT_EQ( 1.5, round_eps( 1.1 , 0.5, round_up));
            UT_ASSERT_FLT_EQ( 1.5, round_eps( 1.49, 0.5, round_up));
            UT_ASSERT_FLT_EQ( 1.5, round_eps( 1.50, 0.5, round_up));
            UT_ASSERT_FLT_EQ( 2.0, round_eps( 1.51, 0.5, round_up));
            UT_ASSERT_FLT_EQ( 2.0, round_eps( 1.9 , 0.5, round_up));
            UT_ASSERT_FLT_EQ( 2.0, round_eps( 2.0 , 0.5, round_up));
            UT_ASSERT_FLT_EQ( 2.5, round_eps( 2.1 , 0.5, round_up));

            UT_ASSERT_FLT_EQ(-0.5, round_eps(-0.9 , 0.5, round_up));
            UT_ASSERT_FLT_EQ(-1.0, round_eps(-1.0 , 0.5, round_up));
            UT_ASSERT_FLT_EQ(-1.0, round_eps(-1.1 , 0.5, round_up));
            UT_ASSERT_FLT_EQ(-1.0, round_eps(-1.49, 0.5, round_up));
            UT_ASSERT_FLT_EQ(-1.5, round_eps(-1.50, 0.5, round_up));
            UT_ASSERT_FLT_EQ(-1.5, round_eps(-1.51, 0.5, round_up));
            UT_ASSERT_FLT_EQ(-1.5, round_eps(-1.9 , 0.5, round_up));
            UT_ASSERT_FLT_EQ(-2.0, round_eps(-2.0 , 0.5, round_up));
            UT_ASSERT_FLT_EQ(-2.0, round_eps(-2.1 , 0.5, round_up));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_dn_eps) {
            UT_ASSERT_FLT_EQ( 0.5, round_eps( 0.9 , 0.5, round_dn));
            UT_ASSERT_FLT_EQ( 1.0, round_eps( 1.0 , 0.5, round_dn));
            UT_ASSERT_FLT_EQ( 1.0, round_eps( 1.1 , 0.5, round_dn));
            UT_ASSERT_FLT_EQ( 1.0, round_eps( 1.49, 0.5, round_dn));
            UT_ASSERT_FLT_EQ( 1.5, round_eps( 1.50, 0.5, round_dn));
            UT_ASSERT_FLT_EQ( 1.5, round_eps( 1.51, 0.5, round_dn));
            UT_ASSERT_FLT_EQ( 1.5, round_eps( 1.9 , 0.5, round_dn));
            UT_ASSERT_FLT_EQ( 2.0, round_eps( 2.0 , 0.5, round_dn));
            UT_ASSERT_FLT_EQ( 2.0, round_eps( 2.1 , 0.5, round_dn));

            UT_ASSERT_FLT_EQ(-1.0, round_eps(-0.9 , 0.5, round_dn));
            UT_ASSERT_FLT_EQ(-1.0, round_eps(-1.0 , 0.5, round_dn));
            UT_ASSERT_FLT_EQ(-1.5, round_eps(-1.1 , 0.5, round_dn));
            UT_ASSERT_FLT_EQ(-1.5, round_eps(-1.49, 0.5, round_dn));
            UT_ASSERT_FLT_EQ(-1.5, round_eps(-1.50, 0.5, round_dn));
            UT_ASSERT_FLT_EQ(-2.0, round_eps(-1.51, 0.5, round_dn));
            UT_ASSERT_FLT_EQ(-2.0, round_eps(-1.9 , 0.5, round_dn));
            UT_ASSERT_FLT_EQ(-2.0, round_eps(-2.0 , 0.5, round_dn));
            UT_ASSERT_FLT_EQ(-2.5, round_eps(-2.1 , 0.5, round_dn));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_zero_eps) {
            UT_ASSERT_FLT_EQ( 0.5, round_eps( 0.9 , 0.5, round_zero));
            UT_ASSERT_FLT_EQ( 1.0, round_eps( 1.0 , 0.5, round_zero));
            UT_ASSERT_FLT_EQ( 1.0, round_eps( 1.1 , 0.5, round_zero));
            UT_ASSERT_FLT_EQ( 1.0, round_eps( 1.49, 0.5, round_zero));
            UT_ASSERT_FLT_EQ( 1.5, round_eps( 1.50, 0.5, round_zero));
            UT_ASSERT_FLT_EQ( 1.5, round_eps( 1.51, 0.5, round_zero));
            UT_ASSERT_FLT_EQ( 1.5, round_eps( 1.9 , 0.5, round_zero));
            UT_ASSERT_FLT_EQ( 2.0, round_eps( 2.0 , 0.5, round_zero));
            UT_ASSERT_FLT_EQ( 2.0, round_eps( 2.1 , 0.5, round_zero));

            UT_ASSERT_FLT_EQ(-0.5, round_eps(-0.9 , 0.5, round_zero));
            UT_ASSERT_FLT_EQ(-1.0, round_eps(-1.0 , 0.5, round_zero));
            UT_ASSERT_FLT_EQ(-1.0, round_eps(-1.1 , 0.5, round_zero));
            UT_ASSERT_FLT_EQ(-1.0, round_eps(-1.49, 0.5, round_zero));
            UT_ASSERT_FLT_EQ(-1.5, round_eps(-1.50, 0.5, round_zero));
            UT_ASSERT_FLT_EQ(-1.5, round_eps(-1.51, 0.5, round_zero));
            UT_ASSERT_FLT_EQ(-1.5, round_eps(-1.9 , 0.5, round_zero));
            UT_ASSERT_FLT_EQ(-2.0, round_eps(-2.0 , 0.5, round_zero));
            UT_ASSERT_FLT_EQ(-2.0, round_eps(-2.1 , 0.5, round_zero));
        } UT_GROUP_END;

        UT_GROUP_BEG(round_inf_eps) {
            UT_ASSERT_FLT_EQ( 1.0, round_eps( 0.9 , 0.5, round_inf));
            UT_ASSERT_FLT_EQ( 1.0, round_eps( 1.0 , 0.5, round_inf));
            UT_ASSERT_FLT_EQ( 1.5, round_eps( 1.1 , 0.5, round_inf));
            UT_ASSERT_FLT_EQ( 1.5, round_eps( 1.49, 0.5, round_inf));
            UT_ASSERT_FLT_EQ( 1.5, round_eps( 1.50, 0.5, round_inf));
            UT_ASSERT_FLT_EQ( 2.0, round_eps( 1.51, 0.5, round_inf));
            UT_ASSERT_FLT_EQ( 2.0, round_eps( 1.9 , 0.5, round_inf));
            UT_ASSERT_FLT_EQ( 2.0, round_eps( 2.0 , 0.5, round_inf));
            UT_ASSERT_FLT_EQ( 2.5, round_eps( 2.1 , 0.5, round_inf));

            UT_ASSERT_FLT_EQ(-1.0, round_eps(-0.9 , 0.5, round_inf));
            UT_ASSERT_FLT_EQ(-1.0, round_eps(-1.0 , 0.5, round_inf));
            UT_ASSERT_FLT_EQ(-1.5, round_eps(-1.1 , 0.5, round_inf));
            UT_ASSERT_FLT_EQ(-1.5, round_eps(-1.49, 0.5, round_inf));
            UT_ASSERT_FLT_EQ(-1.5, round_eps(-1.50, 0.5, round_inf));
            UT_ASSERT_FLT_EQ(-2.0, round_eps(-1.51, 0.5, round_inf));
            UT_ASSERT_FLT_EQ(-2.0, round_eps(-1.9 , 0.5, round_inf));
            UT_ASSERT_FLT_EQ(-2.0, round_eps(-2.0 , 0.5, round_inf));
            UT_ASSERT_FLT_EQ(-2.5, round_eps(-2.1 , 0.5, round_inf));
        } UT_GROUP_END;
    } UT_GROUP_END;
}
