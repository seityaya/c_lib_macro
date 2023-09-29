// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_bit.h"

UT_FUNC_GEN(test_bit_logical) {
    UT_GROUP_BEG(logical) {
        UT_GROUP_BEG(bit_not) {
            UT_ASSERT_BIT_EQ(u8_c(0b11111110), bit_not(u8_c(0b00000001)));
            UT_ASSERT_BIT_EQ(i8_c(0b11111110), bit_not(i8_c(0b00000001)));
        } UT_GROUP_END;

        UT_GROUP_BEG(bit_and) {
            UT_ASSERT_BIT_EQ(u8_c(0b00000001), bit_and(u8_c(0b00000011), u8_c(0b00000101)));
            UT_ASSERT_BIT_EQ(i8_c(0b00000001), bit_and(i8_c(0b00000011), i8_c(0b00000101)));
        }UT_GROUP_END;

        UT_GROUP_BEG(bit_or) {
            UT_ASSERT_BIT_EQ(u8_c(0b00000111), bit_or(u8_c(0b00000011), u8_c(0b00000101)));
            UT_ASSERT_BIT_EQ(i8_c(0b00000111), bit_or(i8_c(0b00000011), i8_c(0b00000101)));
        }UT_GROUP_END;

        UT_GROUP_BEG(bit_nand) {
            UT_ASSERT_BIT_EQ(u8_c(0b11111110), bit_nand(u8_c(0b00000011), u8_c(0b00000101)));
            UT_ASSERT_BIT_EQ(i8_c(0b11111110), bit_nand(i8_c(0b00000011), i8_c(0b00000101)));
        }UT_GROUP_END;

        UT_GROUP_BEG(bit_nor) {
            UT_ASSERT_BIT_EQ(u8_c(0b11111000), bit_nor(u8_c(0b00000011), u8_c(0b00000101)));
            UT_ASSERT_BIT_EQ(i8_c(0b11111000), bit_nor(i8_c(0b00000011), i8_c(0b00000101)));
        }UT_GROUP_END;

        UT_GROUP_BEG(bit_xand) {
            UT_ASSERT_BIT_EQ(u8_c(0b11111001), bit_xand(u8_c(0b00000011), u8_c(0b00000101)));
            UT_ASSERT_BIT_EQ(i8_c(0b11111001), bit_xand(i8_c(0b00000011), i8_c(0b00000101)));
        }UT_GROUP_END;

        UT_GROUP_BEG(bit_xor) {
            UT_ASSERT_BIT_EQ(u8_c(0b00000110), bit_xor(u8_c(0b00000011), u8_c(0b00000101)));
            UT_ASSERT_BIT_EQ(i8_c(0b00000110), bit_xor(i8_c(0b00000011), i8_c(0b00000101)));
        }UT_GROUP_END;
    } UT_GROUP_END;
}
