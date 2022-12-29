//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2022 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_CONCATENATE_H
#define YAYA_CONCATENATE_H

#define MACRODELAY(x) x
#define CAT_3(x, y) CAT_2(MACRODELAY(x), MACRODELAY(y))
#define CAT_2(x, y) CAT_1(x, y)
#define CAT_1(x, y) x##y

#endif /*YAYA_CONCATENATE_H*/
