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
        UT_GROUP_BEG(eql) {
            UT_ASSERT_BIT_EQ(i8_c(  0), i8_c(0b00000000));
            UT_ASSERT_BIT_EQ(u8_c(  0), u8_c(0b00000000));
            UT_ASSERT_BIT_EQ(i8_c(  1), i8_c(0b00000001));
            UT_ASSERT_BIT_EQ(u8_c(  1), u8_c(0b00000001));

            UT_ASSERT_BIT_EQ(i8_c( -1), i8_c(0b11111111));
            UT_ASSERT_BIT_EQ(u8_c(255), u8_c(0b11111111));

            UT_ASSERT_BIT_EQ(i8_c( -1), i8_c(0b111111111));
            UT_ASSERT_BIT_EQ(u8_c(255), u8_c(0b111111111));

            UT_ASSERT_BIT_EQ(u8_c(256), u8_c(0b000000000));
        }UT_GROUP_END;

        UT_GROUP_BEG(cnt) {
            UT_ASSERT_BIT_EQ(umax_c(  8), bit_cnt( i8_c(0)));
            UT_ASSERT_BIT_EQ(umax_c( 16), bit_cnt(i16_c(0)));
            UT_ASSERT_BIT_EQ(umax_c( 32), bit_cnt(i32_c(0)));
            UT_ASSERT_BIT_EQ(umax_c( 64), bit_cnt(i64_c(0)));
            UT_ASSERT_BIT_EQ(umax_c(  8), bit_cnt( u8_c(0)));
            UT_ASSERT_BIT_EQ(umax_c( 16), bit_cnt(u16_c(0)));
            UT_ASSERT_BIT_EQ(umax_c( 32), bit_cnt(u32_c(0)));
            UT_ASSERT_BIT_EQ(umax_c( 64), bit_cnt(u64_c(0)));
            UT_ASSERT_BIT_EQ(umax_c( 32), bit_cnt(f32_c(0)));
            UT_ASSERT_BIT_EQ(umax_c( 64), bit_cnt(f64_c(0)));
        }UT_GROUP_END;


        UT_GROUP_BEG(0) {
            UT_GROUP_BEG(beg) {
                UT_ASSERT_BIT_EQ(imax_c(1), bit_0_beg(u8_c(0b00000000)));
                UT_ASSERT_BIT_EQ(imax_c(2), bit_0_beg(u8_c(0b00000001)));
                UT_ASSERT_BIT_EQ(imax_c(1), bit_0_beg(u8_c(0b00000010)));
                UT_ASSERT_BIT_EQ(imax_c(1), bit_0_beg(u8_c(0b00000110)));
                UT_ASSERT_BIT_EQ(imax_c(1), bit_0_beg(u8_c(0b10000000)));
                UT_ASSERT_BIT_EQ(imax_c(1), bit_0_beg(u8_c(0b11000000)));
                UT_ASSERT_BIT_EQ(imax_c(3), bit_0_beg(u8_c(0b00000011)));
                UT_ASSERT_BIT_EQ(imax_c(4), bit_0_beg(u8_c(0b00000111)));
                UT_ASSERT_BIT_EQ(imax_c(4), bit_0_beg(u8_c(0b11100111)));
                UT_ASSERT_BIT_EQ(imax_c(4), bit_0_beg(u8_c(0b11110111)));
                UT_ASSERT_BIT_EQ(imax_c(7), bit_0_beg(u8_c(0b00111111)));
                UT_ASSERT_BIT_EQ(imax_c(8), bit_0_beg(u8_c(0b01111111)));
                UT_ASSERT_BIT_EQ(imax_c(0), bit_0_beg(u8_c(0b11111111)));
            } UT_GROUP_END;

            UT_GROUP_BEG(end) {
                UT_ASSERT_BIT_EQ(imax_c(0), bit_0_end(u8_c(0b11111111)));
                UT_ASSERT_BIT_EQ(imax_c(1), bit_0_end(u8_c(0b11111110)));
                UT_ASSERT_BIT_EQ(imax_c(2), bit_0_end(u8_c(0b11111100)));
                UT_ASSERT_BIT_EQ(imax_c(2), bit_0_end(u8_c(0b11111101)));
                UT_ASSERT_BIT_EQ(imax_c(3), bit_0_end(u8_c(0b11111011)));
                UT_ASSERT_BIT_EQ(imax_c(8), bit_0_end(u8_c(0b01111111)));
                UT_ASSERT_BIT_EQ(imax_c(6), bit_0_end(u8_c(0b11000000)));
                UT_ASSERT_BIT_EQ(imax_c(6), bit_0_end(u8_c(0b11000011)));
                UT_ASSERT_BIT_EQ(imax_c(8), bit_0_end(u8_c(0b00000000)));
                UT_ASSERT_BIT_EQ(imax_c(8), bit_0_end(u8_c(0b00000001)));
                UT_ASSERT_BIT_EQ(imax_c(7), bit_0_end(u8_c(0b10000000)));
                UT_ASSERT_BIT_EQ(imax_c(8), bit_0_end(u8_c(0b01111111)));
            } UT_GROUP_END;

            UT_GROUP_BEG(cnt) {
                UT_ASSERT_BIT_EQ(imax_c( 0), bit_0_cnt(u32_c(0xFFFFFFFF)));
                UT_ASSERT_BIT_EQ(imax_c( 8), bit_0_cnt(u32_c(0xFFFFFF00)));
                UT_ASSERT_BIT_EQ(imax_c(32), bit_0_cnt(u32_c(0x00000000)));
                UT_ASSERT_BIT_EQ(imax_c( 0), bit_0_cnt( u8_c(0x000000FF)));

                UT_ASSERT_BIT_EQ(imax_c( 8), bit_0_cnt(u8_c(0b00000000)));
                UT_ASSERT_BIT_EQ(imax_c( 7), bit_0_cnt(u8_c(0b00000001)));
                UT_ASSERT_BIT_EQ(imax_c( 6), bit_0_cnt(u8_c(0b00000101)));
            } UT_GROUP_END;

            UT_GROUP_BEG(pos) {
                UT_ASSERT_BIT_EQ(imax_c(-1), bit_0_pos(u8_c(0b00000000)));
                UT_ASSERT_BIT_EQ(imax_c(-1), bit_0_pos(u8_c(0b00000001)));
                UT_ASSERT_BIT_EQ(imax_c(-1), bit_0_pos(u8_c(0b10101111)));
                UT_ASSERT_BIT_EQ(imax_c( 0), bit_0_pos(u8_c(0b11111111)));
                UT_ASSERT_BIT_EQ(imax_c( 1), bit_0_pos(u8_c(0b11111110)));
                UT_ASSERT_BIT_EQ(imax_c( 2), bit_0_pos(u8_c(0b11111101)));
            } UT_GROUP_END;
        } UT_GROUP_END;

        UT_GROUP_BEG(1) {
            UT_GROUP_BEG(beg) {
                UT_ASSERT_BIT_EQ(imax_c( 0), bit_1_beg(0b00000000));
                UT_ASSERT_BIT_EQ(imax_c( 1), bit_1_beg(0b00000001));
                UT_ASSERT_BIT_EQ(imax_c( 8), bit_1_beg(0b10000000));
                UT_ASSERT_BIT_EQ(imax_c( 2), bit_1_beg(0b00000010));
                UT_ASSERT_BIT_EQ(imax_c( 1), bit_1_beg(0b00000011));
                UT_ASSERT_BIT_EQ(imax_c( 2), bit_1_beg(0b00000110));
                UT_ASSERT_BIT_EQ(imax_c( 7), bit_1_beg(0b11000000));
                UT_ASSERT_BIT_EQ(imax_c( 4), bit_1_beg(0b00001000));
                UT_ASSERT_BIT_EQ(imax_c( 1), bit_1_beg(0b10011001));
                UT_ASSERT_BIT_EQ(imax_c( 1), bit_1_beg(0b11111111));
                UT_ASSERT_BIT_EQ(imax_c( 1), bit_1_beg(0xFFFFFFFF));
                UT_ASSERT_BIT_EQ(imax_c(32), bit_1_beg(0x80000000));
                UT_ASSERT_BIT_EQ(imax_c(29), bit_1_beg(0xF0000000));
                UT_ASSERT_BIT_EQ(imax_c(64), bit_1_beg(0x8000000000000000));
            } UT_GROUP_END;

            UT_GROUP_BEG(end) {
                UT_ASSERT_BIT_EQ(imax_c( 0), bit_1_end(0b00000000));
                UT_ASSERT_BIT_EQ(imax_c( 1), bit_1_end(0b00000001));
                UT_ASSERT_BIT_EQ(imax_c( 8), bit_1_end(0b10000000));
                UT_ASSERT_BIT_EQ(imax_c( 2), bit_1_end(0b00000010));
                UT_ASSERT_BIT_EQ(imax_c( 2), bit_1_end(0b00000011));
                UT_ASSERT_BIT_EQ(imax_c( 3), bit_1_end(0b00000110));
                UT_ASSERT_BIT_EQ(imax_c( 8), bit_1_end(0b11000000));
                UT_ASSERT_BIT_EQ(imax_c( 4), bit_1_end(0b00001000));
                UT_ASSERT_BIT_EQ(imax_c( 8), bit_1_end(0b10011001));
                UT_ASSERT_BIT_EQ(imax_c( 8), bit_1_end(0b11111111));
                UT_ASSERT_BIT_EQ(imax_c(32), bit_1_end(0xFFFFFFFF));
                UT_ASSERT_BIT_EQ(imax_c(32), bit_1_end(0x80000000));
                UT_ASSERT_BIT_EQ(imax_c(32), bit_1_end(0xF0000000));
                UT_ASSERT_BIT_EQ(imax_c(64), bit_1_end(0x8000000000000000));
            } UT_GROUP_END;

            UT_GROUP_BEG(cnt) {
                UT_ASSERT_BIT_EQ(imax_c( 0), bit_1_cnt(0b00000000));
                UT_ASSERT_BIT_EQ(imax_c( 1), bit_1_cnt(0b00000001));
                UT_ASSERT_BIT_EQ(imax_c( 2), bit_1_cnt(0b0000000101));
                UT_ASSERT_BIT_EQ(imax_c(24), bit_1_cnt(0xFFFFFF));
            } UT_GROUP_END;

            UT_GROUP_BEG(pos) {
                UT_ASSERT_BIT_EQ(imax_c( 0), bit_1_pos(0b00000000));
                UT_ASSERT_BIT_EQ(imax_c( 1), bit_1_pos(0b00000001));
                UT_ASSERT_BIT_EQ(imax_c( 3), bit_1_pos(0b00000100));
                UT_ASSERT_BIT_EQ(imax_c(-1), bit_1_pos(0b00000101));
                UT_ASSERT_BIT_EQ(imax_c(-1), bit_1_pos(0b11000101));
            } UT_GROUP_END;
        } UT_GROUP_END;

        UT_GROUP_BEG(get) {
            UT_ASSERT_BIT_EQ(u8_c(0), bit_get(u8_c(0b00000001), 0));
            UT_ASSERT_BIT_EQ(u8_c(1), bit_get(u8_c(0b00000001), 1));
            UT_ASSERT_BIT_EQ(u8_c(0), bit_get(u8_c(0b00000001), 2));

            UT_ASSERT_BIT_EQ(u8_c(0), bit_get(u8_c(0b00000001), 8));
            UT_ASSERT_BIT_EQ(u8_c(1), bit_get(u8_c(0b00000001), 9));
        } UT_GROUP_END;

        UT_GROUP_BEG(set) {
            UT_ASSERT_BIT_EQ(u8_c(  0), bit_set(u8_c(0), 0));
            UT_ASSERT_BIT_EQ(u8_c(  1), bit_set(u8_c(0), 1));
            UT_ASSERT_BIT_EQ(u8_c(  2), bit_set(u8_c(0), 2));

            UT_ASSERT_BIT_EQ(u8_c(128), bit_set(u8_c(0), 8));
            UT_ASSERT_BIT_EQ(u8_c(  1), bit_set(u8_c(0), 9));

            UT_ASSERT_BIT_EQ(u8_c(  3), bit_set(bit_set(u8_c(0), 1), 2));
        } UT_GROUP_END;

        UT_GROUP_BEG(res) {
            UT_ASSERT_BIT_EQ(u8_c(0b00001110), bit_res(u8_c(0b00001110), 0));
            UT_ASSERT_BIT_EQ(u8_c(0b00001110), bit_res(u8_c(0b00001110), 1));
            UT_ASSERT_BIT_EQ(u8_c(0b00001100), bit_res(u8_c(0b00001110), 2));
            UT_ASSERT_BIT_EQ(u8_c(0b00000110), bit_res(u8_c(0b00001110), 4));

            UT_ASSERT_BIT_EQ(u8_c(0b00001111), bit_res(u8_c(0b00001111), 8));
            UT_ASSERT_BIT_EQ(u8_c(0b00001110), bit_res(u8_c(0b00001111), 9));

            UT_ASSERT_BIT_EQ(u8_c(0b111110011), bit_res(bit_res(u8_c(0b11111111), 3), 4));
        } UT_GROUP_END;

        UT_GROUP_BEG(tog) {
            UT_ASSERT_BIT_EQ(u8_c(0b00001110), bit_tog(u8_c(0b00001110), 0));
            UT_ASSERT_BIT_EQ(u8_c(0b00001111), bit_tog(u8_c(0b00001110), 1));
            UT_ASSERT_BIT_EQ(u8_c(0b00001100), bit_tog(u8_c(0b00001110), 2));
            UT_ASSERT_BIT_EQ(u8_c(0b00000110), bit_tog(u8_c(0b00001110), 4));
            UT_ASSERT_BIT_EQ(u8_c(0b00011110), bit_tog(u8_c(0b00001110), 5));

            UT_ASSERT_BIT_EQ(u8_c(0b01111111), bit_tog(u8_c(0b11111111), 8));
            UT_ASSERT_BIT_EQ(u8_c(0b11111110), bit_tog(u8_c(0b11111111), 9));
        } UT_GROUP_END;

        UT_GROUP_BEG(wrt) {
            UT_ASSERT_BIT_EQ(u8_c(0b00001110), bit_wrt(u8_c(0b00001110), 0, 0));
            UT_ASSERT_BIT_EQ(u8_c(0b00001110), bit_wrt(u8_c(0b00001110), 1, 0));
            UT_ASSERT_BIT_EQ(u8_c(0b00001100), bit_wrt(u8_c(0b00001110), 2, 0));
            UT_ASSERT_BIT_EQ(u8_c(0b00000110), bit_wrt(u8_c(0b00001110), 4, 0));
            UT_ASSERT_BIT_EQ(u8_c(0b00001110), bit_wrt(u8_c(0b00001110), 5, 0));

            UT_ASSERT_BIT_EQ(u8_c(0b00001110), bit_wrt(u8_c(0b00001110), 0, 1));
            UT_ASSERT_BIT_EQ(u8_c(0b00001111), bit_wrt(u8_c(0b00001110), 1, 1));
            UT_ASSERT_BIT_EQ(u8_c(0b00001110), bit_wrt(u8_c(0b00001110), 2, 1));
            UT_ASSERT_BIT_EQ(u8_c(0b00001110), bit_wrt(u8_c(0b00001110), 4, 1));
            UT_ASSERT_BIT_EQ(u8_c(0b00011110), bit_wrt(u8_c(0b00001110), 5, 1));

            UT_ASSERT_BIT_EQ(u8_c(0b01111111), bit_wrt(u8_c(0b11111111), 8, 0));
            UT_ASSERT_BIT_EQ(u8_c(0b11111110), bit_wrt(u8_c(0b11111111), 9, 0));

            UT_ASSERT_BIT_EQ(u8_c(0b10000000), bit_wrt(u8_c(0b00000000), 8, 1));
            UT_ASSERT_BIT_EQ(u8_c(0b00000001), bit_wrt(u8_c(0b00000000), 9, 1));
        } UT_GROUP_END;

        UT_GROUP_BEG(inv) {
            UT_ASSERT_BIT_EQ(u8_c(0b11111111), bit_inv(u8_c(0b00000000)));
            UT_ASSERT_BIT_EQ(u8_c(0b11111110), bit_inv(u8_c(0b00000001)));

            UT_ASSERT_BIT_EQ(i8_c(0b00000000), bit_inv(i8_c(0b11111111)));
            UT_ASSERT_BIT_EQ(i8_c(0b00000000), bit_inv(i8_c(0b11111111)));

            UT_ASSERT_BIT_EQ(i8_c(127), bit_inv(i8_c(-128)));
        } UT_GROUP_END;

        UT_GROUP_BEG(rev) {
            UT_ASSERT_BIT_EQ(u8_c(0),          bit_rev(u8_c(0)));
            UT_ASSERT_BIT_EQ(u8_c(0b00000001), bit_rev(u8_c(0b10000000)));
            UT_ASSERT_BIT_EQ(u8_c(0b00010001), bit_rev(u8_c(0b10001000)));
        } UT_GROUP_END;


        UT_GROUP_BEG(ari_rig) {
            UT_ASSERT_BIT_EQ(u8_c(0b00011000), bit_ari_rig(u8_c(0b00011000), 0));
            UT_ASSERT_BIT_EQ(u8_c(0b00001100), bit_ari_rig(u8_c(0b00011000), 1));
            UT_ASSERT_BIT_EQ(u8_c(0b00000110), bit_ari_rig(u8_c(0b00011000), 2));
            UT_ASSERT_BIT_EQ(u8_c(0b00000011), bit_ari_rig(u8_c(0b00011000), 3));
            UT_ASSERT_BIT_EQ(u8_c(0b00000001), bit_ari_rig(u8_c(0b00011000), 4));
            UT_ASSERT_BIT_EQ(u8_c(0b00000000), bit_ari_rig(u8_c(0b00011000), 5));

            UT_ASSERT_BIT_EQ(u8_c(0b11100111), bit_ari_rig(u8_c(0b11100111), 0));
            UT_ASSERT_BIT_EQ(u8_c(0b01110011), bit_ari_rig(u8_c(0b11100111), 1));
            UT_ASSERT_BIT_EQ(u8_c(0b00111001), bit_ari_rig(u8_c(0b11100111), 2));
            UT_ASSERT_BIT_EQ(u8_c(0b00011100), bit_ari_rig(u8_c(0b11100111), 3));
            UT_ASSERT_BIT_EQ(u8_c(0b00001110), bit_ari_rig(u8_c(0b11100111), 4));
            UT_ASSERT_BIT_EQ(u8_c(0b00000111), bit_ari_rig(u8_c(0b11100111), 5));


            UT_ASSERT_BIT_EQ(i8_c(0b00011000), bit_ari_rig(i8_c(0b00011000), 0));
            UT_ASSERT_BIT_EQ(i8_c(0b00001100), bit_ari_rig(i8_c(0b00011000), 1));
            UT_ASSERT_BIT_EQ(i8_c(0b00000110), bit_ari_rig(i8_c(0b00011000), 2));
            UT_ASSERT_BIT_EQ(i8_c(0b00000011), bit_ari_rig(i8_c(0b00011000), 3));
            UT_ASSERT_BIT_EQ(i8_c(0b00000001), bit_ari_rig(i8_c(0b00011000), 4));
            UT_ASSERT_BIT_EQ(i8_c(0b00000000), bit_ari_rig(i8_c(0b00011000), 5));

            UT_ASSERT_BIT_EQ(i8_c(0b11100111), bit_ari_rig(i8_c(0b11100111), 0));
            UT_ASSERT_BIT_EQ(i8_c(0b11110011), bit_ari_rig(i8_c(0b11100111), 1));
            UT_ASSERT_BIT_EQ(i8_c(0b11111001), bit_ari_rig(i8_c(0b11100111), 2));
            UT_ASSERT_BIT_EQ(i8_c(0b11111100), bit_ari_rig(i8_c(0b11100111), 3));
            UT_ASSERT_BIT_EQ(i8_c(0b11111110), bit_ari_rig(i8_c(0b11100111), 4));
            UT_ASSERT_BIT_EQ(i8_c(0b11111111), bit_ari_rig(i8_c(0b11100111), 5));
        } UT_GROUP_END;


        UT_GROUP_BEG(ari_lef) {
            UT_ASSERT_BIT_EQ(u8_c(0b00011000), bit_ari_lef(u8_c(0b00011000), 0));
            UT_ASSERT_BIT_EQ(u8_c(0b00110000), bit_ari_lef(u8_c(0b00011000), 1));
            UT_ASSERT_BIT_EQ(u8_c(0b01100000), bit_ari_lef(u8_c(0b00011000), 2));
            UT_ASSERT_BIT_EQ(u8_c(0b11000000), bit_ari_lef(u8_c(0b00011000), 3));
            UT_ASSERT_BIT_EQ(u8_c(0b10000000), bit_ari_lef(u8_c(0b00011000), 4));
            UT_ASSERT_BIT_EQ(u8_c(0b00000000), bit_ari_lef(u8_c(0b00011000), 5));

            UT_ASSERT_BIT_EQ(u8_c(0b11100111), bit_ari_lef(u8_c(0b11100111), 0));
            UT_ASSERT_BIT_EQ(u8_c(0b11001110), bit_ari_lef(u8_c(0b11100111), 1));
            UT_ASSERT_BIT_EQ(u8_c(0b10011100), bit_ari_lef(u8_c(0b11100111), 2));
            UT_ASSERT_BIT_EQ(u8_c(0b00111000), bit_ari_lef(u8_c(0b11100111), 3));
            UT_ASSERT_BIT_EQ(u8_c(0b01110000), bit_ari_lef(u8_c(0b11100111), 4));
            UT_ASSERT_BIT_EQ(u8_c(0b11100000), bit_ari_lef(u8_c(0b11100111), 5));


            UT_ASSERT_BIT_EQ(i8_c(0b00011000), bit_ari_lef(i8_c(0b00011000), 0));
            UT_ASSERT_BIT_EQ(i8_c(0b00110000), bit_ari_lef(i8_c(0b00011000), 1));
            UT_ASSERT_BIT_EQ(i8_c(0b01100000), bit_ari_lef(i8_c(0b00011000), 2));
            UT_ASSERT_BIT_EQ(i8_c(0b11000000), bit_ari_lef(i8_c(0b00011000), 3));
            UT_ASSERT_BIT_EQ(i8_c(0b10000000), bit_ari_lef(i8_c(0b00011000), 4));
            UT_ASSERT_BIT_EQ(i8_c(0b00000000), bit_ari_lef(i8_c(0b00011000), 5));

            UT_ASSERT_BIT_EQ(i8_c(0b11100111), bit_ari_lef(i8_c(0b11100111), 0));
            UT_ASSERT_BIT_EQ(i8_c(0b11001110), bit_ari_lef(i8_c(0b11100111), 1));
            UT_ASSERT_BIT_EQ(i8_c(0b10011100), bit_ari_lef(i8_c(0b11100111), 2));
            UT_ASSERT_BIT_EQ(i8_c(0b00111000), bit_ari_lef(i8_c(0b11100111), 3));
            UT_ASSERT_BIT_EQ(i8_c(0b01110000), bit_ari_lef(i8_c(0b11100111), 4));
            UT_ASSERT_BIT_EQ(i8_c(0b11100000), bit_ari_lef(i8_c(0b11100111), 5));
        } UT_GROUP_END;

        UT_GROUP_BEG(ari_vec) {
            UT_ASSERT_BIT_EQ(u8_c(0b00011000), bit_ari_vec(u8_c(0b00011000),  0));
            UT_ASSERT_BIT_EQ(u8_c(0b00001100), bit_ari_vec(u8_c(0b00011000), -1));
            UT_ASSERT_BIT_EQ(u8_c(0b00000110), bit_ari_vec(u8_c(0b00011000), -2));
            UT_ASSERT_BIT_EQ(u8_c(0b00000011), bit_ari_vec(u8_c(0b00011000), -3));
            UT_ASSERT_BIT_EQ(u8_c(0b00000001), bit_ari_vec(u8_c(0b00011000), -4));
            UT_ASSERT_BIT_EQ(u8_c(0b00000000), bit_ari_vec(u8_c(0b00011000), -5));

            UT_ASSERT_BIT_EQ(u8_c(0b00011000), bit_ari_vec(u8_c(0b00011000),  0));
            UT_ASSERT_BIT_EQ(u8_c(0b00110000), bit_ari_vec(u8_c(0b00011000), +1));
            UT_ASSERT_BIT_EQ(u8_c(0b01100000), bit_ari_vec(u8_c(0b00011000), +2));
            UT_ASSERT_BIT_EQ(u8_c(0b11000000), bit_ari_vec(u8_c(0b00011000), +3));
            UT_ASSERT_BIT_EQ(u8_c(0b10000000), bit_ari_vec(u8_c(0b00011000), +4));
            UT_ASSERT_BIT_EQ(u8_c(0b00000000), bit_ari_vec(u8_c(0b00011000), +5));
        } UT_GROUP_END;

        UT_GROUP_BEG(shf_rig) {
            UT_ASSERT_BIT_EQ(u8_c(0b00011000), bit_shf_rig(u8_c(0b00011000), 0));
            UT_ASSERT_BIT_EQ(u8_c(0b00001100), bit_shf_rig(u8_c(0b00011000), 1));
            UT_ASSERT_BIT_EQ(u8_c(0b00000110), bit_shf_rig(u8_c(0b00011000), 2));
            UT_ASSERT_BIT_EQ(u8_c(0b00000011), bit_shf_rig(u8_c(0b00011000), 3));
            UT_ASSERT_BIT_EQ(u8_c(0b00000001), bit_shf_rig(u8_c(0b00011000), 4));
            UT_ASSERT_BIT_EQ(u8_c(0b00000000), bit_shf_rig(u8_c(0b00011000), 5));

            UT_ASSERT_BIT_EQ(u8_c(0b11100111), bit_shf_rig(u8_c(0b11100111), 0));
            UT_ASSERT_BIT_EQ(u8_c(0b01110011), bit_shf_rig(u8_c(0b11100111), 1));
            UT_ASSERT_BIT_EQ(u8_c(0b00111001), bit_shf_rig(u8_c(0b11100111), 2));
            UT_ASSERT_BIT_EQ(u8_c(0b00011100), bit_shf_rig(u8_c(0b11100111), 3));
            UT_ASSERT_BIT_EQ(u8_c(0b00001110), bit_shf_rig(u8_c(0b11100111), 4));
            UT_ASSERT_BIT_EQ(u8_c(0b00000111), bit_shf_rig(u8_c(0b11100111), 5));


            UT_ASSERT_BIT_EQ(i8_c(0b00011000), bit_shf_rig(i8_c(0b00011000), 0));
            UT_ASSERT_BIT_EQ(i8_c(0b00001100), bit_shf_rig(i8_c(0b00011000), 1));
            UT_ASSERT_BIT_EQ(i8_c(0b00000110), bit_shf_rig(i8_c(0b00011000), 2));
            UT_ASSERT_BIT_EQ(i8_c(0b00000011), bit_shf_rig(i8_c(0b00011000), 3));
            UT_ASSERT_BIT_EQ(i8_c(0b00000001), bit_shf_rig(i8_c(0b00011000), 4));
            UT_ASSERT_BIT_EQ(i8_c(0b00000000), bit_shf_rig(i8_c(0b00011000), 5));

            UT_ASSERT_BIT_EQ(i8_c(0b11100111), bit_shf_rig(i8_c(0b11100111), 0));
            UT_ASSERT_BIT_EQ(i8_c(0b01110011), bit_shf_rig(i8_c(0b11100111), 1));
            UT_ASSERT_BIT_EQ(i8_c(0b00111001), bit_shf_rig(i8_c(0b11100111), 2));
            UT_ASSERT_BIT_EQ(i8_c(0b00011100), bit_shf_rig(i8_c(0b11100111), 3));
            UT_ASSERT_BIT_EQ(i8_c(0b00001110), bit_shf_rig(i8_c(0b11100111), 4));
            UT_ASSERT_BIT_EQ(i8_c(0b00000111), bit_shf_rig(i8_c(0b11100111), 5));
        } UT_GROUP_END;

        UT_GROUP_BEG(shf_lef) {
            UT_ASSERT_BIT_EQ(u8_c(0b00011000), bit_shf_lef(u8_c(0b00011000), 0));
            UT_ASSERT_BIT_EQ(u8_c(0b00110000), bit_shf_lef(u8_c(0b00011000), 1));
            UT_ASSERT_BIT_EQ(u8_c(0b01100000), bit_shf_lef(u8_c(0b00011000), 2));
            UT_ASSERT_BIT_EQ(u8_c(0b11000000), bit_shf_lef(u8_c(0b00011000), 3));
            UT_ASSERT_BIT_EQ(u8_c(0b10000000), bit_shf_lef(u8_c(0b00011000), 4));
            UT_ASSERT_BIT_EQ(u8_c(0b00000000), bit_shf_lef(u8_c(0b00011000), 5));

            UT_ASSERT_BIT_EQ(u8_c(0b11100111), bit_shf_lef(u8_c(0b11100111), 0));
            UT_ASSERT_BIT_EQ(u8_c(0b11001110), bit_shf_lef(u8_c(0b11100111), 1));
            UT_ASSERT_BIT_EQ(u8_c(0b10011100), bit_shf_lef(u8_c(0b11100111), 2));
            UT_ASSERT_BIT_EQ(u8_c(0b00111000), bit_shf_lef(u8_c(0b11100111), 3));
            UT_ASSERT_BIT_EQ(u8_c(0b01110000), bit_shf_lef(u8_c(0b11100111), 4));
            UT_ASSERT_BIT_EQ(u8_c(0b11100000), bit_shf_lef(u8_c(0b11100111), 5));


            UT_ASSERT_BIT_EQ(i8_c(0b00011000), bit_shf_lef(i8_c(0b00011000), 0));
            UT_ASSERT_BIT_EQ(i8_c(0b00110000), bit_shf_lef(i8_c(0b00011000), 1));
            UT_ASSERT_BIT_EQ(i8_c(0b01100000), bit_shf_lef(i8_c(0b00011000), 2));
            UT_ASSERT_BIT_EQ(i8_c(0b11000000), bit_shf_lef(i8_c(0b00011000), 3));
            UT_ASSERT_BIT_EQ(i8_c(0b10000000), bit_shf_lef(i8_c(0b00011000), 4));
            UT_ASSERT_BIT_EQ(i8_c(0b00000000), bit_shf_lef(i8_c(0b00011000), 5));

            UT_ASSERT_BIT_EQ(i8_c(0b11100111), bit_shf_lef(i8_c(0b11100111), 0));
            UT_ASSERT_BIT_EQ(i8_c(0b11001110), bit_shf_lef(i8_c(0b11100111), 1));
            UT_ASSERT_BIT_EQ(i8_c(0b10011100), bit_shf_lef(i8_c(0b11100111), 2));
            UT_ASSERT_BIT_EQ(i8_c(0b00111000), bit_shf_lef(i8_c(0b11100111), 3));
            UT_ASSERT_BIT_EQ(i8_c(0b01110000), bit_shf_lef(i8_c(0b11100111), 4));
            UT_ASSERT_BIT_EQ(i8_c(0b11100000), bit_shf_lef(i8_c(0b11100111), 5));
        } UT_GROUP_END;

        UT_GROUP_BEG(shf_vec) {
            UT_ASSERT_BIT_EQ(u8_c(0b00011000), bit_shf_vec(u8_c(0b00011000),  0));
            UT_ASSERT_BIT_EQ(u8_c(0b00001100), bit_shf_vec(u8_c(0b00011000), -1));
            UT_ASSERT_BIT_EQ(u8_c(0b00000110), bit_shf_vec(u8_c(0b00011000), -2));
            UT_ASSERT_BIT_EQ(u8_c(0b00000011), bit_shf_vec(u8_c(0b00011000), -3));
            UT_ASSERT_BIT_EQ(u8_c(0b00000001), bit_shf_vec(u8_c(0b00011000), -4));
            UT_ASSERT_BIT_EQ(u8_c(0b00000000), bit_shf_vec(u8_c(0b00011000), -5));

            UT_ASSERT_BIT_EQ(u8_c(0b00011000), bit_shf_vec(u8_c(0b00011000),  0));
            UT_ASSERT_BIT_EQ(u8_c(0b00110000), bit_shf_vec(u8_c(0b00011000), +1));
            UT_ASSERT_BIT_EQ(u8_c(0b01100000), bit_shf_vec(u8_c(0b00011000), +2));
            UT_ASSERT_BIT_EQ(u8_c(0b11000000), bit_shf_vec(u8_c(0b00011000), +3));
            UT_ASSERT_BIT_EQ(u8_c(0b10000000), bit_shf_vec(u8_c(0b00011000), +4));
            UT_ASSERT_BIT_EQ(u8_c(0b00000000), bit_shf_vec(u8_c(0b00011000), +5));
        } UT_GROUP_END;

        UT_GROUP_BEG(shf_variable) {
            us8_t i = 0b00011000;
            i = bit_shf_lef(i, 1);
            UT_ASSERT_BIT_EQ(u8_c(0b00110000), i);
            i = bit_shf_rig(i, 1);
            UT_ASSERT_BIT_EQ(u8_c(0b00011000), i);
            i = bit_shf_lef(i, 5);
            UT_ASSERT_BIT_EQ(u8_c(0b00000000), i);
            i = bit_shf_rig(i, 2);
            UT_ASSERT_BIT_EQ(u8_c(0b00000000), i);
        } UT_GROUP_END;

        UT_GROUP_BEG(cyc_lef) {
            UT_ASSERT_BIT_EQ(u32_c(0b10001000000000000000000000000000), bit_cyc_lef(u32_c(0b00001000100000000000000000000000), 4));
            UT_ASSERT_BIT_EQ(u32_c(0b00001000100000000000000000000000), bit_cyc_lef(u32_c(0b00001000100000000000000000000000), 32));
            UT_ASSERT_BIT_EQ(u32_c(0b00001000100000000000000000000000), bit_cyc_lef(u32_c(0b01000100000000000000000000000000), 29));
            UT_ASSERT_BIT_EQ(u32_c(0b00001000100000000000000000000000), bit_cyc_lef(u32_c(0b10001000000000000000000000000000), 28));
        } UT_GROUP_END;

        UT_GROUP_BEG(cyc_rig) {
            UT_ASSERT_BIT_EQ(u32_c(0b00001000100000000000000000000000), bit_cyc_rig(u32_c(0b10001000000000000000000000000000), 4));
            UT_ASSERT_BIT_EQ(u32_c(0b00001000100000000000000000000000), bit_cyc_rig(u32_c(0b00001000100000000000000000000000), 32));
            UT_ASSERT_BIT_EQ(u32_c(0b01000100000000000000000000000000), bit_cyc_rig(u32_c(0b00001000100000000000000000000000), 29));
            UT_ASSERT_BIT_EQ(u32_c(0b10001000000000000000000000000000), bit_cyc_rig(u32_c(0b00001000100000000000000000000000), 28));
        } UT_GROUP_END;

        UT_GROUP_BEG(cyc_vec) {
            UT_ASSERT_BIT_EQ(u32_c(0b00001000100000000000000000000000), bit_cyc_vec(u32_c(0b10001000000000000000000000000000), -4));
            UT_ASSERT_BIT_EQ(u32_c(0b00001000100000000000000000000000), bit_cyc_vec(u32_c(0b00001000100000000000000000000000), -32));
            UT_ASSERT_BIT_EQ(u32_c(0b01000100000000000000000000000000), bit_cyc_vec(u32_c(0b00001000100000000000000000000000), -29));
            UT_ASSERT_BIT_EQ(u32_c(0b10001000000000000000000000000000), bit_cyc_vec(u32_c(0b00001000100000000000000000000000), -28));

            UT_ASSERT_BIT_EQ(u32_c(0b10001000000000000000000000000000), bit_cyc_vec(u32_c(0b00001000100000000000000000000000), +4));
            UT_ASSERT_BIT_EQ(u32_c(0b00001000100000000000000000000000), bit_cyc_vec(u32_c(0b00001000100000000000000000000000), +32));
            UT_ASSERT_BIT_EQ(u32_c(0b00001000100000000000000000000000), bit_cyc_vec(u32_c(0b01000100000000000000000000000000), +29));
            UT_ASSERT_BIT_EQ(u32_c(0b00001000100000000000000000000000), bit_cyc_vec(u32_c(0b10001000000000000000000000000000), +28));
        } UT_GROUP_END;

        UT_GROUP_BEG(mask_up) {
            UT_ASSERT_BIT_EQ(u32_c(0b00000000000000000000000000000000), bit_mask_up(u32_c(0b00000000000000000000000000000000), u32_c(0b00000000000000000000000000000000)));
            UT_ASSERT_BIT_EQ(u32_c(0b00000000000000000000000000000001), bit_mask_up(u32_c(0b00000000000000000000000000000001), u32_c(0b00000000000000000000000000000000)));
            UT_ASSERT_BIT_EQ(u32_c(0b00000000000000000000000000000011), bit_mask_up(u32_c(0b00000000000000000000000000000001), u32_c(0b00000000000000000000000000000011)));
            UT_ASSERT_BIT_EQ(u32_c(0b00000000000000000000000000000011), bit_mask_up(u32_c(0b00000000000000000000000000000001), u32_c(0b00000000000000000000000000000010)));
            UT_ASSERT_BIT_EQ(u32_c(0b11100000011100011000100000000111), bit_mask_up(u32_c(0b00000000000000011000100000000000), u32_c(0b11100000011100000000000000000111)));
        } UT_GROUP_END;

        UT_GROUP_BEG(mask_dw) {
            UT_ASSERT_BIT_EQ(u32_c(0b00000000000000000000000000000000), bit_mask_dw(u32_c(0b00000000000000000000000000000000), u32_c(0b00000000000000000000000000000000)));
            UT_ASSERT_BIT_EQ(u32_c(0b00000000000000000000000000000000), bit_mask_dw(u32_c(0b00000000000000000000000000000001), u32_c(0b00000000000000000000000000000000)));
            UT_ASSERT_BIT_EQ(u32_c(0b00000000000000000000000000000001), bit_mask_dw(u32_c(0b00000000000000000000000000000001), u32_c(0b00000000000000000000000000000011)));
            UT_ASSERT_BIT_EQ(u32_c(0b00000000000000000000000000000000), bit_mask_dw(u32_c(0b00000000000000000000000000000001), u32_c(0b00000000000000000000000000000010)));
        } UT_GROUP_END;
    } UT_GROUP_END;
}

