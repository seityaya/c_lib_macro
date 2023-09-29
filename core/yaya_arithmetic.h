// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_ARITHMETIC_H
#define YAYA_ARITHMETIC_H

#include "math.h"
#include "stddef.h"
#include "tgmath.h"

#include "yaya_arithmetic_round.h"
#include "yaya_bool.h"
#include "yaya_cdecl.h"
#include "yaya_check.h"
#include "yaya_gover.h"
#include "yaya_sugar.h"
#include "yaya_type.h"

// clang-format off
BEG_C_DECLARATION

//================= ARITHMETIC =======================================================================================================================
/*
 * Библиотека создавалась с целью, определить единый математический интерфейс для работы с
 * числами целого типа, чисел с плавающей точкой и комплексных чисел.
 * Покрыть базовые потребности в простейших математических операциях определенных для всех типов.
 * Проверка на строгость соответствия типов ставится на первое место.
*/

//================= ОПРЕДЕЛЕНИЕ ФУНКЦИЙ ==============================================================================================================

char   ___copysign_char(char   r, char   s);
is8_t  ___copysign_is8 (is8_t  r, is8_t  s);
is16_t ___copysign_is16(is16_t r, is16_t s);
is32_t ___copysign_is32(is32_t r, is32_t s);
is64_t ___copysign_is64(is64_t r, is64_t s);
us8_t  ___copysign_us8 (us8_t  r, us8_t  s);
us16_t ___copysign_us16(us16_t r, us16_t s);
us32_t ___copysign_us32(us32_t r, us32_t s);
us64_t ___copysign_us64(us64_t r, us64_t s);

bool_t ___is_prime(umax_t x);

char   ___abs_char(char   x);
is8_t  ___abs_is8 (is8_t  x);
is16_t ___abs_is16(is16_t x);
is32_t ___abs_is32(is32_t x);
is64_t ___abs_is64(is64_t x);
us8_t  ___abs_us8 (us8_t  x);
us16_t ___abs_us16(us16_t x);
us32_t ___abs_us32(us32_t x);
us64_t ___abs_us64(us64_t x);

//================= БАЗОВЫЕ КОНСТАНТЫ ================================================================================================================
/*
 * Положительный ноль, соответствующий переданному типу
*/
#define zero(type_t)                                                                                                                                 \
    BLOCK(base_type_cast(type_t, 0))

/*
 * Положительная единица, соответствующий переданному типу
*/
#define one(type_t)                                                                                                                                  \
    BLOCK(base_type_cast(type_t, 1))

/*
 * Бесконечность, соответствующий переданному типу
*/
#define pos_inf(type_t)                                                                                                                              \
    BLOCK(base_type_cast(type_t, +INFINITY))

#define neg_inf(type_t)                                                                                                                              \
    BLOCK(base_type_cast(type_t, -INFINITY))

/*
 * Не число, соответствующий переданному типу
*/
#define nan(type_t)                                                                                                                                  \
    BLOCK(base_type_cast(type_t, NAN))

//================= УНАРНЫЕ ОПЕРАЦИИ =================================================================================================================
/*
 * Унарный префиксный инкремент
*/
#define un_inc_first(x)                                                                                                                              \
    BLOCK(++(x))

/*
 * Унарный префиксный декремент
*/
#define un_dec_first(x)                                                                                                                              \
    BLOCK(--(x))

/*
 * Унарный постфиксный инкремент
*/
#define un_inc_after(x)                                                                                                                              \
    BLOCK((x)++)

/*
 * Унарный постфиксный декремент
*/
#define un_dec_after(x)                                                                                                                              \
    BLOCK((x)--)

//================= ЛОГИЧЕСКИЕ ОПЕРАЦИИ ==============================================================================================================
/*
 * Логическое отрицание
*/
#define log_not(x)                                                                                                                                   \
    COMPILE_1_CALC((x), _x, __log_not(_x))

#define __log_not(x)                                                                                                                                 \
    BLOCK(!(x))

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Логическое И
*/
#define log_and(x, y)                                                                                                                                \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __log_and(_x, _y))

#define __log_and(x, y)                                                                                                                              \
    BLOCK((x) && (y))

/*
 * Логическое И (Аналогично log_and, но вычисляет второй операнд тоже)
*/
#define log_and_each(x, y)                                                                                                                            \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __log_and_each(_x, _y))

#define __log_and_each(x, y)                                                                                                                          \
    BLOCK(bool_t __x = (x); bool_t __y = (y); (__x) && (__y))

/*
 * Логическое ИЛИ
*/
#define log_or(x, y)                                                                                                                                 \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __log_or(_x, _y))

#define __log_or(x, y)                                                                                                                               \
    BLOCK((x) || (y))

/*
 * Логическое ИЛИ (Аналогично log_or, но вычисляет второй операнд тоже)
*/
#define log_or_each(x, y)                                                                                                                             \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __log_or_each(_x, _y))

#define __log_or_each(x, y)                                                                                                                           \
    BLOCK(bool_t __x = (x); bool_t __y = (y); (__x) || (__y))

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Логическое И-НЕ
*/
#define log_nand(x, y)                                                                                                                               \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __log_nand(_x, _y))

#define __log_nand(x, y)                                                                                                                             \
    BLOCK(__log_not(__log_and(x, y)))

/*
 * Логическое И-НЕ (Аналогично log_nand, но вычисляет второй операнд тоже)
*/
#define log_nand_each(x, y)                                                                                                                          \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __log_nand_each(_x, _y))

#define __log_nand_each(x, y)                                                                                                                        \
    BLOCK(bool_t __x = (x); bool_t __y = (y); __log_not(__log_and(__x, __y)))

/*
 * Логическое ИЛИ-НЕ
*/
#define log_nor(x, y)                                                                                                                                \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __log_nor(_x, _y))

#define __log_nor(x, y)                                                                                                                              \
    BLOCK(__log_not(__log_or(x, y)))

/*
 * Логическое ИЛИ-НЕ (Аналогично log_nor, но вычисляет второй операнд тоже)
*/
#define log_nor_each(x, y)                                                                                                                           \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __log_nor_each(_x, _y))

#define __log_nor_each(x, y)                                                                                                                         \
    BLOCK(bool_t __x = (x); bool_t __y = (y); __log_not(__log_or(__x, __y)))

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Логическое ИСКЛЮЧАЮЩЕЕ И
*/
#define log_xand(x, y)                                                                                                                               \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __log_xand(_x, _y))

#define __log_xand(x, y)                                                                                                                             \
    BLOCK(__log_not(__log_xor(x, y)))

/*
 * Логическое ИСКЛЮЧАЮЩЕЕ ИЛИ
*/
#define log_xor(x, y)                                                                                                                                \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __log_xor(_x, _y))

#define __log_xor(x, y)                                                                                                                              \
    BLOCK(__log_not(x) != __log_not(y))

