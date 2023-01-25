//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_ARITHMETIC_H
#define YAYA_ARITHMETIC_H

#include "yaya_chek.h"
#include "yaya_number.h"

#include <math.h>

/*адрес и значение*/
#define init_ptr(n, t)     typeof(t) *n = NULL
#define init_val(n, t)     typeof(t) n = {0}

#define crete_ptr(n, v)    typeof(v) *(n) = &v
#define crete_val(n, v)    typeof(v)  (n) = v

#define set_adr(n, v)      (*(n)) = (&(v))
#define set_val(n, v)      (n)  = (v)

#define get_adr(x)         (&(x))
#define get_val(x)         (*(x))

/*conditional*/
/*условие*/
#define ternary(_cond, _true, _false) ((_cond) ? (_true) : (_false))

/*присваивание*/
/*assignment*/
#define as(x, y)    COMPILE_WCHDOG(x, y, ((x) = (y)))

/*обмен значений*/
/*value exchange*/
#define swap(x, y)  COMPILE_WCHDOG(x, y, { typeof(x) tmp = (x); (x) = (y); (y) = tmp; } )

/*сравнение*/
/*на равенство*/
/*equality*/
#define eq(x, y)    COMPILE_WCHDOG(x, y, ((x) == (y)))
/*на неравенство*/
/*inequality*/
#define nq(x, y)    COMPILE_WCHDOG(x, y, ((x) != (y)))
/*больше*/
/*greater then*/
#define gt(x, y)    COMPILE_WCHDOG(x, y, ((x) > (y)))
/*меньше*/
/*less then*/
#define lt(x, y)    COMPILE_WCHDOG(x, y, ((x) < (y)))
/*больше или равно*/
/*equality or greater then*/
#define ge(x, y)    COMPILE_WCHDOG(x, y, ((x) >= (y)))
/*меньше или равно*/
/*equality or less then*/
#define le(x, y)    COMPILE_WCHDOG(x, y, ((x) <= (y)))
/*примерное равно*/
/*approximation*/
#define ap(x, y, e) COMPILE_WCHDOG(x, y, (abs((x) - (y)) <= e))

/*взятие целого*/
#define get_int(x)  ((typeof(x))((i_max_t)(x)))
/*взятие дробного*/
#define get_rem(x)  ((typeof(x))((x) - get_int(x)))

/*знак числа*/
#define sig(x)      ({ typeof(x) _x = x; ((_x) > 0) ? (+1) : (((_x) < 0) ? (-1) : (0)); })
/*абсолютное значение*/
#define abs(x)      ({ typeof(x) _x = x; ((_x) > 0) ? (_x) : (((_x) < 0) ? (-(_x)) : (0)); })

/*положительное число*/
#define pos(x)   ({ typeof(x) _x = x; ((_x) > 0) ? (_x) : (-(_x)); })
/*отрицательное число*/
#define neg(x)   ({ typeof(x) _x = x; ((_x) < 0) ? (_x) : (-(_x)); })

/*проверка, что число положительное, но не ноль */
#define is_pos(x)          ((x) > 0)
/*проверка, что число отрицательное, но не ноль*/
#define is_neg(x)          ((x) < 0)
/*проверка, что число ноль*/
#define is_zero(x)         ((x) == 0)
/*проверка, что число положительное или ноль*/
#define is_pos_or_zero(x) ((x) >= 0)
/*проверка, что число отрицательное или ноль*/
#define is_neg_or_zero(x) ((x) <= 0)

/*математические операции*/
/*сумма*/
/*summa*/
#define sum(x, y)   COMPILE_WCHDOG(x, y, ((_x) + (_y)))
/*разность*/
/*difference*/
#define dif(x, y)   COMPILE_WCHDOG(x, y, ((_x) - (_y)))
/*умножение*/
/*multiplication*/
#define mul(x, y)   COMPILE_WCHDOG(x, y, ((_x) * (_y)))
/*целое от деления*/
/*division*/
#define div(x, y)   COMPILE_WCHDOG(x, y, (signed)((_x) / (_y)))
/*остаток от деления*/
/*remainder*/
#define mod(x, y)   COMPILE_WCHDOG(x, y, (typeof(x))((_x) - get_int((_x) / (_y)) * (_y)))
/*полное деление*/
/*quotient*/
#define qut(x, y)   COMPILE_WCHDOG(x, y, ((double_t)((double_t)(_x) / (double_t)(_y))))
/*возведение в степень*/
#define pow(x, p)    (pow((x), (p)))
/*извлечение корня*/
#define rot(x, r)    (pow((x), fl_max_c(1.0)/(r)))
/*логарифм числа по основанию*/
#define log(x, l)    (log(x) / log(l))

/*обратные величины*/
/*
 * Z ÷ a = b -> div(Z, a) ~> div(b, Z) || mul(a, b)
 * Z / a = b -> qut(Z, a) ~> qut(b, Z) || mul(a, b)
 * X ^ Y = Z -> pow(X, Y) ~> log(Z, X) || rot(Z, Y)
 * Y √ Z = X -> rot(Z, Y) ~> pow(X, Y) || log(Z, X)
 * Z _ X = Y -> log(Z, X) ~> rot(Y, Z) || pow(X, Y)
*/

/*округление к ближайшему целому*/
#define round_int(x)   rint(x)
/*округление в большую сторону*/
#define round_up(x)    ceil(x)
/*округление в меньшую сторону*/
#define round_dn(x)    floor(x)
/*округление к нулю*/
#define round_zero(x)  trunc(x)
/*округление к бесконечности*/
#define round_inf(x)   ({ typeof(x) _x = x; ((_x) > 0) ? round_up(x) : round_dn(x); })

/*округление к ближайшему c шагом*/
#define round_int_eps(x, e)  (mul(round_int(qut((x), (e))), (e)))
/*округление в большую сторону c шагом*/
#define round_up_eps(x, e)   (mul(round_up(qut((x), (e))), (e)))
/*округление в меньшую сторону c шагом*/
#define round_dn_eps(x, e)   (mul(round_dn(qut((x), (e))), (e)))
/*округление к нулю c шагом*/
#define round_zero_eps(x, e) (mul(round_zero(qut((x), (e))), (e)))
/*округление к бесконечности c шагом*/
#define round_inf_eps(x, e)  (mul(round_inf(qut((x), (e))), (e)))

/*минимальное из чисел*/
#define min(x, y)                        COMPILE_WCHDOG(x, y, (((_x) < (_y)) ? (_x) : (_y)))
/*максимальное из чисел*/
#define max(x, y)                        COMPILE_WCHDOG(x, y, (((_x) > (_y)) ? (_x) : (_y)))
/*минимальное из чисел, но не ноль*/
#define min_not_zero(x, y)               COMPILE_WCHDOG(x, y, (((_x) == 0) ? (_y) : (((_y) == 0) ? (_x) : (((_x) < (_y)) ? (_x) : (_y)))))
/*максимальное из чисел, но не ноль*/
#define max_not_zero(x, y)               COMPILE_WCHDOG(x, y, (((_x) == 0) ? (_y) : (((_y) == 0) ? (_x) : (((_x) > (_y)) ? (_x) : (_y)))))

/* определяет число как минимальное или максимальное и помещает его в соответствующий аргумент*/
#define minmax_set(min, max, x)          { min = min(min, x);          max = max(max, x);          }
#define minmax_not_zero_set(min, max, x) { min = min_not_zero(min, x); max = max_not_zero(max, x); }

#endif /*YAYA_ARITHMETIC_H*/
