// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_DEBUG_H
#define YAYA_DEBUG_H

#include "stdio.h"

#include "yaya_gover.h"
#include "yaya_sugar.h"
#include "yaya_type.h"

// clang-format off
#include "yaya_cdecl.h"
BEG_C_DECLARATION

//================= DEBUG ============================================================================================================================

void yaya_print_bite(void* p, size_t size);
void yaya_print_byte(void *p, size_t size);

//----------------------------------------------------------------------------------------------------------------------------------------------------

#define __PRINT(...)        BLOCK(printf(__VA_ARGS__); fflush(stdout))

#define __PRINT_VAR_MAIN(x) BLOCK(__PRINT(#x); PRINT_NLN())
#define __PRINT_TXT_MAIN(x) BLOCK(__PRINT(#x); PRINT_NLN())
#define __PRINT_LOC_MAIN(x) BLOCK(__PRINT("%s : %d", __FILE__, __LINE__); PRINT_NLN())
#define __PRINT_FNC_MAIN(x) BLOCK(__PRINT("%s : %d", __FUNC__, __LINE__); PRINT_NLN())
#define __PRINT_SIZ_MAIN(x) BLOCK(__PRINT("%" PRIuPTR " byte", sizeof(x)); PRINT_NLN())
#define __PRINT_TYP_MAIN(x) BLOCK(__PRINT("%s", base_type_full_name(x)); PRINT_NLN())
#define __PRINT_PTR_MAIN(x) BLOCK(__PRINT("%p", (&(x))); PRINT_NLN())
#define __PRINT_BIT_MAIN(x) BLOCK(yaya_print_bite((&(x)), sizeof(x)))
#define __PRINT_RAW_MAIN(x) BLOCK(yaya_print_byte((&(x)), sizeof(x)))

#define __PRINT_BOL_MAIN(x) BLOCK(                                                                                                                   \
    BLOCK(base_type_group(x) != BASE_TYPE_GROUP_BOOL) ?                                                                                              \
    BLOCK(__PRINT("%s", "[not a bool type]")) :                                                                                                      \
    BLOCK(__PRINT("\'%s\'", COMPILE_BOOL_VAR_OR_ZERO(x) ? "true" : "false" )); PRINT_NLN())

#define __PRINT_CHR_MAIN(x) BLOCK(                                                                                                                   \
    BLOCK(base_type_group(x) != BASE_TYPE_GROUP_CHAR) ?                                                                                              \
    BLOCK(__PRINT("%s", "[not a text literal]")) :                                                                                                   \
    BLOCK(__PRINT("\'%s\'", (char[]){ COMPILE_CHAR_VAR_OR_ZERO(x), '\0'} )); PRINT_NLN())

#define __PRINT_STR_MAIN(x) BLOCK(                                                                                                                   \
    BLOCK(BASE_TYPE_GROUP_CHAR_P != base_type_group(x)) ?                                                                                            \
    BLOCK(__PRINT("%s", "[not a text string]")) :                                                                                                    \
    BLOCK(__PRINT("\'%s\'", (char*) COMPILE_CHAR_PTR_OR_NULL(x))); PRINT_NLN())

#define __PRINT_NUM_MAIN(x) BLOCK(                                                                                                                   \
    BLOCK((base_type_group(x) != BASE_TYPE_GROUP_SINT) && (base_type_group(x) != BASE_TYPE_GROUP_UINT)) ?                                            \
    BLOCK(__PRINT("%s", "[not a integer number]")) :                                                                                                 \
    BLOCK(char fmt[15] = {0}; snprintf(fmt, 15, "%%%s", base_type_print(x)); __PRINT(fmt, x)); PRINT_NLN())

#define __PRINT_FLP_MAIN(x) BLOCK(                                                                                                                   \
    BLOCK(BASE_TYPE_GROUP_FLT != base_type_group(x)) ?                                                                                               \
    BLOCK(__PRINT("%s", "[not a floating number]")) :                                                                                                \
    BLOCK(char fmt[15] = {0}; snprintf(fmt, 15, "%%.60%s", base_type_print(x)); __PRINT(fmt, COMPILE_FLT_VAR_OR_ZERO(x))); PRINT_NLN())

