// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_flag.h"

#define FLAG_A 0
#define FLAG_B 1
#define FLAG_C 2

#define MASK_A 0b00000001
#define MASK_B 0b00000010
#define MASK_C 0b00000100

UT_FUNC_GEN(test_flag) {
    UT_GROUP_BEG(set_all) {
        us8_t x = 0b00000001;
        flag_all(x);
        UT_ASSERT_NUM_EQ(u8_c(0b11111111), x);
    } UT_GROUP_END;

    UT_GROUP_BEG(clr_all) {
        us8_t x = 0b00000001;
        flag_clr(x);
        UT_ASSERT_NUM_EQ(u8_c(0b00000000), x);
    } UT_GROUP_END;

    UT_GROUP_BEG(set) {
        us8_t x = 0b00000000;
        x = flag_set_pos(x, FLAG_A);
        UT_ASSERT_NUM_EQ(u8_c(0b00000001), x);

        x = flag_set_pos(x, FLAG_B);
        UT_ASSERT_NUM_EQ(u8_c(0b00000011), x);

        x = flag_set_pos(x, FLAG_C);
        UT_ASSERT_NUM_EQ(u8_c(0b00000111), x);
    }
    UT_GROUP_END;

    UT_GROUP_BEG(res) {
        us8_t x = 0b00000111;
        x = flag_res_pos(x, FLAG_A);
        UT_ASSERT_NUM_EQ(u8_c(0b00000110), x);

        x = flag_res_pos(x, FLAG_B);
        UT_ASSERT_NUM_EQ(u8_c(0b00000100), x);

        x = flag_res_pos(x, FLAG_C);
        UT_ASSERT_NUM_EQ(u8_c(0b00000000), x);
    }
    UT_GROUP_END;

    UT_GROUP_BEG(tog) {
        us8_t x = 0;
        x = 0b00000111;
        x = flag_tog_pos(x, FLAG_A);
        UT_ASSERT_NUM_EQ(u8_c(0b00000110), x);

        x = 0b00000111;
        x = flag_tog_pos(x, FLAG_B);
        UT_ASSERT_NUM_EQ(u8_c(0b00000101), x);

        x = 0b00000111;
        x = flag_tog_pos(x, FLAG_C);
        UT_ASSERT_NUM_EQ(u8_c(0b00000011), x);
    }
    UT_GROUP_END;

    UT_GROUP_BEG(chk) {
        us8_t x = 0b00010101;

        UT_ASSERT_BOOL_TR(flag_chk_pos(x, FLAG_A));
        UT_ASSERT_BOOL_FL(flag_chk_pos(x, FLAG_B));
        UT_ASSERT_BOOL_TR(flag_chk_pos(x, FLAG_C));
    } UT_GROUP_END;
}
