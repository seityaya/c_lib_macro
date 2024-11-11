// Author                 : Seityagiya Terlekchi
// Contacts               : terlekchiseityaya@gmail.com
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2024 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_CONCAT_H
#define YAYA_CONCAT_H

// clang-format off
#include "yaya_cdecl.h"
BEG_C_DECLARATION

//================= CONCAT ===========================================================================================================================

#define MACRO_DELAY(x)    x

#define STR_1(x)          #x
#define STR_2(x)          STR_1(x)
#define STR_3(x)          STR_2(MACRO_DELAY(x))

#define CAT_1(x, y)       x##y
#define CAT_2(x, y)       CAT_1(x, y)
#define CAT_3(x, y)       CAT_2(MACRO_DELAY(x), MACRO_DELAY(y))

#define CAT_VA_1(a, ...)  a##__VA_ARGS__
#define CAT_VA_2(a, ...)  CAT_VA_1(a, __VA_ARGS__)
#define CAT_VA_3(a, ...)  CAT_VA_2(a, MACRO_DELAY(CAT_VA_2(__VA_ARGS__)))

//====================================================================================================================================================

END_C_DECLARATION
// clang-format on
#endif /*YAYA_CONCAT_H*/
