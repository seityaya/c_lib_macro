//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_SUGAR_H
#define YAYA_SUGAR_H

#include "yaya_bool.h"

#include "yaya_cdeclaration.h"
BEG_C_DECLARATION

/*
 * Fun Sugar
*/
#define ever           (;;)
#define forever()      for ever
#define foreveriter(i) for(int (i) = 0; ; (i)++)
#define forcount(i, c) for(int (i) = 0; (i) < (c); (i)++)

/*
 * Compound literals
*/
#define const_area(t, ...) ({ (t[]){ __VA_ARGS__ }; })

/*
 * Type cast
*/
#define typecast(type, cond) ((typeof(type))(cond))

/*
 * Blocs
*/
#define BLOC(x)  ({ x; })
#define UNIT(x)  (x)
#define VOID()   ({0;})
/*
 * Новый тип блока в котором разрешено использовать break и continue вместо
 * конструкции do{ }while (false) или while (true){ }, (где, кстати невозможно
 * использовать оператор continue, без явного указания break, а тут он встроен)
 * и это выглядит опрятнее и намного опаснее в использовании т.к. continue выполняет
 * роль прыжка в начало блока и повтора всех действий. Хехе.
 * Расширяет возможности по управлению ходом выполнения программы без
 * использования оператора goto, если они запрещены явно, для перехода в конец.
 * Можно использовать как с фигурными скобками так и без.
 * Можно использовать с другими операторами if/else, switch/case вместо скобок.
 */
#define beg                  { do {
#define end                  break; } while(true); } MD_SC

/*
 * Переопределение стандартных макросов
*/
#define __FUNC__    __func__
#define nullptr     ((void*)(0))
#define VP_NULL     ((void*)(0))


/*
 * Определение дополнительных макросов
*/
#define ENABLE  TRUE
#define DISABLE FALSE

/*Mandatory Semicolon*/
#define MD_SC do{ } while(false)

/*Mandatory open figure brace*/
#define MD_OFB do

/*Mandatory close figure brace*/
#define MD_CFB while (false);

/*
 * Условие
 * Conditional
*/
#define ter(_cond, _true_cond, _false_cond)                                                                                                          \
    BLOC((_cond) ? (_true_cond) : (_false_cond))

/*
 * Адрес и значение
*/
#define init_ptr(n, t)     typeof(t) *n = NULL
#define init_val(n, t)     typeof(t)  n = {0}

#define crete_ptr(n, v)    typeof(v) *(n) = &v
#define crete_val(n, v)    typeof(v)  (n) = v

#define set_adr(n, v)      (*(n)) = (&(v))
#define set_val(n, v)      (n)    = (v)

#define get_adr(x)         (&(x))
#define get_val(x)         (*(x))


/*обращение по адресу или по значению*/
// .
// ->

/*оператор запятая*/
// ,

/*оператор массива*/
// [ ]

END_C_DECLARATION
#endif /*YAYA_SUGAR_H*/
