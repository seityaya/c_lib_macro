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
            UT_ASSERT_BOOL_TR(TRUE);
            UT_ASSERT_BOOL_FL(FALSE);

            UT_ASSERT_BOOL_TR(true);
            UT_ASSERT_BOOL_FL(false);
        } UT_GROUP_END;

        UT_GROUP_BEG(cros) {
            UT_ASSERT_BOOL_TR(TRUE == true);
            UT_ASSERT_BOOL_TR(FALSE == false);
            UT_ASSERT_BOOL_TR(TRUE != false);
            UT_ASSERT_BOOL_TR(FALSE != true);
        } UT_GROUP_END;

        UT_GROUP_BEG(type) {
            bool_t A = false;
            UT_ASSERT_BOOL_FL(A);
            A = 0;
            UT_ASSERT_BOOL_FL(A);

            A = true;
            UT_ASSERT_BOOL_TR(A);
            A = 1;
            UT_ASSERT_BOOL_TR(A);
            A = 2;
            UT_ASSERT_BOOL_TR(A);
        } UT_GROUP_END;
    } UT_GROUP_END;
}
