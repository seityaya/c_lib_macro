// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_SUGAR_H
#define YAYA_SUGAR_H

#include "yaya_bool.h"
#include "yaya_concat.h"

// clang-format off
#include "yaya_cdecl.h"
BEG_C_DECLARATION

//================= SUGAR ============================================================================================================================
/*
 * Fun Sugar
*/
#define loop           while(true)
#define ever           (;;)
#define forever()      for ever
#define foreveriter(i) for(int (i) = 0; ; (i)++)
#define forcount(i, c) for(int (i) = 0; (i) < (c); (i)++)

//================= BLOCKS ===========================================================================================================================
/*
 * Block
*/
#define BLOCK(x) ({ x; })
#define UNIT(x)  (  x   )
#define VOID()   ({ 0; })

/*
 * Условие
 * Conditional
 */
#define TERNARIUS(_cond, _true_cond, _false_cond) BLOCK(UNIT(_cond) ? BLOCK(_true_cond) : BLOCK(_false_cond))

//================= NEW TYPE BLOCK ===================================================================================================================
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
#define beg_block  { do {
#define end_block  break; } while(true); }  do{ } while(false)

//================= TEXT MACRO =======================================================================================================================
/*
 * Переопределение стандартных макросов
*/
#ifndef __FILE__
#define __FILE__
#endif

#ifndef __LINE__
#define __LINE__
#endif

#ifndef __FUNC__
#define __FUNC__   __FUNCTION__
#endif

//================= COMPOUND LITERALS ================================================================================================================
/*
 * Compound literals
*/
#define const_area(t, ...)   ({ (t[]){ __VA_ARGS__ };          })
#define const_area_0(t, ...) ({ (t[]){ __VA_ARGS__, 0 };       })
#define const_area_N(t, ...) ({ (t[]){ __VA_ARGS__, nullptr }; })

//================= MANDATORY ========================================================================================================================
/*
 * Mandatory Semicolon
*/
#define MD_SC do{ } while(false)

/*
 * Mandatory open figure brace
*/
#define MD_OFB do

/*
 * Mandatory close figure brace
*/
#define MD_CFB while (false);

//================= API TO STD SYNTAXIS ==============================================================================================================
/*
 * Conditional
*/
#define ter(_cond, _true_cond, _false_cond) ({ ((_cond) ? (_true_cond) : (_false_cond)); })

/*
 * Init
*/
#define init_ptr(n, t)   typeof(t) *n = nullptr
#define init_val(n, t)   typeof(t)  n = {0}

/*
 * Create
*/
#define crete_ptr(n, v)  typeof(v) *(n) = &v
#define crete_val(n, v)  typeof(v)  (n) = v

/*
 * Set
*/
#define set_adr(n, v)    (*(n)) = (&(v))
#define set_val(n, v)    (n)    = (v)

/*
 * Get
*/
#define get_adr(x)       (&(x))
#define get_val(x)       (*(x))

/*
 * Access
*/
#define access_fil(x, f) ((x).(f))
#define access_adr(x, f) ((x)->(f))
#define access_ind(x, i) ((x)[i])

/*
 * Split
*/
#define split(x, y)      (x), (y)

//====================================================================================================================================================

END_C_DECLARATION
// clang-format on
#endif /*YAYA_SUGAR_H*/