//----------------------------------------------------------------------------------------------------------------------------------------------------

#define __PRINT_VAR_TYPE(x) __PRINT("[var] ")
#define __PRINT_TXT_TYPE(x) __PRINT("[txt] ")
#define __PRINT_LOC_TYPE(x) __PRINT("[loc] ")
#define __PRINT_FNC_TYPE(x) __PRINT("[fnk] ")
#define __PRINT_SIZ_TYPE(x) __PRINT("[siz] ")
#define __PRINT_TYP_TYPE(x) __PRINT("[typ] ")
#define __PRINT_PTR_TYPE(x) __PRINT("[ptr] ")
#define __PRINT_BIT_TYPE(x) __PRINT("[bit] ")
#define __PRINT_RAW_TYPE(x) __PRINT("[raw] ")
#define __PRINT_BOL_TYPE(x) __PRINT("[bol] ")
#define __PRINT_CHR_TYPE(x) __PRINT("[chr] ")
#define __PRINT_STR_TYPE(x) __PRINT("[str] ")
#define __PRINT_SPC_TYPE(x) __PRINT("[%3s] ", base_type_spec(x))
#define __PRINT_UND_TYPE(x) __PRINT("[und] ")

#define PRINT_TXT(x)        __PRINT_TXT_TYPE(x);                    __PRINT_TXT_MAIN(x)
#define PRINT_VAR(x)        __PRINT_VAR_TYPE(x);                    __PRINT_VAR_MAIN(x)
#define PRINT_LOC(x)        __PRINT_LOC_TYPE(x); __PRINT(#x " = "); __PRINT_LOC_MAIN(x)
#define PRINT_FNC(x)        __PRINT_FNC_TYPE(x); __PRINT(#x " = "); __PRINT_FNC_MAIN(x)
#define PRINT_SIZ(x)        __PRINT_SIZ_TYPE(x); __PRINT(#x " = "); __PRINT_SIZ_MAIN(x)
#define PRINT_TYP(x)        __PRINT_TYP_TYPE(x); __PRINT(#x " = "); __PRINT_TYP_MAIN(x)
#define PRINT_PTR(x)        __PRINT_PTR_TYPE(x); __PRINT(#x " = "); __PRINT_PTR_MAIN(x)
#define PRINT_BIT(x)        __PRINT_BIT_TYPE(x); __PRINT(#x " = "); __PRINT_BIT_MAIN(x)
#define PRINT_RAW(x)        __PRINT_RAW_TYPE(x); __PRINT(#x " = "); __PRINT_RAW_MAIN(x)
#define PRINT_BOL(x)        __PRINT_BOL_TYPE(x); __PRINT(#x " = "); __PRINT_BOL_MAIN(x)
#define PRINT_CHR(x)        __PRINT_CHR_TYPE(x); __PRINT(#x " = "); __PRINT_CHR_MAIN(x)
#define PRINT_STR(x)        __PRINT_STR_TYPE(x); __PRINT(#x " = "); __PRINT_STR_MAIN(x)
#define PRINT_NUM(x)        __PRINT_SPC_TYPE(x); __PRINT(#x " = "); __PRINT_NUM_MAIN(x)
#define PRINT_FLP(x)        __PRINT_SPC_TYPE(x); __PRINT(#x " = "); __PRINT_FLP_MAIN(x)
#define PRINT_NLN( )        __PRINT("\n"); fflush(stdout)

//----------------------------------------------------------------------------------------------------------------------------------------------------

