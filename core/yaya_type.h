// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_TYPE_H
#define YAYA_TYPE_H

#include "inttypes.h"
#include "limits.h"
#include "stdint.h"

// clang-format off
#include "yaya_cdecl.h"
BEG_C_DECLARATION

//================= SETTINGS =========================================================================================================================
/*
 * Settings
*/
#ifndef YAYA_USING_FLOATING
#define YAYA_USING_FLOATING 1
#include "float.h"

/*TODO Del*/
#define FLT32_MIN__      FLT_MIN
#define FLT64_MIN__      DBL_MIN
#define FLT128_MIN__     LDBL_MIN

#define FLT32_MAX__      FLT_MAX
#define FLT64_MAX__      DBL_MAX
#define FLT128_MAX__     LDBL_MAX

#define FLT32_EPSILON__  FLT_EPSILON
#define FLT64_EPSILON__  DBL_EPSILON
#define FLT128_EPSILON__ LDBL_EPSILON

#ifndef YAYA_USING_COMPLEX
#define YAYA_USING_COMPLEX 1
#include "complex.h"
#endif /*YAYA_USING_COMPLEX*/
#endif /*YAYA_USING_FLOATING*/

//================= TYPE CAST ========================================================================================================================
/*
 * Type cast
*/
#define base_type_cast(type, value) ((typeof(type))(value))

//================= TYPE FULL NAME TEXT ==============================================================================================================
/*
 * Type full name text
*/
#define __base_type_name_bool                                                                                                                        \
    _Bool                              : "bool",

#define __base_type_name_bool_p                                                                                                                      \
    _Bool*                             : "point to bool",

#define __base_type_name_char                                                                                                                        \
    char                               : "char",

#define __base_type_name_char_p                                                                                                                      \
    char*                              : "point to char",

#define __base_type_name_int                                                                                                                         \
    signed char                        : "signed char",                                                                                              \
    unsigned char                      : "unsigned char",                                                                                            \
    signed int                         : "signed int",                                                                                               \
    unsigned int                       : "unsigned int",                                                                                             \
    signed short                       : "signed short",                                                                                             \
    unsigned short                     : "unsigned short",                                                                                           \
    signed long                        : "signed long",                                                                                              \
    unsigned long                      : "unsigned long",                                                                                            \
    signed long long                   : "signed long long",                                                                                         \
    unsigned long long                 : "unsigned long long",

#define __base_type_name_int_p                                                                                                                       \
    signed char*                       : "point to signed char",                                                                                     \
    unsigned char*                     : "point to unsigned char",                                                                                   \
    signed int*                        : "point to signed int",                                                                                      \
    unsigned int*                      : "point to unsigned int",                                                                                    \
    signed short*                      : "point to signed short",                                                                                    \
    unsigned short*                    : "point to unsigned short",                                                                                  \
    signed long*                       : "point to signed long",                                                                                     \
    unsigned long*                     : "point to unsigned long",                                                                                   \
    signed long long*                  : "point to signed long long",                                                                                \
    unsigned long long*                : "point to unsigned long long",

#if YAYA_USING_FLOATING
#define __base_type_name_flt                                                                                                                         \
    float                              : "float",                                                                                                    \
    double                             : "double",                                                                                                   \
    long double                        : "long double",

#define __base_type_name_flt_p                                                                                                                       \
    float*                             : "point to float",                                                                                           \
    double*                            : "point to double",                                                                                          \
    long double*                       : "point to long double",
#else
#define __base_type_name_flt
#define __base_type_name_flt_p
#endif

#if YAYA_USING_COMPLEX
#define __base_type_name_cpl                                                                                                                         \
    float complex                      : "float complex",                                                                                            \
    double complex                     : "double complex",                                                                                           \
    long double complex                : "long double complex",

#define __base_type_name_cpl_p                                                                                                                       \
    float complex*                     : "point to float complex",                                                                                   \
    double complex*                    : "point to double complex",                                                                                  \
    long double complex*               : "point to long double complex",
#else
#define __base_type_name_cpl
#define __base_type_name_cpl_p
#endif

#define __base_type_name_void_p                                                                                                                      \
    void*                              : "point to void",

