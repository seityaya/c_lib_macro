// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_ARITHMETIC_H
#define YAYA_ARITHMETIC_H

#include "yaya_cdeclaration.h"
BEG_C_DECLARATION

#include "math.h"
#include "stddef.h"
#include "malloc.h"

#include "yaya_chek.h"
#include "yaya_number.h"
#include "yaya_sugar.h"
#include "yaya_type.h"

/*
 * Библиотека создавалась с целью, определить единый математический интерфейс для работы с
 * числами целого типа, чисел с плавающей точкой и комплексных чисел.
 * Покрыть базовые потребности в простейших математических операциях определенных для всех типов.
 * Праверка соответствия типов ставится на первое место.
 */

//= ОПРЕДЕЛЕНИЕ ФУНКЦИЙ ==============================================================================================================================

umax_t ___gcd(umax_t u, umax_t v);
umax_t ___lcm(umax_t u, umax_t v);
bool_t ___is_prime(umax_t x);
umax_t ___primenum(umax_t x);
umax_t ___fibonacci(umax_t x);
umax_t ___factorial(umax_t x);
umax_t ___binomial(umax_t n, umax_t k);
umax_t ___divisors(umax_t n, umax_t* m[]);
umax_t ___primes(umax_t n, umax_t* m[]);
umax_t ___permutation(umax_t n, const umax_t* m);
umax_t ___accommodation(umax_t n, umax_t k, bool_t f);
umax_t ___combination(umax_t n, umax_t k, bool_t f);

char   ___abs_char(char   x);
is8_t  ___abs_is8 (is8_t  x);
is16_t ___abs_is16(is16_t x);
is32_t ___abs_is32(is32_t x);
is64_t ___abs_is64(is64_t x);
us8_t  ___abs_us8 (us8_t  x);
us16_t ___abs_us16(us16_t x);
us32_t ___abs_us32(us32_t x);
us64_t ___abs_us64(us64_t x);

char   ___pow_char(char   x, char   p);
is8_t  ___pow_is8 (is8_t  x, is8_t  p);
is16_t ___pow_is16(is16_t x, is16_t p);
is32_t ___pow_is32(is32_t x, is32_t p);
is64_t ___pow_is64(is64_t x, is64_t p);
us8_t  ___pow_us8 (us8_t  x, us8_t  p);
us16_t ___pow_us16(us16_t x, us16_t p);
us32_t ___pow_us32(us32_t x, us32_t p);
us64_t ___pow_us64(us64_t x, us64_t p);

char   ___copysign_char(char   r, char   s);
is8_t  ___copysign_is8 (is8_t  r, is8_t  s);
is16_t ___copysign_is16(is16_t r, is16_t s);
is32_t ___copysign_is32(is32_t r, is32_t s);
is64_t ___copysign_is64(is64_t r, is64_t s);
us8_t  ___copysign_us8 (us8_t  r, us8_t  s);
us16_t ___copysign_us16(us16_t r, us16_t s);
us32_t ___copysign_us32(us32_t r, us32_t s);
us64_t ___copysign_us64(us64_t r, us64_t s);

//================= КОНСТАНТЫ ========================================================================================================================

/*
 * Положительный ноль,
 * соответствующий типу с которым сравнивают или присваивают
 * Принимает:
 * Возвращает:
*/
#define zero(type_t)                                                                                                                                 \
    BLOC(typecast(type_t, 0))

/*
 * Положительная единица
*/
#define one(type_t)                                                                                                                                  \
    BLOC(typecast(type_t, 1))

/*
 * Бесконечность
*/
#define inf(type_t)                                                                                                                                  \
    BLOC(typecast(type_t, INFINITY))

/*
 * Не число
*/
#define nan(type_t)                                                                                                                                  \
    BLOC(typecast(type_t, NAN))

//================= БАЗОВЫЕ УНАРНЫЕ ОПЕРАЦИИ =========================================================================================================

/*
 * Унарный постфиксный инкремент
*/
#define post_add(x)                                                                                                                                  \
    BLOC((x)++)

/*
 * Унарный постфиксный декремент
*/
#define post_dif(x)                                                                                                                                  \
    BLOC((x)--)

/*
 * Унарный префиксный инкремент
*/
#define pref_add(x)                                                                                                                                  \
    BLOC(++(x))

/*
 * Унарный префиксный декремент
*/
#define pref_dif(x)                                                                                                                                  \
    BLOC(--(x))

//================= БАЗОВЫЕ ОПЕРАЦИИ СРАВНЕНИЯ =======================================================================================================

/*
 * Сравнение на равенство
 * Equality
*/
#define eq(x, y)                                                                                                                                     \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_eq, _y_eq,                                                                                                         \
    BLOC(__eq(_x_eq, _y_eq))))

#define __eq(x, y)                                                                                                                                   \
    BLOC((x) == (y))

/*
 * Сравнение на неравенство
 * inequality
*/
#define nq(x, y)                                                                                                                                     \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_nq, _y_nq,                                                                                                         \
    BLOC(__nq(_x_nq, _y_nq))))

#define __nq(x, y)                                                                                                                                   \
    BLOC((x) != (y))

/*
 * Больше
 * greater then
*/
#define gt(x, y)                                                                                                                                     \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_gt, _y_gt,                                                                                                         \
    BLOC(__gt(_x_gt, _y_gt))))

#define __gt(x, y)                                                                                                                                   \
    BLOC((x) > (y))

/*
 * Меньше
 * less then
*/
#define lt(x, y)                                                                                                                                     \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_lt, _y_lt,                                                                                                         \
    BLOC(__lt(_x_lt, _y_lt))))

#define __lt(x, y)                                                                                                                                   \
    BLOC((x) < (y))

/*
 * Больше или равно
 * equality or greater then
*/
#define ge(x, y)                                                                                                                                     \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_ge, _y_ge,                                                                                                         \
    BLOC(__ge(_x_ge, _y_ge))))

#define __ge(x, y)                                                                                                                                   \
    BLOC((x) >= (y))

/*
 * Меньше или равно
 * equality or less then
*/
#define le(x, y)                                                                                                                                     \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_le, _y_le,                                                                                                         \
    BLOC(__le(_x_le, _y_le))))

#define __le(x, y)                                                                                                                                   \
    BLOC((x) <= (y))

/*
 * Примерное равно
 * approximation
*/
#define ap(x, y, e)                                                                                                                                  \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_3((x), (y), (e), _x_ap, _y_ap, _e_ap,                                                                                             \
    BLOC(__ap(_x_ap, _y_ap, _e_ap))))

#define __ap(x, y, e)                                                                                                                                \
    BLOC(__le(__abs(__dif((x), (y))), (e)))

