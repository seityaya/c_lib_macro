//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_BIT_H
#define YAYA_BIT_H

#include "limits.h"

#include "yaya_number.h"
#include "yaya_chek.h"

i_s8_t yaya_bit_0_beg(u_max_t x, u_s8_t s);
i_s8_t yaya_bit_0_end(u_max_t x, u_s8_t s);
i_s8_t yaya_bit_0_cnt(u_max_t x, u_s8_t s);
i_s8_t yaya_bit_0_pos(u_max_t x, u_s8_t s);

i_s8_t yaya_bit_1_beg(u_max_t x);
i_s8_t yaya_bit_1_end(u_max_t x);
i_s8_t yaya_bit_1_cnt(u_max_t x);
i_s8_t yaya_bit_1_pos(u_max_t x);

u_max_t yaya_bit_revers(u_max_t x, u_s8_t s);

/*
 * В данных операциях биты нумеруются с 1, если указан 0, то изменений не происходит
 * Если функция возвращает результат, то он тоже нумерует биты c 1
*/

#define BIT_0_ALL(x)      (typeof(x))(u_max_c(0))
#define BIT_0_BEG(x)      yaya_bit_0_beg((u_max_t)(x), sizeof(x)) //вернуть позицию первого взведенного бита
#define BIT_0_END(x)      yaya_bit_0_end((u_max_t)(x), sizeof(x)) //вернуть позицию последнего взведенного бита
#define BIT_0_CNT(x)      yaya_bit_0_cnt((u_max_t)(x), sizeof(x)) //подсчитать количество взведенных битов
#define BIT_0_POS(x)      yaya_bit_0_pos((u_max_t)(x), sizeof(x)) //вернуть позицию одного единичного бита, если битов несколько, то -1

#define BIT_1_ALL(x)      (sizeof(x) == (sizeof(u_max_t)) ? (u_max_c(0) - u_max_c(1)) : (BIT_SHF_LEF(u_max_c(1), CHAR_BIT * sizeof(x)) - u_max_c(1)))
#define BIT_1_BEG(x)      yaya_bit_1_beg((u_max_t)(x))            //вернуть позицию первого взведенного бита
#define BIT_1_END(x)      yaya_bit_1_end((u_max_t)(x))            //вернуть позицию последнего взведенного бита
#define BIT_1_CNT(x)      yaya_bit_1_cnt((u_max_t)(x))            //подсчитать количество взведенных битов
#define BIT_1_POS(x)      yaya_bit_1_pos((u_max_t)(x))            //вернуть позицию одного единичного бита, если битов несколько, то -1

#define BIT_GET(x, n)     (typeof(x)) ((n) == 0 ? (0) : ((x) &  (1ULL << ((n) - 1))))    //чтение бита на позии
#define BIT_SET(x, n)     (typeof(x)) ((n) == 0 ? (x) : ((x) |  (1ULL << ((n) - 1))))    //выставление бита  на позии
#define BIT_RES(x, n)     (typeof(x)) ((n) == 0 ? (x) : ((x) & ~(1ULL << ((n) - 1))))    //сброс бита на позии
#define BIT_TOG(x, n)     (typeof(x)) ((n) == 0 ? (x) : ((x) ^  (1ULL << ((n) - 1))))    //переключение бита на позиции
#define BIT_WRT(x, n, v)  (typeof(x)) ((v) ? BIT_SET((x), (n)) : BIT_RES((x), (n)))      //выставление определенного бита на позии
#define BIT_INV(x)        (typeof(x)) (~((u_max_t)(x)))                                     //инверсия битов в числе
#define BIT_REV(x)        (typeof(x)) yaya_bit_revers((x), sizeof(x))                    //смена порядка битов то начала к концу

#define BIT_SHF_RIG(x, n) ( (x) >> (n))                                                  //сдвиг вправо c занулением ??
#define BIT_SHF_LEF(x, n) ( (x) << (n))                                                  //сдвиг влево с занулением  ??
#define BIT_SHF_VEC(x, n) (((n) < (0)) ? BIT_SHF_RIG((x), -(n)) : BIT_SHF_LEF((x), (n))) //сдвиг относительно знака числа, + влево, - вправо

#define BIT_CYC_RIG(x, n) ( (n) == 0 ? (x) : ((x) >> ((n) % ((sizeof(x) * CHAR_BIT)))) | ((x) << (((sizeof(x) * CHAR_BIT) - (n)) % ((sizeof(x) * CHAR_BIT)))))     //циклический сдвиг вправо
#define BIT_CYC_LEF(x, n) ( (n) == 0 ? (x) : ((x) << ((n) % ((sizeof(x) * CHAR_BIT)))) | ((x) >> (((sizeof(x) * CHAR_BIT) - (n)) % ((sizeof(x) * CHAR_BIT)))))     //циклический сдвиг влево
#define BIT_CYC_VEC(x, n) (((n) < (0)) ? BIT_CYC_RIG((x), -(n)) : BIT_CYC_LEF((x), (n)))                 //сдвиг относительно знака числа, + влево, - вправо

#define BIT_MASK_UP(x, y) COMPILE_WCHDOG(x, y, ((x) | (y)))                                         //выставление битов по единичной маске
#define BIT_MASK_DW(x, y) COMPILE_WCHDOG(x, y, ((x) & (y)))                                         //обнуление битов по единичной маске

#define BIT_OR(x, y)      COMPILE_WCHDOG(x, y, ((x) | (y)))
#define BIT_AND(x, y)     COMPILE_WCHDOG(x, y, ((x) & (y)))
#define BIT_XOR(x, y)     COMPILE_WCHDOG(x, y, ((x) ^ (y)))
#define BIT_NOT(x)        (~(x))
#define BIT_NOR(x, y)     BIT_NOT(BIT_OR ((x), (y)))
#define BIT_NAND(x, y)    BIT_NOT(BIT_AND((x), (y)))
#define BIT_EQV(x, y)     BIT_OR(BIT_AND(BIT_NOT(x), (y)), BIT_AND((x), BIT_NOT(y)))

#endif /*YAYA_BIT_H*/