#define base_type_full_name(x)                                                                                                                       \
    _Generic((x),                                                                                                                                    \
        __base_type_name_bool                                                                                                                        \
        __base_type_name_char                                                                                                                        \
        __base_type_name_int                                                                                                                         \
        __base_type_name_flt                                                                                                                         \
        __base_type_name_cpl                                                                                                                         \
        __base_type_name_bool_p                                                                                                                      \
        __base_type_name_char_p                                                                                                                      \
        __base_type_name_int_p                                                                                                                       \
        __base_type_name_flt_p                                                                                                                       \
        __base_type_name_cpl_p                                                                                                                       \
        __base_type_name_void_p                                                                                                                      \
        default                        : "base type full name undefined")

//================= TYPE SHORT NAME TEXT =============================================================================================================
/*
 * Type short name text
*/
#define __base_type_spec_bool                                                                                                                        \
    _Bool                              : "bol",

#define __base_type_spec_bool_p                                                                                                                      \
    _Bool*                             : "bol",

#define __base_type_spec_char                                                                                                                        \
    char                               : "chr",

#define __base_type_spec_char_p                                                                                                                      \
    char*                              : "str",

#define __base_type_spec_int                                                                                                                         \
    int8_t                             : "i08",                                                                                                      \
    int16_t                            : "i16",                                                                                                      \
    int32_t                            : "i32",                                                                                                      \
    int64_t                            : "i64",                                                                                                      \
    uint8_t                            : "u08",                                                                                                      \
    uint16_t                           : "u16",                                                                                                      \
    uint32_t                           : "u32",                                                                                                      \
    uint64_t                           : "u64",

#define __base_type_spec_int_p                                                                                                                       \
    int8_t*                            : "i08",                                                                                                      \
    int16_t*                           : "i16",                                                                                                      \
    int32_t*                           : "i32",                                                                                                      \
    int64_t*                           : "i64",                                                                                                      \
    uint8_t*                           : "u08",                                                                                                      \
    uint16_t*                          : "u16",                                                                                                      \
    uint32_t*                          : "u32",                                                                                                      \
    uint64_t*                          : "u64",

#if YAYA_USING_FLOATING
#define __base_type_spec_flt                                                                                                                         \
    float                              : "flt",                                                                                                      \
    double                             : "dbl",                                                                                                      \
    long double                        : "ldb",
#define __base_type_spec_flt_p                                                                                                                       \
    float*                             : "flt",                                                                                                      \
    double*                            : "dbl",                                                                                                      \
    long double*                       : "ldb",
#else
#define __base_type_spec_flt
#define __base_type_spec_flt_p
#endif

#if YAYA_USING_COMPLEX
#define __base_type_spec_cpl                                                                                                                         \
    float complex                      : "fcp",                                                                                                      \
    double complex                     : "cpl",                                                                                                      \
    long double complex                : "lcp",

#define __base_type_spec_cpl_p                                                                                                                       \
    float complex*                     : "fcp",                                                                                                      \
    double complex*                    : "cpl",                                                                                                      \
    long double complex*               : "lcp",
#else
#define __base_type__cpl
#define __base_type__cpl_p
#endif

#define __base_type_spec_void_p                                                                                                                      \
    void*                              : "vpt",

#define base_type_spec(x)                                                                                                                            \
    _Generic((x),                                                                                                                                    \
        __base_type_spec_bool                                                                                                                        \
        __base_type_spec_char                                                                                                                        \
        __base_type_spec_int                                                                                                                         \
        __base_type_spec_flt                                                                                                                         \
        __base_type_spec_cpl                                                                                                                         \
        __base_type_spec_bool_p                                                                                                                      \
        __base_type_spec_char_p                                                                                                                      \
        __base_type_spec_int_p                                                                                                                       \
        __base_type_spec_flt_p                                                                                                                       \
        __base_type_spec_cpl_p                                                                                                                       \
        __base_type_spec_void_p                                                                                                                      \
        default                        : "und")