//================= ОПЕРАЦИИ СРАВНЕНИЯ ===============================================================================================================
/*
 * Сравнение на равенство
 * Equality
*/
#define eq(x, y)                                                                                                                                     \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __eq(_x, _y))

#define __eq(x, y)                                                                                                                                   \
    BLOCK((x) == (y))

/*
 * Сравнение на неравенство
 * Inequality
*/
#define ne(x, y)                                                                                                                                     \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __ne(_x, _y))

#define __ne(x, y)                                                                                                                                   \
    BLOCK((x) != (y))

/*
 * Больше
 * Greater then
*/
#define gt(x, y)                                                                                                                                     \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __gt(_x, _y))

#define __gt(x, y)                                                                                                                                   \
    BLOCK((x) > (y))

/*
 * Меньше
 * Less then
*/
#define lt(x, y)                                                                                                                                     \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __lt(_x, _y))

#define __lt(x, y)                                                                                                                                   \
    BLOCK((x) < (y))

/*
 * Больше или равно
 * Equality or Greater then
*/
#define ge(x, y)                                                                                                                                     \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __ge(_x, _y))

#define __ge(x, y)                                                                                                                                   \
    BLOCK((x) >= (y))

/*
 * Меньше или равно
 * Equality or Less then
*/
#define le(x, y)                                                                                                                                     \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __le(_x, _y))

#define __le(x, y)                                                                                                                                   \
    BLOCK((x) <= (y))

/*
 * Примерное равно
 * Approximate equality
*/
#define ap(x, y, e)                                                                                                                                  \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC((x), (y), (e), _x, _y, _e, __ap(_x, _y, _e))

#define __ap(x, y, e)                                                                                                                                \
    BLOCK(__le(__abs(__dif(__max((x), (y)), __min((x), (y)))), (e)))

//================= ОПЕРАЦИИ ПРИСВАИВАНИЯ И ОБМЕНА ===================================================================================================
/*
 * Проверка корректности присваивания
 * Assignment
*/
#define is_as(dst, src)                                                                                                                              \
    COMPILE_ASSERT_GROUP_EQUAL_2_CALC((dst), (src), _dst, _src, __is_as(_dst, _src))

#define __is_as(dst, src)                                                                                                                            \
    BLOCK(__log_and(__le(base_type_min(dst), (src)), __ge(base_type_max(dst), (src))) ? BLOCK(true) : BLOCK(false))

/*
 * Присваивание
 * Assignment
*/
#define as(dst, src)                                                                                                                                 \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((dst), (src), _dst, _src, __as((dst), _src))

#define __as(dst, src)                                                                                                                               \
    BLOCK((dst) = base_type_cast((dst), (src)); true)

/*
 * Присваивание с проверкой типов одной группы и возможностью присвоения, если присвоение не приведет к усечению значения
*/
#define as_chk(dst, src)                                                                                                                             \
    COMPILE_ASSERT_GROUP_EQUAL_2_CALC((dst), (src), _dst, _src, __as_chk((dst), _src))

#define __as_chk(dst, src)                                                                                                                           \
    BLOCK(__is_as((dst), (src)) ? BLOCK(__as((dst), (src)); true) : BLOCK(false))

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Обмен
 * Exchange
*/
#define swap(x, y)                                                                                                                                   \
    BLOCK(__swap(x, y))

#define __swap(x, y)                                                                                                                                 \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, BLOCK(__as(x, _y); __as(y, _x); true))

//================= ПРОВЕРКА ЧИСЕЛ НА СООТВЕТСТВИЕ ===================================================================================================
/*
 * Проверка, что число положительное, но не ноль
*/
#define is_pos(x)                                                                                                                                    \
    COMPILE_1_CALC((x), _x, __is_pos(_x))

#define __is_pos(x)                                                                                                                                  \
    BLOCK(__gt((x), zero(x)))

/*
 * Проверка, что число отрицательное, но не ноль
*/
#define is_neg(x)                                                                                                                                    \
    COMPILE_1_CALC((x), _x, __is_neg(_x))

#define __is_neg(x)                                                                                                                                  \
    BLOCK(__lt((x), zero(x)))

/*
 * Проверка, что число ноль
*/
#define is_zero(x)                                                                                                                                   \
    COMPILE_1_CALC((x), _x, __is_zero(_x))

#define __is_zero(x)                                                                                                                                 \
    BLOCK(__eq((x), zero(x)))

/*
 * Проверка, что число не ноль
*/
#define is_not_zero(x)                                                                                                                               \
    COMPILE_1_CALC((x), _x, __is_not_zero(_x))

#define __is_not_zero(x)                                                                                                                             \
    BLOCK(__ne((x), zero(x)))

/*
 * Проверка, что число положительное или ноль
*/
#define is_pos_or_zero(x)                                                                                                                            \
    COMPILE_1_CALC((x), _x, __is_pos_or_zero(_x))

#define __is_pos_or_zero(x)                                                                                                                          \
    BLOCK(__ge((x), zero(x)))

/*
 * Проверка, что число отрицательное или ноль
*/
#define is_neg_or_zero(x)                                                                                                                            \
    COMPILE_1_CALC((x), _x, __is_neg_or_zero(_x))

#define __is_neg_or_zero(x)                                                                                                                          \
    BLOCK(__le((x), zero(x)))

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Проверка, что целое число четное
*/
#define is_even(x)                                                                                                                                   \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC((BASE_TYPE_GROUP_CHAR | BASE_TYPE_GROUP_SINT | BASE_TYPE_GROUP_UINT), (x), _x, __is_even(_x))

#define __is_even(x)                                                                                                                                 \
    BLOCK(__is_zero(__mod_int((x), base_type_cast((x), (2)))))

/*
 * Проверка, что целое число нечетное
*/
#define is_odd(x)                                                                                                                                    \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC((BASE_TYPE_GROUP_CHAR | BASE_TYPE_GROUP_SINT | BASE_TYPE_GROUP_UINT), (x), _x, __is_odd(_x))

#define __is_odd(x)                                                                                                                                  \
    BLOCK(__is_not_zero(__mod_int((x), base_type_cast((x), (2)))))

/*
 * Проверка, что целое число простое
 * Не самая оптимальная функция
*/
#define is_prime(x)                                                                                                                                  \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC((BASE_TYPE_GROUP_CHAR | BASE_TYPE_GROUP_SINT | BASE_TYPE_GROUP_UINT), (x), _x, __is_prime(_x))

#define __is_prime(x)                                                                                                                                \
    BLOCK(___is_prime(base_type_cast(umax_t, (x))))

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Классы чисел с плавающей запятой
*/
enum fp_class_e {
    FPC_NAN  = FP_NAN,
    FPC_INF  = FP_INFINITE,
    FPC_ZERO = FP_ZERO,
    FPC_SUB  = FP_SUBNORMAL,
    FPC_NOR  = FP_NORMAL,
};

