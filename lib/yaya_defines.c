//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2022 Seityagiya Terlekchi. All rights reserved.

#include "yaya_defines.h"
#include "stdio.h"

/*Возвращает позицию первого взведеного бита*/
i08s yaya_bit_position(umax x) {
    if (x <= 1){
        return yaya_bit_onse_bit(x);
    }else{
        return -1;
    }
}

i08s yaya_bit_onse_bit(umax n) {
    n = ((n>>1) & 0x5555555555555555) + (n & 0x5555555555555555);
    n = ((n>>2) & 0x3333333333333333) + (n & 0x3333333333333333);
    n = ((n>>4) & 0x0F0F0F0F0F0F0F0F) + (n & 0x0F0F0F0F0F0F0F0F);
    n = ((n>>8) & 0x00FF00FF00FF00FF) + (n & 0x00FF00FF00FF00FF);
    n = ((n>>16) & 0x0000FFFF0000FFFF) + (n & 0x0000FFFF0000FFFF);
    n = ((n>>32) & 0x00000000FFFFFFFF) + (n & 0x00000000FFFFFFFF);
    return n;
}

umax yaya_bit_revers(umax x, umax n) {
    x = (x & 0x00000000FFFFFFFF) << 32 | (x & 0xFFFFFFFF00000000) >> 32;
    x = (x & 0x0000FFFF0000FFFF) << 16 | (x & 0xFFFF0000FFFF0000) >> 16;
    x = (x & 0x00FF00FF00FF00FF) << 8  | (x & 0xFF00FF00FF00FF00) >> 8;
    x = (x & 0xf0f0f0f0f0f0f0f0) >> 4  | (x & 0x0f0f0f0f0f0f0f0f) << 4;
    x = (x & 0xcccccccccccccccc) >> 2  | (x & 0x3333333333333333) << 2;
    x = (x & 0xaaaaaaaaaaaaaaaa) >> 1  | (x & 0x5555555555555555) << 1;
    x = BIT_CYC_LEF(x, (n*8));
    return x;
}

void yaya_print_bit(void *v, uintmax_t size) {
    uintmax_t p = *((uintmax_t*)(v));

    if(ENDIAN_BIT == ENDIAN_LIT){
        p = BIT_REV(p);
        p = BIT_CYC_RIG(p, (size*8));
    }

    for(uintmax_t i = 0; i < size; i++){
        for(uint_fast8_t b = 0; b < 8; b++){
            printf("%c",  (BIT_MASK_DW(BIT_SHF_RIG(p, b), 0x01) ? '1' : '0'));
        }
        p = BIT_SHF_RIG(p, 8);
        printf(" ");
    }
    printf("\n");
}

void yaya_print_raw(void *p, uintmax_t size) {
    for(uintmax_t i = 0; i < size; i++){
        uint8_t temp = *(((uint8_t*)(p)) + i);
        printf("%02" PRIX8 " ", temp);
    }
    printf("\n");
}
