//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_TYPE_H
#define YAYA_TYPE_H

#include "yaya_cdeclaration.h"
BEG_C_DECLARATION

#include "inttypes.h"
#include "stdint.h"

/* НАСТРОЙКИ */

#ifndef YAYA_USING_FLOATING
#define YAYA_USING_FLOATING 1
#include "float.h"

#ifndef YAYA_USING_COMPLEX
#define YAYA_USING_COMPLEX 1
#include "complex.h"
#endif /*YAYA_USING_COMPLEX*/
#endif /*YAYA_USING_FLOATING*/

/* ТЕКСТОВОЕ ИМЯ */

#if YAYA_USING_FLOATING
#define __std_type_name_flt                               \
    float:                "float",                        \
    double:               "double",                       \
    long double:          "long double"

#define __std_type_name_flt_p                             \
    float*:               "point to float",               \
    double*:              "point to double",              \
    long double*:         "point to long double"
#else
#define __std_type_name_flt
#define __std_type_name_flt_p
#endif

#if YAYA_USING_COMPLEX
#define __std_type_name_cpl                               \
    float complex:        "float complex",                \
    double complex:       "double complex",               \
    long double complex:  "long double complex"

#define __std_type_name_cpl_p                             \
    float complex*:       "point to float complex",       \
    double complex*:      "point to double complex",      \
    long double complex*: "point to long double complex"
#else
#define __std_type_name_cpl
#define __std_type_name_cpl_p
#endif

#define std_type_name(x) _Generic((x),                    \
    char:                 "char",                         \
    signed char:          "signed char",                  \
    unsigned char:        "unsigned char",                \
    signed int:           "signed int",                   \
    unsigned int:         "unsigned int",                 \
    signed short:         "signed short",                 \
    unsigned short:       "unsigned short",               \
    signed long:          "signed long",                  \
    unsigned long:        "unsigned long",                \
    signed long long:     "signed long long",             \
    unsigned long long:   "unsigned long long",           \
    __std_type_name_flt,                                  \
    __std_type_name_cpl,                                  \
    \
    char*:                "point to char",                \
    signed char*:         "point to signed char",         \
    unsigned char*:       "point to unsigned char",       \
    signed int*:          "point to signed int",          \
    unsigned int*:        "point to unsigned int",        \
    signed short*:        "point to signed short",        \
    unsigned short*:      "point to unsigned short",      \
    signed long*:         "point to signed long",         \
    unsigned long*:       "point to unsigned long",       \
    signed long long*:    "point to signed long long",    \
    unsigned long long*:  "point to unsigned long long",  \
    __std_type_name_flt_p,                                \
    __std_type_name_cpl_p,                                \
    void*:                "point to void",                \
    default:              "other")


/* ТИП ГРУППЫ */

#define STD_TYPE_GROUP_VOID      0b00100000U
#define STD_TYPE_GROUP_COMPLEX   0b00010000U
#define STD_TYPE_GROUP_FLT       0b00001000U
#define STD_TYPE_GROUP_UINT      0b00000100U
#define STD_TYPE_GROUP_SINT      0b00000010U
#define STD_TYPE_GROUP_CHAR      0b00000001U
#define STD_TYPE_GROUP_NSTDT     0b00000000U
#define STD_TYPE_GROUP_CHAR_P    0b01000001U
#define STD_TYPE_GROUP_SINT_P    0b01000010U
#define STD_TYPE_GROUP_UINT_P    0b01000100U
#define STD_TYPE_GROUP_FLT_P     0b01001000U
#define STD_TYPE_GROUP_COMPLEX_P 0b01010000U
#define STD_TYPE_GROUP_VOID_P    0b01100000U

#if YAYA_USING_FLOATING
#define __std_type_group_flt                        \
    float:                STD_TYPE_GROUP_FLT,       \
    double:               STD_TYPE_GROUP_FLT,       \
    long double:          STD_TYPE_GROUP_FLT,

#define __std_type_group_flt_p                      \
    float*:               STD_TYPE_GROUP_FLT_P,     \
    double*:              STD_TYPE_GROUP_FLT_P,     \
    long double*:         STD_TYPE_GROUP_FLT_P,
#else
#define __std_type_group_flt
#define __std_type_group_flt_p
#endif

#if YAYA_USING_COMPLEX
#define __std_type_group_cpl                        \
    float complex:        STD_TYPE_GROUP_COMPLEX,   \
    double complex:       STD_TYPE_GROUP_COMPLEX,   \
    long double complex:  STD_TYPE_GROUP_COMPLEX,