//================= ПРОВЕРКА ЧИСЕЛ НА СООТВЕТСТВИЕ ===================================================================================================

/*
 * Проверка, что число положительное, но не ноль
*/
#define is_pos(x)                                                                                                                                    \
    BLOC(__gt((x), zero(x)))

/*
 * Проверка, что число отрицательное, но не ноль
*/
#define is_neg(x)                                                                                                                                    \
    BLOC(__lt((x), zero(x)))

/*
 * Проверка, что число ноль
*/
#define is_zero(x)                                                                                                                                   \
    BLOC(__eq((x), zero(x)))

/*
 * Проверка, что число положительное или ноль
*/
#define is_pos_or_zero(x)                                                                                                                            \
    BLOC(__ge((x), zero(x)))

/*
 * Проверка, что число отрицательное или ноль
*/
#define is_neg_or_zero(x)                                                                                                                            \
    BLOC(__le((x), zero(x)))

/*
 * Проверка, что число не ноль
*/
#define is_not_zero(x)                                                                                                                               \
    BLOC(__nq((x), zero(x)))

/*
 * Является ли число конечным
*/
#define is_fin(a)                                                                                                                                    \
    BLOC(isfinite(a))

/*
 * Является ли число «не числом» NaN
*/
#define is_nan(a)                                                                                                                                    \
    BLOC(isnan(a))

/*
 * Является ли число бесконечно большим
*/
#define is_inf(a)                                                                                                                                    \
    BLOC(isinf(a))

/*
 * Является ли число конечным, нормализованным числом отличным от нуля
*/
#define is_nor(a)                                                                                                                                    \
    BLOC(isnormal(a))

/*
 * Является ли число конечным, не нормализованным числом отличным от нуля
*/
#define is_sub(a)                                                                                                                                    \
    BLOC(__eq(fpclassify(a), FP_SUBNORMAL))

/*
 * Классифицирует  число в одну из 5 категорий
*/
#define fp_classify(a)                                                                                                                               \
    BLOC(fpclassify(a))

/*
 * Проверка, что целое число четное
*/
#define is_even(x)                                                                                                                                   \
    BLOC(                                                                                                                                            \
    COMPILE_GROUPMATCH_EQ(STD_TYPE_GROUP_CHAR | STD_TYPE_GROUP_SINT | STD_TYPE_GROUP_UINT, (x));                                                     \
    BLOC(__eq(__mod_int((x), typecast((x), (2))), zero(x))))

/*
 * Проверка, что целое число нечетное
*/
#define is_odd(x)                                                                                                                                    \
    BLOC(                                                                                                                                            \
    COMPILE_GROUPMATCH_EQ(STD_TYPE_GROUP_CHAR | STD_TYPE_GROUP_SINT | STD_TYPE_GROUP_UINT, (x));                                                     \
    BLOC(__nq(__mod_int((x), typecast((x), (2))), zero(x))))

/*
 * Проверка, что целое число простое
*/
#define is_prime(x)                                                                                                                                  \
    BLOC(                                                                                                                                            \
    COMPILE_GROUPMATCH_EQ(STD_TYPE_GROUP_CHAR | STD_TYPE_GROUP_SINT | STD_TYPE_GROUP_UINT, (x));                                                     \
    BLOC(___is_prime(typecast(umax_t, (x)))))

//================= БАЗОВЫЕ ОПЕРАЦИИ ПРИСВАИВАНИЯ ====================================================================================================

/*
 * Присваивание
 * Assignment
*/
#define as(dst, src)                                                                                                                                 \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((dst), (src), _dst_as, _src_as,                                                                                                 \
    BLOC(__as((dst), (_src_as)))))

#define __as(dst, src)                                                                                                                               \
    BLOC((dst) = typecast((dst), (src)))

/*
 * Обмен
 * Exchange
*/
#define swap(x, y)                                                                                                                                   \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_swap, _y_swap,                                                                                                     \
    BLOC(__as(x, _y_swap); __as(y, _x_swap))))

#define __swap(x, y)                                                                                                                                 \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE((x), _x_swap);                                                                                                                   \
    COMPILE_NO_SIDE((y), _y_swap);                                                                                                                   \
    BLOC(__as(x, _y_swap); __as(y, _x_swap)))

//================= ЧАСТИ ВЕЩЕСТВЕНЫХ И КОМПЛЕКСНЫХ ЧИСЕЛ ============================================================================================

/*
 * Взятие целого
 * Принимает:  Число типа Х
 * Возвращает: Целую часть числа типа Х, без потери знака
*/
#define get_int(x)                                                                                                                                   \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE((x), _x_int);                                                                                                                    \
    COMPILE_GROUPMATCH_NQ(STD_TYPE_GROUP_COMPLEX, _x_int);                                                                                           \
    BLOC(__get_int(_x_int)))

#define __get_int(x)                                                                                                                                 \
    BLOC(                                                                                                                                            \
    UNIT(eq(std_type_sigum(x), STD_TYPE_SIGNUM)) ?                                                                                                   \
    BLOC(typecast((x), typecast(imax_t, (x))))   :                                                                                                   \
    BLOC(typecast((x), typecast(umax_t, (x)))))

/*
 * Взятие дробного
 * Принимает:  Число типа Х
 * Возвращает: Дробную числа типа Х
*/
#define get_rem(x)                                                                                                                                   \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE((x), _x_rem);                                                                                                                    \
    COMPILE_GROUPMATCH_NQ(STD_TYPE_GROUP_COMPLEX, _x_rem);                                                                                           \
    BLOC(__get_rem(_x_rem)))

#define __get_rem(x)                                                                                                                                 \
    BLOC(typecast((x), __dif((x), __get_int(x))))

/*
 * Вещественная часть числа
 * Принимает:  Число типа complex
 * Возвращает: Вещественную часть числа типа X
*/
#define get_real(x)                                                                                                                                  \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE((x), _x_real);                                                                                                                   \
    COMPILE_GROUPMATCH_EQ(STD_TYPE_GROUP_COMPLEX, _x_real);                                                                                          \
    BLOC(__get_real(_x_real)))

#define __get_real(x)                                                                                                                                \
    BLOC(                                                                                                                                            \
    _Generic(x,                                                                                                                                      \
    float complex: crealf,                                                                                                                           \
    double complex: creal,                                                                                                                           \
    long double complex: creall,                                                                                                                     \
    default: 0)(x))

/*
 * Мнимая часть числа
 * Принимает:  Число типа complex
 * Возвращает: Мнимую часть числа типа X
*/
#define get_imag(x)                                                                                                                                  \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE((x), _x_imag);                                                                                                                   \
    COMPILE_GROUPMATCH_EQ(STD_TYPE_GROUP_COMPLEX, _x_imag);                                                                                          \
    BLOC(__get_imag(_x_imag)))

