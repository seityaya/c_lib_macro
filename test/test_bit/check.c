// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_bit.h"

UT_FUNC_GEN(test_bit_check) {
    UT_GROUP_BEG(check) {
        UT_GROUP_BEG(bit_get) {
            UT_ASSERT_BOOL_FL(bit_get(u8_c(0b00000000), 2));
            UT_ASSERT_BOOL_TR(bit_get(u8_c(0b00000010), 2));
            UT_ASSERT_BOOL_FL(bit_get(u8_c(0b11111101), 2));
            UT_ASSERT_BOOL_TR(bit_get(u8_c(0b11111111), 2));

            UT_ASSERT_BOOL_FL(bit_get(i8_c(0b00000000), 2));
            UT_ASSERT_BOOL_TR(bit_get(i8_c(0b00000010), 2));
            UT_ASSERT_BOOL_FL(bit_get(i8_c(0b11111101), 2));
            UT_ASSERT_BOOL_TR(bit_get(i8_c(0b11111111), 2));

            UT_ASSERT_BOOL_FL(bit_get(u8_c(0b00000000), CHAR_BIT));
            UT_ASSERT_BOOL_TR(bit_get(u8_c(0b10000000), CHAR_BIT));
            UT_ASSERT_BOOL_FL(bit_get(u8_c(0b01111111), CHAR_BIT));
            UT_ASSERT_BOOL_TR(bit_get(u8_c(0b11111111), CHAR_BIT));

            UT_ASSERT_BOOL_FL(bit_get(i8_c(0b00000000), CHAR_BIT));
            UT_ASSERT_BOOL_TR(bit_get(i8_c(0b10000000), CHAR_BIT));
            UT_ASSERT_BOOL_FL(bit_get(i8_c(0b01111111), CHAR_BIT));
            UT_ASSERT_BOOL_TR(bit_get(i8_c(0b11111111), CHAR_BIT));
        } UT_GROUP_END;

        UT_GROUP_BEG(bit_set) {
            UT_ASSERT_BIT_EQ(u8_c(0b00000010), bit_set(u8_c(0b00000000), 2));
            UT_ASSERT_BIT_EQ(u8_c(0b00000010), bit_set(u8_c(0b00000010), 2));
            UT_ASSERT_BIT_EQ(u8_c(0b11111111), bit_set(u8_c(0b11111101), 2));
            UT_ASSERT_BIT_EQ(u8_c(0b11111111), bit_set(u8_c(0b11111111), 2));
            UT_ASSERT_BIT_EQ(i8_c(0b00000010), bit_set(i8_c(0b00000000), 2));
            UT_ASSERT_BIT_EQ(i8_c(0b00000010), bit_set(i8_c(0b00000010), 2));
            UT_ASSERT_BIT_EQ(i8_c(0b11111111), bit_set(i8_c(0b11111101), 2));
            UT_ASSERT_BIT_EQ(i8_c(0b11111111), bit_set(i8_c(0b11111111), 2));
        } UT_GROUP_END;

        UT_GROUP_BEG(bit_res) {
            UT_ASSERT_BIT_EQ(u8_c(0b00000000), bit_res(u8_c(0b00000000), 2));
            UT_ASSERT_BIT_EQ(u8_c(0b00000000), bit_res(u8_c(0b00000010), 2));
            UT_ASSERT_BIT_EQ(u8_c(0b11111101), bit_res(u8_c(0b11111101), 2));
            UT_ASSERT_BIT_EQ(u8_c(0b11111101), bit_res(u8_c(0b11111111), 2));
            UT_ASSERT_BIT_EQ(i8_c(0b00000000), bit_res(i8_c(0b00000000), 2));
            UT_ASSERT_BIT_EQ(i8_c(0b00000000), bit_res(i8_c(0b00000010), 2));
            UT_ASSERT_BIT_EQ(i8_c(0b11111101), bit_res(i8_c(0b11111101), 2));
            UT_ASSERT_BIT_EQ(i8_c(0b11111101), bit_res(i8_c(0b11111111), 2));
        } UT_GROUP_END;

        UT_GROUP_BEG(bit_tog) {
            UT_ASSERT_BIT_EQ(u8_c(0b00000010), bit_tog(u8_c(0b00000000), 2));
            UT_ASSERT_BIT_EQ(u8_c(0b00000000), bit_tog(u8_c(0b00000010), 2));
            UT_ASSERT_BIT_EQ(u8_c(0b11111111), bit_tog(u8_c(0b11111101), 2));
            UT_ASSERT_BIT_EQ(u8_c(0b11111101), bit_tog(u8_c(0b11111111), 2));
            UT_ASSERT_BIT_EQ(i8_c(0b00000010), bit_tog(i8_c(0b00000000), 2));
            UT_ASSERT_BIT_EQ(i8_c(0b00000000), bit_tog(i8_c(0b00000010), 2));
            UT_ASSERT_BIT_EQ(i8_c(0b11111111), bit_tog(i8_c(0b11111101), 2));
            UT_ASSERT_BIT_EQ(i8_c(0b11111101), bit_tog(i8_c(0b11111111), 2));
        } UT_GROUP_END;

        UT_GROUP_BEG(bit_wrt) {
            UT_ASSERT_BIT_EQ(u8_c(0b00000000), bit_wrt(u8_c(0b00000000), 2, 0));
            UT_ASSERT_BIT_EQ(u8_c(0b00000000), bit_wrt(u8_c(0b00000010), 2, 0));
            UT_ASSERT_BIT_EQ(u8_c(0b11111101), bit_wrt(u8_c(0b11111101), 2, 0));
            UT_ASSERT_BIT_EQ(u8_c(0b11111101), bit_wrt(u8_c(0b11111111), 2, 0));
            UT_ASSERT_BIT_EQ(u8_c(0b00000010), bit_wrt(u8_c(0b00000000), 2, 1));
            UT_ASSERT_BIT_EQ(u8_c(0b00000010), bit_wrt(u8_c(0b00000010), 2, 1));
            UT_ASSERT_BIT_EQ(u8_c(0b11111111), bit_wrt(u8_c(0b11111101), 2, 1));
            UT_ASSERT_BIT_EQ(u8_c(0b11111111), bit_wrt(u8_c(0b11111111), 2, 1));
            UT_ASSERT_BIT_EQ(i8_c(0b00000000), bit_wrt(i8_c(0b00000000), 2, 0));
            UT_ASSERT_BIT_EQ(i8_c(0b00000000), bit_wrt(i8_c(0b00000010), 2, 0));
            UT_ASSERT_BIT_EQ(i8_c(0b11111101), bit_wrt(i8_c(0b11111101), 2, 0));
            UT_ASSERT_BIT_EQ(i8_c(0b11111101), bit_wrt(i8_c(0b11111111), 2, 0));
            UT_ASSERT_BIT_EQ(i8_c(0b00000010), bit_wrt(i8_c(0b00000000), 2, 1));
            UT_ASSERT_BIT_EQ(i8_c(0b00000010), bit_wrt(i8_c(0b00000010), 2, 1));
            UT_ASSERT_BIT_EQ(i8_c(0b11111111), bit_wrt(i8_c(0b11111101), 2, 1));
            UT_ASSERT_BIT_EQ(i8_c(0b11111111), bit_wrt(i8_c(0b11111111), 2, 1));
        } UT_GROUP_END;

        UT_GROUP_BEG(bit_inv) {
            UT_ASSERT_BIT_EQ(u8_c(0b11111111), bit_inv(u8_c(0b00000000)));
            UT_ASSERT_BIT_EQ(u8_c(0b11111101), bit_inv(u8_c(0b00000010)));
            UT_ASSERT_BIT_EQ(u8_c(0b00000010), bit_inv(u8_c(0b11111101)));
            UT_ASSERT_BIT_EQ(u8_c(0b00000000), bit_inv(u8_c(0b11111111)));
            UT_ASSERT_BIT_EQ(i8_c(0b11111111), bit_inv(i8_c(0b00000000)));
            UT_ASSERT_BIT_EQ(i8_c(0b11111101), bit_inv(i8_c(0b00000010)));
            UT_ASSERT_BIT_EQ(i8_c(0b00000010), bit_inv(i8_c(0b11111101)));
            UT_ASSERT_BIT_EQ(i8_c(0b00000000), bit_inv(i8_c(0b11111111)));
        } UT_GROUP_END;

        UT_GROUP_BEG(bit_rev) {
            UT_ASSERT_BIT_EQ(u8_c(0b00000000), bit_rev(u8_c(0b00000000)));
            UT_ASSERT_BIT_EQ(u8_c(0b01000000), bit_rev(u8_c(0b00000010)));
            UT_ASSERT_BIT_EQ(u8_c(0b10111111), bit_rev(u8_c(0b11111101)));
            UT_ASSERT_BIT_EQ(u8_c(0b11111111), bit_rev(u8_c(0b11111111)));
            UT_ASSERT_BIT_EQ(i8_c(0b00000000), bit_rev(i8_c(0b00000000)));
            UT_ASSERT_BIT_EQ(i8_c(0b01000000), bit_rev(i8_c(0b00000010)));
            UT_ASSERT_BIT_EQ(i8_c(0b10111111), bit_rev(i8_c(0b11111101)));
            UT_ASSERT_BIT_EQ(i8_c(0b11111111), bit_rev(i8_c(0b11111111)));
        } UT_GROUP_END;

        UT_GROUP_BEG(bit_seq) {
            UT_GROUP_BEG(u) {
                us8_t a = u8_c(0b10000000);
                us8_t b = u8_c(0b10000010);
                us8_t c = u8_c(0b10001100);
                us8_t d = u8_c(0b10001110);
                UT_ASSERT_BIT_EQ(umax_c(0b00000000), bit_seq(&a, 2, 3));
                UT_ASSERT_BIT_EQ(umax_c(0b00000001), bit_seq(&b, 2, 3));
                UT_ASSERT_BIT_EQ(umax_c(0b00000110), bit_seq(&c, 2, 3));
                UT_ASSERT_BIT_EQ(umax_c(0b00000111), bit_seq(&d, 2, 3));
                UT_ASSERT_BIT_EQ(umax_c(0b00000100), bit_seq(&a, 6, 3));
                UT_ASSERT_BIT_EQ(umax_c(0b00000100), bit_seq(&b, 6, 3));
                UT_ASSERT_BIT_EQ(umax_c(0b00000100), bit_seq(&c, 6, 3));
                UT_ASSERT_BIT_EQ(umax_c(0b00000100), bit_seq(&d, 6, 3));
            } UT_GROUP_END;

            UT_GROUP_BEG(i) {
                is8_t a = i8_c(0b10000000);
                is8_t b = i8_c(0b10000010);
                is8_t c = i8_c(0b10001100);
                is8_t d = i8_c(0b10001110);
                UT_ASSERT_BIT_EQ(umax_c(0b00000000), bit_seq(&a, 2, 3));
                UT_ASSERT_BIT_EQ(umax_c(0b00000001), bit_seq(&b, 2, 3));
                UT_ASSERT_BIT_EQ(umax_c(0b00000110), bit_seq(&c, 2, 3));
                UT_ASSERT_BIT_EQ(umax_c(0b00000111), bit_seq(&d, 2, 3));
                UT_ASSERT_BIT_EQ(umax_c(0b00000100), bit_seq(&a, 6, 3));
                UT_ASSERT_BIT_EQ(umax_c(0b00000100), bit_seq(&b, 6, 3));
                UT_ASSERT_BIT_EQ(umax_c(0b00000100), bit_seq(&c, 6, 3));
                UT_ASSERT_BIT_EQ(umax_c(0b00000100), bit_seq(&d, 6, 3));
            } UT_GROUP_END;
        } UT_GROUP_END;
    } UT_GROUP_END;
}
