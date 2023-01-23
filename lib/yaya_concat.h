//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_CONCAT_H
#define YAYA_CONCAT_H

#define MACRO_DELAY(x) x

#define STR_3(x) STR_2(MACRO_DELAY(x))
#define STR_2(x) STR_1(x)
#define STR_1(x) #x

#define CAT_3(x, y) CAT_2(MACRO_DELAY(x), MACRO_DELAY(y))
#define CAT_2(x, y) CAT_1(x, y)
#define CAT_1(x, y) x##y

#endif /*YAYA_CONCAT_H*/