#define __get_imag(x)                                                                                                                                \
    BLOC(                                                                                                                                            \
    _Generic(x,                                                                                                                                      \
    float complex: cimagf,                                                                                                                           \
    double complex: cimag,                                                                                                                           \
    long double complex: cimagl,                                                                                                                     \
    default: 0)(x))

//================= РАЗЛОЖЕНИЕ ВЕЩЕСТВЕНОГО ЧИСЛА НА СОСТАВЛЯЮЩИЕ ==== S*M*B^E =======================================================================

/*
 * Знак числа
 * Signum
 * Принимает:  Число типа X
 * Возвращает: Тип X
 * -1 - если отрицательное
 * +1 - если положительное
 *  0 - если у значения не удаётся определить знак
*/
#define get_sign(x)                                                                                                                                  \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE(x, _x_sign);                                                                                                                     \
    COMPILE_GROUPMATCH_EQ(STD_TYPE_GROUP_CHAR | STD_TYPE_GROUP_SINT | STD_TYPE_GROUP_UINT | STD_TYPE_GROUP_FLT, _x_sign);                            \
    BLOC(__get_sign(_x_sign)))

#define __get_sign(x) BLOC(COMPILE_NO_SIDE(one(x), _y); _y = ___get_sign(_y, _x_sign); _y)
#define ___get_sign(x, y)                                                                                                                            \
    BLOC(                                                                                                                                            \
    _Generic(x,                                                                                                                                      \
    char                : ___copysign_char,                                                                                                          \
    is8_t               : ___copysign_is8 ,                                                                                                          \
    is16_t              : ___copysign_is16,                                                                                                          \
    is32_t              : ___copysign_is32,                                                                                                          \
    is64_t              : ___copysign_is64,                                                                                                          \
    us8_t               : ___copysign_us8 ,                                                                                                          \
    us16_t              : ___copysign_us16,                                                                                                          \
    us32_t              : ___copysign_us32,                                                                                                          \
    us64_t              : ___copysign_us64,                                                                                                          \
    float               : copysignf,                                                                                                                 \
    double              : copysign,                                                                                                                  \
    long double         : copysignl,                                                                                                                 \
    default: 0)(x, y))

/*
 * Мантисса числа по основанию 2
 * Принимает:  Число типа floating
 * Возвращает: Тип floating
*/
#define get_mantissa(x)                                                                                                                              \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE(x, _x_mant);                                                                                                                     \
    COMPILE_GROUPMATCH_EQ(STD_TYPE_GROUP_FLT, _x_mant);                                                                                              \
    BLOC(__get_mantissa(_x_mant)))

#define __get_mantissa(x)                                                                                                                            \
    BLOC(                                                                                                                                            \
    int e;                                                                                                                                           \
    __abs(                                                                                                                                           \
    _Generic(x,                                                                                                                                      \
    float: frexpf,                                                                                                                                   \
    double: frexp,                                                                                                                                   \
    long double: frexpl,                                                                                                                             \
    default: 0)(x, &e)))

/*
 * Экспонента числа по основанию 2
 * Принимает:  Число типа floating
 * Возвращает: Тип imax_t
*/
#define get_exponent(x)                                                                                                                              \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE(x, _x_exp);                                                                                                                      \
    COMPILE_GROUPMATCH_EQ(STD_TYPE_GROUP_FLT, _x_exp);                                                                                               \
    __get_exponent(_x_exp))

#define __get_exponent(x)                                                                                                                            \
    BLOC(                                                                                                                                            \
    int e;                                                                                                                                           \
    _Generic(x,                                                                                                                                      \
    float: frexpf,                                                                                                                                   \
    double: frexp,                                                                                                                                   \
    long double: frexpl,                                                                                                                             \
    default: 0)(x, &e);                                                                                                                              \
    typecast(imax_t, e))

/*
 * Мантисса числа по основанию 10
 * Принимает:  Число типа floating
 * Возвращает: Тип floating
*/
#define get_mantissa10(x)                                                                                                                            \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE(x, _x_mant);                                                                                                                     \
    COMPILE_GROUPMATCH_EQ(STD_TYPE_GROUP_FLT, _x_mant);                                                                                              \
    BLOC(__get_mantissa10(_x_mant)))

#define __get_mantissa10(x)                                                                                                                          \
    BLOC(typecast(x, powm(typecast(x, 10.0), typecast(x, get_rem(logm(x, typecast(x, 10.0)))))))

/*
 * Экспонента числа по основанию 10
 * Принимает:  Число типа floating
 * Возвращает: Тип umax_t
*/
#define get_exponent10(x)                                                                                                                            \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE(x, _x_exp);                                                                                                                      \
    COMPILE_GROUPMATCH_EQ(STD_TYPE_GROUP_FLT, _x_exp);                                                                                               \
    __get_exponent10(_x_exp))

#define __get_exponent10(x)                                                                                                                          \
    BLOC(is_zero(x) ? zero(imax_t) : typecast(imax_t, round_dn(logm(__abs(x), typecast(x, 10.0)))))

//================= БАЗОВЫЕ МАТЕМАТИЧЕСКИЕ ОПЕРАЦИИ И ФУНКЦИИ ========================================================================================

/*
 * Сумма
 * Summa
 * Принимает:  Два числа типа Х
 * Возвращает: Сумму чисел типа Х
*/
#define sum(x, y)                                                                                                                                    \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_sum, _y_sum,                                                                                                       \
    BLOC(typecast(_x_sum, __sum(_x_sum, _y_sum)))))

#define __sum(x, y)                                                                                                                                  \
    BLOC((x) + (y))

/*
 * Сумма с проверкой
 * Возвращает true - если результат операции дает переполнение
*/
#define sum_chk(r, x, y)                                                                                                                             \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_3((r), (x), (y), _r_, _x_sum, _y_sum,                                                                                             \
    BLOC(__sum_chk((r), _x_sum, _y_sum))))

#define __sum_chk(r, x, y)                                                                                                                           \
    BLOC(                                                                                                                                            \
    UNIT(__sum_chk_overflow(x, y))             ?                                                                                                     \
    BLOC(__as(r,     zero(r)); true )          :                                                                                                     \
    BLOC(__as(r, __sum(x, y)); false))

#define __sum_chk_overflow(x, y)                                                                                                                     \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE((x), res);                                                                                                                       \
    __builtin_add_overflow(x, y, &res))

//----------------------------------------------------------------------------------------------------------------------------------------------------

/*
 * Разность
 * Difference
 * Принимает:  Два числа типа Х
 * Возвращает: Разность чисел типа Х
*/
#define dif(x, y)                                                                                                                                    \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_dif, _y_dif,                                                                                                       \
    BLOC(__dif(_x_dif, _y_dif))))

