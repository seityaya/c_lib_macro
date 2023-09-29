// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_RAND_H
#define YAYA_RAND_H

#include "math.h"

#include "yaya_arithmetic.h"
#include "yaya_check.h"
#include "yaya_sugar.h"
#include "yaya_type.h"

// clang-format off
#include "yaya_cdecl.h"
BEG_C_DECLARATION

//================= ОПРЕДЕЛЕНИЕ ФУНКЦИЙ ==============================================================================================================

fmax_t __get_rand_normal(fmax_t mu, fmax_t sigma);
fmax_t __get_rand_beta(fmax_t a, fmax_t b);

/*
 * Подключение функций генерации ГСПЧ
*/
extern void   srand(unsigned int __seed);    /* TODO */
extern int    rand (void);                   /* TODO */
extern umax_t __rand_seed;

#define RANDOM_MIN umax_c(0)
#define RANDOM_MAX umax_c(2147483647)

//================= СЛУЧАЙНЫЕ ВЕЛИЧИНЫ И РАСПРЕДЕЛЕНИЯ ===============================================================================================
/*
 * Установка начального значения ГСПЧ
*/
#define set_seed(s)                                                                                                                                  \
    BLOCK(__as(__rand_seed, (s));                                                                                                                    \
    srand(base_type_cast(unsigned int, __rand_seed)))

#define __set_seed(s) \
    ___set_seed(s)

/*
 * Возврат текущего значения ГСПЧ
*/
#define get_seed()                                                                                                                                   \
    BLOCK(__rand_seed)

/*
 * Возврат случайного целочисленного значения от 0 до RAND_MAX
*/
#define get_random()                                                                                                                                 \
    BLOCK(__as(__rand_seed, base_type_cast(umax_t, rand())); __rand_seed)

/*
 * Возврат случайного целочисленного значения в установленых интервалах включительно
*/
#define get_rand(min, max)                                                                                                                           \
    BLOCK(                                                                                                                                           \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC(min, max, _min_r, _max_r,                                                                                       \
    BLOCK(__get_rand(_min_r, _max_r))))

#define __get_rand(min, max)                                                                                                                         \
    BLOCK(                                                                                                                                           \
    UNIT(COMPILE_GROUP_CHECK(BASE_TYPE_GROUP_CHAR | BASE_TYPE_GROUP_SINT | BASE_TYPE_GROUP_UINT, min)) ?                                             \
    BLOCK(__get_rand_int(COMPILE_INT_VAR_OR_ZERO(min), COMPILE_INT_VAR_OR_ZERO(max))) :                                                                      \
    BLOCK(__get_rand_flt(COMPILE_FLT_VAR_OR_ZERO(min), COMPILE_FLT_VAR_OR_ZERO(max))))

#define __get_rand_int(min, max) \
    base_type_cast(min, __sum(base_type_cast(min, __mod(get_random(), base_type_cast(umax_t, __sum(__dis(min, max), base_type_eps(max))))), min))

#define __get_rand_flt(min, max) \
    base_type_cast(min, __sum(base_type_cast(min, __qut(base_type_cast(fmax_t, get_random()), \
    base_type_cast(fmax_t, __qut(RANDOM_MAX, base_type_cast(umax_t, __dis(min, max)))))), min))

/*
 * Возврат случайного значения в промежутке с шагом от min к max включительно
*/
#define get_rand_mms(min, max, step)                                                                                                                 \
    BLOCK(                                                                                                                                           \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC(min, max, step, _min, _max, _step,                                                                              \
    BLOCK(__get_rand_mms(_min, _max, _step))))

#define __get_rand_mms(min, max, step) \
    __sum(__mul(__mod(base_type_cast(max, get_random()), __div(__sum(__dis(min, max), step), step)), step), min)

/*
 * Возврат случайного значения в промежутке с количеством шагов между min и max включительно
*/
#define get_rand_mmc(min, max, count)                                                                                                                \
    BLOCK(                                                                                                                                           \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC(min, max, count, _min, _max, _count,                                                                            \
    BLOCK(__get_rand_mmc(_min, _max, _count))))

#define __get_rand_mmc(min, max, count)                                                                                                              \
    __sum(__mul(__mod(base_type_cast(count, get_random()), count), __div(__dis(min, max), count)), min)

/*
 * Нормальное распределение Гаусса
*/
#define get_rand_normal(mu, sigma)                                                                                                                   \
    BLOCK(                                                                                                                                           \
    COMPILE_ASSERT_GROUP_MATCH_2_CALC(BASE_TYPE_GROUP_FLT, mu, sigma, _mu, _sigma,                                                                   \
    BLOCK(__get_rand_normal(_mu, _sigma))))

/*
 * Бета-распределение
*/
#define get_rand_beta(a, b)                                                                                                                          \
    BLOCK(                                                                                                                                           \
    COMPILE_ASSERT_GROUP_MATCH_2_CALC(BASE_TYPE_GROUP_FLT, a, b, _a, _b,                                                                             \
    BLOCK(__get_rand_beta(_a, _b))))

#define __get_rand_beta(a, b)                                                                                                                        \
    __get_rand_beta(a, b)

//====================================================================================================================================================

END_C_DECLARATION
// clang-format on
#endif /* YAYA_RAND_H */
