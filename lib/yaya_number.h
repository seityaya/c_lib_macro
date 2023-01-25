//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_NUMBER_H
#define YAYA_NUMBER_H

#include "stdint.h"

/*ALIASES*/
/*max types*/
#define i_max_t       intmax_t
#define u_max_t       uintmax_t
#define f_max_t       long double
#define i_ptr_t       intptr_t
#define u_ptr_t       uintptr_t

/*strict types*/
#define i_s8_t        int8_t
#define i_s16_t       int16_t
#define i_s32_t       int32_t
#define i_s64_t       int64_t

#define u_s8_t        uint8_t
#define u_s16_t       uint16_t
#define u_s32_t       uint32_t
#define u_s64_t       uint64_t

/*least types*/
#define i_l8_t        int_least8_t
#define i_l16_t       int_least16_t
#define i_l32_t       int_least32_t
#define i_l64_t       int_least64_t

#define u_l8_t        uint_least8_t
#define u_l16_t       uint_least16_t
#define u_l32_t       uint_least32_t
#define u_l64_t       uint_least64_t

/*fast types*/
#define i_f8_t        int_fast8_t
#define i_f16_t       int_fast16_t
#define i_f32_t       int_fast32_t
#define i_f64_t       int_fast64_t

#define u_f8_t        uint_fast8_t
#define u_f16_t       uint_fast16_t
#define u_f32_t       uint_fast32_t
#define u_f64_t       uint_fast64_t

#define fl_32_t       float
#define fl_64_t       double
#define fl_128_t      long double

/*CONST NUMBER*/
#define i_8_c(x)     (i_s8_t) (INT8_C(x))
#define i_16_c(x)    (i_s16_t)(INT16_C(x))
#define i_32_c(x)    (i_s32_t)(INT32_C(x))
#define i_64_c(x)    (i_s64_t)(INT64_C(x))
#define i_max_c(x)   (i_max_t)(INTMAX_C(x))

#define u_8_c(x)     (u_s8_t) (UINT8_C(x))
#define u_16_c(x)    (u_s16_t)(UINT16_C(x))
#define u_32_c(x)    (u_s32_t)(UINT32_C(x))
#define u_64_c(x)    (u_s64_t)(UINT64_C(x))
#define u_64_c(x)    (u_s64_t)(UINT64_C(x))
#define u_max_c(x)   (u_max_t)(UINTMAX_C(x))

#define fl_32_c(x)   ((fl_32_t)(x))
#define fl_64_c(x)   ((fl_64_t)(x))
#define fl_max_c(x)  ((f_max_t)(x))


typedef union allt{
    void*      voidt;
    char       chart;
    i_max_t    imaxt;
    u_max_t    umaxt;
    i_ptr_t    iptrt;
    u_ptr_t    uptrt;
    i_s8_t     is08t;
    i_s16_t    is16t;
    i_s32_t    is32t;
    i_s64_t    is64t;
    u_s8_t     us08t;
    u_s16_t    us16t;
    u_s32_t    us32t;
    u_s64_t    us64t;
    i_l8_t     il08t;
    i_l16_t    il16t;
    i_l32_t    il32t;
    i_l64_t    il64t;
    u_l8_t     ul08t;
    u_l16_t    ul16t;
    u_l32_t    ul32t;
    u_l64_t    ul64t;
    i_f8_t     if08t;
    i_f16_t    if16t;
    i_f32_t    if32t;
    i_f64_t    if64t;
    u_f8_t     uf08t;
    u_f16_t    uf16t;
    u_f32_t    uf32t;
    u_f64_t    uf64t;
    fl_32_t    fl32t;
    fl_64_t    fl64t;
} allt;


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

#endif /*YAYA_NUMBER_H*/
