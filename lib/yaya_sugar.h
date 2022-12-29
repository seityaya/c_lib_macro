//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2022 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_SUGAR_H
#define YAYA_SUGAR_H

#include "yaya_bool.h"

#define mandatory_semicolon do{ } while(false)
#define ever      (;;)
#define forever() for ever
#define ternarius(_if, _true, _false) ((_if) ? (_true) : (_false))

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
#define beg do{  mandatory_semicolon
#define end break; } while (true); mandatory_semicolon

#endif /*YAYA_SUGAR_H*/
