// Author                 : Seityagiya Terlekchi
// Contacts               : terlekchiseityaya@gmail.com
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2025 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_ENDIAN_H
#define YAYA_ENDIAN_H

// clang-format off
#include "yaya_cdecl.h"
BEG_C_DECLARATION

//================= ENDIAN ===========================================================================================================================

/*возвращает типа архитектуры*/
#define CURRENT_BYTE_ORDER              __BYTE_ORDER__

#define LIT_ENDIAN_BYTE_ORDER           __ORDER_LITTLE_ENDIAN__ //(0x04030201)
#define BIG_ENDIAN_BYTE_ORDER           __ORDER_BIG_ENDIAN__    //(0x01020304)
#define MID_LIT_ENDIAN_BYTE_ORDER       __ORDER_PDP_ENDIAN__    //(0x02010403)
#define MID_BIG_ENDIAN_BYTE_ORDER       (0x03040102)            //(0x03040102)

#define IS_CURRENT_BYTE_ORDER(ORDER)    (CURRENT_BYTE_ORDER == (ORDER))

//====================================================================================================================================================

END_C_DECLARATION
// clang-format on
#endif /*YAYA_ENDIAN_H*/
