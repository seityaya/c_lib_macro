//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#include "yaya_bit.h"

#define BIT_SET_ALL_1(x, s)   ((sizeof(x) == (s)) ? (umaxc(0) - umaxc(1)) :  (BIT_SHF_LEF(umaxc(1), CHAR_BIT * (s)) - 1))

/*Возвращает позицию первого (младшего / правого) выключеного бита для заданого размера*/
i08s yaya_bit_0_beg(umax x, u08s s) {
    if(x == BIT_SET_ALL_1(x, s)){
        return 0;
    }
    i08s res = 1;
    while (BIT_GET(x, res) != 0 && res != (CHAR_BIT * s)) {
        res++;
    }
    return res;
}

/*Возвращает позицию последнего (старшего / левого) выключеного бита для заданого размера*/
i08s yaya_bit_0_end(umax x, u08s s) {
    if(x == BIT_SET_ALL_1(x, s)){
        return 0;
    }
    i08s res = CHAR_BIT * s;
    while (BIT_GET(x, res) != 0 && res != 0) {
        res--;
    }
    return res;
}

/*Возвращает количество выключеных битов для заданого размера*/
i08s yaya_bit_0_cnt(umax x, u08s s) {
    return (i08s)((CHAR_BIT * s) - yaya_bit_1_cnt(x));
}

/*Возвращает положение одного единственого выключеного бита*/
i08s yaya_bit_0_pos(umax x, u08s s) {
    if(x == BIT_SET_ALL_1(x, s)){
        return 0;
    }
    if(yaya_bit_0_cnt(x, s) > 1){
        return -1;
    }
    return yaya_bit_0_beg(x, s);
}

/*Возвращает позицию первого (младшего / правого) взведенного бита*/
i08s yaya_bit_1_beg(umax x) {
    if(x == 0){
        return 0;
    }
    return (i08s)(yaya_bit_1_cnt((x - 1) & ~x) + (1));
}

/*Возвращает позицию последнего (старшего / левого) взведенного бита*/
i08s yaya_bit_1_end(umax x) {
    if(x == 0){
        return 0;
    }
    i08s res = 1;
    while (x != 1) {
        x >>= 1;
        res++;
    }
    return res;
}

/*Возвращает количество взведенных битов*/
i08s yaya_bit_1_cnt(umax x) {
    x = ((x >>  1) & 0x5555555555555555) + (x & 0x5555555555555555);
    x = ((x >>  2) & 0x3333333333333333) + (x & 0x3333333333333333);
    x = ((x >>  4) & 0x0F0F0F0F0F0F0F0F) + (x & 0x0F0F0F0F0F0F0F0F);
    x = ((x >>  8) & 0x00FF00FF00FF00FF) + (x & 0x00FF00FF00FF00FF);
    x = ((x >> 16) & 0x0000FFFF0000FFFF) + (x & 0x0000FFFF0000FFFF);
    x = ((x >> 32) & 0x00000000FFFFFFFF) + (x & 0x00000000FFFFFFFF);
    return (i08s)(x);
}

/*Возвращает положение одного единственого взведенного бита*/
i08s yaya_bit_1_pos(umax x) {
    if(x == 0){
        return 0;
    }
    if(yaya_bit_1_cnt(x) > 1){
        return -1;
    }
    return yaya_bit_1_beg(x);
}

/*Развернуть биты в противоположный порядок*/
umax yaya_bit_revers(umax x, u08s s) {
    {x = (x & 0x00000000FFFFFFFF) << 32 | (x & 0xFFFFFFFF00000000) >> 32;}
    {x = (x & 0x0000FFFF0000FFFF) << 16 | (x & 0xFFFF0000FFFF0000) >> 16;}
    {x = (x & 0x00FF00FF00FF00FF) << 8  | (x & 0xFF00FF00FF00FF00) >> 8 ;}
    {x = (x & 0xf0f0f0f0f0f0f0f0) >> 4  | (x & 0x0f0f0f0f0f0f0f0f) << 4 ;}
    {x = (x & 0xcccccccccccccccc) >> 2  | (x & 0x3333333333333333) << 2 ;}
    {x = (x & 0xaaaaaaaaaaaaaaaa) >> 1  | (x & 0x5555555555555555) << 1 ;}
    x = BIT_CYC_LEF(x, (CHAR_BIT * s));
    return x;
}
