// Author                 : Seityagiya Terlekchi
// Contacts               : terlekchiseityaya@gmail.com
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2025 Seityagiya Terlekchi. All rights reserved.

#include "stdio.h"

extern int test_argcount(void);
extern int test_bool(void);
extern int test_check(void);
extern int test_concat(void);
extern int test_endian(void);
extern int test_flag(void);
extern int test_sugar(void);
extern int test_type(void);
extern int test_unused(void);

int main(void) {
    int err = 0;

    printf("Tests Beg...\n");

    err = test_bool();
    if (err != 0) {
        return err;
    }

    err = test_check();
    if (err != 0) {
        return err;
    }

    err = test_concat();
    if (err != 0) {
        return err;
    }

    err = test_argcount();
    if (err != 0) {
        return err;
    }

    err = test_endian();
    if (err != 0) {
        return err;
    }

    err = test_flag();
    if (err != 0) {
        return err;
    }

    err = test_sugar();
    if (err != 0) {
        return err;
    }

    err = test_type();
    if (err != 0) {
        return err;
    }

    err = test_unused();
    if (err != 0) {
        return err;
    }

    printf("Tests End...\n");

    return 0;
}
