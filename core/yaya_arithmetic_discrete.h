// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_ARITHMETIC_DISCRETE_H
#define YAYA_ARITHMETIC_DISCRETE_H

#include "yaya_cdecl.h"
BEG_C_DECLARATION
// clang-format off

#include "malloc.h"
#include "math.h"
#include "stddef.h"
#include "tgmath.h"

#include "yaya_check.h"
#include "yaya_sugar.h"
#include "yaya_type.h"
#include "yaya_gover.h"

#include "yaya_arithmetic.h"



















umax_t ___primenum(umax_t x);
umax_t ___primenum_get(umax_t beg, umax_t end, umax_t* m[]);

umax_t ___primenum_buffering(umax_t x);
umax_t ___primenum_buffering_get(umax_t beg, umax_t end, umax_t* m[]);
umax_t ___primenum_buffering_free();


umax_t ___fibonacci(umax_t x);
umax_t ___fibonacci_get(umax_t beg, umax_t end, umax_t* m[]);

umax_t ___fibonacci_buffering(umax_t x);
umax_t ___fibonacci_buffering_get(umax_t beg, umax_t end, umax_t* m[]);
umax_t ___fibonacci_buffering_free();


umax_t ___factorial(umax_t x);
umax_t ___factorial_get(umax_t beg, umax_t end, umax_t* m[]);

umax_t ___factorial_buffering(umax_t x);
umax_t ___factorial_buffering_get(umax_t beg, umax_t end, umax_t* m[]);
umax_t ___factorial_free();


umax_t ___binomial(umax_t n, umax_t k);


umax_t ___divisors(umax_t n, umax_t* m[]);
umax_t ___primes(umax_t n, umax_t* m[]);

//----------------------------------------------------------------------------------------------------------------------------------------------------

/*
 * Возвращает n-e простое число
*/
#define primenum(n)                                                                                                                                  \
    BLOCK(                                                                                                                                           \
    COMPILE_ASSERT_TYPE_MATCH(umax_t, n);                                                                                                            \
    BLOCK(___primenum(n)))

/*
 * Возвращает n-e простое число, сохраняя результаты предыдущих поисков до n в скрытый буфер
 * Для освобождения памяти использовать функцию освобождения
*/
#define primenum_buffering(n) \
    ___primenum_buffering(n)

#define primenum_free()\
    ___primenum_free()

/*
 * Возвращает количество простых чисел от 1 до x
 * Заполняет массив простых чисел
 * После вызова необходимо вызвать free(m)
*/
#define primes(x, m)                                                                                                                                 \
    BLOCK(                                                                                                                                            \
    COMPILE_ASSERT_TYPE_MATCH(umax_t, x);                                                                                                                 \
    BLOCK(___primes(x, m)))

/*
 * Возвращает n-e число Фибоначчи
*/
#define fibonacci(n)                                                                                                                                 \
    BLOCK(                                                                                                                                            \
    COMPILE_ASSERT_TYPE_MATCH(umax_t, n);                                                                                                                 \
    BLOCK(___fibonacci(n)))                                                                                                                           \

/*
 * Возвращает n-e число Фибоначчи, сохраняя результаты предыдущих поисков до n в скрытый буфер
 * Для освобождения памяти использовать функцию освобождения
*/
#define fibonacci_buffering(n)

#define fibonacci_free()

/*
 * Возвращает n-e число факториала
*/
#define factorial(n)                                                                                                                                 \
    BLOCK(                                                                                                                                            \
    COMPILE_ASSERT_TYPE_MATCH(umax_t, n);                                                                                                                 \
    BLOCK(___factorial(n)))

/*
 * Возвращает n-e число факториала, сохраняя результаты предыдущих поисков до n в скрытый буфер
 * Для освобождения памяти использовать функцию освобождения
*/
#define factorial_buffering(n)

#define factorial_free()

/*
 * Возвращает n-e число субфакториала
*/
#define subfactorial(n)                                                                                                                              \
    BLOCK(                                                                                                                                            \
    COMPILE_ASSERT_TYPE_MATCH(umax_t, n);                                                                                                                 \
    BLOCK(___subfactorial(n))) //TODO