//================= TYPE GROUP =======================================================================================================================
/*
 * Type group
*/
#define BASE_TYPE_GROUP_VOID      0b01000000U
#define BASE_TYPE_GROUP_COMPLEX   0b00100000U
#define BASE_TYPE_GROUP_FLT       0b00010000U
#define BASE_TYPE_GROUP_UINT      0b00001000U
#define BASE_TYPE_GROUP_SINT      0b00000100U
#define BASE_TYPE_GROUP_CHAR      0b00000010U
#define BASE_TYPE_GROUP_BOOL      0b00000001U
#define BASE_TYPE_GROUP_UNDEFINED 0b00000000U
#define BASE_TYPE_GROUP_BOOL_P    0b10000001U
#define BASE_TYPE_GROUP_CHAR_P    0b10000010U
#define BASE_TYPE_GROUP_SINT_P    0b10000100U
#define BASE_TYPE_GROUP_UINT_P    0b10001000U
#define BASE_TYPE_GROUP_FLT_P     0b10010000U
#define BASE_TYPE_GROUP_COMPLEX_P 0b10100000U
#define BASE_TYPE_GROUP_VOID_P    0b11000000U


#define __base_type_group_bool                                                                                                                       \
    _Bool                              : BASE_TYPE_GROUP_BOOL,

#define __base_type_group_bool_p                                                                                                                     \
    _Bool*                             : BASE_TYPE_GROUP_BOOL_P,

#define __base_type_group_char                                                                                                                       \
    char                               : BASE_TYPE_GROUP_CHAR,

#define __base_type_group_char_p                                                                                                                     \
    char*                              : BASE_TYPE_GROUP_CHAR_P,

#define __base_type_group_int                                                                                                                        \
    signed char                        : BASE_TYPE_GROUP_SINT,                                                                                       \
    unsigned char                      : BASE_TYPE_GROUP_UINT,                                                                                       \
    signed int                         : BASE_TYPE_GROUP_SINT,                                                                                       \
    unsigned int                       : BASE_TYPE_GROUP_UINT,                                                                                       \
    signed short                       : BASE_TYPE_GROUP_SINT,                                                                                       \
    unsigned short                     : BASE_TYPE_GROUP_UINT,                                                                                       \
    signed long                        : BASE_TYPE_GROUP_SINT,                                                                                       \
    unsigned long                      : BASE_TYPE_GROUP_UINT,                                                                                       \
    signed long long                   : BASE_TYPE_GROUP_SINT,                                                                                       \
    unsigned long long                 : BASE_TYPE_GROUP_UINT,

#define __base_type_group_int_p                                                                                                                      \
    signed char*                       : BASE_TYPE_GROUP_SINT_P,                                                                                     \
    unsigned char*                     : BASE_TYPE_GROUP_UINT_P,                                                                                     \
    signed int*                        : BASE_TYPE_GROUP_SINT_P,                                                                                     \
    unsigned int*                      : BASE_TYPE_GROUP_UINT_P,                                                                                     \
    signed short*                      : BASE_TYPE_GROUP_SINT_P,                                                                                     \
    unsigned short*                    : BASE_TYPE_GROUP_UINT_P,                                                                                     \
    signed long*                       : BASE_TYPE_GROUP_SINT_P,                                                                                     \
    unsigned long*                     : BASE_TYPE_GROUP_UINT_P,                                                                                     \
    signed long long*                  : BASE_TYPE_GROUP_SINT_P,                                                                                     \
    unsigned long long*                : BASE_TYPE_GROUP_UINT_P,

#if YAYA_USING_FLOATING
#define __base_type_group_flt                                                                                                                        \
    float                              : BASE_TYPE_GROUP_FLT,                                                                                        \
    double                             : BASE_TYPE_GROUP_FLT,                                                                                        \
    long double                        : BASE_TYPE_GROUP_FLT,

#define __base_type_group_flt_p                                                                                                                      \
    float*                             : BASE_TYPE_GROUP_FLT_P,                                                                                      \
    double*                            : BASE_TYPE_GROUP_FLT_P,                                                                                      \
    long double*                       : BASE_TYPE_GROUP_FLT_P,
#else
#define __base_type_group_flt
#define __base_type_group_flt_p
#endif

#if YAYA_USING_COMPLEX
#define __base_type_group_cpl                                                                                                                        \
    float complex                      : BASE_TYPE_GROUP_COMPLEX,                                                                                    \
    double complex                     : BASE_TYPE_GROUP_COMPLEX,                                                                                    \
    long double complex                : BASE_TYPE_GROUP_COMPLEX,

#define __base_type_group_cpl_p                                                                                                                      \
    float complex*                     : BASE_TYPE_GROUP_COMPLEX_P,                                                                                  \
    double complex*                    : BASE_TYPE_GROUP_COMPLEX_P,                                                                                  \
    long double complex*               : BASE_TYPE_GROUP_COMPLEX_P,
