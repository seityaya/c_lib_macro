// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_bit.h"

UT_FUNC_GEN(test_bit_mask) {
    UT_GROUP_BEG(mask) {
        UT_GROUP_BEG(mask_up) {
            UT_ASSERT_BIT_EQ(u8_c(0b10001010), bit_mask_up(u8_c(0b00000000), u8_c(0b10001010)));
            UT_ASSERT_BIT_EQ(u8_c(0b10001011), bit_mask_up(u8_c(0b00000001), u8_c(0b10001010)));
            UT_ASSERT_BIT_EQ(u8_c(0b10001011), bit_mask_up(u8_c(0b10000011), u8_c(0b10001010)));
            UT_ASSERT_BIT_EQ(u8_c(0b10001111), bit_mask_up(u8_c(0b10000111), u8_c(0b00001010)));
            UT_ASSERT_BIT_EQ(u8_c(0b10001111), bit_mask_up(u8_c(0b10001111), u8_c(0b00001010)));
            UT_ASSERT_BIT_EQ(i8_c(0b10001010), bit_mask_up(i8_c(0b00000000), i8_c(0b10001010)));
            UT_ASSERT_BIT_EQ(i8_c(0b10001011), bit_mask_up(i8_c(0b00000001), i8_c(0b10001010)));
            UT_ASSERT_BIT_EQ(i8_c(0b10001011), bit_mask_up(i8_c(0b10000011), i8_c(0b10001010)));
            UT_ASSERT_BIT_EQ(i8_c(0b10001111), bit_mask_up(i8_c(0b10000111), i8_c(0b00001010)));
            UT_ASSERT_BIT_EQ(i8_c(0b10001111), bit_mask_up(i8_c(0b10001111), i8_c(0b00001010)));
        } UT_GROUP_END;

        UT_GROUP_BEG(mask_dw) {
            UT_ASSERT_BIT_EQ(u8_c(0b00000000), bit_mask_dw(u8_c(0b00000000), u8_c(0b10001010)));
            UT_ASSERT_BIT_EQ(u8_c(0b00000001), bit_mask_dw(u8_c(0b00000001), u8_c(0b10001010)));
            UT_ASSERT_BIT_EQ(u8_c(0b00000001), bit_mask_dw(u8_c(0b10000011), u8_c(0b10001010)));
            UT_ASSERT_BIT_EQ(u8_c(0b10000101), bit_mask_dw(u8_c(0b10000111), u8_c(0b00001010)));
            UT_ASSERT_BIT_EQ(u8_c(0b10000101), bit_mask_dw(u8_c(0b10001111), u8_c(0b00001010)));
            UT_ASSERT_BIT_EQ(i8_c(0b00000000), bit_mask_dw(i8_c(0b00000000), i8_c(0b10001010)));
            UT_ASSERT_BIT_EQ(i8_c(0b00000001), bit_mask_dw(i8_c(0b00000001), i8_c(0b10001010)));
            UT_ASSERT_BIT_EQ(i8_c(0b00000001), bit_mask_dw(i8_c(0b10000011), i8_c(0b10001010)));
            UT_ASSERT_BIT_EQ(i8_c(0b10000101), bit_mask_dw(i8_c(0b10000111), i8_c(0b00001010)));
            UT_ASSERT_BIT_EQ(i8_c(0b10000101), bit_mask_dw(i8_c(0b10001111), i8_c(0b00001010)));
        } UT_GROUP_END;

        UT_GROUP_BEG(mask_in) {
            UT_ASSERT_BIT_EQ(u8_c(0b10001010), bit_mask_in(u8_c(0b00000000), u8_c(0b10001010)));
            UT_ASSERT_BIT_EQ(u8_c(0b10001011), bit_mask_in(u8_c(0b00000001), u8_c(0b10001010)));
            UT_ASSERT_BIT_EQ(u8_c(0b00001001), bit_mask_in(u8_c(0b10000011), u8_c(0b10001010)));
            UT_ASSERT_BIT_EQ(u8_c(0b10001101), bit_mask_in(u8_c(0b10000111), u8_c(0b00001010)));
            UT_ASSERT_BIT_EQ(u8_c(0b10000101), bit_mask_in(u8_c(0b10001111), u8_c(0b00001010)));
            UT_ASSERT_BIT_EQ(i8_c(0b10001010), bit_mask_in(i8_c(0b00000000), i8_c(0b10001010)));
            UT_ASSERT_BIT_EQ(i8_c(0b10001011), bit_mask_in(i8_c(0b00000001), i8_c(0b10001010)));
            UT_ASSERT_BIT_EQ(i8_c(0b00001001), bit_mask_in(i8_c(0b10000011), i8_c(0b10001010)));
            UT_ASSERT_BIT_EQ(i8_c(0b10001101), bit_mask_in(i8_c(0b10000111), i8_c(0b00001010)));
            UT_ASSERT_BIT_EQ(i8_c(0b10000101), bit_mask_in(i8_c(0b10001111), i8_c(0b00001010)));
        } UT_GROUP_END;
    }UT_GROUP_END;
}
