// Author                 : Seityagiya Terlekchi
// Contacts               : terlekchiseityaya@gmail.com
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2025 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_ARGCOUNT_H
#define YAYA_ARGCOUNT_H

#include "yaya_concat.h"

// clang-format off
#include "yaya_cdecl.h"
BEG_C_DECLARATION

//================= ARGCOUNT =========================================================================================================================
/*
 * Using ARGCOUNT :
 *
 * void f(int count, ...) { }
 *
 * f(ARGCOUNT_AND_ARGS(arg1, arg2, .... ))           - V1 use in code
 *
 * #define f(...) f(ARGCOUNT_AND_ARGS(__VA_ARGS__))  - V2 redefinion function name
*/

#define ARGCOUNT_AND_ARGS(...) ARGCOUNT(__VA_ARGS__), ##__VA_ARGS__

#define ARGCOUNT(...)          CAT_2(___VAR_COUNT_EMPTY_, __IS_EMPTY(__VA_ARGS__))(__VA_ARGS__)

/* Returns the 100th argument. */
#define ___ARG_100(                                                                                                                                  \
      _, _99, _98, _97, _96, _95, _94, _93, _92, _91, _90, _89, _88, _87, _86, _85, _84, _83, _82, _81,                                              \
    _80, _79, _78, _77, _76, _75, _74, _73, _72, _71, _70, _69, _68, _67, _66, _65, _64, _63, _62, _61,                                              \
    _60, _59, _58, _57, _56, _55, _54, _53, _52, _51, _50, _49, _48, _47, _46, _45, _44, _43, _42, _41,                                              \
    _40, _39, _38, _37, _36, _35, _34, _33, _32, _31, _30, _29, _28, _27, _26, _25, _24, _23, _22, _21,                                              \
    _20, _19, _18, _17, _16, _15, _14, _13, _12, _11, _10,  _9,  _8,  _7,  _6,  _5,  _4,  _3,  _2,  _1, X_, ...) X_

/* Returns whether __VA_ARGS__ has a comma (up to 100 arguments). */
#define ___HAS_COMMA(...) MACRO_DELAY(___ARG_100(__VA_ARGS__,                                                                                        \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,                                                                                      \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,                                                                                      \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,                                                                                      \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1,                                                                                      \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0))

#define ___VAR_COUNT_EMPTY_0(...) MACRO_DELAY(___ARG_100(__VA_ARGS__,                                                                                \
    100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81,                                                                 \
     80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61,                                                                 \
     60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41,                                                                 \
     40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21,                                                                 \
     20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1))

#define ___VAR_COUNT_EMPTY_1(...) 0

/* Produces a comma if followed by a parenthesis. */
#define ___TRIGGER_PARENTHESIS_(...) ,
#define ___PASTE5(_0, _1, _2, _3, _4) _0 ## _1 ## _2 ## _3 ## _4
#define ___IS_EMPTY_CASE_0001 ,

/* Returns true if inputs expand to (false, false, false, true) */
#define ___IS_EMPTY(_0, _1, _2, _3) ___HAS_COMMA(___PASTE5(___IS_EMPTY_CASE_, _0, _1, _2, _3))

/* Returns whether __VA_ARGS__ is empty. */
#define __IS_EMPTY(...)                                                                                                                              \
    ___IS_EMPTY(                                                                                                                                     \
        /* Testing for an argument with a comma e.g. "ARG1, ARG2", "ARG1, ...", or "," */                                                            \
        ___HAS_COMMA(__VA_ARGS__),                                                                                                                   \
        /* Testing for an argument around parenthesis e.g. "(ARG1)", "(...)", or "()" */                                                             \
        ___HAS_COMMA(___TRIGGER_PARENTHESIS_ __VA_ARGS__),                                                                                           \
        /* Testing for a macro as an argument, which will expand the parenthesis, possibly generating a comma. */                                    \
        ___HAS_COMMA(__VA_ARGS__ (/*empty*/)),                                                                                                       \
        /* If all previous checks are false, __VA_ARGS__ does not generate a comma by itself, */                                                     \
        /* nor with ___TRIGGER_PARENTHESIS_ behind it, nor with () after it. */                                                                      \
        /* Therefore, "___TRIGGER_PARENTHESIS_ __VA_ARGS__ ()" only generates a comma if __VA_ARGS__ is empty. */                                    \
        /* So, this tests for an empty __VA_ARGS__ (given the previous conditionals are false). */                                                   \
        ___HAS_COMMA(___TRIGGER_PARENTHESIS_ __VA_ARGS__ (/*empty*/))                                                                                \
    )

//====================================================================================================================================================

END_C_DECLARATION
// clang-format on
#endif /*YAYA_ARGCOUNT_H*/