#define __std_type_group_cpl_p                      \
    float complex*:       STD_TYPE_GROUP_COMPLEX_P, \
    double complex*:      STD_TYPE_GROUP_COMPLEX_P, \
    long double complex*: STD_TYPE_GROUP_COMPLEX_P,
#else
#define __std_type_group_cpl
#define __std_type_group_cpl_p
#endif

#define std_type_group(x)  _Generic((x),             \
    char:                  STD_TYPE_GROUP_CHAR,      \
    signed char:           STD_TYPE_GROUP_SINT,      \
    unsigned char:         STD_TYPE_GROUP_UINT,      \
    signed int:            STD_TYPE_GROUP_SINT,      \
    unsigned int:          STD_TYPE_GROUP_UINT,      \
    signed short:          STD_TYPE_GROUP_SINT,      \
    unsigned short:        STD_TYPE_GROUP_UINT,      \
    signed long:           STD_TYPE_GROUP_SINT,      \
    unsigned long:         STD_TYPE_GROUP_UINT,      \
    signed long long:      STD_TYPE_GROUP_SINT,      \
    unsigned long long:    STD_TYPE_GROUP_UINT,      \
    __std_type_group_flt                             \
    __std_type_group_cpl                             \
    \
    char*:                 STD_TYPE_GROUP_CHAR_P,    \
    signed char*:          STD_TYPE_GROUP_SINT_P,    \
    unsigned char*:        STD_TYPE_GROUP_UINT_P,    \
    signed int*:           STD_TYPE_GROUP_SINT_P,    \
    unsigned int*:         STD_TYPE_GROUP_UINT_P,    \
    signed short*:         STD_TYPE_GROUP_SINT_P,    \
    unsigned short*:       STD_TYPE_GROUP_UINT_P,    \
    signed long*:          STD_TYPE_GROUP_SINT_P,    \
    unsigned long*:        STD_TYPE_GROUP_UINT_P,    \
    signed long long*:     STD_TYPE_GROUP_SINT_P,    \
    unsigned long long*:   STD_TYPE_GROUP_UINT_P,    \
    __std_type_group_flt_p                           \
    __std_type_group_cpl_p                           \
    \
    void*:                STD_TYPE_GROUP_VOID_P,     \
    default:              STD_TYPE_GROUP_NSTDT)


/* ТИП ЗНАКА */

/*определение типа*/
#define STD_TYPE_SIGNUM       (-1) /*если число имеет знак*/
#define STD_TYPE_UNSIGNUM     (+1) /*если число беззнаковое*/
#define STD_TYPE_UNDEFSIGNUM  ( 0) /*если у значения не удаётся определить знак*/

#define std_type_sigum(x) (                                                                        \
    ((std_type_group(x) == STD_TYPE_GROUP_SINT) || (std_type_group(x) == STD_TYPE_GROUP_FLT)) ?    \
    STD_TYPE_SIGNUM :                                                                              \
    (((std_type_group(x) == STD_TYPE_GROUP_UINT) || (std_type_group(x) == STD_TYPE_GROUP_CHAR)) ?  \
    STD_TYPE_UNSIGNUM :                                                                            \
    STD_TYPE_UNDEFSIGNUM))


/* УНИКАЛЬНЫЙ ИНДЕКС */

#if YAYA_USING_FLOATING
#define __std_type_index_flt            \
    float:                  'l',        \
    double:                 'm',        \
    long double:            'n',

#define __std_type_index_flt_p          \
    float*:                 'L',        \
    double*:                'M',        \
    long double*:           'N',
#else
#define __std_type__flt
#define __std_type__flt_p
#endif

#if YAYA_USING_COMPLEX
#define __std_type_index_cpl            \
    float complex:          'o',        \
    double complex:         'p',        \
    long double complex:    'r',

#define __std_type_index_cpl_p          \
    float complex*:         'O',        \
    double complex*:        'P',        \
    long double complex*:   'R',
#else
#define __std_type_index_cpl
#define __std_type_index_cpl_p
#endif

