//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2022 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_TYPE_H
#define YAYA_TYPE_H

#include "stdint.h"
#include "inttypes.h"

#define typename(x) _Generic((x),                         \
    char:                       "char",                   \
    signed char:                "signed char",            \
    unsigned char:              "unsigned char",          \
    signed int:                 "signed int",             \
    unsigned int:               "unsigned int",           \
    signed short:               "signed short",           \
    unsigned short:             "unsigned short",         \
    signed long:                "signed long",            \
    unsigned long:              "unsigned long",          \
    signed long long:           "signed long long",       \
    unsigned long long:         "unsigned long long",     \
    \
    float:                      "float",                  \
    \
    double:                     "double",                 \
    long double:                "long double",            \
    \
    char*:                      "point to char",                   \
    signed char*:               "point to signed char",            \
    unsigned char*:             "point to unsigned char",          \
    signed int*:                "point to signed int",             \
    unsigned int*:              "point to unsigned int",           \
    signed short*:              "point to signed short",           \
    unsigned short*:            "point to unsigned short",         \
    signed long*:               "point to signed long",            \
    unsigned long*:             "point to unsigned long",          \
    signed long long*:          "point to signed long long",       \
    unsigned long long*:        "point to unsigned long long",     \
    \
    float*:                     "point to float",                  \
    \
    double*:                    "point to double",                 \
    long double*:               "point to long double",            \
    \
    default:                    "other")

#define TYPE_NAN   0
#define TYPE_CHR   1
#define TYPE_INT   2
#define TYPE_FLT   3
#define TYPE_CHR_P 4
#define TYPE_INT_P 5
#define TYPE_FLT_P 6

#define typeid(x) _Generic((x),      \
    char:                       TYPE_CHR,   \
    signed char:                TYPE_INT,   \
    unsigned char:              TYPE_INT,   \
    signed int:                 TYPE_INT,   \
    unsigned int:               TYPE_INT,   \
    signed short:               TYPE_INT,   \
    unsigned short:             TYPE_INT,   \
    signed long:                TYPE_INT,   \
    unsigned long:              TYPE_INT,   \
    signed long long:           TYPE_INT,   \
    unsigned long long:         TYPE_INT,   \
    \
    float:                      TYPE_FLT,   \
    double:                     TYPE_FLT,   \
    long double:                TYPE_FLT,   \
    \
    char*:                      TYPE_CHR_P,   \
    signed char*:               TYPE_INT_P,   \
    unsigned char*:             TYPE_INT_P,   \
    signed int*:                TYPE_INT_P,   \
    unsigned int*:              TYPE_INT_P,   \
    signed short*:              TYPE_INT_P,   \
    unsigned short*:            TYPE_INT_P,   \
    signed long*:               TYPE_INT_P,   \
    unsigned long*:             TYPE_INT_P,   \
    signed long long*:          TYPE_INT_P,   \
    unsigned long long*:        TYPE_INT_P,   \
    \
    float*:                     TYPE_FLT_P,   \
    double*:                    TYPE_FLT_P,   \
    long double*:               TYPE_FLT_P,   \
    \
    default:                    TYPE_NAN)

#define typespec(x) _Generic((x),                         \
    char:                       "chr",                    \
    int8_t:                     "i08",                    \
    int16_t:                    "i16",                    \
    int32_t:                    "i32",                    \
    int64_t:                    "i64",                    \
    uint8_t:                    "u08",                    \
    uint16_t:                   "u16",                    \
    uint32_t:                   "u32",                    \
    uint64_t:                   "u64",                    \
    float:                      "flt",                    \
    double:                     "dbl",                    \
    \
    char*:                      "chr",                    \
    int8_t*:                    "i08",                    \
    int16_t*:                   "i16",                    \
    int32_t*:                   "i32",                    \
    int64_t*:                   "i64",                    \
    uint8_t*:                   "u08",                    \
    uint16_t*:                  "u16",                    \
    uint32_t*:                  "u32",                    \
    uint64_t*:                  "u64",                    \
    float*:                     "flt",                    \
    double*:                    "dbl",                    \
    \
    default:                    "nan")

#define typeprint(x) _Generic((x),                        \
    char:                       "%"PRIi8,                 \
    int8_t:                     "%"PRIi8,                 \
    int16_t:                    "%"PRIi16,                \
    int32_t:                    "%"PRIi32,                \
    int64_t:                    "%"PRIi64,                \
    uint8_t:                    "%"PRIu8,                 \
    uint16_t:                   "%"PRIu16,                \
    uint32_t:                   "%"PRIu32,                \
    uint64_t:                   "%"PRIu64,                \
    \
    float:                      "%""f",                   \
    double:                     "%""f",                   \
    \
    char*:                      "chr",                    \
    int8_t*:                    "i08",                    \
    int16_t*:                   "i16",                    \
    int32_t*:                   "i32",                    \
    int64_t*:                   "i64",                    \
    uint8_t*:                   "u08",                    \
    uint16_t*:                  "u16",                    \
    uint32_t*:                  "u32",                    \
    uint64_t*:                  "u64",                    \
    float*:                     "flt",                    \
    double*:                    "dbl",                    \
    \
    default:                    "nan")

#endif /*YAYA_TYPE_H*/
