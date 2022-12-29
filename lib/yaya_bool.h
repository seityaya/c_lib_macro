//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2022 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_BOOL_H
#define YAYA_BOOL_H

#include <stdbool.h>

#ifndef bool
#define TRUE    (1 == 1)
#define FALSE   (!TRUE)

typedef enum bool {
    true = TRUE,
    false = FALSE
}bool;
#else
#define TRUE    true
#define FALSE   false
#endif

#define ENABLE  TRUE
#define DISABLE FALSE

#endif /*YAYA_BOOL_H*/