#define std_type_index(x) _Generic((x), \
    char:                   'a',        \
    signed char:            'b',        \
    unsigned char:          'c',        \
    signed int:             'd',        \
    unsigned int:           'e',        \
    signed short:           'f',        \
    unsigned short:         'g',        \
    signed long:            'h',        \
    unsigned long:          'i',        \
    signed long long:       'j',        \
    unsigned long long:     'k',        \
    __std_type_index_flt                \
    __std_type_index_cpl                \
    \
    char*:                  'A',        \
    signed char*:           'B',        \
    unsigned char*:         'C',        \
    signed int*:            'D',        \
    unsigned int*:          'E',        \
    signed short*:          'F',        \
    unsigned short*:        'G',        \
    signed long*:           'H',        \
    unsigned long*:         'I',        \
    signed long long*:      'J',        \
    unsigned long long*:    'K',        \
    __std_type_index_flt_p              \
    __std_type_index_cpl_p              \
    \
    void*:                  'Y',        \
    default:                'Z')


/* СОКРАЩЕННОЕ ТЕКСТОВОЕ ИМЯ */

#if YAYA_USING_FLOATING
#define __std_type_spec_flt             \
    float:                "flt",        \
    double:               "dbl",        \
    long double:          "ldb",
#define __std_type_spec_flt_p           \
    float*:               "flt",        \
    double*:              "dbl",        \
    long double*:         "ldb",
#else
#define __std_type_spec_flt
#define __std_type_spec_flt_p
#endif

#if YAYA_USING_COMPLEX
#define __std_type_spec_cpl             \
    float complex:        "fcp",        \
    double complex:       "cpl",        \
    long double complex:  "lcp",

#define __std_type_spec_cpl_p           \
    float complex*:       "fcp",        \
    double complex*:      "cpl",        \
    long double complex*: "lcp",
#else
#define __std_type__cpl
#define __std_type__cpl_p
#endif

#define std_type_spec(x) _Generic((x),  \
    char:                 "chr",        \
    int8_t:               "i08",        \
    int16_t:              "i16",        \
    int32_t:              "i32",        \
    int64_t:              "i64",        \
    uint8_t:              "u08",        \
    uint16_t:             "u16",        \
    uint32_t:             "u32",        \
    uint64_t:             "u64",        \
    __std_type_spec_flt                 \
    __std_type_spec_cpl                 \
    \
    char*:                "str",        \
    int8_t*:              "i08",        \
    int16_t*:             "i16",        \
    int32_t*:             "i32",        \
    int64_t*:             "i64",        \
    uint8_t*:             "u08",        \
    uint16_t*:            "u16",        \
    uint32_t*:            "u32",        \
    uint64_t*:            "u64",        \
    __std_type_spec_flt_p               \
    __std_type_spec_cpl_p               \
    \
    void*:                "vpt",        \
    default:              "nan")


/* ТИП ВЫВОДА */

#if YAYA_USING_FLOATING
#define __std_type_print_flt              \
    float:                  "f",          \
    double:                 "lf",         \
    long double:            "Lf",

#define __std_type_print_flt_p            \
    float*:                 "f",          \
    double*:                "lf",         \
    long double*:           "Lf",
#else
#define __std_type_print_flt
#define __std_type_print_flt_p
#endif

#if YAYA_USING_COMPLEX
#define __std_type_print_cpl              \
    float complex:          "f",          \
    double complex:         "lf",         \
    long double complex:    "Lf",

#define __std_type_print_cpl_p            \
    float complex*:         "f",          \
    double complex*:        "lf",         \
    long double complex*:   "Lf",
#else
#define __std_type_print_cpl
#define __std_type_print_cpl_p
#endif

#define std_type_print(x) _Generic((x),   \
    char:                   "c",          \
    int8_t:                 PRIi8,        \
    int16_t:                PRIi16,       \
    int32_t:                PRIi32,       \
    int64_t:                PRIi64,       \
    uint8_t:                PRIu8,        \
    uint16_t:               PRIu16,       \
    uint32_t:               PRIu32,       \
    uint64_t:               PRIu64,       \
    __std_type_print_flt                  \
    __std_type_print_cpl                  \
    \
    char*:                  "s",          \
    int8_t*:                PRIi8,        \
    int16_t*:               PRIi16,       \
    int32_t*:               PRIi32,       \
    int64_t*:               PRIi64,       \
    uint8_t*:               PRIu8,        \
    uint16_t*:              PRIu16,       \
    uint32_t*:              PRIu32,       \
    uint64_t*:              PRIu64,       \
    __std_type_print_flt_p                \
    __std_type_print_cpl_p                \
    \
    void*:                "p",            \
    default:              "nan")

END_C_DECLARATION
#endif /*YAYA_TYPE_H*/



