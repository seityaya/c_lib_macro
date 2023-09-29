// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_BIT_H
#define YAYA_BIT_H

#include "limits.h"
#include "stddef.h"

#include "yaya_arithmetic.h"
#include "yaya_cdecl.h"
#include "yaya_check.h"
#include "yaya_type.h"

// clang-format off
BEG_C_DECLARATION

//================= BIT ==============================================================================================================================
/*
 * В данных операциях биты нумеруются с 1, если указан 0, то изменений не происходит
 * Если функция возвращает результат, то он тоже нумерует биты c 1
*/

//================= ОПРЕДЕЛЕНИЕ ФУНКЦИЙ ==============================================================================================================

imax_t ___bit_0_beg(umax_t x, umax_t s);
imax_t ___bit_0_end(umax_t x, umax_t s);
imax_t ___bit_0_cnt(umax_t x, umax_t s);
imax_t ___bit_0_pos(umax_t x, umax_t s);

imax_t ___bit_1_beg(umax_t x, umax_t s);
imax_t ___bit_1_end(umax_t x, umax_t s);
imax_t ___bit_1_cnt(umax_t x, umax_t s);
imax_t ___bit_1_pos(umax_t x, umax_t s);

umax_t ___bit_revers(umax_t x, umax_t s);
umax_t ___bit_sequence(void *ptr, imax_t offset, imax_t len);

//================= ПРОВЕРКА ЧИСЕЛ НА СООТВЕТСТВИЕ ===================================================================================================
/*
 * Проверка, что значение истина
*/
#define is_true(x)                                                                                                                                   \
    BLOCK((x) == true)

/*
 * Проверка, что значение ложь
*/
#define is_false(x)                                                                                                                                  \
    BLOCK((x) == false)

//================= БИТОВЫЕ ОПЕРАЦИИ =================================================================================================================
/*
 * Битовое НЕ
*/
#define bit_not(x)                                                                                                                                   \
    COMPILE_1_CALC((x), _x, __bit_not(_x))

#define __bit_not(x)                                                                                                                                 \
    base_type_cast((x), (~(x)))

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Битовое И
*/
#define bit_and(x, y)                                                                                                                                \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __bit_and(_x, _y))

#define __bit_and(x, y)                                                                                                                              \
    base_type_cast((x), ((x) & (y)))

/*
 * Битовое ИЛИ
*/
#define bit_or(x, y)                                                                                                                                 \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __bit_or(_x, _y))

#define __bit_or(x, y)                                                                                                                               \
    base_type_cast((x), ((x) | (y)))

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Битовое И-НЕ
*/
#define bit_nand(x, y)                                                                                                                               \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __bit_nand(_x, _y))

#define __bit_nand(x, y)                                                                                                                             \
    __bit_not(__bit_and((x), (y)))

/*
 * Битовое ИЛИ-НЕ
*/
#define bit_nor(x, y)                                                                                                                                \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __bit_nor(_x, _y))

#define __bit_nor(x, y)                                                                                                                              \
    __bit_not(__bit_or((x), (y)))

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Битовое ИСЛЮЧАЮЩЕЕ И
*/
#define bit_xand(x, y)                                                                                                                               \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __bit_xand(_x, _y))

#define __bit_xand(x, y)                                                                                                                             \
    __bit_not(__bit_xor(x, y))

/*
 * Битовое ИСЛЮЧАЮЩЕЕ ИЛИ
*/
#define bit_xor(x, y)                                                                                                                                \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((x), (y), _x, _y, __bit_xor(_x, _y))

#define __bit_xor(x, y)                                                                                                                              \
    base_type_cast((x), ((x) ^ (y)))

//================= БИТОВЫЕ МАСКИ ====================================================================================================================
/*
 * Выставление битов по единичной маске
*/
#define bit_mask_up(val, mask)                                                                                                                       \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((val), (mask), _val, _mask, __bit_mask_up(_val, _mask))

#define __bit_mask_up(val, mask)                                                                                                                     \
    base_type_cast((val), ((val) | (mask)))

/*
 * Обнуление битов по единичной маске
*/
#define bit_mask_dw(val, mask)                                                                                                                       \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((val), (mask), _val, _mask, __bit_mask_dw(_val, _mask))