#define __dif(x, y)                                                                                                                                  \
    BLOC((x) - (y))

/*
 * Разность с проверкой
 * Возвращает true - если результат операции дает переполнение
*/
#define dif_chk(r, x, y)                                                                                                                             \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_3((r), (x), (y), _r_, _x_dif, _y_dif,                                                                                             \
    BLOC(__dif_chk((r), _x_dif, _y_dif))))

#define __dif_chk(r, x, y)                                                                                                                           \
    BLOC(                                                                                                                                            \
    UNIT(__dif_chk_overflow(x, y))             ?                                                                                                     \
    BLOC(__as(r,     zero(r)); true )          :                                                                                                     \
    BLOC(__as(r, __dif(x, y)); false))

#define __dif_chk_overflow(x, y)                                                                                                                     \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE((x), res);                                                                                                                       \
    __builtin_sub_overflow(x, y, &res))

//----------------------------------------------------------------------------------------------------------------------------------------------------

/*
 * Умножение
 * Multiplication
 * Принимает:  Два числа типа Х
 * Возвращает: Произведение чисел типа Х
*/
#define mul(x, y)                                                                                                                                    \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_mul, _y_mul,                                                                                                       \
    BLOC(__mul(_x_mul, _y_mul))))

#define __mul(x, y)                                                                                                                                  \
    BLOC((x) * (y))

/*
 * Умножение с проверкой
 * Возвращает true - если результат операции дает переполнение
*/
#define mul_chk(r, x, y)                                                                                                                             \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_3((r), (x), (y), _r_, _x_mul, _y_mul,                                                                                             \
    BLOC(__mul_chk((r), _x_mul, _y_mul))))

#define __mul_chk(r, x, y)                                                                                                                           \
    BLOC(                                                                                                                                            \
    UNIT(__mul_chk_overflow(x, y))             ?                                                                                                     \
    BLOC(__as(r,     zero(r)); true )          :                                                                                                     \
    BLOC(__as(r, __mul(x, y)); false))

#define __mul_chk_overflow(x, y)                                                                                                                     \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE((x), res);                                                                                                                       \
    __builtin_mul_overflow(x, y, &res))

//----------------------------------------------------------------------------------------------------------------------------------------------------

/*
 * Целое от деления или усеченное деление
 * При делении отбрасывается дробная часть, или просходит округление к нулю
 * Остаток вычислется функцией mod
 * Division
 * Принимает:  Два числа типа Х
 * Возвращает: Целое от целочисленного деления типа Х, без потери знака
*/
#define div(x, y)                                                                                                                                    \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_div, _y_div,                                                                                                       \
    BLOC(__div(_x_div, _y_div))))

#define __div(x, y)                                                                                                                                  \
    BLOC(                                                                                                                                            \
    UNIT(eq(std_type_sigum(x), STD_TYPE_SIGNUM))      ?                                                                                              \
    BLOC(typecast((x), typecast(imax_t, (x / y))))    :                                                                                              \
    BLOC(typecast((x), typecast(umax_t, (x / y)))))

/*
 * Целое от деления или усеченное деление с проверкой
 * Возвращает true - если результат операции дает переполнение или происходит деление на ноль
*/
#define div_chk(r, x, y)                                                                                                                             \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_3((r), (x), (y), _r_, _x_div, _y_div,                                                                                             \
    BLOC(__div_chk((r), _x_div, _y_div))))

#define __div_chk(r, x, y)                                                                                                                           \
    BLOC(                                                                                                                                            \
    UNIT(__div_chk_overflow(x, y))             ?                                                                                                     \
    BLOC(__as(r,     zero(r)); true )          :                                                                                                     \
    BLOC(__as(r, __div(x, y)); false))

#define __div_chk_overflow(x, y)                                                                                                                     \
    BLOC(                                                                                                                                            \
    UNIT(is_zero(y)) ? BLOC(true) :                                                                                                                  \
    BLOC((x == typemin(x)) && (y == -one(y))))

//----------------------------------------------------------------------------------------------------------------------------------------------------

/*
 * Остаток от деления
 * При взятии остатка знак остатка равен знаку делимого
 * Частное вычисляется функцией div
 * Remainder
 * Принимает:  Два числа типа Х
 * Возвращает: Остаток от целочисленного деления типа Х
*/
#define mod(x, y)                                                                                                                                    \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_mod, _y_mod,                                                                                                       \
    BLOC(__mod(_x_mod, _y_mod))))

#define __mod(x, y)                                                                                                                                  \
    BLOC(                                                                                                                                            \
    UNIT(COMPILE_GROUPCHEK(STD_TYPE_GROUP_CHAR | STD_TYPE_GROUP_SINT | STD_TYPE_GROUP_UINT, x)) ?                                                    \
    BLOC(__mod_int(COMPILE_INT_OR_ZERO(x), COMPILE_INT_OR_ZERO(y))) :                                                                                \
    BLOC(__mod_flt(COMPILE_FLT_OR_ZERO(x), COMPILE_FLT_OR_ZERO(y))))
#define __mod_int(x, y) BLOC((x) % (y))
#define __mod_flt(x, y) BLOC(typecast((x), ((x) - __get_int((x) / (y)) * (y))))

/*
 * Остаток от деления
 * Возвращает true - если результат операции дает переполнение или происходит взятие модуля от ноля
*/
#define mod_chk(r, x, y)                                                                                                                             \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_3((r), (x), (y), _r_mod_, _x_mod, _y_mod,                                                                                         \
    BLOC(__mod_chk(r, _x_mod, _y_mod))))

#define __mod_chk(r, x, y)                                                                                                                           \
    BLOC(                                                                                                                                            \
    UNIT(__mod_chk_overflow(x, y))             ?                                                                                                     \
    BLOC(__as(r,     zero(r)); true )          :                                                                                                     \
    BLOC(__as(r, __mod(x, y)); false))

#define __mod_chk_overflow(x, y)                                                                                                                     \
    BLOC(is_zero(y))

//----------------------------------------------------------------------------------------------------------------------------------------------------

/*
 * Полное деление
 * Quotient
 * Принимает:  Два числа типа Х
 * Возвращает: Частное типа fmax_t
*/
#define qut(x, y)                                                                                                                                    \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_qut, _y_qut,                                                                                                       \
    BLOC(__qut(_x_qut, _y_qut))))

#define __qut(x, y)                                                                                                                                  \
    BLOC(                                                                                                                                            \
    typecast(fmax_t, typecast(fmax_t, (x)) / typecast(fmax_t, (y))))

