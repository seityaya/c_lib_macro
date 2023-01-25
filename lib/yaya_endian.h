//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_ENDIAN_H
#define YAYA_ENDIAN_H

/*возвращает типа архитектуры*/
#define ENDIAN_BIT() (((union { unsigned x; unsigned char c; }){1}).c)

#define ENDIAN_BIG 0
#define ENDIAN_LIT 1

#endif /*YAYA_ENDIAN_H*/
