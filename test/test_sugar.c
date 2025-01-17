// Author                 : Seityagiya Terlekchi
// Contacts               : terlekchiseityaya@gmail.com
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2025 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_sugar.h"

int test_sugar() {
    {
        {
            int i = 0;
            ASSERT_NUM_EQ(0, i);
            beg_block {
                i++;
                if (i == 1) {
                    ASSERT_NUM_EQ(1, i);
                    continue;
                }
                ASSERT_NUM_EQ(2, i);
            }
            end_block;
            ASSERT_NUM_EQ(2, i);
        }

        {
            int i = 0;
            ASSERT_NUM_EQ(0, i);
            beg_block {
                i++;
                if (i == 1) {
                    ASSERT_NUM_EQ(1, i);
                    break;
                }
                ASSERT_CALL_IF();
            }
            end_block;
            ASSERT_NUM_EQ(1, i);
        }
    }

    {
        {
            ASSERT_NUM_EQ(0, ter(false, 1, 0));
            ASSERT_NUM_EQ(1, ter(true, 1, 0));

            ASSERT_NUM_EQ(0, ter(false, ter(true, 1, 0), ter(false, 1, 0)));
            ASSERT_NUM_EQ(1, ter(true, ter(true, 1, 0), ter(false, 1, 0)));
        }

        {
            init_ptr(a, int);
            init_ptr(b, char);
            ASSERT_TYP_EQ((int*){0}, a);
            ASSERT_TYP_EQ((char*){0}, b);
            ASSERT_NUL_EQ(a);
            ASSERT_NUL_EQ(b);
        }

        {
            init_val(A, int);
            init_val(B, char);
            ASSERT_NUM_EQ(0, A);
            ASSERT_CHR_EQ(char_c('\0'), B);
        }

        {
            {
                crete_val(i, 1.0);
                crete_ptr(p, i);
                ASSERT_PTR_EQ(p, &i);
                ASSERT_TYP_EQ((double*){0}, p);
            }

            {
                crete_val(i, 1.0);
                ASSERT_FLT_EQ(1.0, i);
                ASSERT_TYP_EQ((double){0}, i);
            }
        }
    }

    return 0;
}