#define __bit_mask_dw(val, mask)                                                                                                                     \
    base_type_cast((val), ((val) & (~(mask))))

/*
 * Инвертирование битов по единичной маске
*/
#define bit_mask_in(val, mask)                                                                                                                       \
    COMPILE_ASSERT_TYPE_EQUAL_2_CALC((val), (mask), _val, _mask, __bit_mask_in(_val, _mask))

#define __bit_mask_in(val, mask)                                                                                                                     \
    base_type_cast((val), ((val) ^ (mask)))

//================= ПОДСЧЕТ И ПОИСК БИТОВ ============================================================================================================
/*
 * Возвращает количество битов в байтах
*/
#define bit_cnt_to_byte(x)                                                                                                                           \
    COMPILE_1_CALC((x), _x, __bit_cnt_to_byte_cnt(_x))

#define __bit_cnt_to_byte_cnt(x)                                                                                                                     \
    base_type_cast(imax_t, (x) * CHAR_BIT)

/*
 * Возвращает количество битов в типе
*/
#define bit_cnt_to_type(x)                                                                                                                           \
    COMPILE_1_CALC((x), _x, __bit_cnt_to_type(_x))

#define __bit_cnt_to_type(x)                                                                                                                         \
    base_type_cast(imax_t, sizeof(x) * CHAR_BIT)

/*
 * Опустить все биты в 0
*/
#define bit_0_all(x)                                                                                                                                 \
    COMPILE_1_CALC((x), _x, __bit_0_all(_x))

#define __bit_0_all(x)                                                                                                                               \
    base_type_cast(imax_t, umax_c(0))

/*
 * Вернуть позицию первого опущеного бита
*/
#define bit_0_beg(x)                                                                                                                                 \
    COMPILE_1_CALC((x), _x, __bit_0_beg(_x))

#define __bit_0_beg(x)                                                                                                                               \
    ___bit_0_beg(base_type_cast(umax_t, (x)), sizeof(x))

/*
 * Вернуть позицию последнего опущеного бита
*/
#define bit_0_end(x)                                                                                                                                 \
    COMPILE_1_CALC((x), _x, __bit_0_end(_x))

#define __bit_0_end(x)                                                                                                                               \
    ___bit_0_end(base_type_cast(umax_t, (x)), sizeof(x))

/*
 * Подсчитать количество опущеных битов
*/
#define bit_0_cnt(x)                                                                                                                                 \
    COMPILE_1_CALC((x), _x, __bit_0_cnt(_x))

#define __bit_0_cnt(x)                                                                                                                               \
    ___bit_0_cnt(base_type_cast(umax_t, (x)), sizeof(x))

/*
 * Вернуть позицию одного опущенного бита, если битов несколько, то -1
*/
#define bit_0_pos(x)                                                                                                                                 \
    COMPILE_1_CALC((x), _x, __bit_0_pos(_x))

#define __bit_0_pos(x)                                                                                                                               \
    ___bit_0_pos(base_type_cast(umax_t, (x)), sizeof(x))

/*
 * Поднять все биты в 1
*/
#define bit_1_all(x)                                                                                                                                 \
    COMPILE_1_CALC((x), _x, __bit_1_all(_x))

#define __bit_1_all(x)                                                                                                                               \
    base_type_cast((x), (umax_c(0) - umax_c(1)))

/*
 * Вернуть позицию первого взведенного бита
*/
#define bit_1_beg(x)                                                                                                                                 \
    COMPILE_1_CALC((x), _x, __bit_1_beg(_x))

#define __bit_1_beg(x)                                                                                                                               \
    ___bit_1_beg(base_type_cast(umax_t, (x)), sizeof(x))

/*
 * Вернуть позицию последнего взведенного бита
*/
#define bit_1_end(x)                                                                                                                                 \
    COMPILE_1_CALC((x), _x, __bit_1_end(_x))

#define __bit_1_end(x)                                                                                                                               \
    ___bit_1_end(base_type_cast(umax_t, (x)), sizeof(x))

/*
 * Подсчитать количество взведенных битов
*/
#define bit_1_cnt(x)                                                                                                                                 \
    COMPILE_1_CALC((x), _x, __bit_1_cnt(_x))

