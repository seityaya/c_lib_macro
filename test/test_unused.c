// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_unused.h"

int global_x = 0;

UNUSED_GLOBAL_VAR(global_x);


static int global_f() { return 0; }
static int global_F(int i) { return i; }

UNUSED_GLOBAL_FNC(global_f);
UNUSED_GLOBAL_FNC(global_F);


UT_FUNC_GEN(test_unused) {
    UT_GROUP_BEG(var) {
        int local_x = 0;
        void *local_p = nullptr;

        UNUSED_LOCAL_VAR(local_x);
        UNUSED_LOCAL_VAR(local_p);
    } UT_GROUP_END;

    UT_GROUP_BEG(fnc) {
        int local_f() { return 0; }
        int local_F(int i) { return i; }

        UNUSED_LOCAL_FNC(local_f);
        UNUSED_LOCAL_FNC(local_F);
    } UT_GROUP_END;
}
