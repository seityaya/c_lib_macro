// Author                 : Seityagiya Terlekchi
// Contacts               : terlekchiseityaya@gmail.com
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2022-2025 Seityagiya Terlekchi. All rights reserved.

#ifndef TEST_H
#define TEST_H

#include "math.h"
#include "string.h"
#include "yaya_bool.h"
#include "yaya_check.h"
#include "yaya_type.h"

// clang-format off

#define ASSERT_CALL_IF(                )  ({ if ( !__ASSERT_CALL_IF           (nullptr, nullptr, nullptr) ) return -1; })
#define ASSERT_BOOL_TR(  VAL           )  ({ if ( !__ASSERT_BOOL_TRUE         (VAL    , true   , nullptr) ) return -1; })
#define ASSERT_BOOL_FL(  VAL           )  ({ if ( !__ASSERT_BOOL_FALSE        (VAL    , false  , nullptr) ) return -1; })
#define ASSERT_BIT_EQ(   ACT, EXP      )  ({ if ( !__ASSERT_BIT_EQUAL         (ACT    , EXP    , nullptr) ) return -1; })
#define ASSERT_BIT_NQ(   ACT, EXP      )  ({ if ( !__ASSERT_BIT_NOT_EQUAL     (ACT    , EXP    , nullptr) ) return -1; })
#define ASSERT_NUM_EQ(   ACT, EXP      )  ({ if ( !__ASSERT_NUM_EQUAL         (ACT    , EXP    , nullptr) ) return -1; })
#define ASSERT_NUM_NQ(   ACT, EXP      )  ({ if ( !__ASSERT_NUM_NOT_EQUAL     (ACT    , EXP    , nullptr) ) return -1; })
#define ASSERT_CHR_EQ(   ACT, EXP      )  ({ if ( !__ASSERT_CHAR_EQUAL        (ACT    , EXP    , nullptr) ) return -1; })
#define ASSERT_CHR_NQ(   ACT, EXP      )  ({ if ( !__ASSERT_CHAR_NOT_EQUAL    (ACT    , EXP    , nullptr) ) return -1; })
#define ASSERT_PTR_EQ(   ACT, EXP      )  ({ if ( !__ASSERT_PTR_EQUAL         (ACT    , EXP    , nullptr) ) return -1; })
#define ASSERT_PTR_NQ(   ACT, EXP      )  ({ if ( !__ASSERT_PTR_NOT_EQUAL     (ACT    , EXP    , nullptr) ) return -1; })
#define ASSERT_NUL_EQ(   VAL           )  ({ if ( !__ASSERT_PTR_NULL          (VAL    , nullptr, nullptr) ) return -1; })
#define ASSERT_NUL_NQ(   VAL           )  ({ if ( !__ASSERT_PTR_NOT_NULL      (VAL    , nullptr, nullptr) ) return -1; })
#define ASSERT_STR_EQ(   ACT, EXP      )  ({ if ( !__ASSERT_STR_EQUAL         (ACT    , EXP    , nullptr) ) return -1; })
#define ASSERT_STR_NQ(   ACT, EXP      )  ({ if ( !__ASSERT_STR_NOT_EQUAL     (ACT    , EXP    , nullptr) ) return -1; })
#define ASSERT_STR_EQ_N( ACT, EXP, CNT )  ({ if ( !__ASSERT_STR_LEN_EQUAL     (ACT    , EXP    , CNT    ) ) return -1; })
#define ASSERT_STR_NQ_N( ACT, EXP, CNT )  ({ if ( !__ASSERT_STR_LEN_NOT_EQUAL (ACT    , EXP    , CNT    ) ) return -1; })
#define ASSERT_FLT_EQ(   ACT, EXP      )  ({ if ( !__ASSERT_FLT_EQUAL         (ACT    , EXP    , nullptr) ) return -1; })
#define ASSERT_FLT_NQ(   ACT, EXP      )  ({ if ( !__ASSERT_FLT_NOT_EQUAL     (ACT    , EXP    , nullptr) ) return -1; })
#define ASSERT_FLT_EQ_E( ACT, EXP, EPS )  ({ if ( !__ASSERT_FLT_EPS_EQUAL     (ACT    , EXP    , EPS    ) ) return -1; })
#define ASSERT_FLT_NQ_E( ACT, EXP, EPS )  ({ if ( !__ASSERT_FLT_EPS_NOT_EQUAL (ACT    , EXP    , EPS    ) ) return -1; })
#define ASSERT_TYP_EQ(   ACT, EXP      )  ({ if ( !__ASSERT_TYPE_EQUAL        (ACT    , EXP    , nullptr) ) return -1; })
#define ASSERT_TYP_NQ(   ACT, EXP      )  ({ if ( !__ASSERT_TYPE_NOT_EQUAL    (ACT    , EXP    , nullptr) ) return -1; })