#else
#define __base_type_group_cpl
#define __base_type_group_cpl_p
#endif

#define __base_type_group_void_p                                                                                                                     \
    void*                              : BASE_TYPE_GROUP_VOID_P,

#define base_type_group(x)                                                                                                                           \
    _Generic((x),                                                                                                                                    \
        __base_type_group_bool                                                                                                                       \
        __base_type_group_char                                                                                                                       \
        __base_type_group_int                                                                                                                        \
        __base_type_group_flt                                                                                                                        \
        __base_type_group_cpl                                                                                                                        \
        __base_type_group_bool_p                                                                                                                     \
        __base_type_group_char_p                                                                                                                     \
        __base_type_group_int_p                                                                                                                      \
        __base_type_group_flt_p                                                                                                                      \
        __base_type_group_cpl_p                                                                                                                      \
        __base_type_group_void_p                                                                                                                     \
        default                        : BASE_TYPE_GROUP_UNDEFINED)

//================= TYPE SIGN ========================================================================================================================
/*
 * Type sign
*/
/* Определение типа */
#define BASE_TYPE_SIGN_SIGNUM    (-1) /*если тип имеет знак числа*/
#define BASE_TYPE_SIGN_UNSIGNUM  (+1) /*если тип беззнаковое*/
#define BASE_TYPE_SIGN_UNDEFINED ( 0) /*если у значения не удаётся определить знак*/

#define base_type_sign(x)                                                                                                                            \
    (                                                                                                                                                \
        ((base_type_group(x) == BASE_TYPE_GROUP_SINT) || (base_type_group(x) == BASE_TYPE_GROUP_FLT) ) ? BASE_TYPE_SIGN_SIGNUM   :                   \
        ((base_type_group(x) == BASE_TYPE_GROUP_UINT) || (base_type_group(x) == BASE_TYPE_GROUP_CHAR)) ? BASE_TYPE_SIGN_UNSIGNUM :                   \
        BASE_TYPE_SIGN_UNDEFINED                                                                                                                     \
    )

//================= TYPE UID =========================================================================================================================
/*
 * Type unique identifier
*/
#define __base_type_uid_bool                                                                                                                         \
    _Bool                              : '0',

#define __base_type_uid_bool_p                                                                                                                       \
    _Bool*                             : '1',

#define __base_type_uid_char                                                                                                                         \
    char                               : 'a',

#define __base_type_uid_char_p                                                                                                                       \
    char*                              : 'A',

#define __base_type_uid_int                                                                                                                          \
    signed char                        : 'b',                                                                                                        \
    unsigned char                      : 'c',                                                                                                        \
    signed int                         : 'd',                                                                                                        \
    unsigned int                       : 'e',                                                                                                        \
    signed short                       : 'f',                                                                                                        \
    unsigned short                     : 'g',                                                                                                        \
    signed long                        : 'h',                                                                                                        \
    unsigned long                      : 'i',                                                                                                        \
    signed long long                   : 'j',                                                                                                        \
    unsigned long long                 : 'k',

#define __base_type_uid_int_p                                                                                                                        \
    signed char*                       : 'B',                                                                                                        \
    unsigned char*                     : 'C',                                                                                                        \
    signed int*                        : 'D',                                                                                                        \
    unsigned int*                      : 'E',                                                                                                        \
    signed short*                      : 'F',                                                                                                        \
    unsigned short*                    : 'G',                                                                                                        \
    signed long*                       : 'H',                                                                                                        \
    unsigned long*                     : 'I',                                                                                                        \
    signed long long*                  : 'J',                                                                                                        \
    unsigned long long*                : 'K',

#if YAYA_USING_FLOATING
#define __base_type_uid_flt                                                                                                                          \
    float                              : 'l',                                                                                                        \
    double                             : 'm',                                                                                                        \
    long double                        : 'n',

#define __base_type_uid_flt_p                                                                                                                        \
    float*                             : 'L',                                                                                                        \
    double*                            : 'M',                                                                                                        \
    long double*                       : 'N',
#else
#define __base_type__flt
#define __base_type__flt_p
#endif

#if YAYA_USING_COMPLEX
#define __base_type_uid_cpl                                                                                                                          \
    float complex                      : 'o',                                                                                                        \
    double complex                     : 'p',                                                                                                        \
    long double complex                : 'r',

