//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_BOOL_H
#define YAYA_BOOL_H

#include "yaya_cdeclaration.h"
BEG_C_DECLARATION

#include "stdbool.h"

#ifndef bool

typedef enum bool_t {
    true = TRUE,
    false = FALSE
}bool_t;

#define BOOL    bool_t
#define TRUE    (1 == 1)
#define FALSE   (!TRUE)

#else

#define bool_t  bool
#define BOOL    bool
#define TRUE    true
#define FALSE   false

#endif

END_C_DECLARATION
#endif /*YAYA_BOOL_H*/
