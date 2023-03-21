//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_ENDIAN_H
#define YAYA_ENDIAN_H

#include "yaya_cdeclaration.h"
BEG_C_DECLARATION

/*возвращает типа архитектуры*/
#define CURRENT_BYTE_ORDER     (*(int *)"\x01\x02\x03\x04")
#define LIT_ENDIAN_BYTE_ORDER  0x04030201
#define BIG_ENDIAN_BYTE_ORDER  0x01020304
#define PDP_ENDIAN_BYTE_ORDER  0x02010403

#define IS_LIT_ENDIAN    (CURRENT_BYTE_ORDER == LIT_ENDIAN_BYTE_ORDER)
#define IS_BIG_ENDIAN    (CURRENT_BYTE_ORDER == BIG_ENDIAN_BYTE_ORDER)
#define IS_PDP_ENDIAN    (CURRENT_BYTE_ORDER == PDP_ENDIAN_BYTE_ORDER)

/*возвращает типа архитектуры*/
#define ENDIAN_BIT() (((union { unsigned x; unsigned char c; }){1}).c)

#define ENDIAN_BIG 0
#define ENDIAN_LIT 1

END_C_DECLARATION
#endif /*YAYA_ENDIAN_H*/