#define __bit_1_cnt(x)                                                                                                                               \
    ___bit_1_cnt(base_type_cast(umax_t, (x)), sizeof(x))

/*
 * Вернуть позицию одного единичного бита, если битов несколько, то -1
*/
#define bit_1_pos(x)                                                                                                                                 \
    COMPILE_1_CALC((x), _x, __bit_1_pos(_x))

#define __bit_1_pos(x)                                                                                                                               \
    ___bit_1_pos(base_type_cast(umax_t, (x)), sizeof(x))

//================= БИТОВЫЕ СДВИГИ ===================================================================================================================
/*
 * Логический сдвиг влево
*/
#define bit_shf_log_lef(x, n)                                                                                                                        \
    COMPILE_2_CALC((x), (n), _x, _n, __bit_shf_log_lef(_x, _n))

#define __bit_shf_log_lef(x, n)                                                                                                                      \
    base_type_cast((x), base_type_cast(umax_t, (x)) << (n))

/*
 * Логический сдвиг вправо
*/
#define bit_shf_log_rig(x, n)                                                                                                                        \
    COMPILE_2_CALC((x), (n), _x, _n, __bit_shf_log_rig(_x, _n))

#define __bit_shf_log_rig(x, n)                                                                                                                      \
    base_type_cast((x), __is_pos_or_zero(x) ? (x) >> (n) : __bit_set(__bit_res((x), __bit_cnt_to_type(x)) >> (n), __bit_cnt_to_type(x) - ((n))))

/*
 * Логический сдвиг относительно знака числа
 * +n - влево
 * -n - вправо
*/
#define bit_shf_log_vec(x, n)                                                                                                                        \
    COMPILE_2_CALC((x), (n), _x, _n, __bit_shf_log_vec(_x, _n))

#define __bit_shf_log_vec(x, n)                                                                                                                      \
    base_type_cast((x), is_pos(n) ? __bit_shf_log_lef((x), (n)) : __bit_shf_log_rig((x), (-(n))))

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Арифметический сдвиг влево
*/
#define bit_shf_ari_lef(x, n)                                                                                                                        \
    COMPILE_2_CALC((x), (n), _x, _n, __bit_shf_ari_lef(_x, _n))

#define __bit_shf_ari_lef(x, n)                                                                                                                      \
    base_type_cast((x), base_type_cast(umax_t, (x)) << (n))

/*
 * Арифметический сдвиг вправо
*/
#define bit_shf_ari_rig(x, n)                                                                                                                        \
    COMPILE_2_CALC((x), (n), _x, _n, __bit_shf_ari_rig(_x, _n))

#define __bit_shf_ari_rig(x, n)                                                                                                                      \
    base_type_cast((x), (x) >> (n))

/*
 * Арифметический сдвиг относительно знака числа
 * +n - влево
 * -n - вправо
*/
#define bit_shf_ari_vec(x, n)                                                                                                                        \
    COMPILE_2_CALC((x), (n), _x, _n, __bit_shf_ari_vec(_x, _n))

#define __bit_shf_ari_vec(x, n)                                                                                                                      \
    base_type_cast((x), is_pos_or_zero(n) ? __bit_shf_ari_lef((x), (n)) : __bit_shf_ari_rig((x), (-(n))))

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Циклический сдвиг влево
*/
#define bit_rot_lef(x, n)                                                                                                                            \
    COMPILE_2_CALC((x), (n), _x, _n, __bit_rot_lef(_x, _n))

#define __bit_rot_lef(x, n)                                                                                                                          \
    base_type_cast((x), is_zero(n) ? (x) : base_type_cast((x),                                                                                       \
    __bit_shf_log_lef((x), ((n) % __bit_cnt_to_type(x))) | __bit_shf_log_rig((x), (__bit_cnt_to_type(x) - ((n) % __bit_cnt_to_type(x))))))

/*
 * Циклический сдвиг вправо
*/
#define bit_rot_rig(x, n)                                                                                                                            \
    COMPILE_2_CALC((x), (n), _x, _n, __bit_rot_rig(_x, _n))

