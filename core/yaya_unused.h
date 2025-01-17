// Author                 : Seityagiya Terlekchi
// Contacts               : terlekchiseityaya@gmail.com
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2025 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_UNUSED_H
#define YAYA_UNUSED_H

// clang-format off
#include "yaya_cdecl.h"
BEG_C_DECLARATION

//================= UNUSED ===========================================================================================================================
/*
 * Unused variable
*/
#define UNUSED_LOCAL_VAR(x)  typeof(x) UNUSED_LOCAL_##x  = {0}; ((void)(UNUSED_LOCAL_##x)); ((void)(x))

#define UNUSED_GLOBAL_VAR(x) typeof(x) UNUSED_GLOBAL_##x = {0}

/*
 * Unused function
*/
#define UNUSED_LOCAL_FNC(f)  void UNUSED_LOCAL_##f(void)  { while (0) { void *p = f; UNUSED_LOCAL_VAR(p); } } UNUSED_LOCAL_##f()

#define UNUSED_GLOBAL_FNC(f) void UNUSED_GLOBAL_##f(void) { while (0) { void *p = f; UNUSED_LOCAL_VAR(p); } } int UNUSED_GLOBAL_##f##_ = {0}

//====================================================================================================================================================

END_C_DECLARATION
// clang-format on
#endif /*YAYA_UNUSED_H*/
