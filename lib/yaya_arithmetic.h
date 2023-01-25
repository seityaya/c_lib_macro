//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_ARITHMETIC_H
#define YAYA_ARITHMETIC_H

#include "yaya_chek.h"
#include <math.h>

/*адрес и значение*/
#define SetAdr(x)       (*x)
#define GetAdr(x)       (&(x))
#define GetVal(x)       (*(x))

/*conditional*/
/*условие*/
#define ternary(_cond, _true, _false) ((_cond) ? (_true) : (_false))

/*присваивание*/
/*assignment*/
#define AS(x, y)    COMPILE_WCHDOG(x, y, ((x) = (y)))

/*обмен значений*/
/*value exchange*/
#define SWAP(x, y)  COMPILE_WCHDOG(x, y, { typeof(x) tmp = x; x = y; y = tmp; } )

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
#define AP(x, y, e) COMPILE_WCHDOG(x, y, (ABS((x) - (y)) <= e))

/*взятие целого*/
#define GET_INT(x)  ((typeof(x))((imax)(x)))
/*взятие дробного*/
#define GET_REM(x)  ((typeof(x))((x) - GET_INT(x)))

/*знак числа*/
#define SIG(x)      ({ typeof(x) _x = x; ((_x) > 0) ? (+1) : (((_x) < 0) ? (-1) : (0)); })
/*абсолютное значение*/
#define ABS(x)      ({ typeof(x) _x = x; ((_x) > 0) ? (_x) : (((_x) < 0) ? (-(_x)) : (0)); })

/*положительное число*/
#define POSITIV(x)   ({ typeof(x) _x = x; ((_x) > 0) ? (_x) : (-(_x)); })
/*отрицательное число*/
#define NEGITIV(x)   ({ typeof(x) _x = x; ((_x) < 0) ? (_x) : (-(_x)); })

/*проверка, что число положительное, но не ноль */
#define IS_POS(x)          ((x) > 0)
/*проверка, что число отрицательное, но не ноль*/
#define IS_NEG(x)          ((x) < 0)
/*проверка, что число ноль*/
#define IS_ZERO(x)         ((x) == 0)
/*проверка, что число положительное или ноль*/
#define IS_POS_AND_ZERO(x) ((x) >= 0)
/*проверка, что число отрицательное или ноль*/
#define IS_NEG_AND_ZERO(x) ((x) <= 0)

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
#define MOD(x, y)   COMPILE_WCHDOG(x, y, (typeof(x))((_x) - GET_INT((_x) / (_y)) * (_y)))
/*полное деление*/
/*quotient*/
#define QUT(x, y)   COMPILE_WCHDOG(x, y, ((double_t)((double_t)(_x) / (double_t)(_y))))
/*возведение в степень*/
#define POW(x, p)    (pow((x), (p)))
/*извлечение корня*/
#define ROT(x, r)    (pow((x), (double_t)(1.0)/(r)))
/*логарифм числа по основанию*/
#define LOG(x, l)    (log(x) / log(l))

/*обратные величины*/
/*
 * Z ÷ a = b -> div(Z, a) ~> mod(b, Z) || mul(a, b)
 * Z / a = b -> qut(Z, a) ~> qut(b, Z) || mul(a, b)
 * X ^ Y = Z -> pow(X, Y) ~> log(Z, X) || rot(Z, Y)
 * Y √ Z = X -> rot(Z, Y) ~> pow(X, Y) || log(Z, X)
 * Z _ X = Y -> log(Z, X) ~> rot(Y, Z) || pow(X, Y)
*/

/*округление к ближайшему целому*/
#define ROUND_INT(x)   rint(x)
/*округление в большую сторону*/
#define ROUND_UP(x)    ceil(x)
/*округление в меньшую сторону*/
#define ROUND_DN(x)    floor(x)
/*округление к нулю*/
#define ROUND_ZERO(x)  GET_INT(x)
/*округление к бесконечности*/
#define ROUND_INF(x)   ({ typeof(x) _x = x; ((_x) > 0) ? ROUND_UP(x) : ROUND_DN(x); })

/*округление к ближайшему c шагом*/
#define ROUND_INT_EPS(x, e)  (MUL(ROUND_INT(QUT((x), (e))), (e)))
/*округление в большую сторону c шагом*/
#define ROUND_UP_EPS(x, e)   (MUL(ROUND_UP(QUT((x), (e))), (e)))
/*округление в меньшую сторону c шагом*/
#define ROUND_DN_EPS(x, e)   (MUL(ROUND_DN(QUT((x), (e))), (e)))
/*округление к нулю c шагом*/
#define ROUND_ZERO_EPS(x, e) (MUL(ROUND_ZERO(QUT((x), (e))), (e)))
/*округление к бесконечности c шагом*/
#define ROUND_INF_EPS(x, e)  (MUL(ROUND_INF(QUT((x), (e))), (e)))

/*минимальное из чисел*/
#define MIN(x, y)                        COMPILE_WCHDOG(x, y, (((_x) < (_y)) ? (_x) : (_y)))
/*максимальное из чисел*/
#define MAX(x, y)                        COMPILE_WCHDOG(x, y, (((_x) > (_y)) ? (_x) : (_y)))
/*минимальное из чисел, но не ноль*/
#define MIN_NOT_ZERO(x, y)               COMPILE_WCHDOG(x, y, (((_x) == 0) ? (_y) : (((_y) == 0) ? (_x) : (((_x) < (_y)) ? (_x) : (_y)))))
/*максимальное из чисел, но не ноль*/
#define MAX_NOT_ZERO(x, y)               COMPILE_WCHDOG(x, y, (((_x) == 0) ? (_y) : (((_y) == 0) ? (_x) : (((_x) > (_y)) ? (_x) : (_y)))))

/* определяет число как минимальное или максимальное и помещает его в соответствующий аргумент*/
#define MINMAX_SET(min, max, x)          { min = MIN(min, x);          max = MAX(max, x);          }
#define MINMAX_NOT_ZERO_SET(min, max, x) { min = MIN_NOT_ZERO(min, x); max = MAX_NOT_ZERO(max, x); }

#endif /*YAYA_ARITHMETIC_H*/
