// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_sugar.h"

UT_FUNC_GEN(test_sugar) {
    UT_GROUP_BEG(block) {
        UT_SPASE_TEST_BEG {
            int i = 0;
            UT_ASSERT_NUM_EQ(0, i);
            beg_block {
                i++;
                if(i == 1) {
                    UT_ASSERT_NUM_EQ(1, i);
                    continue;
                }
                UT_ASSERT_NUM_EQ(2, i);
            } end_block;
            UT_ASSERT_NUM_EQ(2, i);
        } UT_SPASE_TEST_END;

        UT_SPASE_TEST_BEG {
            int i = 0;
            UT_ASSERT_NUM_EQ(0, i);
            beg_block {
                i++;
                if(i == 1){
                    UT_ASSERT_NUM_EQ(1, i);
                    break;
                }
                UT_ASSERT_CALL_IF();
            } end_block;
            UT_ASSERT_NUM_EQ(1, i);
        } UT_SPASE_TEST_END;
    } UT_GROUP_END;

    UT_GROUP_BEG(syntaxis) {
        UT_GROUP_BEG(ternarius) {
            UT_ASSERT_NUM_EQ(0, ter(false, 1, 0));
            UT_ASSERT_NUM_EQ(1, ter(true, 1, 0));

            UT_ASSERT_NUM_EQ(0, ter(false, ter(true, 1, 0), ter(false, 1, 0)));
            UT_ASSERT_NUM_EQ(1, ter(true, ter(true, 1, 0), ter(false, 1, 0)));
        } UT_GROUP_END;

        UT_GROUP_BEG(init_ptr) {
            init_ptr(a, int);
            init_ptr(b, char);
            UT_ASSERT_TYP_EQ((int*){0}, a);
            UT_ASSERT_TYP_EQ((char*){0}, b);
            UT_ASSERT_NUL_EQ(a);
            UT_ASSERT_NUL_EQ(b);
        } UT_GROUP_END;

        UT_GROUP_BEG(init_val) {
            init_val(A, int);
            init_val(B, char);
            UT_ASSERT_NUM_EQ(0, A);
            UT_ASSERT_CHR_EQ(char_c('\0'), B);
        } UT_GROUP_END;

        UT_GROUP_BEG(crete_ptr) {
            crete_val(i, 1.0);
            crete_ptr(p, i);
            UT_ASSERT_PTR_EQ(p, &i);
            UT_ASSERT_TYP_EQ((double*){0}, p);
        } UT_GROUP_END;

        UT_GROUP_BEG(crete_val) {
            crete_val(i, 1.0);
            UT_ASSERT_FLT_EQ(1.0, i);
            UT_ASSERT_TYP_EQ((double){0}, i);
        } UT_GROUP_END;

        UT_GROUP_BEG(set_adr) {

        }UT_GROUP_END;

        UT_GROUP_BEG(set_val) {

        }UT_GROUP_END;

        UT_GROUP_BEG(get_adr) {

        }UT_GROUP_END;

        UT_GROUP_BEG(get_val) {

        }UT_GROUP_END;

    }UT_GROUP_END;
}
