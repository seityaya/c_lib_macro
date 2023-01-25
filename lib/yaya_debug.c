//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#include "stdio.h"
#include "limits.h"
#include "stdint.h"

#include "yaya_bit.h"
#include "yaya_endian.h"

/*Распечатать число побитово*/
void yaya_print_bit(void *v, size_t size) {
    uintmax_t p = *((uintmax_t*)(v));
    p = yaya_bit_revers(p, size);

    for(size_t i = 0; i < size; i++){
        for(uintmax_t b = 0; b < CHAR_BIT; b++){
            printf("%c", BIT_MASK_DW(BIT_SHF_RIG(p, b), u_max_c(1)) ? '1' : '0');
        }
        p = BIT_SHF_RIG(p, CHAR_BIT);
        printf(" ");
    }
    printf("\n");
}

/*Распечатать число побайтово*/
void yaya_print_but(void *v, size_t size) {
    for(size_t i = size - 1; i >= 0 ; i--){
        uint8_t temp = *(((uint8_t*)(v)) + i);
        printf("%02" PRIX8 " ", temp);
    }
    printf("\n");
}