/*
 * Возвращает n-e число субфакториала, сохраняя результаты предыдущих поисков до n в скрытый буфер
 * Для освобождения памяти использовать функцию освобождения
*/
#define subfactorial_buffering(n)

#define subfactorial_free()

/*
 * Возвращает n-e число на k-й позиции, бинома Ньютона
*/
#define binomial(n, k)                                                                                                                               \
    BLOCK(                                                                                                                                            \
    COMPILE_ASSERT_TYPE_MATCH(umax_t, n);                                                                                                                 \
    COMPILE_ASSERT_TYPE_MATCH(umax_t, k);                                                                                                                 \
    BLOCK(___binomial(n, k)))

/*
 * Возвращает n-e число на k-й позиции, бинома Ньютона, сохраняя результаты предыдущих поисков до n в скрытый буфер
 * Для освобождения памяти использовать функцию освобождения
*/
#define binomial_buffering(n)

#define binomial_free()

/*
 * Возвращает количество делителей числа
 * Заполняет массив делителями числа
 * После вызова необходимо вызвать free()
*/
#define divisors(x, m)                                                                                                                               \
    BLOCK(                                                                                                                                            \
    COMPILE_ASSERT_TYPE_MATCH(umax_t, x);                                                                                                                 \
    BLOCK(___divisors(x, m)))

#define factorization(x, m)

//================= КОМБИНАТОРИКА ====================================================================================================================

umax_t ___permutation(umax_t n, const umax_t* m);
umax_t ___accommodation(umax_t n, umax_t k, bool_t f);
umax_t ___combination(umax_t n, umax_t k, bool_t f);

/*
 * Перестановка P_n
 * n - количество элементов, m - null
 * Перестановка с повторением `P_n_k
 * n - количество групп, m - массив, количество значений в каждой группе
*/
#define permutation(n, m)                                                                                                                            \
    BLOCK(                                                                                                                                            \
    COMPILE_ASSERT_TYPE_MATCH(umax_t, n);                                                                                                                 \
    BLOCK(___permutation(n, m)))

/*
 * Размещение A^n_k
 * n - количество элементов, k - различных элементов, f - false
 *
 * Размещение с повторением (выборка с возвращением) `A^n_k
 * n - количество групп, k - различных элементов, f - true
*/
#define accommodation(n, k, f)                                                                                                                       \
    BLOCK(                                                                                                                                            \
    COMPILE_ASSERT_TYPE_MATCH(umax_t, n);                                                                                                                 \
    COMPILE_ASSERT_TYPE_MATCH(umax_t, k);                                                                                                                 \
    BLOCK(___accommodation(n, k, f)))

/*
 * Сочетание C^n_k
 * n - количество элементов, k - различных элементов, f - false
 *
 * Сочетание с повторением (сочетание с возвращением) `C^n_k
 * n - количество групп, k - различных элементов, f - true
*/
#define combination(n, k, f)                                                                                                                         \
    BLOCK(                                                                                                                                            \
    COMPILE_ASSERT_TYPE_MATCH(umax_t, n);                                                                                                                 \
    COMPILE_ASSERT_TYPE_MATCH(umax_t, k);                                                                                                                 \
    BLOCK(___combination(n, k, f)))







//================= ПРОГРЕССИИ =======================================================================================================================

/*
 * Вернуть n-й член арифметической прогрессии
 * a_n = a_1 + b * (n - 1), где - n = 0, 1, 2, ...
*/
#define progresion_arithmetic(a, b, n)                                                                                                               \
    BLOCK(                                                                                                                                            \
    COMPILE_NO_SIDE_EFFECT_VARIABLE(n, _n_ari);                                                                                                                      \
    COMPILE_ASSERT_GROUP_MATCH(BASE_TYPE_GROUP_SINT | BASE_TYPE_GROUP_UINT, _n_ari);                                                                        \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC(a, b, _a_ari, _b_ari,                                                                                                           \
    BLOCK(__progresion_arithmetic(_a_ari, _b_ari, _n_ari))))

#define __progresion_arithmetic(a, b, n)                                                                                                             \
    BLOCK(__sum(a, __mul(b, base_type_cast(b, n))))