/*
 * Полное деление с проверкой
 * Возвращает true - если результат операции дает переполнение или происходит деление на ноль
*/
#define qut_chk(r, x, y)                                                                                                                             \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_qut, _y_qut,                                                                                                       \
    BLOC(__qut_chk((r), _x_qut, _y_qut))))

#define __qut_chk(r, x, y)                                                                                                                           \
    BLOC(                                                                                                                                            \
    UNIT(__qut_chk_overflow(x, y))             ?                                                                                                     \
    BLOC(__as(r,     zero(r)); true )          :                                                                                                     \
    BLOC(__as(r, __qut(x, y)); false))

#define __qut_chk_overflow(x, y)                                                                                                                     \
    BLOC(                                                                                                                                            \
    UNIT(is_zero(y)) ? BLOC(true) :                                                                                                                  \
    BLOC((x == typemin(x)) && (y == -one(y))))

//----------------------------------------------------------------------------------------------------------------------------------------------------

/*
 * Возведение в степень
 * Power
 * Принимает:  Два числа типа Х
 * Возвращает: Результат возведение в степень типа X
*/
#define powm(x, p)                                                                                                                                   \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (p), _x_pow, _p_pow,                                                                                                       \
    BLOC(__powm(_x_pow, _p_pow))))

#define __powm(x, p) BLOC(                                                                                                                           \
    _Generic((x),                                                                                                                                    \
    char                : _Generic((p), default : ___pow_char),                                                                                      \
    is8_t               : _Generic((p), default : ___pow_is8 ),                                                                                      \
    is16_t              : _Generic((p), default : ___pow_is16),                                                                                      \
    is32_t              : _Generic((p), default : ___pow_is32),                                                                                      \
    is64_t              : _Generic((p), default : ___pow_is64),                                                                                      \
    us8_t               : _Generic((p), default : ___pow_us8 ),                                                                                      \
    us16_t              : _Generic((p), default : ___pow_us16),                                                                                      \
    us32_t              : _Generic((p), default : ___pow_us32),                                                                                      \
    us64_t              : _Generic((p), default : ___pow_us64),                                                                                      \
    float               : _Generic((p), default : powf       ),                                                                                      \
    double              : _Generic((p), default : pow        ),                                                                                      \
    long double         : _Generic((p), default : powl       ),                                                                                      \
    float complex       : _Generic((p), default : cpowf      ),                                                                                      \
    long double complex : _Generic((p), default : cpowl      ),                                                                                      \
    double complex      : _Generic((p), default : cpow       ))                                                                                      \
    (x, p))

/*
 * Возведение в степень с проверкой
*/
#define powm_chk(r, x, y)                                                                                                                            \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_pow, _y_pow,                                                                                                       \
    BLOC(__pow_chk((r), _x_pow, _y_pow))))

#define __pow_chk(r, x, y)                                                                                                                           \
    BLOC(                                                                                                                                            \
    UNIT(__pow_chk_overflow(x, y))             ?                                                                                                     \
    BLOC(__as(r,     zero(r)); true )          :                                                                                                     \
    BLOC(__as(r, __pow(x, y)); false))

#define __pow_chk_overflow(x, y)                                                                                                                     \
    BLOC(true)                                 /* TODO IMPLEMENTATION */

//----------------------------------------------------------------------------------------------------------------------------------------------------

/*
 * Извлечение корня по основанию
 * Root
 * Принимает:  Два числа типа Х
 * Возвращает: Результат извлечение корня типа X
*/
#define root(x, r)                                                                                                                                   \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (r), _x_rot, _r_rot,                                                                                                       \
    BLOC(__root(_x_rot, _r_rot))))

#define __root(x, r)                                                                                                                                 \
    BLOC(                                                                                                                                            \
    __powm((x), typecast(x, (1.0 / r))))    /* TODO */

/*
 * Извлечение корня по основанию с проверкой
*/
#define root_chk(r, x, y)                                                                                                                            \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_rot, _y_rot,                                                                                                       \
    BLOC(__rot_chk((r), _x_rot, _y_rot))))

#define __rot_chk(r, x, y)                                                                                                                           \
    BLOC(                                                                                                                                            \
    UNIT(__rot_chk_overflow(x, y))             ?                                                                                                     \
    BLOC(__as(r,     zero(r)); true )          :                                                                                                     \
    BLOC(__as(r, __rot(x, y)); false))

#define __rot_chk_overflow(x, y)                                                                                                                     \
    BLOC(true)                                 /* TODO IMPLEMENTATION */

//----------------------------------------------------------------------------------------------------------------------------------------------------

/*
 * Логарифм числа по основанию
 * Logarithm
 * Принимает:  Два числа типа Х
 * Возвращает: Результат логарифмирования типа X
*/
#define logm(x, l)                                                                                                                                   \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (l), _x_log, _l_log,                                                                                                       \
    BLOC(__logm(_x_log, _l_log))))

#define __logm(x, l)                                                                                                                                 \
    BLOC(__log_flt(x) / __log_flt(l))          /* TODO */

#define __log_flt(x)                                                                                                                                 \
    BLOC(                                                                                                                                            \
    _Generic(x,                                                                                                                                      \
    float: logf,                                                                                                                                     \
    double: log,                                                                                                                                     \
    long double: logl,                                                                                                                               \
    float complex: clogf,                                                                                                                            \
    double complex: clog,                                                                                                                            \
    long double complex: clogl,                                                                                                                      \
    default: 0)(x))                            /* TODO */

/*
 * Логарифм числа по основанию с проверкой
*/
#define logm_chk(r, x, y)                                                                                                                            \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_log, _y_log,                                                                                                       \
    BLOC(__log_chk((r), _x_log, _y_log))))

#define __log_chk(r, x, y)                                                                                                                           \
    BLOC(                                                                                                                                            \
    UNIT(__log_chk_overflow(x, y))             ?                                                                                                     \
    BLOC(__as(r,     zero(r)); true )          :                                                                                                     \
    BLOC(__as(r, __log(x, y)); false))

#define __log_chk_overflow(x, y)                                                                                                                     \
    BLOC(true)                                 /* TODO IMPLEMENTATION */

//----------------------------------------------------------------------------------------------------------------------------------------------------

/*
 * Обратные величины
 * Z ÷ a = b -> div(Z, a) ~> div(b, Z) || mul(a, b)
 * Z / a = b -> qut(Z, a) ~> qut(b, Z) || mul(a, b)
 * X ^ Y = Z -> pow(X, Y) ~> log(Z, X) || rot(Z, Y)
 * Y √ Z = X -> rot(Z, Y) ~> pow(X, Y) || log(Z, X)
 * Z _ X = Y -> log(Z, X) ~> rot(Y, Z) || pow(X, Y)
*/

