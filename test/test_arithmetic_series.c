//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_series) {
    UT_GROUP_BEG(series) {
        UT_GROUP_BEG(primenum) {
            UT_ASSERT_NUM_EQUAL( 0, primenum(0UL));
            UT_ASSERT_NUM_EQUAL( 2, primenum(1UL));
            UT_ASSERT_NUM_EQUAL( 3, primenum(2UL));
            UT_ASSERT_NUM_EQUAL( 5, primenum(3UL));
            UT_ASSERT_NUM_EQUAL( 7, primenum(4UL));
            UT_ASSERT_NUM_EQUAL(11, primenum(5UL));
            UT_ASSERT_NUM_EQUAL(13, primenum(6UL));
        } UT_GROUP_END;

        UT_GROUP_BEG(fibonacci) {
            UT_ASSERT_NUM_EQUAL( 0, fibonacci(0UL));
            UT_ASSERT_NUM_EQUAL( 1, fibonacci(1UL));
            UT_ASSERT_NUM_EQUAL( 1, fibonacci(2UL));
            UT_ASSERT_NUM_EQUAL( 2, fibonacci(3UL));
            UT_ASSERT_NUM_EQUAL( 3, fibonacci(4UL));
            UT_ASSERT_NUM_EQUAL( 5, fibonacci(5UL));
            UT_ASSERT_NUM_EQUAL( 8, fibonacci(6UL));
        } UT_GROUP_END;

        UT_GROUP_BEG(factorial) {
            UT_ASSERT_NUM_EQUAL(   1, factorial(0UL));
            UT_ASSERT_NUM_EQUAL(   1, factorial(1UL));
            UT_ASSERT_NUM_EQUAL(   2, factorial(2UL));
            UT_ASSERT_NUM_EQUAL(   6, factorial(3UL));
            UT_ASSERT_NUM_EQUAL(  24, factorial(4UL));
            UT_ASSERT_NUM_EQUAL( 120, factorial(5UL));
            UT_ASSERT_NUM_EQUAL( 720, factorial(6UL));
        } UT_GROUP_END;

        UT_GROUP_BEG(binomial) {
            UT_ASSERT_NUM_EQUAL(   1, binomial(0UL, 0UL));
            UT_ASSERT_NUM_EQUAL(   1, binomial(1UL, 1UL));
            UT_ASSERT_NUM_EQUAL(   1, binomial(2UL, 2UL));
            UT_ASSERT_NUM_EQUAL(   1, binomial(3UL, 3UL));
            UT_ASSERT_NUM_EQUAL(   1, binomial(4UL, 4UL));
            UT_ASSERT_NUM_EQUAL(   1, binomial(5UL, 5UL));
            UT_ASSERT_NUM_EQUAL(   1, binomial(6UL, 6UL));

            UT_ASSERT_NUM_EQUAL(10UL, binomial(5UL, 3UL));
            UT_ASSERT_NUM_EQUAL(131282408400UL, binomial(40UL, 19UL));
            UT_ASSERT_NUM_EQUAL(11923179284862717872UL, binomial(67UL, 31UL));
        } UT_GROUP_END;

        UT_GROUP_BEG(divisors_count) {
            UT_ASSERT_NUM_EQUAL(0, divisors(0UL, NULL));
            UT_ASSERT_NUM_EQUAL(1, divisors(1UL, NULL));
            UT_ASSERT_NUM_EQUAL(2, divisors(2UL, NULL));
            UT_ASSERT_NUM_EQUAL(2, divisors(3UL, NULL));
            UT_ASSERT_NUM_EQUAL(3, divisors(4UL, NULL));
            UT_ASSERT_NUM_EQUAL(2, divisors(5UL, NULL));
            UT_ASSERT_NUM_EQUAL(4, divisors(6UL, NULL));
            UT_ASSERT_NUM_EQUAL(2, divisors(7UL, NULL));
        } UT_GROUP_END;

        UT_BLOCK_BEG(divisors_list) {
UT_BLOCK_INIT:;
            umax_t *list = NULL;
UT_BLOCK_TEST:;
            UT_ASSERT_NUM_EQUAL( 6, divisors(12UL, &list));
            UT_ASSERT_NUM_EQUAL( 1, list[0]);
            UT_ASSERT_NUM_EQUAL( 2, list[1]);
            UT_ASSERT_NUM_EQUAL( 3, list[2]);
            UT_ASSERT_NUM_EQUAL( 4, list[3]);
            UT_ASSERT_NUM_EQUAL( 6, list[4]);
            UT_ASSERT_NUM_EQUAL(12, list[5]);
UT_BLOCK_FREE:;
            free(list);
        } UT_BLOCK_END;

        UT_GROUP_BEG(primes_count) {
            UT_ASSERT_NUM_EQUAL(0, primes(umax_c(0), NULL));
            UT_ASSERT_NUM_EQUAL(0, primes(umax_c(1), NULL));
            UT_ASSERT_NUM_EQUAL(1, primes(umax_c(2), NULL));
            UT_ASSERT_NUM_EQUAL(2, primes(umax_c(3), NULL));
            UT_ASSERT_NUM_EQUAL(2, primes(umax_c(4), NULL));
            UT_ASSERT_NUM_EQUAL(3, primes(umax_c(5), NULL));
            UT_ASSERT_NUM_EQUAL(3, primes(umax_c(6), NULL));
            UT_ASSERT_NUM_EQUAL(4, primes(umax_c(7), NULL));
        } UT_GROUP_END;

        UT_BLOCK_BEG(primes_list) {
UT_BLOCK_INIT:;
            umax_t *list = NULL;
UT_BLOCK_TEST:;
            UT_ASSERT_NUM_EQUAL( 6, primes(13UL, &list));
            UT_ASSERT_NUM_EQUAL( 2, list[0]);
            UT_ASSERT_NUM_EQUAL( 3, list[1]);
            UT_ASSERT_NUM_EQUAL( 5, list[2]);
            UT_ASSERT_NUM_EQUAL( 7, list[3]);
            UT_ASSERT_NUM_EQUAL(11, list[4]);
            UT_ASSERT_NUM_EQUAL(13, list[5]);
UT_BLOCK_FREE:;
            free(list);
        } UT_BLOCK_END;

    } UT_GROUP_END;
}