/*
 * Является ли число конечным
*/
#define is_fp_fin(x)                                                                                                                                 \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC(BASE_TYPE_GROUP_FLT, (x), _x, isfinite(_x))

/*
 * Является ли число «не числом» (NaN)
*/
#define is_fp_nan(x)                                                                                                                                 \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC(BASE_TYPE_GROUP_FLT, (x), _x, isnan(_x))

/*
 * Является ли число бесконечно большим
*/
#define is_fp_inf(x)                                                                                                                                 \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC(BASE_TYPE_GROUP_FLT, (x), _x, isinf(_x))

/*
 * Является ли число конечным, нормализованным числом отличным от нуля
*/
#define is_fp_nor(x)                                                                                                                                 \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC(BASE_TYPE_GROUP_FLT, (x), _x, isnormal(_x))

/*
 * Является ли число конечным, не нормализованным числом отличным от нуля
*/
#define is_fp_sub(x)                                                                                                                                 \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC(BASE_TYPE_GROUP_FLT, (x), _x, __eq(fpclassify(_x), FP_SUBNORMAL))

/*
 * Является ли число не отличным от нуля
*/
#define is_fp_zero(x)                                                                                                                                \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC(BASE_TYPE_GROUP_FLT, (x), _x, __eq(fpclassify(_x), FP_ZERO))

/*
 * Классифицирует  число в одну из 5 категорий
*/
#define fp_class(x)                                                                                                                                  \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC(BASE_TYPE_GROUP_FLT, (x), _x, fpclassify(_x))

//================= ЧАСТИ ВЕЩЕСТВЕННЫХ И КОМПЛЕКСНЫХ ЧИСЕЛ ===========================================================================================
/*
 * Взятие целого
 * Принимает:  Число типа Х
 * Возвращает: Целую часть числа типа Х, без потери знака
*/
#define get_int(x)                                                                                                                                   \
    COMPILE_ASSERT_GROUP_NOT_MATCH_1_CALC(BASE_TYPE_GROUP_COMPLEX, (x), _x, __get_int(_x))

#define __get_int(x)                                                                                                                                 \
    BLOCK(                                                                                                                                           \
        (__eq(base_type_sign(x), BASE_TYPE_SIGN_SIGNUM)) ?                                                                                           \
            BLOCK(base_type_cast((x), base_type_cast(imax_t, (x)))) :                                                                                \
            BLOCK(base_type_cast((x), base_type_cast(umax_t, (x))))                                                                                  \
    )

/*
 * Взятие дробного
 * Принимает:  Число типа Х
 * Возвращает: Дробную числа типа Х
*/
#define get_frc(x)                                                                                                                                   \
    COMPILE_ASSERT_GROUP_NOT_MATCH_1_CALC(BASE_TYPE_GROUP_COMPLEX, (x), _x, __get_frc(_x))

#define __get_frc(x)                                                                                                                                 \
    BLOCK(base_type_cast((x), __dif((x), __get_int((x)))))

/*
 * Вещественная часть числа
 * Принимает:  Число типа complex
 * Возвращает: Вещественную часть числа типа X
*/
#define get_real(x)                                                                                                                                  \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC(BASE_TYPE_GROUP_COMPLEX, (x), _x, __get_real(_x))

#define __get_real(x)                                                                                                                                \
    BLOCK(                                                                                                                                           \
        _Generic((x),                                                                                                                                \
            float       complex : crealf,                                                                                                            \
            double      complex : creal ,                                                                                                            \
            long double complex : creall)((x))                                                                                                       \
    )

/*
 * Мнимая часть числа
 * Принимает:  Число типа complex
 * Возвращает: Мнимую часть числа типа X
*/
#define get_imag(x)                                                                                                                                  \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC(BASE_TYPE_GROUP_COMPLEX, (x), _x, __get_imag(_x))

#define __get_imag(x)                                                                                                                                \
    BLOCK(                                                                                                                                           \
        _Generic((x),                                                                                                                                \
            float       complex : cimagf,                                                                                                            \
            double      complex : cimag ,                                                                                                            \
            long double complex : cimagl)((x))                                                                                                       \
    )

//================= РАЗЛОЖЕНИЕ ВЕЩЕСТВЕННОГО ЧИСЛА НА СОСТАВЛЯЮЩИЕ ==== S*M*B^E ======================================================================
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
    COMPILE_ASSERT_GROUP_NOT_MATCH_1_CALC(BASE_TYPE_GROUP_COMPLEX, (x), _x, __get_sign(_x))

#define __get_sign(x)                                                                                                                                \
    BLOCK(                                                                                                                                           \
        COMPILE_NO_SIDE_EFFECT_VARIABLE(one((x)), _y);                                                                                               \
        BLOCK(_y = ___get_sign(_y, (x)); _y)                                                                                                         \
    )

#define ___get_sign(x, y)                                                                                                                            \
    BLOCK(                                                                                                                                           \
        _Generic((x),                                                                                                                                \
            char         : ___copysign_char,                                                                                                         \
            is8_t        : ___copysign_is8 ,                                                                                                         \
            is16_t       : ___copysign_is16,                                                                                                         \
            is32_t       : ___copysign_is32,                                                                                                         \
            is64_t       : ___copysign_is64,                                                                                                         \
            us8_t        : ___copysign_us8 ,                                                                                                         \
            us16_t       : ___copysign_us16,                                                                                                         \
            us32_t       : ___copysign_us32,                                                                                                         \
            us64_t       : ___copysign_us64,                                                                                                         \
            float        : copysignf       ,                                                                                                         \
            double       : copysign        ,                                                                                                         \
            long double  : copysignl       ,                                                                                                         \
            default      : 0               )((x), (y))                                                                                               \
    )

/*
 * Мантисса числа по основанию 2
 * Принимает:  Число типа floating
 * Возвращает: Тип floating
*/
#define get_mantissa2(x)                                                                                                                             \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC(BASE_TYPE_GROUP_FLT, (x), _x, __get_mantissa2(_x))

#define __get_mantissa2(x)                                                                                                                           \
    BLOCK(                                                                                                                                           \
        int e;                                                                                                                                       \
        __abs(                                                                                                                                       \
        _Generic((x),                                                                                                                                \
            float        : frexpf,                                                                                                                   \
            double       : frexp ,                                                                                                                   \
            long double  : frexpl,                                                                                                                   \
            default      : 0     )((x), &e))                                                                                                         \
    )

/*
 * Экспонента числа по основанию 2
 * Принимает:  Число типа floating
 * Возвращает: Тип imax_t
*/
#define get_exponent2(x)                                                                                                                             \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC(BASE_TYPE_GROUP_FLT, (x), _x, __get_exponent2(_x))

#define __get_exponent2(x)                                                                                                                           \
    BLOCK(                                                                                                                                           \
        int e;                                                                                                                                       \
        _Generic((x),                                                                                                                                \
            float        : frexpf,                                                                                                                   \
            double       : frexp ,                                                                                                                   \
            long double  : frexpl,                                                                                                                   \
            default      : 0     )((x), &e);                                                                                                         \
        base_type_cast(imax_t, e)                                                                                                                    \
    )

