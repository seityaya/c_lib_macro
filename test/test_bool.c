// Author                 : Seityagiya Terlekchi
// Contacts               : terlekchiseityaya@gmail.com
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2024 Seityagiya Terlekchi. All rights reserved.

#include "yaya_bool.h"

bool_t b_t = true;
bool_t b_f = false;

int test_bool(void) {
    if(true == 0){
        return -1;
    }
    if(false != 0){
        return -1;
    }

    if(true != b_t){
        return -1;
    }
    if(false != b_f){
        return -1;
    }

    return 0;
}
