//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#include "yaya_bit.h"

#define BIT_SET_ALL_1(x, s)   ((sizeof(x) == (s)) ? (umax_c(0) - umax_c(1)) :  (bit_shf_lef(umax_c(1), CHAR_BIT * (s)) - 1))

/*Возвращает позицию первого (младшего / правого) выключеного бита для заданого размера*/
imax_t ___bit_0_beg(umax_t x, umax_t s) {
    if(x == BIT_SET_ALL_1(x, s)){
        return 0;
    }
    is8_t res = 1;
    while (bit_get(x, res) != 0 && res != (CHAR_BIT * s)) {
        res++;
    }
    return res;
}

/*Возвращает позицию последнего (старшего / левого) выключеного бита для заданого размера*/
imax_t ___bit_0_end(umax_t x, umax_t s) {
    if(x == BIT_SET_ALL_1(x, s)) {
        return 0;
    }
    is8_t res = (is8_t)(CHAR_BIT * s);
    while (bit_get(x, res) != 0 && res != 0) {
        res--;
    }
    return res;
}

/*Возвращает количество выключеных битов для заданого размера*/
imax_t ___bit_0_cnt(umax_t x, umax_t s) {
    return (is8_t)((CHAR_BIT * (is8_t)s) - ___bit_1_cnt(x));
}

/*Возвращает положение одного единственого выключеного бита*/
imax_t ___bit_0_pos(umax_t x, umax_t s) {
    if(x == BIT_SET_ALL_1(x, s)){
        return 0;
    }
    if(___bit_0_cnt(x, s) > 1) {
        return -1;
    }
    return ___bit_0_beg(x, s);
}

/*Возвращает позицию первого (младшего / правого) взведенного бита*/
imax_t ___bit_1_beg(umax_t x) {
    if(x == 0){
        return 0;
    }
    return (is8_t)(___bit_1_cnt((x - 1) & ~x) + (1));
}

/*Возвращает позицию последнего (старшего / левого) взведенного бита*/
imax_t ___bit_1_end(umax_t x) {
    if(x == 0){
        return 0;
    }
    is8_t res = 1;
    while (x != 1) {
        x >>= 1;
        res++;
    }
    return res;
}

/*Возвращает количество взведенных битов*/
imax_t ___bit_1_cnt(umax_t x) {
    x = ((x >>  1) & 0x5555555555555555) + (x & 0x5555555555555555);
    x = ((x >>  2) & 0x3333333333333333) + (x & 0x3333333333333333);
    x = ((x >>  4) & 0x0F0F0F0F0F0F0F0F) + (x & 0x0F0F0F0F0F0F0F0F);
    x = ((x >>  8) & 0x00FF00FF00FF00FF) + (x & 0x00FF00FF00FF00FF);
    x = ((x >> 16) & 0x0000FFFF0000FFFF) + (x & 0x0000FFFF0000FFFF);
    x = ((x >> 32) & 0x00000000FFFFFFFF) + (x & 0x00000000FFFFFFFF);
    return (is8_t)(x);
}

/*Возвращает положение одного единственого взведенного бита*/
imax_t ___bit_1_pos(umax_t x) {
    if(x == 0) {
        return 0;
    }
    if(___bit_1_cnt(x) > 1) {
        return -1;
    }
    return ___bit_1_beg(x);
}

/*Развернуть биты в противоположный порядок*/
umax_t ___bit_revers(umax_t x, umax_t s) {
    { x = (x & 0x00000000FFFFFFFF) << 32 | (x & 0xFFFFFFFF00000000) >> 32; }
    { x = (x & 0x0000FFFF0000FFFF) << 16 | (x & 0xFFFF0000FFFF0000) >> 16; }
    { x = (x & 0x00FF00FF00FF00FF) << 8  | (x & 0xFF00FF00FF00FF00) >> 8 ; }
    { x = (x & 0xf0f0f0f0f0f0f0f0) >> 4  | (x & 0x0f0f0f0f0f0f0f0f) << 4 ; }
    { x = (x & 0xcccccccccccccccc) >> 2  | (x & 0x3333333333333333) << 2 ; }
    { x = (x & 0xaaaaaaaaaaaaaaaa) >> 1  | (x & 0x5555555555555555) << 1 ; }
    x = bit_cyc_lef(x, (CHAR_BIT * s));
    return x;
}

umax_t ___bit_sequence(void *ptr, umax_t offset, umax_t len){  /* FIXME IMPLEMENT */
    us8_t *bytes = (uint8_t*)ptr;
    us64_t result = 0;
    us32_t result32_1 = 0;
    us32_t result32_2 = 0;
    if(len <= 16) {
        for (us64_t i = 0; i < len; i++) {
            result |= ((bytes[(offset + i) / 8] >> ((offset + i) % 8)) & 1) << i;
        }
        return result;
    }
    if(len <= 32) {
        for (us64_t i = 0; i < len; i++) {
            result32_1 |= ((bytes[(offset + i) / 8] >> ((offset + i) % 8)) & 1) << i;
        }
        result = result32_1;
        return result;
    }
    if(len <= 64) {
        for (us64_t i = 0; i < 32; i++) {
            result32_1 |= ((bytes[(offset + i) / 8] >> ((offset + i) % 8)) & 1) << i;
        }
        for (us64_t i = 0; i < 64 - (len - 32); i++) {
            result32_2 |= ((bytes[(offset + 32 + i) / 8] >> ((offset + i) % 8)) & 1) << i;
        }
        result = (us64_t)result32_1 | ((us64_t)result32_2) << 32;
        return result;
    }
    return result;
}
