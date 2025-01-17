// Author                 : Seityagiya Terlekchi
// Contacts               : terlekchiseityaya@gmail.com
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2025 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_FLAG_H
#define YAYA_FLAG_H

#include "yaya_argcount.h"
#include "yaya_bool.h"
#include "yaya_type.h"

// clang-format off
#include "yaya_cdecl.h"
BEG_C_DECLARATION

//================= Операции с флагами ===============================================================================================================
/*
 * Flag
 */

#define flag_clr()                 (0)
#define flag_all(type)             (base_type_cast(type, 0) - base_type_cast(type, 1))

#define flag_set_pos(value, bit)   ((value) | base_type_cast((value), ((1) << (bit))))
#define flag_res_pos(value, bit)   ((value) & base_type_cast((value), ~((1) << (bit))))
#define flag_tog_pos(value, bit)   ((value) ^ base_type_cast((value), ((1) << (bit))))
#define flag_chk_pos(value, bit)   (base_type_cast(bool_t, ((value) >> (bit)) & base_type_cast((value), (1))))

#define flag_set_mask(value, mask) ((value) |  (mask))
#define flag_res_mask(value, mask) ((value) & ~(mask))
#define flag_tog_mask(value, mask) ((value) ^  (mask))
#define flag_chk_mask(value, mask) ((value) == (mask))

//====================================================================================================================================================

END_C_DECLARATION
// clang-format on
#endif /*YAYA_FLAG_H*/