/*
 * Мантисса числа по основанию 10
 * Принимает:  Число типа floating
 * Возвращает: Тип floating
*/
#define get_mantissa10(x)                                                                                                                            \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC(BASE_TYPE_GROUP_FLT, (x), _x, __get_mantissa10(_x))

#define __get_mantissa10(x)                                                                                                                          \
    BLOCK(base_type_cast((x), __powm(base_type_cast((x), 10.0), base_type_cast((x), __get_frc(__logm((x), base_type_cast((x), 10.0)))))))

/*
 * Экспонента числа по основанию 10
 * Принимает:  Число типа floating
 * Возвращает: Тип imax_t
*/
#define get_exponent10(x)                                                                                                                            \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC(BASE_TYPE_GROUP_FLT, (x), _x, __get_exponent10(_x))

#define __get_exponent10(x)                                                                                                                          \
    BLOCK(__is_zero((x)) ? zero(imax_t) : base_type_cast(imax_t, __round_dn(__logm(__abs((x)), base_type_cast((x), 10.0)))))

//================= ДОПОЛНИТЕЛЬНЫЕ МАТЕМАТИЧЕСКИЕ ОПЕРАЦИИ И ФУНКЦИИ =================================================================================
/*
 * Положительное число
 * Positive value
*/
#define is_to_pos(x)                                                                                                                                 \
    COMPILE_1_CALC((x), _x, BLOCK(__is_to_pos(_x)))

#define __is_to_pos(x)                                                                                                                               \
    BLOCK(COMPILE_GROUP_CHECK(BASE_TYPE_GROUP_SINT, (x)) ? BLOCK(__ne((x), base_type_min(x))) : BLOCK(true))

#define to_pos(x)                                                                                                                                    \
    COMPILE_1_CALC((x), _x, __to_pos(_x))

#define __to_pos(x)                                                                                                                                  \
    BLOCK(base_type_cast((x), __is_to_pos(x) ? BLOCK(__is_pos(x) ? (x) : (-(x))) : BLOCK((x))))

#define to_pos_chk(result, x)                                                                                                                        \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((result), (x), _result, _x, __to_pos_chk((result), _x))

#define __to_pos_chk(result, x)                                                                                                                      \
    BLOCK(__is_to_pos(x) ? BLOCK(__as((result), __to_pos(x)); true) : BLOCK(false))

/*
 * Отрицательное число
 * Negative value
*/
#define is_to_neg(x)                                                                                                                                 \
    COMPILE_1_CALC(x, _x, BLOCK(__is_to_neg(_x)))

#define __is_to_neg(x)                                                                                                                               \
    BLOCK(COMPILE_GROUP_CHECK(BASE_TYPE_GROUP_UINT, (x)) ? BLOCK(false) : BLOCK(true))

#define to_neg(x)                                                                                                                                    \
    COMPILE_1_CALC(x, _x, BLOCK(__to_neg(_x)))

#define __to_neg(x)                                                                                                                                  \
    BLOCK(base_type_cast((x), __is_to_neg(x) ? BLOCK(__is_neg(x) ?  (x) : (-(x))) : BLOCK((x))))

#define to_neg_chk(result, x)                                                                                                                        \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((result), (x), _result, _x, BLOCK(__to_neg_chk((result), _x)))

#define __to_neg_chk(result, x)                                                                                                                      \
    BLOCK(__is_to_neg(x) ? BLOCK(__as((result), __to_neg(x)); true) : BLOCK(false))

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Абсолютное значение
 * Absolute value
*/
#define is_abs(x)                                                                                                                                    \
    COMPILE_1_CALC((x), _x, __is_abs(_x))

#define __is_abs(x)                                                                                                                                  \
    BLOCK(COMPILE_GROUP_CHECK(BASE_TYPE_GROUP_SINT, (x)) ? BLOCK(__ne((x), base_type_min((x)))) : BLOCK(true))

#define abs(x)                                                                                                                                       \
    COMPILE_1_CALC(x, _x, BLOCK(__abs(_x)))

#define __abs(x)                                                                                                                                     \
    BLOCK(                                                                                                                                           \
        base_type_cast((x),                                                                                                                          \
        _Generic(x,                                                                                                                                  \
            char                : ___abs_char,                                                                                                       \
            is8_t               : ___abs_is8 ,                                                                                                       \
            is16_t              : ___abs_is16,                                                                                                       \
            is32_t              : ___abs_is32,                                                                                                       \
            is64_t              : ___abs_is64,                                                                                                       \
            us8_t               : ___abs_us8 ,                                                                                                       \
            us16_t              : ___abs_us16,                                                                                                       \
            us32_t              : ___abs_us32,                                                                                                       \
            us64_t              : ___abs_us64,                                                                                                       \
            float               : fabsf      ,                                                                                                       \
            double              : fabs       ,                                                                                                       \
            long double         : fabsl      ,                                                                                                       \
            float complex       : cabsf      ,                                                                                                       \
            double complex      : cabs       ,                                                                                                       \
            long double complex : cabsl      ,                                                                                                       \
            default             : 0          )(x)                                                                                                    \
    ))

#define abs_chk(result, x)                                                                                                                           \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((result), (x), _result, _x, __abs_chk((result), _x))

#define __abs_chk(result, x)                                                                                                                         \
    BLOCK(__is_abs(x) ? BLOCK(__as((result), __abs(x)); true) : BLOCK(false))

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Расстояние между значениями
 * Distance
*/
#define dis(x, y)                                                                                                                                    \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __dis(_x, _y))

#define __dis(x, y)                                                                                                                                  \
    BLOCK(__dif(__max(x, y), __min(x, y)))

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Обратное число по сложению
 * Additive inverse
*/
#define is_inv_add(x)                                                                                                                                \
    COMPILE_1_CALC((x), _x, BLOCK(__is_inv_add(_x)))

#define __is_inv_add(x)                                                                                                                              \
    BLOCK(__is_pos(x) ? __is_to_neg(x) : __is_to_pos(x))

#define inv_add(x)                                                                                                                                   \
    COMPILE_1_CALC((x), _x, BLOCK(__inv_add(_x)))

#define __inv_add(x)                                                                                                                                 \
    BLOCK(base_type_cast((x), (-(x))))

#define inv_add_chk(result, x)                                                                                                                       \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((result), (x), _result, _x, __inv_add_chk((result), _x))

#define __inv_add_chk(result, x)                                                                                                                     \
    BLOCK(__is_inv_add(x) ? BLOCK(__as((result), __inv_add(x)); true) : BLOCK(false))

/*
 * Обратное число по умножению
 * Multiplicative inverse
*/
#define is_inv_mul(x)                                                                                                                                \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC(BASE_TYPE_GROUP_FLT, (x), _x, __is_inv_mul(_x))