/*
 * Проверить, что число соответствует арифметической прогрессии
*/
#define is_progresion_arithmetic(a, b, x)                                                                                                            \
    BLOCK(                                                                                                                                            \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC(a, b, x, _a_ari, _b_ari, _x_ari,                                                                                                \
    BLOCK(__is_progresion_arithmetic(_a_ari, _b_ari, _x_ari))))

#define __is_progresion_arithmetic(a, b, x)                                                                                                          \
    BLOCK(is_zero(__get_frc(__qut(__dif((x), (a)), (b)))))

/*
 * Вернуть n-й член геометрической прогрессии
 * b_n = b_1 * q ^ (n - 1), где - n = 0, 1, 2, ...
*/
#define progresion_geometric(b, q, n)                                                                                                                \
    BLOCK(                                                                                                                                            \
    COMPILE_NO_SIDE_EFFECT_VARIABLE(n, _n_geo);                                                                                                                      \
    COMPILE_ASSERT_GROUP_MATCH(BASE_TYPE_GROUP_SINT | BASE_TYPE_GROUP_UINT, _n_geo);                                                                        \
    COMPILE_ASSERT_GROUP_MATCH_2_CALC(BASE_TYPE_GROUP_FLT, b, q, _b_geo, _q_geo,                                                                                 \
    BLOCK(__progresion_geometric(_b_geo, _q_geo, _n_geo))))

#define __progresion_geometric(b, q, n)                                                                                                              \
    BLOCK(__mul((b), __powm((q), base_type_cast(q, n))))

/*
 * Проверить, что число соответствует геометрической прогрессии
*/
#define is_progresion_geometric(b, q, x)                                                                                                             \
    BLOCK(                                                                                                                                            \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC(b, q, x, _b_geo, _q_geo, _x_geo,                                                                                                \
    BLOCK(__is_progresion_geometric(_b_geo, _q_geo, _x_geo))))

#define __is_progresion_geometric(b, q, x)                                                                                                           \
    BLOCK(is_zero(__get_frc(__logm(__qut((x), (b)), (q)))))

/*
 * Вернуть n-й член гармонической прогрессии
 * h_n = 1 / pr_ar(a, b, n), где n = 0, 1, 2, ...
*/
#define progresion_harmonic(a, b, n)                                                                                                                 \
    BLOCK(                                                                                                                                            \
    COMPILE_NO_SIDE_EFFECT_VARIABLE(n, _n_har);                                                                                                                      \
    COMPILE_ASSERT_GROUP_MATCH(BASE_TYPE_GROUP_SINT | BASE_TYPE_GROUP_UINT, _n_har);                                                                        \
    COMPILE_ASSERT_GROUP_MATCH_2_CALC(BASE_TYPE_GROUP_FLT, a, b, _a_har, _b_har,                                                                                 \
    BLOCK(__progresion_harmonic(_a_har, _b_har, _n_har))))

#define __progresion_harmonic(a, b, n)                                                                                                               \
    BLOCK(base_type_cast(a, __qut(one(fmax_t), base_type_cast(fmax_t, __progresion_arithmetic(a, b, n)))))

/*
 * Проверить, что число соответствует формуле  или гармоническая прогрессия
*/
#define is_progresion_harmonic(a, b, x)                                                                                                              \
    BLOCK(                                                                                                                                            \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC(a, b, x, _a_har, _b_har, _x_har,                                                                                                \
    BLOCK(__is_progresion_harmonic(_a_har, _b_har, _x_har))))

#define __is_progresion_harmonic(a, b, x)                                                                                                            \
    BLOCK(                                                                                                                                            \
    __ap(__get_frc(__qut(one(fmax_t) - __mul((x), (a)), __mul((x), (b)))), zero(fmax_t), 0.00001) ||                                                 \
    __ap(__get_frc(__qut(one(fmax_t) - __mul((x), (a)), __mul((x), (b)))),  one(fmax_t), 0.00001))


//====================================================================================================================================================

// clang-format on
END_C_DECLARATION
#endif /*YAYA_ARITHMETIC_DISCRETE_H*/
