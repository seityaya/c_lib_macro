// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "inttypes.h"
#include "limits.h"
#include "stdio.h"

#include "yaya_bit.h"
#include "yaya_cdecl.h"
#include "yaya_type.h"

// clang-format off
BEG_C_DECLARATION

/*Распечатать число побитово*/
void yaya_print_bite(void *v, size_t size) {
    for(size_t i = 0; i < size; i++) {
        us8_t temp = *(((us8_t*)(v)) + i);
        temp = bit_rev(temp);
        for(is8_t b = 1; b <= CHAR_BIT; b++) {
            if(bit_get(temp, b)) {
                printf("%c", '1');
            } else {
                printf("%c", '0');
            }
        }
        if(i != size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

/*Распечатать число побайтово*/
void yaya_print_byte(void *v, size_t size) {
    for(size_t i = 0; i < size; i++) {
        us8_t temp = *(((us8_t*)(v)) + i);
        printf("0x%02" PRIX8 "", temp);
        if(i != (size - 1)) {
            printf(" ");
        }
    }
    printf("\n");
}

END_C_DECLARATION
// clang-format on
