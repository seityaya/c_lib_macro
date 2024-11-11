// Author                 : Seityagiya Terlekchi
// Contacts               : terlekchiseityaya@gmail.com
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2024 Seityagiya Terlekchi. All rights reserved.

extern int test_bool(void);

int main(void) {
    int err = 0;
    if((err = test_bool()) != 0){
        return err;
    }

    return 0;
}
