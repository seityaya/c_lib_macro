//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_rand.h"
#include "yaya_arithmetic.h"

#include "yaya_cdeclaration.h"
BEG_C_DECLARATION

UT_FUNC_GEN(test_rand) {
    UT_GROUP_BEG(rand) {
        UT_GROUP_BEG(set_get_seed) {
            set_seed(0);
            UT_ASSERT_NUM_EQ(umax_c(0), get_seed());

            set_seed(88);
            UT_ASSERT_NUM_EQ(umax_c(88), get_seed());
        }UT_GROUP_END;

        UT_GROUP_BEG(get_random) {
            set_seed(1);
            UT_ASSERT_NUM_EQ(umax_c(1804289383), get_random());
            UT_ASSERT_NUM_EQ(umax_c( 846930886), get_random());
            UT_ASSERT_NUM_EQ(umax_c(1681692777), get_random());
            UT_ASSERT_NUM_EQ(umax_c(1714636915), get_random());
            UT_ASSERT_NUM_EQ(umax_c(1957747793), get_random());

            set_seed(1);
            UT_ASSERT_NUM_EQ(umax_c(1804289383), get_random());
            UT_ASSERT_NUM_EQ(umax_c( 846930886), get_random());
            UT_ASSERT_NUM_EQ(umax_c(1681692777), get_random());
            UT_ASSERT_NUM_EQ(umax_c(1714636915), get_random());
            UT_ASSERT_NUM_EQ(umax_c(1957747793), get_random());
        }UT_GROUP_END;

        UT_GROUP_BEG(get_rand) {
            set_seed(2);
            UT_ASSERT_NUM_EQ(imax_c(8), get_rand(imax_c(0), imax_c(10)));
            UT_ASSERT_NUM_EQ(imax_c(8), get_rand(imax_c(0), imax_c(10)));
            UT_ASSERT_NUM_EQ(imax_c(6), get_rand(imax_c(0), imax_c(10)));
            UT_ASSERT_NUM_EQ(imax_c(5), get_rand(imax_c(0), imax_c(10)));

            set_seed(2);
            UT_ASSERT_NUM_EQ(imax_c(3), get_rand(imax_c(-5), imax_c(5)));
            UT_ASSERT_NUM_EQ(imax_c(3), get_rand(imax_c(-5), imax_c(5)));
            UT_ASSERT_NUM_EQ(imax_c(1), get_rand(imax_c(-5), imax_c(5)));
            UT_ASSERT_NUM_EQ(imax_c(0), get_rand(imax_c(-5), imax_c(5)));
        }UT_GROUP_END;

        UT_GROUP_BEG(get_rand_distribution) {
            set_seed(2);
            imax_t k[10] = {0};
            forcount(i, 999){
                k[get_rand(0, 9)]++;
            }
            int i = 0;
            UT_ASSERT_NUM_EQ(imax_c( 92), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(112), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c( 91), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c( 98), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c( 86), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(110), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c( 97), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(107), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(104), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(102), k[i++]);

            imax_t s = 0;
            forcount(i, 10){
                s += k[i];
            }
            UT_ASSERT_NUM_EQ(imax_c(999), s);
        }UT_GROUP_END;


        UT_GROUP_BEG(get_rand_mms_distribution) {
            set_seed(2);
            imax_t k[10] = {0};
            forcount(i, 999){
                k[get_rand_mms(0, 10, 3)]++;
            }
            int i = 0;
            UT_ASSERT_NUM_EQ(imax_c(234), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(  0), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(  0), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(287), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(  0), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(  0), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(236), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(  0), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(  0), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(242), k[i++]);

            imax_t s = 0;
            forcount(i, 10){
                s += k[i];
            }
            UT_ASSERT_NUM_EQ(imax_c(999), s);
        } UT_GROUP_END;


        UT_GROUP_BEG(get_rand_mmc_distribution) {
            set_seed(2);
            imax_t k[10] = {0};
            forcount(i, 999){
                k[get_rand_mmc(0, 10, 3)]++;
            }
            int i = 0;
            UT_ASSERT_NUM_EQ(imax_c(346), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(  0), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(  0), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(345), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(  0), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(  0), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(308), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(  0), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(  0), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(  0), k[i++]);

            imax_t s = 0;
            forcount(i, 10){
                s += k[i];
            }
            UT_ASSERT_NUM_EQ(imax_c(999), s);
        }UT_GROUP_END;

        UT_GROUP_BEG(get_rand_normal_distribution) {
            set_seed(2);
            imax_t k[13] = {0};
            forcount(i, 100000){
                fmax_t d = get_rand_normal(fmax_c(0), fmax_c(1));
//                umax_t j = scale(typecast(umax_t, round_int(d)), umax_c(-6), umax_c(+6), umax_c( 0), umax_c(13));
                umax_t j = typecast(umax_t, round_int(d)) + 6;
                k[j]++;
            }
            int i = 0;
            UT_ASSERT_NUM_EQ(imax_c(0 ), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(0 ), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(16 ), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(528 ), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(6172 ), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(24430 ), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(37883 ), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(24216 ), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(6183 ), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(562 ), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(10 ), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(0 ), k[i++]);
            UT_ASSERT_NUM_EQ(imax_c(0), k[i++]);

            imax_t s = 0;
            forcount(i, 13){
                s += k[i];
            }

            UT_ASSERT_NUM_EQ(imax_c(100000), s);
        }UT_GROUP_END;
    } UT_GROUP_END;
}

END_C_DECLARATION
