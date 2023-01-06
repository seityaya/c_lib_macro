//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2022 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_BIT_H
#define YAYA_BIT_H

#include "yaya_number.h"

i08s yaya_bit_position(umax x);
i08s yaya_bit_onse_bit(umax x);
umax yaya_bit_revers(umax x, umax n);

/*В данных операциях биты нумеруются с 1, если указан 0, то изменений не происходит
 *Если функция возвращает результат, то он тоже нумерует биты от 1
*/

#define BIT_BEG(x)  yaya_bit_position(x)   //вернуть позицию первого взведенного бита
#define BIT_END(x)  yaya_bit_position(x)   //вернуть позицию последнего взведенного бита
#define BIT_NUM(x)  yaya_bit_onse_bit(x)   //подсчитать количество взведенных битов
#define BIT_POS(x)  yaya_bit_position(x)   //вернуть позицию одного единичного бита, если битов несколько, то -1

#define BIT_GET(x, n)    ((n) == 0 ? (0) : ((x) &  (1ULL << ((n) - 1))))      //чтение бита на позии
#define BIT_SET(x, n)    ((n) == 0 ? (x) : ((x) |  (1ULL << ((n) - 1))))      //выставление бита  на позии
#define BIT_RES(x, n)    ((n) == 0 ? (x) : ((x) & ~(1ULL << ((n) - 1))))      //сброс бита на позии
#define BIT_TOG(x, n)    ((n) == 0 ? (x) : ((x) ^  (1ULL << ((n) - 1))))      //переключение бита на позиции
#define BIT_WRT(x, n, v) ((v) ? BIT_SET((x), (n)) : BIT_RES((x), (n)))        //выставление определенного бита на позии
#define BIT_REV(x)       yaya_bit_revers((x), sizeof(x))                      //смена порядка битов то начала к концу

#define BIT_SHF_RIG(x, n) ( (x) >> (n))                                                  //сбвиг вправо c занулением ??
#define BIT_SHF_LFT(x, n) ( (x) << (n))                                                  //сдвиг влево с занулением  ??
#define BIT_SHF_VEC(x, n) (((n) < (0)) ? BIT_SHF_RIG((x), -(n)) : BIT_SHF_LFT((x), (n))) //сдвиг относительно знака числа, + влево, - вправо

#define BIT_CYC_RIG(x, n) ( (n) == 0 ? (x) : ((x) >> (n)) | ((x) << ((sizeof(x)*8) - (n))))     //циклический сдвиг вправо
#define BIT_CYC_LEF(x, n) ( (n) == 0 ? (x) : ((x) << (n)) | ((x) >> ((sizeof(x)*8) - (n))))     //циклический сдвиг влево
#define BIT_CYC_VEC(x, n) (((n) < (0)) ? BIT_CYC_RIG((x), -(n)) : BIT_CYC_LEF((x), (n)))        //сдвиг относительно знака числа, + влево, - вправо

#define BIT_MASK_IN(x)    (~(x))                                              //инвертирование всех битов
#define BIT_MASK_UP(x, y) ((x) | (y))                                         //выставление битов по еденичной маске
#define BIT_MASK_DW(x, y) ((x) & (y))                                         //обнуление битов по еденичной маске

#endif /*YAYA_BIT_H*/
