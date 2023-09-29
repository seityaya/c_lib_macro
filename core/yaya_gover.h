// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_GOVER_H
#define YAYA_GOVER_H

// clang-format off
#include "yaya_cdecl.h"
BEG_C_DECLARATION

//================= GENERIC OVERLAP ==================================================================================================================

#define COMPILE_BOOL_VAR_OR_ZERO(A)                                                                                                                  \
    _Generic((A),                                                                                                                                    \
        _Bool               : (A), const _Bool               : (A),                                                                                  \
        default             : (false))

#define COMPILE_BOOL_PTR_OR_NULL(A)                                                                                                                  \
    _Generic((A),                                                                                                                                    \
        _Bool*              : (A), const _Bool*              : (A),                                                                                  \
        default             : (NULL))

//----------------------------------------------------------------------------------------------------------------------------------------------------

#define COMPILE_CHAR_VAR_OR_ZERO(A)                                                                                                                  \
    _Generic((A),                                                                                                                                    \
        char                : (A), const char                : (A),                                                                                  \
        default             : ('\0'))

#define COMPILE_CHAR_PTR_OR_NULL(A)                                                                                                                  \
    _Generic((A),                                                                                                                                    \
        char*               : (A), const char*               : (A),                                                                                  \
        signed char*        : (A), const signed char*        : (A),                                                                                  \
        unsigned char*      : (A), const unsigned char*      : (A),                                                                                  \
        default             : (NULL))

//----------------------------------------------------------------------------------------------------------------------------------------------------

#define COMPILE_INT_VAR_OR_ZERO(A)                                                                                                                   \
    _Generic((A),                                                                                                                                    \
    signed char         : (A), const signed char         : (A),                                                                                      \
    unsigned char       : (A), const unsigned char       : (A),                                                                                      \
    signed int          : (A), const signed int          : (A),                                                                                      \
    unsigned int        : (A), const unsigned int        : (A),                                                                                      \
    signed short        : (A), const signed short        : (A),                                                                                      \
    unsigned short      : (A), const unsigned short      : (A),                                                                                      \
    signed long         : (A), const signed long         : (A),                                                                                      \
    unsigned long       : (A), const unsigned long       : (A),                                                                                      \
    signed long long    : (A), const signed long long    : (A),                                                                                      \
    unsigned long long  : (A), const unsigned long long  : (A),                                                                                      \
    default             : (0))

#define COMPILE_INT_PTR_OR_NULL(A)                                                                                                                   \
    _Generic((A),                                                                                                                                    \
    signed int*         : (A), const signed int*         : (A),                                                                                      \
    unsigned int*       : (A), const unsigned int*       : (A),                                                                                      \
    signed short*       : (A), const signed short*       : (A),                                                                                      \
    unsigned short*     : (A), const unsigned short*     : (A),                                                                                      \
    signed long*        : (A), const signed long*        : (A),                                                                                      \
    unsigned long*      : (A), const unsigned long*      : (A),                                                                                      \
    signed long long*   : (A), const signed long long*   : (A),                                                                                      \
    unsigned long long* : (A), const unsigned long long* : (A),                                                                                      \
    default             : (NULL))

//----------------------------------------------------------------------------------------------------------------------------------------------------

#define COMPILE_FLT_VAR_OR_ZERO(A)                                                                                                                   \
    _Generic((A),                                                                                                                                    \
    float               : (A), const float               : (A),                                                                                      \
    double              : (A), const double              : (A),                                                                                      \
    long double         : (A), const long double         : (A),                                                                                      \
    default             : (0))

#define COMPILE_FLT_PTR_OR_NULL(A)                                                                                                                   \
    _Generic((A),                                                                                                                                    \
    float*              : (A), const float*              : (A),                                                                                      \
    double*             : (A), const double*             : (A),                                                                                      \
    long double*        : (A), const long double*        : (A),                                                                                      \
    default             : (NULL))

//====================================================================================================================================================

END_C_DECLARATION
// clang-format on
#endif /*YAYA_GOVER_H*/
