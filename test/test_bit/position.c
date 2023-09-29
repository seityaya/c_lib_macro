// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_bit.h"

UT_FUNC_GEN(test_bit_position) {
    UT_GROUP_BEG(position) {
        UT_GROUP_BEG(0) {
            UT_GROUP_BEG(beg) {
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(u8_c(0b00000000)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_0_beg(u8_c(0b11111111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(u8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_beg(u8_c(0b01111111)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_0_beg(u8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(u8_c(0b00000010)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(u8_c(0b00000100)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(u8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(u8_c(0b01000000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(u8_c(0b00100000)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_0_beg(u8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 3), bit_0_beg(u8_c(0b00000011)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_0_beg(u8_c(0b00000111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(u8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(u8_c(0b11000000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(u8_c(0b11100000)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_0_beg(u8_c(0b01010101)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(u8_c(0b10101010)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_0_beg(u8_c(0b10000001)));
                UT_ASSERT_NUM_EQ(imax_c( 3), bit_0_beg(u8_c(0b11000011)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_0_beg(u8_c(0b11100111)));
                UT_ASSERT_NUM_EQ(imax_c( 5), bit_0_beg(u8_c(0b11101111)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_0_beg(u8_c(0b11110111)));

                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(i8_c(0b00000000)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_0_beg(i8_c(0b11111111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(i8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_beg(i8_c(0b01111111)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_0_beg(i8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(i8_c(0b00000010)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(i8_c(0b00000100)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(i8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(i8_c(0b01000000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(i8_c(0b00100000)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_0_beg(i8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 3), bit_0_beg(i8_c(0b00000011)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_0_beg(i8_c(0b00000111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(i8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(i8_c(0b11000000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(i8_c(0b11100000)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_0_beg(i8_c(0b01010101)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_beg(i8_c(0b10101010)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_0_beg(i8_c(0b10000001)));
                UT_ASSERT_NUM_EQ(imax_c( 3), bit_0_beg(i8_c(0b11000011)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_0_beg(i8_c(0b11100111)));
                UT_ASSERT_NUM_EQ(imax_c( 5), bit_0_beg(i8_c(0b11101111)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_0_beg(i8_c(0b11110111)));
            } UT_GROUP_END;

            UT_GROUP_BEG(end) {
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(u8_c(0b00000000)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_0_end(u8_c(0b11111111)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_end(u8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(u8_c(0b01111111)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(u8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(u8_c(0b00000010)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(u8_c(0b00000100)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_end(u8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(u8_c(0b01000000)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(u8_c(0b00100000)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(u8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(u8_c(0b00000011)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(u8_c(0b00000111)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_end(u8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 6), bit_0_end(u8_c(0b11000000)));
                UT_ASSERT_NUM_EQ(imax_c( 5), bit_0_end(u8_c(0b11100000)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(u8_c(0b01010101)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_end(u8_c(0b10101010)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_end(u8_c(0b10000001)));
                UT_ASSERT_NUM_EQ(imax_c( 6), bit_0_end(u8_c(0b11000011)));
                UT_ASSERT_NUM_EQ(imax_c( 5), bit_0_end(u8_c(0b11100111)));
                UT_ASSERT_NUM_EQ(imax_c( 5), bit_0_end(u8_c(0b11101111)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_0_end(u8_c(0b11110111)));

                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(i8_c(0b00000000)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_0_end(i8_c(0b11111111)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_end(i8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(i8_c(0b01111111)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(i8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(i8_c(0b00000010)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(i8_c(0b00000100)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_end(i8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(i8_c(0b01000000)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(i8_c(0b00100000)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(i8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(i8_c(0b00000011)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(i8_c(0b00000111)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_end(i8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 6), bit_0_end(i8_c(0b11000000)));
                UT_ASSERT_NUM_EQ(imax_c( 5), bit_0_end(i8_c(0b11100000)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_end(i8_c(0b01010101)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_end(i8_c(0b10101010)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_end(i8_c(0b10000001)));
                UT_ASSERT_NUM_EQ(imax_c( 6), bit_0_end(i8_c(0b11000011)));
                UT_ASSERT_NUM_EQ(imax_c( 5), bit_0_end(i8_c(0b11100111)));
                UT_ASSERT_NUM_EQ(imax_c( 5), bit_0_end(i8_c(0b11101111)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_0_end(i8_c(0b11110111)));
            } UT_GROUP_END;

            UT_GROUP_BEG(cnt) {
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_cnt(u8_c(0b00000000)));
                UT_ASSERT_NUM_EQ(imax_c( 0), bit_0_cnt(u8_c(0b11111111)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_cnt(u8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_cnt(u8_c(0b01111111)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_cnt(u8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_cnt(u8_c(0b00000010)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_cnt(u8_c(0b00000100)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_cnt(u8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_cnt(u8_c(0b01000000)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_cnt(u8_c(0b00100000)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_cnt(u8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 6), bit_0_cnt(u8_c(0b00000011)));
                UT_ASSERT_NUM_EQ(imax_c( 5), bit_0_cnt(u8_c(0b00000111)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_cnt(u8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 6), bit_0_cnt(u8_c(0b11000000)));
                UT_ASSERT_NUM_EQ(imax_c( 5), bit_0_cnt(u8_c(0b11100000)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_0_cnt(u8_c(0b01010101)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_0_cnt(u8_c(0b10101010)));
                UT_ASSERT_NUM_EQ(imax_c( 6), bit_0_cnt(u8_c(0b10000001)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_0_cnt(u8_c(0b11000011)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_0_cnt(u8_c(0b11100111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_cnt(u8_c(0b11101111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_cnt(u8_c(0b11110111)));

                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_cnt(i8_c(0b00000000)));
                UT_ASSERT_NUM_EQ(imax_c( 0), bit_0_cnt(i8_c(0b11111111)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_cnt(i8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_cnt(i8_c(0b01111111)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_cnt(i8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_cnt(i8_c(0b00000010)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_cnt(i8_c(0b00000100)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_cnt(i8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_cnt(i8_c(0b01000000)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_cnt(i8_c(0b00100000)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_cnt(i8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 6), bit_0_cnt(i8_c(0b00000011)));
                UT_ASSERT_NUM_EQ(imax_c( 5), bit_0_cnt(i8_c(0b00000111)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_0_cnt(i8_c(0b01010101)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_0_cnt(i8_c(0b10101010)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_cnt(i8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 6), bit_0_cnt(i8_c(0b11000000)));
                UT_ASSERT_NUM_EQ(imax_c( 5), bit_0_cnt(i8_c(0b11100000)));
                UT_ASSERT_NUM_EQ(imax_c( 6), bit_0_cnt(i8_c(0b10000001)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_0_cnt(i8_c(0b11000011)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_0_cnt(i8_c(0b11100111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_cnt(i8_c(0b11101111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_cnt(i8_c(0b11110111)));
            } UT_GROUP_END;

            UT_GROUP_BEG(pos) {
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_0_pos(u8_c(0b00000000)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_0_pos(u8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_0_pos(u8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_0_pos(u8_c(0b11000000)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_0_pos(u8_c(0b11111111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_pos(u8_c(0b11111110)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_pos(u8_c(0b01111111)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_0_pos(u8_c(0b00111111)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_0_pos(u8_c(0b11111101)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_pos(u8_c(0b10111111)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_0_pos(u8_c(0b11110111)));
                UT_ASSERT_NUM_EQ(imax_c( 5), bit_0_pos(u8_c(0b11101111)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_0_pos(i8_c(0b00000000)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_0_pos(i8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_0_pos(i8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_0_pos(i8_c(0b11000000)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_0_pos(i8_c(0b11111111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_0_pos(i8_c(0b11111110)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_0_pos(i8_c(0b01111111)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_0_pos(i8_c(0b00111111)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_0_pos(i8_c(0b11111101)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_0_pos(i8_c(0b10111111)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_0_pos(i8_c(0b11110111)));
                UT_ASSERT_NUM_EQ(imax_c( 5), bit_0_pos(i8_c(0b11101111)));
            } UT_GROUP_END;
        } UT_GROUP_END;

        UT_GROUP_BEG(1) {
            UT_GROUP_BEG(beg) {
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_1_beg(u8_c(0b00000000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(u8_c(0b11111111)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_beg(u8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(u8_c(0b01111111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(u8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_1_beg(u8_c(0b00000010)));
                UT_ASSERT_NUM_EQ(imax_c( 3), bit_1_beg(u8_c(0b00000100)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_beg(u8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_1_beg(u8_c(0b01000000)));
                UT_ASSERT_NUM_EQ(imax_c( 6), bit_1_beg(u8_c(0b00100000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(u8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(u8_c(0b00000011)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(u8_c(0b00000111)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_beg(u8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_1_beg(u8_c(0b11000000)));
                UT_ASSERT_NUM_EQ(imax_c( 6), bit_1_beg(u8_c(0b11100000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(u8_c(0b01010101)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_1_beg(u8_c(0b10101010)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(u8_c(0b10000001)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(u8_c(0b11000011)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(u8_c(0b11100111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(u8_c(0b11101111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(u8_c(0b11110111)));

                UT_ASSERT_NUM_EQ(imax_c(-1), bit_1_beg(i8_c(0b00000000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(i8_c(0b11111111)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_beg(i8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(i8_c(0b01111111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(i8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_1_beg(i8_c(0b00000010)));
                UT_ASSERT_NUM_EQ(imax_c( 3), bit_1_beg(i8_c(0b00000100)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_beg(i8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_1_beg(i8_c(0b01000000)));
                UT_ASSERT_NUM_EQ(imax_c( 6), bit_1_beg(i8_c(0b00100000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(i8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(i8_c(0b00000011)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(i8_c(0b00000111)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_beg(i8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_1_beg(i8_c(0b11000000)));
                UT_ASSERT_NUM_EQ(imax_c( 6), bit_1_beg(i8_c(0b11100000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(i8_c(0b01010101)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_1_beg(i8_c(0b10101010)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(i8_c(0b10000001)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(i8_c(0b11000011)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(i8_c(0b11100111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(i8_c(0b11101111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_beg(i8_c(0b11110111)));
            } UT_GROUP_END;

            UT_GROUP_BEG(end) {
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_1_end(u8_c(0b00000000)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(u8_c(0b11111111)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(u8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_1_end(u8_c(0b01111111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_end(u8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_1_end(u8_c(0b00000010)));
                UT_ASSERT_NUM_EQ(imax_c( 3), bit_1_end(u8_c(0b00000100)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(u8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_1_end(u8_c(0b01000000)));
                UT_ASSERT_NUM_EQ(imax_c( 6), bit_1_end(u8_c(0b00100000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_end(u8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_1_end(u8_c(0b00000011)));
                UT_ASSERT_NUM_EQ(imax_c( 3), bit_1_end(u8_c(0b00000111)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(u8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(u8_c(0b11000000)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(u8_c(0b11100000)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_1_end(u8_c(0b01010101)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(u8_c(0b10101010)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(u8_c(0b10000001)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(u8_c(0b11000011)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(u8_c(0b11100111)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(u8_c(0b11101111)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(u8_c(0b11110111)));

                UT_ASSERT_NUM_EQ(imax_c(-1), bit_1_end(i8_c(0b00000000)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(i8_c(0b11111111)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(i8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_1_end(i8_c(0b01111111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_end(i8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_1_end(i8_c(0b00000010)));
                UT_ASSERT_NUM_EQ(imax_c( 3), bit_1_end(i8_c(0b00000100)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(i8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_1_end(i8_c(0b01000000)));
                UT_ASSERT_NUM_EQ(imax_c( 6), bit_1_end(i8_c(0b00100000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_end(i8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_1_end(i8_c(0b00000011)));
                UT_ASSERT_NUM_EQ(imax_c( 3), bit_1_end(i8_c(0b00000111)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(i8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(i8_c(0b11000000)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(i8_c(0b11100000)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_1_end(i8_c(0b01010101)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(i8_c(0b10101010)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(i8_c(0b10000001)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(i8_c(0b11000011)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(i8_c(0b11100111)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(i8_c(0b11101111)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_end(i8_c(0b11110111)));
            } UT_GROUP_END;

            UT_GROUP_BEG(cnt) {
                UT_ASSERT_NUM_EQ(imax_c( 0), bit_1_cnt(u8_c(0b00000000)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_cnt(u8_c(0b11111111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_cnt(u8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_1_cnt(u8_c(0b01111111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_cnt(u8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_cnt(u8_c(0b00000010)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_cnt(u8_c(0b00000100)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_cnt(u8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_cnt(u8_c(0b01000000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_cnt(u8_c(0b00100000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_cnt(u8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_1_cnt(u8_c(0b00000011)));
                UT_ASSERT_NUM_EQ(imax_c( 3), bit_1_cnt(u8_c(0b00000111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_cnt(u8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_1_cnt(u8_c(0b11000000)));
                UT_ASSERT_NUM_EQ(imax_c( 3), bit_1_cnt(u8_c(0b11100000)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_1_cnt(u8_c(0b01010101)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_1_cnt(u8_c(0b10101010)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_1_cnt(u8_c(0b10000001)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_1_cnt(u8_c(0b11000011)));
                UT_ASSERT_NUM_EQ(imax_c( 6), bit_1_cnt(u8_c(0b11100111)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_1_cnt(u8_c(0b11101111)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_1_cnt(u8_c(0b11110111)));

                UT_ASSERT_NUM_EQ(imax_c( 0), bit_1_cnt(i8_c(0b00000000)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_cnt(i8_c(0b11111111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_cnt(i8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_1_cnt(i8_c(0b01111111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_cnt(i8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_cnt(i8_c(0b00000010)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_cnt(i8_c(0b00000100)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_cnt(i8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_cnt(i8_c(0b01000000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_cnt(i8_c(0b00100000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_cnt(i8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_1_cnt(i8_c(0b00000011)));
                UT_ASSERT_NUM_EQ(imax_c( 3), bit_1_cnt(i8_c(0b00000111)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_cnt(i8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_1_cnt(i8_c(0b11000000)));
                UT_ASSERT_NUM_EQ(imax_c( 3), bit_1_cnt(i8_c(0b11100000)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_1_cnt(i8_c(0b01010101)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_1_cnt(i8_c(0b10101010)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_1_cnt(i8_c(0b10000001)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_1_cnt(i8_c(0b11000011)));
                UT_ASSERT_NUM_EQ(imax_c( 6), bit_1_cnt(i8_c(0b11100111)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_1_cnt(i8_c(0b11101111)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_1_cnt(i8_c(0b11110111)));
            } UT_GROUP_END;

            UT_GROUP_BEG(pos) {
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_1_pos(u8_c(0b11111111)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_1_pos(u8_c(0b11111110)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_1_pos(u8_c(0b01111111)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_1_pos(u8_c(0b00111111)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_1_pos(u8_c(0b00000000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_pos(u8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_pos(u8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_1_pos(u8_c(0b11000000)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_1_pos(u8_c(0b00000010)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_1_pos(u8_c(0b01000000)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_1_pos(u8_c(0b00001000)));
                UT_ASSERT_NUM_EQ(imax_c( 5), bit_1_pos(u8_c(0b00010000)));

                UT_ASSERT_NUM_EQ(imax_c(-1), bit_1_pos(i8_c(0b11111111)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_1_pos(i8_c(0b11111110)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_1_pos(i8_c(0b01111111)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_1_pos(i8_c(0b00111111)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_1_pos(i8_c(0b00000000)));
                UT_ASSERT_NUM_EQ(imax_c( 1), bit_1_pos(i8_c(0b00000001)));
                UT_ASSERT_NUM_EQ(imax_c( 8), bit_1_pos(i8_c(0b10000000)));
                UT_ASSERT_NUM_EQ(imax_c(-1), bit_1_pos(i8_c(0b11000000)));
                UT_ASSERT_NUM_EQ(imax_c( 2), bit_1_pos(i8_c(0b00000010)));
                UT_ASSERT_NUM_EQ(imax_c( 7), bit_1_pos(i8_c(0b01000000)));
                UT_ASSERT_NUM_EQ(imax_c( 4), bit_1_pos(i8_c(0b00001000)));
                UT_ASSERT_NUM_EQ(imax_c( 5), bit_1_pos(i8_c(0b00010000)));
            } UT_GROUP_END;
        } UT_GROUP_END;
    } UT_GROUP_END;
}