#define __ASSERT_CALL_IF(          A, B, C) (false)
#define __ASSERT_BOOL_TRUE(        A, B, C) ((bool_t)(A) == (true ))
#define __ASSERT_BOOL_FALSE(       A, B, C) ((bool_t)(A) == (false))
#define __ASSERT_BIT_EQUAL(        A, B, C) COMPILE_ASSERT_TYPE_EQUAL_2_CALC((A), (B), _x, _y, ((((umax_t)(_x)) ^ ((umax_t)(_y))) == 0))
#define __ASSERT_BIT_NOT_EQUAL(    A, B, C) COMPILE_ASSERT_TYPE_EQUAL_2_CALC((A), (B), _x, _y, ((((umax_t)(_x)) ^ ((umax_t)(_y))) != 0))
#define __ASSERT_NUM_EQUAL(        A, B, C) COMPILE_ASSERT_GROUP_MATCH_2_CALC(BASE_TYPE_GROUP_SINT | BASE_TYPE_GROUP_UINT, A, B, _a, _b, COMPILE_ASSERT_TYPE_EQUAL_2_CALC((_a), (_b), _x, _y, (_x) == (_y)))
#define __ASSERT_NUM_NOT_EQUAL(    A, B, C) COMPILE_ASSERT_GROUP_MATCH_2_CALC(BASE_TYPE_GROUP_SINT | BASE_TYPE_GROUP_UINT, A, B, _a, _b, COMPILE_ASSERT_TYPE_EQUAL_2_CALC((_a), (_b), _x, _y, (_x) != (_y)))
#define __ASSERT_CHAR_EQUAL(       A, B, C) COMPILE_ASSERT_GROUP_MATCH_2_CALC(BASE_TYPE_GROUP_CHAR, A, B, _a, _b, COMPILE_ASSERT_TYPE_EQUAL_2_CALC((_a), (_b), _x, _y, (_x) == (_y)))
#define __ASSERT_CHAR_NOT_EQUAL(   A, B, C) COMPILE_ASSERT_GROUP_MATCH_2_CALC(BASE_TYPE_GROUP_CHAR, A, B, _a, _b, COMPILE_ASSERT_TYPE_EQUAL_2_CALC((_a), (_b), _x, _y, (_x) != (_y)))
#define __ASSERT_PTR_EQUAL(        A, B, C) ((void*)(A) == (void*)(B))
#define __ASSERT_PTR_NOT_EQUAL(    A, B, C) ((void*)(A) != (void*)(B))
#define __ASSERT_PTR_NULL(         A, B, C) ((void*)(A) == NULL)
#define __ASSERT_PTR_NOT_NULL(     A, B, C) ((void*)(A) != NULL)
#define __ASSERT_STR_EQUAL(        A, B, C) (0 == strcmp ((const char*)(A), (const char*)(B)))
#define __ASSERT_STR_NOT_EQUAL(    A, B, C) (0 != strcmp ((const char*)(A), (const char*)(B)))
#define __ASSERT_STR_LEN_EQUAL(    A, B, C) (0 == strncmp((const char*)(A), (const char*)(B), (size_t)(C)))
#define __ASSERT_STR_LEN_NOT_EQUAL(A, B, C) (0 != strncmp((const char*)(A), (const char*)(B), (size_t)(C)))
#define __ASSERT_FLT_EQUAL(        A, B, C) COMPILE_ASSERT_GROUP_MATCH_2_CALC(BASE_TYPE_GROUP_FLT, A, B, _a, _b, (!(fabs(_a - _b) >= base_type_eps(_a))))
#define __ASSERT_FLT_NOT_EQUAL(    A, B, C) COMPILE_ASSERT_GROUP_MATCH_2_CALC(BASE_TYPE_GROUP_FLT, A, B, _a, _b, (!(fabs(_a - _b) <  base_type_eps(_a))))
#define __ASSERT_FLT_EPS_EQUAL(    A, B, C) COMPILE_ASSERT_GROUP_MATCH_2_CALC(BASE_TYPE_GROUP_FLT, A, B, _a, _b, (!(fabs(_a - _b) >  abs(C)))          )
#define __ASSERT_FLT_EPS_NOT_EQUAL(A, B, C) COMPILE_ASSERT_GROUP_MATCH_2_CALC(BASE_TYPE_GROUP_FLT, A, B, _a, _b, (!(fabs(_a - _b) <= abs(C)))          )
#define __ASSERT_TYPE_EQUAL(       A, B, C) COMPILE_TYPE_EQUAL(A, B)
#define __ASSERT_TYPE_NOT_EQUAL(   A, B, C) !COMPILE_TYPE_EQUAL(A, B)

// clang-format on

#endif /* TEST_H */
