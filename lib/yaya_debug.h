//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_DEBUG_H
#define YAYA_DEBUG_H

#include "yaya_cdeclaration.h"
BEG_C_DECLARATION

#include "stdio.h"
#include "limits.h"

#include "yaya_type.h"
#include "yaya_chek.h"
#include "yaya_sugar.h"

void yaya_print_bit(void* p, size_t size);
void yaya_print_but(void *p, size_t size);

#define __PRINT_VAR_MAIN(x)    BLOC(printf(#x); PRINT_NLN())
#define __PRINT_TXT_MAIN(x)    BLOC(printf(#x); PRINT_NLN())
#define __PRINT_LOC_MAIN(x)    BLOC(printf("%s : %d", __FILE__, __LINE__); PRINT_NLN())
#define __PRINT_FNC_MAIN(x)    BLOC(printf("%s : %d", __FUNC__, __LINE__); PRINT_NLN())
#define __PRINT_SIZ_MAIN(x)    BLOC(printf("%" PRIuPTR " * %" PRIuMAX "bit", sizeof(x), (uintmax_t)(CHAR_BIT)); PRINT_NLN())
#define __PRINT_TYP_MAIN(x)    BLOC(printf("%s", std_type_name(x)); PRINT_NLN())
#define __PRINT_PTR_MAIN(x)    BLOC(printf("%p", (&x)); PRINT_NLN())
#define __PRINT_BIT_MAIN(x)    BLOC(yaya_print_bit(&(x), sizeof(x)))
#define __PRINT_RAW_MAIN(x)    BLOC(yaya_print_but(&(x), sizeof(x)))

#define __PRINT_CHR_MAIN(x) BLOC(\
    BLOC(std_type_group(x) != STD_TYPE_GROUP_CHAR) ? \
    BLOC(printf("\'%s\'", "[not a text literal]")) : \
    BLOC(printf("\'%s\'", (char[]){ COMPILE_CHR_OR_ZERO(x), '\0'} )); PRINT_NLN())

#define __PRINT_STR_MAIN(x) BLOC(\
    BLOC(STD_TYPE_GROUP_CHAR_P != std_type_group(x)) ? \
    BLOC(printf("\'%s\'", "[not a text string]")) : \
    BLOC(printf("\'%s\'", (char*) COMPILE_CHRP_OR_NULL(x))); PRINT_NLN())

#define __PRINT_NUM_MAIN(x) BLOC(\
    BLOC((std_type_group(x) != STD_TYPE_GROUP_SINT) && (std_type_group(x) != STD_TYPE_GROUP_UINT)) ? \
    BLOC(printf("\'%s\'", "[not a integer number]")) : \
    BLOC(char fmt[15] = {0}; snprintf(fmt, 15, "%%%s", std_type_print(x)); printf(fmt, x)); PRINT_NLN())

#define __PRINT_FLP_MAIN(x) BLOC(\
    BLOC(STD_TYPE_GROUP_FLT != std_type_group(x)) ? \
    BLOC(printf("\'%s\'", "[not a floating number]")) : \
    BLOC(char fmt[15] = {0}; snprintf(fmt, 15, "%%%s", std_type_print(x)); printf(fmt, COMPILE_FLT_OR_ZERO(x))); PRINT_NLN())


#define __PRINT_VAR_TYPE(x)    printf("[var] ")
#define __PRINT_TXT_TYPE(x)    printf("[txt] ")
#define __PRINT_LOC_TYPE(x)    printf("[loc] ")
#define __PRINT_FNC_TYPE(x)    printf("[fnk] ")
#define __PRINT_SIZ_TYPE(x)    printf("[siz] ")
#define __PRINT_TYP_TYPE(x)    printf("[typ] ")
#define __PRINT_PTR_TYPE(x)    printf("[ptr] ")
#define __PRINT_BIT_TYPE(x)    printf("[bit] ")
#define __PRINT_RAW_TYPE(x)    printf("[raw] ")
#define __PRINT_CHR_TYPE(x)    printf("[chr] ")
#define __PRINT_STR_TYPE(x)    printf("[str] ")
#define __PRINT_NUM_TYPE(x)    printf("[%3s] ", std_type_spec(x))
#define __PRINT_FLP_TYPE(x)    printf("[%3s] ", std_type_spec(x))