#define __is_inv_mul(x)                                                                                                                              \
    BLOCK(__is_not_zero(x))

#define inv_mul(x)                                                                                                                                   \
    COMPILE_ASSERT_GROUP_MATCH_1_CALC(BASE_TYPE_GROUP_FLT, (x), _x, __inv_mul(_x))

#define __inv_mul(x)                                                                                                                                 \
    BLOCK(__qut(one(x), (x)))

#define inv_mul_chk(result, x)                                                                                                                       \
    COMPILE_ASSERT_GROUP_MATCH_2_CALC(BASE_TYPE_GROUP_FLT, (result), (x), _result, _x, __inv_mul_chk((result), _x))

#define __inv_mul_chk(result, x)                                                                                                                     \
    BLOCK(__is_inv_mul(x) ? BLOCK(__as((result), __inv_mul(x)); true) : BLOCK(false))

//================= ИТЕРАЦИЯ ПО ЧИСЛАМ ===============================================================================================================
/*
 * Следующее представимое число, по направлению к отрицательной бесконечности
*/
#define num_prev(x)                                                                                                                                  \
    COMPILE_1_CALC((x), _x, __num_prev(_x))

#define __num_prev(x)                                                                                                                                \
    BLOCK(                                                                                                                                           \
        _Generic((x),                                                                                                                                \
            float       : __num_prev_flt((x)),                                                                                                       \
            double      : __num_prev_flt((x)),                                                                                                       \
            long double : __num_prev_flt((x)),                                                                                                       \
            default     : __num_prev_int((x)))                                                                                                       \
    )

#define __num_prev_int(x) BLOCK(base_type_cast((x), __eq((x), base_type_min(x)) ? (x) : (x) - one(x)))
#define __num_prev_flt(x) BLOCK(base_type_cast((x), nextafter((x), neg_inf(x))))

/*
 * Следующее представимое число, по направлению к положительной бесконечности
*/
#define num_next(x)                                                                                                                                  \
    COMPILE_1_CALC((x), _x, __num_next(_x))

#define __num_next(x)                                                                                                                                \
    BLOCK(                                                                                                                                           \
        _Generic((x),                                                                                                                                \
            float       : __num_next_flt(x),                                                                                                         \
            double      : __num_next_flt(x),                                                                                                         \
            long double : __num_next_flt(x),                                                                                                         \
            default     : __num_next_int(x))                                                                                                         \
    )

#define __num_next_int(x) BLOCK(base_type_cast((x), __eq((x), base_type_max(x)) ? (x) : (x) + one(x)))
#define __num_next_flt(x) BLOCK(base_type_cast((x), nextafter((x), pos_inf(x))))

/*
 * Следующее представимое число, по направлению к числу
*/
#define num_appr(x, n)                                                                                                                               \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (n), _x, _n, __num_appr(_x, _n))

#define __num_appr(x, n)                                                                                                                             \
    BLOCK(                                                                                                                                           \
        _Generic((x),                                                                                                                                \
            float       : __num_appr_flt(x, n),                                                                                                      \
            double      : __num_appr_flt(x, n),                                                                                                      \
            long double : __num_appr_flt(x, n),                                                                                                      \
            default     : __num_appr_int(x, n))                                                                                                      \
    )

#define __num_appr_int(x, n) BLOCK(base_type_cast((x), __eq((x), (n)) ? (x) : (__gt((x), (n)) ? __num_prev_int(x) : __num_next_int(x))))
#define __num_appr_flt(x, n) BLOCK(base_type_cast((x), nextafter((x), (n))))

//================= ПРЕОБРАЗОВАНИЕ ЗНАЧЕНИЯ ==========================================================================================================
/*
 * Масштабирует значение
*/
#define scale(x, get_min, get_max, to_min, to_max)                                                                                                   \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC((get_min), (get_max), ( x), _gmin, _gmax, _x,                                                                   \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC(( to_min), ( to_max), (_x), _tmin, _tmax, _v,                                                                   \
        BLOCK(__scale(_x, _gmin, _gmax, _tmin, _tmax))))

#define __scale(x, get_min, get_max, to_min, to_max)                                                                                                 \
    BLOCK(__sum(__mul(__dif(x, get_min), base_type_cast(x, __qut(dis(to_min, to_max), __dis(get_min, get_max)))), to_min))

/*
 * Усекает значение
*/
#define clamp(x, min, max)                                                                                                                           \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC((x), (min), (max), _x, _min, _max, __clamp(_x, _min, _max))

#define __clamp(x, min, max)                                                                                                                         \
    BLOCK(__lt((x), (min)) ? (min) : (__gt((x), (max)) ? (max) : (x)))

//================= ПОИСК МИНИМАЛЬНОГО И МАКСИМАЛЬНОГО ЗНАЧЕНИЯ ======================================================================================
/*
 * Установка начальных значений
*/
#define minmax_init(min, max)                                                                                                                        \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((min), (max), _min, _max, BLOCK((min) = base_type_max(_max); (max) = base_type_min(_min)))

/*
 * Минимальное из чисел
*/
#define min(x, y)                                                                                                                                    \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __min(_x, _y))

#define __min(x, y)                                                                                                                                  \
    BLOCK(base_type_cast((x), __lt((x), (y)) ? (x) : (y)))

/*
 * Максимальное из чисел
*/
#define max(x, y)                                                                                                                                    \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __max(_x, _y))

#define __max(x, y)                                                                                                                                  \
    BLOCK(base_type_cast((x), __gt((x), (y)) ? (x) : (y)))

/*
 * Минимальное из чисел, но не ноль
*/
#define min_not_zero(x, y)                                                                                                                           \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __min_not_zero(_x, _y))

#define __min_not_zero(x, y)                                                                                                                         \
    BLOCK(__is_zero(x) ? (y) : BLOCK(__is_zero(y) ? (x) : __min(x, y)))

/*
 * Максимальное из чисел, но не ноль
*/
#define max_not_zero(x, y)                                                                                                                           \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __max_not_zero(_x, _y))

#define __max_not_zero(x, y)                                                                                                                         \
    BLOCK(__is_zero(x) ? (y) : BLOCK(__is_zero(y) ? (x) : __max(x, y)))

/*
 * Определяет число как минимальное или максимальное и помещает его в соответствующий аргумент
*/
#define minmax_set(x, min, max)                                                                                                                      \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC((x), (min), (max), _x, _min, _max,                                                                              \
        BLOCK((min) = __min(_min, _x); (max) = __max(_max, _x)))

/*
 * Определяет число как минимальное или максимальное, но не ноль и помещает его в соответствующий аргумент
*/
#define minmax_not_zero_set(x, min, max)                                                                                                             \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC((x), (min), (max), _x, _min, _max,                                                                              \
        BLOCK((min) = __min_not_zero(_min, _x); (max) = __max_not_zero(_max, _x)))

