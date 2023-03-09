//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_NUMBER_H
#define YAYA_NUMBER_H

#include "yaya_cdeclaration.h"
BEG_C_DECLARATION

#include "stdint.h"
#include "limits.h"

#ifndef YAYA_USING_FLOATING
#define YAYA_USING_FLOATING 1
#include "float.h"
#ifndef YAYA_USING_COMPLEX
#define YAYA_USING_COMPLEX 1
#include "complex.h"
#endif /*YAYA_USING_COMPLEX*/
#endif /*YAYA_USING_FLOATING*/



/*ALIASES*/
/*max types*/
#define imax_t       intmax_t
#define umax_t       uintmax_t
#define iptr_t       intptr_t
#define uptr_t       uintptr_t
#define fmax_t       long double
#define cmax_t       long double

/*strict types*/
#define is8_t        int8_t
#define is16_t       int16_t
#define is32_t       int32_t
#define is64_t       int64_t

#define us8_t        uint8_t
#define us16_t       uint16_t
#define us32_t       uint32_t
#define us64_t       uint64_t

/*least types*/
#define il8_t        int_least8_t
#define il16_t       int_least16_t
#define il32_t       int_least32_t
#define il64_t       int_least64_t

#define ul8_t        uint_least8_t
#define ul16_t       uint_least16_t
#define ul32_t       uint_least32_t
#define ul64_t       uint_least64_t

/*fast types*/
#define if8_t        int_fast8_t
#define if16_t       int_fast16_t
#define if32_t       int_fast32_t
#define if64_t       int_fast64_t

#define uf8_t        uint_fast8_t
#define uf16_t       uint_fast16_t
#define uf32_t       uint_fast32_t
#define uf64_t       uint_fast64_t

/*float point types*/
#define f32_t        float
#define f64_t        double
#define f128_t       long double

/*complex types*/
#define c32_t        float complex
#define c64_t        double complex
#define c128_t       long double complex

/*CONST NUMBER*/
#define i8_c(x)     ((is8_t) (INT8_C(x)))
#define i16_c(x)    ((is16_t)(INT16_C(x)))
#define i32_c(x)    ((is32_t)(INT32_C(x)))
#define i64_c(x)    ((is64_t)(INT64_C(x)))
#define imax_c(x)   ((imax_t)(INTMAX_C(x)))

#define u8_c(x)     ((us8_t) (UINT8_C(x)))
#define u16_c(x)    ((us16_t)(UINT16_C(x)))
#define u32_c(x)    ((us32_t)(UINT32_C(x)))
#define u64_c(x)    ((us64_t)(UINT64_C(x)))
#define u64_c(x)    ((us64_t)(UINT64_C(x)))
#define umax_c(x)   ((umax_t)(UINTMAX_C(x)))

#define f32_c(x)    ((f32_t)(x))
#define f64_c(x)    ((f64_t)(x))
#define fmax_c(x)   ((fmax_t)(x))

#define c32_c(x)    ((c32_t)(x))
#define c64_c(x)    ((c64_t)(x))
#define cmax_c(x)   ((cmax_t)(x))

#define null_c(T)    (((T*)0))

typedef union allt{
    void*     voidp;
    char      chart;
    imax_t    imaxt;
    umax_t    umaxt;
    iptr_t    iptrt;
    uptr_t    uptrt;
    is8_t     is08t;
    is16_t    is16t;
    is32_t    is32t;
    is64_t    is64t;
    us8_t     us08t;
    us16_t    us16t;
    us32_t    us32t;
    us64_t    us64t;
    il8_t     il08t;
    il16_t    il16t;
    il32_t    il32t;
    il64_t    il64t;
    ul8_t     ul08t;
    ul16_t    ul16t;
    ul32_t    ul32t;
    ul64_t    ul64t;
    if8_t     if08t;
    if16_t    if16t;
    if32_t    if32t;
    if64_t    if64t;
    uf8_t     uf08t;
    uf16_t    uf16t;
    uf32_t    uf32t;
    uf64_t    uf64t;
    f32_t     fp32t;
    f64_t     fp64t;
} allt;

#define typemin(x) ({                   \
    typeof(x) _x;   _Generic((_x),      \
    char:               CHAR_MIN,       \
    is8_t:              INT8_MIN,       \
    is16_t:             INT16_MIN,      \
    is32_t:             INT32_MIN,      \
    is64_t:             INT64_MIN,      \
    us8_t:              0,              \
    us16_t:             0,              \
    us32_t:             0,              \
    us64_t:             0,              \
    f32_t:              __FLT32_MIN__,  \
    f64_t:              __FLT64_MIN__,  \
    f128_t:             __FLT128_MIN__, \
    default:            0);             \
})

#define typemax(x) ({                   \
    typeof(x) _x;   _Generic((_x),      \
    char:               CHAR_MAX,       \
    is8_t:              INT8_MAX,       \
    is16_t:             INT16_MAX,      \
    is32_t:             INT32_MAX,      \
    is64_t:             INT64_MAX,      \
    us8_t:              UINT8_MAX,      \
    us16_t:             UINT16_MAX,     \
    us32_t:             UINT32_MAX,     \
    us64_t:             UINT64_MAX,     \
    f32_t:              __FLT32_MAX__,  \
    f64_t:              __FLT64_MAX__,  \
    f128_t:             __FLT128_MAX__, \
    default:            0);             \
})

#define typeeps(x) ({ \
    typeof(x) _x;   _Generic((_x),          \
    char:               1,                  \
    is8_t:              1,                  \
    is16_t:             1,                  \
    is32_t:             1,                  \
    is64_t:             1,                  \
    us8_t:              1,                  \
    us16_t:             1,                  \
    us32_t:             1,                  \
    us64_t:             1,                  \
    f32_t:             __FLT32_EPSILON__,   \
    f64_t:             __FLT64_EPSILON__,   \
    f128_t:            __FLT128_EPSILON__,  \
    default:            0);                 \
})

/*UNDEF*/
#undef intmax_t
#undef uintmax_t
#undef intptr_t
#undef uintptr_t

#undef int8_t
#undef int16_t
#undef int32_t
#undef int64_t
#undef uint8_t
#undef uint16_t
#undef uint32_t
#undef uint64_t

#undef int_least8_t
#undef int_least16_t
#undef int_least32_t
#undef int_least64_t
#undef uint_least8_t
#undef uint_least16_t
#undef uint_least32_t
#undef uint_least64_t

#undef int_fast8_t
#undef int_fast16_t
#undef int_fast32_t
#undef int_fast64_t
#undef uint_fast8_t
#undef uint_fast16_t
#undef uint_fast32_t
#undef uint_fast64_t

END_C_DECLARATION

#endif /*YAYA_NUMBER_H*/
