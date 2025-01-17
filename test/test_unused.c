// Author                 : Seityagiya Terlekchi
// Contacts               : terlekchiseityaya@gmail.com
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2025 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_unused.h"

int global_x = 0;
UNUSED_GLOBAL_VAR(global_x);

static int global_f() { return 0; }
static int global_F(int i) { return i; }
UNUSED_GLOBAL_FNC(global_f);
UNUSED_GLOBAL_FNC(global_F);

int test_unused(void) {
    {
        int local_x = 0;
        void *local_p = nullptr;

        UNUSED_LOCAL_VAR(local_x);
        UNUSED_LOCAL_VAR(local_p);
    }

    {
        /* NOTE
         * Error: Function definition is not allowed here
         */

        // int local_f() { return 0; }
        // int local_F(int i) { return i; }

        // UNUSED_LOCAL_FNC(local_f);
        // UNUSED_LOCAL_FNC(local_F);
    }

    return 0;
}