//================= ДОПОЛНИТЕЛЬНЫЕ МАТЕМАТИЧЕСКИЕ ОПЕРАЦИИ И ФУНКЦИИ =================================================================================

/*
 * Расстояние между значениями
 * Distance
 * Принимает:  Два числа типа Х
 * Возвращает: Расстояние между значениями типа X
*/
#define dis(x, y)                                                                                                                                    \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_dis, _y_dis,                                                                                                       \
    BLOC(__dis(_x_dis, _y_dis))))

#define __dis(x, y)                                                                                                                                  \
    BLOC(__dif(__max(x, y), __min(x, y)))

/*
 * Абсолютное значение
 * Absolute value
 * Принимает:  Число типа Х
 * Возвращает: Абсолютное значение типа X
*/
#define abs(x)                                                                                                                                       \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE(x, _x_abs);                                                                                                                      \
    BLOC(__abs(_x_abs)))

#define __abs(x)                                                                                                                                     \
    BLOC(                                                                                                                                            \
    _Generic(x,                                                                                                                                      \
    char                : ___abs_char,                                                                                                               \
    is8_t               : ___abs_is8 ,                                                                                                               \
    is16_t              : ___abs_is16,                                                                                                               \
    is32_t              : ___abs_is32,                                                                                                               \
    is64_t              : ___abs_is64,                                                                                                               \
    us8_t               : ___abs_us8 ,                                                                                                               \
    us16_t              : ___abs_us16,                                                                                                               \
    us32_t              : ___abs_us32,                                                                                                               \
    us64_t              : ___abs_us64,                                                                                                               \
    float               : fabsf,                                                                                                                     \
    double              : fabs,                                                                                                                      \
    long double         : fabsl,                                                                                                                     \
    double complex      : cabs,                                                                                                                      \
    float complex       : cabsf,                                                                                                                     \
    long double complex : cabsl,                                                                                                                     \
    default: 0)(x))

/*
 * Положительное число
 * Positive value
 * Принимает:  Число типа Х
 * Возвращает: Положительное число типа X
*/
#define pos(x)                                                                                                                                       \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE(x, _x_pos);                                                                                                                      \
    BLOC(__pos(_x_pos)))

#define __pos(x)                                                                                                                                     \
    BLOC(((x) > zero(x)) ? typecast((x), (x)) : typecast((x), (-(x))))

/*
 * Отрицательное число
 * Принимает:  Число типа Х
 * Возвращает: Отрицательное число типа X
*/
#define neg(x)                                                                                                                                       \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE(x, _x_neg);                                                                                                                      \
    BLOC(__neg(_x_neg)))

#define __neg(x)                                                                                                                                     \
    BLOC(((x) < zero(x)) ? typecast((x), (x)) : typecast((x), (-(x))))

/*
 * Наибольший общий делитель
 * Greatest common divisor
 * Принимает:  Два числа типа umax_t
 * Возвращает: Типа umax_t
*/
#define gcd(x, y)                                                                                                                                    \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_TYPE_2(umax_t, x, y, _x_gcd, _y_gcd,                                                                                              \
    BLOC(__gcd(_x_gcd, _y_gcd))))

#define __gcd(x, y)                                                                                                                                  \
    BLOC(___gcd((x), (y)))

/*
 * Наименьшее общее кратное чисел
 * Least common multiple
 * Принимает:  Два числа типа umax_t
 * Возвращает: Типа umax_t
*/
#define lcm(x, y)                                                                                                                                    \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_TYPE_2(umax_t, x, y, _x_lmc, _y_lmc,                                                                                              \
    BLOC(__lcm(_x_lmc, _y_lmc))))

#define __lcm(x, y)                                                                                                                                  \
    BLOC(___lcm((x), (y)))

//================= ИТЕРАЦИЯ ПО ЧИСЛАМ ===============================================================================================================

/*
 * Следующее представимое число, по направлению к отрицательной бесконечности
*/
#define prev_num(x)                                                                                                                                  \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE(x, _x_num);                                                                                                                      \
    BLOC(__prev_num(_x_num)))

#define __prev_num(x)  _Generic((x),                                                                                                                 \
    float:              __prev_num_flt(x),                                                                                                           \
    double:             __prev_num_flt(x),                                                                                                           \
    long double:        __prev_num_flt(x),                                                                                                           \
    default:            __prev_num_int(x))
#define __prev_num_int(x) BLOC(typecast((x), (x) - one(x)))
#define __prev_num_flt(x) BLOC(typecast((x), nextafter((x), neg(inf(x)))))

/*
 * Следующее представимое число, по направлению к положительной бесконечности
*/
#define next_num(x)                                                                                                                                  \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE(x, _x_num);                                                                                                                      \
    BLOC(__next_num(_x_num)))

#define __next_num(x)  _Generic((x),                                                                                                                 \
    float:              __next_num_flt(x),                                                                                                           \
    double:             __next_num_flt(x),                                                                                                           \
    long double:        __next_num_flt(x),                                                                                                           \
    default:            __next_num_int(x))
#define __next_num_int(x) BLOC(typecast((x), (x) + one(x)))
#define __next_num_flt(x) BLOC(typecast((x), nextafter((x), pos(inf(x)))))

/*
 * Следующее представимое число, по направлению от числа
*/
#define prev_num_to(x, n)                                                                                                                            \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_num, _n_num,                                                                                                       \
    BLOC(__prev_num_to(_x_num, _n_num)))

#define __prev_num_to(x, n) _Generic((x),                                                                                                            \
    float:                  __prev_num_to_flt(x, n),                                                                                                 \
    double:                 __prev_num_to_flt(x, n),                                                                                                 \
    long double:            __prev_num_to_flt(x, n),                                                                                                 \
    default:                __prev_num_to_int(x, n))
#define __prev_num_to_int(x, n) BLOC(0)                 /* TODO IMPLEMENTATION */
#define __prev_num_to_flt(x, n) BLOC(0)                 /* TODO IMPLEMENTATION */

/*
 * Следующее представимое число, по направлению к числу
*/
#define next_num_to(x, n)                                                                                                                            \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_num, _n_num,                                                                                                       \
    BLOC(__next_num_to(_x_num, _n_num)))

#define __next_num_to(x, n)  _Generic((x),                                                                                                           \
    float:                   __next_num_to_flt(x),                                                                                                   \
    double:                  __next_num_to_flt(x),                                                                                                   \
    long double:             __next_num_to_flt(x),                                                                                                   \
    default:                 __next_num_to_int(x))
#define __next_num_to_int(x, n) BLOC(0)                 /* TODO IMPLEMENTATION */
#define __next_num_to_flt(x, n) BLOC(0)                 /* TODO IMPLEMENTATION */

