// Author                 : Seityagiya Terlekchi
// Contacts               : terlekchiseityaya@gmail.com
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2025 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_flag.h"

#define FLAG_POS_A 0
#define FLAG_POS_B 1
#define FLAG_POS_C 2

#define MASK_A 0b00000001  // VALUE = 1; POS = 0
#define MASK_B 0b00000010  // VALUE = 2; POS = 1
#define MASK_C 0b00000100  // VALUE = 4; POS = 2

int test_flag(void) {
    {
        us8_t x = 0b00000001;

        x = flag_all(us8_t);
        ASSERT_NUM_EQ(u8_c(0b11111111), x);
    }

    {
        us8_t x = 0b00000001;

        x = flag_clr();
        ASSERT_NUM_EQ(u8_c(0b00000000), x);
    }

    {
        us8_t x = 0b00000000;

        x = flag_set_pos(x, FLAG_POS_A);
        ASSERT_NUM_EQ(u8_c(0b00000001), x);

        x = flag_set_pos(x, FLAG_POS_B);
        ASSERT_NUM_EQ(u8_c(0b00000011), x);

        x = flag_set_pos(x, FLAG_POS_C);
        ASSERT_NUM_EQ(u8_c(0b00000111), x);
    }

    {
        us8_t x = 0b00000111;

        x = flag_res_pos(x, FLAG_POS_A);
        ASSERT_NUM_EQ(u8_c(0b00000110), x);

        x = flag_res_pos(x, FLAG_POS_B);
        ASSERT_NUM_EQ(u8_c(0b00000100), x);

        x = flag_res_pos(x, FLAG_POS_C);
        ASSERT_NUM_EQ(u8_c(0b00000000), x);
    }

    {
        us8_t x = 0;

        x = 0b00000111;
        x = flag_tog_pos(x, FLAG_POS_A);
        ASSERT_NUM_EQ(u8_c(0b00000110), x);

        x = 0b00000111;
        x = flag_tog_pos(x, FLAG_POS_B);
        ASSERT_NUM_EQ(u8_c(0b00000101), x);

        x = 0b00000111;
        x = flag_tog_pos(x, FLAG_POS_C);
        ASSERT_NUM_EQ(u8_c(0b00000011), x);
    }

    {
        us8_t x = 0b00010101;

        ASSERT_BOOL_TR(flag_chk_pos(x, FLAG_POS_A));
        ASSERT_BOOL_FL(flag_chk_pos(x, FLAG_POS_B));
        ASSERT_BOOL_TR(flag_chk_pos(x, FLAG_POS_C));
    }

    return 0;
}