#define PRINT_TXT(x)    __PRINT_TXT_TYPE(x);                   __PRINT_TXT_MAIN(x)
#define PRINT_LOC(x)    __PRINT_LOC_TYPE(x); printf(#x " = "); __PRINT_LOC_MAIN(x)
#define PRINT_FNC(x)    __PRINT_FNC_TYPE(x); printf(#x " = "); __PRINT_FNC_MAIN(x)
#define PRINT_SIZ(x)    __PRINT_SIZ_TYPE(x); printf(#x " = "); __PRINT_SIZ_MAIN(x)
#define PRINT_TYP(x)    __PRINT_TYP_TYPE(x); printf(#x " = "); __PRINT_TYP_MAIN(x)
#define PRINT_PTR(x)    __PRINT_PTR_TYPE(x); printf(#x " = "); __PRINT_PTR_MAIN(x)
#define PRINT_BIT(x)    __PRINT_BIT_TYPE(x); printf(#x " = "); __PRINT_BIT_MAIN(x)
#define PRINT_RAW(x)    __PRINT_RAW_TYPE(x); printf(#x " = "); __PRINT_RAW_MAIN(x)
#define PRINT_CHR(x)    __PRINT_CHR_TYPE(x); printf(#x " = "); __PRINT_CHR_MAIN(x)
#define PRINT_STR(x)    __PRINT_STR_TYPE(x); printf(#x " = "); __PRINT_STR_MAIN(x)
#define PRINT_NUM(x)    __PRINT_NUM_TYPE(x); printf(#x " = "); __PRINT_NUM_MAIN(x)
#define PRINT_FLP(x)    __PRINT_FLP_TYPE(x); printf(#x " = "); __PRINT_FLP_MAIN(x)
#define PRINT_NLN( )    printf("\n"); fflush(stdout)


#define PRINT_DEBUG_INFO(x)                                                                                                                          \
    BLOC(                                                                                                                                            \
    PRINT_NLN();                                                                                                                                     \
    __PRINT_TXT_MAIN(INFO:);                                                                                                                         \
    __PRINT_VAR_TYPE(x); __PRINT_VAR_MAIN(x);                                                                                                        \
    __PRINT_FNC_TYPE(x); __PRINT_FNC_MAIN(x);                                                                                                        \
    __PRINT_TYP_TYPE(x); __PRINT_TYP_MAIN(x);                                                                                                        \
    __PRINT_PTR_TYPE(x); __PRINT_PTR_MAIN(x);                                                                                                        \
    __PRINT_SIZ_TYPE(x); __PRINT_SIZ_MAIN(x);                                                                                                        \
    switch(std_type_group(x)){                                                                                                                       \
    case STD_TYPE_GROUP_CHAR:                                                                                                                        \
    case STD_TYPE_GROUP_SINT:                                                                                                                        \
    case STD_TYPE_GROUP_UINT:                                                                                                                        \
    case STD_TYPE_GROUP_FLT:                                                                                                                         \
    __PRINT_BIT_TYPE(x);                                                                                                                             \
    __PRINT_BIT_MAIN(x);                                                                                                                             \
    __PRINT_RAW_TYPE(x);                                                                                                                             \
    __PRINT_RAW_MAIN(x);                                                                                                                             \
    break;                                                                                                                                           \
    }                                                                                                                                                \
    switch(std_type_group(x)){                                                                                                                       \
    case STD_TYPE_GROUP_CHAR:   { __PRINT_CHR_TYPE(x); __PRINT_CHR_MAIN(COMPILE_CHR_OR_ZERO(x));  break; }                                           \
    case STD_TYPE_GROUP_SINT:   { __PRINT_NUM_TYPE(x); __PRINT_NUM_MAIN(COMPILE_INT_OR_ZERO(x));  break; }                                           \
    case STD_TYPE_GROUP_UINT:   { __PRINT_NUM_TYPE(x); __PRINT_NUM_MAIN(COMPILE_INT_OR_ZERO(x));  break; }                                           \
    case STD_TYPE_GROUP_FLT:    { __PRINT_FLP_TYPE(x); __PRINT_FLP_MAIN(COMPILE_FLT_OR_ZERO(x));  break; }                                           \
    case STD_TYPE_GROUP_CHAR_P: { __PRINT_STR_TYPE(x); __PRINT_STR_MAIN(COMPILE_CHRP_OR_NULL(x)); break; }                                           \
    default:                    { __PRINT_TYP_TYPE(x); __PRINT_TXT_MAIN('[not find type]');       break; }                                           \
    }                                                                                                                                                \
    )

#define PRINT_DEBUG_ALL(x)  \
    __PRINT_TXT_MAIN(ALL:); \
    PRINT_TXT(x);           \
    PRINT_LOC(x);           \
    PRINT_FNC(x);           \
    PRINT_SIZ(x);           \
    PRINT_TYP(x);           \
    PRINT_PTR(x);           \
    PRINT_BIT(x);           \
    PRINT_RAW(x);           \
    PRINT_CHR(x);           \
    PRINT_STR(x);           \
    PRINT_NUM(x);           \
    PRINT_FLP(x)

END_C_DECLARATION
#endif /*YAYA_DEBUG_H*/