#define __base_type_uid_cpl_p                                                                                                                        \
    float complex*                     : 'O',                                                                                                        \
    double complex*                    : 'P',                                                                                                        \
    long double complex*               : 'R',
#else
#define __base_type_id_cpl
#define __base_type_id_cpl_p
#endif

#define __base_type_uid_void_p                                                                                                                       \
    void*                              : 'Y',

#define base_type_uid(x)                                                                                                                             \
    _Generic((x),                                                                                                                                    \
        __base_type_uid_bool                                                                                                                         \
        __base_type_uid_char                                                                                                                         \
        __base_type_uid_int                                                                                                                          \
        __base_type_uid_flt                                                                                                                          \
        __base_type_uid_cpl                                                                                                                          \
        __base_type_uid_bool_p                                                                                                                       \
        __base_type_uid_char_p                                                                                                                       \
        __base_type_uid_int_p                                                                                                                        \
        __base_type_uid_flt_p                                                                                                                        \
        __base_type_uid_cpl_p                                                                                                                        \
        __base_type_uid_void_p                                                                                                                       \
        default                        : 'Z')

//================= TYPE PRINT =======================================================================================================================
/*
 * Type print specifier
*/
#define __base_type_print_bool                                                                                                                       \
    _Bool                              : "b",

#define __base_type_print_bool_p                                                                                                                     \
    _Bool*                             : "b",

#define __base_type_print_char                                                                                                                       \
    char                               : "c",

#define __base_type_print_char_p                                                                                                                     \
    char*                              : "s",

#define __base_type_print_int                                                                                                                        \
    int8_t                             : PRIi8,                                                                                                      \
    int16_t                            : PRIi16,                                                                                                     \
    int32_t                            : PRIi32,                                                                                                     \
    int64_t                            : PRIi64,                                                                                                     \
    uint8_t                            : PRIu8,                                                                                                      \
    uint16_t                           : PRIu16,                                                                                                     \
    uint32_t                           : PRIu32,                                                                                                     \
    uint64_t                           : PRIu64,

#define __base_type_print_int_p                                                                                                                      \
    int8_t*                            : PRIi8,                                                                                                      \
    int16_t*                           : PRIi16,                                                                                                     \
    int32_t*                           : PRIi32,                                                                                                     \
    int64_t*                           : PRIi64,                                                                                                     \
    uint8_t*                           : PRIu8,                                                                                                      \
    uint16_t*                          : PRIu16,                                                                                                     \
    uint32_t*                          : PRIu32,                                                                                                     \
    uint64_t*                          : PRIu64,

#if YAYA_USING_FLOATING
#define __base_type_print_flt                                                                                                                        \
    float                              : "f",                                                                                                        \
    double                             : "lf",                                                                                                       \
    long double                        : "Lf",

#define __base_type_print_flt_p                                                                                                                      \
    float*                             : "f",                                                                                                        \
    double*                            : "lf",                                                                                                       \
    long double*                       : "Lf",
#else
#define __base_type_print_flt
#define __base_type_print_flt_p
#endif

#if YAYA_USING_COMPLEX
#define __base_type_print_cpl                                                                                                                        \
    float complex                      : "f",                                                                                                        \
    double complex                     : "lf",                                                                                                       \
    long double complex                : "Lf",

#define __base_type_print_cpl_p                                                                                                                      \
    float complex*                     : "f",                                                                                                        \
    double complex*                    : "lf",                                                                                                       \
    long double complex*               : "Lf",
#else
#define __base_type_print_cpl
#define __base_type_print_cpl_p
#endif

#define __base_type_print_void_p                                                                                                                     \
    void*                              : "p",

#define base_type_print(x)                                                                                                                           \
    _Generic((x),                                                                                                                                    \
        __base_type_print_bool                                                                                                                       \
        __base_type_print_char                                                                                                                       \
        __base_type_print_int                                                                                                                        \
        __base_type_print_flt                                                                                                                        \
        __base_type_print_cpl                                                                                                                        \
        __base_type_print_bool_p                                                                                                                     \
        __base_type_print_char_p                                                                                                                     \
        __base_type_print_int_p                                                                                                                      \
        __base_type_print_flt_p                                                                                                                      \
        __base_type_print_cpl_p                                                                                                                      \
        __base_type_print_void_p                                                                                                                     \
        default                        : "%")

