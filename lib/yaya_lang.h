//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_LANG_H
#define YAYA_LANG_H

#include "yaya_cdeclaration.h"
BEG_CDECLARATION

/*адрес и значение*/
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

//UT_GROUP_BEG(value&address) {
//    init_val(A, int);
//    init_val(B, char);
//    UT_ASSERT_NUM_EQUAL(0, A);
//    UT_ASSERT_CHAR_EQUAL( (char)'\0', B);

//    init_ptr(a, int);
//    init_ptr(b, char);
//    UT_ASSERT_TYPE_EQUAL(UT_TYPE_DEFINE(int*), a);
//    UT_ASSERT_TYPE_EQUAL(UT_TYPE_DEFINE(char*), b);
//    UT_ASSERT_PTR_EQUAL(NULL, a);
//    UT_ASSERT_PTR_EQUAL(NULL, b);

//    crete_val(i, 1.0);
//    UT_ASSERT_FLT_EQUAL(1.0, i);
//    UT_ASSERT_TYPE_EQUAL( (double){0}, i);

//    crete_ptr(p, i);
//    UT_ASSERT_PTR_EQUAL(p, &i);
//    UT_ASSERT_TYPE_EQUAL( (double*){0}, p);


//} UT_GROUP_END;

/*
 * Условие
 * Conditional
*/
#define ter(_cond, _true_cond, _false_cond)                                                                                                          \
    BLOC((_cond) ? (_true_cond) : (_false_cond))



END_CDECLARATION
#endif /*YAYA_LANG_H*/
