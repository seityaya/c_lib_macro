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
            UT_ASSERT_NUM_EQ( 0UL, primenum(0UL));
            UT_ASSERT_NUM_EQ( 2UL, primenum(1UL));
            UT_ASSERT_NUM_EQ( 3UL, primenum(2UL));
            UT_ASSERT_NUM_EQ( 5UL, primenum(3UL));
            UT_ASSERT_NUM_EQ( 7UL, primenum(4UL));
            UT_ASSERT_NUM_EQ(11UL, primenum(5UL));
            UT_ASSERT_NUM_EQ(13UL, primenum(6UL));
        } UT_GROUP_END;

        UT_GROUP_BEG(fibonacci) {
            UT_ASSERT_NUM_EQ( 0UL, fibonacci(0UL));
            UT_ASSERT_NUM_EQ( 1UL, fibonacci(1UL));
            UT_ASSERT_NUM_EQ( 1UL, fibonacci(2UL));
            UT_ASSERT_NUM_EQ( 2UL, fibonacci(3UL));
            UT_ASSERT_NUM_EQ( 3UL, fibonacci(4UL));
            UT_ASSERT_NUM_EQ( 5UL, fibonacci(5UL));
            UT_ASSERT_NUM_EQ( 8UL, fibonacci(6UL));
        } UT_GROUP_END;

        UT_GROUP_BEG(factorial) {
            UT_ASSERT_NUM_EQ(   1UL, factorial(0UL));
            UT_ASSERT_NUM_EQ(   1UL, factorial(1UL));
            UT_ASSERT_NUM_EQ(   2UL, factorial(2UL));
            UT_ASSERT_NUM_EQ(   6UL, factorial(3UL));
            UT_ASSERT_NUM_EQ(  24UL, factorial(4UL));
            UT_ASSERT_NUM_EQ( 120UL, factorial(5UL));
            UT_ASSERT_NUM_EQ( 720UL, factorial(6UL));
        } UT_GROUP_END;

        UT_GROUP_BEG(binomial) {
            UT_ASSERT_NUM_EQ(   1UL, binomial(0UL, 0UL));
            UT_ASSERT_NUM_EQ(   1UL, binomial(1UL, 1UL));
            UT_ASSERT_NUM_EQ(   1UL, binomial(2UL, 2UL));
            UT_ASSERT_NUM_EQ(   1UL, binomial(3UL, 3UL));
            UT_ASSERT_NUM_EQ(   1UL, binomial(4UL, 4UL));
            UT_ASSERT_NUM_EQ(   1UL, binomial(5UL, 5UL));
            UT_ASSERT_NUM_EQ(   1UL, binomial(6UL, 6UL));

            UT_ASSERT_NUM_EQ(10UL, binomial(5UL, 3UL));
            UT_ASSERT_NUM_EQ(131282408400UL, binomial(40UL, 19UL));
            UT_ASSERT_NUM_EQ(11923179284862717872UL, binomial(67UL, 31UL));
        } UT_GROUP_END;

        UT_GROUP_BEG(divisors_count) {
            UT_ASSERT_NUM_EQ(0UL, divisors(0UL, NULL));
            UT_ASSERT_NUM_EQ(1UL, divisors(1UL, NULL));
            UT_ASSERT_NUM_EQ(2UL, divisors(2UL, NULL));
            UT_ASSERT_NUM_EQ(2UL, divisors(3UL, NULL));
            UT_ASSERT_NUM_EQ(3UL, divisors(4UL, NULL));
            UT_ASSERT_NUM_EQ(2UL, divisors(5UL, NULL));
            UT_ASSERT_NUM_EQ(4UL, divisors(6UL, NULL));
            UT_ASSERT_NUM_EQ(2UL, divisors(7UL, NULL));
        } UT_GROUP_END;

        UT_BLOCK_BEG(divisors_list) {
UT_BLOCK_INIT;
            umax_t *list = NULL;
UT_BLOCK_TEST;
            UT_ASSERT_NUM_EQ( 6UL, divisors(12UL, &list));
            UT_ASSERT_NUM_EQ( 1UL, list[0]);
            UT_ASSERT_NUM_EQ( 2UL, list[1]);
            UT_ASSERT_NUM_EQ( 3UL, list[2]);
            UT_ASSERT_NUM_EQ( 4UL, list[3]);
            UT_ASSERT_NUM_EQ( 6UL, list[4]);
            UT_ASSERT_NUM_EQ(12UL, list[5]);
UT_BLOCK_FREE;
            free(list);
        } UT_BLOCK_END;

        UT_GROUP_BEG(primes_count) {
            UT_ASSERT_NUM_EQ(0UL, primes(umax_c(0), NULL));
            UT_ASSERT_NUM_EQ(0UL, primes(umax_c(1), NULL));
            UT_ASSERT_NUM_EQ(1UL, primes(umax_c(2), NULL));
            UT_ASSERT_NUM_EQ(2UL, primes(umax_c(3), NULL));
            UT_ASSERT_NUM_EQ(2UL, primes(umax_c(4), NULL));
            UT_ASSERT_NUM_EQ(3UL, primes(umax_c(5), NULL));
            UT_ASSERT_NUM_EQ(3UL, primes(umax_c(6), NULL));
            UT_ASSERT_NUM_EQ(4UL, primes(umax_c(7), NULL));
        } UT_GROUP_END;

        UT_BLOCK_BEG(primes_list) {
UT_BLOCK_INIT;
            umax_t *list = NULL;
UT_BLOCK_TEST;
            UT_ASSERT_NUM_EQ( 6UL, primes(13UL, &list));
            UT_ASSERT_NUM_EQ( 2UL, list[0]);
            UT_ASSERT_NUM_EQ( 3UL, list[1]);
            UT_ASSERT_NUM_EQ( 5UL, list[2]);
            UT_ASSERT_NUM_EQ( 7UL, list[3]);
            UT_ASSERT_NUM_EQ(11UL, list[4]);
            UT_ASSERT_NUM_EQ(13UL, list[5]);
UT_BLOCK_FREE;
            free(list);
        } UT_BLOCK_END;

    } UT_GROUP_END;
}