//================= NULLPTR ==========================================================================================================================
/*
 * Nullptr
*/
#define nullptr                        ((void*)(0))
typedef typeof(nullptr)                nullptr_t;

//================= ALIASES ==========================================================================================================================
/*
 * Aliases
*/
typedef void                           void_t;

typedef char                           char_t;

//TODO i (int) -> s(signed)

typedef intmax_t                       imax_t;
typedef uintmax_t                      umax_t;
typedef intptr_t                       iptr_t;
typedef uintptr_t                      uptr_t;
typedef long double                    fmax_t;
typedef long double complex            cmax_t;

//TODO is , us -> s, u

typedef int8_t                         is8_t;
typedef int16_t                        is16_t;
typedef int32_t                        is32_t;
typedef int64_t                        is64_t;

typedef uint8_t                        us8_t;
typedef uint16_t                       us16_t;
typedef uint32_t                       us32_t;
typedef uint64_t                       us64_t;

typedef int_least8_t                   il8_t;
typedef int_least16_t                  il16_t;
typedef int_least32_t                  il32_t;
typedef int_least64_t                  il64_t;

typedef uint_least8_t                  ul8_t;
typedef uint_least16_t                 ul16_t;
typedef uint_least32_t                 ul32_t;
typedef uint_least64_t                 ul64_t;

typedef int_fast8_t                    if8_t;
typedef int_fast16_t                   if16_t;
typedef int_fast32_t                   if32_t;
typedef int_fast64_t                   if64_t;

typedef uint_fast8_t                   uf8_t;
typedef uint_fast16_t                  uf16_t;
typedef uint_fast32_t                  uf32_t;
typedef uint_fast64_t                  uf64_t;

typedef float                          f32_t;
typedef double                         f64_t;
typedef long double                    f128_t;

typedef float complex                  c32_t;
typedef double complex                 c64_t;
typedef long double complex            c128_t;

//================= CONST NUMBER =====================================================================================================================
/*
 * Const number
*/
#define char_c(x)                      ((char_t)(x))

#define i8_c(x)                        ((is8_t) (x))
#define i16_c(x)                       ((is16_t)(x))
#define i32_c(x)                       ((is32_t)(x))
#define i64_c(x)                       ((is64_t)(x))
#define imax_c(x)                      ((imax_t)(x))

#define u8_c(x)                        ((us8_t) (x))
#define u16_c(x)                       ((us16_t)(x))
#define u32_c(x)                       ((us32_t)(x))
#define u64_c(x)                       ((us64_t)(x))
#define u64_c(x)                       ((us64_t)(x))
#define umax_c(x)                      ((umax_t)(x))

#define f32_c(x)                       ((f32_t)(x))
#define f64_c(x)                       ((f64_t)(x))
#define f128_c(x)                      ((f128_t)(x))
#define fmax_c(x)                      ((fmax_t)(x))

#define c32_c(x)                       ((c32_t)(x))
#define c64_c(x)                       ((c64_t)(x))
#define cmax_c(x)                      ((cmax_t)(x))

#define null_c(T)                      (((T*)0))

//================= TYPE INFO ========================================================================================================================
/*
 * Type info
*/
#define base_type_min(x)                                                                                                                             \
    _Generic((x),                                                                                                                                    \
        char:                          char_c(CHAR_MIN),                                                                                             \
        is8_t:                           i8_c(INT8_MIN),                                                                                             \
        is16_t:                         i16_c(INT16_MIN),                                                                                            \
        is32_t:                         i32_c(INT32_MIN),                                                                                            \
        is64_t:                         i64_c(INT64_MIN),                                                                                            \
        us8_t:                           u8_c(0),                                                                                                    \
        us16_t:                         u16_c(0),                                                                                                    \
        us32_t:                         u32_c(0),                                                                                                    \
        us64_t:                         u64_c(0),                                                                                                    \
        f32_t:                          f32_c(FLT32_MIN__),                                                                                          \
        f64_t:                          f64_c(FLT64_MIN__),                                                                                          \
        f128_t:                        f128_c(FLT128_MIN__))

