//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_CHEK_H
#define YAYA_CHEK_H

#include "yaya_type.h"
#include "yaya_concat.h"

#define COMPILE_CHR_OR_ZERO(A) _Generic((A), \
    char          : (A), const char          : (A), \
    signed char   : (A), const signed char   : (A), \
    unsigned char : (A), const unsigned char : (A), \
    default       : ('\0'))

#define COMPILE_INT_OR_ZERO(A) _Generic((A), \
    signed int         : (A), const signed int         : (A), \
    unsigned int       : (A), const unsigned int       : (A), \
    signed short       : (A), const signed short       : (A), \
    unsigned short     : (A), const unsigned short     : (A), \
    signed long        : (A), const signed long        : (A), \
    unsigned long      : (A), const unsigned long      : (A), \
    signed long long   : (A), const signed long long   : (A), \
    unsigned long long : (A), const unsigned long long : (A), \
    default            : (0))

#define COMPILE_FLT_OR_ZERO(A) _Generic((A), \
    float        : (A), const float       : (A), \
    double       : (A), const double      : (A), \
    long double  : (A), const long double : (A), \
    default      : (0.0))

#define COMPILE_CHRP_OR_NULL(A) _Generic((A), \
    char*          : (A), const char*          : (A), \
    signed char*   : (A), const signed char*   : (A), \
    unsigned char* : (A), const unsigned char* : (A), \
    default        : (NULL))

#define COMPILE_INTP_OR_NULL(A) _Generic((A), \
    signed int*         : (A), const signed int*         : (A), \
    unsigned int*       : (A), const unsigned int*       : (A), \
    signed short*       : (A), const signed short*       : (A), \
    unsigned short*     : (A), const unsigned short*     : (A), \
    signed long*        : (A), const signed long*        : (A), \
    unsigned long*      : (A), const unsigned long*      : (A), \
    signed long long*   : (A), const signed long long*   : (A), \
    unsigned long long* : (A), const unsigned long long* : (A), \
    default             : (NULL))

#define COMPILE_FLTP_OR_NULL(A) _Generic((A), \
    float*        : (A), const float*       : (A), \
    double*       : (A), const double*      : (A), \
    long double*  : (A), const long double* : (A), \
    default       : (NULL))

#define COMPILE_ASSERT(cond, name)                       \
    typedef int ASSERT##name[(cond) ? 1 : -1]

#define COMPILE_TYPECHEK(x, y)                           \
    ((type_in(x) == type_in(y)) &&                       \
    (sizeof(x) == sizeof(y)))

#define COMPILE_NO_SIDE(x, y)                            \
    typeof (x) _x = (x);                                 \
    typeof (y) _y = (y);

#define COMPILE_WCHDOG(x, y, op) ({                      \
    COMPILE_NO_SIDE(x, y);                               \
    COMPILE_ASSERT(COMPILE_TYPECHEK(_x, _y), _TYPECHEK); \
    (op);                                                \
    })

#endif /*YAYA_CHEK_H*/
