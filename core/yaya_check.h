// Author                 : Seityagiya Terlekchi
// Contacts               : terlekchiseityaya@gmail.com
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2024 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_CHECK_H
#define YAYA_CHECK_H

#include "yaya_unused.h"
#include "yaya_type.h"

// clang-format off
#include "yaya_cdecl.h"
BEG_C_DECLARATION

//================= COMPTIME ASSERT ==================================================================================================================

#define COMPILE_NO_SIDE_EFFECT_VARIABLE(x, __x_unique)                                                                                               \
    typeof(x) (__x_unique) = (x)

//----------------------------------------------------------------------------------------------------------------------------------------------------

#define COMPTIME_CHECK_IS_RUNTIME_VALUE(x) ({                                                                                                        \
    void* COMPTIME_ASSERT_RUN_TIME_VALUE = &(x);                                                                                                     \
    UNUSED_LOCAL_VAR(COMPTIME_ASSERT_RUN_TIME_VALUE); })

#define COMPTIME_CHECK_IS_COMPTIME_VALUE(x) ({                                                                                                       \
    typedef enum { value = (x) } COMPTIME_ASSERT_COMPILE_TIME_VALUE;                                                                                 \
    COMPTIME_ASSERT_COMPILE_TIME_VALUE t;                                                                                                            \
    UNUSED_LOCAL_VAR(t); })

#define COMPTIME_ASSERT(cond) ({                                                                                                                     \
    COMPTIME_CHECK_IS_COMPTIME_VALUE(cond);                                                                                                          \
    typedef int COMPTIME_ASSERT[(cond) ? 1 : -1];                                                                                                    \
    COMPTIME_ASSERT t;                                                                                                                               \
    UNUSED_LOCAL_VAR(t); })

//----------------------------------------------------------------------------------------------------------------------------------------------------

#define COMPILE_1_CALC(x, _x_unique, calc) ({                                                                                                        \
    COMPILE_NO_SIDE_EFFECT_VARIABLE(x, _x_unique);                                                                                                   \
    (calc); })

#define COMPILE_2_CALC(x, y, _x_unique, _y_unique, calc) ({                                                                                          \
    COMPILE_NO_SIDE_EFFECT_VARIABLE(x, _x_unique);                                                                                                   \
    COMPILE_NO_SIDE_EFFECT_VARIABLE(y, _y_unique);                                                                                                   \
    (calc); })

#define COMPILE_3_CALC(x, y, z, _x_unique, _y_unique, _z_unique, calc) ({                                                                            \
    COMPILE_NO_SIDE_EFFECT_VARIABLE(x, _x_unique);                                                                                                   \
    COMPILE_NO_SIDE_EFFECT_VARIABLE(y, _y_unique);                                                                                                   \
    COMPILE_NO_SIDE_EFFECT_VARIABLE(z, _z_unique);                                                                                                   \
    (calc); })

//----------------------------------------------------------------------------------------------------------------------------------------------------

#define COMPILE_TYPE_EQUAL(x, y)                                                                                                                     \
    ((base_type_uid(x) == base_type_uid(y)) && (base_type_group(x) == base_type_group(y)) && (sizeof(x) == sizeof(y)))

#define COMPILE_ASSERT_TYPE_EQUAL(x, y)                                                                                                              \
    COMPTIME_ASSERT(COMPILE_TYPE_EQUAL((x), (y)))

#define COMPILE_ASSERT_TYPE_NOT_EQUAL(x, y)                                                                                                          \
    COMPTIME_ASSERT(!COMPILE_TYPE_EQUAL((x), (y)))

#define COMPILE_ASSERT_TYPE_EQUAL_2_CALC(x, y, _x_unique, _y_unique, calc) ({                                                                        \
    COMPILE_NO_SIDE_EFFECT_VARIABLE((x), _x_unique);                                                                                                 \
    COMPILE_NO_SIDE_EFFECT_VARIABLE((y), _y_unique);                                                                                                 \
    COMPILE_ASSERT_TYPE_EQUAL(_x_unique, _y_unique);                                                                                                 \
    (calc); })