#define __bit_rot_rig(x, n)                                                                                                                          \
    base_type_cast((x), is_zero(n) ? (x) : base_type_cast((x),                                                                                       \
    __bit_shf_log_rig((x), ((n) % __bit_cnt_to_type(x))) | __bit_shf_log_lef((x), (__bit_cnt_to_type(x) - ((n) % __bit_cnt_to_type(x))))))

/*
 * Циклический сдвиг относительно знака числа
 * +n - влево
 * -n - вправо
*/
#define bit_rot_vec(x, n)                                                                                                                            \
    COMPILE_2_CALC((x), (n), _x, _n, __bit_rot_vec(_x, _n))

#define __bit_rot_vec(x, n)                                                                                                                          \
    base_type_cast((x), is_pos_or_zero(n) ? __bit_rot_rig((x), (n)) : __bit_rot_lef((x), (-(n))))

//================= ВЫСТАВЛЕНИЕ И ВОЗВРАТ БИТОВ ======================================================================================================
/*
 * Чтение бита на позии
*/
#define bit_get(x, n)                                                                                                                                \
    COMPILE_2_CALC((x), (n), _x, _n, __bit_get(_x, _n))

#define __bit_get(x, n)                                                                                                                              \
    base_type_cast((x), is_zero(n) ? false : (x) & (base_type_cast((x), 1) << (((base_type_cast((x), n) - 1) % __bit_cnt_to_type((x))))))

/*
 * Выставление бита  на позии
*/
#define bit_set(x, n)                                                                                                                                \
    COMPILE_2_CALC((x), (n), _x, _n, __bit_set(_x, _n))

#define __bit_set(x, n)                                                                                                                              \
    base_type_cast((x), is_neg_or_zero(n) ? (x) : ((x) | (base_type_cast((x), 1) << ((base_type_cast((x), n) - 1) % __bit_cnt_to_type((x))))))

/*
 * Сброс бита на позии
*/
#define bit_res(x, n)                                                                                                                                \
    COMPILE_2_CALC((x), (n), _x, _n, __bit_res(_x, _n))

#define __bit_res(x, n)                                                                                                                              \
    base_type_cast((x), is_zero(n) ? (x) : ((x) & (~(base_type_cast((x), 1) << ((base_type_cast((x), n) - 1) % __bit_cnt_to_type((x)))))))

/*
 * Переключение бита на позиции
*/
#define bit_tog(x, n)                                                                                                                                \
    COMPILE_2_CALC((x), (n), _x, _n, __bit_tog(_x, _n))

#define __bit_tog(x, n)                                                                                                                              \
    base_type_cast((x), is_zero(n) ? (x) : (x) ^ (base_type_cast((x), 1) << ((base_type_cast((x), n) - 1) % __bit_cnt_to_type((x)))))

/*
 * Выставление определенного бита на позиции
*/
#define bit_wrt(x, n, b)                                                                                                                             \
    COMPILE_3_CALC((x), (n), (b), _x, _n, _b, __bit_wrt(_x, _n, _b))

#define __bit_wrt(x, n, b)                                                                                                                           \
    base_type_cast((x), (b) ? __bit_set((x), (n)) : __bit_res((x), (n)))

/*
 * Инверсия битов в числе
*/
#define bit_inv(x)                                                                                                                                   \
    COMPILE_1_CALC((x), _x, __bit_inv(_x))

#define __bit_inv(x)                                                                                                                                 \
    base_type_cast((x), (~((umax_t)(x))))

/*
 * Смена порядка битов от начала к концу
*/
#define bit_rev(x)                                                                                                                                   \
    COMPILE_1_CALC((x), _x, __bit_rev(_x))

#define __bit_rev(x)                                                                                                                                 \
    base_type_cast((x), ___bit_revers(base_type_cast(umax_t, (x)), sizeof(x)))

/*
 * Возвращает значение по смещению и длине последовательности
*/
#define bit_seq(ptr, offset, len)                                                                                                               \
    COMPILE_3_CALC((ptr), (offset), (len), _p, _o, _l, __bit_seq(_p, _o, _l))

#define __bit_seq(ptr, offset, len)                                                                                                             \
    base_type_cast(umax_t, ___bit_sequence(ptr, offset, len))

//====================================================================================================================================================

END_C_DECLARATION
// clang-format on
#endif /*YAYA_BIT_H*/
