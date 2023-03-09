//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_rand) {
    UT_GROUP_BEG(rand) {

        //    set_seed(7);

        //    forcount(i, 10000){
        //        printf("%d ", get_rand(-5, 5));
        //    }

        //    int k[10] = {0};
        //    int s = 0;
        //    forcount(i, 10000){
        //        k[get_rand(0, 9)]++;
        //    }
        //    forcount(i, 10){
        //        printf("%d ", k[i]);
        //        s += k[i];
        //        k[i] = 0;
        //    }
        //    printf("= %d \n", s);
        //    s = 0;

        //    forcount(i, 10000){
        //        k[get_rand_mms(0, 10, 3)]++;
        //    }
        //    forcount(i, 10){
        //        printf("%d ", k[i]);
        //        s += k[i];
        //        k[i] = 0;
        //    }
        //    printf("= %d \n", s);


        //    forcount(i, 100){
        //        printf("%d ", get_rand_mmc(1, 25, 3));
        //    }
        //    printf("\n");
    } UT_GROUP_END;
}
