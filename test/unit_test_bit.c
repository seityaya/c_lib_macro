//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.01
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "unit_test.h"

#include "yaya_bit.h"

UNIT_TEST_GENERATE_FUNC(math_bit_beg) {
    UT_BEG();
    UT_ASSERT_NUM_EQUAL(4, BIT_BEG(0b00001000));
    UT_END();
}
UNIT_TEST_GENERATE_FUNC(math_bit_end) {
    UT_BEG();
    UT_ASSERT_NUM_EQUAL(4, BIT_END(0b0001));
    UT_END();
}
UNIT_TEST_GENERATE_FUNC(math_bit_num) {
    UT_BEG();

    UT_ASSERT_NUM_EQUAL(1, BIT_NUM(0b0001));
    UT_ASSERT_NUM_EQUAL(2, BIT_NUM(0b000101));

    UT_END();
}
UNIT_TEST_GENERATE_FUNC(math_bit_pos) {
    UT_BEG();

    UT_ASSERT_NUM_EQUAL(4, BIT_POS(0b0001));
    UT_ASSERT_NUM_EQUAL((-1), BIT_POS(0b0101));

    UT_END();
}
UNIT_TEST_GENERATE_FUNC(math_bit_get) {
    UT_BEG();
    u08s test_a = 0b0001;
    UT_ASSERT_NUM_EQUAL(1, BIT_GET(test_a, 4));

    u08s test_b = 0b0001;
    UT_ASSERT_NUM_NOT_EQUAL(1, BIT_GET(test_b, 3));

    UT_END();
}
UNIT_TEST_GENERATE_FUNC(math_bit_set) {
    UT_BEG();
    u08s test_a = 0;
    test_a = BIT_SET(test_a, 0);
    UT_ASSERT_NUM_EQUAL(test_a, 0);

    u08s test_b = 0;
    test_b = BIT_SET(test_b, 1);
    UT_ASSERT_NUM_EQUAL(test_b, 1);

    u08s test_c = 0;
    test_c = BIT_SET(test_c, 2);
    UT_ASSERT_NUM_EQUAL(test_c, 2);

    UT_END();
}
UNIT_TEST_GENERATE_FUNC(math_bit_res) {
    UT_BEG();

    u08s test_a = 1;
    test_a = BIT_RES(test_a, 0);
    UT_ASSERT_NUM_EQUAL(test_a, 1);

    u08s test_b = 1;
    test_b = BIT_RES(test_b, 1);
    UT_ASSERT_NUM_EQUAL(test_b, 0);

    u08s test_c = 2;
    test_c = BIT_RES(test_c, 2);
    UT_ASSERT_NUM_EQUAL(test_c, 0);

    UT_END();
}
UNIT_TEST_GENERATE_FUNC(math_bit_tog) {
    UT_BEG();



    UT_END();
}
UNIT_TEST_GENERATE_FUNC(math_bit_wrt) {
    UT_BEG();
    UT_END();
}
UNIT_TEST_GENERATE_FUNC(math_bit_rev) {
    UT_BEG();
    UT_END();
}
UNIT_TEST_GENERATE_FUNC(math_bit_shf_rig) {
    UT_BEG();
    UT_END();
}
UNIT_TEST_GENERATE_FUNC(math_bit_shf_lef) {
    UT_BEG();
    UT_END();
}
UNIT_TEST_GENERATE_FUNC(math_bit_shf_vec) {
    UT_BEG();
    UT_END();
}
UNIT_TEST_GENERATE_FUNC(math_bit_cyc_rig) {
    UT_BEG();
    UT_END();
}
UNIT_TEST_GENERATE_FUNC(math_bit_cyc_lef) {
    UT_BEG();
    UT_END();
}
UNIT_TEST_GENERATE_FUNC(math_bit_cyc_vec) {
    UT_BEG();
    UT_END();
}
UNIT_TEST_GENERATE_FUNC(math_bit_mask_in) {
    UT_BEG();
    UT_END();
}
UNIT_TEST_GENERATE_FUNC(math_bit_mask_up) {
    UT_BEG();
    UT_END();
}
UNIT_TEST_GENERATE_FUNC(math_bit_mask_dw) {
    UT_BEG();
    UT_END();
}

