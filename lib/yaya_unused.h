//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2022 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_UNUSED_H
#define YAYA_UNUSED_H

#define UNUSED_VAR(x) ((void)(x))
#define UNUSED_FNC(f) static void f##_UNUSED(){do{ f;} while (0);}

#endif // YAYA_UNUSED_H
