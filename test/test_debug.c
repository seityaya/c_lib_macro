//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.01
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_debug.h"

UT_FUNC_GEN(test_debug) {
    UT_SPASE_TEST_BEG{
        UT_GROUP_BEG(char) {
            char x = 'B';
            PRINT_DEBUG_INFO(x);
            PRINT_DEBUG_ALL(x);
        } UT_GROUP_END;

        UT_GROUP_BEG(int) {
            int x = 666;
            PRINT_DEBUG_INFO(x);
            PRINT_DEBUG_ALL(x);
        } UT_GROUP_END;

        UT_GROUP_BEG(float) {
            double x = 777.777;
            PRINT_DEBUG_INFO(x);
            PRINT_DEBUG_ALL(x);
        } UT_GROUP_END;

        UT_GROUP_BEG(double) {
            double x = 888.888;
            PRINT_DEBUG_INFO(x);
            PRINT_DEBUG_ALL(x);
        } UT_GROUP_END;

        UT_GROUP_BEG(char_p) {
            char* x = "Test Text";
            PRINT_DEBUG_INFO(x);
            PRINT_DEBUG_ALL(x);
        } UT_GROUP_END;

        UT_GROUP_BEG(int_p) {
            int16_t x = 666;
            int16_t* p = &x;
            PRINT_DEBUG_INFO(p);
            PRINT_DEBUG_ALL(p);
        } UT_GROUP_END;

        UT_GROUP_BEG(float_p) {
            double x = 777.777;
            double* p = &x;
            PRINT_DEBUG_INFO(p);
            PRINT_DEBUG_ALL(p);
        } UT_GROUP_END;

        UT_GROUP_BEG(double_p) {
            double x = 888.888;
            double* p = &x;
            PRINT_DEBUG_INFO(p);
            PRINT_DEBUG_ALL(p);
        } UT_GROUP_END;
    }UT_SPASE_TEST_END;
}
