// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_CDECL_H
#define YAYA_CDECL_H

// clang-format off

//================= CDECLARATION =====================================================================================================================

#ifdef __cplusplus
    #error  "WARNING C++ compiler!"
    #define BEG_C_DECLARATION extern "C" {
    #define END_C_DECLARATION }
#else
    #define BEG_C_DECLARATION
    #define END_C_DECLARATION
#endif

//====================================================================================================================================================

// clang-format on
#endif /*YAYA_CDECL_H*/