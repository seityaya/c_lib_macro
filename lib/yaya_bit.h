///Author                 : Seityagiya Terlekchi
///Contacts               : seityaya@ukr.net
///Creation Date          : 2020.05
///License Link           : https: spdx.org/licenses/LGPL-2.1-or-later.html
///SPDX-License-Identifier: LGPL-2.1-or-later
///Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_BIT_H
#define YAYA_BIT_H

#include "yaya_cdeclaration.h"
BEG_C_DECLARATION

#include "limits.h"

#include "yaya_number.h"
#include "yaya_chek.h"

/*
 * В данных операциях биты нумеруются с 1, если указан 0, то изменений не происходит
 * Если функция возвращает результат, то он тоже нумерует биты c 1
*/

/* = ОПРЕДЕЛЕНИЕ ФУНКЦИЙ ========================================================================================================================== */

imax_t ___bit_0_beg(umax_t x, umax_t s);
imax_t ___bit_0_end(umax_t x, umax_t s);
imax_t ___bit_0_cnt(umax_t x, umax_t s);
imax_t ___bit_0_pos(umax_t x, umax_t s);

imax_t ___bit_1_beg(umax_t x);
imax_t ___bit_1_end(umax_t x);
imax_t ___bit_1_cnt(umax_t x);
imax_t ___bit_1_pos(umax_t x);

umax_t ___bit_revers(umax_t x, umax_t s);
umax_t ___bit_sequence(void *ptr, umax_t offset, umax_t len);

/* = ПОДСЧЕТ И ПОИСК БИТОВ ======================================================================================================================== */

/*
 * Опустить все биты в 0
*/
#define bit_0_all(x)      typecast((x), umax_c(0))

/*
 * Вернуть позицию первого опущеного бита
*/
#define bit_0_beg(x)      ___bit_0_beg((umax_t)(x), sizeof(x))

/*
 * Вернуть позицию последнего опущеного бита
*/
#define bit_0_end(x)      ___bit_0_end((umax_t)(x), sizeof(x))

/*
 * Подсчитать количество опущеных битов
*/
#define bit_0_cnt(x)      ___bit_0_cnt((umax_t)(x), sizeof(x))

/*
 * Вернуть позицию одного опущенного бита, если битов несколько, то -1
*/
#define bit_0_pos(x)      ___bit_0_pos((umax_t)(x), sizeof(x))

/*
 * Поднять все биты в 1
*/
#define bit_1_all(x)      typecast((x), (umax_c(0) - umax_c(1)))

/*
 * Вернуть позицию первого взведенного бита
*/
#define bit_1_beg(x)      ___bit_1_beg((umax_t)(x))

/*
 * Вернуть позицию последнего взведенного бита
*/
#define bit_1_end(x)      ___bit_1_end((umax_t)(x))

/*
 * Подсчитать количество взведенных битов
*/
#define bit_1_cnt(x)      ___bit_1_cnt((umax_t)(x))

/*
 * Вернуть позицию одного единичного бита, если битов несколько, то -1
*/
#define bit_1_pos(x)      ___bit_1_pos((umax_t)(x))

/* = ВЫСТАВЛЕНИЕ И ВОЗВРАТ БИТОВ ================================================================================================================== */

/*
 * Чтение бита на позии
*/
#define bit_get(x, n)     (typeof(x)) ((n) == 0 ? (0) : ((x) &  (1ULL << ((n) - 1))))

/*
 * Выставление бита  на позии
*/
#define bit_set(x, n)     (typeof(x)) ((n) == 0 ? (x) : ((x) |  (1ULL << ((n) - 1))))

/*
 * Сброс бита на позии
*/
#define bit_res(x, n)     (typeof(x)) ((n) == 0 ? (x) : ((x) & ~(1ULL << ((n) - 1))))

/*
 * Переключение бита на позиции
*/
#define bit_tog(x, n)     (typeof(x)) ((n) == 0 ? (x) : ((x) ^  (1ULL << ((n) - 1))))

/*
 * Выставление определенного бита на позии
*/
#define bit_wrt(x, n, v)  (typeof(x)) ((v) ? bit_set((x), (n)) : bit_res((x), (n)))

