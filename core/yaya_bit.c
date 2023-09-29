// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_bit.h"

// clang-format off
#include "yaya_cdecl.h"
BEG_C_DECLARATION

/*
 * Возвращает позицию первого (младшего / правого) выключеного бита для заданого размера
*/
imax_t ___bit_0_beg(umax_t x, umax_t s) {
    imax_t res = -1;
    imax_t cnt =  1;

    while (cnt <= bit_cnt_to_byte(s)) {
        if(bit_get(x, cnt) != 0) {
            cnt++;
            continue;
        }
        res = cnt;
        break;
    }
    return res;
}

/*
 * Возвращает позицию последнего (старшего / левого) выключеного бита для заданого размера
*/
imax_t ___bit_0_end(umax_t x, umax_t s) {
    imax_t res = -1;
    imax_t cnt = bit_cnt_to_byte(s);

    while (cnt != 0) {
        if(bit_get(x, cnt) != 0) {
            cnt--;
            continue;
        }
        res = cnt;
        break;
    }
    return res;
}

/*
 * Возвращает количество выключеных битов для заданого размера
*/
imax_t ___bit_0_cnt(umax_t x, umax_t s) {
    imax_t res = 0;

    for (imax_t cnt = 1; cnt <= bit_cnt_to_byte(s); cnt++) {
        if(bit_get(x, cnt) == 0) {
            res++;
        }
    }
    return res;
}

/*
 * Возвращает положение одного единственого выключеного бита
*/
imax_t ___bit_0_pos(umax_t x, umax_t s) {
    if(___bit_0_cnt(x, s) > 1){
        return -1;
    }
    return ___bit_0_beg(x, s);
}

/*
 * Возвращает позицию первого (младшего / правого) взведенного бита
*/
imax_t ___bit_1_beg(umax_t x, umax_t s) {
    imax_t res = -1;
    imax_t cnt =  1;

    while (cnt <= bit_cnt_to_byte(s)) {
        if(bit_get(x, cnt) == 0) {
            cnt++;
            continue;
        }
        res = cnt;
        break;
    }
    return res;
}

/*
 * Возвращает позицию последнего (старшего / левого) взведенного бита
*/
imax_t ___bit_1_end(umax_t x, umax_t s) {
    imax_t res = -1;
    imax_t cnt = bit_cnt_to_byte(s);

    while (cnt != 0) {
        if(bit_get(x, cnt) == 0) {
            cnt--;
            continue;
        }
        res = cnt;
        break;
    }
    return res;
}

/*
 * Возвращает количество взведенных битов
*/
imax_t ___bit_1_cnt(umax_t x, umax_t s) {
    imax_t res = 0;

    for (imax_t cnt = 1; cnt <= bit_cnt_to_byte(s); cnt++) {
        if(bit_get(x, cnt) != 0) {
            res++;
        }
    }
    return res;
}

/*
 * Возвращает положение одного единственого взведенного бита
*/
imax_t ___bit_1_pos(umax_t x, umax_t s) {
    if(___bit_1_cnt(x, s) > 1){
        return -1;
    }
    return ___bit_1_beg(x, s);
}

/*
 * Развернуть биты в противоположный порядок
*/
umax_t ___bit_revers(umax_t x, umax_t s) {
    x = (x & 0x00000000FFFFFFFF) << 32 | (x & 0xFFFFFFFF00000000) >> 32;
    x = (x & 0x0000FFFF0000FFFF) << 16 | (x & 0xFFFF0000FFFF0000) >> 16;
    x = (x & 0x00FF00FF00FF00FF) << 8  | (x & 0xFF00FF00FF00FF00) >> 8 ;
    x = (x & 0xf0f0f0f0f0f0f0f0) >> 4  | (x & 0x0f0f0f0f0f0f0f0f) << 4 ;
    x = (x & 0xcccccccccccccccc) >> 2  | (x & 0x3333333333333333) << 2 ;
    x = (x & 0xaaaaaaaaaaaaaaaa) >> 1  | (x & 0x5555555555555555) << 1 ;
    x = bit_rot_lef(x, bit_cnt_to_byte(s));
    return x;
}

/*
 * Выделяет биты из последовательности
*/
umax_t ___bit_sequence(void *ptr, imax_t offset, imax_t len) {
    offset--;

    if(offset < 0) {
        return 0;
    }

    if(len > bit_cnt_to_byte(sizeof(umax_t))) {
        return 0;
    }

    us8_t *bytes = (us8_t*)ptr;
    us64_t result = 0;
    us32_t result32_1 = 0;
    us32_t result32_2 = 0;
    if(len <= 16) {
        for (is64_t i = 0; i < len; i++) {
            result |= (us64_t)(((bytes[(offset + i) / 8] >> ((offset + i) % 8)) & 1) << i);
        }
        return result;
    }
    if(len <= 32) {
        for (is64_t i = 0; i < len; i++) {
            result32_1 |= (us32_t)(((bytes[(offset + i) / 8] >> ((offset + i) % 8)) & 1) << i);
        }
        result = result32_1;
        return result;
    }
    if(len <= 64) {
        for (is64_t i = 0; i < 32; i++) {
            result32_1 |= (us32_t)(((bytes[(offset + i) / 8] >> ((offset + i) % 8)) & 1) << i);
        }
        for (is64_t i = 0; i < 64 - (len - 32); i++) {
            result32_2 |= (us32_t)(((bytes[(offset + 32 + i) / 8] >> ((offset + i) % 8)) & 1) << i);
        }
        result = ((us64_t)(result32_1) | ((us64_t)(result32_2) << 32));
        return result;
    }
    return result;
}

END_C_DECLARATION
// clang-format on
