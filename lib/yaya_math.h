//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2022 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_MATH_H
#define YAYA_MATH_H

/*присваисвние*/
#define AS(a, b) a = b              /*assignment*/

/*сравнение*/
/*на равенство*/
#define EQ(a, b) ((a) == (b))       /*equality*/
/*на неравенство*/
#define NQ(a, b) ((a) != (b))       /*inequality*/
/*больше*/
#define GT(a, b) ((a) > (b))        /*greater then*/
/*меньше*/
#define LT(a, b) ((a) < (b))        /*less then*/
/*больше или равно*/
#define GE(a, b) ((a) >= (b))       /*equality or greater then*/
/*меньше или равно*/
#define LE(a, b) ((a) <= (b))       /*equality or less then*/
/*примерное равно*/
#define AP(a, b, e) (ABS((a) - (b)) > e) /*approximation*/

/*математические операции*/
/*сумма*/
#define SUM(a, b) ((a) + (b))       /*summa*/
/*разность*/
#define DIF(a, b) ((a) - (b))       /*difference*/
/*умножение*/
#define MUL(a, b) ((a) * (b))       /*multiplication*/
/*целое от деления*/
#define DIV(a, b) ((a) / (b))       /*division*/
/*остаток от деления*/
#define MOD(a, b) ((a) / (b))       /*remainder*/
/*полное деление*/
#define QUT(a, b) ((a) / (b))       /*quotient*/

/*взятие целого*/
#define GET_INT(x)
/*взятие дробного*/
#define GET_REM(x)

/*возведение в степень*/
#define POW(a, b)
/*извлечение корня*/
#define ROT(a, b)
/*логарифм числа по основанию*/
#define LOG(a, b)

/*проверка, что число делится на делитель нацело*/
#define IS_DIV(a, b)
/*проверка, что число есть степень числа*/
#define IS_POW(a, b)

/*абсолютное значение*/
#define ABS(a)
/*положительное число*/
#define POSITIV(a) (a) > 0 ? (a) : (-(a))
/*отрицательное число*/
#define NEGITIV(a) (a) < 0 ? (a) : (-(a))

/*проверка, что число положительное, но не ноль */
#define IS_POS(a)
/*проверка, что число отрицательное, но не ноль*/
#define IS_NEG(a)
/*проверка, число ноль*/
#define IS_ZERO(a)
/*проверка, что число положительное или ноль*/
#define IS_POS_AND_ZERO(a)
/*проверка, что число отрицательное или ноль*/
#define IS_NEG_AND_ZERO(a)

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
#define MIN(x,y)  CMP_ONSE(x, y, <)
/*максимальное из чисел*/
#define MAX(a,b)  CMP_ONSE(x, y, >)
/*минимальное из чисел, но не ноль*/
#define MIN_NOT_ZERO(x,y)
/*максимальное из чисел, но не ноль*/
#define MAX_NOT_ZERO(x,y)

/*обмен значений*/
#define SWAP(a,b) { typeof(a) tmp = a; a = b; b = tmp; }

#endif /*YAYA_MATH_H*/
