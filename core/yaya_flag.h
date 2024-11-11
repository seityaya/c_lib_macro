// Author                 : Seityagiya Terlekchi
// Contacts               : terlekchiseityaya@gmail.com
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2024 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_FLAG_H
#define YAYA_FLAG_H

#include "yaya_bool.h"

// clang-format off
#include "yaya_cdecl.h"
BEG_C_DECLARATION

//================= Операции с флагами ===============================================================================================================
/*
* Flag
*/
#define flag_all(x)                 ((x) = base_type_cast((x), (base_type_cast((x), (0)) - base_type_cast((x), (1)))))      //выставление всех флагов
#define flag_clr(x)                 ((x) = 0)                                                                               //сброс всех флагов

#define flag_set_pos(value, bit)    ((value) | ((1) << (bit)))                                                              //установка флага
#define flag_res_pos(value, bit)    ((value) & base_type_cast((value), ~((1) << (bit))))
#define flag_tog_pos(value, bit)    ((value) ^ ((1) << (bit)))
#define flag_chk_pos(value, bit)    (base_type_cast(bool_t, ((value) >> (bit)) & 0x01))

#define flag_crt_mask(a, ...)
#define flag_set_mask(value, mask)  ((value) |  (mask))
#define flag_res_mask(value, mask)  ((value) & ~(mask)))
#define flag_tog_mask(value, mask)  ((value) ^  (mask))
#define flag_chk_mask(value, mask)  ((value) == (mask))

//====================================================================================================================================================

END_C_DECLARATION
// clang-format on
#endif /*YAYA_FLAG_H*/