//================= СПЕЦИАЛИЗИРОВАНЫЕ МАТЕМАТИЧЕСКИЕ ФУНКЦИИ =========================================================================================

umax_t ___gcd(umax_t u, umax_t v);
umax_t ___lcm(umax_t u, umax_t v);

/*
 * Наибольший общий делитель
 * Greatest common divisor
 * Принимает:  Два числа типа umax_t
 * Возвращает: Типа umax_t
*/
#define gcd(x, y)                                                                                                                                    \
    COMPILE_ASSERT_TYPE_MATCH_2_CALC(umax_t, (x), (y), _x, _y,                                                                                       \
        BLOCK(__gcd(_x, _y)))

#define __gcd(x, y)                                                                                                                                  \
    BLOCK(___gcd((x), (y)))

/*
 * Наименьшее общее кратное чисел
 * Least common multiple
 * Принимает:  Два числа типа umax_t
 * Возвращает: Типа umax_t
*/
#define lcm(x, y)                                                                                                                                    \
    COMPILE_ASSERT_TYPE_MATCH_2_CALC(umax_t, (x), (y), _x, _y,                                                                                       \
        BLOCK(__lcm(_x, _y)))

#define __lcm(x, y)                                                                                                                                  \
    BLOCK(___lcm((x), (y)))

//----------------------------------------------------------------------------------------------------------------------------------------------------





















































//====================================================================================================================================================

//================= ОПРЕДЕЛЕНИЕ ФУНКЦИЙ ==============================================================================================================

char   ___pow_char(char   x, char   p);
is8_t  ___pow_is8 (is8_t  x, is8_t  p);
is16_t ___pow_is16(is16_t x, is16_t p);
is32_t ___pow_is32(is32_t x, is32_t p);
is64_t ___pow_is64(is64_t x, is64_t p);
us8_t  ___pow_us8 (us8_t  x, us8_t  p);
us16_t ___pow_us16(us16_t x, us16_t p);
us32_t ___pow_us32(us32_t x, us32_t p);
us64_t ___pow_us64(us64_t x, us64_t p);

umax_t ___isqrt(umax_t x);

//================= БАЗОВЫЕ МАТЕМАТИЧЕСКИЕ ОПЕРАЦИИ ==================================================================================================
/*
 * Сумма двух чисел
*/
#define chk_sum_args(x, y)                                                                                                                            \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __chk_sum_args(_x, _y))

#define __chk_sum_args(x, y)                                                                                                                          \
    BLOCK(true)


#define chk_sum_overflow(x, y)                                                                                                                        \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y,  __chk_sum_overflow(_x, _y))

#define __chk_sum_overflow(x, y)                                                                                                                      \
    BLOCK(__is_pos(x) ? BLOCK((y) > (base_type_max(y) - (x))) : BLOCK((y) < (base_type_min((y)) - (x))))


#define chk_sum_overflow_range(x, y, range)                                                                                                           \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC((x), (y), (range), _x, _y, _range, __chk_sum_overflow_range(_x, _y, _range))

#define __chk_sum_overflow_range(x, y, range)                                                                                                         \
    BLOCK(                                                                                                                                           \
        COMPTIME_ASSERT((r) >  one(r));                                                                                                              \
        COMPTIME_ASSERT((r) <= base_type_max(x));                                                                                                    \
        BLOCK(__is_pos(x) ? BLOCK((y) > (range) - (x)) : BLOCK((y) < (-(range)) - (x))))


#define sum(x, y)                                                                                                                                    \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __sum(_x, _y))

#define __sum(x, y)                                                                                                                                  \
    BLOCK(base_type_cast((x), (x) + (y)))


#define sum_chk(result, x, y)                                                                                                                        \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC((result), (x), (y), _result, _x, _y, __sum_chk((result), _x, _y))

#define __sum_chk(result, x, y)                                                                                                                      \
    BLOCK(__chk_sum_overflow(x, y) ? BLOCK(true) : BLOCK(__as(result,  __sum(x, y)); false))


#define sum_mod(x, y)                                                                                                                                \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __sum_mod(_x, _y))

#define __sum_mod(x, y)                                                                                                                              \
    BLOCK(base_type_cast((x), (x) + (y)))


#define sum_mod_range(x, y, range)                                                                                                                   \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __sum_mod_range(_x, _y))

#define __sum_mod_range(x, y, range)                                                                                                                 \
    BLOCK(base_type_cast((x), ((x) % (range)) + ((y) % (range))))


#define sum_sat(x, y)                                                                                                                                \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __sum_sat(_x, _y))

#define __sum_sat(x, y)                                                                                                                              \
    BLOCK(__chk_sum_overflow(x, y) ? BLOCK(base_type_max(y)) : BLOCK(__sum(x, y)))


#define sum_sat_range(x, y, range)                                                                                                                   \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC((x), (y), (range), _x, _y, _range, __sum_sat_range(_x, _y, _range))

#define __sum_sat_range(x, y, range)                                                                                                                 \
    BLOCK(__chk_sum_overflow_range(x, y, range) ? BLOCK(range) : BLOCK(__sum(x, y)))

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Разность двух чисел
*/
#define chk_dif_args(x, y)                                                                                                                            \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __chk_dif_args(_x, _y))

#define __chk_dif_args(x, y)                                                                                                                          \
    BLOCK(true)


#define chk_dif_overflow(x, y)                                                                                                                        \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __chk_dif_overflow(_x, _y))

#define __chk_dif_overflow(x, y)                                                                                                                      \
    BLOCK(                                                                                                                                           \
        COMPILE_NO_SIDE_EFFECT_VARIABLE((x), _result);                                                                                               \
        __builtin_sub_overflow(x, y, &_result))                      /*TODO: а так ли нужен __builtin? */


#define chk_dif_overflow_range(x, y, range)                                                                                                           \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC((x), (y), (range), _x, _y, _range, __chk_dif_overflow_range(_x, _y, _range))

#define __chk_dif_overflow_range(x, y, r)                                                                                                             \
    BLOCK(                                                                                                                                           \
        COMPTIME_ASSERT((r) >= one(r));                                                                                                              \
        COMPTIME_ASSERT((r) <= base_type_max(x));                                                                                                    \
        COMPILE_NO_SIDE_EFFECT_VARIABLE((x), res);                                                                                                   \
        __builtin_sub_overflow(x, y, &res) )   /*TODO: не уверен в правильности */


#define dif(x, y)                                                                                                                                    \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __dif(_x, _y))

#define __dif(x, y)                                                                                                                                  \
    BLOCK(base_type_cast((x), (x) - (y)))


#define dif_chk(result, x, y)                                                                                                                        \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC((result), (x), (y), _result, _x, _y, __dif_chk(result, _x, _y))

#define __dif_chk(result, x, y)                                                                                                                      \
    BLOCK(__chk_dif_overflow(x, y) ? BLOCK(true) : BLOCK(__as(result, __dif(x, y)); false))


