// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// Creation Date          : 2023.02
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_RAND_H
#define YAYA_RAND_H

#include "yaya_cdeclaration.h"
BEG_C_DECLARATION

#include "math.h"

#include "yaya_chek.h"
#include "yaya_number.h"
#include "yaya_sugar.h"
#include "yaya_type.h"
#include "yaya_arithmetic.h"

//= ОПРЕДЕЛЕНИЕ ФУНКЦИЙ ==============================================================================================================================

fmax_t __get_rand_normal(fmax_t mu, fmax_t sigma);
fmax_t __get_rand_beta(fmax_t a, fmax_t b);

//= СЛУЧАЙНЫЕ ВЕЛИЧИНЫ И РАСПРЕДЕЛЕНИЯ ===============================================================================================================

/*
 * Подключение функций генерации ГСПЧ
*/
extern void srand(unsigned int __seed);
extern int  rand (void);
extern umax_t __rand_seed;

/*
 * Установка начального значения ГСПЧ
*/
#define set_seed(s)                                                                                                                                  \
    BLOC(as(__rand_seed, (s));                                                                                                                       \
    srand(typecast(unsigned int, __rand_seed)))

/*
 * Возврат текущего значения ГСПЧ
*/
#define get_seed()                                                                                                                                   \
    BLOC(__rand_seed)

/*
 * Возврат случайного целочисленного значения от 0 до RAND_MAX
*/
#define get_random()                                                                                                                                 \
    BLOC(__rand_seed = typecast(umax_t, rand()); __rand_seed)

/*
 * Возврат случайного целочисленного значения в установленых интервалах включительно
*/
#define __get_rand(min, max) __sum(__mod(typecast(max, get_random()), __sum(__dis(min, max), next_num(min))), min)
#define get_rand(min, max)                                                                                                                           \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG(min, max, _min_r, _max_r,                                                                                                             \
    BLOC(__get_rand(_min_r, _max_r))))

/*
 * Возврат случайного значения в промежутке с шагом от min к max включительно
*/
#define __get_rand_mms(min, max, step) __sum(__mul(__mod(get_random(), __div(__sum(__dis(min, max), step), step)), step), min)
#define get_rand_mms(min, max, step)                                                                                                                 \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_3(min, max, step _min, _max, _step,                                                                                               \
    BLOC(__get_rand_mms(_min, _max, _step))))

/*
 * Возврат случайного значения в промежутке с количеством шагов между min и max включительно
*/
#define __get_rand_mmc(min, max, count) __sum(__mul(__mod(typecast(count, get_random()), __sum(count, one(count))), __div(__dis(min, max), count)), min)
#define get_rand_mmc(min, max, count)                                                                                                                \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_3(min, max, count _min, _max, _count,                                                                                             \
    BLOC(__get_rand_mmc(_min, _max, _count))))

/*
 * Нормальное распределение Гаусса
*/
#define __get_rand_normal(mu, sigma) __get_rand_normal(mu, sigma)
#define get_rand_normal(mu, sigma)                                                                                                                   \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_GROUP(STD_TYPE_GROUP_FLT, mu, sigma, _mu, _sigma,                                                                                 \
    BLOC(__get_rand_normal(_mu, _sigma))))

/*
 * Бета-распределение
*/
#define __get_rand_beta(a, b) __get_rand_beta(a, b)
#define get_rand_beta(a, b)                                                                                                                          \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_GROUP(STD_TYPE_GROUP_FLT, a, b, _a, _b,                                                                                           \
    BLOC(__get_rand_beta(_a, _b))))

//====================================================================================================================================================

END_C_DECLARATION
#endif /* YAYA_RAND_H */