#define COMPILE_ASSERT_TYPE_EQUAL_3_CALC(x, y, z, _x_unique, _y_unique, _z_unique, calc) ({                                                          \
    COMPILE_NO_SIDE_EFFECT_VARIABLE((x), _x_unique);                                                                                                 \
    COMPILE_NO_SIDE_EFFECT_VARIABLE((y), _y_unique);                                                                                                 \
    COMPILE_NO_SIDE_EFFECT_VARIABLE((z), _z_unique);                                                                                                 \
    COMPILE_ASSERT_TYPE_EQUAL(_x_unique, _y_unique);                                                                                                 \
    COMPILE_ASSERT_TYPE_EQUAL(_y_unique, _z_unique);                                                                                                 \
    (calc); })

#define COMPILE_ASSERT_TYPE_MATCH(type, x) ({                                                                                                        \
    type       _x_type   = {0};                                                                                                                      \
    typeof (x) _x_unique = {0};                                                                                                                      \
    COMPILE_ASSERT_TYPE_EQUAL(_x_type, _x_unique); })

#define COMPILE_ASSERT_TYPE_NOT_MATCH(type, x) ({                                                                                                    \
    type       _x_type   = {0};                                                                                                                      \
    typeof (x) _x_unique = {0};                                                                                                                      \
    COMPILE_ASSERT_TYPE_NOT_EQUAL(_x_type, _x_unique);  })

#define COMPILE_ASSERT_TYPE_MATCH_1_CALC(type, x, _x_unique, calc) ({                                                                                \
    type __type_unique = {0};                                                                                                                        \
    COMPILE_NO_SIDE_EFFECT_VARIABLE(x, _x_unique);                                                                                                   \
    COMPTIME_ASSERT(COMPILE_TYPE_EQUAL(__type_unique, _x_unique));                                                                                   \
    (calc); })

#define COMPILE_ASSERT_TYPE_MATCH_2_CALC(type, x, y, _x_unique, _y_unique, calc) ({                                                                  \
    type __type_unique = {0};                                                                                                                        \
    COMPILE_NO_SIDE_EFFECT_VARIABLE(x, _x_unique);                                                                                                   \
    COMPILE_NO_SIDE_EFFECT_VARIABLE(y, _y_unique);                                                                                                   \
    COMPILE_ASSERT_TYPE_EQUAL(__type_unique, _x_unique);                                                                                             \
    COMPILE_ASSERT_TYPE_EQUAL(__type_unique, _y_unique);                                                                                             \
    (calc); })

#define COMPILE_ASSERT_TYPE_MATCH_3_CALC(type, x, y, z, _x_unique, _y_unique, _z_unique, calc) ({                                                    \
    type __type_unique = {0};                                                                                                                        \
    COMPILE_NO_SIDE_EFFECT_VARIABLE(x, _x_unique);                                                                                                   \
    COMPILE_NO_SIDE_EFFECT_VARIABLE(y, _y_unique);                                                                                                   \
    COMPILE_NO_SIDE_EFFECT_VARIABLE(z, _z_unique);                                                                                                   \
    COMPTIME_ASSERT(COMPILE_TYPE_EQUAL(__type_unique, _x_unique));                                                                                   \
    COMPTIME_ASSERT(COMPILE_TYPE_EQUAL(__type_unique, _y_unique));                                                                                   \
    COMPTIME_ASSERT(COMPILE_TYPE_EQUAL(__type_unique, _z_unique));                                                                                   \
    (calc); })

//----------------------------------------------------------------------------------------------------------------------------------------------------

#define COMPILE_SIGN_CHECK(sign, var)                                                                                                                \
    (base_type_sign((var)) ==  (sign))

//----------------------------------------------------------------------------------------------------------------------------------------------------

#define COMPILE_GROUP_CHECK(groups, var)                                                                                                             \
    (((groups) & base_type_group((var))) != 0)

#define COMPILE_GROUP_EQUAL(x, y)                                                                                                                    \
    (base_type_group(x) == base_type_group(y))

#define COMPILE_ASSERT_GROUP_EQUAL(x, y)                                                                                                             \
    COMPTIME_ASSERT( COMPILE_GROUP_EQUAL((x), (y)))

#define COMPILE_ASSERT_GROUP_NOT_EQUAL(x, y)                                                                                                         \
    COMPTIME_ASSERT(!COMPILE_GROUP_EQUAL((x), (y)))

