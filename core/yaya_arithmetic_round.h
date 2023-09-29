// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_ARITHMETIC_ROUND_H
#define YAYA_ARITHMETIC_ROUND_H

#include "yaya_cdecl.h"
#include "yaya_check.h"
#include "yaya_type.h"

// clang-format off
BEG_C_DECLARATION

//================= ОКРУГЛЕНИЕ =======================================================================================================================
/*
 * Округление к ближайшему целому, 0.5 округляется вверх
*/
#define round_int(x)                                                                                                                                 \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC(BASE_TYPE_GROUP_FLT, (x), _x, __round_int(_x))

#define __round_int(x)                                                                                                                               \
    BLOCK(                                                                                                                                           \
        _Generic((x),                                                                                                                                \
            float       : rintf,                                                                                                                     \
            double      : rint,                                                                                                                      \
            long double : rintl,                                                                                                                     \
            default     : base_type_cast(x, 0))(x)                                                                                                   \
    )

/*
 * Округление к ближайшему целому, 0.5 округляется к четному
*/
#define round_even(x) //TODO

/*
 * Округление к ближайшему целому, 0.5 округляется к нечетному
*/
#define round_odd(x) //TODO

/*
 * Округление к ближайшему целому, 0.5 округляется в случайною сторону
*/
#define round_rand(x) //TODO

/*
 * Округление к ближайшему целому, 0.5 округляется попеременно
*/
#define round_rot(x) //TODO

/*
 * Округление в большую сторону
*/
#define round_up(x)                                                                                                                                  \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC(BASE_TYPE_GROUP_FLT, (x), _x, __round_up(_x))

#define __round_up(x)                                                                                                                                \
    BLOCK(                                                                                                                                           \
        _Generic((x),                                                                                                                                \
            float       : ceilf,                                                                                                                     \
            double      : ceil,                                                                                                                      \
            long double : ceill,                                                                                                                     \
            default     : base_type_cast(x, 0))(x)                                                                                                   \
    )

/*
 * Округление в меньшую сторону
*/
#define round_dn(x)                                                                                                                                  \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC(BASE_TYPE_GROUP_FLT, (x), _x, __round_dn(_x))

#define __round_dn(x)                                                                                                                                \
    BLOCK(                                                                                                                                           \
        _Generic((x),                                                                                                                                \
            float       : floorf,                                                                                                                    \
            double      : floor,                                                                                                                     \
            long double : floorl,                                                                                                                    \
            default     : base_type_cast(x, 0))(x)                                                                                                   \
    )

/*
 * Округление к нулю
*/
#define round_zero(x)                                                                                                                                \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC(BASE_TYPE_GROUP_FLT, (x), _x, __round_zero(_x))

#define __round_zero(x)                                                                                                                              \
    BLOCK(                                                                                                                                           \
        _Generic((x),                                                                                                                                \
            float       : truncf,                                                                                                                    \
            double      : trunc,                                                                                                                     \
            long double : truncl,                                                                                                                    \
            default: base_type_cast(x, 0))(x)                                                                                                        \
    )

/*
 * Округление к бесконечности или округление от нуля
*/
#define round_inf(x)                                                                                                                                 \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC(BASE_TYPE_GROUP_FLT, (x), _x,                                                                                  \
        BLOCK(__round_inf(_x)))

#define __round_inf(x)                                                                                                                               \
    TERNARIUS(__is_pos(x), BLOCK(__round_up(x)), BLOCK(__round_dn(x)))

/*
 * Округление c шагом, используя один из методов округления
*/
#define round_eps(x, e, func)                                                                                                                       \
    COMPILE_ASSERT_GROUP_MATCH_2_CALC(BASE_TYPE_GROUP_FLT, (x), (e), ___x, ___e, __round_eps(___x, ___e, func))

#define __round_eps(x, e, func)                                                                                                                     \
    BLOCK(base_type_cast((x), __mul(func(__qut((x), (e))), (e))))

#endif /*YAYA_ARITHMETIC_ROUND_H*/