#define dif_mod(x, y)                                                                                                                                \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __dif_mod(_x, _y))

#define __dif_mod(x, y)                                                                                                                              \
    BLOCK()


#define dif_mod_range(x, y, range)                                                                                                                   \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), (range), _x, _y, _range, __dif_mod_range(_x, _y, _range))

#define __dif_mod_range(x, y, range)                                                                                                                 \
    BLOCK()


#define dif_sat(x, y)                                                                                                                                \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __dif_sat(_x, _y))

#define __dif_sat(x, y)                                                                                                                              \
    BLOCK()


#define dif_sat_range(x, y, range)                                                                                                                   \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC((x), (y), (range), _x, _y, _range, __dif_sat_range(_x, _y, _range))

#define __dif_sat_range(x, y, range)                                                                                                                 \
    BLOCK()

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Произведение двух чисел
*/
#define chk_mul_args(x, y)                                                                                                                            \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __chk_mul_args(_x, _y))

#define __chk_mul_args(x, y)                                                                                                                          \
    BLOCK(true)


#define chk_mul_overflow(x, y)                                                                                                                        \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __chk_mul_overflow(_x, _y))

#define __chk_mul_overflow(x, y)                                                                                                                      \
    BLOCK(                                                                                                                                           \
        COMPILE_NO_SIDE_EFFECT_VARIABLE((x), res);                                                                                                   \
        __builtin_mul_overflow(x, y, &res))                      /*TODO: а так ли нужен __builtin? TODO: и слачаи с -128 * -1? */


#define is_mul_overflow_range(x, y, range)                                                                                                           \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC((x), (y), (range), _x, _y, _range, __is_mul_overflow_range(_x, _y, _range))

#define __is_mul_overflow_range(x, y, r)                                                                                                             \
    BLOCK()


#define mul(x, y)                                                                                                                                    \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __mul(_x, _y))

#define __mul(x, y)                                                                                                                                  \
    BLOCK(base_type_cast((x), (x) * (y)))


#define mul_chk(result, x, y)                                                                                                                        \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC((result), (x), (y), _result, _x, _y, __mul_chk((result), _x, _y))

#define __mul_chk(result, x, y)                                                                                                                      \
    BLOCK(__chk_mul_overflow(x, y) ? BLOCK(true) : BLOCK(__as(result, __mul(x, y)); false))


#define mul_mod(x, y)                                                                                                                                \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __mul_mod(_x, _y))

#define __mul_mod(x, y)                                                                                                                              \
    BLOCK()


#define mul_mod_range(x, y, range)                                                                                                                   \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC((x), (y), (range), _x, _y, _range, __mul_mod_range(_x, _y, _range))

#define __mul_mod_range(x, y, range)                                                                                                                 \
    BLOCK()


#define mul_sat(x, y)                                                                                                                                \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __mul_sat(_x, _y))

#define __mul_sat(x, y)                                                                                                                              \
    BLOCK()


#define mul_sat_range(x, y, range)                                                                                                                   \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC((x), (y), (range), _x, _y, _range, __mul_mod_range(_x, _y, _range))

#define __mul_sat_range(x, y, range)                                                                                                                 \
    BLOCK()

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Целое от деления или усеченное деление двух чисел
 * При делении отбрасывается дробная часть, или другими словами просходит округление к нулю
 * Остаток вычислется функцией mod или rem
*/
#define chk_div_args(x, y)                                                                                                                            \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __chk_div_args(_x, _y))

#define __chk_div_args(x, y)                                                                                                                          \
    BLOCK(is_zero(y) || (((x) == base_type_min(x)) && ((y) == -one(y))))


#define div(x, y)                                                                                                                                    \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __div(_x, _y))

#define __div(x, y)                                                                                                                                  \
    BLOCK(                                                                                                                                           \
        COMPILE_SIGN_CHECK(BASE_TYPE_SIGN_SIGNUM, (x))            ?                                                                                  \
        base_type_cast((x), base_type_cast(imax_t, ((x) / (y))))  :                                                                                  \
        base_type_cast((x), base_type_cast(umax_t, ((x) / (y))))  )


#define div_chk(result, x, y)                                                                                                                        \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC((result), (x), (y), _result, _x, _y, __div_chk((result), _x, _y))

#define __div_chk(result, x, y)                                                                                                                      \
    BLOCK(__chk_div_args(x, y) ? BLOCK(true) : BLOCK(__as(result, __div(x, y)); false))

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Остаток от деления
 * При взятии остатка знак остатка равен знаку делимого
 * Частное вычисляется функцией div
*/
#define is_mod_args(x, y)                                                                                                                            \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __is_mod_args(_x, _y))

#define __is_mod_args(x, y)                                                                                                                          \
    BLOCK(is_zero(y) || (((x) == base_type_min(x)) && ((y) == -one(y))))


#define mod(x, y)                                                                                                                                    \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __mod(_x, _y))

#define __mod(x, y)                                                                                                                                  \
    BLOCK(                                                                                                                                           \
        COMPILE_GROUP_CHECK(BASE_TYPE_GROUP_CHAR | BASE_TYPE_GROUP_SINT | BASE_TYPE_GROUP_UINT, (x))   ?                                             \
        __mod_int(COMPILE_INT_VAR_OR_ZERO(x), COMPILE_INT_VAR_OR_ZERO(y))                              :                                             \
        __mod_flt(COMPILE_FLT_VAR_OR_ZERO(x), COMPILE_FLT_VAR_OR_ZERO(y))                              )

#define __mod_int(x, y) BLOCK((x) % (y))
#define __mod_flt(x, y) BLOCK(base_type_cast((x), fmod((x), (y))))


#define mod_chk(result, x, y)                                                                                                                        \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC((result), (x), (y), _result, _x, _y, __mod_chk((result), _x, _y))

#define __mod_chk(result, x, y)                                                                                                                      \
    BLOCK(__is_mod_args(x, y) ? BLOCK(true) : BLOCK(__as(result, __mod(x, y)); false))

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Остаток от деления
 * При взятии остатка знак остатка равен знаку делителя
 * Частное вычисляется функцией div
*/
#define is_rem_args(x, y)                                                                                                                            \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __is_rem_args(_x, _y))

#define __is_rem_args(x, y)                                                                                                                          \
    BLOCK(is_zero(y) || (((x) == base_type_min(x)) && ((y) == -one(y))))


#define rem(x, y)                                                                                                                                    \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __rem(_x, _y))

#define __rem(x, y)                                                                                                                                  \
    BLOCK(                                                                                                                                           \
        COMPILE_GROUP_CHECK(BASE_TYPE_GROUP_CHAR | BASE_TYPE_GROUP_SINT | BASE_TYPE_GROUP_UINT, (x))   ?                                             \
        __rem_int(COMPILE_INT_VAR_OR_ZERO(x), COMPILE_INT_VAR_OR_ZERO(y))                              :                                             \
        __rem_flt(COMPILE_FLT_VAR_OR_ZERO(x), COMPILE_FLT_VAR_OR_ZERO(y))                              )