//================= ОКРУГЛЕНИЕ =======================================================================================================================

/*
 * Округление к ближайшему целому
*/
#define round_int(x)                                                                                                                                 \
    BLOC(                                                                                                                                            \
    COMPILE_GROUPMATCH_EQ(STD_TYPE_GROUP_FLT, x);                                                                                                    \
    _Generic((x),                                                                                                                                    \
    float:       rintf,                                                                                                                              \
    double:      rint,                                                                                                                               \
    long double: rintl,                                                                                                                              \
    default: 0)(x))

/*
 * Округление в большую сторону
*/
#define round_up(x)                                                                                                                                  \
    BLOC(                                                                                                                                            \
    COMPILE_GROUPMATCH_EQ(STD_TYPE_GROUP_FLT, x);                                                                                                    \
    _Generic((x),                                                                                                                                    \
    float:       ceilf,                                                                                                                              \
    double:      ceil,                                                                                                                               \
    long double: ceill,                                                                                                                              \
    default: 0)(x))

/*
 * Округление в меньшую сторону
*/
#define round_dn(x)                                                                                                                                  \
    BLOC(                                                                                                                                            \
    COMPILE_GROUPMATCH_EQ(STD_TYPE_GROUP_FLT, x);                                                                                                    \
    _Generic((x),                                                                                                                                    \
    float:       floorf,                                                                                                                             \
    double:      floor,                                                                                                                              \
    long double: floorl,                                                                                                                             \
    default: 0)(x))

/*
 * Округление к нулю
*/
#define round_zero(x)                                                                                                                                \
    BLOC(                                                                                                                                            \
    COMPILE_GROUPMATCH_EQ(STD_TYPE_GROUP_FLT, x);                                                                                                    \
    _Generic((x),                                                                                                                                    \
    float:       truncf,                                                                                                                             \
    double:      trunc,                                                                                                                              \
    long double: truncl,                                                                                                                             \
    default: 0)(x))

/*
 * Округление к бесконечности или округление от нуля
*/
#define round_inf(x)                                                                                                                                 \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE(x, _x_ri);                                                                                                                       \
    BLOC(                                                                                                                                            \
    UNIT((_x_ri) > 0) ?                                                                                                                              \
    BLOC(round_up(_x_ri)) :                                                                                                                          \
    BLOC(round_dn(_x_ri))))

/*
 * Округление к ближайшему c шагом
*/
#define round_eps(x, e, func)                                                                                                                        \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2(x, e, _x_rei, _e_rei,                                                                                                           \
    BLOC(__mul(func(__qut((_x_rei), (_e_rei))), (_e_rei)))))

//================= ПОИСК МИНИМАЛЬНОГО И МАКСИМАЛЬНОГО ЗНАЧЕНИЯ ======================================================================================

/*
 * Минимальное из чисел
*/
#define min(x, y)                                                                                                                                    \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_min, _y_min,                                                                                                       \
    BLOC(__min(x, y))))

#define __min(x, y)                                                                                                                                  \
    (((x) < (y)) ? (x) : (y))

/*
 * Максимальное из чисел
*/
#define max(x, y)                                                                                                                                    \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_max, _y_max,                                                                                                       \
    BLOC(__max(x, y))))

#define __max(x, y)                                                                                                                                  \
    (((x) > (y)) ? (x) : (y))

/*
 * Минимальное из чисел, но не ноль
*/
#define min_not_zero(x, y)                                                                                                                           \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_mnz, _y_mnz,                                                                                                       \
    BLOC(__min_not_zero(_x_mnz, _y_mnz))))

#define __min_not_zero(x, y)                                                                                                                         \
    (((x) == zero(x)) ? (y) : (((y) == zero(y)) ? (x) : (((x) < (y)) ? (x) : (y))))

/*
 * Максимальное из чисел, но не ноль
*/
#define max_not_zero(x, y)                                                                                                                           \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((x), (y), _x_mnz, _y_mnz,                                                                                                       \
    BLOC(__max_not_zero(_x_mnz, _y_mnz))))

#define __max_not_zero(x, y)                                                                                                                         \
    (((x) == zero(x)) ? (y) : (((y) == zero(y)) ? (x) : (((x) > (y)) ? (x) : (y))))

/*
 * Установка начальных значений
*/
#define minmax_init(min, max)                                                                                                                        \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_2((min), (max), _x_mmi, _y_mmi,                                                                                                   \
    BLOC(min =  typemax(_x_mmi); max = typemin(_y_mmi))))

/*
 * Определяет число как минимальное или максимальное и помещает его в соответствующий аргумент
*/
#define minmax_set(min, max, x)                                                                                                                      \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_3((min), (max), (x), _min, _max, _x,                                                                                              \
    BLOC(min = __min(_min, _x); max = __max(_max, _x))))

/*
 * Определяет число как минимальное или максимальное, но не ноль и помещает его в соответствующий аргумент
*/
#define minmax_not_zero_set(min, max, x)                                                                                                             \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_3((min), (max), (x), _min, _max, _x,                                                                                              \
    BLOC(min = __min_not_zero(_min, _x); max = __max_not_zero(_max, _x))))

//================= ПРОГРЕССИИ =======================================================================================================================

/*
 * Вернуть n-й член арифметической прогрессии
 * a_n = a_1 + b * (n - 1), где - n = 0, 1, 2, ...
*/
#define progresion_arithmetic(a, b, n)                                                                                                               \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE(n, _n_ari);                                                                                                                      \
    COMPILE_GROUPMATCH_EQ(STD_TYPE_GROUP_SINT | STD_TYPE_GROUP_UINT, _n_ari);                                                                        \
    COMPILE_WCHDOG_2(a, b, _a_ari, _b_ari,                                                                                                           \
    BLOC(__progresion_arithmetic(_a_ari, _b_ari, _n_ari))))

#define __progresion_arithmetic(a, b, n)                                                                                                             \
    BLOC(__sum(a, __mul(b, typecast(b, n))))

/*
 * Проверить, что число соответствует арифметической прогрессии
*/
#define is_progresion_arithmetic(a, b, x)                                                                                                            \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_3(a, b, x, _a_ari, _b_ari, _x_ari,                                                                                                \
    BLOC(__is_progresion_arithmetic(_a_ari, _b_ari, _x_ari))))

#define __is_progresion_arithmetic(a, b, x)                                                                                                          \
    BLOC(is_zero(__get_rem(__qut(__dif((x), (a)), (b)))))

