//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_RAND_H
#define YAYA_RAND_H

#include "math.h"

#include "yaya_chek.h"
#include "yaya_number.h"
#include "yaya_sugar.h"
#include "yaya_type.h"
#include "yaya_arithmetic.h"

#include "yaya_cdeclaration.h"
BEG_C_DECLARATION

//= ОПРЕДЕЛЕНИЕ ФУНКЦИЙ ==============================================================================================================================

fmax_t __get_rand_normal(fmax_t mu, fmax_t sigma);
fmax_t __get_rand_beta(fmax_t a, fmax_t b);

//= СЛУЧАЙНЫЕ ВЕЛИЧИНЫ И РАСПРЕДЕЛЕНИЯ ===============================================================================================================

/*
 * Подключение функций генерации ГСПЧ
*/
extern void srand(unsigned int __seed);    /* TODO */
extern int  rand (void);                   /* TODO */
extern umax_t __rand_seed;

#define RANDOM_MIN umax_c(0)
#define RANDOM_MAX umax_c(2147483647)

/*
 * Установка начального значения ГСПЧ
*/
#define set_seed(s)                                                                                                                                  \
    BLOC(__as(__rand_seed, (s));                                                                                                                       \
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
    BLOC(__as(__rand_seed, rand()); __rand_seed)

/*
 * Возврат случайного целочисленного значения в установленых интервалах включительно
*/
#define get_rand(min, max)                                                                                                                           \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2(min, max, _min_r, _max_r,                                                                                                       \
    BLOC(__get_rand(_min_r, _max_r))))

#define __get_rand(min, max)                                                                                                                         \
    BLOC(                                                                                                                                            \
    UNIT(COMPILE_GROUPCHEK(STD_TYPE_GROUP_CHAR | STD_TYPE_GROUP_SINT | STD_TYPE_GROUP_UINT, min)) ?                                                  \
    BLOC(__get_rand_int(COMPILE_INT_OR_ZERO(min), COMPILE_INT_OR_ZERO(max))) :                                                                       \
    BLOC(__get_rand_flt(COMPILE_FLT_OR_ZERO(min), COMPILE_FLT_OR_ZERO(max))))

#define __get_rand_int(min, max) \
    typecast(min, __sum(typecast(min, __mod(get_random(), typecast(umax_t, __sum(__dis(min, max), typeeps(max))))), min))

#define __get_rand_flt(min, max) \
    typecast(min, __sum(typecast(min, __qut(typecast(fmax_t, get_random()), \
    typecast(fmax_t, __qut(RANDOM_MAX, typecast(umax_t, __dis(min, max)))))), min))

/*
 * Возврат случайного значения в промежутке с шагом от min к max включительно
*/
#define get_rand_mms(min, max, step)                                                                                                                 \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_3(min, max, step, _min, _max, _step,                                                                                              \
    BLOC(__get_rand_mms(_min, _max, _step))))

#define __get_rand_mms(min, max, step) \
    __sum(__mul(__mod(typecast(max, get_random()), __div(__sum(__dis(min, max), step), step)), step), min)

/*
 * Возврат случайного значения в промежутке с количеством шагов между min и max включительно
*/
#define get_rand_mmc(min, max, count)                                                                                                                \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_3(min, max, count, _min, _max, _count,                                                                                            \
    BLOC(__get_rand_mmc(_min, _max, _count))))

#define __get_rand_mmc(min, max, count)                                                                                                              \
    __sum(__mul(__mod(typecast(count, get_random()), count), __div(__dis(min, max), count)), min)

/*
 * Нормальное распределение Гаусса
*/
#define get_rand_normal(mu, sigma)                                                                                                                   \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_GROUP_2(STD_TYPE_GROUP_FLT, mu, sigma, _mu, _sigma,                                                                               \
    BLOC(__get_rand_normal(_mu, _sigma))))

/*
 * Бета-распределение
*/
#define get_rand_beta(a, b)                                                                                                                          \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_GROUP_2(STD_TYPE_GROUP_FLT, a, b, _a, _b,                                                                                         \
    BLOC(__get_rand_beta(_a, _b))))

#define __get_rand_beta(a, b)                                                                                                                        \
    __get_rand_beta(a, b)

//====================================================================================================================================================

END_C_DECLARATION

#endif /* YAYA_RAND_H */
