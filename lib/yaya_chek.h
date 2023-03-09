//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_CHEK_H
#define YAYA_CHEK_H

#include "yaya_cdeclaration.h"
BEG_C_DECLARATION

#include "assert.h"

#include "yaya_type.h"
#include "yaya_concat.h"
#include "yaya_sugar.h"
#include "yaya_unused.h"
#include "yaya_concat.h"

#define COMPILE_CHR_OR_ZERO(A) _Generic((A),                                      \
    char          : (A), const char          : (A),                               \
    signed char   : (A), const signed char   : (A),                               \
    unsigned char : (A), const unsigned char : (A),                               \
    default       : ('\0'))

#define COMPILE_INT_OR_ZERO(A) _Generic((A),                                      \
    signed int         : (A), const signed int         : (A),                     \
    unsigned int       : (A), const unsigned int       : (A),                     \
    signed short       : (A), const signed short       : (A),                     \
    unsigned short     : (A), const unsigned short     : (A),                     \
    signed long        : (A), const signed long        : (A),                     \
    unsigned long      : (A), const unsigned long      : (A),                     \
    signed long long   : (A), const signed long long   : (A),                     \
    unsigned long long : (A), const unsigned long long : (A),                     \
    default            : (0))

#define COMPILE_FLT_OR_ZERO(A) _Generic((A),                                      \
    float        : (A), const float       : (A),                                  \
    double       : (A), const double      : (A),                                  \
    long double  : (A), const long double : (A),                                  \
    default      : typecast(A, 0))

#define COMPILE_CHRP_OR_NULL(A) _Generic((A),                                     \
    char*          : (A), const char*          : (A),                             \
    signed char*   : (A), const signed char*   : (A),                             \
    unsigned char* : (A), const unsigned char* : (A),                             \
    default        : (NULL))

#define COMPILE_INTP_OR_NULL(A) _Generic((A),                                     \
    signed int*         : (A), const signed int*         : (A),                   \
    unsigned int*       : (A), const unsigned int*       : (A),                   \
    signed short*       : (A), const signed short*       : (A),                   \
    unsigned short*     : (A), const unsigned short*     : (A),                   \
    signed long*        : (A), const signed long*        : (A),                   \
    unsigned long*      : (A), const unsigned long*      : (A),                   \
    signed long long*   : (A), const signed long long*   : (A),                   \
    unsigned long long* : (A), const unsigned long long* : (A),                   \
    default             : (NULL))

#define COMPILE_FLTP_OR_NULL(A) _Generic((A),                                     \
    float*        : (A), const float*       : (A),                                \
    double*       : (A), const double*      : (A),                                \
    long double*  : (A), const long double* : (A),                                \
    default       : (NULL))


#define ASSERT_NAME(name) CAT_2(CAT_2(CAT_2(ASSERT, name), __LINE_), __LINE__)
#define COMPILE_ASSERT(cond, name) ({                                             \
    typedef int ASSERT_NAME(name)[(cond) ? 1 : -1];                               \
    ASSERT_NAME(name) t;                                                          \
    UNUSED_VAR(t);                                                                \
})


#define COMPILE_TYPECHEK(x, y)                                                    \
    (                                                                             \
    (std_type_index(x) == std_type_index(y)) &&                                   \
    (std_type_group(x) == std_type_group(y)) &&                                   \
    (sizeof(x) == sizeof(y))                                                      \
    )

#define COMPILE_GROUPCHEK(groups, var)                                            \
    (((groups) & std_type_group(var)) != 0)

#define COMPILE_NO_SIDE(x, __x_unique)                                            \
    typeof(x) __x_unique = (x)


#define COMPILE_WCHDOG(x, y, _x_unique, _y_unique, op) ({                         \
    COMPILE_NO_SIDE((x), (_x_unique));                                            \
    COMPILE_NO_SIDE((y), (_y_unique));                                            \
    COMPILE_ASSERT(COMPILE_TYPECHEK((_x_unique), (_y_unique)), _TYPECHEK);        \
    op;                                                                           \
})

#define COMPILE_WCHDOG_3(x, y, z, _x_unique, _y_unique, _z_unique, op) ({         \
    COMPILE_NO_SIDE((x), (_x_unique));                                            \
    COMPILE_NO_SIDE((y), (_y_unique));                                            \
    COMPILE_NO_SIDE((z), (_z_unique));                                            \
    COMPILE_ASSERT(COMPILE_TYPECHEK((_x_unique), (_y_unique)), _TYPECHEK);        \
    COMPILE_ASSERT(COMPILE_TYPECHEK((_x_unique), (_z_unique)), _TYPECHEK);        \
    BLOC(op);                                                                     \
})


#define COMPILE_WCHDOG_TYPE(type, x, y, _x_unique, _y_unique, op) ({              \
    COMPILE_NO_SIDE(x, _x_unique);                                                \
    COMPILE_NO_SIDE(y, _y_unique);                                                \
    type __type_unique;                                                           \
    COMPILE_ASSERT(COMPILE_TYPECHEK((__type_unique), _x_unique), _TYPECHEK);      \
    COMPILE_ASSERT(COMPILE_TYPECHEK((__type_unique), _y_unique), _TYPECHEK);      \
    BLOC(op);                                                                     \
})

#define COMPILE_WCHDOG_GROUP(group, x, y, _x_unique, _y_unique, op) ({            \
    COMPILE_NO_SIDE(x, _x_unique);                                                \
    COMPILE_NO_SIDE(y, _y_unique);                                                \
    COMPILE_ASSERT(COMPILE_GROUPCHEK((group), (_x_unique)), _GROUPMATCH);         \
    COMPILE_ASSERT(COMPILE_GROUPCHEK((group), (_y_unique)), _GROUPMATCH);         \
    COMPILE_ASSERT(COMPILE_TYPECHEK((_x_unique), (_y_unique)), _TYPECHEK);        \
    BLOC(op);                                                                     \
})


#define COMPILE_TYPEMATCH(type, x) ({                                             \
    typeof (x) _x_unique = {0};                                                   \
    type       _x_type   = {0};                                                   \
    COMPILE_ASSERT(COMPILE_TYPECHEK(_x_type, _x_unique), _TYPEMATCH);             \
})


#define COMPILE_GROUPMATCH(group, x) ({                                           \
    COMPILE_ASSERT(COMPILE_GROUPCHEK((group), (x)), _GROUPMATCH);                 \
})

END_C_DECLARATION
#endif /*YAYA_CHEK_H*/