/*
 * Вернуть n-й член геометрической прогрессии
 * b_n = b_1 * q ^ (n - 1), где - n = 0, 1, 2, ...
*/
#define progresion_geometric(b, q, n)                                                                                                                \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE(n, _n_geo);                                                                                                                      \
    COMPILE_GROUPMATCH_EQ(STD_TYPE_GROUP_SINT | STD_TYPE_GROUP_UINT, _n_geo);                                                                        \
    COMPILE_WCHDOG_GROUP_2(STD_TYPE_GROUP_FLT, b, q, _b_geo, _q_geo,                                                                                 \
    BLOC(__progresion_geometric(_b_geo, _q_geo, _n_geo))))

#define __progresion_geometric(b, q, n)                                                                                                              \
    BLOC(__mul((b), __powm((q), typecast(q, n))))

/*
 * Проверить, что число соответствует геометрической прогрессии
*/
#define is_progresion_geometric(b, q, x)                                                                                                             \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_3(b, q, x, _b_geo, _q_geo, _x_geo,                                                                                                \
    BLOC(__is_progresion_geometric(_b_geo, _q_geo, _x_geo))))

#define __is_progresion_geometric(b, q, x)                                                                                                           \
    BLOC(is_zero(__get_rem(__logm(__qut((x), (b)), (q)))))

/*
 * Вернуть n-й член гармонической прогрессии
 * h_n = 1 / pr_ar(a, b, n), где n = 0, 1, 2, ...
*/
#define progresion_harmonic(a, b, n)                                                                                                                 \
    BLOC(                                                                                                                                            \
    COMPILE_NO_SIDE(n, _n_har);                                                                                                                      \
    COMPILE_GROUPMATCH_EQ(STD_TYPE_GROUP_SINT | STD_TYPE_GROUP_UINT, _n_har);                                                                        \
    COMPILE_WCHDOG_GROUP_2(STD_TYPE_GROUP_FLT, a, b, _a_har, _b_har,                                                                                 \
    BLOC(__progresion_harmonic(_a_har, _b_har, _n_har))))

#define __progresion_harmonic(a, b, n)                                                                                                               \
    BLOC(__qut(one(fmax_t), typecast(fmax_t, __progresion_arithmetic(a, b, n))))

/*
 * Проверить, что число соответствует формуле  или гармоническая прогрессия
*/
#define is_progresion_harmonic(a, b, x)                                                                                                              \
    BLOC(                                                                                                                                            \
    COMPILE_WCHDOG_3(a, b, x, _a_har, _b_har, _x_har,                                                                                                \
    BLOC(__is_progresion_harmonic(_a_har, _b_har, _x_har))))

#define __is_progresion_harmonic(a, b, x)                                                                                                            \
    BLOC(                                                                                                                                            \
    __ap(__get_rem(__qut(one(fmax_t) - __mul((x), (a)), __mul((x), (b)))), zero(fmax_t), 0.00001) ||                                                 \
    __ap(__get_rem(__qut(one(fmax_t) - __mul((x), (a)), __mul((x), (b)))),  one(fmax_t), 0.00001))

//================= СПЕЦИАЛИЗИРОВАНЫЕ МАТЕМАТИЧЕСКИЕ ФУНКЦИИ =========================================================================================

/*
 * Возвращает n-e простое число
*/
#define primenum(n)                                                                                                                                  \
    BLOC(                                                                                                                                            \
    COMPILE_TYPEMATCH_EQ(umax_t, n);                                                                                                                 \
    BLOC(___primenum(n)))

/*
 * Возвращает n-e число Фибоначчи
*/
#define fibonacci(n)                                                                                                                                 \
    BLOC(                                                                                                                                            \
    COMPILE_TYPEMATCH_EQ(umax_t, n);                                                                                                                 \
    BLOC(___fibonacci(n)))                                                                                                                           \

/*
 * Возвращает n-e число факториала
*/
#define factorial(n)                                                                                                                                 \
    BLOC(                                                                                                                                            \
    COMPILE_TYPEMATCH_EQ(umax_t, n);                                                                                                                 \
    BLOC(___factorial(n)))

/*
 * Возвращает n-e число на k-й позиции, бинома Ньютона
*/
#define binomial(n, k)                                                                                                                               \
    BLOC(                                                                                                                                            \
    COMPILE_TYPEMATCH_EQ(umax_t, n);                                                                                                                 \
    COMPILE_TYPEMATCH_EQ(umax_t, k);                                                                                                                 \
    BLOC(___binomial(n, k)))

/*
 * Возвращает количество делителей числа
 * Заполняет массив делителями числа
 * После вызова необходимо вызвать free()
*/
#define divisors(x, m)                                                                                                                               \
    BLOC(                                                                                                                                            \
    COMPILE_TYPEMATCH_EQ(umax_t, x);                                                                                                                 \
    BLOC(___divisors(x, m)))

/*
 * Возвращает количество простых множителей от 1 до x
 * Заполняет массив простых множителей
 * После вызова необходимо вызвать free()
*/
#define primes(x, m)                                                                                                                                 \
    BLOC(                                                                                                                                            \
    COMPILE_TYPEMATCH_EQ(umax_t, x);                                                                                                                 \
    BLOC(___primes(x, m)))

//================= КОМБИНАТОРИКА ====================================================================================================================

/*
 * Перестановка P_n
 * n - количество элементов, m - null
 * Перестановка с повторением `P_n_k
 * n - количество групп, m - массив, количество значений в каждой группе
*/
#define permutation(n, m)                                                                                                                            \
    BLOC(                                                                                                                                            \
    COMPILE_TYPEMATCH_EQ(umax_t, n);                                                                                                                 \
    BLOC(___permutation(n, m)))

/*
 * Размещение A^n_k
 * n - количество элементов, k - различных элементов, f - false
 * Размещение с повторением (выборка с возвращением) `A^n_k
 * n - количество групп, k - различных элементов, f - true
*/
#define accommodation(n, k, f)                                                                                                                       \
    BLOC(                                                                                                                                            \
    COMPILE_TYPEMATCH_EQ(umax_t, n);                                                                                                                 \
    COMPILE_TYPEMATCH_EQ(umax_t, k);                                                                                                                 \
    BLOC(___accommodation(n, k, f)))

/*
 * Сочетание C^n_k
 * n - количество элементов, k - различных элементов, f - false
 * Сочетание с повторением (сочетание с возвращением) `C^n_k
 * n - количество групп, k - различных элементов, f - true
*/
#define combination(n, k, f)                                                                                                                         \
    BLOC(                                                                                                                                            \
    COMPILE_TYPEMATCH_EQ(umax_t, n);                                                                                                                 \
    COMPILE_TYPEMATCH_EQ(umax_t, k);                                                                                                                 \
    BLOC(___combination(n, k, f)))

//====================================================================================================================================================

END_C_DECLARATION
#endif /*YAYA_ARITHMETIC_H*/