#define base_type_max(x)                                                                                                                             \
    _Generic(x,                                                                                                                                      \
        char:                          char_c(CHAR_MAX),                                                                                             \
        is8_t:                           i8_c(INT8_MAX),                                                                                             \
        is16_t:                         i16_c(INT16_MAX),                                                                                            \
        is32_t:                         i32_c(INT32_MAX),                                                                                            \
        is64_t:                         i64_c(INT64_MAX),                                                                                            \
        us8_t:                           u8_c(UINT8_MAX),                                                                                            \
        us16_t:                         u16_c(UINT16_MAX),                                                                                           \
        us32_t:                         u32_c(UINT32_MAX),                                                                                           \
        us64_t:                         u64_c(UINT64_MAX),                                                                                           \
        f32_t:                          f32_c(FLT32_MAX__),                                                                                          \
        f64_t:                          f64_c(FLT64_MAX__),                                                                                          \
        f128_t:                        f128_c(FLT128_MAX__))

#define base_type_eps(x)                                                                                                                             \
     _Generic((x),                                                                                                                                   \
        char:                         char_c(1),                                                                                                     \
        is8_t:                          i8_c(1),                                                                                                     \
        is16_t:                        i16_c(1),                                                                                                     \
        is32_t:                        i32_c(1),                                                                                                     \
        is64_t:                        i64_c(1),                                                                                                     \
        us8_t:                          u8_c(1),                                                                                                     \
        us16_t:                        u16_c(1),                                                                                                     \
        us32_t:                        u32_c(1),                                                                                                     \
        us64_t:                        u64_c(1),                                                                                                     \
        f32_t:                         f32_c(FLT32_EPSILON__),                                                                                       \
        f64_t:                         f64_c(FLT64_EPSILON__),                                                                                       \
        f128_t:                       f128_c(FLT128_EPSILON__))

//================= TYPE CONVERSION ==================================================================================================================
/*
 * Type conversion
*/
#define base_type_cast_to_uint(x)                                                                                                                    \
    _Generic((x),                                                                                                                                    \
        char:                          char_c(x),                                                                                                    \
        is8_t:                           u8_c(x),                                                                                                    \
        is16_t:                         u16_c(x),                                                                                                    \
        is32_t:                         u32_c(x),                                                                                                    \
        is64_t:                         u64_c(x),                                                                                                    \
        us8_t:                           u8_c(x),                                                                                                    \
        us16_t:                         u16_c(x),                                                                                                    \
        us32_t:                         u32_c(x),                                                                                                    \
        us64_t:                         u64_c(x),                                                                                                    \
        f32_t:                          f32_c(x),                                                                                                    \
        f64_t:                          f64_c(x),                                                                                                    \
        f128_t:                        f128_c(x)                                                                                                     \
    )

#define base_type_cast_to_sint(x)                                                                                                                    \
    _Generic((x),                                                                                                                                    \
        char:                          char_c(x),                                                                                                    \
        is8_t:                           i8_c(x),                                                                                                    \
        is16_t:                         i16_c(x),                                                                                                    \
        is32_t:                         i32_c(x),                                                                                                    \
        is64_t:                         i64_c(x),                                                                                                    \
        us8_t:                           i8_c(x),                                                                                                    \
        us16_t:                         i16_c(x),                                                                                                    \
        us32_t:                         i32_c(x),                                                                                                    \
        us64_t:                         i64_c(x),                                                                                                    \
        f32_t:                          f32_c(x),                                                                                                    \
        f64_t:                          f64_c(x),                                                                                                    \
        f128_t:                        f128_c(x)                                                                                                     \
    )

//================= UNDEF ============================================================================================================================
/*
 * Hide std definition
*/
//#define intmax_t
//#define uintmax_t
//#define intptr_t
//#define uintptr_t

//#define int8_t
//#define int16_t
//#define int32_t
//#define int64_t
//#define uint8_t
//#define uint16_t
//#define uint32_t
//#define uint64_t

//#define int_least8_t
//#define int_least16_t
//#define int_least32_t
//#define int_least64_t
//#define uint_least8_t
//#define uint_least16_t
//#define uint_least32_t
//#define uint_least64_t

//#define int_fast8_t
//#define int_fast16_t
//#define int_fast32_t
//#define int_fast64_t
//#define uint_fast8_t
//#define uint_fast16_t
//#define uint_fast32_t
//#define uint_fast64_t

//====================================================================================================================================================

END_C_DECLARATION
// clang-format on
#endif /*YAYA_TYPE_H*/
