//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#include "yaya_cdeclaration.h"
BEG_C_DECLARATION

#include "limits.h"
#include "stdint.h"
#include "stdio.h"

#include "yaya_bit.h"
#include "yaya_endian.h"

/*Распечатать число побитово*/
void yaya_print_bit(void *v, size_t size) {
    uintmax_t p = *((uintmax_t*)(v));
    p = ___bit_revers(p, (uintmax_t)(size));

    for(size_t i = 0; i < size; i++){
        for(uintmax_t b = 0; b < CHAR_BIT; b++){
            printf("%c", bit_mask_dw(bit_shf_rig(p, b), umax_c(1)) ? '1' : '0');
        }
        p = bit_shf_rig(p, CHAR_BIT);
        if(i != size - 1){
            printf(" ");
        }
    }
    printf("\n");
}

/*Распечатать число побайтово*/
void yaya_print_but(void *v, size_t size) {
    for(intmax_t i = (intmax_t)(size) - 1; i >= 0; i--){
        uint8_t temp = *(((uint8_t*)(v)) + i);
        printf("%02" PRIX8 "", temp);
        if(i !=  0){
            printf(" ");
        }
    }
    printf("\n");
}

END_C_DECLARATION