#define PRINT_DEBUG_INFO(x)                                                                                                                          \
    BLOCK(                                                                                                                                           \
        __PRINT_TXT_MAIN(INFO:);                                                                                                                     \
        __PRINT_VAR_TYPE(x); __PRINT_VAR_MAIN(x);                                                                                                    \
        __PRINT_FNC_TYPE(x); __PRINT_FNC_MAIN(x);                                                                                                    \
        __PRINT_TYP_TYPE(x); __PRINT_TYP_MAIN(x);                                                                                                    \
        __PRINT_PTR_TYPE(x); __PRINT_PTR_MAIN(x);                                                                                                    \
        __PRINT_SIZ_TYPE(x); __PRINT_SIZ_MAIN(x);                                                                                                    \
        switch(base_type_group(x)) {                                                                                                                 \
            case BASE_TYPE_GROUP_CHAR:                                                                                                               \
            case BASE_TYPE_GROUP_SINT:                                                                                                               \
            case BASE_TYPE_GROUP_UINT:                                                                                                               \
            case BASE_TYPE_GROUP_FLT:                                                                                                                \
            __PRINT_BIT_TYPE(x); __PRINT_BIT_MAIN(x);                                                                                                \
            __PRINT_RAW_TYPE(x); __PRINT_RAW_MAIN(x);                                                                                                \
            break;                                                                                                                                   \
            default:                                                                                                                                 \
            break;                                                                                                                                   \
        }                                                                                                                                            \
        switch(base_type_group(x)) {                                                                                                                 \
            case BASE_TYPE_GROUP_BOOL:   { __PRINT_BOL_TYPE(x); __PRINT_BOL_MAIN(COMPILE_BOOL_VAR_OR_ZERO(x));  break; }                             \
            case BASE_TYPE_GROUP_CHAR:   { __PRINT_CHR_TYPE(x); __PRINT_CHR_MAIN(COMPILE_CHAR_VAR_OR_ZERO(x));  break; }                             \
            case BASE_TYPE_GROUP_SINT:   { __PRINT_SPC_TYPE(x); __PRINT_NUM_MAIN(COMPILE_INT_VAR_OR_ZERO(x));   break; }                             \
            case BASE_TYPE_GROUP_UINT:   { __PRINT_SPC_TYPE(x); __PRINT_NUM_MAIN(COMPILE_INT_VAR_OR_ZERO(x));   break; }                             \
            case BASE_TYPE_GROUP_FLT:    { __PRINT_SPC_TYPE(x); __PRINT_FLP_MAIN(COMPILE_FLT_VAR_OR_ZERO(x));   break; }                             \
            case BASE_TYPE_GROUP_CHAR_P: { __PRINT_STR_TYPE(x); __PRINT_STR_MAIN(COMPILE_CHAR_PTR_OR_NULL(x));  break; }                             \
            default:                     { __PRINT_UND_TYPE(x); __PRINT_TXT_MAIN('[not find type]');            break; }                             \
        }                                                                                                                                            \
    )

#define PRINT_DEBUG_ALL(x)                                                                                                                           \
    BLOCK(                                                                                                                                           \
        __PRINT_TXT_MAIN(ALL:);                                                                                                                      \
        __PRINT_VAR_TYPE(x); __PRINT_VAR_MAIN(x);                                                                                                    \
        __PRINT_LOC_TYPE(x); __PRINT_LOC_MAIN(x);                                                                                                    \
        __PRINT_FNC_TYPE(x); __PRINT_FNC_MAIN(x);                                                                                                    \
        __PRINT_SIZ_TYPE(x); __PRINT_SIZ_MAIN(x);                                                                                                    \
        __PRINT_TYP_TYPE(x); __PRINT_TYP_MAIN(x);                                                                                                    \
        __PRINT_PTR_TYPE(x); __PRINT_PTR_MAIN(x);                                                                                                    \
        __PRINT_BIT_TYPE(x); __PRINT_BIT_MAIN(x);                                                                                                    \
        __PRINT_RAW_TYPE(x); __PRINT_RAW_MAIN(x);                                                                                                    \
        __PRINT_BOL_TYPE(x); __PRINT_BOL_MAIN(x);                                                                                                    \
        __PRINT_CHR_TYPE(x); __PRINT_CHR_MAIN(x);                                                                                                    \
        __PRINT_STR_TYPE(x); __PRINT_STR_MAIN(x);                                                                                                    \
        __PRINT_SPC_TYPE(x); __PRINT_NUM_MAIN(x);                                                                                                    \
        __PRINT_SPC_TYPE(x); __PRINT_FLP_MAIN(x);                                                                                                    \
    )

//====================================================================================================================================================

END_C_DECLARATION
// clang-format on
#endif /*YAYA_DEBUG_H*/
