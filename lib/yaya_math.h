//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_MATH_H
#define YAYA_MATH_H

#include "yaya_chek.h"
#include "tgmath.h"

/*адрес и значение*/
#define GtA(x)       (&(x))
#define GtV(x)       (*(x))

/*присваисвние*/
/*assignment*/
#define AS(x, y)    a = b

/*сравнение*/
/*на равенство*/
/*equality*/
#define EQ(x, y)    COMPILE_WCHDOG(x, y, ((x) == (y)))
/*на неравенство*/
/*inequality*/
#define NQ(x, y)    COMPILE_WCHDOG(x, y, ((x) != (y)))
/*больше*/
/*greater then*/
#define GT(x, y)    COMPILE_WCHDOG(x, y, ((x) > (y)))
/*меньше*/
/*less then*/
#define LT(x, y)    COMPILE_WCHDOG(x, y, ((x) < (y)))
/*больше или равно*/
/*equality or greater then*/
#define GE(x, y)    COMPILE_WCHDOG(x, y, ((x) >= (y)))
/*меньше или равно*/
/*equality or less then*/
#define LE(x, y)    COMPILE_WCHDOG(x, y, ((x) <= (y)))
/*примерное равно*/
/*approximation*/
#define AP(x, y, e) COMPILE_WCHDOG(x, y, (ABS((x) - (y)) > e))

/*математические операции*/
/*сумма*/
/*summa*/
#define SUM(x, y)   COMPILE_WCHDOG(x, y, ((_x) + (_y)))
/*разность*/
/*difference*/
#define DIF(x, y)   COMPILE_WCHDOG(x, y, ((_x) - (_y)))
/*умножение*/
/*multiplication*/
#define MUL(x, y)   COMPILE_WCHDOG(x, y, ((_x) * (_y)))
/*целое от деления*/
/*division*/
#define DIV(x, y)   COMPILE_WCHDOG(x, y, (signed)((_x) / (_y)))
/*остаток от деления*/
/*remainder*/
#define MOD(x, y)   COMPILE_WCHDOG(x, y, ((_x) % (_y)))
/*полное деление*/
/*quotient*/
#define QUT(x, y)   COMPILE_WCHDOG(x, y, ((((double_t)(_x) / (double_t)(_y)))


/*взятие целого*/
#define GET_INT(x)
/*взятие дробного*/
#define GET_REM(x)


/*возведение в степень*/
#define POW(x, p)    (pow((x), (p)))
/*извлечение корня*/
#define ROT(x, r)    (pow((x), (double_t)(1.0)/(r)))
/*логарифм числа по основанию*/
#define LOG(x, l)    (log(x) / log(l))

/*проверка, что число делится на делитель нацело*/
#define IS_DIV(x, k)
/*проверка, что число есть степень числа*/
#define IS_POW(x, k)

/*знак числа*/
#define SIG(x)             ({ typeof(x) _x = x; ((_x) > 0) ? (+1) : (((_x) < 0) ? (-1) : (0)); })
/*абсолютное значение*/
#define ABS(x)             ({ typeof(x) _x = x; ((_x) > 0) ? (_x) : (((_x) < 0) ? (-(_x)) : (0)); })

/*положительное число*/
#define POSITIV(x)         ({ typeof(x) _x = x; ((_x) > 0) ? (_x) : (-(_x)); })
/*отрицательное число*/
#define NEGITIV(x)         ({ typeof(x) _x = x; ((_x) < 0) ? (_x) : (-(_x)); })


/*проверка, что число положительное, но не ноль */
#define IS_POS(x)          ({ ((x) > 0) })
/*проверка, что число отрицательное, но не ноль*/
#define IS_NEG(x)          ({ ((x) < 0) })
/*проверка, что число ноль*/
#define IS_ZERO(x)         ({ ((x) == 0) })
/*проверка, что число положительное или ноль*/
#define IS_POS_AND_ZERO(x) ({ ((x) >= 0) })
/*проверка, что число отрицательное или ноль*/
#define IS_NEG_AND_ZERO(x) ({ ((x) <= 0) })

/*округление к ближайшему целому*/
#define ROUND(x)
/*округление в большую сторону*/
#define ROUND_UP(x)
/*округление в меньшую сторону*/
#define ROUND_DN(x)

/*округление к ближайшему c шагом*/
#define ROUND_EPS(x, e)
/*округление в большую сторону c шагом*/
#define ROUND_UP_EPS(x, e)
/*округление в меньшую сторону c шагом*/
#define ROUND_DN_EPS(x, e)

/*минимальное из чисел*/
#define MIN(x, y)                        COMPILE_WCHDOG(x, y, (((_x) < (_y)) ? (_x) : (_y)))
/*максимальное из чисел*/
#define MAX(x, y)                        COMPILE_WCHDOG(x, y, (((_x) > (_y)) ? (_x) : (_y)))
/*минимальное из чисел, но не ноль*/
#define MIN_NOT_ZERO(x, y)               COMPILE_WCHDOG(x, y, (((_x) == 0) ? (_y) : (((_y) == 0) ? (_x) : (((_x) < (_y)) ? (_x) : (_y)))))
/*максимальное из чисел, но не ноль*/
#define MAX_NOT_ZERO(x, y)               COMPILE_WCHDOG(x, y, (((_x) == 0) ? (_y) : (((_y) == 0) ? (_x) : (((_x) > (_y)) ? (_x) : (_y)))))

/*обмен значений*/
#define SWAP(a,b) { typeof(x) tmp = a; a = b; b = tmp; }

/*тригонометрические*/

#endif /*YAYA_MATH_H*/
