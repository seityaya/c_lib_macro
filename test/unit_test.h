//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.01
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "yaya_unit.h"

#define LIST_OF_TEST \
    X(math_bit_beg) \
    X(math_bit_end) \
    X(math_bit_num) \
    X(math_bit_pos) \
    \
    X(math_bit_get) \
    X(math_bit_set) \
    X(math_bit_res) \
    X(math_bit_tog) \
    X(math_bit_wrt) \
    X(math_bit_rev) \
    \
    X(math_bit_shf_rig) \
    X(math_bit_shf_lef) \
    X(math_bit_shf_vec) \
    X(math_bit_cyc_rig) \
    X(math_bit_cyc_lef) \
    X(math_bit_cyc_vec) \
    \
    X(math_bit_mask_in) \
    X(math_bit_mask_up) \
    X(math_bit_mask_dw) \
    \
    \



#define X(NAME, ...) UNIT_TEST_GENERATE_FUNC(NAME);
LIST_OF_TEST
#undef X


static unit_test_func_t unit_test_func[] = {
    UNIT_TEST_GENERATE_ST_BEG
    #define X(NAME) UNIT_TEST_GENERATE_ST(NAME)
    LIST_OF_TEST
    #undef X
    UNIT_TEST_GENERATE_ST_END
};

#endif /*UNIT_TEST_H*/
