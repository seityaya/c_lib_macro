//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2022 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_NUMBER_H
#define YAYA_NUMBER_H

#include "yaya_type.h"

/*ALIASES*/
/*types*/
#define imax       intmax_t
#define umax       uintmax_t

#define iptr       intptr_t
#define uptr       uintptr_t

/*strict*/
#define i08s       int8_t
#define i16s       int16_t
#define i32s       int32_t
#define i64s       int64_t

#define u08s       uint8_t
#define u16s       uint16_t
#define u32s       uint32_t
#define u64s       uint64_t

/*least*/
#define i08l       int_least8_t
#define i16l       int_least16_t
#define i32l       int_least32_t
#define i64l       int_least64_t

#define u08l       uint_least8_t
#define u16l       uint_least16_t
#define u32l       uint_least32_t
#define u64l       uint_least64_t

/*fast*/
#define i08f       int_fast8_t
#define i16f       int_fast16_t
#define i32f       int_fast32_t
#define i64f       int_fast64_t

#define u_8f       uint_fast8_t
#define u16f       uint_fast16_t
#define u32f       uint_fast32_t
#define u64f       uint_fast64_t

#define fl32       float
#define fl64       double
#define fp32       char
#define fp64       char

typedef union allt{
    void*      voidt;
    char       chart;
    imax       imaxt;
    umax       umaxt;
    iptr       iptrt;
    uptr       uptrt;
    i08s       i08st;
    i16s       i16st;
    i32s       i32st;
    i64s       i64st;
    u08s       u_8st;
    u16s       u16st;
    u32s       u32st;
    u64s       u64st;
    i08l       i08lt;
    i16l       i16lt;
    i32l       i32lt;
    i64l       i64lt;
    u08l       u08lt;
    u16l       u16lt;
    u32l       u32lt;
    u64l       u64lt;
    i08f       i08ft;
    i16f       i16ft;
    i32f       i32ft;
    i64f       i64ft;
    u_8f       u08ft;
    u16f       u16ft;
    u32f       u32ft;
    u64f       u64ft;
    fl32       fl32t;
    fl64       fl64t;
    fp32       fp32t;
    fp64       fp64t;
}allt;

/*NUMBER*/
#define i08n(x)    (i08s)(INT8_C(x))
#define i16n(x)    (i16s)(INT16_C(x))
#define i32n(x)    (i32s)(INT32_C(x))
#define i64n(x)    (i64s)(INT64_C(x))

#define u08n(x)    (u08s)(UINT8_C(x))
#define u16n(x)    (u16s)(UINT16_C(x))
#define u32n(x)    (u32s)(UINT32_C(x))
#define u64n(x)    (u64s)(UINT64_C(x))

#define fl32n(x)    ((fl32)(x))
#define fl64n(x)    ((fl64)(x))
#define flmxn(x)    ((fl64)(x))

#endif /*YAYA_NUMBER_H*/
