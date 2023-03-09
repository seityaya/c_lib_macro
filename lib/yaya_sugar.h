//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_SUGAR_H
#define YAYA_SUGAR_H

#include "yaya_cdeclaration.h"
BEG_C_DECLARATION

#include "yaya_bool.h"

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

END_C_DECLARATION
#endif /*YAYA_SUGAR_H*/
