//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_BIT_H
#define YAYA_BIT_H

#include "yaya_number.h"
#include "yaya_chek.h"

i08s yaya_bit_0_beg(umax x, u08s s);
i08s yaya_bit_0_end(umax x, u08s s);
i08s yaya_bit_0_cnt(umax x, u08s s);
i08s yaya_bit_0_pos(umax x, u08s s);

i08s yaya_bit_1_beg(umax x);
i08s yaya_bit_1_end(umax x);
i08s yaya_bit_1_cnt(umax x);
i08s yaya_bit_1_pos(umax x);

umax yaya_bit_revers(umax x, u08s s);

/*
 * В данных операциях биты нумеруются с 1, если указан 0, то изменений не происходит
 * Если функция возвращает результат, то он тоже нумерует биты c 1
*/

#define BIT_0_ALL(x)      (typeof(x))(umaxc(0))
#define BIT_0_BEG(x)      yaya_bit_0_beg((umax)(x), sizeof(x)) //вернуть позицию первого взведенного бита
#define BIT_0_END(x)      yaya_bit_0_end((umax)(x), sizeof(x)) //вернуть позицию последнего взведенного бита
#define BIT_0_CNT(x)      yaya_bit_0_cnt((umax)(x), sizeof(x)) //подсчитать количество взведенных битов
#define BIT_0_POS(x)      yaya_bit_0_pos((umax)(x), sizeof(x)) //вернуть позицию одного единичного бита, если битов несколько, то -1

#define BIT_1_ALL(x)      (sizeof(x) == (sizeof(umax)) ? (umaxc(0) - umaxc(1)) : (BIT_SHF_LEF(umaxc(1), CHAR_BIT * sizeof(x)) - umaxc(1)))
#define BIT_1_BEG(x)      yaya_bit_1_beg((umax)(x))            //вернуть позицию первого взведенного бита
#define BIT_1_END(x)      yaya_bit_1_end((umax)(x))            //вернуть позицию последнего взведенного бита
#define BIT_1_CNT(x)      yaya_bit_1_cnt((umax)(x))            //подсчитать количество взведенных битов
#define BIT_1_POS(x)      yaya_bit_1_pos((umax)(x))            //вернуть позицию одного единичного бита, если битов несколько, то -1

#define BIT_GET(x, n)     (typeof(x)) ((n) == 0 ? (0) : ((x) &  (1ULL << ((n) - 1))))    //чтение бита на позии
#define BIT_SET(x, n)     (typeof(x)) ((n) == 0 ? (x) : ((x) |  (1ULL << ((n) - 1))))    //выставление бита  на позии
#define BIT_RES(x, n)     (typeof(x)) ((n) == 0 ? (x) : ((x) & ~(1ULL << ((n) - 1))))    //сброс бита на позии
#define BIT_TOG(x, n)     (typeof(x)) ((n) == 0 ? (x) : ((x) ^  (1ULL << ((n) - 1))))    //переключение бита на позиции
#define BIT_WRT(x, n, v)  (typeof(x)) ((v) ? BIT_SET((x), (n)) : BIT_RES((x), (n)))      //выставление определенного бита на позии
#define BIT_INV(x)        (typeof(x)) (~((umax)(x)))                                     //инверсия битов в числе
#define BIT_REV(x)        (typeof(x)) yaya_bit_revers((x), sizeof(x))                    //смена порядка битов то начала к концу

#define BIT_SHF_RIG(x, n) ( (x) >> (n))                                                  //сдвиг вправо c занулением ??
#define BIT_SHF_LEF(x, n) ( (x) << (n))                                                  //сдвиг влево с занулением  ??
#define BIT_SHF_VEC(x, n) (((n) < (0)) ? BIT_SHF_RIG((x), -(n)) : BIT_SHF_LEF((x), (n))) //сдвиг относительно знака числа, + влево, - вправо

#define BIT_CYC_RIG(x, n) ( (n) == 0 ? (x) : ((x) >> (n)) | ((x) << ((sizeof(x) * CHAR_BIT) - (n))))     //циклический сдвиг вправо
#define BIT_CYC_LEF(x, n) ( (n) == 0 ? (x) : ((x) << (n)) | ((x) >> ((sizeof(x) * CHAR_BIT) - (n))))     //циклический сдвиг влево
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
