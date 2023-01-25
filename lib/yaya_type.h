//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_TYPE_H
#define YAYA_TYPE_H

#include "stdint.h"
#include "inttypes.h"

#define type_name(x) _Generic((x),                       \
    char:                "char",                         \
    signed char:         "signed char",                  \
    unsigned char:       "unsigned char",                \
    signed int:          "signed int",                   \
    unsigned int:        "unsigned int",                 \
    signed short:        "signed short",                 \
    unsigned short:      "unsigned short",               \
    signed long:         "signed long",                  \
    unsigned long:       "unsigned long",                \
    signed long long:    "signed long long",             \
    unsigned long long:  "unsigned long long",           \
    \
    float:               "float",                        \
    double:              "double",                       \
    long double:         "long double",                  \
    \
    char*:               "point to char",                \
    signed char*:        "point to signed char",         \
    unsigned char*:      "point to unsigned char",       \
    signed int*:         "point to signed int",          \
    unsigned int*:       "point to unsigned int",        \
    signed short*:       "point to signed short",        \
    unsigned short*:     "point to unsigned short",      \
    signed long*:        "point to signed long",         \
    unsigned long*:      "point to unsigned long",       \
    signed long long*:   "point to signed long long",    \
    unsigned long long*: "point to unsigned long long",  \
    \
    float*:              "point to float",               \
    double*:             "point to double",              \
    long double*:        "point to long double",         \
    \
    void*:               "point to void",                \
    default:             "other")


#define TYPE_GROUP_VOID   +4
#define TYPE_GROUP_FLT    +3
#define TYPE_GROUP_INT    +2
#define TYPE_GROUP_CHR    +1
#define TYPE_GROUP_NSTDT   0
#define TYPE_GROUP_CHR_P  -1
#define TYPE_GROUP_INT_P  -2
#define TYPE_GROUP_FLT_P  -3
#define TYPE_GROUP_VOID_P -4

#define type_group(x) _Generic((x),          \
    char:                TYPE_GROUP_CHR,     \
    signed char:         TYPE_GROUP_INT,     \
    unsigned char:       TYPE_GROUP_INT,     \
    signed int:          TYPE_GROUP_INT,     \
    unsigned int:        TYPE_GROUP_INT,     \
    signed short:        TYPE_GROUP_INT,     \
    unsigned short:      TYPE_GROUP_INT,     \
    signed long:         TYPE_GROUP_INT,     \
    unsigned long:       TYPE_GROUP_INT,     \
    signed long long:    TYPE_GROUP_INT,     \
    unsigned long long:  TYPE_GROUP_INT,     \
    \
    float:               TYPE_GROUP_FLT,     \
    double:              TYPE_GROUP_FLT,     \
    long double:         TYPE_GROUP_FLT,     \
    \
    char*:               TYPE_GROUP_CHR_P,   \
    signed char*:        TYPE_GROUP_INT_P,   \
    unsigned char*:      TYPE_GROUP_INT_P,   \
    signed int*:         TYPE_GROUP_INT_P,   \
    unsigned int*:       TYPE_GROUP_INT_P,   \
    signed short*:       TYPE_GROUP_INT_P,   \
    unsigned short*:     TYPE_GROUP_INT_P,   \
    signed long*:        TYPE_GROUP_INT_P,   \
    unsigned long*:      TYPE_GROUP_INT_P,   \
    signed long long*:   TYPE_GROUP_INT_P,   \
    unsigned long long*: TYPE_GROUP_INT_P,   \
    \
    float*:              TYPE_GROUP_FLT_P,   \
    double*:             TYPE_GROUP_FLT_P,   \
    long double*:        TYPE_GROUP_FLT_P,   \
    \
    void*:               TYPE_GROUP_VOID_P,  \
    default:             TYPE_GROUP_NSTDT)


#define type_index(x) _Generic((x), \
    char:                   'a',    \
    signed char:            'b',    \
    unsigned char:          'c',    \
    signed int:             'd',    \
    unsigned int:           'e',    \
    signed short:           'f',    \
    unsigned short:         'g',    \
    signed long:            'h',    \
    unsigned long:          'i',    \
    signed long long:       'j',    \
    unsigned long long:     'k',    \
    \
    float:                  'l',    \
    double:                 'm',    \
    long double:            'n',    \
    \
    char*:                  'A',    \
    signed char*:           'B',    \
    unsigned char*:         'C',    \
    signed int*:            'D',    \
    unsigned int*:          'E',    \
    signed short*:          'F',    \
    unsigned short*:        'G',    \
    signed long*:           'H',    \
    unsigned long*:         'I',    \
    signed long long*:      'J',    \
    unsigned long long*:    'K',    \
    \
    float*:                 'L',    \
    double*:                'M',    \
    long double*:           'N',    \
    \
    void*:                  'Y',    \
    default:                'Z')


#define type_spec(x) _Generic((x), \
    char:         "chr",           \
    int8_t:       "i08",           \
    int16_t:      "i16",           \
    int32_t:      "i32",           \
    int64_t:      "i64",           \
    uint8_t:      "u08",           \
    uint16_t:     "u16",           \
    uint32_t:     "u32",           \
    uint64_t:     "u64",           \
    float:        "flt",           \
    double:       "dbl",           \
    long double:  "ldb",           \
    \
    char*:        "chr",           \
    int8_t*:      "i08",           \
    int16_t*:     "i16",           \
    int32_t*:     "i32",           \
    int64_t*:     "i64",           \
    uint8_t*:     "u08",           \
    uint16_t*:    "u16",           \
    uint32_t*:    "u32",           \
    uint64_t*:    "u64",           \
    float*:       "flt",           \
    double*:      "dbl",           \
    long double*: "ldb",           \
    \
    void*:        "void",          \
    default:      "nan")


#define type_print(x) _Generic((x), \
    char:         "c",              \
    int8_t:       PRIi8,            \
    int16_t:      PRIi16,           \
    int32_t:      PRIi32,           \
    int64_t:      PRIi64,           \
    uint8_t:      PRIu8,            \
    uint16_t:     PRIu16,           \
    uint32_t:     PRIu32,           \
    uint64_t:     PRIu64,           \
    float:        "f",              \
    double:       "lf",             \
    long double:  "llf",            \
    \
    char*:        "s",              \
    int8_t*:      PRIi8,            \
    int16_t*:     PRIi16,           \
    int32_t*:     PRIi32,           \
    int64_t*:     PRIi64,           \
    uint8_t*:     PRIu8,            \
    uint16_t*:    PRIu16,           \
    uint32_t*:    PRIu32,           \
    uint64_t*:    PRIu64,           \
    float*:       "f",              \
    double*:      "lf",             \
    long double*: "llf",            \
    \
    void*:        "p",              \
    default:      "nan")

#endif /*YAYA_TYPE_H*/