#define COMPILE_ASSERT_GROUP_EQUAL_2_CALC(x, y, _x_unique, _y_unique, calc) ({                                                                       \
    COMPILE_NO_SIDE_EFFECT_VARIABLE((x), _x_unique);                                                                                                 \
    COMPILE_NO_SIDE_EFFECT_VARIABLE((y), _y_unique);                                                                                                 \
    COMPILE_ASSERT_GROUP_EQUAL(_x_unique, _y_unique);                                                                                                \
    (calc); })

#define COMPILE_ASSERT_GROUP_EQUAL_3_CALC(x, y, z, _x_unique, _y_unique, _z_unique, calc) ({                                                         \
    COMPILE_NO_SIDE_EFFECT_VARIABLE((x), _x_unique);                                                                                                 \
    COMPILE_NO_SIDE_EFFECT_VARIABLE((y), _y_unique);                                                                                                 \
    COMPILE_NO_SIDE_EFFECT_VARIABLE((z), _z_unique);                                                                                                 \
    COMPILE_ASSERT_GROUP_EQUAL(_x_unique, _y_unique);                                                                                                \
    COMPILE_ASSERT_GROUP_EQUAL(_y_unique, _z_unique);                                                                                                \
    (calc); })

#define COMPILE_ASSERT_GROUP_MATCH(group, x)                                                                                                         \
    COMPTIME_ASSERT( COMPILE_GROUP_CHECK((group), (x)))

#define COMPILE_ASSERT_GROUP_NOT_MATCH(group, x)                                                                                                     \
    COMPTIME_ASSERT(!COMPILE_GROUP_CHECK((group), (x)))

#define COMPILE_ASSERT_GROUP_NOT_MATCH_1_CALC(group, x, _x_unique, calc) ({                                                                          \
    COMPILE_NO_SIDE_EFFECT_VARIABLE((x), _x_unique);                                                                                                 \
    COMPTIME_ASSERT(!COMPILE_GROUP_CHECK((group), _x_unique));                                                                                       \
    (calc); })

#define COMPILE_ASSERT_GROUP_MATCH_1_CALC(group, x, _x_unique, calc) ({                                                                              \
    COMPILE_NO_SIDE_EFFECT_VARIABLE((x), _x_unique);                                                                                                 \
    COMPILE_ASSERT_GROUP_MATCH((group), _x_unique);                                                                                                  \
    (calc); })

#define COMPILE_ASSERT_GROUP_MATCH_2_CALC(group, x, y, _x_unique, _y_unique, calc) ({                                                                \
    COMPILE_NO_SIDE_EFFECT_VARIABLE((x), _x_unique);                                                                                                 \
    COMPILE_NO_SIDE_EFFECT_VARIABLE((y), _y_unique);                                                                                                 \
    COMPILE_ASSERT_GROUP_MATCH((group),  _x_unique);                                                                                                 \
    COMPILE_ASSERT_GROUP_MATCH((group),  _y_unique);                                                                                                 \
    COMPILE_ASSERT_GROUP_EQUAL(_x_unique, _y_unique);                                                                                                \
    (calc); })

#define COMPILE_ASSERT_GROUP_MATCH_3_CALC(group, x, y, z, _x_unique, _y_unique, _z_unique, calc) ({                                                  \
    COMPILE_NO_SIDE_EFFECT_VARIABLE((x), _x_unique);                                                                                                 \
    COMPILE_NO_SIDE_EFFECT_VARIABLE((y), _y_unique);                                                                                                 \
    COMPILE_NO_SIDE_EFFECT_VARIABLE((z), _z_unique);                                                                                                 \
    COMPILE_ASSERT_GROUP_MATCH((group),  _x_unique);                                                                                                 \
    COMPILE_ASSERT_GROUP_MATCH((group),  _y_unique);                                                                                                 \
    COMPILE_ASSERT_GROUP_MATCH((group),  _z_unique);                                                                                                 \
    COMPILE_ASSERT_GROUP_EQUAL(_x_unique, _y_unique);                                                                                                \
    COMPILE_ASSERT_GROUP_EQUAL(_x_unique, _z_unique);                                                                                                \
    (calc); })

//====================================================================================================================================================

END_C_DECLARATION
// clang-format on
#endif /*YAYA_CHECK_H*/
