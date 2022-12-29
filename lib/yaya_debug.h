//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2022 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_DEBUG_H
#define YAYA_DEBUG_H

#include "limits.h"
#include "yaya_number.h"
#include "yaya_type.h"

void yaya_print_bit(void *p, umax size);
void yaya_print_raw(void *p, umax size);

#define PRINT_LOC_MAIN(x)    printf("%s : %d\n", __FILE__, __LINE__)
#define PRINT_FNC_MAIN(x)    printf("%s : %d\n", __func__, __LINE__)
#define PRINT_BIT_MAIN(x)    yaya_print_bit(&(x), sizeof(x))
#define PRINT_RAW_MAIN(x)    yaya_print_raw(&(x), sizeof(x))
#define PRINT_TXT_MAIN(x)    printf(#x); PRINT_NLN()
#define PRINT_SIZ_MAIN(x)    printf("%" PRIuPTR " * %" PRIuMAX "bit\n", sizeof(x), (umax)CHAR_BIT)
#define PRINT_TYP_MAIN(x)    printf("%s\n", typename(x))
#define PRINT_INT_MAIN(x)    printf(typeprint(x), x); PRINT_NLN()
#define PRINT_CHR_MAIN(x)    printf("\'%c\'\n", x)
#define PRINT_FLT_MAIN(x)    printf("%.60f\n", (flmxn(x)))
#define PRINT_STR_MAIN(x)    printf("\'%s\'\n", (TYPE_CHR == typeid(x)) ? (char*)(x) : "[not a text string]")
#define PRINT_PTR_MAIN(x)    printf("%p\n", (&x))


#define PRINT_LOC_TYPE(x)    printf("[loc] " #x " = ")
#define PRINT_FNC_TYPE(x)    printf("[fnk] " #x " = ")
#define PRINT_BIT_TYPE(x)    printf("[bit] " #x " = ")
#define PRINT_RAW_TYPE(x)    printf("[raw] " #x " = ")
#define PRINT_TXT_TYPE(x)    printf("[txt] " #x " = ")
#define PRINT_INT_TYPE(x)    printf("[%3s] " #x " = ", typespec(x))
#define PRINT_CHR_TYPE(x)    printf("[chr] " #x " = ")
#define PRINT_SIZ_TYPE(x)    printf("[siz] " #x " = ")
#define PRINT_TYP_TYPE(x)    printf("[typ] " #x " = ")
#define PRINT_FLT_TYPE(x)    printf("[flt] " #x " = ")
#define PRINT_STR_TYPE(x)    printf("[str] " #x " = ")
#define PRINT_PTR_TYPE(x)    printf("[ptr] " #x " = ")


#define PRINT_LOC(x)    PRINT_LOC_TYPE(x); PRINT_LOC_MAIN(x)
#define PRINT_FNC(x)    PRINT_FNC_TYPE(x); PRINT_FNC_MAIN(x)
#define PRINT_INT(x)    PRINT_INT_TYPE(x); PRINT_INT_MAIN(x)
#define PRINT_CHR(x)    PRINT_CHR_TYPE(x); PRINT_CHR_MAIN(x)
#define PRINT_BIT(x)    PRINT_BIT_TYPE(x); PRINT_BIT_MAIN(x)
#define PRINT_RAW(x)    PRINT_RAW_TYPE(x); PRINT_RAW_MAIN(x)
#define PRINT_SIZ(x)    PRINT_SIZ_TYPE(x); PRINT_SIZ_MAIN(x)
#define PRINT_FLT(x)    PRINT_FLT_TYPE(x); PRINT_FLT_MAIN(x)
#define PRINT_STR(x)    PRINT_STR_TYPE(x); PRINT_STR_MAIN(x)
#define PRINT_PTR(x)    PRINT_PTR_TYPE(x); PRINT_PTR_MAIN(x)
#define PRINT_TYP(x)    PRINT_TYP_TYPE(x); PRINT_TYP_MAIN(x)
#define PRINT_TXT(x)    PRINT_TXT_TYPE(x); PRINT_TXT_MAIN(x)
#define PRINT_NLN( )    printf("\n")

#define PRINT_INF(x) \
    do{                                                                                           \
        PRINT_TXT_MAIN(\n"INFO:");                                                                \
        PRINT_FNC(x);                                                                             \
        PRINT_TYP(x);                                                                             \
        PRINT_SIZ(x);                                                                             \
        PRINT_RAW(x);                                                                             \
        PRINT_BIT(x);                                                                             \
        PRINT_PTR(x);                                                                             \
        umax type = typeid(x);                                                                    \
        switch(type){                                                                             \
            case TYPE_CHR: {                                                                      \
                PRINT_CHR_TYPE(x); PRINT_CHR_MAIN((TYPE_CHR == type) ? (char)x : 0); break;       \
            }                                                                                     \
            case TYPE_INT: {                                                                      \
                PRINT_INT_TYPE(x); PRINT_INT_MAIN((TYPE_INT == type) ? (umax)x : 0); break;       \
            }                                                                                     \
            case TYPE_FLT: {                                                                      \
                PRINT_FLT_TYPE(x); PRINT_FLT_MAIN((TYPE_FLT == type) ? (double)x : 0); break;     \
            }                                                                                     \
        }                                                                                         \
    }while(0)

#endif /*YAYA_DEBUG_H*/