/*
 * Инверсия битов в числе
*/
#define bit_inv(x)        (typeof(x)) (~((umax_t)(x)))

/*
 * Смена порядка битов то начала к концу
*/
#define bit_rev(x)        (typeof(x)) ___bit_revers((x), sizeof(x))

/*
 * Возвращает значение по смещению и длинне последовательности
*/
#define bit_seq(p, o, l)  ___bit_sequence(p, o, l)

/* = БИТОВЫЕ СДВИГИ =============================================================================================================================== */

/*
 * Логический сдвиг вправо (c занулением ??)
*/
#define bit_shf_rig(x, n) ((x) >> (n))

/*
 * Логический сдвиг влево (с занулением ??)
*/
#define bit_shf_lef(x, n) ((x) << (n))

/*
 * Логический сдвиг относительно знака числа
         * +n - влево
         * -n - вправо
*/
#define bit_shf_vec(x, n) (((n) < (0)) ? bit_shf_rig((x), -(n)) : bit_shf_lef((x), (n)))

/*
 * Циклический сдвиг вправо
*/
#define bit_cyc_rig(x, n) ( (n) == 0 ? (x) : ((x) >> ((n) % ((sizeof(x) * CHAR_BIT)))) | ((x) << (((sizeof(x) * CHAR_BIT) - (n)) % ((sizeof(x) * CHAR_BIT)))))

/*
 * Циклический сдвиг влево
*/
#define bit_cyc_lef(x, n) ( (n) == 0 ? (x) : ((x) << ((n) % ((sizeof(x) * CHAR_BIT)))) | ((x) >> (((sizeof(x) * CHAR_BIT) - (n)) % ((sizeof(x) * CHAR_BIT)))))

/*
 * Циклический сдвиг относительно знака числа
 * +n - влево
 * -n - вправо
*/
#define bit_cyc_vec(x, n) (((n) < (0)) ? bit_cyc_rig((x), -(n)) : bit_cyc_lef((x), (n)))

/*
 * Арифметический сдвиг вправо
*/
#define bit_ari_rig(x, n)

/*
 * Арифметический сдвиг влево
*/
#define bit_ari_lef(x, n)

/*
 * Арифметический сдвиг относительно знака числа
 * +n - влево
 * -n - вправо
*/
#define bit_ari_vec(x, n)

/* = БИТОВЫЕ МАСКИ ================================================================================================================================ */


/*
 * Выставление битов по единичной маске
*/
#define bit_mask_up(x, y) COMPILE_WCHDOG(x, y, _x, _y, ((x) | (y)))

/*
 * Обнуление битов по единичной маске
*/
#define bit_mask_dw(x, y) COMPILE_WCHDOG(x, y, _x, _y, ((x) & (y)))

/* = БИТОВЫЕ ОПЕРРАЦИИ ============================================================================================================================ */

/*
 * Битовое НЕ
*/
#define bit_not(x)        (~(x))

/*
 * Битовое ИЛИ
*/
#define bit_or(x, y)      COMPILE_WCHDOG(x, y, _x, _y, ((x) | (y)))

/*
 * Битовое И
*/
#define bit_and(x, y)     COMPILE_WCHDOG(x, y, _x, _y, ((x) & (y)))

/*
 * Битовое ИСЛЮЧАЮЩЕЕ ИЛИ
 * (Операторы не равны)
*/
#define bit_xor(x, y)     COMPILE_WCHDOG(x, y, _x, _y, ((x) ^ (y)))

/*
 * Битовое ИЛИ-НЕ
*/
#define bit_nor(x, y)     bit_not(bit_or ((x), (y)))

/*
 * Битовое И-НЕ
*/
#define bit_nand(x, y)    bit_not(bit_and((x), (y)))

/*
 * Битовое ИСКЛЮЧАЮЩЕЕ ИЛИ-НЕ
 * Битовое ЭКВИВАЛЕНТНОСТЬ
 * (Операторы равны)
*/
#define bit_xnor(x, y)    bit_not(bit_xor((x), (y)))
#define bit_eqv(x, y)     bit_or(bit_and(bit_not(x), (y)), bit_and((x), bit_not(y)))

/* ================================================================================================================================================ */

END_C_DECLARATION
#endif /*YAYA_BIT_H*/
