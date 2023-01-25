//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_DEBUG_H
#define YAYA_DEBUG_H

#include "stdio.h"

#include "yaya_number.h"
#include "yaya_type.h"
#include "yaya_chek.h"
#include "yaya_sugar.h"

void yaya_print_bit(void* p, umax size);
void yaya_print_but(void *p, umax size);

#define PRINT_LOC_MAIN(x)    printf("%s : %d\n", __FILE__, __LINE__)
#define PRINT_FNC_MAIN(x)    printf("%s : %d\n", __FUNC__, __LINE__)
#define PRINT_BIT_MAIN(x)    yaya_print_bit(&(x), sizeof(x))
#define PRINT_RAW_MAIN(x)    yaya_print_but(&(x), sizeof(x))
#define PRINT_SIZ_MAIN(x)    printf("%" PRIuPTR " * %" PRIuMAX "bit\n", sizeof(x), (umax)(CHAR_BIT))
#define PRINT_TYP_MAIN(x)    printf("%s\n", type_name(x))
#define PRINT_TXT_MAIN(x)    printf(#x"\n");
#define PRINT_PTR_MAIN(x)    printf("%p\n", (&x))
#define PRINT_CHR_MAIN(x)    { ((TYPE_CHR   != type_group(x)) ? printf("\'%s\'\n", "[not a text literal]")    : printf("\'%s\'\n", (char[]){ COMPILE_CHR_OR_ZERO(x), '\0'} )                            ); }
#define PRINT_STR_MAIN(x)    { ((TYPE_CHR_P != type_group(x)) ? printf("\'%s\'\n", "[not a text string]")     : printf("\'%s\'\n", (char*) COMPILE_CHRP_OR_NULL(x))                                     ); }
#define PRINT_INT_MAIN(x)    { ((TYPE_INT   != type_group(x)) ? printf("\'%s\'\n", "[not a integer number]")  : ({ char fmt[15] = {0};  snprintf(fmt, 15, "%%%s\n", type_print(x));  printf(fmt, x); }) ); }
#define PRINT_FLT_MAIN(x)    { ((TYPE_FLT   != type_group(x)) ? printf("\'%s\'\n", "[not a floating number]") : printf("%.60f\n", (flmaxc(COMPILE_FLT_OR_ZERO(x))))                                     ); }

#define PRINT_LOC_TYPE(x)    printf("[loc] " #x " = ")
#define PRINT_FNC_TYPE(x)    printf("[fnk] " #x " = ")
#define PRINT_BIT_TYPE(x)    printf("[bit] " #x " = ")
#define PRINT_RAW_TYPE(x)    printf("[raw] " #x " = ")
#define PRINT_SIZ_TYPE(x)    printf("[siz] " #x " = ")
#define PRINT_TYP_TYPE(x)    printf("[typ] " #x " = ")
#define PRINT_TXT_TYPE(x)    printf("[txt] " #x " = ")
#define PRINT_PTR_TYPE(x)    printf("[ptr] " #x " = ")
#define PRINT_CHR_TYPE(x)    printf("[chr] " #x " = ")
#define PRINT_STR_TYPE(x)    printf("[str] " #x " = ")
#define PRINT_INT_TYPE(x)    printf("[%3s] " #x " = ", type_spec(x))
#define PRINT_FLT_TYPE(x)    printf("[flt] " #x " = ")

#define PRINT_LOC(x)    PRINT_LOC_TYPE(x); PRINT_LOC_MAIN(x)
#define PRINT_FNC(x)    PRINT_FNC_TYPE(x); PRINT_FNC_MAIN(x)
#define PRINT_BIT(x)    PRINT_BIT_TYPE(x); PRINT_BIT_MAIN(x)
#define PRINT_RAW(x)    PRINT_RAW_TYPE(x); PRINT_RAW_MAIN(x)
#define PRINT_SIZ(x)    PRINT_SIZ_TYPE(x); PRINT_SIZ_MAIN(x)
#define PRINT_TYP(x)    PRINT_TYP_TYPE(x); PRINT_TYP_MAIN(x)
#define PRINT_TXT(x)    PRINT_TXT_TYPE(x); PRINT_TXT_MAIN(x)
#define PRINT_PTR(x)    PRINT_PTR_TYPE(x); PRINT_PTR_MAIN(x)
#define PRINT_CHR(x)    PRINT_CHR_TYPE(x); PRINT_CHR_MAIN(x)
#define PRINT_STR(x)    PRINT_STR_TYPE(x); PRINT_STR_MAIN(x)
#define PRINT_INT(x)    PRINT_INT_TYPE(x); PRINT_INT_MAIN(x)
#define PRINT_FLT(x)    PRINT_FLT_TYPE(x); PRINT_FLT_MAIN(x)
#define PRINT_NLN( )    printf("\n")


#define PRINT_DEBUG_INFO(x)                                                                         \
    do{                                                                                             \
        PRINT_NLN();                                                                                \
        PRINT_TXT_MAIN(INFO:);                                                                      \
        PRINT_FNC(x);                                                                               \
        PRINT_TYP(x);                                                                               \
        PRINT_SIZ(x);                                                                               \
        PRINT_RAW(x);                                                                               \
        PRINT_BIT(x);                                                                               \
        PRINT_PTR(x);                                                                               \
        switch(type_group(x)){                                                                      \
            case TYPE_CHR:   { PRINT_CHR_TYPE(x); PRINT_CHR_MAIN(COMPILE_CHR_OR_ZERO(x));  break; } \
            case TYPE_INT:   { PRINT_INT_TYPE(x); PRINT_INT_MAIN(COMPILE_INT_OR_ZERO(x));  break; } \
            case TYPE_FLT:   { PRINT_FLT_TYPE(x); PRINT_FLT_MAIN(COMPILE_FLT_OR_ZERO(x));  break; } \
            case TYPE_CHR_P: { PRINT_STR_TYPE(x); PRINT_STR_MAIN(COMPILE_CHRP_OR_NULL(x)); break; } \
            default:         { PRINT_TYP_TYPE(x); PRINT_TXT_MAIN('[not find type]');       break; } \
        }                                                                                           \
    }while(0)


#define PRINT_DEBUG_ALL(x)\
    PRINT_NLN();          \
    PRINT_TXT_MAIN(ALL:); \
    PRINT_LOC(x);         \
    PRINT_FNC(x);         \
    PRINT_BIT(x);         \
    PRINT_RAW(x);         \
    PRINT_SIZ(x);         \
    PRINT_TYP(x);         \
    PRINT_TXT(x);         \
    PRINT_PTR(x);         \
    PRINT_CHR(x);         \
    PRINT_STR(x);         \
    PRINT_INT(x);         \
    PRINT_FLT(x);

#endif /*YAYA_DEBUG_H*/
