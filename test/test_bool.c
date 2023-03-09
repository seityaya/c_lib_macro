//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.01
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_bool.h"

UT_FUNC_GEN(test_bool) {
    UT_GROUP_BEG(bool) {
        UT_GROUP_BEG(macro) {
            UT_ASSERT_BOOL_TRUE(TRUE);
            UT_ASSERT_BOOL_FALSE(FALSE);

            UT_ASSERT_BOOL_TRUE(true);
            UT_ASSERT_BOOL_FALSE(false);
        } UT_GROUP_END;

        UT_GROUP_BEG(cros) {
            UT_ASSERT_BOOL(TRUE == true);
            UT_ASSERT_BOOL(FALSE == false);
            UT_ASSERT_BOOL(TRUE != false);
            UT_ASSERT_BOOL(FALSE != true);
        } UT_GROUP_END;

        UT_GROUP_BEG(type) {
            bool_t A = false;
            UT_ASSERT_BOOL_FALSE(A);
            A = 0;
            UT_ASSERT_BOOL_FALSE(A);

            A = true;
            UT_ASSERT_BOOL_TRUE(A);
            A = 1;
            UT_ASSERT_BOOL_TRUE(A);
            A = 2;
            UT_ASSERT_BOOL_TRUE(A);
        } UT_GROUP_END;
    } UT_GROUP_END;
}
