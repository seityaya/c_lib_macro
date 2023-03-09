//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.01
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_bit.h"

UT_FUNC_GEN(test_bit) {
    UT_GROUP_BEG(bit) {
        UT_GROUP_BEG(0) {
            UT_GROUP_BEG(eql) {
                UT_ASSERT_BIT_EQUAL(i8_c(  0), i8_c(0b00000000));
                UT_ASSERT_BIT_EQUAL(u8_c(  0), u8_c(0b00000000));
                UT_ASSERT_BIT_EQUAL(i8_c(  1), i8_c(0b00000001));
                UT_ASSERT_BIT_EQUAL(u8_c(  1), u8_c(0b00000001));
                UT_ASSERT_BIT_EQUAL(i8_c( -1), i8_c(0b11111111));
                UT_ASSERT_BIT_EQUAL(u8_c(255), u8_c(0b11111111));
                UT_ASSERT_BIT_EQUAL(i8_c( -1), i8_c(0b111111111));
                UT_ASSERT_BIT_EQUAL(u8_c(255), u8_c(0b111111111));
                UT_ASSERT_BIT_EQUAL(u8_c(256), u8_c(0b000000000));
            }UT_GROUP_END;

            UT_GROUP_BEG(beg) {
                UT_ASSERT_BIT_EQUAL(imax_c(1), bit_0_beg(u8_c(0b00000000)));
                UT_ASSERT_BIT_EQUAL(imax_c(2), bit_0_beg(u8_c(0b00000001)));
                UT_ASSERT_BIT_EQUAL(imax_c(1), bit_0_beg(u8_c(0b00000010)));
                UT_ASSERT_BIT_EQUAL(imax_c(1), bit_0_beg(u8_c(0b00000110)));
                UT_ASSERT_BIT_EQUAL(imax_c(1), bit_0_beg(u8_c(0b10000000)));
                UT_ASSERT_BIT_EQUAL(imax_c(1), bit_0_beg(u8_c(0b11000000)));
                UT_ASSERT_BIT_EQUAL(imax_c(3), bit_0_beg(u8_c(0b00000011)));
                UT_ASSERT_BIT_EQUAL(imax_c(4), bit_0_beg(u8_c(0b00000111)));
                UT_ASSERT_BIT_EQUAL(imax_c(4), bit_0_beg(u8_c(0b11100111)));
                UT_ASSERT_BIT_EQUAL(imax_c(4), bit_0_beg(u8_c(0b11110111)));
                UT_ASSERT_BIT_EQUAL(imax_c(7), bit_0_beg(u8_c(0b00111111)));
                UT_ASSERT_BIT_EQUAL(imax_c(8), bit_0_beg(u8_c(0b01111111)));
                UT_ASSERT_BIT_EQUAL(imax_c(0), bit_0_beg(u8_c(0b11111111)));
            } UT_GROUP_END;

            UT_GROUP_BEG(end) {
                UT_ASSERT_BIT_EQUAL(imax_c(0), bit_0_end(u8_c(0b11111111)));
                UT_ASSERT_BIT_EQUAL(imax_c(1), bit_0_end(u8_c(0b11111110)));
                UT_ASSERT_BIT_EQUAL(imax_c(2), bit_0_end(u8_c(0b11111100)));
                UT_ASSERT_BIT_EQUAL(imax_c(2), bit_0_end(u8_c(0b11111101)));
                UT_ASSERT_BIT_EQUAL(imax_c(3), bit_0_end(u8_c(0b11111011)));
                UT_ASSERT_BIT_EQUAL(imax_c(8), bit_0_end(u8_c(0b01111111)));
                UT_ASSERT_BIT_EQUAL(imax_c(6), bit_0_end(u8_c(0b11000000)));
                UT_ASSERT_BIT_EQUAL(imax_c(6), bit_0_end(u8_c(0b11000011)));
                UT_ASSERT_BIT_EQUAL(imax_c(8), bit_0_end(u8_c(0b00000000)));
                UT_ASSERT_BIT_EQUAL(imax_c(8), bit_0_end(u8_c(0b00000001)));
                UT_ASSERT_BIT_EQUAL(imax_c(7), bit_0_end(u8_c(0b10000000)));
                UT_ASSERT_BIT_EQUAL(imax_c(8), bit_0_end(u8_c(0b01111111)));
            } UT_GROUP_END;

            UT_GROUP_BEG(cnt) {
                UT_ASSERT_BIT_EQUAL(imax_c( 0), bit_0_cnt(u32_c(0xFFFFFFFF)));
                UT_ASSERT_BIT_EQUAL(imax_c( 8), bit_0_cnt(u32_c(0xFFFFFF00)));
                UT_ASSERT_BIT_EQUAL(imax_c(32), bit_0_cnt(u32_c(0x00000000)));
                UT_ASSERT_BIT_EQUAL(imax_c( 0), bit_0_cnt(u8_c(0x000000FF)));

                UT_ASSERT_BIT_EQUAL(imax_c( 8), bit_0_cnt(u8_c(0b00000000)));
                UT_ASSERT_BIT_EQUAL(imax_c( 7), bit_0_cnt(u8_c(0b00000001)));
                UT_ASSERT_BIT_EQUAL(imax_c( 6), bit_0_cnt(u8_c(0b00000101)));
            } UT_GROUP_END;

            UT_GROUP_BEG(pos) {
                UT_ASSERT_BIT_EQUAL(imax_c(-1), bit_0_pos(u8_c(0b00000000)));
                UT_ASSERT_BIT_EQUAL(imax_c(-1), bit_0_pos(u8_c(0b00000001)));
                UT_ASSERT_BIT_EQUAL(imax_c( 0), bit_0_pos(u8_c(0b11111111)));
                UT_ASSERT_BIT_EQUAL(imax_c( 1), bit_0_pos(u8_c(0b11111110)));
                UT_ASSERT_BIT_EQUAL(imax_c( 2), bit_0_pos(u8_c(0b11111101)));
                UT_ASSERT_BIT_EQUAL(imax_c(-1), bit_0_pos(u8_c(0b10101111)));
            } UT_GROUP_END;
        } UT_GROUP_END;

        UT_GROUP_BEG(1) {
            UT_GROUP_BEG(beg) {
                UT_ASSERT_BIT_EQUAL(imax_c( 0), bit_1_beg(0b00000000));
                UT_ASSERT_BIT_EQUAL(imax_c( 1), bit_1_beg(0b00000001));
                UT_ASSERT_BIT_EQUAL(imax_c( 8), bit_1_beg(0b10000000));
                UT_ASSERT_BIT_EQUAL(imax_c( 2), bit_1_beg(0b00000010));
                UT_ASSERT_BIT_EQUAL(imax_c( 1), bit_1_beg(0b00000011));
                UT_ASSERT_BIT_EQUAL(imax_c( 2), bit_1_beg(0b00000110));
                UT_ASSERT_BIT_EQUAL(imax_c( 7), bit_1_beg(0b11000000));
                UT_ASSERT_BIT_EQUAL(imax_c( 4), bit_1_beg(0b00001000));
                UT_ASSERT_BIT_EQUAL(imax_c( 1), bit_1_beg(0b10011001));
                UT_ASSERT_BIT_EQUAL(imax_c( 1), bit_1_beg(0b11111111));
                UT_ASSERT_BIT_EQUAL(imax_c( 1), bit_1_beg(0xFFFFFFFF));
                UT_ASSERT_BIT_EQUAL(imax_c(32), bit_1_beg(0x80000000));
                UT_ASSERT_BIT_EQUAL(imax_c(29), bit_1_beg(0xF0000000));
                UT_ASSERT_BIT_EQUAL(imax_c(64), bit_1_beg(0x8000000000000000));
            } UT_GROUP_END;

            UT_GROUP_BEG(end) {
                UT_ASSERT_BIT_EQUAL(imax_c( 0), bit_1_end(0b00000000));
                UT_ASSERT_BIT_EQUAL(imax_c( 1), bit_1_end(0b00000001));
                UT_ASSERT_BIT_EQUAL(imax_c( 8), bit_1_end(0b10000000));
                UT_ASSERT_BIT_EQUAL(imax_c( 2), bit_1_end(0b00000010));
                UT_ASSERT_BIT_EQUAL(imax_c( 2), bit_1_end(0b00000011));
                UT_ASSERT_BIT_EQUAL(imax_c( 3), bit_1_end(0b00000110));
                UT_ASSERT_BIT_EQUAL(imax_c( 8), bit_1_end(0b11000000));
                UT_ASSERT_BIT_EQUAL(imax_c( 4), bit_1_end(0b00001000));
                UT_ASSERT_BIT_EQUAL(imax_c( 8), bit_1_end(0b10011001));
                UT_ASSERT_BIT_EQUAL(imax_c( 8), bit_1_end(0b11111111));
                UT_ASSERT_BIT_EQUAL(imax_c(32), bit_1_end(0xFFFFFFFF));
                UT_ASSERT_BIT_EQUAL(imax_c(32), bit_1_end(0x80000000));
                UT_ASSERT_BIT_EQUAL(imax_c(32), bit_1_end(0xF0000000));
                UT_ASSERT_BIT_EQUAL(imax_c(64), bit_1_end(0x8000000000000000));
            } UT_GROUP_END;

            UT_GROUP_BEG(cnt) {
                UT_ASSERT_BIT_EQUAL(imax_c( 0), bit_1_cnt(0b00000000));
                UT_ASSERT_BIT_EQUAL(imax_c( 1), bit_1_cnt(0b00000001));
                UT_ASSERT_BIT_EQUAL(imax_c( 2), bit_1_cnt(0b0000000101));
                UT_ASSERT_BIT_EQUAL(imax_c(24), bit_1_cnt(0xFFFFFF));
            } UT_GROUP_END;

            UT_GROUP_BEG(pos) {
                UT_ASSERT_BIT_EQUAL(imax_c( 0), bit_1_pos(0b00000000));
                UT_ASSERT_BIT_EQUAL(imax_c( 1), bit_1_pos(0b00000001));
                UT_ASSERT_BIT_EQUAL(imax_c( 3), bit_1_pos(0b00000100));
                UT_ASSERT_BIT_EQUAL(imax_c(-1), bit_1_pos(0b00000101));
                UT_ASSERT_BIT_EQUAL(imax_c(-1), bit_1_pos(0b11000101));
            } UT_GROUP_END;
        } UT_GROUP_END;

        UT_GROUP_BEG(get) {
            UT_ASSERT_BIT_EQUAL(0, bit_get(0b0001, 0));
            UT_ASSERT_BIT_EQUAL(1, bit_get(0b0001, 1));
            UT_ASSERT_BIT_EQUAL(0, bit_get(0b0001, 2));
        } UT_GROUP_END;

        UT_GROUP_BEG(set) {
            UT_ASSERT_BIT_EQUAL(0, bit_set(0, 0));
            UT_ASSERT_BIT_EQUAL(1, bit_set(0, 1));
            UT_ASSERT_BIT_EQUAL(2, bit_set(0, 2));
        } UT_GROUP_END;

        UT_GROUP_BEG(res) {
            UT_ASSERT_BIT_EQUAL(0b01110, bit_res(0b01110, 0));
            UT_ASSERT_BIT_EQUAL(0b01110, bit_res(0b01110, 1));
            UT_ASSERT_BIT_EQUAL(0b01100, bit_res(0b01110, 2));
            UT_ASSERT_BIT_EQUAL(0b00110, bit_res(0b01110, 4));
        } UT_GROUP_END;

        UT_GROUP_BEG(tog) {
            UT_ASSERT_BIT_EQUAL(0b01110, bit_tog(0b01110, 0));
            UT_ASSERT_BIT_EQUAL(0b01111, bit_tog(0b01110, 1));
            UT_ASSERT_BIT_EQUAL(0b01100, bit_tog(0b01110, 2));
            UT_ASSERT_BIT_EQUAL(0b00110, bit_tog(0b01110, 4));
            UT_ASSERT_BIT_EQUAL(0b11110, bit_tog(0b01110, 5));
        } UT_GROUP_END;

        UT_GROUP_BEG(wrt) {
            UT_ASSERT_BIT_EQUAL(0b01110, bit_wrt(0b01110, 0, 0));
            UT_ASSERT_BIT_EQUAL(0b01110, bit_wrt(0b01110, 1, 0));
            UT_ASSERT_BIT_EQUAL(0b01100, bit_wrt(0b01110, 2, 0));
            UT_ASSERT_BIT_EQUAL(0b00110, bit_wrt(0b01110, 4, 0));
            UT_ASSERT_BIT_EQUAL(0b01110, bit_wrt(0b01110, 5, 0));

            UT_ASSERT_BIT_EQUAL(0b01110, bit_wrt(0b01110, 0, 1));
            UT_ASSERT_BIT_EQUAL(0b01111, bit_wrt(0b01110, 1, 1));
            UT_ASSERT_BIT_EQUAL(0b01110, bit_wrt(0b01110, 2, 1));
            UT_ASSERT_BIT_EQUAL(0b01110, bit_wrt(0b01110, 4, 1));
            UT_ASSERT_BIT_EQUAL(0b11110, bit_wrt(0b01110, 5, 1));
        } UT_GROUP_END;

        UT_GROUP_BEG(inv) {
            UT_ASSERT_BIT_EQUAL(u32_c(0b11111111111111111111111111111111), bit_inv(u32_c(0b00000000000000000000000000000000)));
            UT_ASSERT_BIT_EQUAL(u32_c(0b11111111111111111111111111111110), bit_inv(u32_c(0b00000000000000000000000000000001)));
            UT_ASSERT_BIT_EQUAL(i8_c(127), bit_inv(i8_c(-128)));
        } UT_GROUP_END;

        UT_GROUP_BEG(rev) {
            UT_ASSERT_BIT_EQUAL(u32_c(0b0), bit_rev((us32_t)0b0));
            UT_ASSERT_BIT_EQUAL(u32_c(0b0000000000000001), bit_rev(u32_c(0b10000000000000000000000000000000)));
            UT_ASSERT_BIT_EQUAL(u32_c(0b0000000000010001), bit_rev(u32_c(0b10001000000000000000000000000000)));
        } UT_GROUP_END;

        UT_GROUP_BEG(shf_rig) {
            UT_ASSERT_BIT_EQUAL(0b00010, bit_shf_rig(0b00100, 1));
            UT_ASSERT_BIT_EQUAL(0b00101, bit_shf_rig(0b10100, 2));
            UT_ASSERT_BIT_EQUAL(0b00001, bit_shf_rig(0b10100, 4));
        } UT_GROUP_END;

        UT_GROUP_BEG(shf_lef) {
            UT_ASSERT_BIT_EQUAL(0b01000, bit_shf_lef(0b00100, 1));
            UT_ASSERT_BIT_EQUAL(0b10100, bit_shf_lef(0b00101, 2));
            UT_ASSERT_BIT_EQUAL(0b1010000, bit_shf_lef(0b00101, 4));
            UT_ASSERT_BIT_EQUAL(0b10000000000000000000000000000000, bit_shf_lef(0b10001000000000000000000000000000, 4));
        } UT_GROUP_END;

        UT_GROUP_BEG(shf_vec) {
            UT_ASSERT_BIT_EQUAL(0b00010, bit_shf_vec(0b00100, -1));
            UT_ASSERT_BIT_EQUAL(0b00101, bit_shf_vec(0b10100, -2));
            UT_ASSERT_BIT_EQUAL(0b00001, bit_shf_vec(0b10100, -4));

            UT_ASSERT_BIT_EQUAL(0b01000, bit_shf_vec(0b00100, +1));
            UT_ASSERT_BIT_EQUAL(0b10100, bit_shf_vec(0b00101, +2));
            UT_ASSERT_BIT_EQUAL(0b1010000, bit_shf_vec(0b00101, +4));
            UT_ASSERT_BIT_EQUAL(0b10000000000000000000000000000000, bit_shf_lef(0b10001000000000000000000000000000, +4));
        } UT_GROUP_END;

        UT_GROUP_BEG(cyc_lef) {
            UT_ASSERT_BIT_EQUAL(u32_c(0b10001000000000000000000000000000), bit_cyc_lef(u32_c(0b00001000100000000000000000000000), 4));
            UT_ASSERT_BIT_EQUAL(u32_c(0b00001000100000000000000000000000), bit_cyc_lef(u32_c(0b00001000100000000000000000000000), 32));
            UT_ASSERT_BIT_EQUAL(u32_c(0b00001000100000000000000000000000), bit_cyc_lef(u32_c(0b01000100000000000000000000000000), 29));
            UT_ASSERT_BIT_EQUAL(u32_c(0b00001000100000000000000000000000), bit_cyc_lef(u32_c(0b10001000000000000000000000000000), 28));
        } UT_GROUP_END;

        UT_GROUP_BEG(cyc_rig) {
            UT_ASSERT_BIT_EQUAL(u32_c(0b00001000100000000000000000000000), bit_cyc_rig(u32_c(0b10001000000000000000000000000000), 4));
            UT_ASSERT_BIT_EQUAL(u32_c(0b00001000100000000000000000000000), bit_cyc_rig(u32_c(0b00001000100000000000000000000000), 32));
            UT_ASSERT_BIT_EQUAL(u32_c(0b01000100000000000000000000000000), bit_cyc_rig(u32_c(0b00001000100000000000000000000000), 29));
            UT_ASSERT_BIT_EQUAL(u32_c(0b10001000000000000000000000000000), bit_cyc_rig(u32_c(0b00001000100000000000000000000000), 28));
        } UT_GROUP_END;

        UT_GROUP_BEG(cyc_vec) {
            UT_ASSERT_BIT_EQUAL(u32_c(0b00001000100000000000000000000000), bit_cyc_vec(u32_c(0b10001000000000000000000000000000), -4));
            UT_ASSERT_BIT_EQUAL(u32_c(0b00001000100000000000000000000000), bit_cyc_vec(u32_c(0b00001000100000000000000000000000), -32));
            UT_ASSERT_BIT_EQUAL(u32_c(0b01000100000000000000000000000000), bit_cyc_vec(u32_c(0b00001000100000000000000000000000), -29));
            UT_ASSERT_BIT_EQUAL(u32_c(0b10001000000000000000000000000000), bit_cyc_vec(u32_c(0b00001000100000000000000000000000), -28));

            UT_ASSERT_BIT_EQUAL(u32_c(0b10001000000000000000000000000000), bit_cyc_vec(u32_c(0b00001000100000000000000000000000), +4));
            UT_ASSERT_BIT_EQUAL(u32_c(0b00001000100000000000000000000000), bit_cyc_vec(u32_c(0b00001000100000000000000000000000), +32));
            UT_ASSERT_BIT_EQUAL(u32_c(0b00001000100000000000000000000000), bit_cyc_vec(u32_c(0b01000100000000000000000000000000), +29));
            UT_ASSERT_BIT_EQUAL(u32_c(0b00001000100000000000000000000000), bit_cyc_vec(u32_c(0b10001000000000000000000000000000), +28));
        } UT_GROUP_END;

        UT_GROUP_BEG(mask_up) {
            UT_ASSERT_BIT_EQUAL(u32_c(0b00000000000000000000000000000000), bit_mask_up(u32_c(0b00000000000000000000000000000000), u32_c(0b00000000000000000000000000000000)));
            UT_ASSERT_BIT_EQUAL(u32_c(0b00000000000000000000000000000001), bit_mask_up(u32_c(0b00000000000000000000000000000001), u32_c(0b00000000000000000000000000000000)));
            UT_ASSERT_BIT_EQUAL(u32_c(0b00000000000000000000000000000011), bit_mask_up(u32_c(0b00000000000000000000000000000001), u32_c(0b00000000000000000000000000000011)));
            UT_ASSERT_BIT_EQUAL(u32_c(0b00000000000000000000000000000011), bit_mask_up(u32_c(0b00000000000000000000000000000001), u32_c(0b00000000000000000000000000000010)));
            UT_ASSERT_BIT_EQUAL(u32_c(0b11100000011100011000100000000111), bit_mask_up(u32_c(0b00000000000000011000100000000000), u32_c(0b11100000011100000000000000000111)));
        } UT_GROUP_END;

        UT_GROUP_BEG(mask_dw) {
            UT_ASSERT_BIT_EQUAL(u32_c(0b00000000000000000000000000000000), bit_mask_dw(u32_c(0b00000000000000000000000000000000), u32_c(0b00000000000000000000000000000000)));
            UT_ASSERT_BIT_EQUAL(u32_c(0b00000000000000000000000000000000), bit_mask_dw(u32_c(0b00000000000000000000000000000001), u32_c(0b00000000000000000000000000000000)));
            UT_ASSERT_BIT_EQUAL(u32_c(0b00000000000000000000000000000001), bit_mask_dw(u32_c(0b00000000000000000000000000000001), u32_c(0b00000000000000000000000000000011)));
            UT_ASSERT_BIT_EQUAL(u32_c(0b00000000000000000000000000000000), bit_mask_dw(u32_c(0b00000000000000000000000000000001), u32_c(0b00000000000000000000000000000010)));
        } UT_GROUP_END;
    } UT_GROUP_END;
}

