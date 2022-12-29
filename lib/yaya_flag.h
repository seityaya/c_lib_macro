//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2022 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_FLAG_H
#define YAYA_FLAG_H

#define FLAG_SET(x)    (((x) == 0) ? (0ULL) : (1ULL << ((x) - 1ULL)))  //установка флага
#define FLAG_COM(x, y) ((x) & (y))                                     //сравнение двух флагов или масок
#define FLAG_ALL       (((0ULL) - 1))                                  //выставление всех флагов
#define FLAG_NUL       (0)                                             //сброс всех флагов

#endif /*YAYA_FLAG_H*/
