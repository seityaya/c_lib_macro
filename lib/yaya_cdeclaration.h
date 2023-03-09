//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_CDECLARATION_H
#define YAYA_CDECLARATION_H

#ifdef	__cplusplus
#error  "WARNING C++ compiler!"
#define BEG_C_DECLARATION extern "C" {
#define END_C_DECLARATION }
#else
#define BEG_C_DECLARATION
#define END_C_DECLARATION
#endif

#endif /*YAYA_CDECLARATION_H*/
