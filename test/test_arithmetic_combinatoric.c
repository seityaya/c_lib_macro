//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_combinatoric) {
    UT_GROUP_BEG(combinatoric) {
        UT_GROUP_BEG(permutation_count) {
            UT_ASSERT_NUM_EQ(umax_c( 1), permutation(umax_c(0), null_c(umax_t) ));
            UT_ASSERT_NUM_EQ(umax_c( 1), permutation(umax_c(1), null_c(umax_t) ));
            UT_ASSERT_NUM_EQ(umax_c( 2), permutation(umax_c(2), null_c(umax_t) ));
            UT_ASSERT_NUM_EQ(umax_c( 6), permutation(umax_c(3), null_c(umax_t) ));
            UT_ASSERT_NUM_EQ(umax_c(24), permutation(umax_c(4), null_c(umax_t) ));
        } UT_GROUP_END;


        UT_BLOCK_BEG(permutation_with_repetition) {
            UT_BLOCK_INIT;
            umax_t list1[] = {1, 1, 1, 1, 1};
            umax_t list2[] = {1, 1, 2, 2, 3};

            UT_BLOCK_TEST;
            UT_ASSERT_NUM_EQ(umax_c(    1), permutation(umax_c(0), NULL ));
            UT_ASSERT_NUM_EQ(umax_c(    1), permutation(umax_c(1), NULL ));
            UT_ASSERT_NUM_EQ(umax_c(    2), permutation(umax_c(2), NULL ));
            UT_ASSERT_NUM_EQ(umax_c(    6), permutation(umax_c(3), NULL ));
            UT_ASSERT_NUM_EQ(umax_c(   24), permutation(umax_c(4), NULL ));

            UT_ASSERT_NUM_EQ(umax_c(    1), permutation(umax_c(0), list1 ));
            UT_ASSERT_NUM_EQ(umax_c(    1), permutation(umax_c(1), list1 ));
            UT_ASSERT_NUM_EQ(umax_c(    2), permutation(umax_c(2), list1 ));
            UT_ASSERT_NUM_EQ(umax_c(    6), permutation(umax_c(3), list1 ));
            UT_ASSERT_NUM_EQ(umax_c(   24), permutation(umax_c(4), list1 ));

            UT_ASSERT_NUM_EQ(umax_c(    1), permutation(umax_c(0), list2 ));
            UT_ASSERT_NUM_EQ(umax_c(    1), permutation(umax_c(1), list2 ));
            UT_ASSERT_NUM_EQ(umax_c(    2), permutation(umax_c(2), list2 ));
            UT_ASSERT_NUM_EQ(umax_c(   12), permutation(umax_c(3), list2 ));
            UT_ASSERT_NUM_EQ(umax_c(  180), permutation(umax_c(4), list2 ));
            UT_ASSERT_NUM_EQ(umax_c(15120), permutation(umax_c(5), list2 ));
            UT_BLOCK_FREE;
        } UT_BLOCK_END;


        UT_GROUP_BEG(accommodation_count) {
            UT_ASSERT_NUM_EQ(umax_c( 1), accommodation(umax_c(0), umax_c(0), false ));
            UT_ASSERT_NUM_EQ(umax_c( 0), accommodation(umax_c(0), umax_c(1), false ));
            UT_ASSERT_NUM_EQ(umax_c( 1), accommodation(umax_c(1), umax_c(0), false ));

            UT_ASSERT_NUM_EQ(umax_c( 1), accommodation(umax_c(1), umax_c(1), false ));
            UT_ASSERT_NUM_EQ(umax_c( 2), accommodation(umax_c(2), umax_c(2), false ));
            UT_ASSERT_NUM_EQ(umax_c( 6), accommodation(umax_c(3), umax_c(3), false ));
            UT_ASSERT_NUM_EQ(umax_c(24), accommodation(umax_c(4), umax_c(4), false ));

            UT_ASSERT_NUM_EQ(umax_c( 1), accommodation(umax_c(4), umax_c(0), false ));
            UT_ASSERT_NUM_EQ(umax_c( 4), accommodation(umax_c(4), umax_c(1), false ));
            UT_ASSERT_NUM_EQ(umax_c(12), accommodation(umax_c(4), umax_c(2), false ));
            UT_ASSERT_NUM_EQ(umax_c(24), accommodation(umax_c(4), umax_c(3), false ));
            UT_ASSERT_NUM_EQ(umax_c(24), accommodation(umax_c(4), umax_c(4), false ));
        } UT_GROUP_END;


        UT_GROUP_BEG(accommodation_with_repetition) {
            UT_ASSERT_NUM_EQ(umax_c(  1), accommodation(umax_c(0), umax_c(0), true ));
            UT_ASSERT_NUM_EQ(umax_c(  1), accommodation(umax_c(1), umax_c(1), true ));
            UT_ASSERT_NUM_EQ(umax_c(  4), accommodation(umax_c(2), umax_c(2), true ));
            UT_ASSERT_NUM_EQ(umax_c( 27), accommodation(umax_c(3), umax_c(3), true ));
            UT_ASSERT_NUM_EQ(umax_c(256), accommodation(umax_c(4), umax_c(4), true ));

            UT_ASSERT_NUM_EQ(umax_c(  1), accommodation(umax_c(4), umax_c(0), true ));
            UT_ASSERT_NUM_EQ(umax_c(  4), accommodation(umax_c(4), umax_c(1), true ));
            UT_ASSERT_NUM_EQ(umax_c( 16), accommodation(umax_c(4), umax_c(2), true ));
            UT_ASSERT_NUM_EQ(umax_c( 64), accommodation(umax_c(4), umax_c(3), true ));
            UT_ASSERT_NUM_EQ(umax_c(256), accommodation(umax_c(4), umax_c(4), true ));
        } UT_GROUP_END;


        UT_GROUP_BEG(combination_count) {
            UT_ASSERT_NUM_EQ(umax_c(1), combination(umax_c(0), umax_c(0), false ));
            UT_ASSERT_NUM_EQ(umax_c(0), combination(umax_c(0), umax_c(1), false ));
            UT_ASSERT_NUM_EQ(umax_c(1), combination(umax_c(1), umax_c(0), false ));

            UT_ASSERT_NUM_EQ(umax_c(1), combination(umax_c(1), umax_c(1), false ));
            UT_ASSERT_NUM_EQ(umax_c(1), combination(umax_c(2), umax_c(2), false ));
            UT_ASSERT_NUM_EQ(umax_c(1), combination(umax_c(3), umax_c(3), false ));
            UT_ASSERT_NUM_EQ(umax_c(1), combination(umax_c(4), umax_c(4), false ));

            UT_ASSERT_NUM_EQ(umax_c(1), combination(umax_c(4), umax_c(0), false ));
            UT_ASSERT_NUM_EQ(umax_c(4), combination(umax_c(4), umax_c(1), false ));
            UT_ASSERT_NUM_EQ(umax_c(6), combination(umax_c(4), umax_c(2), false ));
            UT_ASSERT_NUM_EQ(umax_c(4), combination(umax_c(4), umax_c(3), false ));
            UT_ASSERT_NUM_EQ(umax_c(1), combination(umax_c(4), umax_c(4), false ));
        } UT_GROUP_END;


        UT_GROUP_BEG(combination_with_repetition) {
            UT_ASSERT_NUM_EQ(umax_c( 0), combination(umax_c(0), umax_c(0), true ));
            UT_ASSERT_NUM_EQ(umax_c( 1), combination(umax_c(1), umax_c(1), true ));
            UT_ASSERT_NUM_EQ(umax_c( 3), combination(umax_c(2), umax_c(2), true ));
            UT_ASSERT_NUM_EQ(umax_c(10), combination(umax_c(3), umax_c(3), true ));
            UT_ASSERT_NUM_EQ(umax_c(35), combination(umax_c(4), umax_c(4), true ));

            UT_ASSERT_NUM_EQ(umax_c( 1), combination(umax_c(4), umax_c(0), true ));
            UT_ASSERT_NUM_EQ(umax_c( 4), combination(umax_c(4), umax_c(1), true ));
            UT_ASSERT_NUM_EQ(umax_c(10), combination(umax_c(4), umax_c(2), true ));
            UT_ASSERT_NUM_EQ(umax_c(20), combination(umax_c(4), umax_c(3), true ));
            UT_ASSERT_NUM_EQ(umax_c(35), combination(umax_c(4), umax_c(4), true ));
        } UT_GROUP_END;
    } UT_GROUP_END;
}