#define __rem_int(x, y) BLOCK((x) - ((x) / (y)) * (y))
#define __rem_flt(x, y) BLOCK(base_type_cast((x), remainder((x), (y))))


#define rem_chk(result, x, y)                                                                                                                        \
    COMPILE_ASSERT_TYPE_EQUAL_3_CALC((result), (x), (y), _result, _x, _y, __rem_chk((result), _x_rem, _y_rem))

#define __rem_chk(r, x, y)                                                                                                                           \
    BLOCK(__is_rem_args(x, y) ? BLOCK(true) : BLOCK(__as(result, __rem(x, y)); false))

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Полное деление
*/
#define is_qut_args(x, y)                                                                                                                            \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __is_qut_args(_x, _y))

#define __is_qut_args(x, y)                                                                                                                          \
    BLOCK(is_zero(y))


#define qut(x, y)                                                                                                                                    \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __qut(_x, _y))

#define __qut(x, y)                                                                                                                                  \
    BLOCK(base_type_cast(fmax_t, base_type_cast(fmax_t, (x)) / base_type_cast(fmax_t, (y))))


#define qut_chk(result, x, y)                                                                                                                             \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __qut_chk((result), _x, _y))

#define __qut_chk(result, x, y)                                                                                                                           \
    BLOCK(__is_qut_args(x, y) ? BLOCK(true) : BLOCK(__as(result, __qut(x, y)); false))

//----------------------------------------------------------------------------------------------------------------------------------------------------



































/*
 * Возведение в степень
 * Power
 * Принимает:  Два числа типа Х
 * Возвращает: Результат возведение в степень типа X
*/
#define powm(x, p)                                                                                                                                   \
    BLOCK(                                                                                                                                            \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (p), _x_pow, _p_pow,                                                                                                       \
    BLOCK(__powm(_x_pow, _p_pow))))

#define __powm(x, p) BLOCK(                                                                                                                           \
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
    BLOCK(                                                                                                                                            \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x_pow, _y_pow,                                                                                                       \
    BLOCK(__pow_chk((r), _x_pow, _y_pow))))

#define __pow_chk(r, x, y)                                                                                                                           \
    BLOCK(                                                                                                                                            \
    UNIT(is_pow(x, y))                         ?                                                                                                     \
    BLOCK(__as(r,      zero(r)); true )         :                                                                                                     \
    BLOCK(__as(r, __powm(x, y)); false))

/*
 * Проверка, что операнды дадут переполнение или ошибку выполнения
*/
#define is_pow(x, y)                                                                                                                                 \
    BLOCK((is_zero(y) && is_zero(y)) || is_fp_nan(x) || is_fp_nan(y))

//----------------------------------------------------------------------------------------------------------------------------------------------------

/*
 * Извлечение корня по основанию
 * Root
 * Принимает:  Два числа типа Х
 * Возвращает: Результат извлечение корня типа X
*/
#define root(x, r)                                                                                                                                   \
    BLOCK(                                                                                                                                            \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (r), _x_rot, _r_rot,                                                                                                       \
    BLOCK(__root(_x_rot, _r_rot))))

#define __root(x, r)                                                                                                                                 \
    BLOCK(                                                                                                                                            \
    __powm((x), base_type_cast(x, (1.0 / r))))

/*
 * Извлечение корня по основанию с проверкой
*/
#define root_chk(r, x, y)                                                                                                                            \
    BLOCK(                                                                                                                                            \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x_rot, _y_rot,                                                                                                       \
    BLOCK(__root_chk((r), _x_rot, _y_rot))))

#define __root_chk(r, x, y)                                                                                                                          \
    BLOCK(                                                                                                                                            \
    UNIT(is_root(x, y))                        ?                                                                                                     \
    BLOCK(__as(r,      zero(r)); true )         :                                                                                                     \
    BLOCK(__as(r, __root(x, y)); false))

/*
 * Проверка, что операнды дадут переполнение или ошибку выполнения
*/
#define is_root(x, y)                                                                                                                                \
    BLOCK((is_zero(y) && is_zero(y)) || is_fp_nan(x) || is_fp_nan(y))

//----------------------------------------------------------------------------------------------------------------------------------------------------

/*
 * Логарифм числа по основанию
 * Logarithm
 * Принимает:  Два числа типа Х
 * Возвращает: Результат логарифмирования типа X
*/
#define logm(x, l)                                                                                                                                   \
    BLOCK(                                                                                                                                            \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (l), _x_log, _l_log,                                                                                                       \
    BLOCK(__logm(_x_log, _l_log))))

#define __logm(x, l)                                                                                                                                 \
    BLOCK(__log_flt(x) / __log_flt(l))

#define __log_flt(x)                                                                                                                                 \
    BLOCK(                                                                                                                                            \
    _Generic(x,                                                                                                                                      \
    float: logf,                                                                                                                                     \
    double: log,                                                                                                                                     \
    long double: logl,                                                                                                                               \
    float complex: clogf,                                                                                                                            \
    double complex: clog,                                                                                                                            \
    long double complex: clogl,                                                                                                                      \
    default: 0)(x))

/*
 * Логарифм числа по основанию с проверкой
*/
#define logm_chk(r, x, y)                                                                                                                            \
    BLOCK(                                                                                                                                            \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x_log, _y_log,                                                                                                       \
    BLOCK(__logm_chk((r), _x_log, _y_log))))

#define __logm_chk(r, x, y)                                                                                                                          \
    BLOCK(                                                                                                                                            \
    UNIT(is_logm(x, y))                        ?                                                                                                     \
    BLOCK(__as(r,      zero(r)); true )         :                                                                                                     \
    BLOCK(__as(r, __logm(x, y)); false))

/*
 * Проверка, что операнды дадут переполнение или ошибку выполнения
*/
#define is_logm(x, y)                                                                                                                                \
    BLOCK((is_zero(y) && is_zero(y)) || is_fp_nan(x) || is_fp_nan(y))

//----------------------------------------------------------------------------------------------------------------------------------------------------

/*
 * Обратные величины
 * Z ÷ a = b -> div(Z, a) ~> div(b, Z) || mul(a, b)
 * Z / a = b -> qut(Z, a) ~> qut(b, Z) || mul(a, b)
 * X ^ Y = Z -> pow(X, Y) ~> log(Z, X) || rot(Z, Y)
 * Y √ Z = X -> rot(Z, Y) ~> pow(X, Y) || log(Z, X)
 * Z _ X = Y -> log(Z, X) ~> rot(Y, Z) || pow(X, Y)
*/

//====================================================================================================================================================

END_C_DECLARATION
// clang-format on
#endif /*YAYA_ARITHMETIC_H*/
